#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

enum Direction {
	UP,DOWN,RIGHT,LEFT
};//0 UP , 1 DOWN , 2 RIGHT , 3 LEFT
class SnakeBody {
	RectangleShape rectangle;
public:
	Vector2f LastPosition;

	Direction snakeDirection;

	SnakeBody();
	
	void Update();

	Vector2f GetPosition();

	void SetPosition(Vector2f NewPosition);

	RectangleShape GetBody();

};