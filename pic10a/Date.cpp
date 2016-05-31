#include <iostream>
using namespace std;


class Date
{
 private:
  int day;
  int month;
  int year;

  
 public:
  Date(); // default constructer
  Date(int, int, int); // customized constructer
  int get_day() const;
  int get_month() const;
  int get_year() const;
  bool is_valid();  
  //  Date next_date(Date);
  void print();
  void operator++();
};

// default constructer
Date::Date()
{
  day = 1;
  month = 1;
  year = 1900;
}

Date::Date(int m, int d, int y)
{
  day = d;
  month = m;
  year = y;
}

// check if the date if valid
bool Date::is_valid()
{
  if(month > 12 || month < 1) return false;
  if(day > 31 || day < 1) return false;
  if(year<1) return false;
  if((month==4 ||month==6 ||month==9 ||
      month==11) && day==31) return false;
  if(year%4==0 && month==2 && day>29)
    return false;
  else if(month==2 && year%4 !=0 && day>28)
    return false;
  return true;
}

inline Date next_date(Date day)
{
  Date nd;
  if(!day.is_valid()) return nd;

  nd = Date(day.get_month(), day.get_day()+1, day.get_year());
  if(nd.is_valid()) return nd;
  nd = Date(day.get_month()+1, 1, day.get_year()); if (nd.is_valid()) return nd;
  nd = Date(1, 1, day.get_year()+1); if (nd.is_valid()) return nd;
  return nd;
}

void Date::operator++()
{
  day +=1;
  if(!(*this).is_valid())
  {
    day = 1, month +=1;
    if(!(*this).is_valid())
    {
      day =1, month = 1, year+=1;
    }
  }
}

void Date::print()
{
  cout<<month<<"/"<<day<<"/"<<year<<endl;
}

int Date::get_day() const
{
  return day;
}

int Date::get_month() const
{
  return month;
}

int Date::get_year() const
{
  return year;
}



int main(int argc, char *argv[])
{
  Date day1;
  Date A(12, 31, 2015);
  A.print();
  ++A;
  A.print();  

  return 0;
}
