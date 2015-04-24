#ifndef RENDER_H
#define RENDER_H

#include "SFML/Graphics/RenderTarget.hpp"
#include "svar.h"

class Render
{
public:
    Render();
    ~Render();

    void render() const;
};

#endif // RENDER_H
