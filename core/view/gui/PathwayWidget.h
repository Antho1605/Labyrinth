#ifndef PATHWAYWIDGET_H
#define PATHWAYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include "Game.h"

namespace Ui {
class PathwayWidget;
}

class PathwayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PathwayWidget(labyrinth::model::Game *game,
                           unsigned row = 0,
                           unsigned column = 0,
                           QWidget *parent = 0);

    unsigned getRow() { return row_; }

    unsigned getColumn() { return column_; }

    ~PathwayWidget();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    void setPlayers();

    Ui::PathwayWidget *ui;
    labyrinth::model::Game *game_;
    unsigned row_;
    unsigned column_;
};

#endif // PATHWAYWIDGET_H
