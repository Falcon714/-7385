#include <bits/stdc++.h>
using namespace std;

struct node {
 int key;
 struct node *left, *right;
};

struct node* newNode(int item) {
 struct node* temp =
 (struct node*)malloc(sizeof(struct node));
 temp->key = item;
 temp->left =
 temp->right = NULL;
 return temp;
}

int findMax(struct node* root)
{
    if (root == NULL)
        return INT_MIN;

    int res = root->key;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}


void inorder(struct node* root) {

 if (root != NULL)
 {
  inorder(root->left);
  cout << root->key;
  inorder(root->right);
 }
}

struct node* insert(struct node* node, int key) {

 if (node == NULL) return newNode(key);
 if (key < node->key) node->left = insert(node->left, key);
 else node->right = insert(node->right, key);
 return node;
}

struct node* minValueNode(struct node* node) {

 struct node* current = node;
 while (current && current->left != NULL)
  current = current->left;

 return current;
}

struct node* deleteNode(struct node* root, int key) {

 if (root == NULL) return root;
 if (key < root->key) root->left = deleteNode(root->left, key);
 else if (key > root->key) root->right = deleteNode(root->right, key);
 else {
  if (root->left==NULL and root->right==NULL)
   return NULL;
  else
  if (root->left == NULL) {
   struct node* temp = root->right;
   free(root);
   return temp;
  }
  else
  if (root->right == NULL) {
   struct node* temp = root->left; free(root);
   return temp;
  }

  struct node* temp = minValueNode(root->right);
  root->key = temp->key;
  root->right = deleteNode(root->right, temp->key);
  }
 return root;
}

int INT(string s)
{
 int p = 0;
 for (int i = 0; i < s.size(); i++)
 {
  p = 10 * p + (s[i] - '0');
 }
 return p;
}

int main() {
 int n=1000000000;
 struct node* root = NULL;
 while (n)
 {
  string s;
  cin >> s;
  if (s == "GET")
  {
   int max_elem = findMax(root);
   cout << max_elem << endl;
   root = deleteNode(root, max_elem);
  }
  else
  {
   root = insert(root, INT(s));
  }
 }

 return 0;
}
