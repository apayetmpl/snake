#include "snakeController.h"
#include <thread>
#include <chrono>
using namespace std;

SnakeController::SnakeController(SnakeView *pView, SnakeModel *pModel){
    this->pModel = pModel;
    this->pView = pView;
    this->pModel->newGame();
}

SnakeController::~SnakeController(void)
{
    
}

void SnakeController::start(void){
    while (!this->pModel->gameOver)
    {
        pModel->step();
        pView->draw();
        std::chrono::milliseconds timespan(1000 - (20*this->pModel->gameSpeed));
        std::this_thread::sleep_for(timespan);
    }
}

/* EOF snakeController.cpp */