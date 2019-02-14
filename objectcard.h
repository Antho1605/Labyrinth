#ifndef OBJECTCARD_H
#define OBJECTCARD_H
#include "object.h"

namespace labyrinth {

class ObjectCard
{
    enum class ObjectCardState {TURNED_OVER, IN_DECK};
    Object object_;
    ObjectCardState state_; //en a-t-on vraiment besoin?
public:
    ObjectCard(Object object)
        : object_{object}, state_{ObjectCardState::IN_DECK}
    {}
    Object getObject() { return object_; }
    ObjectCardState getState() { return state_; }
};

}

#endif // OBJECTCARD_H
