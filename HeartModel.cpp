//
//  HeartModel.cpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 09.12.2025.
//

#include "HeartModel.hpp"
#define eps 1e-9

SpinHeart::SpinHeart() {
      origin = {HSIZE / 2, VSIZE / 2};
      t = 0;
      step = 180 * 2;
      // step = 47.51;
}


sf::Vector2f SpinHeart::getPointOnShape(bool random) {
      srand((unsigned int)time(NULL));
      float arg = t;
      if (mem == 2) {
            mem = cos(arg);
            tMem = t;
      }
      else if ((mem - cos(arg)) < eps) {
            t = tMem;
            // mem = 2;
            // tMem = 0;
      }
      float x = 16 * sin(arg) * sin(arg) * sin(arg);
      float y = 13 * cos(arg) - 5 * cos(2 * arg) - 2 * cos(3 * arg) - cos(4 * arg);
      if (random)  t += rand() % 180;
      else  t += step;
      int mul = 25;
      sf::Vector2f vec = {mul * x, -mul * y};
      return vec;
}


void SpinHeart::addPoint(sf::Vector2f vec) {
      if (segments.size() >= 1000) {
            segments.erase(segments.begin());
      }
      sf::VertexArray seg(sf::PrimitiveType::Lines, 2);
      seg[0].position = origin;
      seg[1].position = vec + origin;
      
      seg[0].color = sf::Color::Red;
      seg[1].color = sf::Color::Red;
      
      segments.push_back(seg);
}

void SpinHeart::draw(sf::RenderWindow *window) {
      for (sf::VertexArray seg : segments) {
            window->draw(seg);
      }
}
