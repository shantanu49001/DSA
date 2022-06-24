/*     1--------->    1
     2   3          2
  4    5              5
         6


*/


#include <bits\stdc++.h>
#include <math.h>
#include <queue>
//#include <limits.h> //for infinty
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
BinaryTree* remove_leaf(BinaryTree *r){
    /*
    consider only the root
    rt  -->if roott ka left &right ==nulll
   l r
    */
    if (r==NULL)
    {
        return NULL;
    }
    //free (root)
    //return null
    if (r->left==NULL&&r->right==NULL)
    {
        free(r);
        return NULL;
    }
    
  /*  remove_leaf(r->left);
    remove_leaf(r->right);
    */
   r->left=remove_leaf(r->left);
   r->right=remove_leaf(r->right);
   //we are assigning the right and left of first most root as we are deleting the nodes so we must also connect the left and right of our root 
   //since lrft and right are also the effective roots we wrote this
   //1.root ka left and right null check
   //2.if null we are freeing the node
   //3.if not we are connecing the left and right of root rom the chuldren who also go through the same process.
    return r;

}
int main()
{
    BinaryTree *root = takeInput();
    printf("You Entered\n");
    PrintTree(root);
    printf("\n");
    printf("Now removing the leaf nodes\n");
  BinaryTree *n=  remove_leaf(root);
    PrintTree(n);
    return 0;
}