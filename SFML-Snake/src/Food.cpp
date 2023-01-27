#include "Food.hpp"

Food::Food(const std::vector<sf::Vector2i>& snakeBodyPositions)
{
	display.setFillColor(sf::Color::Green);
	display.setOutlineThickness(2.f);
	display.setOutlineColor(sf::Color::Black);

	srand(uint16_t(time(NULL)));
	setRandPosition(snakeBodyPositions);
}

void Food::setRandPosition(const std::vector<sf::Vector2i>& snakeBodyPositions)
{
	setField();
	removeSnakeBodyPosToField(snakeBodyPositions);

	mPos = sf::Vector2i(mField[rand()%mField.size()]);
}

sf::Vector2i Food::getPosition() const
{
	return mPos;
}

void Food::draw(sf::RenderWindow& window)
{
	display.setPosition(sf::Vector2f((float)(mPos.x * mPixelSize.x), (float)(mPos.y * mPixelSize.y)));
	window.draw(display);
}

void Food::setField()
{
	for (int i = 0; i < SCREEN_HEIGHT/mPixelSize.y; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH/mPixelSize.x; j++)
		{
			mField.push_back(sf::Vector2i((j), (i)));
		}
	}
}

void Food::removeSnakeBodyPosToField(const std::vector<sf::Vector2i>& snakeBodyPositions)
{
	for (size_t i = 0; i < snakeBodyPositions.size(); i++)
	{
		for (size_t j = 0; j < mField.size(); j++)
		{
			if (snakeBodyPositions[i] == mField[j]) mField.erase(mField.begin() + j);
		}
	}
}