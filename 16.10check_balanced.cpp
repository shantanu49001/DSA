// if differnce between left and right depth is <=1
#include <bits\stdc++.h>
#include<math.h>
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

BinaryTree *height(BinaryTree *r)//very very imp function.
{
    if (r == NULL)
    {
        return 0; // 0 as in answer .
    }

    return max(height(r->left), height(r->right)) + 1;
}

int Balanced(BinaryTree *r,bool b){
    if (r==NULL)
    {
        return INT_MIN;
    }
//bool n=0;
   int n=height(r->left)-height(r->right);   
   if (abs(n)<=1)
   {
       b=1;
   }
   else{
       b=0;
      // printf("Tree not balanced \n");
       return b;
   }
   Balanced(r->left,b=1);
   Balanced(r->right,b=1);
   
return b;
    
}
int main()
{
    BinaryTree *root = takeInput();
    printf("You Entered\n");
    PrintTree(root);
    printf("Checking for balanced tree\n");
    bool balance=1;
    if (Balanced(root,balance)==true)
    {
        printf("Tree Balanced\n");
    }
    else{
        printf("Tree Unbalanced\n");
    }
    
    return 0;
}