#include "VisualCalculator.h"

void VisualCalculator::Play()
{
    //drawer->cameraCenterOnPoint({ 0, 0, 0 });

	
    SegmentLine f1{ {0,1,1}, { 0,0,0 } };
	//SegmentLine f2{ 0,2,1,0,0,0};

	Point p{ 1, 2, 1 };
	Point p1{ 2, 0, 0 };

	Point p2{ 3, 1, 1 };
	Point p3{ 4, 2, 0 };
	// test prostej i punktów wzglêdem niej
    Point p4{ 5, 2, 2 };
    Point p5{ 6, -1, -1 };
	// test odcinka
	Point p6{ 7, 4, 2 };


	data->addPoint(p);
	data->addPoint(p1);
	data->addPoint(p2);
	data->addPoint(p3);
	data->addPoint(p4);
	data->addPoint(p5);
	data->addPoint(p6);

	data->addLine({ 1, 1, 2});

	//sprawdzenie czy punkt le¿y na prostej i po której stronie jest
	std::cout << "Test przynale¿noœci punktu do prostej f1: " << std::endl;
    std::cout << "Czy punkt 3. le¿y na prostej f1? : " << isPointOnLine(p2, f1) << std::endl;
	std::cout << "Czy punkt 5. le¿y na prostej f1? : " << isPointOnLine(p4, f1) << std::endl;
	std::cout << "Czy punkt 6. le¿y na prostej f1? : " << isPointOnLine(p5, f1) << std::endl;

	std::cout << "Test przynale¿noœci punktu do odcinka f2: " << std::endl;
    std::cout << "Czy punkt 4. le¿y na odcinku f2? : " << isPointOnLineSegment(p3,{p, p1}) << std::endl;
	std::cout << "Czy punkt 1. le¿y na odcinku f2? : " << isPointOnLineSegment(p, { p, p1 }) << std::endl;
	std::cout << "Czy punkt 6. le¿y na odcinku f2? : " << isPointOnLineSegment(p5, { p, p1 }) << std::endl;
    std::cout << "Test sprawdzenia stron wzgêdem prostej/odcinka: " << std::endl;
	std::cout << "Czy punkt 4. le¿y po prawej stronie f2 : " << isPointOnRightSideOfLine(p3, { p, p1 }) << std::endl;
	std::cout << "Czy punkt 5. le¿y po prawej stronie f2 : " << isPointOnRightSideOfLine(p4, { p, p1 }) << std::endl;
	std::cout << "Czy punkt 5. le¿y po lewej stronie f2 : " << isPointOnLeftSideOfLine(p4, { p, p1 }) << std::endl;

    //przemiestwienie prostej f1 o wektor (0, -1, 1)
	std::cout << "Test przesuwania prostej f1 o wektor (0, -1, 1): " << std::endl;
    SegmentLine f2 = f1;
	moveLineByVector(f1, { 0, -1, 1 });

	//odbicie punktu p2 wzglêdem prostej f1
    std::cout << "Test Odbicia punktu wzgêdem prostej: " << std::endl;

	std::cout << "Odbicie p2 wzglêdem f1: " << std::endl;
	mirrorPointOnLine(p2, f1);
	p2.id = 8;
	data->addPoint(p2);




    drawer->adjustScaleToCavas(data->getPoints());
    drawer->cameraCenterOnPoint({ 0, 0, 0 });
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        //drawing
        drawer->setDrawColor(255, 255, 255, 255);
        drawer->clearCavas();

        drawer->setDrawColor(0, 0, 0, 255);
        drawer->drawLines(data->getLines(), data->getPoints());
        drawer->drawFullLine(f1);
        drawer->drawFullLine(f2);
        //drawer->drawExtendedLine(f2, -10, 10);
		drawer->writePointsData(data->getPoints());
        drawer->drawCoordinateSystem();
        drawer->setDrawColor(255, 0, 0, 255);
        drawer->drawPoints(data->getPoints());
        drawer->presentCanvas();
        //imput


        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
            if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                case SDLK_LEFT:
                    drawer->camera.x -= 100.0f / drawer->scale;
                    break;
				case SDLK_RIGHT:
					drawer->camera.x += 100.0f / drawer->scale;
                    break;
                case SDLK_UP:
					drawer->camera.y -= 100.0f / drawer->scale;
                    break;
                case SDLK_DOWN:
					drawer->camera.y += 100.0f / drawer->scale;
                    break;
                case SDLK_r:
					drawer->cameraCenterOnPoint({ 0, 0, 0 });
                    break;
                case SDLK_q:
					drawer->scale *= 1.1;
                    break;
                case SDLK_w:
                    drawer->scale *= 0.9;
					break;
				case SDLK_a:
                    drawer->scale = 1;
                }
			}

            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                //nie dzia³a :/
     //           if (e.button.button == SDL_BUTTON_LEFT)
     //           {
     //               Point p{ 0, e.button.x, e.button.y};
					//drawer->adjustPointFromCameraToCoordinates(p);
     //               drawer->cameraCenterOnPoint(p);
     //           }
			}
        }
        SDL_Delay(16);
    }
}

void VisualCalculator::LoadData(const char* file)
{
    data->loadData(file);
}
