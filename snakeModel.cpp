#include "snakeModel.h"
#include <assert.h>

SnakeModel::SnakeModel(unsigned char width, unsigned char height)
{
    int i;
    this->width = width;
    this->height = height;
    this->gameOver = false;
    this->snakeLen = 2;
    this->gameSpeed = 1;
    this->contents = new unsigned char*[height];
    for(i=0;i<this->height;i++)
    {
        this->contents[i] = new unsigned char[width];
    }
    this->newGame();
}
SnakeModel::~SnakeModel(void)
{
    int i;
    for(i=0;i<this->height;i++)
    {
        delete [] this->contents[i];
    }
    delete [] this->contents;
    return;
}

void SnakeModel::step(void)
{
    switch (this->snakeDir)
    {
      case SNAKE_DIR_RIGHT:
        this->snakeX++;
        break;
      case SNAKE_DIR_BOTTOM:
        this->snakeY++;
        break;
      case SNAKE_DIR_LEFT:
        this->snakeX--;
        break;
      case SNAKE_DIR_TOP:
        this->snakeY--;
        break;
      default:
        assert(false);
    }
    /* TODO: Add colision detection */
}
void SnakeModel::newGame(void)
{
    this->gameSpeed = 0;
    this->snakeX    = 1;
    this->snakeY    = this->height / 2;
    this->snakeDir = SNAKE_DIR_RIGHT;
}

void SnakeModel::inputKey(snake_key_t key)
{
    switch(key)
    {
        case SNAKE_KEY_SPEED_UP:
            if (this->gameSpeed < 50)
            {
                this->gameSpeed++;
            }
            break;
        case SNAKE_KEY_SPEED_DOWN:
            if (this->gameSpeed > 1)
            {
                this->gameSpeed--;
            }
            break;
        case SNAKE_KEY_LEFT:
            this->snakeDir = PREV_DIR(this->snakeDir);
            break;
        case SNAKE_KEY_RIGHT:
            this->snakeDir = NEXT_DIR(this->snakeDir);
            break;
        case SNAKE_KEY_QUIT:
            /* Quit */
            this->gameOver = true;
            break;
        default:
             /* Todo: log system */
            break;
    }
}

/* EOF snakeModel.cpp */