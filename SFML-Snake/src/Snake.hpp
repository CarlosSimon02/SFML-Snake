#pragma once

#include <vector>

#include "Object.hpp"

class Snake :public Object
{
public:
	Snake();
	void move(float elapsedtime);
	void setDir(sf::Vector2i dir);
	bool hasAte(const sf::Vector2i& foodPosition);
	void draw(sf::RenderWindow& window) override;
	void incrementBodySize();
	bool hasBiteBody();
	void restart();
	std::vector<sf::Vector2i> getBodyPositions();

private:
	uint16_t speed{ 3 };
	float mAccumulatedTime{};
	bool mHasMoved{};
	sf::Vector2i mDir{ 1,0 };
	sf::Vector2i mHeadPos{ ((SCREEN_WIDTH / mPixelSize.x) / 2) - 3, ((SCREEN_HEIGHT / mPixelSize.y) / 2) - 1 };
	std::vector<sf::Vector2i> mBodyPos{ sf::Vector2i(((SCREEN_WIDTH / mPixelSize.x) / 2) - 4, ((SCREEN_HEIGHT / mPixelSize.y) / 2) - 1) };
	sf::RectangleShape mHeadDisplay{ sf::Vector2f(mPixelSize) };
	sf::RectangleShape mBodyDisplay{ sf::Vector2f(mPixelSize) };
};