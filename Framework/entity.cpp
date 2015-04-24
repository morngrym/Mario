#include "entity.h"

Entity::Entity(sf::Texture& texture, unsigned int layerNumber)
    : m_spriteSheet(new SpriteSheet(texture))
    , m_layer(layerNumber)
{
}

Entity::~Entity()
{

}

SpriteSheet &Entity::getSpriteSheet()
{
    // Updating sprite position first
    m_spriteSheet->updateSpritePosition(m_worldPosition);

    return *m_spriteSheet.get();
}

const Layer& Entity::getLayer() const
{
    return m_layer;
}
