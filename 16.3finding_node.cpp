#include <bits\stdc++.h>
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
void search(BinaryTree *r,int element){
if (r==NULL)
{
    return;
}
if (r->data==element)
{
    printf("Element present in the BT\n");
    return;
}
search(r->left,element);
search(r->right,element);

printf("Not in this tree\n");
}
int main(){
    BinaryTree *root=takeInput();
    printf("You entered\n");
    PrintTree(root);
    int element;
    printf("Enter node data to search\n");
    scanf("%d",&element);
    search(root,element);
    return 0;
}