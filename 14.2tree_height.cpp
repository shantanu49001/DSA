/*
     1
   2   3
  4      --->basically we hav to find max heght of thr brbaches and return the max value of all childs.
*/
// recursivly roots pass till root->children[i]!=NULL

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

    printf("Enter no of child for %d node\n", front->data);
    scanf("%d", &numChild);
    for (int i = 0; i < numChild; i++)
    {
      int childData;
      printf("Enter data for %dth child node", i);
      scanf("%d", &childData);
      TreeNode *child = new TreeNode(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
        
    }
  }
  return root;
}
void  printTree(TreeNode *root)
{ 
  printf("%d:", root->data);
  for (int i = 0; i < root->children.size(); i++)
  {
    printf("%d ", root->children[i]->data);
  }
  printf("\n");
  for (int i = 0; i < root->children.size(); i++)
  {
    printTree(root->children[i]);
  }
}
int heightofTree(TreeNode *root,int length){
for (int  i = 0; i < root->children.size(); i++)
{
  if (root->children[i]!=NULL)
  {
    length++;
    heightofTree(root->children[i], length);
  }
  
}

return length;


  

}
int main()
{ int height=0;
  TreeNode *root = takeInput();
  printf("You Entered-:\n");
 printTree(root);
 //printf("Height of tree is\n");
 int h=heightofTree(root,height);
 printf("Height of tree is %d",h);
  return 0;
}
