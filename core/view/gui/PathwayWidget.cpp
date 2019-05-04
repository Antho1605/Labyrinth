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

static void initPathways(const QGridLayout *pathway) {
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

PathwayWidget::PathwayWidget(labyrinth::model::Game *game,
                             int row,
                             int column,
                             QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PathwayWidget),
    game_(game),
    row_{row},
    column_{column}
{
    ui->setupUi(this);
    setupPathways();
    if (!isPreviewPathWayWidget()) setupPlayers();
}

labyrinth::model::MazeCard PathwayWidget::getPathway() const {
    MazeCard pathway;
    if (isPreviewPathWayWidget()) {
        pathway = game_->getCurrentMazeCard();
    } else {
        pathway = game_->getMaze().getCardAt(MazePosition{row_, column_});
    }
    return pathway;
}

PathwayWidget::~PathwayWidget()
{
    delete ui;
}

void PathwayWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
        std::cout << "CLICKED\n";
    }
}

void PathwayWidget::setupPlayers() {
    for (auto player : game_->getPlayers()) {
        if (player.getPosition() == MazePosition{row_, column_}) {
            setPlayer(ui->center, player);
        }
    }
}

void PathwayWidget::setupPathways() {
    MazeCard pathway = getPathway();
    initPathways(ui->pathway);
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
}
