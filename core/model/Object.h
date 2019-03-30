#ifndef OBJECTTYPE_H
#define OBJECTTYPE_H

namespace labyrinth {

/**
 * @brief Represents one of the object of the game.
 */
enum Object {
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
    NONE
};

inline Object &operator++(Object &object) {
    object = static_cast<Object>(object + 1);
    return object;
}

}

#endif // OBJECTTYPE_H
