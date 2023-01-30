#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Food {
	CircleShape circle;
public:

	Food();

	void SetPosition(Vector2f NewPosition);

	Vector2f GetPosition();

	CircleShape GetFood();
};