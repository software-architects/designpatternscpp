#pragma once

#include "AbstractBuilder.hpp"

class StaticSceneBuilder : public AbstractBuilder
{
public:
	virtual ShapePtr construct(AbstractShapeFactory& factory) override;
};
