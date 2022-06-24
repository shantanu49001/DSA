#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <Windows.h>
#include <vector>
#include <queue>
using namespace std;
int min_n = INT_MIN;
HANDLE h;
void Animation()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
                                                
                                            
    char x = 219;                               
    for (int i = 0; i < 35; i++)
    {
        SetConsoleTextAttribute(h, 13); 
        printf("%c", x);
        if (i < 10)
        {
            Sleep(300); 
        }
        if (i >= 10 && i < 20)
        {
            Sleep(150);
        }
        if (i >= 10)
        {
            Sleep(25);
        }
    }
    SetConsoleTextAttribute(h, 7);
}

int val;
struct node
{
    int data;
    node *left;
    node *right;
    int stree_sum;
    
    node(char data)
    {
        this->data = data;
        left = right = NULL;
    }
};
node *r_fourth = NULL;
vector<node *> leaf;
node *buildTree(int in[], int pre[], int start, int end, map<int, int> &m, int &index)
{
    
    if (start > end)
    {
        return NULL;
    }

    char current = pre[index++];
    node *p = new node(current);
    int inFind = m[current];
    p->left = buildTree(in, pre, start, inFind - 1, m, index);
    p->right = buildTree(in, pre, inFind + 1, end, m, index);
    return p;
}
void PrintTree(node *r)
{
    if (r == NULL)
    {
        return;
    }
    if (r->left == NULL && r->right == NULL)
    {
        printf("%d:\n", r->data);
    }
    else
    {
        printf("%d:", r->data);
    }

    if (r->left != NULL)
    {
        printf("L:%d ", r->left->data);
    }
    if (r->right != NULL)
    {
        printf("R:%d\n", r->right->data);
    }
    PrintTree(r->left);
    PrintTree(r->right);
}

node *reach_node(node *r, int n)
{
    if (r == NULL)
    {
        return NULL;
    }
    if (r->data == n)
    {

        return r;
    }

    reach_node(r->left, n);
    reach_node(r->right, n);
}
int sum(node *r)
{
    if (r == NULL)
        return 0; 
    return r->data + sum(r->left) + sum(r->right);
}
node *insert(node *r, int key1, int key2)
{
    if (r == NULL)
    {
        return NULL;
    }

    if (r->data == key2)
    {
        
        int left_sum = sum(r->left);
        int right_sum = sum(r->right);
        
        if (left_sum > right_sum)
        {
            while (r->left != NULL)
            {
                r = r->left;
            }
            node *n = new node(key1);
            r->left = n;
        }
        else
        {
            while (r->right != NULL)
            {
                r = r->right;
            }
            node *n1 = new node(key1);
            r->right = n1;
        }

        return r;
    }

    insert(r->left, key1, key2);
    insert(r->right, key1, key2);

    return r;
}
node *insert_tree(node *r, node *r_i, int key2)
{
    if (r == NULL)
    {
        return NULL;
    }

    if (r->data == key2)
    {
        
        int left_sum = sum(r->left);
        int right_sum = sum(r->right);
        
        if (left_sum > right_sum)
        {
            while (r->left != NULL)
            {
                r = r->left;
            }
            
            r->left = r_i;
        }
        else
        {
            while (r->right != NULL)
            {
                r = r->right;
            }
            
            r->right = r_i;
        }

        return r;
    }

    insert_tree(r->left, r_i, key2);
    insert_tree(r->right, r_i, key2);

    return r;
}
node *insert_tree_last(node *r, node *r_i, int key2)
{
    if (r == NULL)
    {
        return NULL;
    }

    if (r->data == key2)
    {
        if (r->left == NULL && r->right != NULL)
        {
            r->left = r_i;
        }
        else if (r->right == NULL && r->left != NULL)
        {
            r->right = r_i;
        }
        else if (r->left == NULL && r->right == NULL)
        {
            r->left = r_i;
        }
        else if (r->left != NULL && r->right != NULL)
        {
            r->left = r_i;
        }

        return r;
    }

    insert_tree(r->left, r_i, key2);
    insert_tree(r->right, r_i, key2);

    return r;
}

node *reach_leaf(node *r, node *r_max_node)
{ 
    if (r == NULL)
    {
        return NULL;
    }
    if (r->left == NULL && r->right == NULL)
    {
        if (r->data > min_n)
        {
            r_max_node = r;
        }
    }
    reach_leaf(r->left, r_max_node);
    reach_leaf(r->right, r_max_node);
    return r_max_node;
}

node *delete_node(node *r, int node_val)
{
    if (r == NULL)
    {
        return NULL;
    }

    if (r->data == node_val)
    {
        
        int left_sum = sum(r->left);
        int right_sum = sum(r->right);
        
        if (left_sum > right_sum)
        { 
            node *max_leaf = reach_leaf(r->left, r->left);
            r->data = max_leaf->data;
            SetConsoleTextAttribute(h, 14);
            printf("PART 3:New Updates tree is\n");
            Animation();
            printf("\n");
            node *r_fourth = r;
            SetConsoleTextAttribute(h, 7);
            PrintTree(r);
            return r_fourth;
            
        }
        else
        {
            node *max_leaf = reach_leaf(r->right, r->right);
            r->data = max_leaf->data;

            
        }

    
    }

    delete_node(r->left, node_val);
    delete_node(r->right, node_val);
}
node *return_max_sum_diff(node *r, node *r_max) 
{
    if (r == NULL)
    {
        return NULL;
    }
    
    int left_sub_sum = sum(r->left);
    int right_sub_sum = sum(r->right);
    if (abs((left_sub_sum) - (right_sub_sum)) > r_max->data)
    {
        r_max = r;
    }
    return_max_sum_diff(r->left, r_max);
    return_max_sum_diff(r->left, r_max);

    return r_max;
}
node *build_tree_absent(int n, node *root_a)
{ 
    node *r = new node(n);
    int count = 1;

    queue<node *> pendingNodes;
    pendingNodes.push(r);
    while (count != 7)
    {
        node *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        printf("Enter left child data of %d \n", front->data);
        scanf("%d", &leftChildData);
        if (reach_node(root_a, leftChildData) == NULL)
        {
            node *leftChild = new node(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
            count++;
        }
        else
        {
            printf("Enter the nodes that r not present,re enter left child data of %d ", front->data);
            scanf("%d", &leftChildData);
            node *leftChild = new node(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
            count++;
        }
        int rightChildData;
        printf("Enter right child Data of %d\n", front->data);
        scanf("%d", &rightChildData);
        if (reach_node(root_a, rightChildData) == NULL)
        {
            node *rightChild = new node(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
            count++;
        }
        else
        {
            printf("Enter the nodes that r not present,re enter left child data of %d ", front->data);
            scanf("%d", &rightChildData);
            node *rightChild = new node(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
            count++;
        }
    }
    return r;
}
int main()
{
    int n;
    int choice = 1;
    while (choice != 0)
    {
        printf("PART 1(A):Enter  Inorder and preOrder array size\n");
        cin >> n;
        int *in = new int[n];
        int *pre = new int[n];
        printf("Enter inorder array\n");
        for (int i = 0; i < n; i++)
        {
            cin >> in[i];
        }
        printf("Enter preOrder array\n");
        for (int i = 0; i < n; i++)
        {
            cin >> pre[i];
        }
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[in[i]] = i;
        }
        int start = 0, end = n - 1, index = 0;
        node *root = buildTree(in, pre, start, end, m, index);
        node *root_skip = root;
        SetConsoleTextAttribute(h, 14);
        printf("PART 1(A):You Tree is\n");
        Animation();
        printf("\n");
        SetConsoleTextAttribute(h, 7);
        PrintTree(root);
        int element;
        printf("PART 1(B):Enter node to find sum of node and children\n");
        scanf("%d", &element);
        SetConsoleTextAttribute(h, 14);
        printf("PART 1(B):Sum of root and it's children is\n");
        Animation();
        printf("\n");
        SetConsoleTextAttribute(h, 7);
        if (!sum(reach_node(root, element)))
        {
            printf("Node not in tree\n");
        }
        else
        {
            printf("PART 1(B):Sum is:%d\n", sum(reach_node(root, element)));
        }

        int key1;
        int key2;
        printf("PART 2:Enter value of key1\n");
        scanf("%d", &key1);
        printf("PART 2:Enter value of key2\n");
        scanf("%d", &key2);
        node *root_two = NULL;
        if (reach_node(root, key2) == NULL)
        {
            printf("Error key2 absent\n");
        }

        else
        {
            node *root_two = insert(root, key1, key2);
            SetConsoleTextAttribute(h, 14);
            printf("PART 2:New Updated tree is\n");
            Animation();
            printf("\n");
            SetConsoleTextAttribute(h, 7);
            PrintTree(root_two);
            int root_data;
            printf("PART 3:Enter node u want to delete\n");
            scanf("%d", &root_data);
            if (reach_node(root_two, root_data) == NULL)
            {
                printf("Not in the tree\n");
            }
            else
            {
                node *root_three = delete_node(root_two, root_data);
                Sleep(500);
                printf("PART 4:Enter key2 not present in origional tree:\n");
                PrintTree(root_skip);
                printf("\n");
                int n;
                scanf("%d", &n);
                if (reach_node(root, n) == NULL)
                {
                    printf("Key2 not in the tree\n");
                    printf("Forming new tree with root as %d\n", n);
                    printf("Enter tree data in level order\n");
                    node *root_four = build_tree_absent(n, root_skip);
                    printf("PART 4:New Tree is\n");
                    Animation();
                    printf("\n");
                    PrintTree(root_four);
                    printf("Inserting this tree into tree at PART 2\n");
                    node *r_max_dif = return_max_sum_diff(root_skip, root_skip);
                    printf("Node with max difference of left and right sub tree is %d\n", r_max_dif->data);
                    node *root_final=insert_tree_last(root_skip,root_four,r_max_dif->data);
                    printf("PART4:Final Tree is\n");
                    Animation();
                    printf("\n");
                    PrintTree(root_final);
                }
                else
                {
                    printf("Key2 in the tree, operation  alredy done in PART 2\n");
                }
            }
        }
        printf("Run Programme again? 1->yes 0->No!Exit!\n");
        scanf("%d", &choice);
    }
    printf("Exited!\n");
    return 0;
}