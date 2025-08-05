#include <cstdlib>
#include <iostream>

class BinaryTree {
    int data;
    BinaryTree *left = NULL;
    BinaryTree *right = NULL;
    BinaryTree *parent = NULL;

   public:
    BinaryTree *Create_Node(int val) {
        BinaryTree *Newnode = new BinaryTree();
        Newnode->data = val;
        Newnode->left = NULL;
        Newnode->right = NULL;
        Newnode->parent = NULL;
        return Newnode;
    }
    void preorder(BinaryTree *root) {
        std::cout << root->data<< " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(BinaryTree *root) {
        std::cout << "Inorder Traversal! " << std::endl;
        if (root != NULL) {
            std::cout << "(";

            if (root->left)
                inorder(root->left);
            else
                std::cout << "NULL";

            std::cout << "<-" << root->data << "->";

            if (root->right)
                inorder(root->right);
            else
                std::cout << "NULL";

            std::cout << ")";
        }
    }

    void postorder(BinaryTree *root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            std::cout << root->data;
        }
    }
    int getdata() {
        return data;
    }
    BinaryTree *Insert(BinaryTree *root, int val) {
        if (root == NULL) root = Create_Node(val);
        if (val < root->data) {
            root->left = Insert(root->left, val);
            root->left->parent = root;
        }
        if (val > root->data) {
            root->right = Insert(root->right, val);
            root->right->parent = root;
        }
        return root;
    }
    BinaryTree *Search(BinaryTree *root, int key) {
        if ((root == NULL) || key == root->data)
            return root;
        else if (key < root->data)
            return Search(root->left, key);
        else
            return Search(root->right, key);
    }
    BinaryTree *FindMax(BinaryTree *root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }
    BinaryTree *FindMin(BinaryTree *root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    BinaryTree *Delete_node(BinaryTree *root, int val) {
        if (root == NULL) return root;
        if (val < root->data) {
            root->left = Delete_node(root->left, val);
            if (root->left) root->left->parent = root;
        } else if (val > root->data) {
            root->right = Delete_node(root->right, val);
            if (root->right) root->right->parent = root;
        } else {
            // case 1 & case 2
            if (root->left == NULL) {
                BinaryTree *temp = root->right;
                if (temp) temp->parent = root->parent;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                BinaryTree *temp = root->left;
                if (temp) temp->parent = root->parent;
                delete root;
                return temp;
            } else {
                // case 3
                BinaryTree *temp = FindMin(root->right);
                root->data = temp->data;
                root->right = Delete_node(root->right, temp->data);
                if (root->right) root->right->parent = root;
            }
        }
        return root;
    }
};

int main(int argc, char *argv[]) {
    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = sizeof(a) / sizeof(a[0]);
    BinaryTree B, *temp;
    BinaryTree *root = NULL;
    int i, element, choice;

    do {
        std::cout << "1.INSERT\n2.CREATE\n3.PREORDER\n4.INORDER\n";
        std::cout << "5.POSTORDER\n6.SEARCH\n7.FIND MAX\n8.FIND MIN\n";
        std::cout << "9.DELETE\n10.EXIT\nEnter your choice ";

        std::cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                std::cout << "Enter the element to insert ";
                std::cin >> element;
                root = B.Insert(root, element);
                std::cout << element << " INSERTED !\n";
                break;
            case 2:
                for (i = 0; i < n; i++) {
                    root = B.Insert(root, a[i]);
                }
                std::cout << "All elements inserted sucessfully! \n";
                break;
            case 3:
                B.preorder(root);
                std::cout << std::endl;
                break;
            case 4:
                B.inorder(root);
                std::cout << std::endl;
                break;
            case 5:
                B.postorder(root);
                std::cout << std::endl;
                break;
            case 6:
                std::cout << "Enter the element to search: ";
                std::cin >> element;
                temp = B.Search(root, element);
                if (temp == NULL)
                    std::cout << element << " Not found!\n ";
                else
                    std::cout << element << " Found!\n ";
                break;
            case 7:
                temp = B.FindMax(root);
                if (temp != NULL) {
                    std::cout << temp->getdata()
                              << " IS THE LARGEST ELEMENT IN BST! "
                              << std::endl;
                }
                break;
            case 8:
                temp = B.FindMin(root);
                if (temp != NULL) {
                    std::cout << temp->getdata()
                              << " IS THE SMALLEST ELEMENT IN BST! "
                              << std::endl;
                }

                break;
            case 9:
                std::cout << "Enter the element to delete: ";
                std::cin >> element;
                root = B.Delete_node(root, element);
                std::cout << element << " DELETED!" << std::endl;
                break;

            case 10:
                std::cout << "Binary Tree succesfully Implemented! \n";
                exit(0);
            default:
                std::cout << "Invalid choice! " << std::endl;
                break;
        }

    } while (choice != 10);

    return 0;
}