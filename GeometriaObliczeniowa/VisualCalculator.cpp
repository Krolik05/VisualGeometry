#include "VisualCalculator.h"

void VisualCalculator::Play()
{
    drawer->setDrawColor(255, 255, 255, 255);
    drawer->clearCavas();
    drawer->setDrawColor(0, 0, 0, 255);

    drawer->drawLines(data->getLines(), data->getPoints());
    drawer->presentCanvas();
    drawer->setDrawColor(0, 0, 255, 255);
	drawer->drawPoints(data->getPoints());

    SDL_Event e;
    bool quit = false;
    while (!quit)
    {




        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }
        SDL_Delay(16);
    }
}

void VisualCalculator::LoadData(const char* file)
{
    data->loadData(file);
}
