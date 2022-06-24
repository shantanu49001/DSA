//DAIMETER ->MAXIMUM DISTANCE BETWEEN TWO POINTS.
//MAXIMUM DISTANCE BETWEEN TWO NODES.
//3:00 TIME STAMP
//LEFT HEIGHT +RIGHT HEIGHT->TWO TWO NODES ARE OPPE
//LEFT HEIGHT/RIGHT HEIGHT IF BTH ARE AT SAME NODE
//MAX OF ALL THESE IS THE DAIMETER OF TREE
#include <stdio.h>
#include<stdlib.h>
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
 int height(BinaryTree *r)
{
    if (r == NULL)
    {
        return 0; // 0 as in answer .
    }

    return max(height(r->left), height(r->right)) + 1;
}
int Daimeter(BinaryTree *r)
{
    if (r == NULL)
    {
        return 0; // 0 as in answer .
    }
    int option1=height(r->left) + height(r->right);//when both ae at differentimmediate parent
    int option2=Daimeter(r->left);//when both the max odes are at same psarent (immediate)//we are nting parent's height
    int option3=Daimeter(r->right);
    return max(option1,option2,option3)/2; 
    

}
    int main()
    {
        BinaryTree *root = takeInput();
        printf("You Entered\n");
        PrintTree(root);
        printf("Radius of three is \n");

        return 0;
    }