#include "WindowManager.h"

WindowManager* WindowManager::currentWindow = nullptr;

void WindowManager::CreateWindow(Vec2 size)
{
	windowSize = size;

	glutInitWindowSize(windowSize.x, windowSize.y);
	glutCreateWindow("Marbles");

	SetupWindow();
}

void WindowManager::SetupWindow()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-windowSize.x / 2, windowSize.x / 2, -windowSize.y / 2, windowSize.y / 2);
}