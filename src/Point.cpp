#include "Point.hpp"

Point::Point(): x(), y()
{};
Point::Point(const int& x_, const int& y_): x(x_), y(y_)
{};
Point::~Point(){};

inline int Point::get_x(){
  return x;
};
inline void Point::set_x(const int& x_){
  this->x = x_;
};

inline int Point::get_y(){
  return y;
};
inline void Point::set_y(const int& y_){
  this->y = y_;
};

Point Point::operator+(const Point& pos)
{
  return Point{this->x + get_x(pos), this->y + get_y(pos)};
}

Point& Point::operator+=(const Point& pos)
{
  pos1.set_x(this->x + get_x(pos));
  pos1.set_y(this->y + get_y(pos));
  return *this;
}
