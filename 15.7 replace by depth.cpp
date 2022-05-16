/*
      1--->basic tree

     2

*/
//top most ka refeence zero hai
//i thought neecke tak count krna hai for root node.
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

/*TreeNode *replace(TreeNode *r){

    1  
   2
1.call the root
2.with for loop calculate the depth.
3.update the value


if (r==NULL)
{
    return NULL;
}
int depth=0;//reference level
   if (r->children.size()!=0)
   {
      depth++;
   }
   
   for (int  i = 0; i < r->children.size(); i++)
   {
      replace(r->children[i]);
   }
   
    r->data=depth;
    printNodes( r);
}
*/
/*
basic step is call root chamge it's depth then call it's children and do thatfor then also



*/
TreeNode* replace(TreeNode *r,int level=0){
/*
initially level is passed as 0
we move to exit condition
1.root pr level 0 assign
2.ab 2,3 is passed as child with leel=1
3.when 2 will finish the work then 3 will start.
trees me hr side pr ek side ka sochobaaki sides apne aap kr dengi
perfect example of recursuin.

*/
if (r==NULL)
{
    return NULL;

}
r->data=level;
for (int  i = 0; i < r->children.size(); i++)
{
    replace(r->children[i],level+1);//obvio saare child is level pr same value le rhe hai
}

return r;
}
int main(){
    TreeNode *root=takeInput();
    printf("You Entered\n");
    printNodes(root);
    printf("Now replacing the valus\n");
    printNodes(replace(root));
    return 0;
}
//main issue is i am not able to break recursion in simple and procedural way.
//possible path  me sirf ek path k baare me socho.