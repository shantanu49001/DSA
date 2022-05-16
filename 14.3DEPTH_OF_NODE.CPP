//DEPTH OF ROOT=0
//DEPT OF A NODE=DISTANCE FROM NODE
//problem is print all nodes at depth =k;
//WE WILL USE RECURSIONS HERE.
/*
       1
    2     3---->recursion gets choice here so it first explores 1st choice comp then return to sendong choice 
 4    5  6  7 
if we wnter level 2
1->deny karke for lopp ke through pehle child ko bolega 
2->deny apne aage wale pehle child ko call
4->agree
2->second child ko cal
5->agree
iske baad 
1->doosre wlae child mo call
3->deny
3->call pehle cjhild 
6->agree
3->call doosre child 
7->agree
*/
#include<bits\stdc++.h>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public:
int data;
vector<TreeNode *> children;
TreeNode(int data){
    this->data=data;
}
};
TreeNode* takeInput(){
int rootData;
printf("Enter data of root node:\n");
scanf("%d",&rootData);
TreeNode *root=new TreeNode(rootData);
queue<TreeNode* > pendingNodes;
pendingNodes.push(root);
while (pendingNodes.size()!=0)
{
    TreeNode *front=pendingNodes.front();
    pendingNodes.pop();
    printf("Enter no of child nodes for node with data %d ",front->data);
    int numChild;
    scanf("%d",&numChild);
    for (int  i = 0; i < numChild; i++)
    {
        int childData;
        printf("Enter data for %d child node\n",i);
        scanf("%d",&childData);
        TreeNode *child=new TreeNode(childData);
        front->children.push_back(child);
        pendingNodes.push(child);
    }
    
}
return root;
}
void Print(TreeNode *root){
    printf("%d:",root->data);
    for (int  i = 0; i < root->children.size(); i++)
    {
        printf("%d ",root->children[i]->data);
    }
    printf("\n");
    for (int i = 0; i < root->children.size(); i++)
    {
        Print(root->children[i]);
    }
    

}
//DEPTH PART
//basically we wil decrement value of k at each recursive call and print when depth=0
void printAtLevelK(TreeNode *root,int k){
    if(root==NULL){
        printf("Nothing to print\n");
        return ;
    }
if(k==0){
    printf("%d ",root->data);
}
for (int  i = 0; i < root->children.size(); i++)
{//now call for root's child and one level down
    printAtLevelK(root->children[i],k-1);
}

}
int main(){
    TreeNode *root=takeInput();
    printf("You entered\n");
    Print(root);
    int value;
    printf("Enter the depth to print all nodes at that depth\n");
    scanf("%d",&value);
   printAtLevelK(root,value);
    return 0;
}