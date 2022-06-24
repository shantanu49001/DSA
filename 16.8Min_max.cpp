//review this it is returning partial correc val;
#include <bits\stdc++.h>
#include <queue>
#include<limits.h>//for infinty 
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
        return;//void 
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
int min(BinaryTree *r,int min){

}
BinaryTree* maximum(BinaryTree *r,int max){
  //  int n;
if (r==NULL)
{
    return NULL;//VOID RETURN 
}
if (r->data>max)
{
    max=r->data;
}
maximum(r->left,max);
maximum(r->right,max);

BinaryTree *maxi=new BinaryTree(max);
return maxi;
}
int main()
{
    BinaryTree *root = takeInput();
    printf("You entered\n");
    PrintTree(root);
    int max_n =  std::numeric_limits<int>::min();//negative infinty assigned. 
    int min_n= std::numeric_limits<int>::max();//positive infinty assigned.
 //   printf("%d\n",max_n);
  //  printf("%d\n",min_n);
    printf("Maximum value of tree is %d",maximum(root,max_n)->data);
    return 0;
}