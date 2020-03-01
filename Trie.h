//
// Created by Benjamin Dinh on 2020-02-26.
//

#ifndef P4_TRIE_H
#define P4_TRIE_H

#include "CheckerRunner.h"

class Trie;
class TrieNode{
 public:
  TrieNode* children[26];
  char letter;
  char* word[37];
  int depth;
  TrieNode();
 private:
  friend class Trie;
};

class Trie{
 public:
  TrieNode** root[26];
  Trie();
  void insert(const char* word);
  void insert(TrieNode* currentNode, int depth);
};



#endif //P4_TRIE_H
