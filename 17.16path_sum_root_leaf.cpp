/*we will use a vector here to push the nodes into it
       1
     2   3
at first we will check at root if it is the data push into the vector and return the sum(call sum function)
then we will move to left if t is not equal push into the vector
move to the last and even then if ti is not fiund (root==NULL)-->pop all
thhen move to the right one and do the same

*/
//ERROR HERE CHECK ONCE ALTHOUGH PROGRAMME IS CORRECT.
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack> //vector skipped coz usme top nhi hota hai.
#include <dos.h>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
BinaryTreeNode *takeInput()
{
    int rootData;
    printf("Enter root data\n");
    scanf("%d", &rootData);
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;

        printf("Enter left child data for %d or 0 to skip\n", front->data);
        scanf("%d", &leftChildData);
        if (leftChildData != 0)
        {
            BinaryTreeNode *leftChild = new BinaryTreeNode(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightChildData;
        printf("Enter right child of %d or 0 to skip\n", front->data);
        scanf("%d", &rightChildData);
        if (rightChildData != 0)
        {
            BinaryTreeNode *rightChild = new BinaryTreeNode(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}
void PrintTree(BinaryTreeNode *r)
{
    if (r == NULL)
    {
        return; // for void we canuse this
    }

    printf("%d: ", r->data);
    if (r->left != NULL)
    {
        printf("L-:%d ", r->left->data);
    }
    if (r->right != NULL)
    {
        printf("R-:%d ", r->right->data);
    }
    printf("\n");
    PrintTree(r->left);
    PrintTree(r->right);
}
int findSum(stack<int> Np)//ab nested k use krke print kr sakte hai
{
    int sum = 0;
    printf("Node path is\n");
    while (Np.size() != 0)
    {
        int n = Np.top();
        sum += n;
        printf("%d->", n);
    }
    printf("Sum is %d", sum);
}
int  NodePath(BinaryTreeNode *root,stack<int> Np,int n ){//passing vector to the function    vector<int> Np
if (root==NULL)
{
    return NULL;
}
Np.push(root->data);

if (root->data==Np.top())//reached to the node now print and find sum
{
    findSum(Np);
}

if ((root->left==NULL&&root->right==NULL)&&Np.top()!=n)//we are at the rooot node and hum abhi tak nhi aa paye apne data tak to wo path remove krna hoga
{
  while (Np.size()!=0)
  {
  Np.pop();
  }

}
NodePath(root->left,Np,n);
NodePath(root->right,Np,n);


findSum(Np);
}
/*
void root_to_leaf_paths(BinaryTreeNode *root, vector<int> path, vector<vector<int>> &all_paths)
{ // we can also use auto that takes tyrpe on it's own
   if (root==NULL)
   {
    return;
   }
   path.push_back(root->data);
   if (root->left==NULL&&root->right==NULL)//upon reaching the leaf jo bhi hoga chahe null ho wo path ban gya higa
   {
    all_paths.push_back(path);//ek path ban gy ahoga use all path parent vector me push kardo
   }
   root_to_leaf_paths(root->left,path,all_paths);
   root_to_leaf_paths(root->right,path,all_paths);
   
}
*/
int main()
{
    BinaryTreeNode *root = takeInput();
    printf("You entered\n");
    PrintTree(root);
    int element;
    printf("Enter node\n");
    scanf("%d", &element);
    stack<int > paths;
    NodePath(root,paths,element);
    return 0;
}