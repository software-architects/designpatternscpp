#pragma once
#include "AbstractShapeVisitor.hpp"

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Composite.hpp"

class ShapeCountingVisitor : public AbstractShapeVisitor
{
public:
	int circleCount = 0;
	int rectangleCount = 0;
	int compositeCount = 0;

	virtual void visitCircle(Circle &circle) override
	{
		circleCount++;
	}

	virtual void visitRectangle(Rectangle &rectangle) override
	{
		rectangleCount++;
	}

	virtual void visitComposite(Composite &composite) override
	{
		compositeCount++;
		for (auto& s : composite.getShapes())
		{
			s->accept(*this);
		}
	}
};