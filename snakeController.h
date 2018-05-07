#ifndef _SNAKE_CONTROLLER_H_
#define _SNAKE_CONTROLLER_H_
#include "snakeView.h"
#include "snakeModel.h"
class SnakeController {
  private:
    SnakeModel *pModel;
    SnakeView *pView;
  public:
    SnakeController(SnakeView *pView, SnakeModel *pModel);
    ~SnakeController(void);
    void newGame(void);
    void start(void);
};
#endif /* _SNAKE_CONTROLLER_H_ */