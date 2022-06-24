// we have to create a sorted ll from bst.
//review this code.
//review this code.
//review this code.
//review this code.
//review this code.
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
void printNode(BinaryTree *r)
{
    while (r->right != NULL)
    {
        printf("%d->", r->data);
        r = r->right;
    }
}

BinaryTree *createll(BinaryTree *r)
{
    // shoretest order of bst is in inorder traversal
    if (r == NULL)
    {
        return NULL;
    }
    /*
            5
         3      7
        2  4   6  8

2->3->4->5->6->7->8->n--------->this traversal is obtained by inoder of bst
|  |  |  |  |  |  |
n  n  n  n  n  n  n      ===>concept.
    basic

    */
    //  5
    // 3  7--->basic
    if (r == NULL)
    {
        return NULL;
    }
    createll(r->left);
    r->left->left = NULL;
    r->left->right = r;
    createll(r);
    // r's right is unchaged.
    r->left = NULL;
    createll(r->right);
    r->right->left = NULL;
    r->right->right = NULL;

    return r;
}
int main()
{
    BinaryTree *root = takeInput();
    printf("You Entered\n");
    PrintTree(root);
    BinaryTree *ll = createll(root);
    printf("Sorted ll is\n");
    printNode(ll);

    return 0;
}