#pragma once
#include "Shape.hpp"
#include "vec2.h"

class Rectangle : public Shape
{
public:
	Rectangle() {};
	Rectangle(vec2f position, vec2f size) : 
		position(position), size(size) {};
	
	vec2f position;
	vec2f size;
	
	virtual ~Rectangle();
	virtual float calculateArea() const  override;
	virtual void draw() const  override;
};