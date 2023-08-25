#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class  Map
{
public:
	string map[25] = {
		"#######################",
		"#          #          #",
		"# ### #### # #### ### #",
		"# ### #### # #### ### #",
		"#    X           X    #",
		"# ### # ####### # ### #",
		"#E   F# ####### #D   R#",
		"##### #E  W#Q  R# #####",
		"##### #### # #### #####",
		"##### #Q  AGA  W# #####",
		"##### # ###-### # #####",
		"0====X F#BP*IC#D X====0",
		"##### # ####### # #####",
		"##### #D0001000F# #####",
		"##### # ####### # #####",
		"##### # ####### # #####",
		"#    X     #      X   #",
		"# ### #### # #### ### #",
		"#   #             #   #",
		"### # # ####### # # ###",
		"#Q A R#E  W#Q  R#E A W#",
		"# ######## # ######## #",
		"#@######## # ########@#",
		"#E        A A        R#",
		"#######################",
	};

	Texture texture;
	Sprite mapS;
	Texture textureA;
	Sprite sprite;
	Map() {
		textureA.loadFromFile("texture/PMSprites.png");
		sprite.setTexture(textureA);
		sprite.setTextureRect(IntRect(0, 180, 30, 30));
		texture.loadFromFile("texture/map1.png");
		mapS.setTexture(texture);
	
	 }



};

 