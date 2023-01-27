#include "Game.hpp"
#include "Utilities.hpp"

Game::Game() :window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), mGameTitle), food(snake.getBodyPositions()){}

void Game::run()
{
	sf::Clock clock;
	sf::Time elapsedTime;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					snake.setDir(sf::Vector2i(0, -1));
					break;
				case sf::Keyboard::Down:
					snake.setDir(sf::Vector2i(0, 1));
					break;
				case sf::Keyboard::Left:
					snake.setDir(sf::Vector2i(-1,0));
					break;
				case sf::Keyboard::Right:
					snake.setDir(sf::Vector2i(1,0));
					break;
				}
			}
		}

		elapsedTime = clock.getElapsedTime();
		clock.restart();

		snake.move(elapsedTime.asSeconds());
		if (snake.hasAte(food.getPosition()))
		{
			food.setRandPosition(snake.getBodyPositions());
			snake.incrementBodySize();
		}
		if (snake.hasBiteBody()) snake.restart();

		window.clear();
		snake.draw(window);
		food.draw(window);
		window.display();
	}
}