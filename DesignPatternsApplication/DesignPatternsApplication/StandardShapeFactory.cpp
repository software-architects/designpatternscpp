#include "stdafx.h"
#include "StandardShapeFactory.hpp"

AbstractShapeFactory::CirclePtr StandardShapeFactory::createCircle(vec2f pos, float r)
{
	return std::make_shared<Circle>(pos, r);
}

AbstractShapeFactory::RectanglePtr StandardShapeFactory::createRectangle(vec2f pos, vec2f size)
{
	return std::make_shared<Rectangle>(pos, size);
}

AbstractShapeFactory::CompositePtr StandardShapeFactory::createComposite()
{
	return std::make_shared<Composite>();
}
