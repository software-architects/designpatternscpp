#include "stdafx.h"
#include "CommandLineBuilder.hpp"

#include <iostream>
#include <string>
#include <memory>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Composite.hpp"

AbstractBuilder::ShapePtr CommandLineBuilder::construct(AbstractShapeFactory& factory)
{
	return createShape(0, factory);
}

AbstractBuilder::ShapePtr CommandLineBuilder::createShape(int level, AbstractShapeFactory& factory)
{
	printMenu(level);

	switch (getMenuChoice())
	{
	case Circle:
		return createCircle(level + 1, factory);
		break;
	case Rectangle:
		return createRectangle(level + 1, factory);
		break;
	case Composite:
		return createComposite(level + 1, factory);
		break;
	}

	return nullptr;
}

AbstractBuilder::ShapePtr CommandLineBuilder::createCircle(int level, AbstractShapeFactory& factory)
{
	using namespace std;

	printIndent(level);
	float x, y, r;
	cout << "x z r: ";
	cin >> x >> y >> r;

	return factory.createCircle(vec2f{ x, y }, r );
}

AbstractBuilder::ShapePtr CommandLineBuilder::createRectangle(int level, AbstractShapeFactory& factory)
{
	using namespace std;
	printIndent(level);
	float x, y, w, h;
	cout << "x z w h: ";
	cin >> x >> y >> w >> h;

	return factory.createRectangle(vec2f{ x, y }, vec2f{ w, h });
}

AbstractBuilder::ShapePtr CommandLineBuilder::createComposite(int level, AbstractShapeFactory& factory)
{
	using namespace std;
	auto composite = factory.createComposite();
	bool keepAdding = true;
	while (keepAdding)
	{
		auto newShape = createShape(level + 1, factory);
		keepAdding = newShape != nullptr;
		if (newShape != nullptr) {
			composite->add(newShape);
		}
	}

	return composite;
}

void CommandLineBuilder::printMenu(int level) const
{
	using namespace std;
	printIndent(level);
	cout << "menu: press..." << std::endl;
	printIndent(level + 1);
	cout << Circle << ") for a new circle" << std::endl;

	printIndent(level + 1);
	cout << Rectangle << ") for a new rectangle" << std::endl;

	printIndent(level + 1);
	cout << Composite << ") for a new composite" << std::endl;

	printIndent(level + 1);
	cout << Done << ") for done" << std::endl;
}

void CommandLineBuilder::printIndent(int level) const
{
	using namespace std;
	string space(level, ' ');
	cout << space;
}

CommandLineBuilder::MenuChoice CommandLineBuilder::getMenuChoice()
{
	using namespace std;
	int answer;

	while (true)
	{
		cin >> answer;

		if (!cin.fail())
		{
			if (answer > FirstChoice && answer < LastChoice)
			{
				return (MenuChoice)answer;
			}
		}

		cout << "Please enter a value between " << FirstChoice << " and " << LastChoice << endl;
	}
}

