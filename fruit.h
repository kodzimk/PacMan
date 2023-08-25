#pragma once
#include<SFML/Graphics.hpp>
#include"map.h"
#include<vector>
#include<iostream>

using namespace std;
using namespace sf;


class fruit {
public:
	Texture texture;
	Sprite fruitSprte;
	int fruitCount = 0;
	Map map;

	fruit()
	{
		texture.loadFromFile("texture/PMSprites.png");
		fruitSprte.setTexture(texture);
		fruitSprte.setTextureRect(IntRect(0,180,25,30));


	}

};
