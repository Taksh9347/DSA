#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
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
int max(int a, int b)
{
    return a > b ? a : b;
}
struct Node *create_node(int data)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int height(struct Node *n)
{
    return (!n) ? 0 : n->height;
}
int getBF(struct Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}
struct Node *left_rot(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
struct Node *right_rot(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return x;
}
struct Node *insert(struct Node *n, int key)
{
    if (n == NULL)
        return create_node(key);
    if (n->data < key)
        n->right = insert(n->right, key);
    else if (n->data > key)
        n->left = insert(n->left, key);
    else
        return n;
    n->height = 1 + max(height(n->left), height(n->right));
    int bf = getBF(n);
    // LL
    if (bf > 1 && key < n->left->data)
        return right_rot(n);
    // RR
    if (bf < -1 && key > n->right->data)
        return left_rot(n);
    // LR
    if (bf > 1 && key > n->left->data)
    {
        n->left = left_rot(n->left);
        return right_rot(n);
    }
    // RL
    if (bf < -1 && key < n->right->data)
    {
        n->right = right_rot(n->right);
        return left_rot(n);
    }
    return n;
}
int isAVL(struct Node *root)
{
    if (root == NULL)
        return 1;
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (abs(left_height - right_height) <= 1 && isAVL(root->left) && isAVL(root->right))
        return 1;
    return 0;
}
struct Node *del(struct Node *root, int key)
{
    if (!root)
        return NULL;
    else if (root->data > key)
        root->left = del(root->left, key);
    else if (root->data < key)
        root->right = del(root->right, key);
    else
    {
        // No child
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        // only left child
        else if (root->left && !root->right)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // only right child
        else if (!root->left && root->right)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        // both child
        else
        {
            struct Node *iPre = root->left;
            while (iPre->right)
            {
                iPre = iPre->right;
            }
            root->data = iPre->data;
            root->left = del(root->left, iPre->data);
        }
    }
    // update height
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getBF(root);
    if (bf > 1)
    {
        // LL
        if (getBF(root->left) >= 0)
            return right_rot(root);
        // LR
        else
        {
            root->left = left_rot(root->left);
            return right_rot(root);
        }
    }
    else if (bf < -1)
    {
        // RR
        if (getBF(root->right) <= 0)
            return left_rot(root);
        // RL
        else
        {
            root->right = right_rot(root->right);
            return left_rot(root);
        }
    }
    else // balanced
        return root;
}
// Given AVL tree
//          33
//       9       53
//    8     21       61
//        11
int main()
{
    struct Node *root = NULL;
    root = insert(root, 33);
    root = insert(root, 9);
    root = insert(root, 53);
    root = insert(root, 8);
    root = insert(root, 21);
    root = insert(root, 61);
    root = insert(root, 11);

    int choice, d;
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Inorder Traversal\n");
    printf("4. Check if AVL\n");
    printf("5. Exit\n");
    printf("Initial AVL Tree (Inorder): ");
    Inorder(root);
    printf("\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &d);
            root = insert(root, d);
            printf("After insertion: ");
            Inorder(root);
            printf("\n");
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &d);
            root = del(root, d);
            printf("After deletion: ");
            Inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Inorder traversal: ");
            Inorder(root);
            printf("\n");
            break;

        case 4:
            if (isAVL(root))
                printf("Yes, AVL tree is balanced\n");
            else
                printf("No, AVL tree is not balanced!\n");
            break;

        case 5:
            Free_tree(root);
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
