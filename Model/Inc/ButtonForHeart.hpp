//
//  Button.hpp
//  SFMLtest
//
//  Created by Michael Lebedev on 05.12.2025.
//

#ifndef Button_hpp
#define Button_hpp


#include "SFML/Graphics.hpp"


class Button {
public:
      sf::Vector2f pos;
      sf::Vector2f size = {200, 100};
      sf::Color color = sf::Color::Yellow;
      bool linkedVar;
      std::string text;

      
      void draw(sf::RenderWindow *window);
      Button(sf::Vector2f pos, bool var, std::string text);
      bool checkPress(sf::Vector2f click);
};



#endif /* Button_hpp */
