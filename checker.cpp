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
  *count = 0;
  findCloseMatch(word, matchingWords, count, this->trie, 0, 0, tempWord);
  cout << matchingWords[0] << endl;
}


void Checker::findCloseMatch(const char *word, char matchingWords[100][MAX_LENGTH + 1], int *count,
    Trie* trie, int depth, int error, char* tempWord){
  if (error > 1) {
    return;
  }
  if (*count > 1 && strcmp(tempWord,word)==0) {
    *count = 1;
    strcpy(matchingWords[0],tempWord);
    return;
  }
  if (trie->endOfWord && word[depth] == '\0') {
    strcpy(matchingWords[*count],tempWord);
    ++*count;
//    cout << tempWord << endl;
//    cout << *count<< endl;
    return;
  }
  if (error == 1){
    if (trie->child[word[depth]-'a']){
      tempWord[depth] = trie->child[word[depth]-'a']->letter;
      findCloseMatch(word,matchingWords,count,trie->child[word[depth]-'a'],depth+1,error,tempWord);
    }
    else {
      return;
    }
  }
  else {
    for (int i = 0; i<26 && word[depth]!= '\0' ; i++){
      if (trie->child[i]){
        if (trie->child[i]->letter == word[depth]){
          tempWord[depth] = trie->child[i]->letter;
          findCloseMatch(word,matchingWords,count,trie->child[i],depth+1,error,tempWord);
        }
        else {
          tempWord[depth] = trie->child[i]->letter;
          findCloseMatch(word,matchingWords,count,trie->child[i],depth+1,error+1,tempWord);
        }
      }
    }
  }
}