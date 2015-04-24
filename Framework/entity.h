#ifndef ENTITY_H
#define ENTITY_H


// This class is for anything in the game. It could be a stone,
// a house, anything that is not controlled by the player or ai.
//
// My naming is sense is not good, so if you have any good name
// idea, please change it

#include "Core/spritesheet.h"
#include "Core/layer.h"

class Entity
{
public:
    // Pointer could be nullptr
    // Just want to ensure there is a texture
    Entity(sf::Texture &texture, unsigned int layerNumber);
    ~Entity();

    // Returns a pointer to SpriteSheet
    // Use this function to add SpriteRectangles
    SpriteSheet &getSpriteSheet();

    // Returns layer class
    const Layer& getLayer() const;

private:
    // Position of the entity
    sf::Vector2f m_worldPosition;

    // SpriteSheet of entity
    std::unique_ptr<SpriteSheet> m_spriteSheet;

    // Layer which our sprite will be drawn
    Layer m_layer;

};

#endif // ENTITY_H
