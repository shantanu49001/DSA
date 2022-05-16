/*we will also use recursion here

        1
      2    3
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
int data;
printf("Enter data for root node\n");
scanf("%d",&data);
TreeNode *root=new TreeNode(data);
queue<TreeNode *> pendingNodes;
pendingNodes.push(root);
while (pendingNodes.size()!=0)
{
    TreeNode *front=pendingNodes.front();
    pendingNodes.pop();
    int numChild;
    printf("Enter no of children for node with data %d \n",front->data);
    scanf("%d",&numChild);
    for (int i = 0; i < numChild; i++)
    {
        int childData;
        printf("Enter data for %dth child of parent node with data",i,front->data);
        scanf("%d",&childData);
        TreeNode *child=new TreeNode(childData);
        front->children.push_back(child);
        pendingNodes.push(child);
    }
    
}
return root;
}
void PrintTree(TreeNode *r){
printf("%d:",r->data);
for (int i = 0; i < r->children.size(); i++)
{
    printf("%d ",r->children[i]->data);
}
printf("\n");
for (int i = 0; i < r->children.size(); i++)
{
    PrintTree(r->children[i]);
}



}
void checkElement(TreeNode *root,int n){
    // agar root hi hai to  return
    // warna child pe jake root data check--->always krna hai
    //check for simplest tree(basic condition)
    if (root->data==n)
    {
        printf("ELEMENT IN TREE\n");
        //return 0;
    }
    for(int i=0;i<root->children.size();i++){
     checkElement(root->children[i],n);
    }

    

}
int main(){
    TreeNode *root=takeInput();
    printf("You Entered\n");
    PrintTree(root);
    int element;
    printf("Enter element to check\n");
    scanf("%d",&element);
    checkElement(root,element);
    return 0;
}