//
//  HeartModel.hpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 09.12.2025.
//

#ifndef HeartModel_hpp
#define HeartModel_hpp

#include "SFML/Graphics.hpp"
#include "time.h"
#include <algorithm>
#include <unistd.h>

enum WindowSize{
      HSIZE = 1600,
      VSIZE = 1000,
};

class SpinHeart {
public:
      sf::Vector2f origin;
      double t;
      float step;
      double mem = 2;
      double tMem = 0;
      std::vector<sf::VertexArray> segments;
      
      SpinHeart();
      
      sf::Vector2f getPointOnShape(bool random=false);
      void addPoint(sf::Vector2f vec);
      void draw(sf::RenderWindow* window);
      
};


#endif /* HeartModel_hpp */
