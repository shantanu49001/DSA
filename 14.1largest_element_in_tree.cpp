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
    printf("Enter root data\n");
    scanf("%d",&rootData);
    int max=rootData;
    TreeNode *root=new TreeNode(rootData);
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode *front=pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        printf("Enter no children for node %d",front->data);
        scanf("%d",&numChild);
        for (int i = 0; i < numChild; i++)
        {   int childData;
        printf("Enter data for %dth child",i);
        scanf("%d",&childData);
            TreeNode *child = new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
            if (childData>max)
            {
                max=childData;
            }
            
        }
        
    }
    printf("Max value in tree is %d\n",max);
    return root;

}
void print(TreeNode *root)
{
    printf("%d:", root->data);
    for (int i = 0; i < root->children.size(); i++)
    {
        printf("%d ", root->children[i]->data);
    }
    printf("\n");
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}
int main(){
    TreeNode *root=takeInput();
    printf("YOU ENTERED\n");
    print(root); 
    return 0;
}