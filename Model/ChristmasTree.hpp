//
//  ChristmasTree.hpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 10.12.2025.
//

#ifndef ChristmasTree_hpp
#define ChristmasTree_hpp

#include "SFML/Graphics.hpp"

class Tree {
public:
      sf::Vector2<float> origin;
      sf::VertexArray treeOutline;
      std::vector<sf::ConvexShape> layers;
      int numOfLayers;
      int widthStep;
      int height;
      
      Tree(sf::Vector2<float> origin, int numOfLayers, int widthStep, int height);
      void buildTreeOutline();
      void buildTreeFill();
      void draw(sf::RenderWindow *window);
};

#endif /* ChristmasTree_hpp */
