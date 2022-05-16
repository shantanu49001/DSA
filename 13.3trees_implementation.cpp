// node class
// har nod k pass apne child ka address lete hai
// root ka address hum samajke rakh lenge
// array to store child->size issue
// ll to store child->traversing issue
// vector stores address of the child nodes for a parent node
#include <bits\stdc++.h>
#include <vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
   T data;
   vector<TreeNode<T> *> children; //--->nodes of tress node formed
                                   // array of pointer nodes                              //--->having address of parent
   TreeNode(T data)
   { // pointer node me initialosation
      this->data = data;
   }
};
int main()
{
   TreeNode<int> *root = new TreeNode<int>(1);
   TreeNode<int> *node1 = new TreeNode<int>(2);
   TreeNode<int> *node2 = new TreeNode<int>(3);
   // we have just made 3 nodes of tree node class
   // each of these will have khud ka data and array of pointers pointing to node of thier own same class
   root->children.push_back(node1);
   root->children.push_back(node2); // connection made with children nodes
   // root ke array of pimter me ye dono nodes ka address push back kardo
   return 0;
}