#include "Renderer.h"
#include <GL/glut.h>

void Renderer::SetColor(Color color)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(color.r, color.g, color.b, color.a);
}

void Renderer::DrawCircle(Vec2 center, float radius)
{
	int triangleAmount = 100; // resolution of the circle
	GLfloat fullRotation = 2.0f * 3.1415926f; // 2*pi radians is a full circle

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(center.x, center.y); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			center.x + (radius * cos(i * fullRotation / triangleAmount)),
			center.y + (radius * sin(i * fullRotation / triangleAmount))
		);
	}
	glEnd();
}
