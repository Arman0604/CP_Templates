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

void levelOrder(Node* root) {

    // if tree is empty
    if(root == NULL) {
        return;
    }

    queue<Node*> q;

    // push root node into queue
    q.push(root);

    while(!q.empty()) {

        // get front node
        Node* current = q.front();
        q.pop();

        // print node value
        cout << current->data << " ";

        // push left child if it exists
        if(current->left != NULL) {
            q.push(current->left);
        }

        // push right child if it exists
        if(current->right != NULL) {
            q.push(current->right);
        }
    }
}
