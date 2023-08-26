#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"map.h"

using namespace std;
using namespace sf;

enum GhostDirection {
	up,down,left,right
};

enum GhostState {
	Attack,Move,Stay
};



class ghost {
public:
	Texture texture;
	Sprite sprite;
	float x, y, dx, dy,anim,time;
	Clock clock;
	GhostDirection direction;
	Map map;
	GhostState state;
	int animation;
	bool isInHome;

	ghost()
	{
		sprite.setScale(0.8, 0.8);
		texture.loadFromFile("texture/PMSprites.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0,30,30,30));

		init();
	}

	void Move()
	{
		if (state == GhostState::Move)
		{
			

			Animation();

			if (dx > 0 || dx < 0 || dy < 0 || dy>0)
				sprite.move(time * dx, time * dy);

			y = sprite.getPosition().y / 27.7;
			x = sprite.getPosition().x / 30;
			
			checkCollision(y, x);
			
		}
		
		
		
	}

	void init()
	{
		isInHome = true;
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 23; j++)
			{
				if (map.map[i][j] == 'P')
				{
					sprite.setPosition(j * 30, i * 30);
				}
			}
		}
		x = sprite.getPosition().x;
		y = sprite.getPosition().y;
		dx = 0.03;
		direction = GhostDirection::right;
		dy = 0;
		anim = 0;
		time = 0;
		state = GhostState::Move;
	}

	void checkCollision(int i,int j)
	{
		
		
		if (map.map[i][j] == '*')
		{
			isInHome = false;
			dx = 0;
			dy = -0.03;
			direction = GhostDirection::up;
			animation = 3;
			return;
		}
		
		cout << "Y:" << i << " X: " << j << endl;
				
			if (map.map[i][j]=='Q')
			{
				if (direction == GhostDirection::left)
				{
					direction = GhostDirection::down;
					dx = 0;
					dy = 0.03;
					anim = 4;
					animation = 4;
				}
				else
				{
					animation = 0;
					dx = 0.03;
					dy = 0;
					direction = GhostDirection::right;
					anim = 0;
				}
				
			}
			else if (map.map[i][j] == 'W')
			{
				if (dx>0)
				{
					animation = 4;
					dx = 0;
					dy = 0.03;
					direction = GhostDirection::down;
					anim = 1;
				}
				else
				{
					animation = 6;
					dx = -0.03;
					dy = 0;
					direction = GhostDirection::left;
					anim = 1;
				}
				
			}
			else if (map.map[i][j] == 'G')
			{
				if (direction == GhostDirection::up)
				{
					dx = 0.03;
					dy = 0;
					direction = GhostDirection::right;
					anim = 0;
					animation = 0;
				}
			}
			else if (map.map[i][j] == 'E'||map.map[i][j]=='A')
			{
				if (direction == GhostDirection::left)
				{
					animation = 2;
					dx = 0;
					dy = -0.03;
					direction = GhostDirection::up;
					anim = 3;
				}
				else
				{
					dx = 0.03;
					dy = 0;
					direction = GhostDirection::right;
					anim = 0;
				}
			
			}
			else if (map.map[i][j] == 'R')
			{
				if (direction == GhostDirection::right)
				{
					dx = 0;
					dy = -0.03;
					direction = GhostDirection::up;
					anim = 3;
				}
				else
				{
					dx = -0.03;
					dy = 0;
					direction = GhostDirection::left;
					anim = 1;
				}
			
			}
			

	

			if (map.map[i][j] == '0' && j > 20)
			{
				sprite.setPosition(660, 330);
				return;
			}
			else if (map.map[i][j] == '0' && j < 20)
			{
				sprite.setPosition(30, 330);
				return;
			}
	}

	void Animation()
	{
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		if (anim == 0)
		{
			animation += 0.005 * time;
			if (animation >= 2)animation = 0;
			sprite.setTextureRect(IntRect(30*int(animation),30,30,30));
		}
		else if (anim == 1)
		{
			animation += 0.005 * time;
			if (animation >= 8)animation = 6;
			sprite.setTextureRect(IntRect(30 * int(animation), 30 ,30, 30));
		}
		else if (anim == 2)
		{
			animation += 0.005 * time;
			if (animation >= 4)animation = 2;
			sprite.setTextureRect(IntRect(30 * int(animation), 30, 30, 30));
		}
		else if (anim == 3)
		{
			animation += 0.005 * time;
			if (animation >= 6)animation = 4;
			sprite.setTextureRect(IntRect(30 * int(animation), 30, 30, 30));
		}
	}

};
