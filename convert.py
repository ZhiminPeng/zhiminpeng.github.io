#!/usr/bin/env python3.13
"""
Convert a Markdown post to a styled HTML page.

Usage:
    python convert.py writing/my-post.md

Requirements:
    pip install markdown python-frontmatter

Markdown frontmatter format:
    ---
    title: Your Post Title
    date: 15 Mar 2026
    description: A short description for SEO.
    tag: Search
    read_time: 8 min read
    ---

    Post body here...
"""

import sys
import re
from pathlib import Path

try:
    import yaml
    import markdown
    from markdown.extensions.fenced_code import FencedCodeExtension
    from markdown.extensions.tables import TableExtension
except ImportError:
    print("Missing dependencies. Run: pip install markdown pyyaml")
    sys.exit(1)


POST_TEMPLATE = """\
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>{title} | Zhimin Peng</title>
  <meta name="description" content="{description}" />
  <link rel="preconnect" href="https://fonts.googleapis.com" />
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
  <link href="https://fonts.googleapis.com/css2?family=Raleway:wght@400;600;700&display=swap" rel="stylesheet" />
  <style>
    *, *::before, *::after {{ box-sizing: border-box; margin: 0; padding: 0; }}

    html {{ overflow-y: scroll; }}

    body {{
      font-family: Raleway, Helvetica, Arial, sans-serif;
      background: #fff;
      color: #333;
      font-size: 16px;
      line-height: 1.75;
      -webkit-font-smoothing: antialiased;
    }}

    a {{ color: #007bff; text-decoration: none; }}
    a:hover {{ text-decoration: underline; }}

    .container {{ max-width: 740px; margin: 0 auto; padding: 0 24px; }}

    /* Nav */
    nav {{ border-bottom: 1px solid #eee; margin-bottom: 48px; }}
    nav .container {{
      display: flex; align-items: center;
      justify-content: space-between; height: 52px;
    }}
    .nav-brand {{ font-weight: 700; font-size: 0.95rem; color: #333; text-decoration: none; }}
    .nav-brand:hover {{ text-decoration: none; color: #333; }}
    nav ul {{ list-style: none; display: flex; gap: 24px; }}
    nav ul a {{ font-size: 0.9rem; font-weight: 600; color: #555; text-decoration: none; }}
    nav ul a:hover {{ color: #007bff; text-decoration: none; }}

    /* Post header */
    .post-header {{ margin-bottom: 36px; }}
    .post-tag {{
      display: inline-block;
      font-size: 0.75rem; font-weight: 700;
      text-transform: uppercase; letter-spacing: 0.08em;
      color: #007bff;
      background: #eff6ff;
      padding: 3px 10px; border-radius: 3px;
      margin-bottom: 12px;
    }}
    .post-header h1 {{
      font-size: 1.75rem; font-weight: 700;
      line-height: 1.25; letter-spacing: -0.02em;
      margin-bottom: 10px; color: #333;
    }}
    .post-meta {{ font-size: 0.875rem; color: #999; }}
    .post-meta span + span::before {{ content: " · "; }}

    /* Post body */
    .post-body {{ margin-bottom: 56px; }}
    .post-body h2 {{
      font-size: 1.25rem; font-weight: 700;
      margin: 36px 0 12px; color: #333;
    }}
    .post-body h3 {{
      font-size: 1.05rem; font-weight: 700;
      margin: 24px 0 8px; color: #333;
    }}
    .post-body p {{ margin-bottom: 15px; }}
    .post-body ul, .post-body ol {{
      margin: 0 0 15px 22px;
    }}
    .post-body li {{ margin-bottom: 6px; }}
    .post-body strong {{ font-weight: 700; }}
    .post-body em {{ font-style: italic; }}
    .post-body blockquote {{
      border-left: 3px solid #ddd;
      padding: 4px 0 4px 16px;
      margin: 20px 0;
      color: #666;
    }}
    .post-body pre {{
      background: #f5f5f5;
      border: 1px solid #e8e8e8;
      border-radius: 4px;
      padding: 16px 20px;
      overflow-x: auto;
      margin: 20px 0;
      font-size: 0.875rem;
      line-height: 1.6;
    }}
    .post-body code {{
      font-family: 'SFMono-Regular', Consolas, monospace;
      font-size: 0.875em;
      background: #f5f5f5;
      padding: 2px 5px;
      border-radius: 3px;
    }}
    .post-body pre code {{
      background: none; padding: 0; font-size: inherit;
    }}
    .post-body hr {{
      border: none; border-top: 1px solid #eee;
      margin: 36px 0;
    }}

    /* Back link */
    .back {{ margin-bottom: 32px; }}
    .back a {{ font-size: 0.9rem; font-weight: 600; color: #555; }}
    .back a:hover {{ color: #007bff; text-decoration: none; }}

    /* Footer */
    footer {{
      border-top: 1px solid #eee; padding: 24px 0 40px;
      font-size: 0.85rem; color: #999;
      display: flex; justify-content: space-between;
      flex-wrap: wrap; gap: 8px;
    }}
    footer a {{ color: #999; }}
    footer a:hover {{ color: #007bff; text-decoration: none; }}
  </style>
</head>
<body>

  <nav>
    <div class="container">
      <a href="/" class="nav-brand">zhiminpeng</a>
      <ul>
        <li><a href="/papers.html">Research</a></li>
        <li><a href="/writing/">Writing</a></li>
        <li><a href="https://latentvaluelab.com" target="_blank" rel="noopener">Consulting</a></li>
        <li><a href="https://scholar.google.com/citations?user=vRvQj2IAAAAJ&hl=en" target="_blank" rel="noopener">Scholar</a></li>
      </ul>
    </div>
  </nav>

  <div class="container">

    <div class="back"><a href="/writing/">← Writing</a></div>

    <header class="post-header">
      {tag_html}
      <h1>{title}</h1>
      <div class="post-meta">
        <span>{date}</span>
        <span>{read_time}</span>
      </div>
    </header>

    <article class="post-body">
{body}
    </article>

    <footer>
      <span>© 2026 Zhimin Peng</span>
      <span>
        <a href="mailto:zhiminp@gmail.com">Email</a> &nbsp;·&nbsp;
        <a href="https://www.linkedin.com/in/zhimin-peng-20005033/" target="_blank" rel="noopener">LinkedIn</a> &nbsp;·&nbsp;
        <a href="https://latentvaluelab.com" target="_blank" rel="noopener">Latent Value Lab</a>
      </span>
    </footer>

  </div>
</body>
</html>
"""


def estimate_read_time(text):
    words = len(re.findall(r'\w+', text))
    minutes = max(1, round(words / 200))
    return f"{minutes} min read"


def convert(md_path):
    path = Path(md_path)
    if not path.exists():
        print(f"File not found: {md_path}")
        sys.exit(1)

    raw = path.read_text(encoding='utf-8')

    # Parse YAML frontmatter (--- ... ---)
    meta, content = {}, raw
    fm_match = re.match(r'^---\s*\n(.*?)\n---\s*\n(.*)', raw, re.DOTALL)
    if fm_match:
        meta = yaml.safe_load(fm_match.group(1)) or {}
        content = fm_match.group(2)

    title       = meta.get('title', 'Untitled')
    date        = str(meta.get('date', ''))
    description = meta.get('description', title)
    tag         = meta.get('tag', '')
    read_time   = meta.get('read_time') or estimate_read_time(content)

    tag_html = f'<div class="post-tag">{tag}</div>' if tag else ''

    # Convert Markdown to HTML
    md = markdown.Markdown(extensions=[
        FencedCodeExtension(),
        TableExtension(),
        'nl2br',
    ])
    body_html = md.convert(content)

    html = POST_TEMPLATE.format(
        title=title,
        description=description,
        date=date,
        read_time=read_time,
        tag_html=tag_html,
        body=body_html,
    )

    output_path = path.with_suffix('.html')
    output_path.write_text(html, encoding='utf-8')
    print(f"✓ Created: {output_path}")


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python convert.py writing/my-post.md")
        sys.exit(1)
    convert(sys.argv[1])
