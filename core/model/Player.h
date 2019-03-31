#ifndef PLAYER_H
#define PLAYER_H
#include "MazePosition.h"
#include "ObjectCard.h"
#include "ObjectivesDeck.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

namespace labyrinth {

/**
 * @brief Represents a player of Labyrinth.
 */
struct Player {

    /**
     * @brief Represents the color of a player.
     */
    enum Color
    {
        RED,
        BLUE,
        YELLOW,
        GREEN
    };

    /**
     * @brief Represents the state of a player.
     */
    enum class State
    {
        WAITING,
        MOVED_PATHWAYS,
        MOVED_PIECE,
    };

private:

    /**
     * @brief Is this player color. Each player of a same game has a different
     * color.
     */
    Color color_;

    /**
     * @brief Is the position in the maze of this player.
     */
    MazePosition position_;

    /**
     * @brief Is the state of this player.
     */
    State state_;

    /**
     * @brief Are all the objectives this player must find in order to be the
     * winner.
     */
    ObjectivesDeck objectives_;

    /**
     * @brief Is the current objective of this player.
     */
    ObjectCard *currentObjective_;

public:

    /**
     * @brief Constructs this player. Initially this player has no objectif and
     * is waiting.
     *
     * @param color is the color of this player.
     * @param position is the position of this player.
     * @param objectives is the player`s objectives deck. The deck contains
     * less than 12 or lower than 6. (24 / 4 = 6 / 24 / 2 = 12).
     */
    Player(Color color, MazePosition position=MazePosition{0, 0})
        : color_{color},
          position_{position},
          state_{State::WAITING},
          objectives_{},
          currentObjective_{nullptr}
    {}

    /**
     * @brief Constructs player with default members values.
     */
    Player()
        : color_{BLUE},
          position_{},
          state_{State::WAITING},
          objectives_{},
          currentObjective_{nullptr}
    {}

    /**
     * @brief Gets this player color.
     *
     * @return this player color.
     */
    Color getColor() const{return color_;}

    /**
      * @brief getState gets the state of this player.
      *
      * @return the current state of this player.
      */
    State getState() const{ return state_; }

    /**
     * @brief Gets this player position.
     *
     * @return this player position.
     */
    MazePosition getPosition() const{ return position_; }

    /**
     * @brief Tells if a player is at the given position.
     *
     * @param position is the position of this player.
     * @return true if this player is at the given position.
     */
    bool isAt(const MazePosition &position) const { return position == position_; }

    /**
     * @brief Gets this player current objective.
     *
     * @return this player current objective.
     */
    ObjectCard *getCurrentObjective() const { return currentObjective_; }

    /**
     * @brief Gets the objectives of this player.
     *
     * @return the objectives of this player.
     */
    ObjectivesDeck getObjectives() const { return objectives_; }

    /**
     * @brief Sets this player state.
     *
     * @param state is the state of this player.
     */
    void setState(State state) {state_ = state;}

    /**
     * @brief Sets this player objectives. When the player gets his objectives
     * the current objective is immediatly set.
     *
     * @param cards are the objective cards of this player.
     */
    void setObjectives(const ObjectivesDeck &cards) {
        objectives_ = cards;
        nextObjective();
    }

    /**
     * @brief Moves this player position to the given coordinates.
     *
     * @param row is the row of this player position.
     * @param column is the column of this player position.
     */
    void moveTo(unsigned row, unsigned column) { position_.moveTo(row, column); }

    /**
     * @brief Turns the current objective over.
     */
    void turnCurrentObjectiveOver() { currentObjective_->turnOver(); }

    /**
     * @brief Sets the player current objective to the next one. After setting
     * this player deck, a call to this method set the player current objective
     * to the first one.
     */
    void nextObjective() {
        if (hasFoundAllObjectives()) {
            throw std::logic_error("All objectives have been turned over.");
        }
        currentObjective_ = objectives_.getCurrentCard();
    }

    /**
     * @brief Tells if this player has found his objectives.
     *
     * @return true if this player has found all his objectives.
     */
    bool hasFoundAllObjectives() const {
        return objectives_.areAllCardsTurnedOver();
    }

    bool isGoodPosition(const MazePosition &position) const{
        return (position.getColumn() == 0 && position.getRow() == 0) ||
                (position.getColumn() == 6 && position.getRow() == 0) ||
                (position.getColumn() == 0 && position.getRow() == 6) ||
                (position.getColumn()==6 && position.getRow()==6);
    }

    bool isWaiting(){
        return state_ == State::WAITING;
    }
    bool hasMovedPathWays(){
        return state_ == State::MOVED_PATHWAYS;
    }

    bool hasMoved(){
        return state_ == State::MOVED_PIECE;
    }

    bool isReturnedToInitialPos() const {
        switch(color_){
        case Color::RED :
            return position_.getRow() == 0 && position_.getColumn() == 0;
        case Color::YELLOW :
            return position_.getRow() == 0 && position_.getColumn() == 6;
        case Color::GREEN :
            return position_.getRow() == 6 && position_.getColumn() == 0;
        case Color::BLUE :
            return position_.getRow() == 6 && position_.getColumn() == 6;
        }
    }

    Player& operator=(const Player &that)
    {
        color_ = that.color_;
        position_ = that.position_;
        state_ = that.state_;
        objectives_ = that.objectives_;
        currentObjective_ = that.currentObjective_;
        return *this;
    }

};

inline Player::Color &operator++(Player::Color &color) {
    color = static_cast<Player::Color>(color + 1);
    return color;
}

inline bool operator==(const Player &lhs, const Player &rhs) {
    return lhs.getColor() == rhs.getColor();
}

}

#endif
