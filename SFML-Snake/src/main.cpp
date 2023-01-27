#include "Game.hpp"

int mod(int a, int b) { return (a % b + b) % b; }

int main()
{
	Game game;
	game.run();
}