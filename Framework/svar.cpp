#include "svar.h"

// Static variables, must be shown here
std::unique_ptr<sf::RenderWindow> SVar::m_window;
std::vector<std::unique_ptr<Entity>> SVar::m_gameEntities;

SVar::SVar()
{

}

SVar::~SVar()
{

}

bool SVar::initialize()
{
    // Initializing m_window
    m_window.reset(new sf::RenderWindow(sf::VideoMode(800, 600), "Mario", sf::Style::Close | sf::Style::Titlebar));

    if(m_window.get() != nullptr)
        m_window->setFramerateLimit(60);

    m_gameEntities = std::vector<std::unique_ptr<Entity>>();
}

sf::RenderWindow &SVar::getWindow()
{
    // Returns reference holding window
    //
    // The pointer doesnt have to be deleted since it is already
    // owned by m_window
    return *m_window.get();
}

std::vector<std::unique_ptr<Entity>> &SVar::getEntities()
{
    return m_gameEntities;
}
