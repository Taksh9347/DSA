#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *create_node(int data)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void Inorder(struct Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}
void Free_tree(struct Node *root)
{
    if (root == NULL)
        return;
    Free_tree(root->left);
    Free_tree(root->right);
    free(root);
}
void Min_of_BST(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    printf("Lowest value in BST = %d\n", root->data);
}
struct Node *Ins_new_node(struct Node *root, int data)
{
    struct Node *new = create_node(data);
    if (root == NULL)
        return new;
    struct Node *prev = NULL;
    struct Node *curr = root;
    while (curr != NULL)
    {
        prev = curr;
        if (data == curr->data)
        {
            printf("Duplicates are not allowed in BST\n");
            free(new); // cant insert new node so free uneccessary memory
            return root;
        }
        else if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (data < prev->data)
        prev->left = new;
    else
        prev->right = new;
    return root;
}
struct Node *in_order_pre(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct Node *Del_node(struct Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = Del_node(root->left, key);
    else if (key > root->data)
        root->right = Del_node(root->right, key);
    else
    {
        // No children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // One child (right)
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        // One child (left)
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Two children
        else
        {
            struct Node *iPre = in_order_pre(root);
            root->data = iPre->data;
            root->left = Del_node(root->left, iPre->data); // delete original node
        }
    }
    return root;
}
// Given BST
//         13
//     7       15
//  3    8   14    19
//               18
int main()
{
    struct Node *root = NULL;
    root = Ins_new_node(root, 13);
    root = Ins_new_node(root, 7);
    root = Ins_new_node(root, 15);
    root = Ins_new_node(root, 3);
    root = Ins_new_node(root, 8);
    root = Ins_new_node(root, 14);
    root = Ins_new_node(root, 19);
    root = Ins_new_node(root, 18);

    int choice;
    int d1; 
    int d2;
    printf("1.Insert new node\n2.Delete new node\n3.Get Lowest Value of BST\n4.Exit\n");
    printf("Current Inorder of BST -> ");
    Inorder(root);
    while(1)
    {
        printf("\nEnter choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data of new node to be inserted in BST : ");
            scanf("%d", &d1);
            root = Ins_new_node(root, d1);
            printf("After Insertion -> ");
            Inorder(root);
            printf("\n");
            break;

        case 2:
            printf("Enter data of node to be deleted in BST : ");
            scanf("%d", &d2);
            root = Del_node(root, d2);
            printf("After deletion -> ");
            Inorder(root);
            printf("\n");
            break;

        case 3:
            Min_of_BST(root);
            break;

        case 4:
            printf("Exiting...");
            Free_tree(root);
            return 0;
            break;
        }
    }
    return 0;
}