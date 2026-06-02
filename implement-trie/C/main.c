/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.
Implement the Trie class:
Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1
Input: 
    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEnd;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }

    node->isEnd = false;

    return node;
}

Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* current = obj->root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }

        current = current->children[index];
    }

    current->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* current = obj->root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            return false;
        }

        current = current->children[index];
    }

    return current->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* current = obj->root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (current->children[index] == NULL) {
            return false;
        }

        current = current->children[index];
    }

    return true;
}

void freeNode(TrieNode* node) {
    if (node == NULL)
        return;

    for (int i = 0; i < 26; i++) {
        freeNode(node->children[i]);
    }

    free(node);
}

void trieFree(Trie* obj) {
    freeNode(obj->root);
    free(obj);
}