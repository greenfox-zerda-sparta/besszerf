#ifndef KILLERS_H_
#define KILLERS_H_
#include "point2d.h"
#include "util.h"
#include "randomboard.h"
#include "gameengine2.hpp"

class Killers {
  public:
    Killers();
    Killers(const board &myBoard);
    Killers(const board &myBoard, const std::vector<Point2d> &killers_positions);
    virtual void draw(GameContext& context);
    virtual void move(GameContext& context);
    virtual ~Killers() {};
    Point2d get_position();
    std::string get_image();
  protected:
    static board gameBoard;
    Point2d position;
    std::string image;
    static std::vector<Point2d> killers_positions;
    void generate_random_position();
    bool is_a_good_position(Point2d &_position);
};

#endif /* KILLERS_H_ */
