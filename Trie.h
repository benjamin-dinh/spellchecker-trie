//
// Created by Benjamin Dinh on 2020-02-26.
//

#ifndef P4_TRIE_H
#define P4_TRIE_H

#include "CheckerRunner.h"


class Trie{
 public:
  Trie* child[26];
  bool endOfWord;
  char letter;
  Trie();
  void insert(Trie* trie, const char* word);
  void insert2(Trie* trie, const char* word, int depth);
  bool isBottom(Trie* root);
  void print(Trie* root, char* word, int level);
  void printWord();
};



#endif //P4_TRIE_H
