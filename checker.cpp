// Author: Sean Davis

#include "CheckerRunner.h"
#include "checker.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

Checker::Checker(const DictionaryWord *words, int numWords) 
{
  trie = new Trie;
  for (int i = 0; i<numWords; i++) {
    trie->insert(words[i].word, trie->root, 0);
  }
} // Checker()



void Checker::findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1],
  int *count)
{
}


