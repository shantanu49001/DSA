//compltetly correct code.
//note the diffrerence between 15.1 and 15.1.1
#include <bits\stdc++.h>
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
    printf("Enter data for root\n");
    scanf("%d", &rootData);
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        printf("Enter number of child nodes for node with data %d", front->data);
        scanf("%d", &numChild);
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            printf("Enter data for %dth child node of parent node with data %d: \n", i, front->data);
            scanf("%d", &childData);
            TreeNode *child = new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
void PrintTree(TreeNode *r)
{
    printf("%d:", r->data);
    for (int i = 0; i < r->children.size(); i++)
    {
        printf("%d ", r->children[i]->data);
    }
    printf("\n");
    for (int i = 0; i < r->children.size(); i++)
    {
        PrintTree(r->children[i]);
    }
}
int numNodes(TreeNode *r,int n){
    /*
          1
        2    3
       4 5  6 7 
    it was not adding value to count it was doing it for indivisual array and then erasing that
    */
if(r==NULL){//--->exit condition most basic -->root mr focus
    return 0;
}
int count=0;//har node ka add hoga
if(r->data>n){
    count++;//---->what we want o do with root focused 
}
for (int  i = 0; i < r->children.size(); i++)
{
    count+=numNodes(r->children[i],n);//now calling recursion.
    //pehli node se jo hoga isme add fir doosri se ......
}

return count;
}
int main()
{
    TreeNode *root = takeInput();
    printf("You Entered\n");
    PrintTree(root);
    int element;
    printf("Enter the element to check \n");
    scanf("%d",&element);
    printf("Number of nodes with data >%d are %d ", element, numNodes(root, element));
}
