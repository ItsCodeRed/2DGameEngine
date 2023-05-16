#pragma once

#include "Vector2.h"
#include <GL/glut.h>

class WindowManager
{

	void SetupWindow();
public:
	Vec2 windowSize;

	static WindowManager* currentWindow;

	void CreateWindow(Vec2 size);
};
