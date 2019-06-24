#include "Player.Hpp"
#include "Rockets.hpp"
#include <SFML/Graphics.hpp>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

class Aurtus
{
public:
    void run();
    void genrocket();
    Aurtus() : window(sf::VideoMode(1200, 800), "Aurtus"), Tex_background(), Spr_bck(), Top(), rocket(), guy(), end{0}
    {

        Tex_background.loadFromFile("Assets\\BCK2.jpg");
        Global_Tex.loadFromFile("Assets\\roc.png");
        Player123.loadFromFile("Assets\\Player.png");
        Spr_bck.setTexture(Tex_background);

        Top.setSize(sf::Vector2f(1200.0, 50.0));
        Top.setFillColor(sf::Color(0, 0, 0));
        Top.setPosition(sf::Vector2f(0.0, 0.0));
        rocket.newRoc(150.0, Global_Tex);
        guy.load_tex(Player123);
    }

public:
    sf::RenderWindow window;
    sf::Texture Tex_background;
    sf::Sprite Spr_bck;
    sf::RectangleShape Top;
    sf::Texture Global_Tex;
    sf::Texture Player123;
    Rockets rocket;
    Player guy;
    int end;
};
void Aurtus::run()
{
    window.setVerticalSyncEnabled(true);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                end = 1;
                window.close();
            }
        }

        window.draw(Spr_bck);
        window.draw(Top);
        rocket.move();
        rocket.drawrockets(window);
        
        guy.render(window);
        window.display();
    }
}

void genrocket(Aurtus *A)
{
    std::random_device dev;
    std::default_random_engine eng{dev()};
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(500, 1000);

    std::uniform_int_distribution<std::mt19937::result_type> dist7(100, 1100);
    while (1)
    {
        int numofroc = A->rocket.countroc();
        if (numofroc < 11)
        {
            Sleep(dist6(rng));
            A->rocket.newRoc((float)dist7(rng), A->Global_Tex);
            
            std::cout << "\n"
                      << numofroc << "\n";
            
            if (A->end == 1)
            {
                break;
            }
            
        }
        A->rocket.deletemanager(0.0,0.0);

    }
}

int main()
{
    Aurtus A;
    sf::Thread a(&genrocket, &A);
    a.launch();
    A.run();
    a.terminate();
}