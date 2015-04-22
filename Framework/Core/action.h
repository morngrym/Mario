#ifndef ACTION_H
#define ACTION_H


// This class is for controlling key events
//
// Example: Right Arrow and D key moves the character
// to right. So MoveRight action will hold necessery keys
// to move right and when they are pressed game will move
// character to right

// TODO: Not that elegant at the moment, but we will improve

#include <functional>
#include "SFML/Window/Event.hpp"

class Action
{
public:
    Action(sf::Keyboard::Key key, std::function<void()>  pressedFunction, std::function<void()>  releasedFunction);
    ~Action();

    // Adds key to key vector
    void changeKey(sf::Keyboard::Key key);

    // Update actions situation
    void update();

    // Returns true if pressed
    bool isPressed();

    // Returns true if released
    bool isReleased();

private:
    // Key that holds action
    sf::Keyboard::Key m_key;

    // Boolean that holds if pressed or not
    bool m_isPressed;

    // Boolean that holds if released or not
    bool m_isReleased;

    // Function to call if pressed
    std::function<void()> m_whenPressed;

    //Function to call if released
    std::function<void()> m_whenReleased;

};

#endif // ACTION_H
