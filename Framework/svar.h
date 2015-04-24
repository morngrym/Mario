#ifndef SVAR_H
#define SVAR_H

#include <memory>
#include "SFML/Graphics/RenderWindow.hpp"
#include "entity.h"

// This is a static class to store most used variables such as window
// SVar is for Static Variables. I know, i didnt liked the name also

// This might as well could be a global but i dont like globals.
// Since static classes are also like globals. No problem

// WARNING : There will be an initialize function since constructors
// is a problem for static classes

class SVar
{
public:
    SVar();
    ~SVar();

    // Initialize class variables
    static bool initialize();

    // Get window
    static sf::RenderWindow &getWindow();

    // Returns a reference to entities exist in game
    static std::vector<std::unique_ptr<Entity>> &getEntities();

private:
    // It is a unique pointer since window should have only one owner
    static std::unique_ptr<sf::RenderWindow> m_window;

    // Array that holds Entities
    static std::vector<std::unique_ptr<Entity>> m_gameEntities;
};

#endif // SVAR_H
