#include"HighScoreManager.h"

HighScoreManager::HighScoreManager() {
    if (!font.loadFromFile("../assets/fonts/comic.ttf"))
    {
        // error...
    }
    title.setFont(font);
    title.setString("<<*************LEADERBOARD*****************>>");
    title.setCharacterSize(45);
    title.setFillColor(sf::Color::Green);
    title.setPosition(100, 0);
}
HighScoreManager::~HighScoreManager() {
}
void HighScoreManager::putScore(int _score, string _name) {
    Score score;
    score.name = _name;
    score.score = _score;

    order(score);
}
void HighScoreManager::changeScore(int score, string name) {
    for (int i = 0; i < vecScore.size(); i++) {
        if (name == vecScore[i].name) {
            vecScore[i].score = score;
        }
    }
    
}
void HighScoreManager::deleteScore(string name) {
    for (int i = 0; i < vecScore.size(); i++) {
        if (name == vecScore[i].name) {
            vecScore.erase(vecScore.begin()+i);
        }
    }
}
void HighScoreManager::viewScore() {
    for (int i = 0; i < vecScore.size(); i++) {
        int num = i * 40;
        textScore(vecScore[i], num);
    }
}
void HighScoreManager::textScore(Score score, int incremento) {
    sf::Text text;
    text.setFont(font);
    text.setString(string(+"Name:" + score.name + " Score:" + to_string(score.score)));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Red);
    text.setPosition(350, 70 + incremento);
    vecText.push_back(text);
}
void HighScoreManager::draw(sf::RenderTarget& window, sf::RenderStates states)const {
    window.draw(title);
    for (const sf::Text& text : vecText)
    {
        window.draw(text);
    }
}

void HighScoreManager::order(Score s) {



    vecScore.push_back(s);
    for (int i = 0; i < vecScore.size(); i++) {

        for (int i2 = 0; i2 < vecScore.size(); i2++) {
            if (vecScore[i].score > vecScore[i2].score) {
                Score aux = vecScore[i];
                vecScore[i] = vecScore[i2];
                vecScore[i2] = aux;
            }
        }
    }
    cout << "separando" << endl;
    for (Score s : vecScore) {
        cout << s.score << endl;
    }



}


