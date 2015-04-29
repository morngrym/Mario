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
    enum class ActionType : uint8_t
    {
        Key,
        Button,
        JoystickButton
    };

    Action(sf::Keyboard::Key key, std::function<void()>  pressedFunction, std::function<void()>  releasedFunction);
    Action(sf::Mouse::Button button, std::function<void()>  pressedFunction, std::function<void()>  releasedFunction);
    Action(uint8_t joystickButton, std::function<void()>  pressedFunction, std::function<void()>  releasedFunction);
    ~Action();

    // Changes keyboard key, disables any other type
    void changeKey(sf::Keyboard::Key key);

    // Changes mouse button, disables any other type
    void changeButton(sf::Mouse::Button button);

    // Changes joystick button, disables any other type
    // This function is dangerous to use hardcoded, use it with interface
    // from user input. This way it is safer
    void changeJoystickButton(uint8_t joystickButton);

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
    ActionType m_type;

    // Key that triggers action
    sf::Keyboard::Key m_key;

    // Button that triggers action
    sf::Mouse::Button m_button;

    uint8_t m_joystickButton;

    // Function to call if pressed
    std::function<void()> m_whenPressed;

    //Function to call if released
    std::function<void()> m_whenReleased;

};

#endif // ACTION_H
