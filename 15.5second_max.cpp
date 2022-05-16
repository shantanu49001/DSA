//har node sub tree ka max and secon d ma x ko apas me compare krke update krn hai.
/*
     1
   2----->basic tree to work on 
1.making root node max ad child second max on comparision


*/
//problem here in the code
//problem here in the code
//problem here in the code
//problem here in the code
//problem here in the code
//problem here in the code
//problem here in the code
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
int  secondMax(TreeNode *r){
    if (r==NULL)
    {
        return NULL;
    }
     int val=r->data;
     int val2;
    for (int  i = 0; i < r->children.size(); i++)
    {
  val2=secondMax(r->children[i]);
      
    }
int largest;
int second_l;
if(val>val2){
 largest=val;
 second_l=val2;
}
  

return second_l;
}
int main(){
    TreeNode *root=takeInput();
    printf("You Entered\n");
    printNodes(root);
    printf("Second max element in tree is %d ",secondMax(root));
    return 0;
}