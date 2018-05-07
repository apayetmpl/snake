#include "snakeModel.h"
#include "commandLineView.h"
#include "snakeController.h"

int main (int argc, char*argv[])
{
    SnakeModel model(60,40);
    CommandLineView view (&model);
    SnakeController controller(&view,&model);
    model.newGame();
    controller.start();
    return 0;
}