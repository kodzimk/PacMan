#pragma once
#include"pac.h"
#include"fruit.h"
#include"map.h"
#include<SFML/Graphics.hpp>
#include"ghostEnemy.h"
#include"sound.h"

using namespace std;
using namespace sf;

class Starter {
public:
	Pac pac;
	Map map;
	RenderWindow window;
	Texture texture;
	Sprite sprite;
	ghost redGhost;
	Text gameOverText;	
	fruit fruits;
	

	Starter()
	{
		
		gameOverText.setFont(pac.font);
		gameOverText.setString("Game Over");
		gameOverText.setScale(sf::Vector2f(5,5));

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
			if(!redGhost.gameOver){
			FloatRect other = pac.sprite.getGlobalBounds();

			redGhost.Move(other,pac);

	
				pac.inreactwithworld(pac.sprite.getPosition().y / 30, pac.sprite.getPosition().x / 30, map);

				for (int i = 0; i < map.dotsArr.size(); i++)
				{
					FloatRect other = map.dotsArr[i].getGlobalBounds();
					pac.move(other);
				}
			}

			winGame();

			window.clear();	
			window.draw(map.sprite);		
			for (int i = 0; i < map.dotsArr.size(); i++)
			{
				window.draw(map.dotsArr[i]);
			}		
			window.draw(redGhost.sprite);
			if (redGhost.gameOver)
			{
				window.draw(gameOverText);
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
			window.draw(pac.sprite);
			window.draw(pac.scoreText);
			window.display();
		}
	}
	void GameStart(bool startgame, ghost* redGhost,Pac* pac)
	{

			(*redGhost).state = GhostState::Move;
			(*redGhost).dx = 0.03;
			
			(*pac).startGame = false;
	}

	void winGame()
	{
		int count = 0;
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 23; j++)
			{
				if (map.map[i][j] == ' ')
				{
					count++;
				}
			}
	    }
		if (count == 0)
		{
			redGhost.gameOver = true;
			gameOverText.setString("You win");
			gameOverText.setScale(Vector2f(5,5));
			pac.dx = 0;
			pac.dy = 0;
		}
	}

};


