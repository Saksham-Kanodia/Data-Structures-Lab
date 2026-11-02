# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

Node* createTree(){

    int x;
    printf("Enter data(-1 for NULL):- ");
    scanf("%d", x);

    if(x==-1)
    return NULL;

    Node* p = createNode(x);

    printf("Enter data for left child of %d\n", x);
    p-> left = createTree();

    printf("Enter data for right child of %d\n", x);
    p->right = createTree();

    return p;//this is data in preorder. How do do for inorder and postorder?
}

void preorder(Node* root){

    if(root == NULL)
    return;

    printf("%d", root-> data);
    prorder(root->left);
    preorder(root->right);

}

void inorder(Node* root){

    if(root== NULL)
    return;

    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);

}

void postorder(Node* root){

    if(root== NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);

}

void itInorder(Node* root){

    Node* stack [100];
    int top =-1;

    Node* curr = root;

    while(curr!=NULL || top!=-1){

        while(curr!=NULL){
            stack[++top]= curr;
            curr = curr->left;
        }

        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr -> right;
    }
}


void itPostorder(Node* root){

    if(root==NULL)
    return;

    Node* s1[100];
    Node* s2[100];

    int top1=-1, top2=-1;

    s1[top1++]= root;

    while(top1!=-1){

        Node* curr = s1[top1--];
        s2[++top2] = curr;

        if(curr->left!=NULL)
        s1[++top1]=curr->left;

        if(curr->right!=NULL)
        s1[++top1]=curr->right;

    }

    while(top2!=-1){
        printf("%d ",s2[top2--]->data);
    }
}

void itPreorder(Node* root){

    if(root == NULL)
    return;

    Node* stack[100];
    int top=-1;

    stack[++top] = root;

    while(top!=-1){

        Node* curr = stack[top--];
        printf("%d ", curr->data);

        if(curr->right!=NULL)
        stack[++top] = curr->right;

        if(curr->left!=NULL)
        stack[++top] = curr->left;
    }
}

void printParent(Node* root,int data){
    if(root==NULL)
    return root;

    if(root->left->data==data || root->right->data==data){
        printf("Parent of %d is %d", data, root->data);
        return;
    }

    printParent(root->left, data);
    printParent(root->right, data);
}

int height(Node* root){

    if(root==NULL)
    return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh>rh)
    return lh+1;
    else
    return rh+1;
}

int printAncestors(Node* root, int data){
    
    if(root==NULL)
    return 0; 

    if(root->data==data)
    return 1;

    if(printAncestors(root->left, data) || printAncestors(root->right, data)){
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

int countLeafNodes(Node* root){

    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void levelOrder(Node* root){

    if(root==NULL)
    return;

    Node* queue[100];
    int front=0, rear=-1;

    queue[++rear]= root;

    while(front<=rear){

        Node* curr = queue[front++];
        printf("%d ", curr->data);

        if(curr->left!=NULL)
        queue[++rear] = curr->left;

        if(curr->right!=NULL)
        queue[++rear] = curr->right;

    }
}

int main(){

    int choice;
    Node* root = NULL;

    while(1){
        printf("Menu\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Iterative Inorder Traversal\n");
        printf("6. Iterative Preorder Traversal\n");
        printf("7. Iterative Postorder Traversal\n");
        printf("8. Print Parent of a Node\n");
        printf("9. Print Ancestors of a Node\n");
        printf("10. Count Leaf Nodes\n");
        printf("11. Level Order Traversal\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                root = createTree();
                break;

            case 2:
                preorder(root);
                break;

            case 3:
                inorder(root);  
                break;

            case 4:
                postorder(root);
                break;

            case 5:
                itInorder(root);
                break;

            case 6:
                itPreorder(root);
                break;

            case 7:
                itPostorder(root);
                break;

            case 8:
                int data;
                printf("Enter the node value: ");
                scanf("%d", &data);
                printParent(root, data);
                break;

            case 9:
                int data;
                printf("Enter the node value: ");
                scanf("%d", &data);
                printAncestors(root, data);
                break;

            case 10:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;

            case 11:
                levelOrder(root);
                break;

            case 12:
                exit(0);      
        }
    }

    return 0;
}