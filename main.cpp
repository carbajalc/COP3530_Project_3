#include "VideoGameReccomendations.h"
#include "videoGame.h"
#include <iostream>
#include <vector>

int main() {

  VideoGameReccomendations v;

  std::string age, console, genre;

  // ESRB rating (E for everyone, M for mature, etc)
  std::cout << "How old are you?" << std::endl;
  std::cin >> age;
  std::cout << std::endl;
  int newAge = stoi(age);

  // consoles
  // are we going to allow them to play on more than one console?
  std::cout << "What console would you like to play on? (Type a number 1-11)"
            << std::endl;
  std::cout << "1. PlayStation 1" << std::endl;
  std::cout << "2. PlayStation 2" << std::endl;
  std::cout << "3. PlayStation 3" << std::endl;
  std::cout << "4. PlayStation 4" << std::endl;
  std::cout << "5. XBox 360" << std::endl;
  std::cout << "6. XBox One" << std::endl;
  std::cout << "7. Sony PSP" << std::endl;
  std::cout << "8. Nintendo DS" << std::endl;
  std::cout << "9. Nintendo 3DS" << std::endl;
  std::cout << "10. Wii" << std::endl;
  std::cout << "11. WiiU" << std::endl;
  std::cin >> console;
  std::cout << std::endl;

  // converting number to console
  int c = stoi(console);
  switch (c) {
  case 1:
    console = "PS";
    break;
  case 2:
    console = "PS2";
    break;
  case 3:
    console = "PS3";
    break;
  case 4:
    console = "PS4";
    break;
  case 5:
    console = "X360";
    break;
  case 6:
    console = "XOne";
    break;
  case 7:
    console = "PSP";
    break;
  case 8:
    console = "DS";
    break;
  case 9:
    console = "3DS";
    break;
  case 10:
    console = "Wii";
    break;
  case 11:
    console = "WiiU";
    break;
  }
  // genre
  std::cout << "What genre would you like to play? (Type a number 1-9)"
            << std::endl;
  std::cout << "1. Sports" << std::endl;
  std::cout << "2. Racing" << std::endl;
  std::cout << "3. Role-Playing" << std::endl;
  std::cout << "4. Platform" << std::endl;
  std::cout << "5. Simulation" << std::endl;
  std::cout << "6. Party" << std::endl;
  std::cout << "7. Action" << std::endl;
  std::cout << "8. Puzzle" << std::endl;
  std::cout << "9. Misc" << std::endl;
  std::cin >> genre;
  std::cout << std::endl;

  // converting number to genre
  int g = stoi(genre);
  switch (g) {
  case 1:
    genre = "Sports";
    break;
  case 2:
    genre = "Racing";
    break;
  case 3:
    genre = "Role-Playing";
    break;
  case 4:
    genre = "Platform";
    break;
  case 5:
    genre = "Simulation";
    break;
  case 6:
    genre = "Party";
    break;
  case 7:
    genre = "Action";
    break;
  case 8:
    genre = "Puzzle";
    break;
  case 9:
    genre = "Misc";
    break;
  }

  // making new vector with parameters taken into account
  std::vector<videoGame> newGames;
  for (int i = 0; i < v.vg.size(); i++) {
    if (v.vg.at(i).getConsole() == console && v.vg.at(i).getGenre() == genre) {
      if (stoi(age) < 13 && v.vg.at(i).getESRBrating() == "E") {
        newGames.push_back(v.vg.at(i));
      } else if (stoi(age) >= 13) {
        newGames.push_back(v.vg.at(i));
      }
    }
  }

  // sorting and printing the games
  std::string num;
  // randomizing quick and shell sort
  std::cout << "Pick any number you want" << std::endl;
  std::cin >> num;
  std::cout << std::endl;

  std::cout << "You should play these games!" << std::endl;
   // shell sort
  if (stoi(num) % 2 == 0) {
    int n = newGames.size();
    v.shellSort(newGames, n);
    v.printVideoGames(newGames);
  } else {
    // quick sort
    int n = newGames.size();
    v.quickSort(newGames, 0, n - 1);
    v.printQuickSort(newGames);
  }
}