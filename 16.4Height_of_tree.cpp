#include <bits\stdc++.h>
#include <queue>
#include<math.h>
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
        return;
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
BinaryTree* height(BinaryTree *r){
    if (r==NULL)
    {
        return 0 ;//0 as in answer .

    }
    
   return max(height(r->left),height(r->right))+1;
/*
         1
     2       3--->brewk into simple 1,2,3
   4   5
      6
1->not numm
it will turn to 2,3---->sub problems are 2,3,
they are also not null it will turn to their chidren which is null
0,0 ->max=0  +1==1
height =1 correct naswer 
explanation at anuj bhaiya 6:00
hume sirf "base case"  and simle solution ko cut=rrusion ke form me solve krna hota hai.
think steps in words.
*/


    

}
int main(){
    BinaryTree *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    int n=0;
  printf( "Max height of the tree is %d" ,height(root));

    return 0;
}