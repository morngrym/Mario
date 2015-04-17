#ifndef INPUT_H
#define INPUT_H


// This class is for controlling inputs

#include <vector>
#include "Core/action.h"

class Input
{
public:
    Input();
    ~Input();

    // Updates situations of actions
    void HandleInput();

private:
    // Actions for game
    std::vector<Action> m_actions;
};

#endif // INPUT_H
