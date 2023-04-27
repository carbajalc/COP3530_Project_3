#pragma once

#include "videoGame.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class VideoGameReccomendations {
public:
  std::vector<videoGame> vg;
  VideoGameReccomendations();
  void shellSort(std::vector<videoGame>& v, int n);
  void printVideoGames(std::vector<videoGame> v);
  void quickSort(std::vector<videoGame> &v, int low, int high);
  int partition(std::vector<videoGame> &v, int low, int high);
  void printQuickSort(std::vector<videoGame> v);
};
