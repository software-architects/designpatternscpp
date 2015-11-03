#pragma once

#include "Shape.hpp"
#include <vector>
#include <memory>
#include "AbstractShapeVisitor.hpp"

class Composite : public Shape
{
public:
	Composite() {};
	virtual ~Composite() {}

	virtual float calculateArea() const override;
	virtual void draw() const override;

	using ShapePtr = std::shared_ptr<Shape>;
	void add(ShapePtr shape);

	void accept(AbstractShapeVisitor& visitor) override;

	std::vector<ShapePtr>& getShapes();
private:
	std::vector<ShapePtr> shapes;
};
