#include <assert.h>

#include "commandLineView.h"
#include "snakeModel.h"

static void keyThread(CommandLineView *pView)
{
    int ch;
    snake_key_t pressedKey;
    while (pView->pModel->gameOver == false)
    {
        ch = getch();
        switch (ch) {
          case KEY_BACKSPACE:
            pressedKey = SNAKE_KEY_NEWGAME;
            break;
          case KEY_UP:
            pressedKey = SNAKE_KEY_SPEED_UP;
            break;
          case KEY_DOWN:
            pressedKey = SNAKE_KEY_SPEED_DOWN;
            break;
          case KEY_LEFT:
            pressedKey = SNAKE_KEY_LEFT;
            break;
          case KEY_RIGHT:
            pressedKey = SNAKE_KEY_RIGHT;
            break;
          case 'q':
            pressedKey = SNAKE_KEY_QUIT;
            break;
          default:
            /* TODO */
            continue;
        }
        pView->pModel->inputKey(pressedKey);
    }
}

CommandLineView::CommandLineView(SnakeModel * pSnakeModel)
{
    int i;
    /* init ncurses for keys input */
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    this->pModel = pSnakeModel;
    for (i=0;i<MAX_MESSAGES;i++)
    {
        this->logMessages[i]=(const char*)0;
    }
    this->pGameWin = newwin(pSnakeModel->height + 2, pSnakeModel->width + 2, 0, 0);
    this->pLogWin = newwin(MAX_MESSAGES + 1, pSnakeModel->width + 2, pSnakeModel->height + 2, 0);
    this->pInfoWin = newwin(10, 12, 0, pSnakeModel->width + 2);
    curLog = 0;
    /* start key listen thread */
    this->pKbdThread = new std::thread(keyThread, this);
    return;
};

CommandLineView::~CommandLineView(void)
{
    endwin();
};

void CommandLineView::log(const char *message)
{
    this->logMessages[this->curLog] = message;
    this->curLog++;
    if (this->curLog >= MAX_MESSAGES)
    {
        this->curLog = 0;
    };
};

void CommandLineView::draw(void)
{
    int i;
    
    /* Game window */
    for (i=0;i<this->pModel->width;i++)
    {
        /* top line */
        mvwaddch(this->pGameWin, 0, i, '#');
        /* bottom line */
        mvwaddch(this->pGameWin, this->pModel->height, i, '#');
    }
    for (i=0;i<this->pModel->height;i++)
    {
        /* left line */
        mvwaddch(this->pGameWin, i, 0, '#');
        /* right line */
        mvwaddch(this->pGameWin, i, this->pModel->width, '#');
    }
    /* Snake */
    mvwaddch(this->pGameWin, this->pModel->snakeY, this->pModel->snakeX, 'S');
    wrefresh(this->pGameWin);
    
    /* Log window */
    for (i=0;i<this->curLog;i++)
    {
        assert(this->curLog < MAX_MESSAGES);
        if (this->logMessages[i] != 0)
        {
            wmove(this->pLogWin, i, 0);
            waddstr(this->pLogWin, this->logMessages[i]);
        }
    }
    wrefresh(this->pLogWin);
    /* Info window */
    wmove(this->pInfoWin, 0, 0);
    waddstr(this->pInfoWin, "############");
    wmove(this->pInfoWin, 9, 0);
    waddstr(this->pInfoWin, "############");
    for (i=0;i<10;i++)
    {
        mvwaddch(this->pInfoWin, i, 11, '#');
    }
    wmove(this->pInfoWin, 2, 1);
    waddstr(this->pInfoWin, "Dir:");
    waddstr(this->pInfoWin, TEXT_DIR(this->pModel->snakeDir));
    wmove(this->pInfoWin, 3, 1);
    waddstr(this->pInfoWin, "Spd:");
    char buffer[3];/* max 50 */
    snprintf(buffer, sizeof(buffer), "%d",this->pModel->gameSpeed);
    waddstr(this->pInfoWin, buffer);
    wrefresh(this->pInfoWin);
};

/* EOF commandLineView.cpp */