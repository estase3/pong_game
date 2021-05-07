#pragma once
#include <SFML/Graphics.hpp>

class Score 
	{
	friend class Ball;
public:
	Score();
	Score(float width,float hight);
	void setScore(int score);
	void IncrementScore();
	void setPos(sf::Vector2f newPos);
	void draw(sf::RenderWindow &window);
private:
	sf::Text score;
	sf::Font font;
	int value;
}; 
Score::Score() {

}
Score::Score(float width, float hight) {
	value = 0;
	font.loadFromFile("PressStart2P.ttf");
	score.setFont(font);
	score.setFillColor(sf::Color::White);
	score.setPosition(width,hight);
	score.setCharacterSize(50);
	score.setString(std::to_string(value));
}
void Score::IncrementScore() {
	value += 1;
	score.setString(std::to_string(value));
}

void Score::setPos(sf::Vector2f newPos) {
	score.setPosition(newPos);
}
void Score::draw(sf::RenderWindow &window) {
	window.draw(score);
}
void Score::setScore(int scorevalue) {
	value = scorevalue;
	score.setString(std::to_string(value));
}
