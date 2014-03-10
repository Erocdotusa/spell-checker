/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <ctype.h>
#include "dictionary.h"




 
trieNode* rootNode;
int wordCount;

/**
 * Returns true if word is in dictionary else false.
 */
  
bool check(const char* word)
{
    if (trieWordIsFound(word, rootNode))
        
    {
        
    	return true;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    if (!rootNode)
    {
        rootNode = trieNodeCreate();
        if (!rootNode)
        {
            printf("could not allocate root node");
            return false;
        }
    }
    
    // Open the file 
    FILE* fp = fopen(dictionary, "r");
    
    if (fp == NULL)
    {
        printf("could not open dictioanry %s\n", dictionary);
        return false;
    }
    
    char word[LENGTH];
    int index = 0;
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {

        if (c != '\n' )
        {
            word[index] = c;
            index++;
        }
        else
        {
            word[index] = '\0';
        	trieWordInsert(word, rootNode);
        	index = 0;
        	wordCount ++;
            
        } 
    
    }
    fclose(fp);
    
    if (wordCount)
    {
    	return true;
    }
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (wordCount)
    {
    	return (wordCount);
    }
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    
    trieRemoveNode(rootNode);
    if (rootNode)
    {
    	return true;
    }
    return false;
}
