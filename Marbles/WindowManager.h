#pragma once
#include "Vector2.h"
#include <GL/glut.h>

class WindowManager
{
	Vec2 windowSize;

	void SetupWindow();
public:
	void CreateWindow(Vec2 size);
};

