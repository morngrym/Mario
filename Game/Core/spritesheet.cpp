#include "spritesheet.h"

SpriteSheet::SpriteSheet(sf::Texture &texture)
{
    m_texture.reset(&texture);
}

SpriteSheet::~SpriteSheet()
{

}

const sf::Sprite * const SpriteSheet::getCurrentSprite()
{
    // Set current rectangle of sprite
    m_currentSprite->setTextureRect(m_spriteRectangles.at(m_currentSpriteRectNumber));

    // Increase it one and if bigger than total size of rectangle vector
    // make it 0
    m_currentSpriteRectNumber++;
    if(m_currentSpriteRectNumber > m_spriteRectangles.size())
        m_currentSpriteRectNumber = 0;

    return m_currentSprite.get();
}
