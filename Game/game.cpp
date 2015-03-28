#include "game.h"

Game::Game()
    :m_inputHandler()
{

}

Game::~Game()
{

}

void Game::Run()
{
    m_inputHandler.HandleInput();
}
