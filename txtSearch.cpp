
#include <algorithm>
#include "txtSearch.h"

vector<string> word_split(const string &filename) {
  fstream fs;
  fs.open(filename);
  vector<string> WordVector;
  char buf[1024] = {0};
  string line, word;
  while (fs.getline(buf, 1024)) {
    size_t pos;
    line = buf;
    auto it = std::remove_if(line.begin(), line.end(), [](char const &c) {
      return !std::isblank(c) && (std::ispunct(c) || (!std::isalpha(c) && !std::isdigit(c)));
    });
    line.erase(it, line.end());
    pos = line.find_first_of(" \t");
    while (pos != string::npos) {
      word = line.substr(0, pos);
      WordVector.push_back(word);
      line.erase(0, pos + 1);
      pos = line.find_first_of(" \t");
    }
  }
  fs.close();
  return WordVector;
}