#pragma once
#include<SFML/Graphics.hpp>
#include"map.h"
#include<iostream>
#include<sstream>

using namespace sf;

enum Direction {
	left,right,up,down
};

class Pac {
public:
	Texture texture;
	Sprite sprite;
	Direction direction;
	float CurrentFrame = 0;
	float dy, dx = 0;
	float pacRot,x,y;
	int score = 0;
	Text scoreText;
	Map map;
	Clock clock;
	Font font;

	Pac()
	{
		 font.loadFromFile("font/comic.ttf");
		 scoreText.setFont(font);
		 scoreText.setScale(1, 1);
		 scoreText.setString("0");
		 scoreText.setPosition(0, 0);
		sprite.setOrigin(15,15);
		texture.loadFromFile("texture/PMSprites.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(30,0,30,30));
		direction = Direction::right;
		sprite.setScale(1,1);
		sprite.setPosition(12 * 30, 13 * 30);



	}

	bool intearctwithmap(int i,int j,float time)
	{
		if (map.map[i][j] == ' ')
		{
			for (int i = 0; i < 25; i++)
			{
				for (int j = 0; j < 23; j++)
				{
					cout << map.map[i][j];
				}
				cout << endl;
			}
			map.map[i][j] = '1';
			score += 20;
			scoreText.setString(std::to_string(score));
			return false;

		}
		if (dx < 0)
		{
			j--;
		}
		else if (dx > 0)
		{
			j++;
		}
		else if (dy > 0)
		{
			i++;
		}
		else if (dy < 0)
		{
			i--;
		}

		if (map.map[i][j] == '#')
		{
			if (dx < 0)
			{
				return true;
			}
			if (dx > 0)
			{
				return true;
			}
			if (dy > 0)
			{
				
				return true;
			}
			if (dy < 0)
			{
				return true;
			}
		}
		
		if (map.map[i][j] == '0'&&j==22)
		{
			sprite.setPosition(1 * 30, 11 * 30);
		}
		else if (j == 0)
		{
			dx = -0.07;
			sprite.setPosition(22*30,11*30);
		}
		return false;
	}
	void Move()
	{
		
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			
			dx = 0;
			dy = 0.07;
			pacRot = 90;
			if (pacRot != sprite.getRotation())
			{
				pacRot -= sprite.getRotation();
				sprite.rotate(pacRot);
			}
			
			direction = Direction::down;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			
			dx = -0.07;
			dy = 0;
			direction = Direction::left;

			pacRot = 180;
			if (pacRot != sprite.getRotation())
			{
				pacRot -= sprite.getRotation();
				sprite.rotate(pacRot);
			}
			
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			
			dx = 0;
			dy = -0.07;
			pacRot = -90;
			if (pacRot != sprite.getRotation())
			{
				pacRot -= sprite.getRotation();
				sprite.rotate(pacRot);

			}
			direction = Direction::up;


		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
		
			pacRot = 0;
			if (pacRot != sprite.getRotation())
			{
				pacRot -= sprite.getRotation();
				sprite.rotate(pacRot);

			}
			dx = 0.07;
			dy = 0;
			direction = Direction::right;
		}
		
		
			CurrentFrame +=0.005* time;
			if (CurrentFrame >= 3)CurrentFrame = 0;
			sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 0, 30, 30));

			bool can = intearctwithmap(sprite.getPosition().y / 30, sprite.getPosition().x / 30, time);

			if (can == false)
			{
				if (dx > 0 || dx < 0)
					sprite.move(dx * time, 0);
				else
					sprite.move(0, dy * time);
				
			}

			
	}
};