#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"map.h"

using namespace std;
using namespace sf;

enum GhostDirection {
	up,down,left,right,none
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
	int startX, startY;
	GhostState state;
	int animation;
	bool isInHome;
	bool gameOver;
	float timer = 40;
	bool isEten;


	ghost()
	{
		sprite.setScale(0.8, 0.8);
		texture.loadFromFile("texture/PMSprites.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0,30,30,30));

		init();
	}

	void Move(FloatRect other,Pac pac)
	{
		if (isEten == true)
		{
			timer--;
			if (time <= 0)
			{
				isEten = false;
				time = 100;
				direction = GhostDirection::right;
				state = GhostState::Move;
				dx = 0.03;
			}
		}
		if (state == GhostState::Move)
		{
			

			Animation();

			if (dx > 0 || dx < 0 || dy < 0 || dy>0)
				sprite.move(time * dx, time * dy);

			y = sprite.getPosition().y / 30;
			x = sprite.getPosition().x / 30;
			inteacrt(y, x,other,pac);
			
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
					startX = j;
					startY = i;
					break;
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

	void inteacrt(int i,int j,FloatRect other,Pac pac)
	{
		FloatRect own = sprite.getGlobalBounds();


		if (own.intersects(other))
		{
			if (direction == GhostDirection::up && (dy > 0||dy<0))
			{
				isInHome = true;
				goHome();
			}
			else if (direction == GhostDirection::down && (dy < 0||dy>0))
			{
				isInHome = true;
				goHome();
			}
			else if (direction == GhostDirection::right && (dx < 0 || dx>0))
			{
				isInHome = true;
				goHome();
			}
			else if (direction == GhostDirection::left && (dx > 0 || dx < 0))
			{
				isInHome = true;
				goHome();
			}
			else
			   gameOver = true;
		}

		if (state == GhostState::Move)
		{
			for (int k = 0; k < 25; k++)
			{
				for (int q = 0; q < 23; q++)
				{
					if (i + 1 == k && q == j && map.map[i + 1][j] == 'W')
					{
						if (direction == GhostDirection::right)
						{

							dx = 0;
							dy = 0.03;
							direction = GhostDirection::down;
							anim = 3;
							animation = 2;
						}
						else
						{

							dx = -0.03;
							dy = 0;
							direction = GhostDirection::left;
							anim = 0;
							animation = 0;
						}
					}
					else if (i + 1 == k && q == j + 1 && map.map[i + 1][j + 1] == 'T')
					{
						if (direction == GhostDirection::left)
						{
							dx = 0;
							dy = 0.03;
							direction = GhostDirection::down;
							anim = 3;
							animation = 2;
						}
						else
						{
							dx = 0.03;
							dy = 0;
							direction = GhostDirection::right;
							anim = 1;
							animation = 4;
						}
					}
					else if (i == k && q == j && map.map[i][j] == 'R') {
						if (direction == GhostDirection::right)
						{
							dx = 0;
							dy = -0.03;
							direction = GhostDirection::up;
							anim = 2;
							animation = 2;
						}
						else
						{
							dx = -0.03;
							dy = 0;
							direction = GhostDirection::left;
							anim = 1;
							animation = 4;
						}
					}
					else if (i == k && q == j && map.map[i][j] == 'E')
					{
						if (direction == GhostDirection::left)
						{
							dx = 0;
							dy = -0.03;
							direction = GhostDirection::up;
							anim = 2;
							animation = 2;
						}
						else
						{
							dx = 0.03;
							dy = 0;
							direction = GhostDirection::right;
							anim = 0;
							animation = 0;
						}
					}
					else if (i == k && q == j && map.map[i][j] == 'F')
					{
						if (direction == GhostDirection::right)
						{
							dx = 0;
							dy = -0.03;
							direction = GhostDirection::down;
							anim = 2;
							animation = 2;
						}
						else
						{
							dx = 0.03;
							dy = 0;
							direction = GhostDirection::left;
							anim = 0;
							animation = 0;
						}
					}
					else if (i == k && q == j && map.map[i][j] == 'A')
					{
						if (direction == GhostDirection::up)
						{
							dx = 0;
							dy = -0.03;
							direction = GhostDirection::right;
							anim = 2;
							animation = 2;
						}
						else
						{
							dx = 0;
							dy = -0.03;
							direction = GhostDirection::up;
							anim = 2;
							animation = 2;
						}
					}
					else if (i == k && q == j && map.map[i][j] == 'Q')
					{
						if (direction == GhostDirection::left)
						{
							dx = 0;
							dy = 0.03;
							direction = GhostDirection::down;
							anim = 3;
							animation = 2;
						}
						else
						{
							dx = 0.03;
							dy = 0;
							direction = GhostDirection::right;
							anim = 1;
							animation = 4;
						}
					}
					else if (i + 1 == k && q == j + 1 && map.map[i + 1][j + 1] == 'Y')
					{
						if (direction == GhostDirection::right)
						{
							dx = 0;
							dy = -0.03;
							direction = GhostDirection::up;
							anim = 3;
							animation = 2;
						}
						else
						{
							dx = 0.03;
							dy = 0;
							direction = GhostDirection::left;
							anim = 1;
							animation = 4;
						}
					}
				}
			}
		}

        if (map.map[i][j] == '*')
	  {
		  isInHome = false;
		  dx = 0;
		  dy = -0.03;
		  direction = GhostDirection::up;
		  animation = 3;
		  return;
	  }	
		if (map.map[i+1][j] == 'G')
			{
				dx = 0.03;
				dy = 0;
				direction = GhostDirection::right;
				animation = 1;
				anim = 4;
				return;
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

	void goHome()
	{
		isEten = true;
		sprite.setPosition(startX * 30, startY * 30);
		state = GhostState::Stay;
		direction = GhostDirection::none;
		dx = 0;
		dy = 0;
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
