#ifndef _SNAKE_VIEW_H_
#define _SNAKE_VIEW_H_

class SnakeView {
  public:
    virtual void draw(void) = 0;
    virtual void log(const char *message) = 0;
};
#endif /* _SNAKE_VIEW_H_ */