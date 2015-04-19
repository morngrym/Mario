#ifndef SPRITESHEET_H
#define SPRITESHEET_H


// This class is for sprite animations
//
// Use m_texture to load the texture and load
// m_spriteRects to hold the info of sprite
// positions
//
// <type> is for whatever file we use, could be JSON
//
// This class is incomplete, in constructor it
// should load from a <type> file the texture and
// sprite rectangles as an array
//
// TODO: Complete class load from whatever <type> map is level

#include <vector>
#include <memory>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

class SpriteSheet
{
public:
    SpriteSheet(sf::Texture& texture);
    ~SpriteSheet();

    // Sprite pointer that holds current sprite
    const sf::Sprite * const getCurrentSprite();

    // Add sprite rectangles in order
    void addNextSpriteRect(sf::Rect<int> rect);

private:
    // Holds the position of sprites in the texture
    std::vector<sf::Rect<int>> m_spriteRectangles;

    // Texture that holds the sprite sheet.
    // Texture can be used at other classes
    // so it is a shared pointer
    std::shared_ptr<sf::Texture> m_texture;

    // Integer that holds current Sprite
    unsigned int m_currentSpriteRectNumber;

    // Sprite that holds current to be used
    std::unique_ptr<sf::Sprite> m_currentSprite;
};

#endif // SPRITESHEET_H
