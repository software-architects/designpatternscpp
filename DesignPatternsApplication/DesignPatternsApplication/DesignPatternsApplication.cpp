// DesignPatternsApplication.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class DesignPatternsApp : public App {
public:
	void setup() override;
	void draw() override;
};

void DesignPatternsApp::setup()
{
	gl::enableDepthRead();
	gl::enableDepthWrite();
}

void DesignPatternsApp::draw()
{
	gl::clear(Color(0, 0.0f, 0.15f));
}

int main(int argc, char *argv[])
{
	cinder::app::RendererRef renderer(new RendererGl);
	cinder::app::AppMsw::main<DesignPatternsApp>(renderer, "DesignPatternsApp");
	return 0;
}

