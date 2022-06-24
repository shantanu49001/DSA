//we have to replace all nodes with sum of data greeater than it 
//cocept  order of changing wll be r->n->left
//also sum of right sub tree has all grtaet than noodes
/*
                6
             3      8
           2  5   7  9 */
//learn in which types programmes we are required to deal with traversals 

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include<vector>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
BinaryTreeNode* takeInput()
{
    int rootData;
    printf("Enter root data\n");
    scanf("%d", &rootData);
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;

        printf("Enter left child data for %d or 0 to skip\n", front->data);
        scanf("%d", &leftChildData);
        if (leftChildData != 0)
        {
            BinaryTreeNode *leftChild = new BinaryTreeNode(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightChildData;
        printf("Enter right child of %d or 0 to skip\n", front->data);
        scanf("%d", &rightChildData);
        if (rightChildData != 0)
        {
            BinaryTreeNode *rightChild = new BinaryTreeNode(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}
void PrintTree(BinaryTreeNode *r)
{
    if (r == NULL)
    {
        return; // for void we canuse this
    }

    printf("%d: ", r->data);
    if (r->left != NULL)
    {
        printf("L-:%d ", r->left->data);
    }
    if (r->right != NULL)
    {
        printf("R-:%d ", r->right->data);
    }
    printf("\n");
    PrintTree(r->left);
    PrintTree(r->right);
}
int minimum(BinaryTreeNode *r)
{
    if (r == NULL)
    {
        return INT_MAX; // reurn max no possible
    }
    // this is the builtin function
    return min(r->data, minimum(r->left), minimum(r->right));
}
int maximum(BinaryTreeNode *r)
{
    if (r == NULL)
    {
        return INT_MIN;
    }
    return max(r->data, minimum(r->left), minimum(r->right));
    // this is the built in
}


bool isBST(BinaryTreeNode *r)
{
    if (r == NULL)
    {
        return true;
    }
    int leftMax = maximum(r->left);
    int rightMin = minimum(r->right);
    bool output = (r->data > leftMax) && (r->data <= rightMin) && isBST(r->left) && isBST(r->right); // we want left and right to also satisfy
    return output;
}
int summ(BinaryTreeNode *r,int sum){
/*   1
   2   3

*/
if (r==NULL)
{
    return NULL;
}
r->data=sum+summ(r->left,sum)+summ(r->right,sum);

return sum;
}
BinaryTreeNode *replaceData(BinaryTreeNode *r)
{   if (r==NULL)
{
    return NULL;
}
  replaceData(r->right);
  r->data=summ(r->right,0);
  replaceData(r->left);
   
   return r;  
}
int main()
{
    BinaryTreeNode *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    if (!isBST(root))
    {
        printf("Not a BST ,this works only for bst\n");
    }
    printf("New BST is\n");
    BinaryTreeNode *rr= replaceData(root);
    printf("\n");
    PrintTree(rr);
    return 0;
}