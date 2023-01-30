#include "Food.h"

Food::Food()
{
	circle.setRadius(10.f);
	circle.setFillColor(Color::Red);
}

void Food::SetPosition(Vector2f NewPosition)
{
	circle.setPosition(NewPosition);
}

Vector2f Food::GetPosition()
{
	return circle.getPosition();
}

CircleShape Food::GetFood()
{
	return circle;
}
