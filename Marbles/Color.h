#pragma once
class Color
{
public:
	float r;
	float g;
	float b;
	float a;

	Color()
	{
		r = 1;
		g = 1;
		b = 1;
		a = 1;
	}

	Color(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		a = 1;
	}

	Color(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};

