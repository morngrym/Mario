#include "game.h"

Game::Game()
    :m_inputHandler()
{
    // SVar class have to be initialized here
    SVar::initialize();
}

Game::~Game()
{

}

void Game::Run()
{
    while (SVar::getWindow().isOpen())
    {
        // Check events that are triggered
        sf::Event event;
        while (SVar::getWindow().pollEvent(event))
        {
            // If close button is pressed, close the window
            if (event.type == sf::Event::Closed)
                SVar::getWindow().close();
        }

        // Clear buffer
        SVar::getWindow().clear(sf::Color::Black);

        // Display buffer at screen
        SVar::getWindow().display();
    }
}
