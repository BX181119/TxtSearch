//
// Created by Rcforest on 2022/5/29.
//
#include <string>
using std::string;
#ifndef TXTSEARCH__TRIE_H_
#define TXTSEARCH__TRIE_H_

class TrieNode {
 public:
  TrieNode *children[52];
  int count;
  TrieNode();

};

class Trie {
 private:
  TrieNode *head;
 public:
  Trie();
  void insert(const string &key);
  int find(const string &key);
};

#endif //TXTSEARCH__TRIE_H_
