// review this code later.
/*
Traversal->
1.level oder the way we did
2.post order->first print my children then me(l,r,n)
3.pre order->first print me then my chiodren.(n,l,r)
4.in order-> l n r


void inorder(BinaryTree *r){
    if(r==NULL){
        return NULL;
    }
    inorder(r->left);
    printf("%d",r->data);
    inorder(r->right);
}


*/
// from the given data in series we have to form a post oreder tree .
// we are doing pre oder here r->l->r
// we have to crete a tree from preoder and inorder .
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
//DOBT IN THIS 
#include <stdio.h>
#include <stdlib.h>
#include <queue>
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
    printf("Enter root Data\n");
    scanf("%d", &rootData);
    BinaryTree *root = new BinaryTree(rootData);
    queue<BinaryTree *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTree *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
    }
}
void PrintTree(BinaryTree *r)
{
    printf("%d:", r->data);
    if (r->left != NULL)
    {
        printf("L-%d ", r->left->data);
    }
    if (r->right != NULL)
    {
        printf("R-%d ", r->right->data);
    }
    printf("\n");
    PrintTree(r->left);
    PrintTree(r->right);
}
BinaryTree *buildTreeHelper(int *n, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = pre[preS];
    int lPreS;
    int lPreE;
    int lInS;
    int lInE;
    int rPreS;
    int rPreE;
    int rInS;
    int rInE;
    BinaryTree *root=new BinaryTree(rootData);
    root->left=buildTreeHelper(in,pre,lInS,lInE,lPreS,lPreE);
    root->right=buildTreeHelper(in,pre,rInS,rInE,rPreS,rPreE);
    reurn root;
}
BinaryTree *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}
int main()
{
    BinaryTree *root = takeInput();
    printf("You entered-:\n");
    PrintTree(root);
    return 0;
}