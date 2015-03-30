#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "svar.h"
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
