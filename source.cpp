#include <SFML/Graphics.hpp>
#include <cmath>
#include <time.h>  
#include "Player.h"
#include "Ball.h"
#include "Menu.h"
#include "Score.h"

int main()
{
	srand((int)time(NULL));
	sf::RenderWindow window;
	window.create(sf::VideoMode(1200,900), "Pong");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(true);

	float windowWidth = (float)window.getSize().x, windowHight = (float)window.getSize().y, playerWidht = 10, playerHight = 150; 

	Score score1(windowWidth / 2 - 100, 50), score2(windowWidth / 2 + 50, 50);
	Player player1(windowWidth,windowHight),player2(windowWidth,windowHight);
	Ball ball(windowWidth,windowHight);
	Menu menu(windowWidth,windowHight);

	player1.setPos(sf::Vector2f(35, windowHight / 2 - playerHight / 2));
	player2.setPos(sf::Vector2f(windowWidth - 35 - playerWidht, windowHight / 2 - playerHight / 2));

	gamemode = gamemenu;
	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed )
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				gamemode=gamemenu;
			}
			switch (Event.type)
			{
			case sf::Event::KeyPressed:
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu.Up();
					break;
				case sf::Keyboard::Down:
					menu.Down();
					break;
				case sf::Keyboard::Return:
					switch (menu.Pressed())
					{
					case 0:
						gamemode = gameplay;
						break;
					case 1:
					{
						ball.reset(windowWidth, windowHight);
					
					player1.setPos(sf::Vector2f(25, windowHight / 2 - playerHight / 2));
					player2.setPos(sf::Vector2f(windowWidth - 25 - playerWidht, windowHight / 2 - playerHight / 2));
					score1.setScore(0);
					score2.setScore(0);
					gamemode = gameplay;
					}
						break;
					case 2:
						window.close();
						break;
					}
				}

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			player2.moveDown(windowHight);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			player2.moveUp();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			player1.moveDown(windowHight);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			player1.moveUp();

		window.clear();

		if (gamemode == gamemenu)
			menu.draw(window);
		else if (gamemode == gameplay)
		{
			if (ball.getLeft() <= 1 )
			{
				ball.reset(windowWidth,windowHight);
				score2.IncrementScore();
			}
			if (ball.getRight() >= windowWidth)
			{
				ball.reset(windowWidth, windowHight);
				score1.IncrementScore();	
			}
			ball.checkPitchCol(windowWidth, windowHight);
			ball.checkColLeft(player1);
			ball.checkColRight(player2);
			ball.draw(window);
			ball.move();	
			player1.draw(window);
			player2.draw(window);
			score1.draw(window);
			score2.draw(window);
		}
		window.display();
	}
	return 0;
}
