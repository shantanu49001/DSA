//1.root ->null 
//2.if root ka data ==element 
//3.left right
#include <bits\stdc++.h>
#include <math.h>
#include <queue>
//#include <limits.h> //for infinty
using namespace std;
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
int search(BinaryTree *r,int n){
    if (r==NULL)
    {
        return INT_MIN;
    }
    if (r->data==n)
    {
         printf("Element in the tree\n");
    }
 /*   if (r->left->data<n)
    {
        search(r->right,n);
    }
    if (r->left->data>n)
    {
        search(r->left,n);
    }
   */ 
    if (r->data>n)
    {
        search(r->left,n);
    }
    else if (r->data<n)
    {
        search(r->right,n);
    }
    search(r->left,n);
    search(r->right,n);
/*
      1
    2   3
1.if root =val print
2.if val>root->data move
3/now we want all these to do fpr right and left also --------------->i forgot this earlier.

*/ 

    

    
 
}
int main(){
    //provided the tree is binary search tree only.
    BinaryTree *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    printf("\n");
    int element;
    printf("Enter element to search\n");
    scanf("%d",&element);
     search(root, element);
  
    
    return 0;
}