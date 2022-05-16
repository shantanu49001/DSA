#include<bits\stdc++.h>
#include<vector>
//ctrl z -->undo.
#include<queue>
using namespace std;
//har parent ko apne child return karne hai bas recursively.
class TreeNode{
public:
int data;
vector<TreeNode*> children;//ye template hai to batana padega k ye treenode k pointer ko store krta hai
TreeNode(int data){
    this->data=data;
}
};
TreeNode* takeInput(){
    int rootData;
    printf("Enter root data\n");
    scanf("%d",&rootData);
    TreeNode *root=new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);//parent
    while (pendingNodes.size()!=0)
    {
        TreeNode *front=pendingNodes.front();
        pendingNodes.pop();
        printf("Enter no of child for %d node\n",front->data);
        int numChild;
        scanf("%d",&numChild);
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            printf("Enter %d child data",i);
            scanf("%d",&childData);
            TreeNode *child=new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
        
    }
    return root;
}
void printTree(TreeNode *root){
    printf("%d:",root->data);
    for (int  i = 0; i < root->children.size(); i++)
    {
        printf("%d ",root->children[i]->data);
    }
    printf("\n");
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
    
}
int main(){
    TreeNode *root=takeInput();
    printTree(root);
    return 0;
}