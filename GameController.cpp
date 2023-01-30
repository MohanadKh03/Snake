#include "GameController.h"
#include <iostream>

using namespace std;

GameController::GameController()
{
	score = 0;
	font.loadFromFile("ARCADE_R.ttf");
	scoreText.setFont(font);
	scoreText.setString(to_string(score));
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(Vector2f(Window.getSize().x, Window.getSize().y));

	Window.create(VideoMode::getFullscreenModes()[0], "Snake", Style::None);
	Window.setFramerateLimit(10);
	//Initialize the snake
	SnakeBody head;
	head.SetPosition({ (float)Window.getSize().x / 2 - 17.5f , (float)Window.getSize().y / 2 - 17.5f });
	Snake.push_back(head);
	Snake[0].LastPosition = Snake[0].GetPosition();
	Snake[0].snakeDirection = RIGHT;

	//Initialize the food randomization
	RandomizeFoodPosition();
}
void GameController::AddNewSnakeBody()
{
	SnakeBody NewSnake;
	NewSnake.SetPosition(Snake[Snake.size() - 1].LastPosition);
	Snake.push_back(NewSnake);
}

void GameController::RandomizeFoodPosition()
{
	srand(time(NULL));
	int randX = rand() % (int)(Window.getSize().x - food.GetFood().getRadius());
	int randY = rand() % (int)(Window.getSize().y - food.GetFood().getRadius());

	food.SetPosition({ (float)randX,(float)randY });

}


void GameController::UpdateGameEvents()
{
	Event event;
	while (Window.pollEvent(event))
	{
		if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			Window.close();
	}


	if (Snake[0].GetBody().getGlobalBounds().intersects(food.GetFood().getGlobalBounds())) {
		score++;
		scoreText.setString(to_string(score));
		RandomizeFoodPosition();
		AddNewSnakeBody();
	}
	//if keyboard , then change the DIRECTION 
	if (Keyboard::isKeyPressed(Keyboard::Up) && Snake[0].snakeDirection != Direction::DOWN)
		Snake[0].snakeDirection = Direction::UP;
	if (Keyboard::isKeyPressed(Keyboard::Down) && Snake[0].snakeDirection != Direction::UP)
		Snake[0].snakeDirection = Direction::DOWN;
	if (Keyboard::isKeyPressed(Keyboard::Right) && Snake[0].snakeDirection != Direction::LEFT)
		Snake[0].snakeDirection = Direction::RIGHT;
	if (Keyboard::isKeyPressed(Keyboard::Left) && Snake[0].snakeDirection != Direction::RIGHT)
		Snake[0].snakeDirection = Direction::LEFT;

	Vector2f snakeSize = Snake[0].GetBody().getSize();

	Snake[0].LastPosition = Snake[0].GetPosition();

	switch (Snake[0].snakeDirection) {
		case UP:
			Snake[0].SetPosition({ Snake[0].LastPosition.x,Snake[0].LastPosition.y - snakeSize.y });
			break;
		case DOWN:
			Snake[0].SetPosition({ Snake[0].LastPosition.x,Snake[0].LastPosition.y + snakeSize.y });
			break;
		case RIGHT:
			Snake[0].SetPosition({ Snake[0].LastPosition.x + snakeSize.x,Snake[0].LastPosition.y });
			break;
		case LEFT:
			Snake[0].SetPosition({ Snake[0].LastPosition.x - snakeSize.x,Snake[0].LastPosition.y });
			break;
	}
	for (int i = 1; i < Snake.size(); i++) {
		Snake[i].LastPosition = Snake[i].GetPosition();
		Snake[i].SetPosition(Snake[i - 1].LastPosition);
	}

}

bool GameController::IsGameOver()
{
	if (Snake[0].GetPosition().x < 0 || Snake[0].GetPosition().x > Window.getSize().x)
		return true;
	if (Snake[0].GetPosition().y < 0 || Snake[0].GetPosition().y > Window.getSize().y)
		return true;
	return false;
}
void GameController::ShowGameOverScreen()
{
	Window.clear();
	gameOverText.setFont(font);
	gameOverText.setString("GAME OVER , Press ESC key to exit!");
	gameOverText.setCharacterSize(20);
	gameOverText.setFillColor(Color::White);
	gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2.0f, gameOverText.getLocalBounds().height / 2.0f);
	gameOverText.setPosition({ (float)Window.getSize().x / 2.0f , (float)Window.getSize().y / 2.0f });
	Window.draw(gameOverText);
	Window.display();
}
void GameController::Draw()
{
	Window.clear();
	Window.draw(scoreText);
	Window.draw(food.GetFood());
	for (SnakeBody s : Snake) {
		//s.Update();
		Window.draw(s.GetBody());
	}
	Window.display();
}


void GameController::Run()
{
	while (Window.isOpen()) {
		if (!IsGameOver()) {
			UpdateGameEvents();
			Draw();
		}
		else {
			ShowGameOverScreen();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				Window.close();
		}
	}
}
