// DesignPatternsApplication.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <memory>
#include <vector>

#include "Circle.hpp"
#include "Rectangle.hpp"

using namespace ci;
using namespace ci::app;

using ShapePtr = std::shared_ptr<Shape>;

class DesignPatternsApp : public App {
public:
	void setup() override;
	void draw() override;

	std::vector<ShapePtr> scene;
};

void DesignPatternsApp::setup()
{
	using namespace std;

	scene.push_back(make_shared<Circle>(vec2f{ 2.f, 2.f }, 1.f));
	scene.push_back(make_shared<Rectangle>(vec2f{ -2.f, 2.f }, vec2f{ 1.f, 1.f }));

	float area = 0.0;
	for (const auto& s : scene) {
		area += s->calculateArea();
	}

	std::cout << "area is " << area << std::endl;

	gl::enableDepthRead();
	gl::enableDepthWrite();
}

void DesignPatternsApp::draw()
{
	gl::clear(Color(0, 0.0f, 0.15f));
	
	auto aspect = getWindowAspectRatio();
	ci::CameraOrtho ortho;
	ortho.setOrtho(-10, 10, -10 / aspect, 10 / aspect, -10, 10);
	ci::gl::setMatrices(ortho);

	gl::color(0.5f, 1.0f, 0.5f, 1.0f);
	for (const auto& s : scene) {
		s->draw();
	}

}

int main(int argc, char *argv[])
{
	cinder::app::RendererRef renderer(new RendererGl);
	cinder::app::AppMsw::main<DesignPatternsApp>(renderer, "DesignPatternsApp");
	return 0;
}

