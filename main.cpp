//
//  main.cpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 09.12.2025.
//

#include "HeartModel.hpp"

enum Params {
      ANANASTYA,
      MISHOON,
};



int main(void) {
      int mode = ANANASTYA;
      int delay = 1;
      int framesToSkip = 1;
      double step = 1;
      bool random = 0;
      bool clear = 1;
      
      if (mode == ANANASTYA) {
            // Ananastasia's Heart
            delay = 50000000;
            framesToSkip = 1;
            random = true;
            clear = false;
      }
      
      if (mode == MISHOON) {
            delay = 50000;
            framesToSkip = 10;
            random = false;
            step = 180 * 2;
            clear = true;
      }
      
      struct timespec req;
      req.tv_sec = 0;
      req.tv_nsec = delay;
      
      sf::RenderWindow window(sf::VideoMode({HSIZE, VSIZE}), "SortTiles");
      window.setVerticalSyncEnabled(false);
      
      SpinHeart heart = SpinHeart();
      if (!random) {
            heart.step = step;
      }

      
      int cnt = 0;
      while (window.isOpen()) {
            nanosleep(&req, NULL);
            cnt++;
            sf::Vector2f point = heart.getPointOnShape(random);
            heart.addPoint(point);
            // fflush(stdout);
            // printf("t = %lf \n", heart.mem);
            while (const std::optional event = window.pollEvent()) {
                  if (event->is<sf::Event::Closed>())
                        window.close();
                  
                  if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                              window.close();
                  }
            }
            if (cnt %framesToSkip == 0) {
                  if (clear) {
                        window.clear();
                  }
                  heart.draw(&window);
                  window.display();
                  cnt = 0;
            }
            
            
      }
      
      return 0;
}

