#pragma once

class Circle;
class Rectangle;
class Composite;

class AbstractShapeVisitor
{
public:
	virtual void visitCircle(Circle &circle) = 0;
	virtual void visitRectangle(Rectangle &rectangle) = 0;
	virtual void visitComposite(Composite &composite) = 0;
};
