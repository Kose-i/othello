#ifndef Point_hpp
#define Point_hpp

class Point{

  private:
    int x,y;

  public:
    Point();
    ~Point();
    int get_x();
    int get_y();
    Point operator+(const Point&, const Point&);
    Point& operator+=(Point&, const Point&);

    void set_x();
    void set_y();

};

#endif
