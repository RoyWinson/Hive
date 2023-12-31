// Generated by dia2code
#ifndef RENDER__TEXTDRAW__H
#define RENDER__TEXTDRAW__H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

namespace state {
  class Player;
  class Game;
}

#include "state/Game.hpp"

namespace render {

  /// class TextDraw - 
  class TextDraw {
    // Attributes
  public:
    sf::Font font;
    sf::Text nbtour;
    sf::Text playerName;
    std::string p1;
    std::string p2;
    std::string state;
    sf::Text stateText;
  private:
    std::vector<state::Player*> listPlayer;
    // Operations
  public:
    TextDraw ();
    void drawText (sf::RenderWindow& window, state::Game state);
    void getPlayerName (state::Game state);
    TextDraw (state::Game state);
    std::string getStateString (state::Game state);
    // Setters and Getters
  };

};

#endif
