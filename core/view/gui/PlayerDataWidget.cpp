#include <QString>
#include <QStringBuilder>
#include <QPalette>

#include "PlayerDataWidget.h"
#include "ui_PlayerDataWidget.h"
#include "Player.h"
#include "ToString.h"

using namespace labyrinth;

static std::string getStatus(model::Player &player, bool isCurrentPlayer) {
    std::string status;
    if (isCurrentPlayer) {
        if (player.isReadyToMove()) {
            status += "is ready to move...";
        } else {
            status += "is ready to insert...";
        }
    } else {
        status += "is waiting...";
    }
    return status;
}

PlayerDataWidget::PlayerDataWidget(model::Player player,
                                   bool isCurrentPlayer,
                                   QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerDataWidget),
    player_(player)
{
    ui->setupUi(this);
    setupPlayerData(isCurrentPlayer);
    setupBackgroundColor();
}

void PlayerDataWidget::setupPlayerData(bool isCurrentPlayer) {
    std::string name = view::toString(player_.getColor()) + " player";
    std::string status = getStatus(player_, isCurrentPlayer);
    std::string objective = view::toString(player_.getCurrentObjective().getObject());
    ui->player->setText(QString::fromStdString(name));
    ui->status->setText(QString::fromStdString(status));
    ui->objective->setText(QString::fromStdString(objective));
}

static QString getBackgroundStyle(const model::Player &player) {
    QString backgroundStyle = "background-color:";
    switch (player.getColor()) {
    case model::Player::RED:
        backgroundStyle += "red;";
        break;
    case model::Player::BLUE:
        backgroundStyle += "lightblue;";
        break;
    case model::Player::YELLOW:
        backgroundStyle += "yellow;";
        break;
    case model::Player::GREEN:
        backgroundStyle += "lightgreen;";
    }
    return backgroundStyle;
}

void PlayerDataWidget::setupBackgroundColor() {
    setStyleSheet(getBackgroundStyle(player_));
}

PlayerDataWidget::~PlayerDataWidget()
{
    delete ui;
}
