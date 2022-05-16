#include<bits\stdc++.h>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public:
int data;
vector <TreeNode *> children;
TreeNode(int data){
    this->data=data;
}
};
TreeNode* takeInput(int nodes){
   // int nodes=0;
    int rootData;
    printf("Enter data for root node\n");
    scanf("%d",&rootData);
    TreeNode *root=new TreeNode(rootData);
    nodes++;
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode *front=pendingNodes.front();//!= treenOde *front =root
        pendingNodes.pop();
        
        printf("Enter no of children for %d node\n",front->data);//note this
        int numChild;
        scanf("%d",&numChild);
        for (int  i = 0; i < numChild; i++)//-------->here numChild
        {
            int childData;
            printf("Enter data for %dth child node\n",i);
            scanf("%d",&childData);
            TreeNode *child=new TreeNode(childData);
            nodes++;
            front->children.push_back(child);//sabse peh;e front aka previos ode ke vector me child push bacj
            pendingNodes.push(child);//uske baad queue me pending node k place pr child push
        }
        
    }
    printf("No of nodes are %d\n",nodes); 
    return root;
}
void printNodes(TreeNode *root){
printf("%d:",root->data);
for (int  i = 0; i < root->children.size(); i++)//--->here children.size-->children->size -->ize isn't element of node it is function of vector
{
    printf("%d ",root->children[i]->data);
}
printf("\n");
for (int  i = 0; i < root->children.size(); i++)
{
    printNodes(root->children[i]);
}


}
int main(){
    int num_nodes;
TreeNode *root=takeInput(num_nodes);
printf("You entered\n");
printNodes(root);
}