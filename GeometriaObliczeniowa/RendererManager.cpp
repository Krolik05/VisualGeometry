#include "RendererManager.h"

std::unique_ptr<RendererManager> initRenderer(SDL_Window* win, int index, Uint32 renderer_flags)
{
	return std::make_unique<RendererManager>(win,index,renderer_flags);
}

void RendererManager::drawCoordinateSystem() // póŸniej
{
}

void RendererManager::drawPoints(const std::vector<Point>& points)
{
	for (Point p : points)
		SDL_RenderDrawPoint(renderer, p.x, p.y);
}

void RendererManager::drawLines(const std::vector<indexLine>& lines, const std::vector<Point>& points)
{
	Point a, b;
	for (indexLine l : lines)
	{
		a = points[l.id_beginning - 1];
		b = points[l.id_end - 1];
		SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
	}
}

void RendererManager::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void RendererManager::clearCavas()
{
	SDL_RenderClear(renderer);
}

void RendererManager::presentCanvas()
{
	SDL_RenderPresent(renderer);
}
