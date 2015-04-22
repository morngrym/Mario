#include "layer.h"

Layer::Layer(unsigned int layerNumber)
{
    m_layer = 1u << layerNumber;
}

Layer::~Layer()
{
}

void Layer::setLayer(unsigned int layerNumber)
{
    m_layer = 1u << layerNumber;
}

uint8_t Layer::getLayer()
{
    return m_layer;
}

bool Layer::isEqual(Layer b) const
{
    // We are sure that layers are all initialized
    // and they have only one bit equal to 1
    return (m_layer & b.getLayer()) > 0;
}

bool Layer::isLayerMemberOf(unsigned int layerNumber) const
{
    return (m_layer & (1u << layerNumber)) > 0;
}
