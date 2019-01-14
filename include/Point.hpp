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

    const Point operator+(const Point&)const;
    const Point& operator+=(const Point&);
    bool operator==(const Point&)const;
    bool operator!=(const Point&)const;
};

#endif
