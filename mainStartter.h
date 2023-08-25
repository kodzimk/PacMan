#pragma once
#include<SFML/Graphics.hpp>
#include"PacPlayer.h"
#include<iostream>
#include"map.h"

using namespace sf;

class StartGame {
public:
	Pac player;
    Map map;

    sf::RenderWindow window;
	StartGame()
	{
        window.create(sf::VideoMode(690, 750), "Pac Man!");

       
        LoopGame();
	}

	void LoopGame()
	{
        while (window.isOpen())
        {

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            player.Move();
           
            window.clear();
            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 23; j++)
                {
                    if (map.map[i][j] == ' ' && map.map[i][j] != '1')
                    {
                        map.sprite.setPosition(j * 30, i * 30);
                        window.draw(map.sprite);
                    }
                }
            } 
            window.draw(map.mapS);
            window.draw(player.scoreText);
            window.draw(player.sprite);


            window.display();
        }
	}
};