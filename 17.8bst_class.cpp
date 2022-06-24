// we will now create a class to implement all the functions
#include <stdio.h>
#include <stdlib.h>
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
class BST
{
    BinaryTreeNode *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode *deleteData(int data, BinaryTreeNode *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data > node->data)
        {
            // deleteData(data,node->right);//but might have possible that right might have changed
            node->right = deleteData(data, node->right);
            return node;
        }
        else if (data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        else
        {
            // now we might have a root whose right or left might be null
            // in these cases we will replace the node with it's max or in in subtree.
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
                ;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else // most intersting case-->where right and left both are not null
                 // minimum of right is the replacement
                BinaryTreeNode *minNode = node->right;
            while (minNode->left != NULL)
            {
                minNode = minNode->left;
            }
            int rightMin = minNode->data;
            node->data = rightMin;
            node->right = (rightMin, node->right);
            return node;
        }
    }
private:
    void PrintTree(BinaryTreeNode *r)
    {
        if (r == NULL)
        {
            return; // void
        }
        printf("%d: ", r->data);
        if (r->left != NULL)
        {
            printf("L:%d ", r->left->data);
        }
        if (r->right != NULL)
        {
            printf("R:%d ", r->right->data);
        }
        printf("\n");
        PrintTree(r->left);
        PrintTree(r->right);
    }
public:
void printTree(){
    PrintTree(root);
}
public:
    void deleteData(int data)
    {
        root=deleteData(data,root);
    }
    void printTree(BinaryTreeNode *root){
        printTree(root);
    }

private:
    BinaryTreeNode *insert(int data, BinaryTreeNode *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode *newNode = new BinaryTreeNode(data);
            return newNode;
        }
        if (data < node->data) // reaching the left node node for insertion
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }

public:
    void insert(int data)
    {
        this->root = insert(data, this->root);
    }

private:
    bool hasData(int data, BinaryTreeNode *node)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (data < root->data)
        {
            // return hasData(data,root->left);---->we want this to occur.
            return hasData(data, node->left);
        }
        else
        {
            return hasData(data, node->right);
        }
    }

public:
    bool hasData(int data) // isko root nhi deni padti coz ye objexct ke root me call krta hai
    {
        return hasData(data, root); // lekin we don't want ki ye object k root pr call kare isliye ye doosre function me jata hai
    }
};
int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.printTree();
/*
                10
              5    20
            3   7




*/
    return 0;
}