//1.given level order traveral--->same as what we were doing in bst code.
/*
we shold not comapre left and right child with the root
as 
         4
     2       6 
  1   10   5   7--->satisfies the condion but it is not bst

for this we need to get max of left and min of right and compre that with the root

for tsting-:

      1                              4
  2        3------>false            2   6
4  5     6   7                      3 5 7--->true
        8 9
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
int minimum(BinaryTree *r){
    if (r==NULL)
    {
        return INT_MAX;//reurn max no possible
    }
    //this is the builtin function
    return min(r->data,minimum(r->left),minimum(r->right));
    

}
int maximum(BinaryTree *r){
    if (r==NULL)
    {
        return INT_MIN;
    }
    return max(r->data,minimum(r->left),minimum(r->right));
    //this is the built in
    

}
bool isBST(BinaryTree *r){
    if (r==NULL)
    {
        return true;
    }
    int leftMax=maximum(r->left);
    int rightMin=minimum(r->right);
    bool output=(r->data>leftMax)&&(r->data<=rightMin)&&isBST(r->left)&&isBST(r->right);//we want left and right to also satisfy
    return output;
    

}
int main(){
    BinaryTree *root=takeInput();
    printf("You entered\n");
    PrintTree(root);
    printf("Now checking for bst\n");
    if (isBST(root))
    {
        printf("BST true\n");
    }
    else{
        printf("BST false");
    }
    
    return 0;
}
/*
Now checking the time complexity->
we are moving to each ad every node which must be avoided
T(n)=2T(n/2)+kN---->2 half tree and n comparisions












*/