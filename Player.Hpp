#include <SFML/Graphics.hpp>
#include<iostream>
class Player
{
public:
    sf::Sprite guy;
    double posx;
    double posy;
    void controls();
    void render(sf::RenderWindow &win);
    void load_tex(sf::Texture &a)
    {
        guy.setTexture(a);
        guy.setOrigin(-100, -400);
    }
    void gravity()
    {
        sf::Vector2f a = guy.getPosition();
        guy.setPosition(a.x, a.y + 2);
    }

    Player()
    {
    }
};

void Player::controls()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        guy.move(0, -5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        guy.move(0, -5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        guy.move(0, 5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sf::Vector2f a = guy.getPosition();
        if (guy.getPosition().x >-100)
            {guy.setPosition(a.x - 5, a.y);}
        // if (guy.getRotation() < 90)
        //     guy.rotate(10);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sf::Vector2f a = guy.getPosition();
        if (guy.getPosition().x < 950)
            {guy.setPosition(a.x + 5, a.y);
            // std::cout<<a.x<<std::endl;
            }
        else{;}
        // if (guy.getRotation() > 270 || (guy.getRotation() > 0 && guy.getRotation() < 90))
        //     guy.rotate(-10);
    }
}

void Player::render(sf::RenderWindow &window)
{
    controls();
    gravity();
    window.draw(guy);
}