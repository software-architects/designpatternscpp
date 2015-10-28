#include "stdafx.h"
#include "Composite.hpp"
#include <numeric>

float Composite::calculateArea() const
{
	return std::accumulate(shapes.begin(), shapes.end(), 0.0f,
		[](float agg, const ShapePtr &ptr) { return agg + ptr->calculateArea();  });
}

void Composite::draw() const
{
	for(const auto &s : this->shapes) {
		s->draw();
	}
}

void Composite::add(ShapePtr shape)
{
	this->shapes.push_back(shape);
}



