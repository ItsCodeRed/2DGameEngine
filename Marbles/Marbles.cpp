#include "WindowManager.h"
#include <GL/glut.h>
#include "Vector2.h"
#include "CircleNode.h"
#include "PhysicsBody.h"
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

auto start_timestamp = Clock::now();
auto now_timestamp = Clock::now();

Vec2 size = Vec2(1280, 720);
Vec2 center = size / 2;

Node gameNode;

float current_time = 0;
float dt = 0;

void updateTime()
{
	auto latest_timestamp = Clock::now();

	current_time = std::chrono::duration<float>(latest_timestamp - start_timestamp).count();
	dt = std::chrono::duration<float>(latest_timestamp - now_timestamp).count();

	now_timestamp = latest_timestamp;
}

void display()
{
	updateTime();

	gameNode.Refresh(dt);

	glFlush();
}

void update()
{
	glutPostRedisplay(); // force a redraw of the screen
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	
	// creates window
	WindowManager windowManager = WindowManager();
	windowManager.CreateWindow(size);

	CircleNode entity(Vec2(0, 0), 50, Color(1, 0, 0, 1));
	PhysicsBody body = PhysicsBody();

	entity.AddNode(&body);

	gameNode.AddNode(&entity);

	// rendering callbacks
	glutDisplayFunc(display);
	glutIdleFunc(update);

	// starts main loop
	glutMainLoop();
	return 0;
}
