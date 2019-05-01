#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "observer/Subject.h"
#include "observer/Observer.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow, public nvs::Observer
{
    Q_OBJECT

public:

    explicit GameWindow(const labyrinth::model::Game *game, QWidget *parent = 0);

    void update(const nvs::Subject * subject) override {}

    ~GameWindow();

private:
    void setupBoard();
    void setupPlayersData();

    Ui::GameWindow *ui;
    const labyrinth::model::Game *game_;
};

#endif // GAMEWINDOW_H
