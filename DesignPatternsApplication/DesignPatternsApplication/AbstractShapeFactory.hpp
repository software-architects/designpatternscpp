#pragma once

#include <memory>
#include "Shape.hpp"

#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Composite.hpp"

class AbstractShapeFactory
{
public:
	using RectanglePtr = std::shared_ptr<Rectangle>;
	using CirclePtr = std::shared_ptr<Circle>;
	using CompositePtr = std::shared_ptr<Composite>;

	virtual CirclePtr createCircle(vec2f pos, float r) = 0;
	virtual RectanglePtr createRectangle(vec2f pos, vec2f size) = 0;
	virtual CompositePtr createComposite() = 0;
};
