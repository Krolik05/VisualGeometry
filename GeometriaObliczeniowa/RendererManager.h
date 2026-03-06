#pragma once
#include "General.h"



class RendererManager
{
public:

    void drawCoordinateSystem();
    void drawPoints(const std::vector<Point>& points);
    void drawLines(const std::vector<indexLine>& lines, const std::vector<Point>& points);
    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void clearCavas();
    void presentCanvas();


    RendererManager(SDL_Window* win, int index, Uint32 renderer_flags) : renderer(nullptr), rendererFlags(renderer_flags)
    {
        renderer = SDL_CreateRenderer(win, index, renderer_flags);
        if (!renderer) {
            std::cout << "Failed initialize renderer: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }
    ~RendererManager()
    {
        if (renderer)
            SDL_DestroyRenderer(renderer);
    }
private:
    SDL_Renderer* renderer;
    Uint32 rendererFlags;
};

std::unique_ptr<RendererManager> initRenderer(SDL_Window* win, int index, Uint32 renderer_flags);
