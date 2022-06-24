//array is soted
//we have to first figure out max min inarray to construct valid bst
/*
1 2 3 4 5 6 7 
 1
  2
   3---->we don't want this as here also complexit is o(n)-->not reuired
    4
     5
solution-:
1 2 3 4 5 6 7 ---> mid =root
            ----->low =start index and high =length

*/
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
BinaryTree* construct(int a[],int start,int end){
    /** and the tree must be a balancd bst 
     *   1 2 3 -->simple case 
     *   mid =root
     *   start->mid-1--->left subtree
     * mid+1 to end ---->right subtree
     */
    if (start>end)//this is the base case here.
    {
        return NULL;
    }
    
int mid=(start+end)/2;
BinaryTree *root=new BinaryTree(a[mid]);
root->left=construct(a,start,mid-1);//to be given t subtrees.
root->right=construct(a,mid+1,end);
return root;
    
}
int main(){
    int arr[]={10,20,30,40,50,60,70};
    BinaryTree *root=construct(arr,0,6);
    PrintTree(root);
    return 0;
}