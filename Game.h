#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <ctime>

#include "Fish.h"
using namespace sf;
typedef enum gameSceneState {
	Scene_Start, Scene_Launch 
};
class Game {
public:

	sf::RenderWindow window;
	Game(); ~Game();
	Clock clock;
	float time;

	int windowWidth, windowHeight;
	int gameSceneState;
	
	int Fishnum=0,Acnum=0;
	Texture Fishmod[102][50]; //”„Œ∆¿Ì
	FISH Fish[1000],Fishmodel[100];

	bool gameOver, gameQuit;
	bool startMusic, fightMusic;
	Texture tGameStartBK, tGameFightBK, tStartBtn;
	
	Sprite sGameStartBK, sGameFightBK, sStartBtn;
	Music gameStartMusic;
	SoundBuffer victorSb, defeatSb, attackSb, hoverSb, pressSb, releaseSb;
	Sound victorSd, defeatSd, attackSd, hoverSd, pressSd, releaseSd;

	bool pointCheck(float x,float y,FISH i);
	bool checkPoint(float x1, float y1, float x2, float y2,float x,float y);
	bool checkCover(FISH a, FISH b);
	bool getRate(int x);

	void Run();
	void Initial();
	void loadMediaData();	
	void Input();	
	void Draw();
	void drawFish();
	void drawStart();
	void drawFight();	
	void Logic();
};