#include "action.h"

Action::Action(sf::Keyboard::Key key, std::function<void()> pressedFunction, std::function<void()> releasedFunction)
    :m_isPressed(false)
    ,m_isReleased(false)
    ,m_type(ActionType::Key)
    ,m_key(key)
    ,m_whenPressed(pressedFunction)
    ,m_whenReleased(releasedFunction)
{

}

Action::Action(sf::Mouse::Button button, std::function<void()>  pressedFunction, std::function<void()> releasedFunction)
    :m_isPressed(false)
    ,m_isReleased(false)
    ,m_type(ActionType::Button)
    ,m_button(button)
    ,m_whenPressed(pressedFunction)
    ,m_whenReleased(releasedFunction)
{

}

Action::Action(uint8_t joystickButton, std::function<void()>  pressedFunction, std::function<void()>  releasedFunction)
    :m_isPressed(false)
    ,m_isReleased(false)
    ,m_type(ActionType::JoystickButton)
    ,m_joystickButton(joystickButton)
    ,m_whenPressed(pressedFunction)
    ,m_whenReleased(releasedFunction)
{

}

Action::~Action()
{

}

void Action::changeKey(sf::Keyboard::Key key)
{
    m_type = ActionType::Key;               // Disables mouse button checking
    m_key = key;
}

void Action::changeButton(sf::Mouse::Button button)
{
    m_type = ActionType::Button;            // Disables key checking
    m_button = button;
}

void Action::changeJoystickButton(uint8_t joystickButton)
{
    m_type = ActionType::JoystickButton;    // Disables key checking
    m_joystickButton = joystickButton;
}

void Action::update()
{
    // Needed for checking if key is released
    bool tempIsPressed = m_isPressed;
    // Set it false at the beginning
    m_isPressed = false;

    // Controlling if selected type is pressed
    switch (m_type) {
    case ActionType::Button:
        if(sf::Mouse::isButtonPressed(m_button)) {
            m_isPressed = true;
        }
        break;
    case ActionType::JoystickButton:
        if(sf::Joystick::isButtonPressed(0, m_joystickButton)){
            m_isPressed = true;
        }
        break;
    case ActionType::Key:
        if(sf::Keyboard::isKeyPressed(m_key)) {
            m_isPressed = true;
        }
        break;
    default:
        break;
    }

    // If the key is released
    if(tempIsPressed && !m_isPressed) {
        m_isReleased = true;
    }

    if(m_whenPressed != nullptr)
        m_whenPressed();

    if(m_whenReleased != nullptr)
        m_whenReleased();
}

bool Action::isPressed()
{
    return m_isPressed;
}

bool Action::isReleased()
{
    return m_isReleased;
}
