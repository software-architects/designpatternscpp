#pragma once
#include <memory>
#include "Shape.hpp"
#include "AbstractShapeFactory.hpp"

class AbstractBuilder
{
public:
	using ShapePtr = std::shared_ptr<Shape>;
	virtual ShapePtr construct(AbstractShapeFactory& factory) = 0;
};


