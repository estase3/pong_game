#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define NUMBERS_OF_ITEMS 3
enum GameMode { gamemenu, gameplay,} gamemode;
class Menu
{
public:
	Menu(float width, float height);
	void draw(sf::RenderWindow &window);
	void Up();
	void Down();
	int Pressed();
private:
	int selectedItem;
	sf::Font font;
	sf::Text menu[NUMBERS_OF_ITEMS];
	float textWidth;
};
void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < NUMBERS_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
};
Menu::Menu(float width, float height) {

	if (!font.loadFromFile("PressStart2P.ttf"))
	{
		std::cout << "XD";
	}

	menu[0].setCharacterSize(45);
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	textWidth = menu[0].getGlobalBounds().width;
	menu[0].setPosition(sf::Vector2f(width / 2-textWidth/2, height / (NUMBERS_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Reset");
	textWidth = menu[1].getGlobalBounds().width;
	menu[1].setPosition(sf::Vector2f(width / 2 - textWidth / 2, height / (NUMBERS_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	textWidth = menu[2].getGlobalBounds().width;
	menu[2].setPosition(sf::Vector2f(width / 2 - textWidth / 2, height / (NUMBERS_OF_ITEMS + 1) * 3));




	selectedItem = 0;
}
void Menu::Down()
{
	if (selectedItem + 1 < NUMBERS_OF_ITEMS)
	{
		menu[selectedItem].setCharacterSize(30);
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Red);
		menu[selectedItem].setCharacterSize(45);
	}
};
void Menu::Up()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setCharacterSize(30);
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Red);
		menu[selectedItem].setCharacterSize(45);
	}
};
int Menu::Pressed(){
	return selectedItem; 
}
