#include "entity.h"

Entity::Entity(sf::Texture& texture)
    : m_spriteSheet(new SpriteSheet(texture))
{
}

Entity::~Entity()
{

}

SpriteSheet* Entity::getSpriteSheet()
{
    return m_spriteSheet.get();
}
