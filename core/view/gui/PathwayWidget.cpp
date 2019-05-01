#include <QLabel>
#include <QLayoutItem>
#include <QWidget>
#include <QWidgetItem>
#include <QPalette>

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

PathwayWidget::PathwayWidget(const labyrinth::model::MazeCard &card, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PathwayWidget),
    pathway(card)
{
    ui->setupUi(this);
    setupPathway(ui->pathway);


    if (pathway.isGoing(UP)) {
        ui->top->setStyleSheet("background-color: lightgreen");
    }
    if (pathway.isGoing(RIGHT)) {
        ui->right->setStyleSheet("background-color: lightgreen");
    }
    if (pathway.isGoing(DOWN)) {
        ui->bottom->setStyleSheet("background-color: lightgreen");
    }
    if (pathway.isGoing(LEFT)) {
        ui->left->setStyleSheet("background-color: lightgreen");
    }
    ui->center->setStyleSheet("background-color: lightgreen");
}

PathwayWidget::~PathwayWidget()
{
    delete ui;
}
