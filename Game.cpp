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
	srand(std::time(0));
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
bool Game::checkPoint(float x1, float y1, float x2, float y2, float x, float y) {
	if (x >= x1 && x <= x2 && y >= y1 && y <= y2) return 1;
	return 0;
}
bool Game::checkCover(FISH a, FISH b) {
	float x1, y1, x2, y2, x, y;
	x1 = a.x; y1 = a.y;
	x2 = a.x + a.szx; y2 = a.y + a.szy;
	x = b.x; y = b.y;
	if (a.dx[0]<0 && checkPoint(x1, y1, x2, y2, x, y)) return 1;
	if (a.dx[0]>0 && checkPoint(x1, y1, x2, y2, x+b.szx, y)) return 1;
	if (a.dx[0]<0 && checkPoint(x1, y1, x2, y2, x, y+b.szy)) return 1;
	if (a.dx[0]>0 && checkPoint(x1, y1, x2, y2, x+b.szx, y+b.szy)) return 1;
	return 0;
}
void Game::loadMediaData() {
	if (!tGameStartBK.loadFromFile("data/pic/pc1.png")) {
		cout << "fail to load data/pic/pc1.png" << endl;
	}
	sGameStartBK.setTexture(tGameStartBK);
	if (!gameStartMusic.openFromFile("data/music/msc1.ogg")) {
		cout << "fail to load data/music/msc1.ogg" << endl;
	}
	if (!Fishmod[1][1].loadFromFile("data/pic/fish1_1.png")) {
		cout << "fail to load data/pic/fish1_1.png" << endl;
	}
	if (!Fishmod[1][2].loadFromFile("data/pic/fish1_2.png")) {
		cout << "fail to load data/pic/fish1_2.png" << endl;
	}
	if (!Fishmod[1][3].loadFromFile("data/pic/fish1_3.png")) {
		cout << "fail to load data/pic/fish1_3.png" << endl;
	}
	if (!Fishmod[1][4].loadFromFile("data/pic/fish1_4.png")) {
		cout << "fail to load data/pic/fish1_4.png" << endl;
	}
	Fishmodel[1].setTextures(Fishmod[1][1], Fishmod[1][2], Fishmod[1][3], Fishmod[1][4]);
	Fishmodel[1].delay = 5; Fishmodel[1].timer = 0; Fishmodel[1].id = 1;
	Fishmodel[1].setPosition(sf::Vector2f(0, 0));
	
	if (!Fishmod[2][1].loadFromFile("data/pic/fish2_1.png")) {
		cout << "fail to load data/pic/fish2_1.png" << endl;
	}
	if (!Fishmod[2][2].loadFromFile("data/pic/fish2_2.png")) {
		cout << "fail to load data/pic/fish2_2.png" << endl;
	}
	Fishmodel[2].setTextures(Fishmod[2][1], Fishmod[2][2], Fishmod[2][1], Fishmod[2][2]);
	Fishmodel[2].delay = 5; Fishmodel[2].timer = 0; Fishmodel[2].id = 2;
	Fishmodel[2].setPosition(sf::Vector2f(0, 0));
	Fishmodel[2].szx = 230; Fishmodel[2].szy = 208;
	
	if (!Fishmod[0][0].loadFromFile("data/pic/fish0_0.png")) {
		cout << "faile to load data/pic/fish0_1.png" << endl;
	}
	if (!Fishmod[0][1].loadFromFile("data/pic/fish0_1.png")) {
		cout << "faile to load data/pic/fish0_2.png" << endl;
	}
	
	Fishmodel[0].setTextures(Fishmod[0][0], Fishmod[0][1], Fishmod[0][0], Fishmod[0][0]);
	Fishmodel[0].setPosition(sf::Vector2f(0, 0));
	Fishmodel[0].szx = 80; Fishmodel[0].szy = 79;
	//Fishmodel[0].setScale(sf::Vector2f(0.2, 0.2));
	for (int i = 0; i < 4; i++) {
		Fishmodel[0].dx[i] *= 0.1;
		Fishmodel[0].dy[i] *= 0.1;
	}

	if (!Fishmod[4][1].loadFromFile("data/pic/fish10_1.png")) {
		cout << "fail to load data/pic/fish2_1.png" << endl;
	}
	if (!Fishmod[4][2].loadFromFile("data/pic/fish10_2.png")) {
		cout << "fail to load data/pic/fish2_2.png" << endl;
	}
	Fishmodel[4].setTextures(Fishmod[4][1], Fishmod[4][2], Fishmod[4][1], Fishmod[4][2]);
	Fishmodel[4].delay = 5; Fishmodel[4].timer = 0; Fishmodel[4].id = 4;
	Fishmodel[4].setPosition(sf::Vector2f(0, 0));
	Fishmodel[4].szx = 150; Fishmodel[2].szy = 139;
	for (int i = 0; i < 4; i++) {
		Fishmodel[4].dx[i] *= 0.3;
		Fishmodel[4].dy[i] *= 0.3;
	}

	if (!Fishmod[5][1].loadFromFile("data/pic/fish100_1.png")) {
		cout << "fail to load data/pic/fish2_1.png" << endl;
	}
	if (!Fishmod[5][2].loadFromFile("data/pic/fish100_2.png")) {
		cout << "fail to load data/pic/fish2_2.png" << endl;
	}
	Fishmodel[5].setTextures(Fishmod[5][1], Fishmod[5][2], Fishmod[5][1], Fishmod[5][2]);
	Fishmodel[5].delay = 5; Fishmodel[5].timer = 0; Fishmodel[5].id = 5;
	Fishmodel[5].setPosition(sf::Vector2f(0, 0));
	Fishmodel[5].szx = 200; Fishmodel[2].szy = 133;
	for (int i = 0; i < 4; i++) {
		Fishmodel[5].dx[i] *= 0.6;
		Fishmodel[5].dy[i] *= 0.6;
	}
}
bool Game::getRate(int x) {
	int r = rand() % 100;
	return r <= x;
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
			Fish[Fishnum].id = 1;
			Fish[Fishnum].x = rand() % 400+10;
			Fish[Fishnum].y = rand() % 800+10;
		}
		if (event.type == sf::Event::EventType::KeyReleased && event.key.code == sf::Keyboard::Num0) {
			Fish[++Fishnum] = Fishmodel[0];
			Fish[Fishnum].id = 0;
			Fish[Fishnum].x = rand() % 400 + 10;
			Fish[Fishnum].y = rand() % 800 + 10;
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
bool Game::pointCheck(float x, float y,FISH i) {
	if (x<0 || x+i.szx>windowWidth) return 0;
	if (y<0 || y+i.szy>windowHeight) return 0;
	return 1;
}
void Game::drawFish() {
	//cout << Fishnum << endl;
	for (int i = 1; i <= Fishnum; i++)if(Fish[i].exist) {
		float xx=Fish[i].x, yy=Fish[i].y;
		Fish[i].timer += time;
		if (Fish[i].timer >= Fish[i].delay) {
			Fish[i].timer -= Fish[i].delay;
			Fish[i].dr = rand()%4;
			Fish[i].delay = 1 + rand() % 5;
		}

		if (!pointCheck(xx + Fish[i].dx[Fish[i].dr], yy + Fish[i].dy[Fish[i].dr],Fish[i]))
			Fish[i].dx[Fish[i].dr] = -Fish[i].dx[Fish[i].dr], Fish[i].dy[Fish[i].dr] = -Fish[i].dy[Fish[i].dr];
		Fish[i].x = xx + Fish[i].dx[Fish[i].dr]; Fish[i].y = yy + Fish[i].dy[Fish[i].dr];

		if (Fish[i].dx[Fish[i].dr] < 0) Fish[i].setTexture(Fish[i].tLeft);
		if (Fish[i].dx[Fish[i].dr] > 0) Fish[i].setTexture(Fish[i].tRight);
		
	}
	for (int i = 1; i <= Fishnum; i++)if (Fish[i].exist) {
		int id = Fish[i].id;
		for (int j = 1; j <= Fishnum; j++)if (Fish[j].exist && i != j) {
			if (Fish[i].id > 3) continue;
			if (Fish[i].id - Fish[j].id != 1) continue;
			if (!Game::checkCover(Fish[i], Fish[j])) continue;
			Fish[j].exist = 0;
			Fish[i].nd++;
			if (Fish[j].id==1&&getRate(20)) {
				Fish[++Fishnum] = Fishmodel[4];
				Fish[Fishnum].id = 4;
				Fish[Fishnum].x = Fish[j].x;
				Fish[Fishnum].y = Fish[j].y;
			}
			if (Fish[i].id==1&&Fish[i].nd >= 3) {
				Fish[i].nd -= 3;
				Fishmodel[Fish[i].id + 1].x = Fish[i].x;
				Fishmodel[Fish[i].id + 1].y = Fish[i].y;
				if (Fish[i].id == 1) Acnum++;
				Fish[i] = Fishmodel[Fish[i].id + 1];
				if (Acnum >= 3) {
					Acnum -= 3;
					Fish[++Fishnum] = Fishmodel[5];
					Fish[Fishnum].id = 5;
					Fish[Fishnum].x = rand() % 400 + 10;
					Fish[Fishnum].y = rand() % 800 + 10;
				}
			}
		}
	}

	for (int i = 1; i <= Fishnum; i++)if (Fish[i].exist) {
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
	window.display();
}
void Game::Logic() {

}
void Game::Run() {
	do {
		Initial();

		while (window.isOpen()) {
			time = clock.getElapsedTime().asSeconds(); clock.restart();
			
			Input();
			Draw();
			Logic();
		}
	} while (!gameQuit);
}