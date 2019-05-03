#include <QLabel>
#include <QLayoutItem>
#include <QWidget>
#include <QWidgetItem>
#include <QPalette>
#include <QMouseEvent>

#include <iostream>
#include <vector>
#include <iostream>

#include "Maze.h"
#include "PathwayWidget.h"
#include "ui_PathwayWidget.h"

using namespace labyrinth::model;

static void setupPathway(const QGridLayout *pathway) {
    for (int i = 0; i < pathway->count(); ++i) {
        QLayoutItem *item = pathway->itemAt(i);
        if (dynamic_cast<QWidgetItem *>(item)) {
            item->widget()->setStyleSheet("background-color: brown;");
        }
    }
}

static void setAsPathway(QLabel *label) {
    label->setStyleSheet("background-color: lightgreen");
}

PathwayWidget::PathwayWidget(labyrinth::model::Game *game,
                             unsigned row,
                             unsigned column,
                             QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PathwayWidget),
    game_(game),
    row_{row},
    column_{column}
{
    ui->setupUi(this);

    MazeCard pathway = game_->getMaze().getCardAt(MazePosition{row_, column_});
    setupPathway(ui->pathway);
    if (pathway.isGoing(UP)) {
        setAsPathway(ui->top);
    }
    if (pathway.isGoing(RIGHT)) {
        setAsPathway(ui->right);
    }
    if (pathway.isGoing(DOWN)) {
        setAsPathway(ui->bottom);
    }
    if (pathway.isGoing(LEFT)) {
        setAsPathway(ui->left);
    }
    setAsPathway(ui->center);
    setPlayers();
}

static void setPlayer(QLabel *label, labyrinth::model::Player player) {
    QString style;
    switch (player.getColor()) {
    case labyrinth::model::Player::RED:
        style += "background-color: red";
        break;
    case labyrinth::model::Player::BLUE:
        style += "background-color: blue";
        break;
    case labyrinth::model::Player::YELLOW:
        style += "background-color: yellow";
        break;
    case labyrinth::model::Player::GREEN:
        style += "background-color: green";
    }
    label->setStyleSheet(style);
}

void PathwayWidget::setPlayers() {
    for (auto player : game_->getPlayers()) {
        if (player.getPosition() == MazePosition{row_, column_}) {
            setPlayer(ui->center, player);
        }
    }
}

void PathwayWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        std::cout << "CLICKED\n";
        emit clicked();
    }
}

PathwayWidget::~PathwayWidget()
{
    delete ui;
}
