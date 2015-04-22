#ifndef LAYER_H
#define LAYER_H


// This class is created for layer controlling which this games
// drawing logic is based on. For performance purposes bits are
// choosen to work with.
//
// Layer are from 0 to 7(0, 1...6, 7)

#include <stdint.h>

class Layer
{
public:
    Layer(unsigned int layerNumber);
    ~Layer();

    // Sets the layer that is wanted to 1
    void setLayer(unsigned int layerNumber);

    // Returns an 8 bit integer which represents layer
    uint8_t getLayer();

    // Checks if two layer classes are member of same layer
    bool isEqual(Layer b) const;

    // Check this layer with a number instead of another class
    bool isLayerMemberOf(unsigned int layerNumber) const;

private:
    uint8_t m_layer;
};

#endif // LAYER_H
