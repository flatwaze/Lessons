struct node{
    double data;
    int count;
    struct node* left;
    struct node* right;
};

struct node* addToTree(struct node* root, double newData)
{
    if (root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));

        root->data = newData;

        root->left = NULL;
        root->right = NULL;
        root->count = 1;
        return root;
    }

    double curData = root->data;

    if (curData < newData)
        root->right = addToTree(root->right, newData);

    else if (curData > newData)
        root->left = addToTree(root->left, newData);

    else
        root->count++;

    return root;
}

void printTree(struct node* root) {
    if (root == NULL) return;
    
    printTree(root->left);
    for (int i = 0; i < root->count; i++) printf("%lf ", root->data);
    printTree(root->right);
}
