#ifndef OBJECTTYPE_H
#define OBJECTTYPE_H

namespace labyrinth {

/**
 * @brief Represents one of the object of the game.
 */
enum Object {

    /**
     * The following objects are set on the movable maze cards of a maze.
     */
    GHOST,
    GNOME,
    DRAGON,
    FAIRY,
    BAT,
    GENIE,
    OWL,
    SCARAB,
    RAT,
    SPIDER,
    BUTTERFLY,
    LIZARD,

    /**
     * The following objects are set on the steadt maze cards of a maze.
     */
    GRIMOIRE,
    PURSE_OF_GOLD,
    MAP,
    CROWN,
    KEYS,
    BONES,
    RING,
    TREASURE_CHEST,
    EMERALD,
    SWORD,
    CHANDELIER,
    HELMET,

    /**
     * Represents the absence of object on a maze card.
     */
    NONE

};

inline Object &operator++(Object &object) {
    object = static_cast<Object>(object + 1);
    return object;
}

}

#endif // OBJECTTYPE_H
