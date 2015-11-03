#pragma once

#include "AbstractShapeFactory.hpp"

class StandardShapeFactory : public AbstractShapeFactory
{
public:
	virtual CirclePtr createCircle(vec2f pos, float r);
	virtual RectanglePtr createRectangle(vec2f pos, vec2f size);
	virtual CompositePtr createComposite();
};