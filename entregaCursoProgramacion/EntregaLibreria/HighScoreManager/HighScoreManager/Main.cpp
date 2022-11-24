#include <SFML/Graphics.hpp>
#include "HighScoreManager.h"
int main()
{
   

        HighScoreManager hsm;

        hsm.putScore(30, "jose");
        hsm.putScore(100, "manu");
        hsm.putScore(40, "cristian");
        hsm.putScore(20, "lalo");
        hsm.putScore(75, "adrian");
        hsm.changeScore(120, "manu");
        hsm.deleteScore("manu");
        hsm.viewScore();
        sf::RenderWindow window(sf::VideoMode(1024, 860), "HIGHSCORE");

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(); // Limpia la pantalla clr

            window.draw(hsm);

            window.display(); // Renderiza la imagen final
        }

    return 0;
}