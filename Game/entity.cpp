#include "entity.h"

Entity::Entity(sf::Texture& texture, unsigned int layerNumber)
    : m_spriteSheet(new SpriteSheet(texture))
    , m_layer(layerNumber)
{
}

Entity::~Entity()
{

}

SpriteSheet* Entity::getSpriteSheet()
{
    return m_spriteSheet.get();
}
