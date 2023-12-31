// Generated by dia2code
#ifndef RENDER__MAPDRAW__H
#define RENDER__MAPDRAW__H

#include <vector>
#include <SFML/Graphics.hpp>

namespace render {

  /// class MapDraw - 
  class MapDraw {
    // Attributes
  public:
    sf::Font font;
    std::vector<sf::CircleShape> map;
    sf::Texture background;
    std::vector<sf::CircleShape> mapRemaining;
    sf::CircleShape tiles;
    std::vector<std::vector<sf::Vector2f>> mapPixelPosition;
    std::vector<std::vector<sf::Vector2f>> mapPixelRemainingPosition;
    // Operations
  public:
    MapDraw ();
    void setTilesShape ();
    void generateMapPixel ();
    void generateMapPixelRemaining ();
    int setBackground ();
    void initMapDraw (sf::RenderWindow& window);
    std::vector<int> getPressedTiles (int posx, int posy);
    // Setters and Getters
  };

};

#endif
