#ifndef PATHWAYWIDGET_H
#define PATHWAYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include "MazeCard.h"

namespace Ui {
class PathwayWidget;
}

class PathwayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PathwayWidget(const labyrinth::model::MazeCard &card,
                           unsigned row = 0,
                           unsigned column = 0,
                           QWidget *parent = 0);

    labyrinth::model::MazeCard getPathway() const { return pathway; }

    unsigned getRow() { return row_; }

    unsigned getColumn() { return column_; }

    ~PathwayWidget();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::PathwayWidget *ui;
    labyrinth::model::MazeCard pathway;
    unsigned row_;
    unsigned column_;
};

#endif // PATHWAYWIDGET_H
