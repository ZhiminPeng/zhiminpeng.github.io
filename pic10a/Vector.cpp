#include <iostream>
using namespace std;

class Vector
{
 public:
  Vector();
  Vector(double, double);
  double get_x() const;
  double get_y() const;
  void set_x(double);
  void set_y(double);
  Vector operator+(const Vector&);
  
 private:
  double x;
  double y;

};

Vector::Vector()
{
  x = 0.;
  y = 0.;
}

Vector::Vector(double xx, double yy)
{
  x = xx;
  y = yy;
}

void Vector::set_x(double xx)
{
  x = xx;
}

void Vector::set_y(double yy)
{
  y = yy;
}
double Vector::get_x() const
{
  return x;
}
double Vector::get_y() const
{
  return y;
}
/*
Vector operator+(const Vector& a, const Vector& b)
{
  Vector c;
  c.set_x(a.get_x() + b.get_x());
  c.set_y(a.get_y() + b.get_y());
  return c;
}
*/


Vector Vector::operator+(const Vector& b)
{
  Vector c;
  c.set_x(x + b.get_x());
  c.set_y(y + b.get_y());  
  return c;
}








// point wise multiplication
Vector operator*(Vector& a, Vector& b)
{
  Vector c;
  c.set_x(a.get_x() * b.get_x());
  c.set_y(a.get_y() * b.get_y());
  return c;
}


// point wise division
Vector operator/(const Vector& a, const Vector& b)
{
  Vector c;
  c.set_x(a.get_x() / b.get_x());
  c.set_y(a.get_y() / b.get_y());
  return c;
}


double dot(const Vector& a, const Vector& b)
{
  return a.get_x() * b.get_x() + a.get_y() * b.get_y();
}



Vector operator-(const Vector& a, const Vector& b)
{
  Vector c;
  c.set_x(a.get_x() - b.get_x());
  c.set_y(a.get_y() - b.get_y());
  return c;
}



ostream& operator<<(ostream& os, const Vector& obj)
{
  cout<<"("<<obj.get_x() << ", "<< obj.get_y()<< ")";
  return os;
}

int main(int argc, char *argv[])
{
  Vector a(1, 1);
  Vector b(0., 0.);
  Vector c;
  c = a + b;
  Vector d;

  d = a * b;
  cout<<a<<endl;
  cout<<b<<endl;
  cout<<c<<endl;
  cout<<d<<endl;
  return 0;
}
