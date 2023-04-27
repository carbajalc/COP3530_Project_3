#pragma once
#include <iostream>
#include <string>

class videoGame {
public:
  std::string title;
  std::string genre;
  std::string console;
  double critic_score;    // how well the game was liked
  std::string esrb_rating; // the content rating

  // functions
  void printVideoGame();
  std::string getTitle();
  std::string getGenre();
  std::string getConsole();
  double getCriticScore();
  std::string getESRBrating();

  // constructor
  videoGame(std::string t, std::string g, std::string c, double r, std::string ra) {
    title = t;
    genre = g;
    console = c;
    critic_score = r;
    esrb_rating = ra;
  }
};
