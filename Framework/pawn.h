#ifndef PAWN_H
#define PAWN_H

// Pawn is a game entity, but it has the ability to move
// and react

// TODO: Add move and react abilities


#include "entity.h"

class Pawn : public Entity
{
public:
    Pawn(sf::Texture &texture, unsigned int layerNumber);
    ~Pawn();
};

#endif // PAWN_H
