#include <iostream>
#include <experimental/filesystem>



#define SFML_STATIC

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"



#include "src/ResourceManager.h"
#include "src/GUI/Button.h"
#include "src/GUI/Image.h"



int main(int, char *argv[])
{
    std::string path = std::experimental::filesystem::path(argv[0]).parent_path().string();
    path += '\\';
    ResourceManager::init(path);
    
    Button b1("abc", [](){std::cout << "Hello world!" << std::endl;});
    b1.setPosition({500.f, 100.f});
    
    Image i1("duckcarrier");
    i1.setPosition({100.f, 100.f});
    
    
    
    
    sf::RenderWindow window(sf::VideoMode(1280, 721), "My window", sf::Style::Close);
    window.setPosition({0, 0});
    window.setSize({1280, 720});
    window.setView(sf::View({640, 360}, {1280, 720}));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            b1.onEvent(event);
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::P)
                {
                    
                }
            default:
                break;
            }
        }
        
        window.clear();
        window.draw(i1);
        window.draw(b1);
        window.display();
    }
    
    return 0;
}
