//
// Created by Benjamin Dinh on 2020-02-26.
//

#include "Trie.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

Trie::Trie() {
  for (int i = 0; i < 26; i++) {
    root[i] = NULL;
  }
}

//TrieNode::TrieNode() {
//  this->letter = letter;
//  for (int i; i<26; i++){
//    this->children[i] = NULL;
//  }
//}

TrieNode::TrieNode() {
  letter = '\0';
  for (int i = 0; i < 26; i++) {
    children[i] = NULL;
  }
  for (int i = 0; i < 37; i++) {
    word[i] = NULL;
  }
  depth = 0;
}


void Trie::insert(const char* word) {
//  TrieNode* currentNode = root;
  if (root[word[depth]-'a'] == NULL){
      insert(root[word[root->depth]-'a'],root->depth);
  }
  else {
    insert(root[word[depth]-'a'],depth);
  }
}

void Trie::insert(TrieNode* currentNode, int depth) {
  currentNode->children[0];
 return;
}