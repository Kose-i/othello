#include "Point.hpp"

Point::Point(): x(), y()
{};

Point::Point(const int& x_, const int& y_): x(x_), y(y_)
{};

Point::~Point(){};

int Point::get_x()const{
  return x;
};
void Point::set_x(const int& x_){
  x = x_;
};

int Point::get_y()const{
  return y;
};
void Point::set_y(const int& y_){
  y = y_;
};

Point Point::operator+(const Point& pos)
{
  Point ans{};
  int t_x, t_y;
  t_x = x + pos.get_x();
  t_y = y + pos.get_y();
  ans.set_x(t_x);
  ans.set_y(t_y);
  return ans;
}

Point& Point::operator+=(const Point& pos)
{
  set_x(x + pos.get_x());
  set_y(y + pos.get_y());
  return *this;
}