#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Starter.h"
#include<iostream>

using namespace std;
using namespace sf;

class Map {
public:
    static Map* instance;
	string map[25] =
	{
"#######################" ,
"#Q   S    W#Q    S   W#" ,
"#@### #### # #### ###@#" ,
"# ### #### # #### ### #" ,
"#D   X S  A A  S X   F#" ,
"# ### # ####### # ### #" ,
"#E   F# ####### #D   R#" ,
"##### #E  W#Q  R# #####" ,
"##### #### # #### #####" ,
"##### #Q  AGA  W# #####" ,
"##### # ###-### # #####" ,
"0====X F#BP*IC#D X====0" ,
"##### # ####### # #####" ,
"##### #D   1   F# #####" ,
"##### # ####### # #####" ,
"##### # ####### # #####" ,
"#Q   X A  W#Q  A X   W#" ,
"# ### #### # #### ### #" ,
"#E W#D S  AcA  S F#Q R#" ,
"### # # ####### # # ###" ,
"#Q A R#E  W#Q  R#E A W#" ,
"# ######## # ######## #" ,
"#@######## # ########@#" ,
"#E        A A        R#" ,
"#######################"
};

	Texture texture;
	Sprite sprite;
    std::vector<sf::RectangleShape>  dotsArr;
	RectangleShape shape;
    int dotsCount = 0;
	int rectangleCount = 0;
 
    
	Map()
	{
		rectangleCount = 0;
		texture.loadFromFile("texture/map1.png");
		sprite.setTexture(texture);
        initMaze();
		
	}

    void initMaze()
    {
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 23; j++)
			{
				if (map[i][j] == '#')
				{
					shape.setSize(sf::Vector2f(30, 30));
					shape.setPosition(j * 30, i * 30);
					shape.setFillColor(Color::Blue);
					dotsArr.push_back(shape);
					rectangleCount++;
				}
			}
		}
    }

    
    

 



 


};