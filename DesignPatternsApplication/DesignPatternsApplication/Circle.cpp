#include "stdafx.h"
#include "Circle.hpp"

#include "cinder/gl/gl.h"

Circle::~Circle()
{
}

float Circle::calculateArea() const
{
	return radius * radius * 3.14159f;
}

void Circle::draw() const
{
	ci::gl::drawSolidCircle({ this->position.x, this->position.y }, 
				this->radius, 360);
}
