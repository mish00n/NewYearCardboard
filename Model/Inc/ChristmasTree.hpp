//
//  ChristmasTree.hpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 10.12.2025.
//

#ifndef ChristmasTree_hpp
#define ChristmasTree_hpp

#include "SFML/Graphics.hpp"

class Light {
public:
      sf::Vector2f pos;
      float radius = 3;
      int colorNum = 0;
      int cnt = 0;
      sf::Color color = sf::Color::Blue;
      
      Light(sf::Vector2f pos);
      void draw(sf::RenderWindow *window);
};


class Tree {
public:
      sf::Vector2f origin;
      sf::VertexArray treeOutline;
      std::vector<sf::ConvexShape> layers;
      std::vector<Light> lights;
      int numOfLayers;
      int widthStep;
      int height;
      bool lightsOn = false;
      
      Tree(sf::Vector2<float> origin, int numOfLayers, int widthStep, int height);
      void buildTreeOutline();
      void buildTreeFill();
      void draw(sf::RenderWindow *window);
};



#endif /* ChristmasTree_hpp */
