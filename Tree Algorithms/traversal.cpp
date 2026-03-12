// Structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root) {

    // Base case: if node is NULL, stop recursion
    if(root == NULL) {
        return;
    }

    // Step 1: visit left subtree
    inorder(root->left);

    // Step 2: print current node
    cout << root->data << " ";

    // Step 3: visit right subtree
    inorder(root->right);
}

void preorder(Node* root) {

    // Base case
    if(root == NULL) {
        return;
    }

    // Step 1: print root node
    cout << root->data << " ";

    // Step 2: traverse left subtree
    preorder(root->left);

    // Step 3: traverse right subtree
    preorder(root->right);
}

void postorder(Node* root) {

    // Base case
    if(root == NULL) {
        return;
    }

    // Step 1: traverse left subtree
    postorder(root->left);

    // Step 2: traverse right subtree
    postorder(root->right);

    // Step 3: print root node
    cout << root->data << " ";
}
