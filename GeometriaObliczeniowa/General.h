#pragma once



// Jak to zrobiæ ¿eby by³o dobrze
//  MenagerOkna 
//      |- konstruktor, destruktor
//      |- rendererFlags, windowFlags
//      |- SCREEN_WIDTH, SCREEN_HEIGHT
//      |- SDL_Window
//      |- SDL_Renderer
//      |- MenagerScenes
//      |   |- Scenes
//      |   *
//      |- MenagerObjects
//      *

#ifndef General
#define General

#include "SDL.h"
#include <iostream>
#include <vector>
#include <memory>
#include <utility>

struct Point
{
    int id, x, y;
};

inline std::ostream& operator<< (std::ostream& os, const Point& p)
{
    os << "id: " << p.id << " x: " << p.x << " y: " << p.y;
    return os;
}   

struct Line
{
    Point beginning, end;
};

inline std::ostream& operator<< (std::ostream& os, const Line& l)
{
    os << "beginning: " << l.beginning << " end: " << l.end;
    return os;
}

struct indexLine
{
    int id, id_beginning, id_end;
};

inline std::ostream& operator<< (std::ostream& os, const indexLine& l)
{
    os << "id: " << l.id << " id_beginning: " << l.id_beginning << " id_end: " << l.id_end;
    return os;
}

#endif // !General