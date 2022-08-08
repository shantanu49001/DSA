// we want to implement a dictionary
/*
1.addWord()
2.search()
3.RemoveWord()


if we use hashmap->
1.element-> key ,value(string,boolean)->insertion deletion,search all are O(1)/order of word length to get hashcode
2.search->hashcode figure out krna hip padga'O(word length)
3.remove->same


But let's ude another data structure



TRIES---------------------
1.looks like a tree
2.root=>start
3.the insert->strt ka ek child hona chahiye ->T T ka ek child H and H ka ek child E
  this                                                H ke baad new branch me H ka child I I ka S

words ke ending points ko mark
insertion->O(wl)
search(wl) aga start ko and ending word marked bhi ho
delete->sirf us word ka ending dlete to make sure other word isn't lost
      ->delete and free the terminal node
      ->(wl)




comparing a Hashmap and trie->trie me space optimisation
                            ->making functionality of suggestionn search
                            ->



implemeting the class Trie

node->char data
    ->har children ke address ko store at max 26 children->array me save of type trie
    ->int *a=new int[10]
    ->int **a=new int*[10]->pointer containg the pointer to integer values
    ->TrieNode **children=new TrieNode*[26]
    ->for marking a nde terminal make bool IsTerminal
    ->






*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class TrieNode
{
  // data members
public:
  char data;
  TrieNode **children;
  bool IsTerminal;
  TrieNode(char data)
  {
    this->data = data;
    children = new TrieNode *[26];
    for (int i = 0; i < 26; i++)
    {
      this->children[i] = NULL;
    }

    this->IsTerminal = false;
  }
  // member functions
};
class Trie
{
  TrieNode *root; // this must be private

public:
  Trie()
  {
    root = new TrieNode('\0'); // initally we don't want any data
    // dta ->null string
    // isTerminal by def false
    // children all are nnull
  }
  // for us
  void InsertWord(TrieNode *root, string word)
  { // here the user will not pass the root we wrill cretae a helper functio tp pass root each time
    // yes krne k liye are me and add

    // we can apply recursion here also
    // do work at root ony rest children will do
    // 1.search root word child pesence and we will ask toinsert
    // 2.if not present we will make and pass to children
    // 3.after ending the insert mark last child as terminal
    // har node apne pe next ltter ka child check karega agar hai to age move nhi hai to bana lo
    // and reaching '\0' mark that as terminal

    // base case
    if (word.size() == 0)
    {
      root->IsTerminal = true;
      return;
    }

    // check karenge if and ka a hai ya nhi
    int index = word[0] - 'a'; // a->0 b->1 c->2->ascii ke index pe jake put
    TrieNode *child;
    if (root->children[index] != NULL) // kuch hohga malb next wala hihiga
    {
      child = root->children[index];
    }
    else
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    InsertWord(child, word.substr(1)); // pehe index ko choke bacha hua string
  }

  // for user
  void InsertWord(string word)
  { // this is the he,pe rfution
    InsertWord(root, word);
  }

  bool Search(TrieNode *root, string word)
  {
    // har node check karega agla ketter child hai ya nhi
    /// root of tree me humega '\0 hi hai
    // jahan pr string ka length zero wahan pr cgeck us node pr data hai and terminal nod hai ya nhi gar hai to true
    // yahan pr node jo check karega usko acees karne k liye index pr jump karna oadega

    if (word.size() == 0)
    {
      if (root->IsTerminal = true) // jab previous ne next hild search krliya aur hum already last pe hai bas usko terminal check krna hai
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    // check karenge if and ka a hai ya nhi
    int index = word[0] - 'a'; // a->0 b->1 c->2->ascii ke index pe jake put
    TrieNode *child;
    if (root->children[index] != NULL) // kuch hohga malb next wala hihiga
    {
      child = root->children[index];
    }
    else
    {
      return false;
    }

    Search(child, word.substr(1)); // pehe index ko choke bacha hua string
  }

  // for user
  void Search(string word) // otp like function
  {                        // this is the he,pe rfution
    Search(root, word);
  }

  void Remove(TrieNode *root, string word)
  {
    if (word.size() == 0) // handles single or none lengt word
    {
      root->IsTerminal = false;
    }

    TrieNode *child;
    int index = word[0] - 'a'; // getting tht index
    if (root->children[index] != NULL)
    {
      // call recursion
      child = root->children[index];
    }
    else
    {
      // word not found
      return;
    }
    // we will be here id ]f wor present
    Remove(child, word.substr(1)); // top element haake string jo bacha
    // removing the nodes if they are useless
    if (child->IsTerminal == false)
    {
      // now e ot the node to delete
      // now oother condition hai k iske child me saare null
      for (int i = 0; i < 26; i++)
      {
        if (child->children[i] != NULL)
        {
          return;
        }
        delete child;
        root->children[index] = NULL;
      }
    }

    // ab let's say and remove d unterminal and n agar pehle se unterminal hai n,d usless nodes ho gyi
    //
  }
  void Remove(string word)
  {
    // and pass kara root a pe ayega bolega nd ko rmove
    // imilaly recursive call
    // reaching word.length()=0
    // mark that node non terminal
    Remove(root, word);
  }
};

int main()
{
  Trie T;
  T.InsertWord("and");
  T.InsertWord("are");
  T.InsertWord("dot");

  return 0;
}
