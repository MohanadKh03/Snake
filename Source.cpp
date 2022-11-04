#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode::getFullscreenModes()[0], "SFML works!", Style::None);

    RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(10, 20);
    rectangle.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            if (rectangle.getPosition().x == window.getSize().x || rectangle.getPosition().y == window.getSize().y)
                rectangle.setPosition(0, 0);
            if (Keyboard::isKeyPressed(Keyboard::Right))
                rectangle.setPosition(Vector2f(5 + rectangle.getPosition().x, rectangle.getPosition().y));
            if (Keyboard::isKeyPressed(Keyboard::Left))
                rectangle.setPosition(Vector2f(rectangle.getPosition().x - 5, rectangle.getPosition().y));
            if (Keyboard::isKeyPressed(Keyboard::Up))
                rectangle.setPosition(Vector2f(rectangle.getPosition().x, rectangle.getPosition().y - 5));
            if (Keyboard::isKeyPressed(Keyboard::Down))
                rectangle.setPosition(Vector2f(rectangle.getPosition().x, 5 + rectangle.getPosition().y));
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}