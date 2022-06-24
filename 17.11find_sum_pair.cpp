/*
sample bst->
         5
     3       6 
   2   4        7

*/
//brut force->inorder is always sorted of bst
//store that in arrau and print the parirs
//complexity O(n) for inorder
//and then for searching

//now a better solution
/*



*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
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
int checkarr(int b[],int val){
    for (int  i = 0; b[i]!=0; i++)
    {
        for (int  j = 0; b[j]!=0; i++)
        {
            if (b[i]+b[j]==val)
            {
                printf("%d+%d ",b[i],b[j]);
            }
            
        }
        
    }
    

}
int checkSumPair(BinaryTreeNode *r,int a[],int i,int sum){
    //inordeer traversal-->l nr
if (r->data==NULL)
{
    return NULL;
}
checkSumPair(r->left,a,i,sum);
int val=r->data;
a[i]=val;
checkSumPair(r->right,a,i+1,sum);

checkarr(a,sum);


}
int main(){
    BinaryTreeNode *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    int arr[100]={0};
    int i=0;
    int sum;
    printf("Enter value to check pairs\n");
    scanf("%d",&sum);
    checkSumPair(root,arr,i,sum);    
    return 0;
}