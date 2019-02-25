#include <stdexcept>
#include <sstream>
#include <bitset>

#include "MazeCard.h"

namespace labyrinth {

MazeCard::InstancesCounter MazeCard::T_COUNTER{6, 0, 12, 0};
MazeCard::InstancesCounter MazeCard::L_COUNTER{16, 0, 4, 0};
MazeCard::InstancesCounter MazeCard::I_COUNTER{12, 0, 0, 0};

void MazeCard::requireValidNbOfCards(MazeCard::InstancesCounter &ir,
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

void MazeCard::increment(MazeCard::InstancesCounter &ir, bool isMovable)
{
    isMovable?ir.TOTAL_NB_OF_MOVABLE_CARDS++:ir.TOTAL_NB_OF_STEADY_CARDS++;
    requireValidNbOfCards(ir, isMovable);
}

void MazeCard::decrement(MazeCard::InstancesCounter &ir, bool isMovable)
{
    isMovable?ir.TOTAL_NB_OF_MOVABLE_CARDS--:ir.TOTAL_NB_OF_STEADY_CARDS--;
}



MazeCard::MazeCard(const MazeCardShape &shape, bool isMovable)
    : shape_{shape}, isMovable_{isMovable}
{
    if (shape_.isT()) {
        increment(T_COUNTER, isMovable_);
    } else if (shape_.isL()) {
        increment(L_COUNTER, isMovable_);
    } else {
        increment(I_COUNTER, isMovable_);
    }
}

MazeCard::~MazeCard()
{
    if (shape_.isT()) {
        decrement(T_COUNTER, isMovable_);
    } else if (shape_.isL()) {
        decrement(L_COUNTER, isMovable_);
    } else {
        decrement(I_COUNTER, isMovable_);
    }
}

}
