#ifndef _SNAKE_MODEL_H_
#define _SNAKE_MODEL_H_
typedef enum {
    SNAKE_KEY_LEFT = 0,
    SNAKE_KEY_RIGHT,
    SNAKE_KEY_QUIT,
    SNAKE_KEY_SPEED_UP,
    SNAKE_KEY_SPEED_DOWN,
    SNAKE_KEY_NEWGAME
} snake_key_t;

typedef enum
{
    SNAKE_DIR_RIGHT = 0,
    SNAKE_DIR_BOTTOM,
    SNAKE_DIR_LEFT,
    SNAKE_DIR_TOP,
    SNAKE_DIR_MAX
} snake_dir_e;

#define NEXT_DIR(dir) ((dir==SNAKE_DIR_RIGHT)?SNAKE_DIR_BOTTOM:((dir==SNAKE_DIR_BOTTOM)?SNAKE_DIR_LEFT:((dir==SNAKE_DIR_LEFT)?SNAKE_DIR_TOP:SNAKE_DIR_RIGHT)))
#define PREV_DIR(dir) ((dir==SNAKE_DIR_RIGHT)?SNAKE_DIR_TOP:((dir==SNAKE_DIR_BOTTOM)?SNAKE_DIR_RIGHT:((dir==SNAKE_DIR_LEFT)?SNAKE_DIR_BOTTOM:SNAKE_DIR_LEFT)))
#define TEXT_DIR(dir) ((dir==SNAKE_DIR_RIGHT)?"Right":((dir==SNAKE_DIR_BOTTOM)?"Down ":((dir==SNAKE_DIR_LEFT)?"Left ":"Up   ")))

class SnakeModel {
  private:
    unsigned char snakeLen;
    unsigned char **contents;
  public:
    /* Speed  0: wait   1 s between two frames
       Speed  1: wait 980 ms
       Speed  2: wait 960 ms
       Speed 49: wait  20 ms
       Speed 50: wait   0 ms
     */
    unsigned char gameSpeed;
    bool gameOver;
    unsigned char width;
    unsigned char height;
    unsigned char snakeX;
    unsigned char snakeY;
    snake_dir_e snakeDir;
    
    SnakeModel(unsigned char width, unsigned char height);
    ~SnakeModel(void);
    void step(void);
    void newGame(void);
    void inputKey(snake_key_t key);
};
#endif /* _SNAKE_MODEL_H_ */
