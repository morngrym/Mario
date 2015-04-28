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
        for(std::unique_ptr<Entity>& entity : SVar::getEntities())
        {
            // If entity is not nullptr and is a member of layerNumber
            if(entity && entity->getLayer().isLayerMemberOf(layerNumber))
            {
                // Draw the current sprite to screen
                SVar::getWindow().draw(entity->getSpriteSheet().getCurrentSprite());
            }
        }
    }
}
