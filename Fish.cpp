#include "Fish.h"
void FISH::setTextures(Texture Fishsh1,Texture Fishsh2,Texture Fishsh3,Texture Fishsh4) {
	tLeft = Fishsh1;
	tRight = Fishsh2;
	tLeft2 = Fishsh3;
	tRight2 = Fishsh4;
	if (dr == 1) setTexture(tLeft);
	else setTexture(tRight);
}