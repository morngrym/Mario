#include "render.h"

Render::Render()
{

}

Render::~Render()
{

}

void Render::render() const
{
    // For all layers in order
    for(unsigned int layerNumber = 0; layerNumber < 8; layerNumber++)
    {
        // Layers that are member of this layer
        for(unsigned int entityNumber = 0; entityNumber < SVar::getEntities().size(); entityNumber++)
        {
            // Create a temporary pointer for current entity
            Entity* const tempEntity = SVar::getEntities().at(entityNumber).get();

            // If entity is not nullptr and is a member of layerNumber
            if(tempEntity && tempEntity->getLayer().isLayerMemberOf(layerNumber))
            {
                // Draw the current sprite to screen
                SVar::getWindow().draw(tempEntity->getSpriteSheet().getCurrentSprite());
            }
        }
    }
}
