#include "SnakeBody.h"

SnakeBody::SnakeBody()
{
	rectangle.setSize(Vector2f(35, 35));
	rectangle.setFillColor(Color::Green);
	rectangle.setOutlineColor(Color::Black);
	rectangle.setOutlineThickness(2);
}

Vector2f SnakeBody::GetPosition()
{
	return rectangle.getPosition();
}

void SnakeBody::SetPosition(Vector2f NewPosition)
{
	rectangle.setPosition(NewPosition);
}

RectangleShape SnakeBody::GetBody()
{
	return rectangle;
}
