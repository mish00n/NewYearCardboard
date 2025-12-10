//
//  Heart.cpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 10.12.2025.
//

#include "Shapes.hpp"

SpinHeart::SpinHeart(double t, float step) : Shape(t, step) {
      origin = {HSIZE / 2, VSIZE / 2};
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
      sf::Vector2f vec = {size * x, -size * y};
      return vec;
}
