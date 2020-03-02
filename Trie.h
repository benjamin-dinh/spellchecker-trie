//
// Created by Benjamin Dinh on 2020-02-26.
//

#ifndef P4_TRIE_H
#define P4_TRIE_H

#include "CheckerRunner.h"


class Trie{
 public:
  Trie* child[26];
  // endOfWord is true if the node represents
  // end of a word
  bool endOfWord;
  Trie();
  void insert(Trie* trie, const char* word);
  void insert2(Trie* trie, const char* word, int depth);
  bool isBottom(Trie* root);
  void displayContent(Trie* root, char* word, int level);
};



#endif //P4_TRIE_H
