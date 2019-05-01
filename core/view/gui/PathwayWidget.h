#ifndef PATHWAYWIDGET_H
#define PATHWAYWIDGET_H

#include <QWidget>
#include <QString>
#include "MazeCard.h"

namespace Ui {
class PathwayWidget;
}

class PathwayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PathwayWidget(const labyrinth::model::MazeCard &card, QWidget *parent = 0);
    ~PathwayWidget();

private:
    void rotate();
    void setImage();

    Ui::PathwayWidget *ui;
    labyrinth::model::MazeCard pathway;
    QString path;
};

#endif // PATHWAYWIDGET_H
