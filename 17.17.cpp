//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//study this once proprly before noting it down
//apna college explanation
//apna college explanation
//apna college explanation
//apna college explanation
//apna college explanation
//apna college explanation
//apna college explanation
//apna college explanation
//print nodes at level k.
//similar to print cousins
//longest leaf to node path max height wala concept


//distance k pr nodes print all
/*
we are given a target node and k 
let k=3   node =5
           1
         5   2
       6    3  4
        7
       8 9

8,9,3,4  problem ->upar kaise jao


now for 8,9 taking 5 as root k=3
till k=0 moving down print all

now for 3,4
check 5's immediate ancestor and note it's distance from 5
it is 1 nd distance =1 now making it a root print all nodes at distance k-1 


now if 5 is at left and then we have to do that in right sub tree of ancestor node
 reducing our search domain.
 */
//please do it once properly apna college explanation
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack> //vector skipped coz usme top nhi hota hai.
#include <dos.h>
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
//case 1:  8,9  ye 
void printSubtreeNodes(BinaryTreeNode *root,int k){
    if (root==NULL||k<0)
    {
        return;
    }
//bas itna hi hai analyse why and how is it so simple
//bas itna hi hai analyse why and how is it so simple
//bas itna hi hai analyse why and how is it so simple
//bas itna hi hai analyse why and how is it so simple
//bas itna hi hai analyse why and how is it so simple
    if (k==0)
    {
        printf("%d ",root->data);
    }
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
    
    
}
//case2:3,4   isme uoar koi nhi jaa rha root ,root->left root->rigjt hi mjor roles hai
//we are checking taget node at root->left or right and then printing the opssite side nodes.
int printNodesAtk(BinaryTreeNode *root,BinaryTreeNode *target, int k){
if (root==NULL)
{
    return -1;
}
if (root==target)
{
    printSubtreeNodes(root,k);//prints nodes at level k from parent
    return 0;
}
int dl=printNodesAtk(root->left,target,k);
if (dl!=-1)
{
    if (dl+1==k)
    {
        printf("%d",root->data);
    }
    else{
        printSubtreeNodes(root->right,k-dl-2);
    }
    return 1+dl;
}
//we are not going up 
//if let root=5 input
//then we are moving till 1 only and root->left 5 se check 
//then printing root->right nodes
int dr=printNodesAtk(root->right,target,k);
if (dr!=-1)
{
    if (dr+1==k)
    {
        printf("%d",root->data);
    }
    else{
        printSubtreeNodes(root->left,k-dl-2);
    }
    return 1+dl;
}
return -1;



 
}

int main(){
    BinaryTreeNode *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    printNodesAtk(root,root->left,1);
    return 0;
}