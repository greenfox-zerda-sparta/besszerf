#ifndef POINT2D_H_
#define POINT2D_H_
class Point2d {
  private:
    int x;
    int y;
  public:
    bool operator == (const Point2d&);
    void set_x(int x);
    void set_y(int y);
    int get_x();
    int get_y();
};
#endif /* POINT2D_H_ */
