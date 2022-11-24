#pragma once
#include<string>
#include <iostream>
#include<list>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
struct Score {
	int score;
	string name;
}
;
class HighScoreManager : public sf::Drawable
{
public:
	HighScoreManager();
	~HighScoreManager();
	void putScore(int _score, string name);
	void changeScore(int score,string name);
	void deleteScore(string name);
	void viewScore();
	void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
private:

	vector<Score>vecScore;
	vector<sf::Text>vecText;
	sf::Font font;
	sf::Text title;
	
private:
	void order(Score s);
	void textScore(Score s, int n);
};

