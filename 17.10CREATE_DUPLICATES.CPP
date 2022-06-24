//here we have to create duplicate of each noode at ad d it tas their eft child
/*
       10                          10
    7       15------->          10     15
  2  8   12   25               7     15    25
                             7     12    25
                           2     12
                         2



CODE IS CORRECT!!!!
*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
class BinaryTreeNode{
    public:
int data;
BinaryTreeNode *left;
BinaryTreeNode *right;
BinaryTreeNode(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};
BinaryTreeNode* takeInput(){
int rootData;
printf("Enter root data\n");
scanf("%d",&rootData);
BinaryTreeNode *root=new BinaryTreeNode(rootData);
queue<BinaryTreeNode *> pendingNodes;
pendingNodes.push(root);
while (pendingNodes.size()!=0)
{
    BinaryTreeNode *front=pendingNodes.front();
    pendingNodes.pop();
    int leftChildData;
   
    printf("Enter left child data for %d or 0 to skip\n",front->data);
    scanf("%d", &leftChildData);
    if (leftChildData!=0)
    {
        BinaryTreeNode *leftChild=new BinaryTreeNode(leftChildData);
        front->left=leftChild;
        pendingNodes.push(leftChild);

    }
    int rightChildData;
    printf("Enter right child of %d or 0 to skip\n",front->data);
    scanf("%d",&rightChildData);
    if (rightChildData!=0)
    {
        BinaryTreeNode *rightChild=new BinaryTreeNode(rightChildData);
        front->right=rightChild;
        pendingNodes.push(rightChild);
    }
    
    
}

return root;

}
void PrintTree(BinaryTreeNode *r){
    if (r==NULL)
    {
        return;//for void we canuse this
    }
    
   printf("%d: ",r->data);
   if (r->left!=NULL)
   {
       printf("L-:%d ",r->left->data);
   }
   if (r->right!=NULL)
   {
       printf("R-:%d ",r->right->data);
   }
   printf("\n");
   PrintTree(r->left);
   PrintTree(r->right);
}
BinaryTreeNode* updataTree(BinaryTreeNode *r){
/*
    1             1
  2   3----->   2   3
              2    3
1.at each node i have to create it's duplocate
2.make a duplicate node with 
3.store the left sub tree in a new node
4.point the root's left to the dupl
5.point the duplicate's left to the store eft subtree
6.that's it.
*/
if (r==NULL)
{
    return NULL;
}

BinaryTreeNode *r_l_d=new BinaryTreeNode(r->left->data);
BinaryTreeNode *r_l_r=r->left;//we have creted a pointer of type binary nde that has addtre of r->left
r->left=r_l_d;
r_l_d->left=r_l_r;
updataTree(r->left);
updataTree(r->right);


return r;
}
int main(){
    BinaryTreeNode *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    printf("Now duplicating the left children\n");
    BinaryTreeNode *dup=updataTree(root);
    PrintTree(dup);
    return 0;
}