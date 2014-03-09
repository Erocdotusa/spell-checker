//
//  trie.h
//  trie
//
//  Created by Joe Million on 3/6/14.
//  Copyright (c) 2014 iMillIndustries. All rights reserved.
//

#ifndef trie_trie_h
#define trie_trie_h
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

//typedef uint8_t  SHORT_INT;



typedef struct trieNode
{
    bool isWord;
    struct trieNode* children[27];
} trieNode;

// Creates a new node
trieNode* trieNodeCreate();

// removes a node
void trieRemoveNode(trieNode* node);

// checks to see if a word is present in the root node, returns true if yes, else false
bool trieWordIsFound(const char* word, const trieNode* root) ;

// inserts word into trie
void trieWordInsert(const char* word, trieNode* root);

// return int for mapping to child array
int trieIndexForChar(char input);

#endif
