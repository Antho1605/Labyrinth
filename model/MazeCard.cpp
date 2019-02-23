#include <stdexcept>
#include <sstream>
#include <bitset>

#include "MazeCard.h"

namespace labyrinth {

MazeCard::InstancesRestriction MazeCard::T_RESTRICTION{6, 0, 12, 0};
MazeCard::InstancesRestriction MazeCard::L_RESTRICTION{16, 0, 4, 0};
MazeCard::InstancesRestriction MazeCard::I_RESTRICTION{12, 0, 0, 0};

void MazeCard::update(MazeCard::InstancesRestriction &ir, bool isMovable)
{
    isMovable?ir.TOTAL_NB_OF_MOVABLE_CARDS++:ir.TOTAL_NB_OF_STEADY_CARDS++;
}

void MazeCard::requireValidNbOfCards(MazeCard::InstancesRestriction &ir,
                                     bool isMovable) const
{
    if (isMovable) {
        if (ir.MAX_NB_OF_MOVABLE_CARDS < ir.TOTAL_NB_OF_MOVABLE_CARDS) {
            throw std::logic_error("All movable maze cards are instantiated.");
        }
    } else {
        if (ir.MAX_NB_OF_STEADY_CARDS < ir.TOTAL_NB_OF_STEADY_CARDS) {
            throw std::logic_error("All steady maze cards are instantiated.");
        }
    }
}

MazeCard::MazeCard(const MazeCardShape &shape, bool isMovable)
    : shape_{shape}, isMovable_{isMovable}
{
    if (shape_.isT()) {
        update(T_RESTRICTION, isMovable);
    } else if (shape_.isL()) {
        update(L_RESTRICTION, isMovable);
    } else {
        update(I_RESTRICTION, isMovable);
    }
}

}
