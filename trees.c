//Binary Search Tree is only fast if the tree is fairly balanced
// time complexity for searching an element is O(log(n))
// ways to implement BST that take care of situations where the tree would otherwise not end up being well balanced such as if the data is already sorted, it would mostly look like a normal linked list not a tree: AVL, red & black tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *createnode(int value) {
    treenode* result = malloc(sizeof(treenode));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printtabs(int numtabs) {
    for (int i=0; i<numtabs; i++) {
        printf("\t");
    }
}

void printtree_rec(treenode *root, int level) {
    if (root == NULL) {
        printtabs(level);
        printf("---<empty>--\n");
        return;
    }
    // pre-order traversal used here, could have used post-order
    printtabs(level);
    printf("value = %d\n", root->value);
    printtabs(level);
    printf("left\n");

    printtree_rec(root->left, level+1);
    printtabs(level);
    printf("right\n");

    printtree_rec(root->right, level+1);

    printtabs(level);
    printf("done\n");
    
}

void printtree(treenode* root) {
    printtree_rec(root, 0);
}

bool insertnumber(treenode **rootptr, int value) {
    treenode *root = *rootptr;
    if (root == NULL) { // first base case
        //tree empty
        (*rootptr) = createnode(value);
        return true;
    }
    if (value == root->value) { //second base base
        //do nothing
        return false;
    }

    //now the 2 recursive cases we have
    if (value < root->value) {
        return insertnumber(&(root->left), value);
    } else {
        return insertnumber(&(root->right), value);
    }
}

bool findnumber(treenode * root, int value) { // no double ptr needed this time because we're not changing the tree in any way in this function, so single ptr should suffice
    if (root == NULL) return false; //1st base case
    if (root->value == value) { //2nd base case
        return true;
    }
    
    //recursive cases
    if (value < root->value) {
        return findnumber(root->left, value);
    } else {
        return findnumber(root->right, value);
    }
}

int main() {
    
    treenode *root = NULL;

    insertnumber(&root, 15);
    insertnumber(&root, 11);
    insertnumber(&root, 24);
    insertnumber(&root, 5);
    insertnumber(&root, 19);
    insertnumber(&root, 16);

    printtree(root); 

    printf("%d (%d)\n", 16, findnumber(root, 16));
    printf("%d (%d)\n", 15, findnumber(root, 15));
    printf("%d (%d)\n", 5, findnumber(root, 5));
    printf("%d (%d)\n", 115, findnumber(root, 115));
    printf("%d (%d)\n", 1, findnumber(root, 1));
    printf("%d (%d)\n", 7, findnumber(root, 7));

}