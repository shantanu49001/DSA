#include<bits\stdc++.h>
#include<queue>
using namespace std;
class BinaryTree{
    public:
int data;
BinaryTree *left;
BinaryTree *right;
BinaryTree(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};
BinaryTree* takeInput(){
    int rootData;
    printf("Enter root data\n");
    scanf("%d",&rootData);
    BinaryTree *r=new BinaryTree(rootData);
    queue<BinaryTree *> pendingNodes;
    pendingNodes.push(r);
    while (pendingNodes.size()!=0)
    {
        BinaryTree *front=pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        printf("Enter left child data for %d node: or press 0 to skip \n ",front->data);
        scanf("%d", &leftChildData);

        if (leftChildData!=0)
        {
            BinaryTree *leftChild=new BinaryTree(leftChildData);
            front->left=leftChild;
            pendingNodes.push(leftChild);
        }
        int rightChildData;
        printf("Enter right child data for %d node: or 0 to skip \n ",front->data);
        scanf("%d",&rightChildData);
        if (rightChildData!=0)
        {
            BinaryTree *rightChild=new BinaryTree(rightChildData);
            front->right-rightChild;
            pendingNodes.push(rightChild);
        }
        

    }
    
return r;
}
void printTree(BinaryTree *r){
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
printTree(r->left);
printTree(r->right);
}
int main(){
    BinaryTree *root=takeInput();
    printf("You entered\n");
    printTree(root);
    return 0;
}