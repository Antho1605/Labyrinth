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

    explicit GameWindow(labyrinth::model::Game *game, QWidget *parent = 0);

    void update(const nvs::Subject * subject) override {
        this->setupBoard();
        this->setupCurrentMazecard();
    }

    ~GameWindow();

public slots:
    void rotateCurrentMazeCard();
    void show();
    void insertCurrentMazeCard(int row, int column);

private:
    void setupBoard();
    void setupPlayersData();
    void setupCurrentMazecard();
    void setupConnection();

    Ui::GameWindow *ui;
    labyrinth::model::Game *game_;
};

#endif // GAMEWINDOW_H
