#include <QString>
#include <QStringBuilder>
#include <QPalette>

#include "PlayerDataWidget.h"
#include "ui_PlayerDataWidget.h"
#include "Player.h"
#include "ToString.h"

using namespace labyrinth;

PlayerDataWidget::PlayerDataWidget(model::Player player, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerDataWidget),
    player_(player)
{
    ui->setupUi(this);
    setupPlayerData();
    setupBackgroundColor();
}

void PlayerDataWidget::setupPlayerData() {
    std::string name = view::toString(player_.getColor()) + " player";
    std::string status = view::toString(player_.getState());
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
    case model::Player::BLUE:
        backgroundStyle += "lightblue;";
    case model::Player::YELLOW:
        backgroundStyle += "yellow;";
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
