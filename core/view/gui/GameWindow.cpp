#include <QLabel>
#include <QPixmap>
#include <QString>

#include <string>
#include <iostream>

#include "Game.h"
#include "MazeCard.h"
#include "GameWindow.h"
#include "PathwayWidget.h"
#include "ui_GameWindow.h"
#include "observer/Subject.h"
#include "observer/Observer.h"
#include "PlayerDataWidget.h"

using namespace labyrinth::model;

GameWindow::GameWindow(const Game *game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    game_{game}
{
    ui->setupUi(this);
    setupBoard();
    setupPlayersData();
    ui->board->setSpacing(2);
    ui->board->setContentsMargins(0, 0, 0, 0);
}

void GameWindow::setupBoard() {
    for (int row = 0; row < Maze::SIZE; ++row) {
        for (int col = 0; col < Maze::SIZE; ++col) {
            MazeCard card = game_->getMaze().getCardAt({row, col});
            ui->board->addWidget(new PathwayWidget(card), row, col);
        }
    }
}

void GameWindow::setupPlayersData() {
    for (auto player : game_->getPlayers()) {
        ui->players->addWidget(new PlayerDataWidget(player));
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}
