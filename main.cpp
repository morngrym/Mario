#include "Game/game.h"

// NOTE: Just create raw pointers that holds textures
// and forget about them. Entity and Pawn classes will
// handle the rest

int main()
{
    // Initialize game object
    Game game;

    // Run function handles game loop
    game.Run();

    return 0;
}
