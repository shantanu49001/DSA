/*
1.BASE CASE -:SIMPLEAST CASE AKA  EXIT POINT-->HITTING LEAF NODE
 2 .INDUCTION -:ASKING OR ASSUMING THAT RECURSION WILL DO WORK FOR CHILDREN NODES
3.CALCULATION -:CALCULATING THE OR COMAPARION WORK
DAIGRM PRANAV BHARADWAJ 4:09


*/
//best method to understand recursuions.


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;
    TreeNode(int data)
    {
        this->data = data;
    }
};

TreeNode *takeInput()
{
    int rootData;
    printf("Enter root data ");
    scanf("%d", &rootData);
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        printf("Enter no of children for node with data %d ", front->data);
        int numChild;
        scanf("%d", &numChild);
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            printf("Enter no of children for %dth child of node with data %d ", i, front->data);
            scanf("%d", &childData);
            TreeNode *child = new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printNodes(TreeNode *root)
{
    printf("%d:", root->data);

    for (int i = 0; i < root->children.size(); i++)
    {
        printf("%d ", root->children[i]->data);
    }
    printf("\n");
    for (int i = 0; i < root->children.size(); i++)
    {
        printNodes(root->children[i]);
    }
}
TreeNode* maxSum(TreeNode *r){
/* 1
  2 
first we are asking 1 to calculate sum of it's nodes 
then we are aksing it's child to calculate it's sum 
then we are comparing the two.*/

    if (r==NULL)
    {
        return NULL;
    }
    TreeNode *max=r;//max node is parent node 
    int ans=max->data;
    for (int  i = 0; i < r->children.size(); i++)
    {
        ans+=r->children[i]->data;//sum of parent node 
        
    }
    for (int  i = 0; i <r->children.size(); i++)
    {
        TreeNode *temp=maxSum(r->children[i]);//ye bhi paremt raha hoga kisi node ka to wo recursion se hi milega---->don't think much here go by the words only.
        int tempSum=temp->data;
        for (int  i = 0; i < temp->children.size(); i++)
        {
            tempSum+=temp->children[i]->data;//storing child sum
        }
       if(tempSum>ans){//comparing and ysng it for other steps .
           ans=tempSum;//child sum is gretaer so for further nodes child is the parent and hence it will be given paremt sum value for other recursions 
           max=temp;//earlier max was parent nde but as child node has grtar sum max node is child now
       } 
    }
    
    
  return max;  
}
int main()
{
    TreeNode *root = takeInput();
    printf("You entered->\n");
    printNodes(root);
  
    printf("Node with maximum sum is %d ", maxSum(root)->data);
    return 0;
}