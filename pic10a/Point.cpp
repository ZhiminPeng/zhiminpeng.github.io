#include <iostream>
using namespace std;

class Point
{
 public:
  Point();
  Point(double, double);
  double get_x() const;
  double get_y() const;
  void set_x(double);
  void set_y(double);
 private:
  double x;
  double y;
};

Point::Point()
{
  x = 0;
  y = 0;
}

ostream& operator<<(std::ostream& os, const Point& obj)
{
  // write obj to stream
  cout<< "(" << obj.get_x() <<", "<< obj.get_y()<< ")";
  return os;
}


Point operator+(Point a, Point b)
{
  Point c;
  c.set_x(a.get_x() + b.get_x());
  c.set_y(a.get_y() + b.get_y());
  return c;
}

void Point::set_x(double xx)
{
  x = xx;
}

void Point::set_y(double yy)
{
  y = yy;
}

double Point::get_y() const
{
  return y;
}

double Point::get_x() const
{
  return x;
}


Point::Point(double xx, double yy)
{
  x = xx;
  y = yy;
}

int main(int argc, char *argv[])
{
  Point a(1,1);
  Point b(5, 5);
  Point c;
  cout<<a;
  cout<<b;
  c = a + b;
  cout<<c;
  return 0;
}
