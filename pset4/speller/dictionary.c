// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// dictionary size
int words = 0;

typedef struct node *nodeptr;
nodeptr hashtable[N];

void insert(nodeptr node, int index)
{
    // check if the array location is null
    if (!(hashtable[index]))
    {
        hashtable[index] = node;
    }
    else
    {
        // there is a node already at that location
        // assign our node as the head of the new linked list
        // we need to store the ptr to the old node in a temp variable
        nodeptr temp = hashtable[index];

        // now we can assign the new node to the head of the list
        hashtable[index] = node;

        // and attach the old head node to the new head's next property
        node->next = temp;
    }

}

void freelist(nodeptr headptr)
{
    while (headptr != NULL)
    {
        // create temp variable to save the memory location of the head pointer
        nodeptr temp = headptr;

        // set the head node equal to it's next property making it the next node
        headptr = headptr->next;

        // free the temp variable which deletes the original head node
        free(temp);
    }

}

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // create a FILE pointer and fopen() to start the stream
    FILE *dictionary_stream = fopen(dictionary, "r");

    // get each line
    // create a node
    // save to node->text
    // insert into hashtable
    char temp[LENGTH + 1] = {'\0'};

    // the condition in this while loop is also storing
    // the string as well so...a slick way of doing
    // two jobs in one place!
    while (fscanf(dictionary_stream, "%s", temp) == 1)
    {
        // make space for a node
        nodeptr d_node_ptr = malloc(sizeof(struct node));

        // set node's next property to null
        d_node_ptr->next = NULL;

        // save the current word in the node's char property
        strcpy(d_node_ptr->word, temp);

        // generate a hash
        int ht_index = hash(d_node_ptr->word);

        // insert node into hashtable
        insert(d_node_ptr, ht_index);

        words++;
    }

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    int len = strlen(word);
    char *lowerword = malloc(sizeof(word) * (len + 1));
    lowerword[len + 1] = '\0';

    // change all letters to lowercase
    for (int i = 0; i < len; i++)
    {
        lowerword[i] = tolower(word[i]);
    }

    // generate the int hash
    int index = hash(lowerword);

    // traverse the linked list at the array index
    nodeptr trav = hashtable[index];

    // loop through while node->next is not null
    while (trav != NULL)
    {
        if (strcmp(trav->word, lowerword) == 0)
        {
            return true;
        }

        trav = trav->next;
    }

    // if we get to this point the word was not found
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        freelist(hashtable[i]);
    }

    return true;
}
