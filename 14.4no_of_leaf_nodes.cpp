//nodes that don't have any child.

#include<bits\stdc++.h>
#include<vector>
#include<queue>
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
    printf("Enter data of root node:\n");
    scanf("%d", &rootData);
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        printf("Enter no of child nodes for node with data %d ", front->data);
        int numChild;
        scanf("%d", &numChild);
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            printf("Enter data for %d child node\n", i);
            scanf("%d", &childData);
            TreeNode *child = new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void Print(TreeNode *root)
{
    printf("%d:", root->data);
    for (int i = 0; i < root->children.size(); i++)
    {
        printf("%d ", root->children[i]->data);
    }
    printf("\n");
    for (int i = 0; i < root->children.size(); i++)
    {
        Print(root->children[i]);
    }
}
int LeafNodes(TreeNode *root,int n){
    if (root==NULL)
    {
       // printf("No leaf\n");
        return 1;
    }
for (int i = 0; i < root->children.size(); i++)
{
    if (root->children[i]==NULL)
    {
        
       // break;--->nhi coz abhi baaki chid bache hai
       n++;
        LeafNodes(root->children[i],n);
    }
    
        LeafNodes(root->children[i],n);
    
    
}

//printf("No of leaf Nodes are%d \n", n);
 // 
 //return;
return n;
    }
int main(){
    TreeNode *root=takeInput();
    Print(root);
  //  int leaf=0;
  int a=0;

  int number = LeafNodes(root, a);
  printf("No of leaf nodes are %d \n",number);
  return 0;
}