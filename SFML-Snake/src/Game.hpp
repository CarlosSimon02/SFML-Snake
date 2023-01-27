#pragma once

#include <SFML/Graphics.hpp>

#include "Snake.hpp"
#include "Food.hpp"

class Game
{
public:
	Game();
	void run();

private:
	const std::string mGameTitle{ "SFML_Snake" };
	sf::RenderWindow window;
	sf::Event event;

	Snake snake;
	Food food;
};