#include "WindowManager.h"

std::unique_ptr<WindowManager> initWidow(const char* title, int x, int y, int w, int h, Uint32 window_flags)
{
	return std::make_unique<WindowManager>(title, x, y, w, h, window_flags);
}
