
#include "Renderer.h"


void render(Model* m, SDL_Renderer* rend)
{
    SDL_RenderSetScale(rend,  1.0,  1.0);
    double x1 = 0;
    double y1 = m->a * x1 + m->b;
    double x2 = 1;
    double y2 = m->a * x2 + m->b;
    x1 *= SCALE;
    y1 *= SCALE;
    x2 *= SCALE;
    y2 *= SCALE;
    y1 = SCALE - y1;
    y2 = SCALE - y2;
    SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
    SDL_RenderDrawLine(rend, x1, y1, x2, y2);
}
