#include "stdafx.h"
#include "DebugShapeFactory.hpp"

#include <iostream>

class DebugCircle : public Circle
{
public:
	DebugCircle(vec2f pos, float r) : Circle(pos, r) {};
	virtual float calculateArea() const override
	{
		std::cout << "Calculating area for circle at (" << this->position.x << "/" << this->position.y << ")";
		std::cout << "r: " << this->radius << std::endl;
		auto area = Circle::calculateArea();
		std::cout << "Done calculating area" << std::endl;
		return area;
	}
};

class DebugRectangle : public Rectangle
{
public:
	DebugRectangle(vec2f pos, vec2f size) : Rectangle(pos, size) {};
	virtual float calculateArea() const override
	{
		std::cout << "Calculating area for rectangle at (" << this->position.x << "/" << this->position.y << ")";
		std::cout << "size: (" << this->size.x << " / " << this->size.y << ")" << std::endl;
		auto area = Rectangle::calculateArea();
		std::cout << "Done calculating area" << std::endl;
		return area;
	}
};

class DebugComposite : public Composite
{
public:
	virtual float calculateArea() const override
	{
		std::cout << "Calculating for a composite" << std::endl;
		auto area = Composite::calculateArea();
		std::cout << "Done calculating area" << std::endl;
		return area;
	}
};

AbstractShapeFactory::CirclePtr DebugShapeFactory::createCircle(vec2f pos, float r)
{
	return std::make_shared<DebugCircle>(pos, r);
}

AbstractShapeFactory::RectanglePtr DebugShapeFactory::createRectangle(vec2f pos, vec2f size)
{
	return std::make_shared<DebugRectangle>(pos, size);
}

AbstractShapeFactory::CompositePtr DebugShapeFactory::createComposite()
{
	return std::make_shared<DebugComposite>();
}
