#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class FISH :public Sprite {
public:
	float x = 0, y = 0,dx[4] = {1,-1,1,-1}, dy[4] = {1,1,-1,-1}, timer, delay,szp=1.;
	int dr = 0, id = 1, szx = 130, szy = 66,nd=0;
	bool exist=1;
	std::string fishAddress;
	Texture tLeft,tRight,tLeft2,tRight2;
	void setTextures(Texture,Texture,Texture,Texture);
};