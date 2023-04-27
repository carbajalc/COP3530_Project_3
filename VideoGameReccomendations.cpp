#include "VideoGameReccomendations.h"

VideoGameReccomendations::VideoGameReccomendations() {
  std::string path = "vg.csv";
  std::ifstream stream;
  stream.open(path);

  if (stream.is_open()) {
    std::string header;
    getline(stream, header, '\n');

    while (stream.peek() != EOF) {
      std::string title, genre, console, critic_score, esrb_rating;
      getline(stream, title, ',');
      getline(stream, genre, ',');
      getline(stream, esrb_rating, ',');
      getline(stream, console, ',');
      getline(stream, critic_score);

      vg.push_back(
          videoGame(title, genre, console, stod(critic_score), esrb_rating));
    }
  }
}

void VideoGameReccomendations::shellSort(std::vector<videoGame> &v, int n) {
  int gap = n / 2;
  while (gap > 0) {
    if (gap == 2) {
      gap = 1;
    } else {
      gap /= 2;
    }
    for (int i = gap; i < n; i++) {
      videoGame temp = v[i];
      int j;
      for (j = i;
           j >= gap && v[j - gap].getCriticScore() < temp.getCriticScore();
           j -= gap) {
        v[j] = v[j - gap];
      }
      v[j] = temp;
    }
  }
}

void VideoGameReccomendations::printVideoGames(std::vector<videoGame> v) {
  for (int i = 0; i < 10; i++) {
    std::cout << i + 1 << ". " << v.at(i).getTitle() << std::endl;
  }
}

int VideoGameReccomendations::partition(std::vector<videoGame> &v, int low, int high){
    double pivot = v[low].getCriticScore(); //Basing pivot off position of first element
    int up = low, down = high; //up starts at beginning of v, down starts at end of v

    //Using sorting notes
    while(up < down){ //While up score is less than down score
        for(int j = up; j < high; j++){ //increase position of up until it finds a score more than pivot
            if(v[up].getCriticScore() > pivot)
                break;
            up++;
        }
        for(int j = high; j > low; j--){ //decrease position of down until it finds a score less than pivot
            if(v[down].getCriticScore() < pivot)
                break;
            down--;
        } //up is the position of first score more than pivot, vice versa for down
        if(up < down) //switch values, left of pivot is < pivot, vice versa right
            std::swap(v[up], v[down]);
    }
    std::swap(v[low], v[down]); //final swap
    return down;

}

void VideoGameReccomendations::quickSort(std::vector<videoGame> &v, int low, int high){
    //Using sorting notes
    if(low < high){ //low is first value, high is last value
        int pivot = partition(v, low, high); //get pivot value
        quickSort(v, low, pivot - 1); //sort everything after pivot
        quickSort(v, pivot + 1, high); //sort everything before pivot
    }
}

void VideoGameReccomendations::printQuickSort(std::vector<videoGame> v){
    int j = 1;
    for(int i = v.size() - 1; i >= v.size() - 10; i--){
        std::cout << j << ". " << v.at(i).getTitle() << std::endl;
        j++;
    }
}