#ifndef H_BUTTON
#define H_BUTTON



#include <functional>

#include "Widget.h"



class Button : public Widget
{
private:
    
    using CallbackType = std::function<void(void)>;
    
    
    
public:
    
    Button(std::string text, CallbackType callback);
    
    
    
    void onEvent_(const sf::Event &event) override; 
    
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    
    
    
private:
    
    std::string m_text;
    
    CallbackType m_callback;
    
    sf::Sprite m_default_sprite;
    sf::Sprite m_hovered_sprite;
    sf::Sprite m_pressed_sprite;
};



#endif // H_BUTTON
