#include <SFML/Graphics.hpp>
#include <iostream>
class Rockets
{
public:
    int id;
    sf::Sprite Data;
    Rockets *next;
    Rockets() : id{0}, Data(), next{nullptr}
    {
        ;
    }
    void newRoc(double y, const sf::Texture &Global_Tex);
    void deleteroc(int idel);
    void move();
    void drawrockets(sf::RenderWindow &window);
    int countroc();
    void render();
};

void Rockets::newRoc(double y, const sf::Texture &Global_Tex)
{
    Rockets *temp{next};
    if (next == nullptr)
    {
        next = new Rockets();
        next->Data.setTexture(Global_Tex);
        next->Data.setOrigin(-1100, -y);
        next->next = nullptr;
        next->id = id + 1;
    }
    else
    {

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        Rockets *new1 = new Rockets();
        // std::cout<<"Rocket Initialised\n";
        new1->Data.setTexture(Global_Tex);
        new1->Data.setOrigin(-1100, -y);
        new1->id = temp->id + 1;
        new1->next = nullptr;
        temp->next = new1;
    }
}

void Rockets::deleteroc(int idel)
{
    Rockets *temp{next};
    Rockets *del{nullptr};
    if (next->id == idel)
    {
        del = next;
        next = next->next;
        delete del;
    }
    while (temp->next != nullptr)
    {
        if (temp->next->id == idel)
        {
            del = temp->next;
            temp->next = temp->next->next;
            delete del;
            break;
        }
    }
    del = nullptr;
}
void Rockets::move()
{
    Rockets *temp{nullptr};
    temp = next;
    if (next != nullptr)
    {
        sf::Vector2f a = next->Data.getPosition();
        next->Data.setPosition(a.x - 1.0, a.y);
    }
    while (temp->next != nullptr)
    {
        sf::Vector2f a = temp->Data.getPosition();
        temp->Data.setPosition(a.x - 1.0, a.y);

        temp = temp->next;
    }
}

void Rockets::drawrockets(sf::RenderWindow &window)
{
    Rockets *temp{nullptr};
    temp = next;
    if (next != nullptr)
        window.draw(next->Data);
    // window.draw(next->next->Data);
    while (temp->next != nullptr)
    {
        window.draw(temp->Data);
        temp = temp->next;
        // std::cout<<"Rocket Drawn\n";
    }
}

int Rockets::countroc()
{
    int a = 1;
    Rockets *temp = next;
    while (temp->next != nullptr)
    {
        a += 1;
        temp = temp->next;
    }
    return a;
}
