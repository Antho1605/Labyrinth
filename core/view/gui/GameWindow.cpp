#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QErrorMessage>

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

static void clear(QLayout *grid) {
    QLayoutItem *child;
    while ((child = grid->takeAt(0)) != 0);
}

GameWindow::GameWindow(Game *game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    game_{game}
{
    ui->setupUi(this);
    setWindowTitle("Labyrinth");
    setupBoard();
    setupPlayersData();
    setupCurrentMazecard();
    setupConnection();
    ui->board->setSpacing(2);
    ui->board->setContentsMargins(0, 0, 0, 0);
    connect(ui->rotate, SIGNAL(clicked(bool)), this, SLOT(rotateCurrentMazeCard()));
}

void GameWindow::update(const nvs::Subject * subject) {
    std::cout << "UPDATE\n";
    this->setupBoard();
    this->setupCurrentMazecard();
    this->setupPlayersData();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::rotateCurrentMazeCard() {
    game_->getCurrentMazeCard().rotate();
    setupCurrentMazecard();
}

void GameWindow::handleClickedPathway() {
    QObject *obj = sender();
    PathwayWidget *pathway = dynamic_cast<PathwayWidget *>(obj);
    MazePosition pos{pathway->getRow(), pathway->getColumn()};
    try {
        if (game_->getCurrentPlayer().isReadyToMove()) {
            game_->selectPlayerPosition(pos);
            game_->moveCurrentPlayer();
        } else {
            game_->selectInsertionPosition(pos);
            game_->movePathWays();
        }
        std::cout << "(" << pos.getRow() << "; " << pos.getColumn() << ").\n";
        if (game_->getCurrentPlayer().isDone()) {
            game_->nextPlayer();
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
    setupConnection();
}

void GameWindow::setupBoard() {
    clear(ui->board);
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned col = 0; col < Maze::SIZE; ++col) {
            ui->board->addWidget(new PathwayWidget(game_, row, col), row, col);
        }
    }
}

void GameWindow::setupPlayersData() {
    clear(ui->players);
    for (auto player : game_->getPlayers()) {
        ui->players->addWidget(new PlayerDataWidget(player));
    }
}

void GameWindow::setupCurrentMazecard() {
    clear(ui->currentMazeCard);
    ui->currentMazeCard->addWidget(new PathwayWidget(game_));
}

void GameWindow::setupConnection() {
    for (int i = 0; i < ui->board->count(); ++i) {
        QLayoutItem *item = ui->board->itemAt(i);
        if (dynamic_cast<QWidgetItem *>(item)) {
            connect(item->widget(), SIGNAL(clicked()), this, SLOT(handleClickedPathway()));
        }
    }
}

