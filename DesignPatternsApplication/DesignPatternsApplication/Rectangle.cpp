#include "stdafx.h"
#include "Rectangle.hpp"
#include "cinder/gl/gl.h"

Rectangle::~Rectangle()
{
}

float Rectangle::calculateArea() const
{
	return size.x * size.y;
}

void Rectangle::draw() const
{
	ci::gl::drawSolidRect({ this->position.x, this->position.y,
				this->position.x + this->size.x, this->position.y + this->size.y });
}

void Rectangle::accept(AbstractShapeVisitor& visitor)
{
	visitor.visitRectangle(*this);
}

