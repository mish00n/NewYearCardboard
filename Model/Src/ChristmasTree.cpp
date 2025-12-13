//
//  ChristmasTree.cpp
//  SFMLHeart
//
//  Created by Michael Lebedev on 10.12.2025.
//

#include "ChristmasTree.hpp"
#include "Shapes.hpp"




Tree::Tree(sf::Vector2f origin, int numOfLayers, int widthStep, int height) {
      this->height = height;
      this->numOfLayers = numOfLayers;
      this->widthStep = widthStep;
      this->origin = origin;
      
      sf::VertexArray tree(sf::PrimitiveType::LineStrip, numOfLayers * 4 - 1);
      this->treeOutline = tree;
      
      this->buildTreeFill();
      this->buildTreeOutline();
}

void Tree::buildTreeFill() {

      float dy = height / numOfLayers;
      float doy = 0;
      float dx = widthStep;

      for (int i = 0; i < numOfLayers; ++i) {
            sf::ConvexShape layer;
            layer.setPointCount(3);
            
            layer.setPoint(0, {origin.x, origin.y + doy});
            layer.setPoint(1, {origin.x - dx, origin.y + dy});
            layer.setPoint(2, {origin.x + dx, origin.y + dy});
            
            layer.setFillColor(sf::Color::Green);
            layers.push_back(layer);
            
            for (int j = 1; j < (i + 1) * 5 + 1; j++) {
                  sf::Vector2f pos = (layer.getPoint(0) - layer.getPoint(1) + layer.getPoint(2) - layer.getPoint(1));
                  pos = {static_cast<float>(pos.x / 2 / (i * 5 + 5) * j), static_cast<float>(pos.y / 2 / (i * 5 + 5) * j)};
                  
                  pos += layer.getPoint(1);
                  Light bulb = Light(pos);
                  bulb.colorNum = j % 6;
                  lights.push_back(bulb);
            }
            
            dx += widthStep;
            dy += height / numOfLayers;
            doy += height / numOfLayers / 1.5;
      }
}

void Tree::buildTreeOutline() {
      treeOutline[0].position = origin;
      treeOutline[0].color = sf::Color::Green;
      
      int dx = widthStep, dy = height / numOfLayers;
      int i = 1;
      for (i = 1; i < (numOfLayers - 1) * 2; i += 2) {
            treeOutline[i].position = {origin.x + dx, origin.y + dy};
            treeOutline[treeOutline.getVertexCount() - i].position = {origin.x - dx, origin.y + dy};
            treeOutline[i + 1].position = {origin.x + dx / 2, origin.y + dy};
            treeOutline[treeOutline.getVertexCount() - i - 1].position = {origin.x - dx / 2, origin.y + dy};
            
            treeOutline[i].color = sf::Color::Green;
            treeOutline[i + 1].color = sf::Color::Green;
            treeOutline[treeOutline.getVertexCount() - i].color = sf::Color::Green;
            treeOutline[treeOutline.getVertexCount() - i - 1].color = sf::Color::Green;
            
            // dx /= 2;
            dx += widthStep;
            dy += height / numOfLayers;
            
      }
      treeOutline[i].position = {origin.x + dx, origin.y + dy};
      treeOutline[treeOutline.getVertexCount() - i].position = {origin.x - dx, origin.y + dy};
      
      treeOutline[i].color = sf::Color::Green;
      treeOutline[treeOutline.getVertexCount() - i].color = sf::Color::Green;
      
      treeOutline.append(treeOutline[0]);
}

void Tree::draw(sf::RenderWindow *window) {
      for (sf::ConvexShape layer: layers)
            window->draw(layer);
      if (lightsOn)
            for (Light &bulb : lights)
                  bulb.draw(window);
       window->draw(treeOutline);
}

Light::Light(sf::Vector2f pos) {
      this->pos = pos;
}

void Light::draw(sf::RenderWindow *window) {
      // printf("pos = (%.2lf, %.2lf) \n", pos.x, pos.y);
      
      // printf("cnt = %d", cnt);
      if (cnt % 100 == 0) {
            printf("Changing Color... \n");
            colorNum = (colorNum + 1) % 6;
            cnt = 0;
      }
      cnt++;
      switch (colorNum) {
            case 0:
                  color = sf::Color::White;
                  break;
            case 1:
                  color = sf::Color::Blue;
                  break;
            case 2:
                  color = sf::Color::Red;
                  break;
            case 3:
                  color = sf::Color::Yellow;
                  break;
            case 4:
                  color = sf::Color::White;
                  break;
            case 5:
                  color = sf::Color::Blue;
                  break;
            default:
                  break;
      }
      sf::CircleShape circle;
      circle.setRadius(radius);
      circle.setFillColor(color);
      circle.setPosition(pos);
      
      window->draw(circle);
}
