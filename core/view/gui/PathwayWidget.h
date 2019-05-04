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

    /**
     * @brief Constructs an instance of a PathwayWidget with the specified game
     * and board position.
     *
     * If the given position coordinates are not given, they are set to a
     * negative value and this widget shoould be used as a simple preview for
     * a pathway, not a board component.
     *
     * @param game is the game to represent a pathway for.
     * @param row is the maze row of the pathway to represent.
     * @param column is the maze column of the pathway to represent.
     * @param parent is the parent of this widget.
     */
    explicit PathwayWidget(labyrinth::model::Game *game,
                           int row = -1,
                           int column = -1,
                           QWidget *parent = 0);

    labyrinth::model::MazeCard getPathway() const;

    unsigned getRow() const { return row_; }

    unsigned getColumn() const { return column_; }

    bool isPreviewPathWayWidget() const { return row_ < 0 && column_ < 0; }

    ~PathwayWidget();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:

    void setupPlayers();

    void setupPathways();

    void setupObjectives();

    Ui::PathwayWidget *ui;
    labyrinth::model::Game *game_;
    int row_;
    int column_;
};

#endif // PATHWAYWIDGET_H
