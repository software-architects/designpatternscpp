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

using namespace ci;
using namespace ci::app;

class DesignPatternsApp : public App {
public:
	void setup() override;
	void draw() override;

	using ShapePtr = std::shared_ptr<Shape>;
	ShapePtr root;
};

void DesignPatternsApp::setup()
{
	using namespace std;

	auto snowMan = make_shared<Composite>();
	snowMan->add(make_shared<Circle>(vec2f{ 4.f, 9.f }, 1.f));
	snowMan->add(make_shared<Circle>(vec2f{ 4.f, 6.3f }, 2.f));
	snowMan->add(make_shared<Circle>(vec2f{ 4.f, 2.4f }, 3.f));

	auto house = make_shared<Composite>();
	house->add(make_shared<Rectangle>(vec2f{ -7.0f, 0.0f }, vec2f{ 6.0, 11.0 }));
	house->add(make_shared<Rectangle>(vec2f{ -8.5f, 0.0f }, vec2f{ 1.5, 8.0 }));
	house->add(make_shared<Rectangle>(vec2f{ -1.0f, 0.0f }, vec2f{ 1.5, 8.0 }));
	house->add(make_shared<Circle>(vec2f{ -4.0, 11.0 }, 2.5f));

	auto scene = make_shared<Composite>();
	scene->add(snowMan);
	scene->add(house);

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