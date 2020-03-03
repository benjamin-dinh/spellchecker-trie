// Author: Sean Davis

#include "CheckerRunner.h"
#include "checker.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

Checker::Checker(const DictionaryWord *words, int numWords) 
{
  trie = new Trie();
  for (int i = 0; i < numWords; i++){
    trie->insert(trie,words[i].word);
  }
//  int level = 0;
//  char word[37];
//  trie->print(trie, word, 0);
} // Checker()



void Checker::findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1], int *count){
  char tempWord[37] = "";
  Trie* current = trie;
  *count = 0;
  for (int i = 0; (current->child[word[i]-'a']) ; i++){
    tempWord[i] = current->child[word[i]-'a']->letter;
    current = current->child[word[i]-'a'];
    if (current->endOfWord && word[i+1] == '\0') {
      strcpy(matchingWords[*count], tempWord);
      ++*count;
      return;
      }
    }

  findClose(word, matchingWords, count, trie, 0, 0, tempWord);
}


void Checker::findClose(const char *word, char matchingWords[100][MAX_LENGTH + 1], int *count,
    Trie* trie, int depth, int error, char* tempWord){
  if (error > 1) {
    return;
  }
  if (trie->endOfWord && word[depth] == '\0') {
      strcpy(matchingWords[*count], tempWord);
      ++*count;
      return;
  }
  if (error == 1){
    if (trie->child[word[depth]-'a']){
      tempWord[depth] = trie->child[word[depth]-'a']->letter;
      findClose(word,matchingWords,count,trie->child[word[depth]-'a'],depth+1,error,tempWord);
    }
    else {
      return;
    }
  }
  else {
    for (int i = 0; i<26 && word[depth]!= '\0' ; i++){
      if (trie->child[i]){
        if (trie->child[i]->letter == word[depth]){ // keep error as 0 if exact match
          tempWord[depth] = trie->child[i]->letter;
          findClose(word,matchingWords,count,trie->child[i],depth+1,error,tempWord);
        }
        else {
          tempWord[depth] = trie->child[i]->letter; // increment error if one mismatch
          findClose(word,matchingWords,count,trie->child[i],depth+1,error+1,tempWord);
        }
      }
    }
  }
}