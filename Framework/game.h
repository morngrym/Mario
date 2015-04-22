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

    // Runs game loop
    void Run();

private:
    // Input class
    Input m_inputHandler;
};

#endif // GAME_H
