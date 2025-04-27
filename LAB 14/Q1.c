#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3
#define MIN 2

struct Node
{
    int val[MAX + 1];
    int count;
    struct Node *link[MAX + 1];
};

struct Node *root;

void deleteVal(struct Node *node, int k);

struct Node *createNode(int val, struct Node *child)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val[1] = val;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}

void insertIntoNode(int val, int pos, struct Node *node, struct Node *child)
{
    int j = node->count;
    while (j > pos)
    {
        node->val[j + 1] = node->val[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->val[j + 1] = val;
    node->link[j + 1] = child;
    node->count++;
}

void splitNode(int val, int *pval, int pos, struct Node *node, struct Node *child, struct Node **newNode)
{
    int median, j;

    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *newNode = (struct Node *)malloc(sizeof(struct Node));
    j = median + 1;
    while (j <= MAX)
    {
        (*newNode)->val[j - median] = node->val[j];
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*newNode)->count = MAX - median;

    if (pos <= MIN)
    {
        insertIntoNode(val, pos, node, child);
    }
    else
    {
        insertIntoNode(val, pos - median, *newNode, child);
    }
    *pval = node->val[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;
}

int setValueInNode(int val, int *pval, struct Node *node, struct Node **child)
{
    int pos;
    if (!node)
    {
        *pval = val;
        *child = NULL;
        return 1;
    }

    if (val < node->val[1])
    {
        pos = 0;
    }
    else
    {
        for (pos = node->count; (val < node->val[pos] && pos > 1); pos--)
            ;
        if (val == node->val[pos])
        {
            printf("Duplicates not allowed\n");
            return 0;
        }
    }

    if (setValueInNode(val, pval, node->link[pos], child))
    {
        if (node->count < MAX)
        {
            insertIntoNode(*pval, pos, node, *child);
        }
        else
        {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

void insert(int val)
{
    int flag, i;
    struct Node *child;

    flag = setValueInNode(val, &i, root, &child);
    if (flag)
        root = createNode(i, child);
}

void search(int val, int *pos, struct Node *myNode)
{
    if (!myNode)
    {
        printf("Key not found\n");
        return;
    }

    if (val < myNode->val[1])
    {
        *pos = 0;
    }
    else
    {
        for (*pos = myNode->count; (val < myNode->val[*pos] && *pos > 1); (*pos)--)
            ;
        if (val == myNode->val[*pos])
        {
            printf("%d is found\n", val);
            return;
        }
    }
    search(val, pos, myNode->link[*pos]);
    return;
}

void traversal(struct Node *myNode)
{
    int i;
    if (myNode)
    {
        for (i = 0; i < myNode->count; i++)
        {
            traversal(myNode->link[i]);
            printf("%d ", myNode->val[i + 1]);
        }
        traversal(myNode->link[i]);
    }
}

int getPredecessor(struct Node *node, int index)
{
    struct Node *cur = node->link[index];
    while (!cur->link[cur->count])
        cur = cur->link[cur->count];
    return cur->val[cur->count];
}

int getSuccessor(struct Node *node, int index)
{
    struct Node *cur = node->link[index + 1];
    while (!cur->link[0])
        cur = cur->link[0];
    return cur->val[1];
}

void mergeNodes(struct Node *node, int idx)
{
    struct Node *child = node->link[idx];
    struct Node *sibling = node->link[idx + 1];

    child->val[MIN] = node->val[idx + 1];

    for (int i = 1; i <= sibling->count; i++)
        child->val[i + MIN] = sibling->val[i];

    if (!child->link[0])
    {
        for (int i = 0; i <= sibling->count; i++)
            child->link[i + MIN] = sibling->link[i];
    }

    for (int i = idx + 1; i < node->count; i++)
    {
        node->val[i] = node->val[i + 1];
        node->link[i] = node->link[i + 1];
    }

    child->count += sibling->count + 1;
    node->count--;
    free(sibling);
}

void borrowFromPrev(struct Node *node, int idx)
{
    struct Node *child = node->link[idx];
    struct Node *sibling = node->link[idx - 1];

    for (int i = child->count; i > 0; i--)
    {
        child->val[i + 1] = child->val[i];
        child->link[i + 1] = child->link[i];
    }

    child->val[1] = node->val[idx];
    child->link[1] = child->link[0];
    child->link[0] = sibling->link[sibling->count];

    node->val[idx] = sibling->val[sibling->count];
    child->count++;
    sibling->count--;
}

void borrowFromNext(struct Node *node, int idx)
{
    struct Node *child = node->link[idx];
    struct Node *sibling = node->link[idx + 1];

    child->val[child->count + 1] = node->val[idx + 1];
    child->link[child->count + 1] = sibling->link[0];

    node->val[idx + 1] = sibling->val[1];

    for (int i = 1; i < sibling->count; i++)
    {
        sibling->val[i] = sibling->val[i + 1];
        sibling->link[i - 1] = sibling->link[i];
    }
    sibling->link[sibling->count - 1] = sibling->link[sibling->count];
    sibling->count--;
    child->count++;
}

void deleteFromLeaf(struct Node *node, int idx)
{
    // Shift only values, not links (leaf nodes don't use links)
    for (int i = idx; i < node->count; i++)
    {
        node->val[i] = node->val[i + 1];
    }
    node->count--;
}

void deleteFromNonLeaf(struct Node *node, int idx)
{
    int k = node->val[idx];
    if (node->link[idx]->count >= MIN)
    {
        int pred = getPredecessor(node, idx);
        node->val[idx] = pred;
        deleteVal(node->link[idx], pred);
    }
    else if (node->link[idx + 1]->count >= MIN)
    {
        int succ = getSuccessor(node, idx);
        node->val[idx] = succ;
        deleteVal(node->link[idx + 1], succ);
    }
    else
    {
        mergeNodes(node, idx);
        deleteVal(node->link[idx], k);
    }
}

void deleteVal(struct Node *node, int k)
{
    int idx;

    // Debug print
    printf("Checking node with keys: ");
    for (int i = 1; i <= node->count; i++) {
        printf("%d ", node->val[i]);
    }
    printf("\n");

    // Find the index of the key
    for (idx = 1; idx <= node->count && node->val[idx] < k; ++idx);

    // If key is found
    if (idx <= node->count && node->val[idx] == k)
    {
        if (!node->link[0])
        {
            deleteFromLeaf(node, idx);
        }
        else
        {
            deleteFromNonLeaf(node, idx);
        }
        return;
    }

    // If key is not found and we're at a leaf node
    if (!node->link[0])
    {
        printf("The key %d is not present in the tree\n", k);
        return;
    }

    // Whether the key is possibly in the last child
    bool flag = ((idx == node->count + 1) ? true : false);

    // If child to descend into has less than MIN keys, fix it
    if (node->link[idx - 1]->count < MIN)
    {
        if (idx > 1 && node->link[idx - 2]->count >= MIN)
        {
            borrowFromPrev(node, idx - 1);
        }
        else if (idx <= node->count && node->link[idx]->count >= MIN)
        {
            borrowFromNext(node, idx - 1);
        }
        else
        {
            if (idx != node->count + 1)
                mergeNodes(node, idx - 1);
            else
            {
                mergeNodes(node, idx - 2);
                idx--; // this is **CRUCIAL** to avoid invalid memory access
            }
        }
    }

    // Recurse only if the root still exists
    if (root)
        deleteVal(node->link[idx - 1], k);
}

void deleteKey(int k)
{
    if (!root)
    {
        printf("Tree is empty\n");
        return;
    }

    deleteVal(root, k);

    if (root->count == 0)
    {
        struct Node *tmp = root;
        if (!root->link[0])
            root = NULL;
        else
            root = root->link[0];
        free(tmp);
    }
}

int main()
{
    int val, ch;
    insert(20), insert(40);
    insert(10), insert(30), insert(33), insert(50), insert(60);
    insert(5), insert(15), insert(25), insert(28), insert(31), insert(35), insert(45), insert(55), insert(65);
    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Traversal\n4. Delete \n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter your data of key to be inserted : ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            printf("Enter the element to search: ");
            scanf("%d", &val);
            int pos;
            search(val, &pos, root);
            break;
        case 3:
            printf("B-Tree traversal: ");
            traversal(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting..");
            exit(0);
        default:
            printf("Invalid option\n");
            break;
        case 4:
            printf("Enter the element to delete: ");
            scanf("%d", &val);
            deleteKey(val);
            break;
        }
    }
    return 0;
}
