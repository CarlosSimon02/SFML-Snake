#include "Snake.hpp"
#include <iostream>
#define Mod(a, b) (a % b + b) % b

Snake::Snake()
{
	mHeadDisplay.setFillColor(sf::Color::Cyan);
	mHeadDisplay.setOutlineThickness(2.f);
	mHeadDisplay.setOutlineColor(sf::Color::Black);

	mBodyDisplay.setFillColor(sf::Color::Blue);
	mBodyDisplay.setOutlineThickness(2.f);
	mBodyDisplay.setOutlineColor(sf::Color::Black);
}

void Snake::move(float elapsedTime)
{
	mAccumulatedTime += elapsedTime;

	if (mAccumulatedTime >= 0.5f / speed)
	{
		mBodyPos.insert(mBodyPos.begin(), mHeadPos);
		mBodyPos.pop_back();
		mHeadPos += mDir;
		mHeadPos.x = Mod(mHeadPos.x, (SCREEN_WIDTH / mPixelSize.x));
		mHeadPos.y = Mod(mHeadPos.y, (SCREEN_HEIGHT / mPixelSize.y));
		mAccumulatedTime = 0;
		mHasMoved = true;
	}
}

void Snake::setDir(sf::Vector2i dir)
{
	if (mHasMoved)
	{
		if (abs(mDir.x) + abs(dir.x) != 2 && abs(mDir.y) + abs(dir.y) != 2)
		{
			mDir = dir;
			mHasMoved = false;
		}
	}
}

bool Snake::hasAte(const sf::Vector2i& foodPosition)
{
	if (foodPosition == mHeadPos) return true;
	return false;
}

void Snake::draw(sf::RenderWindow& window)
{
	mHeadDisplay.setPosition(sf::Vector2f((float)(mHeadPos.x * mPixelSize.x), (float)(mHeadPos.y * mPixelSize.y)));
	window.draw(mHeadDisplay);

	for (size_t i = 0; i < mBodyPos.size(); i++)
	{
		mBodyDisplay.setPosition(sf::Vector2f((float)(mBodyPos[i].x * mPixelSize.x), (float)(mBodyPos[i].y * mPixelSize.y)));
		window.draw(mBodyDisplay);
	}
}  

void Snake::incrementBodySize()
{
	mBodyPos.push_back(mBodyPos[mBodyPos.size() - 1]);
}

bool Snake::hasBiteBody()
{
	for (size_t i = 0; i < mBodyPos.size(); i++)
	{
		if (mBodyPos[i] == mHeadPos) return true;
	}

	return false;
}

void Snake::restart()
{
	mBodyPos.clear();
	mBodyPos.insert(mBodyPos.begin(), mHeadPos);
}

std::vector<sf::Vector2i> Snake::getBodyPositions()
{
	return mBodyPos;
}