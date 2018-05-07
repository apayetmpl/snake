#ifndef _COMMAND_LINE_VIEW_H_
#define _COMMAND_LINE_VIEW_H_
#include <curses.h>
#include <thread>
#include "snakeView.h"
#include "snakeModel.h"
#define MAX_MESSAGES 20
class CommandLineView : public SnakeView {
  private:
    const char *logMessages[MAX_MESSAGES];
    unsigned char curLog;
    WINDOW * pGameWin;
    WINDOW * pLogWin;
    WINDOW * pInfoWin;
    std::thread *pKbdThread;
  public:
    SnakeModel * pModel;
    
    /* Constructor
     */
    CommandLineView(SnakeModel *pModel);
    /* Destructor
     */
    ~CommandLineView(void);
    void draw(void);
    void log(const char *message);
};
#endif /* _COMMAND_LINE_VIEW_H_ */