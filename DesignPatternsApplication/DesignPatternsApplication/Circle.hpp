#pragma once

#include "Shape.hpp"
#include "vec2.h"

class Circle : public Shape
{
public:
	Circle() {};
	Circle(vec2f position, float radius) :
		position(position), radius(radius) {};
	virtual ~Circle();

	vec2f position;
	float radius;

	virtual float calculateArea() const override;
	virtual void draw() const override;
};

