#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "observer/Subject.h"
#include "observer/Observer.h"

namespace Ui {
class GameWindow;
}

/**
 * @brief Is used to display the main window of the game.
 */
class GameWindow : public QMainWindow, public nvs::Observer
{
    Q_OBJECT

public:

    /**
     * @brief Constructs an instance of a GameWindow.
     *
     * @param game is the game to represent.
     * @param parent is the parent of this window.
     */
    explicit GameWindow(labyrinth::model::Game *game, QWidget *parent = 0);

    /**
     * @brief Updates this window content.
     *
     * @param subject is the subject.
     */
    void update(const nvs::Subject * subject) override;

    ~GameWindow();

public slots:

    /**
     * @brief Slot used to handle the rotation of the current maze card.
     */
    void rotateCurrentMazeCard();

    /**
     * @brief Slot used to handle a click on a pathway.
     */
    void handleClickedPathway();

private:

    void setupBoard();

    void setupPlayersData();

    void setupCurrentMazecard();

    void setupObjectives();

    void setupConnection();

    Ui::GameWindow *ui;

    labyrinth::model::Game *game_;
};

#endif // GAMEWINDOW_H
