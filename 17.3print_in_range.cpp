/*
    30
  40   70
range->  10-50
if root->data >min   && root->data<.ax--->print
if root->left ->data >min &&<max -->root->left   
if root->right->data <
*/
#include<stdio.h>
#include<stdlib.h>
#include<queue>
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
void PrintInRange(BinaryTree *r,int max,int min){
if (r==NULL)
{
    return;
}
if (r->data<=max&&r->data>=min)
{
    printf("%d ",r->data);
}
PrintInRange(r->left,max,min);
PrintInRange(r->right,max,min);


}
int main(){
    BinaryTree *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    int max;
    int min;
    printf("Enter max and min for ur range of search\n");
    scanf("%d",&max);
    scanf("%d",&min);
    PrintInRange(root,max,min);
    
    return 0;
}