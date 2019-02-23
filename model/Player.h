#ifndef PLAYER_H
#define PLAYER_H
#include "MazePosition.h"
#include "ObjectCard.h"
#include <vector>
#include <stdexcept>
#include <string>

namespace labyrinth {

/**
 * @brief Represents a player of Labyrinth.
 */
struct Player {

    /**
     * @brief Represents the color of a player.
     */
    enum class PlayerColor
    {
        RED,
        BLUE,
        YELLOW,
        GREEN
    };

    /**
     * @brief Represents the state of a player.
     */
    enum class PlayerState
    {
        WAITING,
        MOVING_PATHWAYS,
        MOVING_PIECE,
        PASS
    };

private:

    /**
     * @brief Is this player color. Each player of a same game has a different
     * color.
     */
    const PlayerColor color_;

    /**
     * @brief Is the age of this player.
     */
    const unsigned age_;

    /**
     * @brief Is the position in the maze of this player.
     */
    MazePosition position_;

    /**
     * @brief Is the state of this player.
     */
    PlayerState state_;

    /**
     * @brief Is the current objective of this player.
     */
    ObjectCard *currentObjective_;

    /**
     * @brief Are all the objectives this player must find in order to be the
     * winner.
     */
    std::vector<ObjectCard> objectives_;

public:

    /**
     * @brief Constructs this player. Initially this player has no objectif and
     * is waiting.
     *
     * @param color is the color of this player.
     * @param age is the age of this player.
     * @param position is the position of this player.
     * @param objectives is the player`s objectives stack. He can't be higher than 12 or lower than 6. (24/4=6 / 24/2=12)
     */
    Player(PlayerColor color, unsigned age, MazePosition position, std::vector<ObjectCard> objectives)
        : color_{color},
          age_{age},
          position_{position}, state_{PlayerState::WAITING},
          currentObjective_{nullptr},
          objectives_{!numberOfCardsValid(objectives)? throw std::invalid_argument("Wrong size of objectives : "
          + std::to_string(objectives.size())) : objectives}
    {
    }
    /**
     * @brief numberOfCardsValid tests if the number of cards in the stack of objectives is valid.
     * @param objectives the stack objectives of this player.
     * @return true if the number of cards in the stack of objectives is valid.
     */
    bool numberOfCardsValid(std::vector<ObjectCard> objectives){
        return objectives.size() == 6 || objectives.size() == 12 || objectives.size() == 8;
    }

    /**
     * @brief Gets this player color.
     *
     * @return this player color.
     */
    PlayerColor getColor_() const{return color_;}

    /**
     * @brief Gets this player age.
     *
     * @return this player age.
     */
    unsigned getAge_() const{return age_;}

    /**
     * @brief Gets this player position.
     *
     * @return this player position.
     */
    MazePosition getPosition() const{return position_;}

    /**
     * @brief Gets this player current objective.
     *
     * @return this player current objective.
     */
    ObjectCard getCurrentObjective() const{return *currentObjective_;}
    /**
     * @brief getCurrentObjective_ gets the pointer of the currentObjective.
     * @return the pointer of the currentObjective.
     */
    ObjectCard * getCurrentObjective_()const{return currentObjective_;}

    /**
     * @brief Sets this player position.
     *
     * @param position is the position of this player.
     */
    void setPosition(const MazePosition &position) { position_ = position; }

    /**
     * @brief Turn over the current objective and sets the player current objective to the next one.
     */
    void nextObjective();

    ObjectCard * getNextCard();

};

}

#endif // PLAYER_H
