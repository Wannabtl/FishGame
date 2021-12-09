#include<iostream>
#include"Game.h"
int main() {
	Game game;
	while (game.window.isOpen()) {
		game.Run();
	}
	return 0;
}