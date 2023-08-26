#include<SFML/Graphics.hpp>
#include <thread>
#include"map.h"

#include<iostream>

using namespace sf;


enum PacDirection
{
 Up,Right,Down,Left
} pacDirection,pacPrevDirection;


class Pac 
{
public:
	Texture texture;
	Sprite sprite;
	float x, y, dy, dx,anim,time;
	int currentAnim;
	Clock clock;
	PacDirection direction;
	Map map;
	Font font;
	int score = 0;
	Text scoreText;
	bool startGame = false;
	std::vector<Sprite> fruits;

	Pac()
	{
		font.loadFromFile("font/comic.ttf");

		scoreText.setString("0");
		scoreText.setScale(1, 1);
		scoreText.setFont(font);
		
		texture.loadFromFile("texture/title.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 25, 25, 25));
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 23; j++)
			{
				if (map.map[i][j] == '1')
				{
					sprite.setPosition(j * 30, i * 30);
					break;
				}
			}
		}
		init();
		
	}

	void init()
	{
		currentAnim = 1;
		dy = 0;
		dx = 0;
		x = sprite.getPosition().x;
		y = sprite.getPosition().y;
		anim = 0;
		time = 0;
	}

	void inreactwithworld(int i,int j)
	{
		if (map.map[i][j] == ' ')
		{
			score += 10;
			scoreText.setString(std::to_string(score));
			map.map[i][j] = '9';
		}
			if (map.map[i][j] == '0'&&j>20)
			{
				sprite.setPosition(30,11*30);
			}
			else if (map.map[i][j] == '0' && j < 20)
			{
				for (int i = 11; i < 25; i++)
				{
					for (int j = 10; j < 23; j++)
					{
						if (map.map[i][j] == '0')
						{
							sprite.setPosition(j*30, i*30);
						}
					}
				}
				
				
			}
					
	}

	bool isCanMove(int i,int j,FloatRect other)
	{
		FloatRect own = sprite.getGlobalBounds();

		if (other.intersects(own))
		{
			if (dx < 0)
			{
				dx = 0;
				dy = 0;
				sprite.setPosition((j+1) * 30, i * 30);
				return true;
			}
			else if (dx > 0)
			{
				dx = 0;
				dy = 0;
				sprite.setPosition(j*30,i*30);
				return true;
			}
			else if (dy < 0)
			{
				dx = 0;
				dy = 0;
				sprite.setPosition(j * 30, (i+1)  * 30);
				return true;
			}
			else if (dy > 0)
			{
				dx = 0;
				dy = 0;
				sprite.setPosition(j * 30, i  * 30);
				return true;
			}
		  
		}
		else
			return false;
		
	}

	void move(FloatRect other)
	{
		if (isPressedKeyboardButton() == true)
		{
			changePD();
		}


		Animation();

		x = sprite.getPosition().x;
		y = sprite.getPosition().y;
		
		

		if (isCanMove(y / 30, x / 30,other)==false)
           	sprite.move(dx * time, dy * time);



	}

	bool isPressedKeyboardButton()
	{
		return Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right) ||
			Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::Up);
	}

	void changePD()
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			currentAnim = 4;
			direction = PacDirection::Down;
			dx = 0;
			dy = 0.05;
			startGame = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			direction = PacDirection::Up;
			currentAnim = 3;
			dx = 0;
			dy = -0.05;
			startGame = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			direction = PacDirection::Left;
			currentAnim = 2;
			dx = -0.05;
			dy = 0;

				startGame = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			direction = PacDirection::Right;
			currentAnim = 1;
			dy = 0;
			dx = 0.05;
				startGame = true;
		}
	}

	void Animation()
	{
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		anim += 0.005 * time;
		if (anim >= 4)anim = 0;
		sprite.setTextureRect(IntRect(25 * int(anim), 25*currentAnim, 25, 25));
		
	}

};