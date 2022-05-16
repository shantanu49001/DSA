// we have to count no of nodes with dtaa gretater than elemnt entered.
//parially correct.
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
    int data;
    printf("Enter root node data\n");
    scanf("%d", &data);
    TreeNode *root = new TreeNode(data);
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        printf("Enter no of child for parent-node with data %d \n", front->data);
        scanf("%d", &numChild);
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            printf("Enter data of %dth child node with parent node as %d : \n", i, front->data);
            scanf("%d", &childData);
            TreeNode *child = new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printNodes(TreeNode *r)
{
    printf("%d:", r->data);
    for (int i = 0; i < r->children.size(); i++)
    {
        printf("%d ", r->children[i]->data); // function-->  .       node element ->
    }
    printf("\n");
    for (int i = 0; i < r->children.size(); i++)
    {
        printNodes(r->children[i]);
    }
}
int num_nodes(TreeNode *r, int element, int n)
{
  //broad steps recall
  //1.if node null->node me kuch nhi -->come out
  //2.if node not null
  //3.firt move to children
  //4.then compare elem with root
  //5.return journey it will handle
  //be cpncerned on;y about root
  
  
  if (r->data>element)
  {
      n++;
  }
  for (int  i = 0; i < r->children.size(); i++)
  {
      if (r->children[i]->data>element)
      {
          n++;
          
      }
      num_nodes(r->children[i],element,n);
      
  }
  
  
  return n;
}
int main()
{
    TreeNode *root = takeInput();
   // printf("%d",root->children.size());
    printf("You Entered: \n");
    printNodes(root);
    int element;
    printf("Enter element to check\n");
    scanf("%d", &element);
    int n=0;
    int nodes = num_nodes(root, element, n);
     printf("No of element > %d are %d \n", element, nodes);
   
    return 0;
}