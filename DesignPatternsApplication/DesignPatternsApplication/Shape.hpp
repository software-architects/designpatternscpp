#pragma once

class Shape
{
public:
	Shape() {};
	virtual ~Shape(){};

	virtual float calculateArea() const = 0;
	virtual void draw() const = 0;
};

