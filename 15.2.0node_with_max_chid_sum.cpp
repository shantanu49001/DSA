// 1.first check if node is null-->sum must be =node's dta+it's all child data.
// 2.if not null we have to move to all it's child sum cal
// 3.we have to keep updatingthe sum.
/*
1.we r concerned only to work n root-->intrees
2.rest child ka work recursion karega
3.initially assume max answer is root only
4.sum=root+sum of chidren
5. now run recursion for each child
6.we ive recursion work to find max sum -->out of root and it's children.
7.now update the max and min values
8.



MY CODE-:

*/
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

TreeNode* takeInput()
{   int rootData;
    printf("Enter root data ");
    scanf("%d",&rootData);
    TreeNode *root=new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root); 
    while (pendingNodes.size()!=0)
    {
        TreeNode *front=pendingNodes.front();
        pendingNodes.pop();
        printf("Enter no of children for node with data %d",front->data);
        int numChild;
        scanf("%d",&numChild);
        for (int  i = 0; i < numChild; i++)
        {    int childData;
            printf("Enter no of children for %dth child of node with data %d ",i,front->data);
            scanf("%d",&childData);
            TreeNode *child=new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
        
    }
    
    return root;
}

void printNodes(TreeNode *root)
{
    printf("%d:", root->data);

for (int i = 0; i < root->children.size(); i++){
    printf("%d ",root->children[i]->data);
}
printf("\n");
for (int  i = 0; i < root->children.size(); i++)
{
    printNodes(root->children[i]);
}


}
int maxSum(TreeNode *r,int sum,int root_max){
/* 1
2     --->first step is to ask 1 to get it's sum
       --->then call children to find thier sum
       --->then compare the root sum with child sum and find which one is greater.

*/
    if (r==NULL)
    {
        return r->data;
    }
  int n=r->data;
  for (int  i = 0; i < r->children.size(); i++)
  {
      n+=r->children[i]->data;
  }
 for (int  i = 0; i < r->children.size(); i++)
 {
     maxSum(r->children[i],sum,root_max);
 }
 //how to do comparision step?.
  
    
return root_max;
}
int main()
{
TreeNode *root=takeInput();
 printf("You entered->\n");
 printNodes(root);
 int sum=0;
 int max=0;
 printf("Node with maximum sum is %d ",maxSum(root,sum,max));
    return 0;
}