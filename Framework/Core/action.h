#ifndef ACTION_H
#define ACTION_H


// This class is for controlling key events without value
//
// Example: Space key triggers jump, so Jump will hold
// necessery key to jump and when it is pressed character
// will jump
//
// TODO: Not that elegant at the moment, but we will improve

#include <functional>
#include "SFML/Window/Event.hpp"

class Action
{
public:
    Action(sf::Keyboard::Key key, std::function<void()>  pressedFunction, std::function<void()>  releasedFunction);
    Action(sf::Mouse::Button button, std::function<void()>  pressedFunction, std::function<void()>  releasedFunction);
    ~Action();

    // Adds key to key vector
    void changeKey(sf::Keyboard::Key key);

    // Adds key to key vector
    void changeButton(sf::Mouse::Button button);

    // Update actions situation
    void update();

    // Returns true if pressed
    bool isPressed();

    // Returns true if released
    bool isReleased();

private:
    // Boolean that holds if pressed or not
    bool m_isPressed;

    // Boolean that holds if released or not
    bool m_isReleased;

    // Value to check if button or key is not assigned
    bool m_isKeyUsed;

    // Key that triggers action
    sf::Keyboard::Key m_key;

    // Button that triggers action
    sf::Mouse::Button m_button;

    // Function to call if pressed
    std::function<void()> m_whenPressed;

    //Function to call if released
    std::function<void()> m_whenReleased;

};

#endif // ACTION_H
