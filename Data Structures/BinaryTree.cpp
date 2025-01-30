//Course Data Structures - PPU - Dr. Zein Salah
//BY:A7mad_Joba 

#include <iostream>
using namespace std;

struct Node
{
  int value;
  Node *Left;
  Node *Right;
};
typedef Node *nodeptr;

class Binary_Tree
{
public:
  Binary_Tree()
  {
    root = NULL;
  }
  ~Binary_Tree()
  {
    deleteTree(root);
  }
  void createBST(nodeptr &root);
  void insertIntoBST(nodeptr &root, int val);
  void traverseInOrder(nodeptr root);
  void traversePreOrder(nodeptr root);
  void traversePostOrder(nodeptr root);
  int countNode(nodeptr root);
  int countNodeEven(nodeptr root);
  int depth(nodeptr root);
  void searchBST(nodeptr root, int key, nodeptr &pos);
  nodeptr searchBST_NonRecursive(nodeptr root, int key);
  nodeptr minElementInBST(nodeptr root);
  nodeptr maxElementInBST(nodeptr root);
  void deleteTree(nodeptr root);

private:
  nodeptr root;
};

void Binary_Tree::insertIntoBST(nodeptr &root, int val)
{
  if (root == NULL)
  {
    root = new Node();
    root->value = val;
    root->Left = NULL;
    root->Right = NULL;
  }
  else if (val <= root->value)
  {
    insertIntoBST(root->Left, val);
  }
  else
  {
    insertIntoBST(root->Right, val);
  }
}

void Binary_Tree::createBST(nodeptr &root)
{
  int val;
  cin >> val;
  while (val != 0)
  {
    insertIntoBST(root, val);
    cin >> val;
  }
}

void Binary_Tree::traverseInOrder(nodeptr root)
{
  if (root != NULL)
  {
    traverseInOrder(root->Left);
    cout << root->value << " ";
    traverseInOrder(root->Right);
  }
}

void Binary_Tree::traversePreOrder(nodeptr root)
{
  if (root != NULL)
  {
    cout << root->value << " ";
    traversePreOrder(root->Left);
    traversePreOrder(root->Right);
  }
}

void Binary_Tree::traversePostOrder(nodeptr root)
{
  if (root != NULL)
  {
    traversePostOrder(root->Left);
    traversePostOrder(root->Right);
    cout << root->value << " ";
  }
}

int Binary_Tree::countNode(nodeptr root)
{
  if (root == NULL)
  {
    return 0;
  }
  return 1 + countNode(root->Left) + countNode(root->Right);
}

int Binary_Tree::countNodeEven(nodeptr root)
{
  if (root == NULL)
  {
    return 0;
  }
  int even = (root->value % 2 == 0) ? 1 : 0;
  return even + countNodeEven(root->Left) + countNodeEven(root->Right);
}

int Binary_Tree::depth(nodeptr root)
{
  if (root == NULL)
  {
    return -1;
  }
  return 1 + max(depth(root->Left), depth(root->Right));
}

void Binary_Tree::searchBST(nodeptr root, int key, nodeptr &pos)
{
  if (root == NULL)
  {
    pos = NULL;
  }
  else if (root->value == key)
  {
    pos = root;
  }
  else if (key < root->value)
  {
    searchBST(root->Left, key, pos);
  }
  else
  {
    searchBST(root->Right, key, pos);
  }
}

nodeptr Binary_Tree::searchBST_NonRecursive(nodeptr root, int key)
{
  while (root != NULL)
  {
    if (key == root->value)
    {
      return root;
    }
    else if (key < root->value)
    {
      root = root->Left;
    }
    else
    {
      root = root->Right;
    }
  }
  return NULL;
}

// Minimum element in BST
nodeptr Binary_Tree::minElementInBST(nodeptr root)
{
  if (root == NULL)
    return NULL;
  while (root->Left != NULL)
  {
    root = root->Left;
  }
  return root;
}

nodeptr Binary_Tree::maxElementInBST(nodeptr root)
{
  if (root == NULL)
    return NULL;
  while (root->Right != NULL)
  {
    root = root->Right;
  }
  return root;
}

void Binary_Tree::deleteTree(nodeptr root)
{
  if (root == NULL)
  {
    return;
  }
  deleteTree(root->Left);
  deleteTree(root->Right);
  delete root;
}

int main()
{
  Binary_Tree tree;
  nodeptr root = NULL;

  cout << "Enter values to create BST (end with 0):" << endl;
  tree.createBST(root);

  cout << "In-order Traversal: ";
  tree.traverseInOrder(root);
  cout << endl;

  cout << "Pre-order Traversal: ";
  tree.traversePreOrder(root);
  cout << endl;

  cout << "Post-order Traversal: ";
  tree.traversePostOrder(root);
  cout << endl;

  cout << "Number of nodes: " << tree.countNode(root) << endl;
  cout << "Number of even nodes: " << tree.countNodeEven(root) << endl;
  cout << "Depth of the tree: " << tree.depth(root) << endl;

  int key;
  cout << "Enter a value to search in the BST: ";
  cin >> key;

  nodeptr foundNode = NULL;
  tree.searchBST(root, key, foundNode);
  if (foundNode != NULL)
  {
    cout << "Value " << key << " found in BST." << endl;
  }
  else
  {
    cout << "Value " << key << " not found in BST." << endl;
  }

  return 0;
}