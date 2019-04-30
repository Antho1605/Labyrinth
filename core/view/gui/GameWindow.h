#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "Game.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(const labyrinth::model::Game &game, QWidget *parent = 0);
    ~GameWindow();

private:
    void setupBoard();

    Ui::GameWindow *ui;
    labyrinth::model::Game game_;
};

#endif // GAMEWINDOW_H
