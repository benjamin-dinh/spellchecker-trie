//
// Created by Benjamin Dinh on 2020-02-26.
//

#include "Trie.h"
#include <cstring>
#include <iostream>
#include <fstream>


Trie::Trie() {
  root = new TrieNode[26];
}

void Trie::insert(const char* word, TrieNode* t, int depth){
  if (word[depth] == '\0') {
    return;
  }
  else if (t->children[depth]->letter != '\0' && word[depth] == t->children[word[depth]-'a']->letter) {
    depth++;
    insert(word,t->children[word[depth]-'a'],depth);
  }
  else {
    TrieNode* newNode = new TrieNode[26];
    newNode->letter = word[depth];
    t->children[word[depth]-'a'] = newNode;
    depth++;
    insert(word, newNode, depth);
  }
}