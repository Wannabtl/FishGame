#include "Game.h"

using namespace std;
Game::Game() {
	windowWidth = 640;
	windowHeight = 1136;
	window.create(VideoMode(windowWidth, windowHeight), L"Ë®×å¹Ý");
}
Game::~Game() {

}
void Game::Initial() {
	window.setFramerateLimit(60);
	gameSceneState = Scene_Start;
	startMusic = 1;
	fightMusic = 0;
	gameOver = gameQuit = 0;
	loadMediaData();
	if (startMusic) {
		gameStartMusic.play();
		gameStartMusic.setLoop(1);
	}
}
void Game::loadMediaData() {
	if (!tGameStartBK.loadFromFile("data/pic/pc1.png")) {
		cout << "fail to load data/pic/pc1.png" << endl;
	}
	sGameStartBK.setTexture(tGameStartBK);
	if (!gameStartMusic.openFromFile("data/music/msc1.ogg")) {
		cout << "fail to load data/music/msc1.ogg" << endl;
	}
	if (!Fishmod1_1.loadFromFile("data/pic/fish1_1.png")) {
		cout << "fail to load data/pic/fish1_1.png" << endl;
	}
	if (!Fishmod1_2.loadFromFile("data/pic/fish1_2.png")) {
		cout << "fail to load data/pic/fish1_2.png" << endl;
	}
	Fishmodel[1].setTextures(Fishmod1_1, Fishmod1_2);


}
void Game::Input() {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			gameQuit = 1;
		}
		if (event.type == sf::Event::EventType::KeyReleased && event.key.code == sf::Keyboard::Escape) {
			window.close();
			gameQuit = 1;
		}
		if (event.type == sf::Event::EventType::KeyReleased && event.key.code == sf::Keyboard::Num1) {
			Fish[++Fishnum] = Fishmodel[1];
		}
	}
}
void Game::Draw() {

	if (gameSceneState == Scene_Start) {
		drawStart();
	}
	else if (gameSceneState == Scene_Launch) {
		drawFight();
	}
}
void Game::drawFight() {

}
void Game::drawFish() {
	for (int i = 1; i <= Fishnum; i++) {
		Fish[i].setPosition(Fish[i].x, Fish[i].y);
		window.draw(Fish[i]);
	}

}
void Game::drawStart() {
	Vector2u size;
	size.x = windowWidth;
	size.y = windowHeight;
	window.setSize(size);

	window.clear();
	sGameStartBK.setPosition(0, 0);
	window.draw(sGameStartBK);
	drawFish();
	Fishmodel[1].setPosition(Fishmodel[1].x, Fishmodel[1].y);
	window.draw(Fishmodel[1]);
	window.display();
}
void Game::Logic() {

}
void Game::Run() {
	do {
		Initial();
		while (window.isOpen()) {
			Input();
			Draw();
			Logic();
		}
	} while (!gameQuit);
}