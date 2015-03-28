#ifndef GAME_H
#define GAME_H

#include "input.h"

class Game
{
public:
    Game();
    ~Game();

    void Run();

private:
    Input m_inputHandler;
};

#endif // GAME_H
