#include "action.h"

Action::Action(sf::Keyboard::Key key, std::function<void()> pressedFunction, std::function<void()> releasedFunction)
    :m_isPressed(false)
    ,m_isReleased(false)
    ,m_isKeyUsed(true)
    ,m_key(key)
    ,m_whenPressed(pressedFunction)
    ,m_whenReleased(releasedFunction)
{

}

Action::Action(sf::Mouse::Button button, std::function<void()>  pressedFunction, std::function<void()> releasedFunction)
    :m_isPressed(false)
    ,m_isReleased(false)
    ,m_isKeyUsed(false)
    ,m_button(button)
    ,m_whenPressed(pressedFunction)
    ,m_whenReleased(releasedFunction)
{

}

Action::~Action()
{

}

void Action::changeKey(sf::Keyboard::Key key)
{
    m_isKeyUsed = true;     // Disables mouse button checking
    m_key = key;
}

void Action::changeButton(sf::Mouse::Button button)
{
    m_isKeyUsed = false;    // Disables key checking
    m_button = button;
}

void Action::update()
{
    // Needed for checking if key is released
    bool tempIsPressed = m_isPressed;
    // Set it false at the beginning
    m_isPressed = false;

    if(m_isKeyUsed)             // if keyboard is used
    {
        // If the key is pressed
        if(sf::Keyboard::isKeyPressed(m_key)) {
            m_isPressed = true;
        }
    }
    else                        // if mouse button is used
    {
        // If the button is pressed
        if(sf::Mouse::isButtonPressed(m_button)) {
            m_isPressed = true;
        }
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
