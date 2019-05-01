#include <QPixmap>
#include <QSize>
#include <iostream>

#include "PathwayWidget.h"
#include "ui_PathwayWidget.h"

using namespace labyrinth::model;

static QString getPathToImage(const MazeCard &card) {
    QString path = ":/resources/images/";
    if (card.isI()) {
        path += "I.png";
    } else if (card.isL()) {
        path += "L.png";
    } else if (card.isT()) {
        path += "T.png";
    } else {
        throw std::invalid_argument("getPathToImage: not a valid card.");
    }
    return path;
}

void PathwayWidget::rotate() {

}

void PathwayWidget::setImage() {
    QPixmap image;
    if (!image.load(path)) {
        throw std::invalid_argument(path.toStdString() + " cannot be loaded!\n");
    }
    ui->pathway->setPixmap(image.scaled(75, 75, Qt::KeepAspectRatio));
}

PathwayWidget::PathwayWidget(const labyrinth::model::MazeCard &card, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PathwayWidget),
    pathway(card),
    path(getPathToImage(card))
{
    ui->setupUi(this);
    setImage();
    ui->pathway->setStyleSheet("border: 1px solid black");
}

PathwayWidget::~PathwayWidget()
{
    delete ui;
}
