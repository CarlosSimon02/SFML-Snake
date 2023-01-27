#pragma once

#include <cstdlib>
#include <vector>

#include "Object.hpp"

class Food : public Object
{
public:
	Food(const std::vector<sf::Vector2i>& snakeBodyPositions);
	void setRandPosition(const std::vector<sf::Vector2i>& snakeBodyPositions);
	sf::Vector2i getPosition() const;
	void draw(sf::RenderWindow& window) override;

private:
	void setField();
	void removeSnakeBodyPosToField(const std::vector<sf::Vector2i>& snakeBodyPositions);

private:
	sf::Vector2i mPos;
	sf::RectangleShape display{sf::Vector2f(mPixelSize)};
	std::vector<sf::Vector2i> mField;
};