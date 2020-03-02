//
// Created by Benjamin Dinh on 2020-02-26.
//

#include "Trie.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

Trie::Trie()
{
//  Trie *newNode = new Trie();
  this->endOfWord = false;
  for(int i=0 ; i<26 ; i++)
  {
    //Initially , initialize null to the all child
    this->child[i] = NULL;
  }
//  return newNode;
}

void Trie::insert(Trie* trie, const char* word)
{
  insert2(trie, word, 0);
}

void Trie::insert2(Trie* trie, const char* word, int depth)
{
  if(word[depth] != '\0')
  {
    int pos = word[depth] - 'a';
    if(trie->child[pos] == NULL )
    {
      trie->child[pos] = new Trie();
    }
    insert2(trie->child[pos], word, depth+1);
  }
  else // end of string
  {
    trie->endOfWord = true;
  }
}

bool Trie::isBottom(Trie* root)
{
  return root->endOfWord != false;
}


void Trie::displayContent(Trie* root, char* word, int level)
{

  if (isBottom(root))
  {
    word[level] = '\0';
    cout << word << endl;
  }

  for (int i = 0; i < 26; i++)
  {
    if (root->child[i])
    {
      word[level] = i + 'a';
      displayContent(root->child[i], word, level + 1);
    }
  }
}

