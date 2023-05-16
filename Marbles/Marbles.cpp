#include "WindowManager.h"
#include <GL/glut.h>
#include "Vector2.h"
#include "CircleRenderer.h"
#include "CircleCollider.h"
#include "Physics.h"
#include "PhysicsBody.h"
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

auto start_timestamp = Clock::now();
auto now_timestamp = Clock::now();

Vec2 size = Vec2(1280, 720); // size of the window

Node gameNode; // the main game node
Physics physics; // the physics manager node

float current_time = 0;
float dt = 0;
int fps = 0;

void updateTime() // calculates time since the program started, and the all crucial deltatime
{
	auto latest_timestamp = Clock::now();

	current_time = std::chrono::duration<float>(latest_timestamp - start_timestamp).count();
	dt = std::chrono::duration<float>(latest_timestamp - now_timestamp).count();

	fps = 1 / dt;

	now_timestamp = latest_timestamp;
}

void display()
{
	updateTime();

	glClear(GL_COLOR_BUFFER_BIT); // clears the screen in preperation for the next frame

	gameNode.Refresh(dt); // actually runs the game

	glFlush();
}

void update()
{
	glutPostRedisplay(); // force a redraw of the screen
}

void spawnBall(Vec2 startPos, float radius, Color color)
{
	Entity* entity = gameNode.AddNode<Entity>(); // creates new ball entity
	entity->transform->position = startPos;

	CircleRenderer* renderer = entity->AddNode<CircleRenderer>(); // adds a circle renderer
	renderer->radius = radius;
	renderer->color = color;

	physics.AddBody(entity->AddNode<PhysicsBody>()); // adds physicsbody to entity, and registers it to the physics engine
	CircleCollider* col = entity->AddNode<CircleCollider>();
	col->radius = radius;

	gameNode.AddNode(*entity);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	
	// creates window
	WindowManager windowManager = WindowManager();
	windowManager.CreateWindow(size);
	WindowManager::currentWindow = &windowManager;

	gameNode.AddNode(physics);

	for (int i = 0; i < 1000; i++) // spawns 1000 balls
	{
		Color color = Color(
			remainderf((static_cast<float>(i) / 200), 3), 
			0, 
			0);
		spawnBall(Vec2(((i * 49) % 1006) - 500, (i * 3747) % 300), 5, color);
	}

	gameNode.Initialize();

	// rendering callbacks
	glutDisplayFunc(display);
	glutIdleFunc(update);

	// starts main loop
	glutMainLoop();

	return 0;
}
