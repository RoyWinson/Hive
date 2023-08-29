// Generated by dia2code
#ifndef RENDER__INSECTDRAW__H
#define RENDER__INSECTDRAW__H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

namespace state {
  class Game;
}

#include "state/Game.hpp"

namespace render {

  /// class InsectDraw - 
  class InsectDraw {
    // Attributes
  public:
    std::vector<std::vector<sf::Vector2f>> mapPixelRemainingPosition;
    std::vector<std::vector<sf::Vector2f>> mapPixelPosition;
    sf::Texture bee_w;
    sf::Texture bee_b;
    sf::Texture grasshopper_b;
    sf::Texture ant_b;
    sf::Texture ant_w;
    sf::Texture beetle_b;
    sf::Texture beetle_w;
    sf::Texture grasshopper_w;
    sf::Texture ladybug_b;
    sf::Texture ladybug_w;
    sf::Texture mosquito_b;
    sf::Texture moskito_w;
    sf::Texture spider_b;
    sf::Texture spider_w;
  private:
    std::map<std::string,sf::CircleShape> insectHex;
    // Operations
  public:
    void drawInsect (sf::RenderWindow& window, state::Game state);
    InsectDraw (std::vector<std::vector<sf::Vector2f>> mapPixel, std::vector<std::vector<sf::Vector2f>> mapPixelRemaining);
    InsectDraw ();
    void loadInsectTexture ();
    std::string getPressedInsect (int xt, int yt, state::Game state);
    // Setters and Getters
  };

};

#endif
