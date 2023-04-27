#pragma once
#include "videoGame.h"
#include <iostream>
#include <string>

void videoGame::printVideoGame() {
  std::cout << " " << title << " " << esrb_rating << " " << std::endl;
}

std::string videoGame::getTitle(){
  return title;
}

std::string videoGame::getGenre(){
  return genre;
}

std::string videoGame::getConsole(){
  return console;
}

double videoGame::getCriticScore(){
  return critic_score;
}

std::string videoGame::getESRBrating(){
  return esrb_rating;
}