#pragma once
#include <SFML/Graphics.hpp>
#define M_PI 3.14159265358979323846

class Ball
{

public:
	Ball();
	Ball(float width, float hight);
	void setPos(sf::Vector2f newPos);
	void bounceX(Player &player);
	void bounceY();
	float getRight();
	float getLeft();
	float getTop();
	float getBottom();
	void draw(sf::RenderWindow &window);
	void move();
	void setBallRadius(float radius);
	void checkColLeft(Player &player);
	void checkColRight(Player &player);
	void checkPitchCol(float windowWidth, float windowHight);
	void reset(float windowWidth, float windowHight);
	private:
	sf::CircleShape ball;
	float ballRadius = 5, speedX , speedY = 0;
		
};
Ball::Ball() {

}
Ball::Ball(float width, float hight) {
	speedX = (float)(rand() % 2);
	if (speedX == 0.f)
		speedX = -7.f;
	else
		speedX = 7.f;
	ball.setRadius(ballRadius);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(width/2, hight/2 );
}
void Ball::setPos(sf::Vector2f newPos)
{
	ball.setPosition(newPos);
}
float Ball::getRight() {
	return ball.getPosition().x + ball.getRadius();
}
float Ball::getLeft() {
	return ball.getPosition().x - ball.getRadius();
}
float Ball::getTop() {
	return ball.getPosition().y - ball.getRadius();
}
float Ball::getBottom() {
	return ball.getPosition().y + ball.getRadius();
}
void Ball::draw(sf::RenderWindow &window) {
	window.draw(ball);
}
void Ball::move()
{
	ball.move(speedX, speedY);
}
void Ball::setBallRadius(float radius){
	ball.setRadius(radius);
}
void Ball::bounceX(Player &player) {

	float relativeIntersectY = (player.getY() + (player.playerHight / 2)) - ball.getPosition().y;
	float normalizedRelativeIntersectionY = (relativeIntersectY / (player.playerHight / 2));
	float bounceAngle = normalizedRelativeIntersectionY * (float)(3 * M_PI / 12);
	if (ball.getPosition().x < 200)
	{
	speedX = 15 * cos(bounceAngle);
	speedY = 15 * -sin(bounceAngle);
	}
	else 
	{
		speedX = -15 * cos(bounceAngle);
		speedY = 15 * -sin(bounceAngle);
	}
}

void Ball::bounceY() {
	speedY = -speedY;

}
void Ball::checkColLeft(Player &player) {
	if (player.getX() + player.playerWidth >= getLeft() && player.getY() <= getBottom() && player.getY() + player.playerHight >= getTop() && getRight() >player.getX())
	{
		bounceX(player);	
	}
}
void Ball::checkColRight(Player &player) {
	if (player.getX() <= getRight() && player.getY() <= getTop() && player.getY() + player.playerHight >= getBottom() && getLeft() < (player.getX()+player.playerWidth))
		bounceX(player);
}
void Ball::checkPitchCol(float windowWidth, float windowHight) {
	if (getTop() <= 1)
		bounceY();
	else if (getBottom() >= windowHight)
		bounceY();
}
void Ball::reset(float windowWidth, float windowHight) {
		setPos(sf::Vector2f(windowWidth / 2, windowHight / 2));
		speedX = (-speedX/abs(speedX))*7 ;
		speedY = (float)(rand() % 7 - 3);
}
