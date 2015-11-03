// DesignPatterns.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <memory>
#include <vector>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Composite.hpp"

#include "AbstractBuilder.hpp"
#include "StaticSceneBuilder.hpp"
#include "CommandLineBuilder.hpp"

#include "StandardShapeFactory.hpp"
#include "DebugShapeFactory.hpp"

using namespace ci;
using namespace ci::app;

class DesignPatternsApp : public App {
public:
	void setup() override;
	void draw() override;

	using ShapePtr = std::shared_ptr<Shape>;
	ShapePtr root;

	using BuilderPtr = std::shared_ptr<AbstractBuilder>;
	BuilderPtr builder = std::make_shared<StaticSceneBuilder>();

	using ShapeFactoryPtr = std::shared_ptr<AbstractShapeFactory>;
	ShapeFactoryPtr factory = std::make_shared<StandardShapeFactory>();
};

void DesignPatternsApp::setup()
{
	using namespace std;

	// check parameters for the builder to use.
	for (const auto &s : getCommandLineArgs())
	{
		if (s == "--commandLineBuilder") {
			builder = std::make_shared<CommandLineBuilder>();
		}

		if (s == "--debugFactory") {
			factory = std::make_shared<DebugShapeFactory>();
		}
	}

	// construct the scene using the builder with the factory
	// (builder actual type depends on command line parameter)
	auto scene = builder->construct(*factory);

	float area = scene->calculateArea();
	std::cout << "area is : " << area << std::endl;

	gl::enableDepthRead();
	gl::enableDepthWrite();

	this->root = scene;
}

void DesignPatternsApp::draw()
{
	gl::clear(Color(0, 0.0f, 0.15f));
	
	auto aspect = getWindowAspectRatio();
	ci::CameraOrtho ortho;
	ortho.setOrtho(-10, 10, 0, 2 * 10 / aspect, -10, 10);
	ci::gl::setMatrices(ortho);

	gl::color(1.0f, 1.0f, 1.0f, 1.0f);
	root->draw();
}

int main(int argc, char *argv[])
{
	cinder::app::RendererRef renderer(new RendererGl);
	cinder::app::AppMsw::main<DesignPatternsApp>(renderer, "DesignPatternsApp");
	return 0;
}