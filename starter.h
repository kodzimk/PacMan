#pragma once
#include"pac.h"
#include"fruit.h"
#include"map.h"
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Starter {
public:
	Pac pac;
	Map map;
	RenderWindow window;
	Texture texture;
	Sprite sprite;
	fruit fruits;

	Starter()
	{

		window.create(VideoMode(690,750),"Pac Man");
		texture.loadFromFile("texture/PMSprites.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0,180,25,25));

		Loop();
	}

	void Loop()
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

		    pac.inreactwithworld(pac.sprite.getPosition().y/30 ,pac.sprite.getPosition().x/30,map);
			

			for (int i = 0; i < map.dotsArr.size(); i++)
			{
				FloatRect other = map.dotsArr[i].getGlobalBounds();
				pac.move(other);
			}
		
			

			

			window.clear();	
			window.draw(pac.sprite);
			window.draw(map.sprite);
			for (int i = 0; i < map.rectangleCount; i++)
			{
				window.draw(map.dotsArr[i]);
			}
			for (int i = 0; i < 25; i++)
			{
				for (int j = 0; j < 23; j++)
				{
					if (map.map[i][j] == ' ')
					{
						fruits.fruitSprte.setPosition(j * 30, i * 30);
						window.draw(fruits.fruitSprte);
					}
				}
			}
			window.draw(pac.scoreText);
			window.display();
		}
	}
};