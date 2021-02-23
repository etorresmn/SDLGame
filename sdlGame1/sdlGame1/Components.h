#pragma once

#include <memory>
#include "SDL_cpp.h"
#include "SDL_Events_cpp.h"

class CTransform {
public:
	SDL::Vector2 position;
	SDL::Vector2 speed;
	float scale = 0;
	double angle = 0;

	CTransform() {}
	CTransform(float positionX, float positionY, float speedX, float speedY, float scale, double angle)
	{
		position = SDL::Vector2(positionX, positionY);
		speed = SDL::Vector2(speedX, speedY);
		this->scale = scale;
		this->angle = angle;
	}
};

class CCollision {
public:
	float radius = 0;

	CCollision() {}
	CCollision(float radius) : radius{ radius }
	{}
};

class CScore {
public:
	int score = 0;

	CScore() {}
	CScore(int score) : score{ score }
	{}
};

class CShape {
public:

	std::shared_ptr<SDL::Polygon> shape;

	CShape() {}

	CShape(uint32_t sides, float radius, float centerPosX, float centerPosY) {

		shape = std::make_shared<SDL::Polygon>(sides, radius, SDL::Vector2(centerPosX, centerPosY));
	}
};

class CInput {
public:

	bool forward = false;
	bool backward = false;
	bool right = false;
	bool left = false;

	CInput(){}
};


class CLifeSpan {
public:
	int lifeSpan = 0;

	CLifeSpan()
	{}
	CLifeSpan(int lifeSpan) : lifeSpan{ lifeSpan }
	{}
};