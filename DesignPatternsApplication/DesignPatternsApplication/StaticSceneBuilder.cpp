#include "stdafx.h"
#include "StaticSceneBuilder.hpp"
#include <memory>
#include "Composite.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

StaticSceneBuilder::ShapePtr StaticSceneBuilder::construct(AbstractShapeFactory& factory)
{
	using namespace std;
	auto snowMan = factory.createComposite();
	snowMan->add(factory.createCircle(vec2f{ 4.f, 9.f }, 1.f));
	snowMan->add(factory.createCircle(vec2f{ 4.f, 6.3f }, 2.f));
	snowMan->add(factory.createCircle(vec2f{ 4.f, 2.4f }, 3.f));

	auto house = factory.createComposite();
	house->add(factory.createRectangle(vec2f{ -7.0f, 0.0f }, vec2f{ 6.0, 11.0 }));
	house->add(factory.createRectangle(vec2f{ -8.5f, 0.0f }, vec2f{ 1.5, 8.0 }));
	house->add(factory.createRectangle(vec2f{ -1.0f, 0.0f }, vec2f{ 1.5, 8.0 }));
	house->add(factory.createCircle(vec2f{ -4.0, 11.0 }, 2.5f));

	auto scene = factory.createComposite();
	scene->add(snowMan);
	scene->add(house);

	return scene;
}

