//
//  Shapes.cpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 10.12.2025.
//

#include "Shapes.hpp"

Shape::Shape(double t, float step) {
      this->t = t;
      this->step = step;
}

void Shape::addPoint(sf::Vector2f vec) {
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

void Shape::draw(sf::RenderWindow *window) {
      for (sf::VertexArray seg : segments) {
            window->draw(seg);
      }
}
