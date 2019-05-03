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

GameWindow::GameWindow(Game *game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    game_{game}
{
    ui->setupUi(this);
    setupBoard();
    setupPlayersData();
    setupCurrentMazecard();
    setupConnection();
    ui->board->setSpacing(2);
    ui->board->setContentsMargins(0, 0, 0, 0);
    connect(ui->rotate, SIGNAL(clicked(bool)), this, SLOT(rotateCurrentMazeCard()));
}

static void clear(QLayout *grid) {
    QLayoutItem *child;
    while ((child = grid->takeAt(0)) != 0);
}

void GameWindow::setupBoard() {
    clear(ui->board);
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

void GameWindow::setupCurrentMazecard() {
    clear(ui->currentMazeCard);
    MazeCard card = game_->getCurrentMazeCard();
    ui->currentMazeCard->addWidget(new PathwayWidget(card));
}

void GameWindow::setupConnection() {
    std::cout << "SETTING CONNECTIONS UP\n";
    for (int i = 0; i < ui->board->count(); ++i) {
        QLayoutItem *item = ui->board->itemAt(i);
        if (dynamic_cast<QWidgetItem *>(item)) {
            connect(item->widget(), SIGNAL(clicked()), this, SLOT(show()));
        }
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::rotateCurrentMazeCard() {
    game_->getCurrentMazeCard().rotate();
    setupCurrentMazecard();
}

void GameWindow::show() {
    std::cout << "CLICKED\n";
}

void GameWindow::insertCurrentMazeCard(int row, int column) {
    std::cout << "inserting the current card\n";
    //    game_->selectInsertionPosition(MazePosition{row, column});
//    game_->movePathWays();
}

