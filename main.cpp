//
//  main.cpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 09.12.2025.
//

#include "Shapes.hpp"
#include "ButtonForHeart.hpp"
#include "ChristmasTree.hpp"

enum Params {
      ANANASTYA,
      MISHOON,
};


void DisplayWindow(sf::RenderWindow *window) {
      
      int mode = MISHOON;
      int delay = 1;
      int framesToSkip = 1;
      double step = 1;
      bool random = 0;
      bool clear = 1;
      bool buttonClicked = false;
      
      if (mode == ANANASTYA) {
            // Ananastasia's Heart (random points on shape)
            delay = 50000000;
            framesToSkip = 1;
            random = true;
            clear = false;
      }
      
      if (mode == MISHOON) {
            // Mishoon's Heart (spinning rays from origin)
            delay = 50000;
            framesToSkip = 10;
            random = false;
            step = 180 * 2;
            clear = true;
      }
      
      sf::Font font("Arial.ttf");
      sf::Text text(font, "Happy New Year!");
      text.setCharacterSize(40);
      text.setStyle(sf::Text::Bold);
      text.setFillColor(sf::Color::Yellow);
      sf::FloatRect textRect = text.getLocalBounds();
      text.setOrigin({textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f});
      text.setPosition({HSIZE / 2, VSIZE / 8});
      
      struct timespec req;
      req.tv_sec = 0;
      req.tv_nsec = delay;

      
      Tree Ltree = Tree({HSIZE / 6 + 20, VSIZE / 4}, 4, 70, VSIZE / 2 + VSIZE / 5);
      Tree Rtree = Tree({HSIZE - HSIZE / 6 - 20, VSIZE / 4}, 4, 70, VSIZE / 2 + VSIZE / 5);
      SpinHeart heart = SpinHeart();
      if (!random) {
            heart.step = step;
      }
      
      Button butt = Button({HSIZE / 2, VSIZE / 2}, buttonClicked, "Click me!");
      
      int cnt = 0;
      while (window->isOpen()) {
            srand((int)time(NULL));
            nanosleep(&req, NULL);
            cnt++;
            if (butt.linkedVar) {
                  sf::Vector2f point = heart.getPointOnShape(random);
                  heart.addPoint(point);
            }
            // fflush(stdout);
            // printf("t = %lf \n", heart.mem);
            while (const std::optional event = window->pollEvent()) {
                  if (event->is<sf::Event::Closed>())
                        window->close();
                  if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                              window->close();
                  }
                  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                        sf::Vector2i posi =  sf::Mouse::getPosition(*window);
                        sf::Vector2f pos = {static_cast<float>(posi.x), static_cast<float>(posi.y)};
                        printf("Click pos: (%.2lf, %.2lf) \n", pos.x, pos.y);
                        // bool press = butt.checkPress(pos);
                        // printf("%d \n", press);
                        if (butt.checkPress(pos)) {
                              printf("Pressed: %d ->", butt.linkedVar);
                              butt.linkedVar = true;
                              Rtree.lightsOn = true;
                              Ltree.lightsOn = true;
                              printf("%d \n", butt.linkedVar);
                        }
                  }
            }
            if (cnt %framesToSkip == 0) {
                  if (clear) {
                        window->clear();
                  }
                  // heart.draw(window);
                  window->draw(text);
                  if (butt.linkedVar)
                        heart.draw(window);
                  else
                        butt.draw(window);
                  Rtree.draw(window);
                  Ltree.draw(window);
                  window->display();
                  cnt = 0;
            }
            
            
      }
}



int main(void) {
      sf::RenderWindow window(sf::VideoMode({HSIZE, VSIZE}), "SortTiles");
      window.setVerticalSyncEnabled(false);
      
      DisplayWindow(&window);
      
      return 0;
}

