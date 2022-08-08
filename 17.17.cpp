
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack> //vector skipped coz usme top nhi hota hai.
#include <dos.h>
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
//case 1:8,9
void printSubtreeNodes(BinaryTreeNode *root,int k){
    if (root==NULL||k<0)//exit condition
    {
        return;
    }
    if (k==0)
    {
        printf("%d",root->data);
    }
    //if k!<0 also k!=0
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);

    
}
//case 2:
int printNodesAtk(BinaryTreeNode *root,BinaryTreeNode *target,int k){
    if (root==NULL)
    {
        return -1;
    }
    if (root==target)
    {
        printSubtreeNodes(root,k);
        return 0;
    }
    //writtrn for left
    int dl=printNodesAtk(root->left,target ,k);
    if (dl!=-1)
    {
        if (dl+1==k)
        {
            printf("%d ",root->data);
        }
        else{
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=printNodesAtk(root->right, target,k);
    if (dr!=-1)
    {
        if (dr+1==k)
        {
            printf("%d ",root->data);
        }
        else{
            printSubtreeNodes(root->left,k-dl-2);
        }
        return 1+dr;
    }
    
    return -1;
}
int main(){
    BinaryTreeNode *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    printNodesAtk(root,root->left,1);
    return 0;
}