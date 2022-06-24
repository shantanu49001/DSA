#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include<math.h>
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
BinaryTreeNode *takeInput()
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
BinaryTreeNode* height(BinaryTreeNode *r)//returns height of tree passed
{
    if (r == NULL)
    {
        return NULL; // 0 as in answer .
    }

    return max(height(r->left), height(r->right)) + 1;
   
}
BinaryTreeNode* max_h(BinaryTreeNode *r)
{
    if (r==NULL)
    {
        return NULL;
    }
 return  max(height(r->left),height(r->right));    
}
int main()
{
    BinaryTreeNode *root = takeInput();
    printf("You Entered\n");
    PrintTree(root);
    printf("Subtree with maximum height is %d \n", max_h(root));

    return 0;
}