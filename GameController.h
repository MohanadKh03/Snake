#pragma once
#include <SFML/Graphics.hpp>
#include "SnakeBody.h"
#include "Food.h"
using namespace sf;
using namespace std;

class GameController {
	Text scoreText;
	Font font;
	int score;

	RenderWindow Window;

	Food food;
	vector<SnakeBody>Snake;

	Text gameOverText;

	void AddNewSnakeBody();

	void RandomizeFoodPosition();

	bool IsGameOver();

	void ShowGameOverScreen();

	void UpdateGameEvents();

	void Draw();
public:

	GameController();

	void Run();
};