#include <QLabel>
#include <QLayoutItem>
#include <QWidget>
#include <QWidgetItem>
#include <QPalette>
#include <QMouseEvent>

#include <iostream>
#include <vector>

#include "Maze.h"
#include "PathwayWidget.h"
#include "ui_PathwayWidget.h"

using namespace labyrinth::model;

static void setupPathway(const QGridLayout *pathway) {
    for (int i = 0; i < pathway->count(); ++i) {
        QLayoutItem *item = pathway->itemAt(i);
        if (dynamic_cast<QWidgetItem *>(item)) {
            item->widget()->setStyleSheet("background-color: green;");
        }
    }
}

static void setAsPathway(QLabel *label) {
    label->setStyleSheet("background-color: lightgreen");
}

PathwayWidget::PathwayWidget(const labyrinth::model::MazeCard &card, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PathwayWidget),
    pathway(card)
{
    ui->setupUi(this);
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
}

void PathwayWidget::mouseMoveEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}

PathwayWidget::~PathwayWidget()
{
    delete ui;
}
