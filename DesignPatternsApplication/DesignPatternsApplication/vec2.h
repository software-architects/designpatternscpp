#pragma once

template<class T>
class vec2
{
public:
	vec2() : x(0), y(0) {};
	vec2(T _x, T _y) : x(_x), y(_y) {};
	T x, y;
};

using vec2f = vec2<float>;


