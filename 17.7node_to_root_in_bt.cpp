#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include<vector>
using namespace std;
//examine this code properly it has how to append data in array dynamicaly.
class BinaryTree
{
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
BinaryTree *takeInput()
{
    int rootData;
    printf("Enter root data\n");
    scanf("%d", &rootData);
    BinaryTree *root = new BinaryTree(rootData);

    queue<BinaryTree *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTree *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        printf("Enter left child data of %d \n", front->data);
        scanf("%d", &leftChildData);
        if (leftChildData != 0)
        {
            BinaryTree *leftChild = new BinaryTree(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightChildData;
        printf("Enter right child Data of %d\n", front->data);
        scanf("%d", &rightChildData);
        if (rightChildData != 0)
        {
            BinaryTree *rightChild = new BinaryTree(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}
void PrintTree(BinaryTree *r)
{
    if (r == NULL)
    {
        return; // void
    }
    printf("%d: ", r->data);
    if (r->left != NULL)
    {
        printf("L:%d ", r->left->data);
    }
    if (r->right != NULL)
    {
        printf("R:%d ", r->right->data);
    }
    printf("\n");
    PrintTree(r->left);
    PrintTree(r->right);
}
//understand this properly.
//with flow example .
vector<int>* getRootNodePath(BinaryTree *r, int n){
if (r==NULL)
{
    return NULL;
}
if (r->data==n)
{
    vector<int>* output=new vector<int>();
    output->push_back(r->data);
    return output;
}
vector<int>* leftOutput=getRootNodePath(r->left,n);
if (leftOutput!=NULL)
{
    leftOutput->push_back(r->data);
    return leftOutput;
}
vector<int>* rightOutput=getRootNodePath(r->right,n);
if (rightOutput!=NULL)
{
    rightOutput->push_back(r->data);
    return rightOutput;
}
else{
    return NULL;
}
/*
explanation->
     1
   2   3
-->exit conditions known
-->let r1=n
-->then move to left nod and if it is not null
-->we assume we get by calling recursion that matches it with r as left 
and then mush back
-->similary for right and if if of right isn't true then it is no where in the tree






*/






}
int main(){
    BinaryTree *root=takeInput();
    printf("You entered\n");
    PrintTree(root);
    printf("\n");
    vector<int>* output=getRootNodePath(root,7);
    for (int i = 0; i < output->size(); i++)
    {
        printf("%d->",output->at(i));
    }
    delete output;
    
    return 0;
}