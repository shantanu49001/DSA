#include<bits\stdc++.h>
#include<queue>
using namespace std;
class BinaryTreeNode{
    public:
int data;
BinaryTreeNode* left;
BinaryTreeNode* right;
BinaryTreeNode(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
   
}
~BinaryTreeNode()
{
    delete left;
    delete right;
}
};
void printTree(BinaryTreeNode *r){
//in generic tree agar koi root ka child nhi tha to wo for loop call nhi karta tha lekin binary me wo paake se call krt hai isliye base case likhna hi padega
//1.check exit condition
//2.call root and print it's left and right
//3.since printing work ids already written,
//4.now we will call left and right to become root and print.
if (r==NULL)
{
    return;
}
printf("%d: ",r->data);
if (r->left!=NULL)
{
    printf("L:%d ",r->left->data);
}
if (r->right!=NULL)
{
    printf("R:%d ",r->right->data);
}
printf("\n");
printTree(r->left);//code is wriiten we will not repaet that again--->do the same for ith parents's left node and right node
printTree(r->right);

}
BinaryTreeNode* takeInput(){//similar to generic tree bas yahn rooot ke baad single child ki jagah pr 2 child pending me push honge.
int rootData;
printf("Enter root data\n");
scanf("%d",&rootData);
if (rootData==0)
{
    return NULL;
}
BinaryTreeNode *root=new BinaryTreeNode(rootData);//root ko form krne k baad 
queue<BinaryTreeNode *> pendingNodes;
pendingNodes.push(root);
while (pendingNodes.size()!=0)
{
    BinaryTreeNode *front=pendingNodes.front();
    pendingNodes.pop();
    printf("Enter left child of %d: ",front->data);
    int leftChildData;
    scanf("%d",&leftChildData);
    if (leftChildData!=0)
    {
        BinaryTreeNode *child=new BinaryTreeNode(leftChildData);
        front->left=child;//front aka current parent
        pendingNodes.push(child);//left node pushed to pending nodes
    }
    printf("Enter right child of %d: ",front->data);
    int rightChildData;
    scanf("%d",&rightChildData);
    if (rightChildData!=0)
    {
     BinaryTreeNode *child=new BinaryTreeNode(rightChildData);
     front->right=child;
     pendingNodes.push(child);
    }
    
    
}

return root;
}
int main(){
   BinaryTreeNode *root=takeInput();
   printf("You enetred-:\n");
   printTree(root);
    return 0;
}