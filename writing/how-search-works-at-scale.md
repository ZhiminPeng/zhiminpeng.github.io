---
title: "How Search Works at Scale: From Query to Result in Milliseconds"
date: "15 Mar 2026"
description: "Building a search system that handles millions of queries per day requires far more than an inverted index. Here's what production search actually looks like."
tag: Search
---

Most engineers have used a search engine. Far fewer have built one that needs to handle millions of queries per day, return results in under 100ms, and continuously improve its relevance without human intervention. I spent eight years at Amazon building exactly these kinds of systems for Fire TV, and the gap between a toy search implementation and a production one is enormous.

This post walks through the architecture of a real-world search system — the key components, the tradeoffs, and the parts that are surprisingly hard.

## The Naive Mental Model (and Why It Breaks)

Most people's mental model of search goes something like: user types a query → system finds documents containing those words → rank by relevance → return results. This works fine at small scale. It breaks badly at production scale for several reasons:

- **Vocabulary mismatch:** Users say "action movies with car chases" but your catalog says "high-octane thriller featuring vehicular pursuit sequences."
- **Latency:** Scanning millions of documents on every query is too slow.
- **Relevance:** Keyword overlap is a terrible proxy for what the user actually wants.
- **Personalization:** The same query from two different users might deserve completely different results.

Production search systems solve each of these problems with dedicated subsystems. Let's walk through them.

## Layer 1: Query Understanding

Before you even touch your index, you need to understand what the user is actually asking for. Query understanding is a pipeline that typically includes:

### Query Rewriting

Spelling correction, synonym expansion, and query normalization. "avngrs" → "avengers". "sci fi" → "science fiction". This is harder than it sounds because you want to rewrite confidently when the original is clearly wrong, and leave it alone when it might be intentional (e.g., a niche brand name).

### Intent Classification

Is this a navigational query ("Ted Lasso Season 2"), an exploratory query ("something funny to watch"), or a task-based query ("action movies for kids")? Different intents call for completely different retrieval and ranking strategies.

### Entity Recognition

Identifying that "Tom Hanks comedies" contains a person entity ("Tom Hanks") and a genre constraint ("comedies") lets downstream systems do structured retrieval rather than just keyword matching.

> **Key insight:** The quality of your query understanding caps the quality of everything downstream. A perfect ranker can't save you if you've fundamentally misunderstood the query.

## Layer 2: Retrieval

Retrieval is the problem of efficiently finding candidate documents from a corpus of millions. You can't rank what you haven't retrieved, and you can't afford to rank everything. The goal is to retrieve a few thousand highly relevant candidates quickly.

### Inverted Index (Sparse Retrieval)

The classic approach: build an index mapping each term to the list of documents containing it. Fast, interpretable, and works well for exact and near-exact matches. Systems like Elasticsearch/Lucene use this under the hood.

### Dense Retrieval (Embeddings)

Encode both queries and documents as dense vectors using a neural model, then find the nearest neighbors in vector space. This handles semantic similarity — "action film with car chases" matches "Fast & Furious" even without shared keywords.

### Hybrid Retrieval

In practice, the best systems combine both. Sparse retrieval is great for precision (exact matches), dense retrieval is great for recall (semantic matches). Merging the two candidate sets, often with reciprocal rank fusion, consistently outperforms either approach alone.

## Layer 3: Ranking

You've retrieved 2,000 candidates. Now you need to rank them. This is where most of the ML complexity lives.

### Learning to Rank

Models are trained on implicit feedback (clicks, completions, dwell time) or explicit labels. Pairwise and listwise approaches (LambdaMART, neural rankers) consistently outperform pointwise approaches because they directly optimize for the ranking objective.

### Two-Stage Ranking

A lightweight model first re-ranks 2,000 candidates to ~200 (fast, cheaper features). A heavier model then re-ranks those 200 to the final top-10 (slower, richer features). This keeps latency in check while allowing expensive models where it matters most.

## Layer 4: Personalization

The same query from two different users should often return different results. Personalization can be injected at multiple layers:

- **Retrieval:** Bias candidate retrieval toward content similar to what the user has engaged with
- **Ranking:** Include user embedding features directly in the ranking model
- **Re-ranking:** Post-hoc re-rank the top results using a personalization signal

## The Hard Parts Nobody Talks About

The components above are well-documented. Here's what's actually hard in practice:

- **Evaluation:** Offline metrics (NDCG, MRR) don't always correlate with online metrics. A/B testing at scale is expensive and slow.
- **Index freshness:** Your catalog changes constantly. Keeping the index current without full rebuilds requires careful incremental update pipelines.
- **Query traffic distribution:** The top 1,000 queries account for a huge fraction of traffic, but the long tail is where most users actually struggle.
- **Position bias:** Users click on rank 1 more than rank 2 regardless of quality. Training on click data without correcting for position bias builds a model that learns to predict clicks, not relevance.

## Closing Thoughts

Building search at scale is fundamentally a systems problem as much as an ML problem. The ML components get most of the attention, but the infrastructure, evaluation frameworks, and data pipelines are equally important.

If you're building search for your product, [reach out](https://latentvaluelab.com/#contact) — this is exactly the kind of problem I work on.
