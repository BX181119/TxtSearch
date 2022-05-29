

#ifndef TXTSEARCH__TXTSEARCH_H_
#define TXTSEARCH__TXTSEARCH_H_
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include <algorithm>
#include <map>
using namespace std;

vector<string> split_str(const string &delimeter, string line);
vector<string> word_split(const string &filename);
map<string, int> word_to_map(const vector<string> &vector);
void quick_sort_triple_partition(vector<string> &a, int low, int high);
void quick_sort(vector<string>(&a), int low, int high);
int binary_search(const vector<string> &a, const string &key);
int count_words(const vector<string> &a, const string &key);
int count_map(map<string, int> &a, const string &key);
void search_word(int solution, vector<string>& words, vector<string> words_to_search);
#endif //TXTSEARCH__TXTSEARCH_H_
