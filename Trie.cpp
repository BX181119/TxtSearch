//
// Created by Rcforest on 2022/5/29.
//


#include "Trie.h"

TrieNode::TrieNode() {
  for (auto & i : children) {
    i = nullptr;
  }
  count = 0;
}

int Trie::find(const string &key) {
  TrieNode *p = head;
  for (auto c:key) {
    int index;
    if ('A' < c && c < 'Z')  index = c - 'A' + 26;
    else if ('a' < c && 'z' > c) index = c - 'a';
    else continue;
    if (!p->children[index]) return 0;
    p = p->children[index];
  }
  return p->count;
}
void Trie::insert(const string &key) {
  TrieNode *p = head;
  for (auto c:key) {
    int index;
    if ('A' < c && c < 'Z')  index = c - 'A' + 26;
    else if ('a' < c && 'z' > c) index = c - 'a';
    else continue;
    if (!p->children[index]) p->children[index] = new TrieNode();
    p = p->children[index];
  }
  p->count += 1;
}
Trie::Trie() {
  head = new TrieNode;
}
