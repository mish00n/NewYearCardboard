//
//  Shapes.hpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 10.12.2025.
//

#ifndef Shapes_hpp
#define Shapes_hpp

#include "SFML/Graphics.hpp"
#include "time.h"
#include <algorithm>
#include <unistd.h>
#define eps 1e-9

enum WindowSize{
      HSIZE = 1600,
      VSIZE = 1000,
};

class Shape {
public:
      sf::Vector2f origin;
      double t;
      float step;
      std::vector<sf::VertexArray> segments;
      
      Shape(double t=0, float step=180);
      
      virtual sf::Vector2f getPointOnShape(bool random=false) = 0;
      void addPoint(sf::Vector2f vec);
      void draw(sf::RenderWindow* window);
};

class SpinHeart: public Shape {
public:
      double mem = 2;
      double tMem = 0;
      int size = 25;
      
      SpinHeart(double t=0, float step=180);
      sf::Vector2f getPointOnShape(bool random=false) override;
};

#endif /* Shapes_hpp */
