//we are given a tree
//we need to crete linked lidts from the nodes at sa,e level and store their heads in a array.
//it is ultimatly level order traversal.
//from this prog i will learn  how to combine all snippets of programmes.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
//watch the video and note down the points properly.
#include <bits\stdc++.h>
#include <math.h>
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
class Node{
    int data;
    Node *next;
    Node(int data){
       this->data=data;
       this->next=NULL; 

    }
};
BinaryTree *takeInput()//this can't retuen size so we use vecors for storing heads 
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
void Store_heads(BinaryTree *r,int arr[],int index){
/*
    1
  2   3--->   2->3----:LL
              2 at arr[index]=head*/

}
int main(){
    BinaryTree *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    int index=0;
    int arr[20]={};
    Store_heads(root,arr,index);
    return 0;

}