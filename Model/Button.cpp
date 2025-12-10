//
//  Button.cpp
//  SFMLtest
//
//  Created by Michael Lebedev on 05.12.2025.
//

#include "Button.hpp"


void Button::draw(sf::RenderWindow *window) {
      sf::RectangleShape rectangle;
      rectangle.setSize(size);
      rectangle.setPosition(pos);
      rectangle.setFillColor(color);
      window->draw(rectangle);
      
      sf::Font font("Arial.ttf");
      sf::Text text(font, this->text);
      text.setCharacterSize(20);
      text.setStyle(sf::Text::Italic);
      text.setFillColor(sf::Color::Red);
      sf::FloatRect textRect = text.getLocalBounds();
      text.setOrigin({textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f});
      text.setPosition(rectangle.getPosition() + rectangle.getSize() / 2.0f);
      
      window->draw(text);
}

Button::Button(sf::Vector2f pos, bool var, std::string text) {
      this->pos = pos;
      this->pos.x -= size.x / 2;
      this->pos.y -= size.y / 2;
      linkedVar = var;
      this->text = text;
}

bool Button::checkPress(sf::Vector2f click) {
      return (fabs((click - pos).x) < size.x && fabs((click - pos).y) < size.y);
}
