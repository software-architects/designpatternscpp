#pragma once
#include "AbstractBuilder.hpp"

class CommandLineBuilder : public AbstractBuilder
{
public:
	enum MenuChoice {
		FirstChoice = 0,
		Circle,
		Rectangle,
		Composite,
		Done,
		LastChoice
	};

	virtual ShapePtr construct(AbstractShapeFactory& factory);

	std::shared_ptr<Shape> createShape(int level, AbstractShapeFactory& factory);
	void printMenu(int level) const;
	void printIndent(int level) const;

	std::shared_ptr<Shape> createCircle(int level, AbstractShapeFactory& factory);
	std::shared_ptr<Shape> createRectangle(int level, AbstractShapeFactory& factory);
	std::shared_ptr<Shape> createComposite(int level, AbstractShapeFactory& factory);
	
	MenuChoice getMenuChoice();
};
