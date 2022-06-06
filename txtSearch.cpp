
#include <algorithm>
#include <random>
#include "txtSearch.h"

vector<string> word_to_vector(const string &filename) {
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
    for (auto &c : line) c = tolower(c);
    pos = line.find_first_of(" \t");
    while (pos != string::npos) {
      word = line.substr(0, pos);
      WordVector.push_back(word);
      line.erase(0, pos + 1);
      pos = line.find_first_of(" \t");
    }
    WordVector.push_back(line);
  }
  fs.close();
  return WordVector;
}
void quick_sort(vector<string> &a, int low, int high) {
  if (high < low + 100) insert_sort(a, low, high);
  string low_str = a[low];
  int i = low, j = high;
  while (i < j) {
    while (i < j && a[j] >= low_str) j--;
    if (i < j) a[i++] = a[j];
    while (i < j && a[i] <= low_str) i++;
    if (i < j) a[j--] = a[i];
  }
  a[i] = low_str;
  if (low < i - 1) quick_sort(a, low, i - 1);
  if (i + 1 < high) quick_sort(a, i + 1, high);
}
void insert_sort(vector<string> &vector, int low, int high) {
  for (int i = low + 1; i < high + 1; ++i) {
    string e = vector[i];
    int j;
    for (j = i - 1; j >= 0 && e < vector[j]; --j) {
      vector[j + 1] = vector[j];
    }
    vector[j + 1] = e;
  }
}
int binary_search(const vector<string> &a, const string &key) {
  int low = 0, high = a.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}
int count_words(const vector<string> &a, const string &key) {
  int pos = binary_search(a, key);
  if (pos == -1) return 0;
  int count = 1;
  int i = pos, j = pos;
  while (a[--i] == key) count++;
  while (a[++j] == key) count++;
  return count;
}
int count_map(unordered_map<string, int> &a, const string &key) {
  if (a.find(key) == a.end()) return 0;
  return a[key];
}
unordered_map<string, int> word_to_map(const vector<string> &vector) {
  unordered_map<string, int> words_pair;
  for (const auto &word : vector) {
    if (words_pair.find(word) == words_pair.end()) {
      words_pair.insert({word, 1});
    } else {
      words_pair[word] += 1;
    }
  }
  return words_pair;
}
vector<string> split_str(const string &delimeter, string line) {
  size_t pos;
  vector<string> splited;
  while ((pos = line.find(delimeter)) != string::npos) {
    splited.push_back(line.substr(0, pos));
    line.erase(0, pos + delimeter.length());
  }
  splited.push_back(line);
  return splited;
}
void search_word(int solution, vector<string>& words, vector<string> words_to_search) {
  if (solution == 1) {
    shuffle(words.begin(), words.end(), std::mt19937(std::random_device()()));
    quick_sort(words, 0, words.size() - 1);
    for (int i = 0; i < words_to_search.size(); i++) {
      cout << count_words(words, words_to_search[i]);
      if (i == words_to_search.size() - 1) cout << endl;
      else cout << "+";
    }
  } else if (solution == 2) {
    unordered_map<string, int> word_map = word_to_map(words);
    for (int i = 0; i < words_to_search.size(); i++) {
      cout << count_map(word_map, words_to_search[i]);
      if (i == words_to_search.size() - 1) cout << endl;
      else cout << "+";
    }
  } else {
    Trie trie = word_to_trie(words);
    for (int i = 0; i < words_to_search.size(); i++) {
      cout << trie.find(words_to_search[i]);
      if (i == words_to_search.size() - 1) cout << endl;
      else cout << "+";
    }
  }
}
Trie word_to_trie(const vector<string> &vector) {
  Trie trie;
  for (const auto &i : vector) {
    trie.insert(i);
  }
  return trie;
}

