#include <iostream>
#include <algorithm>
using namespace std;

// Định nghĩa cấu trúc TreeNode
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef TreeNode *Tree;

// Hàm tạo node mới
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Hàm chèn node mới vào TREE
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Hàm tìm node nhỏ nhất trong cây con phải
void FindAndReplace1(struct TreeNode* &p, Tree &tree) {
    if (tree->left)
        FindAndReplace1(p, tree->left);
    else {
        p->data = tree->data;
        p = tree;
        tree = tree->right;
    }
}

// Hàm tìm node lớn nhất trong cây con trái
void FindAndReplace2(struct TreeNode* &p, Tree &tree) {
    if (tree->right)
        FindAndReplace2(p, tree->right);
    else {
        p->data = tree->data;
        p = tree;
        tree = tree->left;
    }
}

// Hàm xóa node từ TREE
void DeleteNode(Tree &root, int x) {
    if (root) {
        if (x > root->data)
            DeleteNode(root->right, x);
        else if (x < root->data)
            DeleteNode(root->left, x);
        else {
            TreeNode *p = root;
            if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else
                FindAndReplace1(p, root->right); // Tìm và thay thế bằng cách 1
                // FindAndReplace2(p, root->left); // Tìm và thay thế bằng cách 2
            delete p;
        }
    }
    else {
        cout << "Not found!\n";
    }
}

// Duyệt cây theo thứ tự trước (Preorder)
void PreorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

// Duyệt cây theo thứ tự giữa (Inorder)
void InorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }
}

// Duyệt cây theo thứ tự sau (Postorder)
void PostorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Tính chiều cao của cây
int Height(struct TreeNode* tree) {
    if (tree == NULL)
        return 0;
    int heightLeft = Height(tree->left);
    int heightRight = Height(tree->right);
    return 1 + max(heightLeft, heightRight);
}

// Đếm số lá của cây
int CountLeaf(struct TreeNode* tree) {
    if (tree == NULL)
        return 0;
    if (tree->left == NULL && tree->right == NULL)
        return 1;
    return CountLeaf(tree->left) + CountLeaf(tree->right);
}

// Tính kích thước của cây (số lượng node)
int TreeSize(struct TreeNode* tree) {
    if (tree == NULL)
        return 0;
    return TreeSize(tree->left) + TreeSize(tree->right) + 1;
}

// Xóa toàn bộ cây
void DeleteTree(struct TreeNode* tree) {
    if (tree != NULL) {
        DeleteTree(tree->left);
        DeleteTree(tree->right);
        free(tree);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int option, value;

    do {
        // Hiển thị menu
        cout << "1. Tao Cay"<<endl;
        cout << "2. Them nut vao cay"<<endl;
        cout << "3. Xoa 1 nut"<<endl;;
        cout << "4. Duyet theo thu tu truoc"<<endl;
        cout << "5. Duyet theo thu tu giua"<<endl;
        cout << "6. Duyet theo thu tu sau"<<endl;
        cout << "7. Do cao cua cay"<<endl;
        cout << "8. Dem so nut la"<<endl;
        cout << "9. Kich thuoc cua cay"<<endl;
        cout << "10. Xoa cay"<<endl;
        cout << "11. Thoat"<<endl;
        cout << "Vui long chon option: "<<endl;
        cin >> option;

        switch (option) {
            case 1:
                DeleteTree(root); // Xóa cây cũ (nếu có)
                root = NULL; // Khởi tạo cây mới
                cout << "Tao cay thanh cong"<<endl;
                break;
            case 2:
                cout << "Nhap nut can them: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Them nut thanh cong"<<endl;
                break;
            case 3:
                cout << "Nhap nut can xoa: ";
                cin >> value;
                DeleteNode(root, value);
                break;
            case 4:
                cout << "Duyet theo thu tu truoc: ";
                PreorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Duyet theo thu tu giua: ";
                InorderTraversal(root);
                cout << endl;
                break;
            case 6:
                cout << "Duyet theo thu tu sau: ";
                PostorderTraversal(root);
                cout << endl;
                break;
            case 7:
                cout << "Chieu cao cua cay: " << Height(root) << endl;
                break;
            case 8:
                cout << "Tong so nut la cua cay la: " << CountLeaf(root) << endl;
                break;
            case 9:
                cout << "Kich thuoc cua cay: " << TreeSize(root) << endl;
                break;
            case 10:
                DeleteTree(root);
                root = NULL;
                cout << "Xoa cay thanh cong"<<endl;
                break;
            case 11:
                cout << "Thoat...";
                break;
            default:
                cout << "Lua chon khong hop le. Please try again.";
        }
    } while (option != 11);

    return 0;
}

/*
    backtest cây với câu truc sau;
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 14);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 13);
*/