#ifndef Point_hpp
#define Point_hpp

class Point{

  private:
    int x,y;

  public:
    Point();
    Point(const int&,const int&);
    ~Point();

    int get_x()const;
    int get_y()const;

    void set_x(const int&);
    void set_y(const int&);

    Point operator+(const Point&);
    Point& operator+=(const Point&);
};

#endif
