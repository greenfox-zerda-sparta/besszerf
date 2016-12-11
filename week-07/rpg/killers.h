#ifndef KILLERS_H_
#define KILLERS_H_
#include "point2d.h"
#include "util.h"
#include "randomboard.h"
#include "gameengine2.hpp"

class Killers {
  public:
    Killers();
    Killers(const RandomBoard &myBoard);
    Killers(const RandomBoard &myBoard, const std::vector<Killers*> &killers);
    virtual ~Killers() {};
    virtual void draw(GameContext& context);
    virtual void move(GameContext& context);
  protected:
    static const RandomBoard* gameBoard;
    Point2d position;
    std::string image;
    void generate_random_position( const std::vector<Killers*> &killers);
    bool is_a_good_position(Point2d &_position,  const std::vector<Killers*> &killers);
};

#endif /* KILLERS_H_ */
