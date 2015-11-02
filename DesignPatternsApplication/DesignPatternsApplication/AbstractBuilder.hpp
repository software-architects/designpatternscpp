#pragma once
#include <memory>
#include "Shape.hpp"

class AbstractBuilder
{
public:
	using ShapePtr = std::shared_ptr<Shape>;
	virtual ShapePtr construct() = 0;
};


