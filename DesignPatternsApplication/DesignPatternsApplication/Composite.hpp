#pragma once

#include "Shape.hpp"
#include <vector>
#include <memory>

class Composite : public Shape
{
public:
	Composite() {};
	virtual ~Composite() {}

	virtual float calculateArea() const override;
	virtual void draw() const override;

	using ShapePtr = std::shared_ptr<Shape>;
	void add(ShapePtr shape);

private:
	std::vector<ShapePtr> shapes;
};
