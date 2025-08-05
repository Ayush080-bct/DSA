#include <algorithm>
#include <cstdlib>
#include <iostream>

class AvlTree {
    int data;
    AvlTree *left = NULL, *right = NULL, *parent = NULL;
    int height;

   public:
    AvlTree *create_newnode(int val) {
        AvlTree *node = new AvlTree();
        node->data = val;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        node->height = 0;
        std::cout << "Initialize: ";
        std::cout << "Height of " << node->data << " is " << node->height
                  << std::endl;
        return node;
    }
    int getbalance(AvlTree *root) {
        if (root == NULL) return 0;
        int balance_factor = (getheight(root->left) - getheight(root->right));
        if (balance_factor >= -1 && balance_factor <= 1)
            std::cout << "The Tree is balanced! " << std::endl;
        else
            std::cout << "It is Not balanced! " << std::endl;
        return balance_factor;
    }

    int getdata() {
        return data;
    }
    int getheight(AvlTree *root) {
        if (root == NULL)
            return -1;
        else
            return root->height;
    }
    AvlTree *rightrotation(AvlTree *x) {
        AvlTree *y = x->left;
        AvlTree *temp = y->right;

        y->right = x;
        x->left = temp;

        x->height = 1 + std::max(getheight(x->left), getheight(x->right));
        y->height = 1 + std::max(getheight(y->left), getheight(y->right));

        std::cout << "x x x x x After balancing x x x x x " << std::endl;
        std::cout << "          Height of " << x->data << " is " << x->height
                  << std::endl;
        std::cout << "          Height of " << y->data << " is " << y->height
                  << std::endl;
        std::cout << "          Parent of " << x->data << " is " << y->data
                  << std::endl;

        return y;
    }

    AvlTree *leftrotation(AvlTree *x) {
        AvlTree *y = x->right;
        AvlTree *temp = y->left;
        y->left = x;
        x->right = temp;
        x->height = 1 + std::max(getheight(x->left), getheight(x->right));
        y->height = 1 + std::max(getheight(y->left), getheight(y->right));

        std::cout << "x x x x x After balancing x x x x x " << std::endl;
        std::cout << "          Height of " << x->data << " is " << x->height
                  << std::endl;
        std::cout << "          Height of " << y->data << " is " << y->height
                  << std::endl;
        std::cout << "          Parent of " << x->data << " is " << y->data
                  << std::endl;

        return y;
    }
    AvlTree *RightLeftRotation(AvlTree *x) {
        x->right = rightrotation(x->right);
        return leftrotation(x);
    }
    AvlTree *LeftRightRotation(AvlTree *x) {
        x->left = leftrotation(x->left);
        return rightrotation(x);
    }

    AvlTree *Insert_node(AvlTree *root, int val) {
        if (root == NULL) return create_newnode(val);
        if (val == root->data) return root;
        if (root->data > val) {
            root->left = Insert_node(root->left, val);
            root->left->parent = root;
            std::cout << "Parent of " << root->left->data << " Is "
                      << root->data << std::endl;
        } else {
            root->right = Insert_node(root->right, val);
            root->right->parent = root;
            std::cout << "Parent of " << root->right->data << " Is "
                      << root->data << std::endl;
        }
        root->height =
            1 + std::max(getheight(root->left), getheight(root->right));
        std::cout << "Updated: ";
        std::cout << "Height of " << root->data << " is " << root->height
                  << std::endl;
        int balance = getbalance(root);
        if (balance > 1 && val < root->left->data) return rightrotation(root);
        if (balance < -1 && val > root->right->data) return leftrotation(root);
        if (balance < -1 && val < root->right->data)
            return RightLeftRotation(root);
        if (balance > 1 && val > root->left->data)
            return LeftRightRotation(root);
        return root;
    }
    AvlTree *Search(AvlTree *root, int key) {
        if ((root == NULL) || key == root->data)
            return root;
        else if (key < root->data)
            return Search(root->left, key);
        else
            return Search(root->right, key);
    }
    AvlTree *FIND_MAX(AvlTree *root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }
    AvlTree *FIND_MINIMUM(AvlTree *root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    AvlTree *Delete_node(AvlTree *root, int val) {
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
                AvlTree *temp = root->right;
                if (temp) temp->parent = root->parent;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                AvlTree *temp = root->left;
                if (temp) temp->parent = root->parent;
                delete root;
                return temp;
            } else {
                // case 3
                AvlTree *temp = FIND_MINIMUM(root->right);
                root->data = temp->data;
                root->right = Delete_node(root->right, temp->data);
                if (root->right) root->right->parent = root;
            }
        }
        root->height =
            1 + std::max(getheight(root->left), getheight(root->right));
        std::cout << "Updated: ";
        std::cout << "Height of " << root->data << " is " << root->height
                  << std::endl;
        int balance = getbalance(root);
        if (balance > 1 && val < root->left->data) return rightrotation(root);
        if (balance < -1 && val > root->right->data) return leftrotation(root);
        if (balance < -1 && val < root->right->data)
            return RightLeftRotation(root);
        if (balance > 1 && val > root->left->data)
            return LeftRightRotation(root);

        return root;
    }

    void display(AvlTree *root) {
        if (root != NULL) {
            std::cout << "(";

            if (root->left)
                display(root->left);
            else
                std::cout << "NULL";

            std::cout << "<-" << root->data << "->";

            if (root->right)
                display(root->right);
            else
                std::cout << "NULL";
            std::cout << ")";
        } else {
            std::cout << "NULL";
        }
    }
    /*void display(AvlTree *root, int space = 0, int height = 10) {
    if (root == NULL) return;
    space += height;
    display(root->right, space);
    std::cout << std::endl;
    for (int i = height; i < space; i++)
        std::cout << " ";
    std::cout << root->data << "\n";
    display(root->left, space);
}*/
};

int main() {
    AvlTree *root = NULL;
    AvlTree *temp = NULL;
    AvlTree A;
    int a[] = {50, 30, 70, 60, 80, 55};
    int n = sizeof(a) / sizeof(a[0]);
    int choice, element, i;
    while (true) {
        std::cout << "AVLTREE FUNCTIONS: " << std::endl;
        std::cout << "1.INSERT\n2.CREATE\n3.SEARCH\n4.DELETE\n5.DISPLAY\n6."
                     "FIND_MAXIMUM\n7.FIND_MINIMUM\n"
                     "8.EXIT\nENTER "
                     "YOUR CHOICE: ";
        std::cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
                std::cout << "Enter the the element to insert: ";
                std::cin >> element;
                root = A.Insert_node(root, element);
                std::cout << element << " INSERTED! " << std::endl;

                break;
            case 2:
                for (i = 0; i < n; i++) {
                    root = A.Insert_node(root, a[i]);
                }
                std::cout << "ALL ELEMENT INSERTED SUCESSFULLY!" << std::endl;

                break;
            case 3:
                std::cout << "Enter the element to search: ";
                std::cin >> element;
                temp = A.Search(root, element);
                if (temp == NULL)
                    std::cout << element << " Not found!\n ";
                else
                    std::cout << element << " Found!\n ";
                break;
            case 4:
                std::cout << "Enter the element to delete: ";
                std::cin >> element;
                root = A.Delete_node(root, element);
                std::cout << element << " DELETED!" << std::endl;
                break;

                break;
            case 5:
                A.display(root);
                std::cout << std::endl;

                break;
            case 6:
                temp = A.FIND_MAX(root);
                if (temp != NULL) {
                    std::cout << temp->getdata()
                              << " IS THE LARGEST ELEMENT IN TREE "
                              << std::endl;
                }
                break;
            case 7:
                temp = A.FIND_MINIMUM(root);
                if (temp != NULL) {
                    std::cout << temp->getdata()
                              << " IS THE SMALLEST ELEMENT IN TREE "
                              << std::endl;
                }

                break;
            case 8:
                std::cout << "Thank you! " << std::endl;
                exit(0);

                break;

            default:
                std::cout << "Invalid choice ! " << std::endl;
                break;
        }
    }

    return 0;
}
