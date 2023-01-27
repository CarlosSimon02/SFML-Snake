#pragma once

#include <SFML/Graphics.hpp>
#include "Utilities.hpp"

class Object
{
protected:
	const sf::Vector2i mPixelSize{ 30,30 };

public:
	virtual void draw(sf::RenderWindow& window) = 0;
};