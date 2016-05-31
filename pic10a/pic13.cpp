#include <iostream>
using namespace std;


class Date{
 public:
  Date();
  Date(int, int, int);
  int get_day();
  int get_month();
  int get_year();
  void set_day();
  void set_month();
  void set_year();
  void print();
  friend ostream& operator<<(ostream&, const Date&);
  bool is_valid() const;
  Date next_date();
  void operator+=(int day2);
  
 private:
  int day;
  int month;
  int year;
};

bool Date::is_valid() const
{
  if(year<0) return false;
  if(month > 12 || month < 0 ) return false;
  if(day > 31 || day < 1) return false;
  

}


ostream& operator<<(ostream& os, const Date& dt)
{
  os << dt.month << '/' << dt.day << '/' << dt.year;
  return os;
}

Date::Date()
{
  day = 0;
  month = 0;
  year = 0;
}

Date::Date(int m, int d, int y)
{
  day = d;
  month = m;
  year = y;
}

int Date::get_day()
{
  return day;
}

int Date::get_month()
{
  return month;
}

int Date::get_year()
{
  return year;
}

void Date::print()
{
  cout<<month<<"/"<<day<<"/"<<year<<endl;
}

void Date::operator+=(int d)
{
  day = day + d;
}


int main(int argc, char *argv[])
{
  Date day1;
  Date day2(12, 1, 2015);
  day1.print();
  day2.print();
  day1+=1;
  cout<<day1<<endl;
  day1.print();
  return 0;
}
