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
    int sum=0;
int rootData;
printf("Enter data for root node\n");
scanf("%d",&rootData);
TreeNode *root=new TreeNode(rootData);
sum+=rootData;
queue<TreeNode *> pendingNodes;
pendingNodes.push(root);
while (pendingNodes.size()!=0)
{
    TreeNode *front=pendingNodes.front();
    pendingNodes.pop();
    int numChild;
    printf("Enter no of children for %d node\n",front->data);
    scanf("%d",&numChild);
    for (int i = 0; i < numChild; i++)
    {
        int childData;
        printf("Enter data for %dth child",i);
        scanf("%d",&childData);
        sum+=childData;
        TreeNode *child=new TreeNode(childData);
        front->children.push_back(child);//root k children me new node
        pendingNodes.push(child);//maaing new node root foe second link
    }
    
}
printf("Sum of nodes data is %d\n",sum);
return root;


}
void print(TreeNode *root){
printf("%d:",root->data);
for (int  i = 0; i < root->children.size(); i++)
{
    printf("%d ",root->children[i]->data);
}
printf("\n");
for (int  i = 0; i < root->children.size(); i++)
{
    print(root->children[i]);
}


}
int main(){
    TreeNode *root=takeInput();
    printf("You entered\n");
    print(root);
    return 0;
}