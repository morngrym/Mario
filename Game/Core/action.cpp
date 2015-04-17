#include "action.h"

Action::Action(sf::Keyboard::Key key, std::function<void()> pressedFunction, std::function<void()> releasedFunction)
    :m_isPressed(false)
    ,m_isReleased(false)
    ,m_key(key)
    ,m_whenPressed(pressedFunction)
    ,m_whenReleased(releasedFunction)
{

}

Action::~Action()
{

}

void Action::changeKey(sf::Keyboard::Key key)
{
    m_key = key;
}

void Action::update()
{
    // Needed for checking if key is released
    bool tempIsPressed = m_isPressed;
    // Set it false at the beginning
    m_isPressed = false;

    // If the key is pressed, no need to check other keys
    if(sf::Keyboard::isKeyPressed(m_key)) {
        m_isPressed = true;
    }

    // If the key is released
    if(tempIsPressed && !m_isPressed) {
        m_isReleased = true;
    }
}

bool Action::isPressed()
{
    return m_isPressed;
}

bool Action::isReleased()
{
    return m_isReleased;
}
