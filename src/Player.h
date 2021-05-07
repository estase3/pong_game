#pragma once
#include <SFML/Graphics.hpp>
class Player 
{
	friend class Ball;
public:
	float playerWidth = 10;
	Player(float windowWidth, float windowHight);
	void moveUp();
	void moveDown(float windowHight);
	void setPos(sf::Vector2f newPos);
	float getX();
	float getY();
	void draw(sf::RenderWindow &window);

private:
	sf::RectangleShape player, Up, Down, Right, Left;
	float  playerHight = 130, playerSpeed = 7;
	
};

Player::Player(float windowWidth,float windowHight) {
	player.setSize(sf::Vector2f(playerWidth, playerHight));
	player.setFillColor(sf::Color::White);
	Up.setSize(sf::Vector2f(windowWidth, 1));
	Down.setSize(sf::Vector2f(windowWidth, 1));
	Left.setSize(sf::Vector2f(1, windowHight));
	Right.setSize(sf::Vector2f(1, windowHight));
	Up.setPosition(0, 0);
	Down.setPosition(0, windowHight - 1);
	Left.setPosition(0, 0);
	Right.setPosition(windowWidth - 1, 0);
	
}

void Player::moveUp() {
	if(player.getPosition().y>1-playerHight/2)
		player.move(0,-playerSpeed);
}
void Player::moveDown(float windowHight) {
	if (player.getPosition().y+playerHight<windowHight+playerHight/2 )
		player.move(0, playerSpeed);
}
void Player::setPos(sf::Vector2f newPos)
{
	player.setPosition(newPos);
}
float Player::getX() {
	return player.getPosition().x;
}
float Player::getY() {
	return player.getPosition().y;
}
void Player::draw(sf::RenderWindow &window) {
	window.draw(player);
	window.draw(Left);
	window.draw(Right);
	window.draw(Up);
	window.draw(Down);

}
