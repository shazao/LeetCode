#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

template<typename T>
class ListNode {
  public:
    ListNode * next;
    ListNode(T x) : val(x), next(NULL) {}
    T val;
};

template<typename T>
void printList(ListNode<T> * head) {
  ListNode<T> * node = head;
  while (node) {
    std::cout << node->val << ' ';
    node = node->next;
  }
  std::cout << std::endl;
}

BtNode<char> * buildBinaryTree(int idx)
{
	// 9 BtNode pointers; points to the 9 items in the tree
	BtNode<char> *root, *b, *c, *d, *e, *f, *g, *h, *i,
               *j, *k, *l, *m, *n, *o;

	// parameter n specifies a tree in the range 0 - 2
	switch(idx)
	{
		// nodes d and e are leaf nodes
		case 0:
			d = new BtNode<char> ('D');
			e = new BtNode<char> ('E');
			b = new BtNode<char> ('B',(BtNode<char> *)NULL, d);
			c = new BtNode<char> ('C',e, (BtNode<char> *)NULL);
			root = new BtNode<char> ('A',b, c);
			break;

		// nodes g, h, i, and d are leaf nodes
		case 1:
			g = new BtNode<char> ('G');
			h = new BtNode<char> ('H');
			i = new BtNode<char> ('I');
			d = new BtNode<char> ('D');
			e = new BtNode<char> ('E',g, (BtNode<char> *)NULL);
			f = new BtNode<char> ('F',h, i);
			b = new BtNode<char> ('B',d, e);
			c = new BtNode<char> ('C',(BtNode<char> *)NULL, f);
			root = new BtNode<char> ('A',b, c);
			break;

		// nodes g, h, i and f are leaf nodes
		case 2:
			g = new BtNode<char> ('G');
			h = new BtNode<char> ('H');
			i = new BtNode<char> ('I');
			d = new BtNode<char> ('D',(BtNode<char> *)NULL, g);
			e = new BtNode<char> ('E',h, i);
			f = new BtNode<char> ('F');
			b = new BtNode<char> ('B',d, (BtNode<char> *)NULL);
			c = new BtNode<char> ('C',e, f);
			root = new BtNode<char> ('A',b, c);
			break;

    case 3:
			i = new BtNode<char> ('I');
			h = new BtNode<char> ('H', (BtNode<char> *)NULL, i);
			g = new BtNode<char> ('G', (BtNode<char> *)NULL, h);
			f = new BtNode<char> ('F', (BtNode<char> *)NULL, g);
			e = new BtNode<char> ('E', (BtNode<char> *)NULL, f);
			d = new BtNode<char> ('D', (BtNode<char> *)NULL, e);
			c = new BtNode<char> ('C', (BtNode<char> *)NULL, d);
			b = new BtNode<char> ('B', (BtNode<char> *)NULL, c);
			root = new BtNode<char> ('A', (BtNode<char> *)NULL, b);
      break;

    // A right oblique tree.
    case 4:
			i = new BtNode<char> ('I');
			h = new BtNode<char> ('H', i, (BtNode<char> *)NULL);
			g = new BtNode<char> ('G', h, (BtNode<char> *)NULL);
			f = new BtNode<char> ('F', g, (BtNode<char> *)NULL);
			e = new BtNode<char> ('E', f, (BtNode<char> *)NULL);
			d = new BtNode<char> ('D', e, (BtNode<char> *)NULL);
			c = new BtNode<char> ('C', d, (BtNode<char> *)NULL);
			b = new BtNode<char> ('B', c, (BtNode<char> *)NULL);
			root = new BtNode<char> ('A', b, (BtNode<char> *)NULL);
      break;

    case 5:
			i = new BtNode<char> ('I');
			h = new BtNode<char> ('H', i, (BtNode<char> *)NULL);
			g = new BtNode<char> ('G', h, (BtNode<char> *)NULL);
			f = new BtNode<char> ('F', g, (BtNode<char> *)NULL);
			e = new BtNode<char> ('E', f, (BtNode<char> *)NULL);
			d = new BtNode<char> ('D', e, (BtNode<char> *)NULL);
			c = new BtNode<char> ('C', d, (BtNode<char> *)NULL);
			b = new BtNode<char> ('B', c, (BtNode<char> *)NULL);
			root = new BtNode<char> ('A', (BtNode<char> *)NULL, b);
      break;

    case 6:
			i = new BtNode<char> ('I');
			h = new BtNode<char> ('H', i, (BtNode<char> *)NULL);
			g = new BtNode<char> ('G', h, (BtNode<char> *)NULL);
			f = new BtNode<char> ('F', g, (BtNode<char> *)NULL);
			e = new BtNode<char> ('E', f, (BtNode<char> *)NULL);
			d = new BtNode<char> ('D', e, (BtNode<char> *)NULL);
			c = new BtNode<char> ('C', d, (BtNode<char> *)NULL);
			b = new BtNode<char> ('B', (BtNode<char> *)NULL, c);
			root = new BtNode<char> ('A', (BtNode<char> *)NULL, b);
      break;

    // A complete binary tree.
    case 7:
			i = new BtNode<char> ('I');
			h = new BtNode<char> ('H');
			g = new BtNode<char> ('G');
			f = new BtNode<char> ('F');
			e = new BtNode<char> ('E');
			d = new BtNode<char> ('D', h, i);
			c = new BtNode<char> ('C', f, g);
			b = new BtNode<char> ('B', d, e);
			root = new BtNode<char> ('A', b, c);
      break;

    // A complete binary tree.
    case 8:
			i = new BtNode<char> ('i');
			h = new BtNode<char> ('H');
			g = new BtNode<char> ('G');
			f = new BtNode<char> ('F');
			e = new BtNode<char> ('E');
			d = new BtNode<char> ('D', h, i);
			c = new BtNode<char> ('C', f, g);
			b = new BtNode<char> ('B', d, e);
			root = new BtNode<char> ('A', b, c);
      break;

    // A symmetric binary tree.
    case 9:
			//i = new BtNode<char> ('i');
			//h = new BtNode<char> ('H');
			g = new BtNode<char> ('D');
			f = new BtNode<char> ('E');
			e = new BtNode<char> ('E');
			d = new BtNode<char> ('D');
			c = new BtNode<char> ('B', f, g);
			b = new BtNode<char> ('B', d, e);
			root = new BtNode<char> ('A', b, c);
      break;

    // A not-so-symmetric binary tree.
    case 10:
			//i = new BtNode<char> ('i');
			//h = new BtNode<char> ('H');
			g = new BtNode<char> ('d');
			f = new BtNode<char> ('E');
			e = new BtNode<char> ('E');
			d = new BtNode<char> ('D');
			c = new BtNode<char> ('B', f, g);
			b = new BtNode<char> ('B', d, e);
			root = new BtNode<char> ('A', b, c);
      break;

    // A not-so-symmetric binary tree.
    case 11:
			//i = new BtNode<char> ('i');
			//h = new BtNode<char> ('H');
			g = new BtNode<char> ('E');
			f = new BtNode<char> ('D');
			e = new BtNode<char> ('E');
			d = new BtNode<char> ('D');
			c = new BtNode<char> ('B', f, g);
			b = new BtNode<char> ('B', d, e);
			root = new BtNode<char> ('A', b, c);
      break;

    // A not-so-symmetric binary tree.
    case 12:
			//i = new BtNode<char> ('i');
			//h = new BtNode<char> ('H');
			//g = new BtNode<char> ('E');
			//f = new BtNode<char> ('D');
			e = new BtNode<char> ('D');
			d = new BtNode<char> ('D');
			c = new BtNode<char> ('B', (BtNode<char> *)NULL, e);
			b = new BtNode<char> ('B', (BtNode<char> *)NULL, d);
			root = new BtNode<char> ('A', b, c);
      break;

    // A balanced binary tree.
    case 13:
			//i = new BtNode<char> ('i');
			h = new BtNode<char> ('H');
			g = new BtNode<char> ('G');
			f = new BtNode<char> ('F');
			e = new BtNode<char> ('E', (BtNode<char> *)NULL, h);
			d = new BtNode<char> ('D', g, (BtNode<char> *)NULL);
			c = new BtNode<char> ('C', (BtNode<char> *)NULL, f);
			b = new BtNode<char> ('B', d, e);
			root = new BtNode<char> ('A', b, c);
      break;

    // Another balanced binary tree.
    case 14:
			o = new BtNode<char> ('5', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			n = new BtNode<char> ('5', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			m = new BtNode<char> ('4', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			l = new BtNode<char> ('4', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			k = new BtNode<char> ('4', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			j = new BtNode<char> ('4', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			i = new BtNode<char> ('4', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			h = new BtNode<char> ('4', n, o);
			g = new BtNode<char> ('3', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			f = new BtNode<char> ('3', l, m);
			e = new BtNode<char> ('3', j, k);
			d = new BtNode<char> ('3', h, i);
			c = new BtNode<char> ('2', f, g);
			b = new BtNode<char> ('2', d, e);
			root = new BtNode<char> ('1', b, c);
      break;

    // A not-so-balanced binary tree.
    case 15:
			//i = new BtNode<char> ('i');
			//h = new BtNode<char> ('H');
			//g = new BtNode<char> ('G');
			//f = new BtNode<char> ('F', i, (BtNode<char> *)NULL);
			//e = new BtNode<char> ('E', (BtNode<char> *)NULL, h);
			//d = new BtNode<char> ('D', g, (BtNode<char> *)NULL);
			//c = new BtNode<char> ('C', (BtNode<char> *)NULL, f);
			//b = new BtNode<char> ('B', d, e);
			//root = new BtNode<char> ('A', b, c);
			g = new BtNode<char> ('4', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			f = new BtNode<char> ('4', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			e = new BtNode<char> ('3', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			d = new BtNode<char> ('3', f, g);
			c = new BtNode<char> ('2', (BtNode<char> *)NULL, (BtNode<char> *)NULL);
			b = new BtNode<char> ('2', d, e);
			root = new BtNode<char> ('1', b, c);
      break;

    // A one-node tree.
    default:
			//i = new BtNode<char> ('I');
			//h = new BtNode<char> ('H', i, (BtNode<char> *)NULL);
			//g = new BtNode<char> ('G', h, (BtNode<char> *)NULL);
			//f = new BtNode<char> ('F', g, (BtNode<char> *)NULL);
			//e = new BtNode<char> ('E', f, (BtNode<char> *)NULL);
			//d = new BtNode<char> ('D', e, (BtNode<char> *)NULL);
			//c = new BtNode<char> ('C', d, (BtNode<char> *)NULL);
			//b = new BtNode<char> ('B', c, (BtNode<char> *)NULL);
			root = new BtNode<char> ('A');
      break;
	}

	return root;
}

BtNode<int> * buildIntBinaryTree(int idx) {
	// BtNode pointers; points to the items in the tree
	BtNode<int> *root, *b, *c, *d, *e, *f, *g, *h, *i,
               *j, *k, *l, *m, *n, *o;

	switch(idx)
	{
    // A not-so-balanced binary tree.
    case 0:
			//i = new BtNode<int> ('i');
			//h = new BtNode<int> ('H');
			//g = new BtNode<int> ('G');
			//f = new BtNode<int> ('F', i, (BtNode<int> *)NULL);
			//e = new BtNode<int> ('E', (BtNode<int> *)NULL, h);
			//d = new BtNode<int> ('D', g, (BtNode<int> *)NULL);
			//c = new BtNode<int> ('C', (BtNode<int> *)NULL, f);
			//b = new BtNode<int> ('B', d, e);
			//root = new BtNode<int> ('A', b, c);
			g = new BtNode<int> (4, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			f = new BtNode<int> (4, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			e = new BtNode<int> (3, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			d = new BtNode<int> (3, f, g);
			c = new BtNode<int> (2, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			b = new BtNode<int> (2, d, e);
			root = new BtNode<int> (1, b, c);
      break;

    // A balanced binary tree.
    case 1:
			o = new BtNode<int> (5, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			n = new BtNode<int> (5, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			m = new BtNode<int> (-4, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			l = new BtNode<int> (4, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			k = new BtNode<int> (-2, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			j = new BtNode<int> (-4, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			i = new BtNode<int> (9, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			h = new BtNode<int> (8, n, o);
			g = new BtNode<int> (7, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			f = new BtNode<int> (6, l, m);
			e = new BtNode<int> (5, j, k);
			d = new BtNode<int> (4, h, i);
			c = new BtNode<int> (-3, f, g);
			b = new BtNode<int> (2, d, e);
			root = new BtNode<int> (1, b, c);
      break;

    // A binary search tree.
    case 2:
			o = new BtNode<int> (-7, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			n = new BtNode<int> (-9, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			m = new BtNode<int> (3, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			l = new BtNode<int> (1, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			k = new BtNode<int> (-1, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			j = new BtNode<int> (-3, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			i = new BtNode<int> (-5, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			h = new BtNode<int> (-8, n, o);
			g = new BtNode<int> (5, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			f = new BtNode<int> (2, l, m);
			e = new BtNode<int> (-2, j, k);
			d = new BtNode<int> (-6, h, i);
			c = new BtNode<int> (4, f, g);
			b = new BtNode<int> (-4, d, e);
			root = new BtNode<int> (0, b, c);
      break;

    // Another binary search tree.
    case 3:
			f = new BtNode<int> (4, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			e = new BtNode<int> (3, (BtNode<int> *)NULL, f);
			d = new BtNode<int> (1, (BtNode<int> *)NULL, (BtNode<int> *)NULL);
			c = new BtNode<int> (2, d, e);
			b = new BtNode<int> (5, c, (BtNode<int> *)NULL);
			root = new BtNode<int> (6, b, (BtNode<int> *)NULL);
      break;

    // A one-node tree.
    default:
			//i = new BtNode<int> ('I');
			//h = new BtNode<int> ('H', i, (BtNode<int> *)NULL);
			//g = new BtNode<int> ('G', h, (BtNode<int> *)NULL);
			//f = new BtNode<int> ('F', g, (BtNode<int> *)NULL);
			//e = new BtNode<int> ('E', f, (BtNode<int> *)NULL);
			//d = new BtNode<int> ('D', e, (BtNode<int> *)NULL);
			//c = new BtNode<int> ('C', d, (BtNode<int> *)NULL);
			//b = new BtNode<int> ('B', c, (BtNode<int> *)NULL);
			root = new BtNode<int> (0);
      break;
	}

	return root;
}

template<typename T>
BtNode<T> * findElement(BtNode<T> * root, T element) {
  if (root == NULL)
    return NULL;

  if (root->element() == element)
    return root;
  
  BtNode<T> * l = findElement(root->left(), element);
  if (l) return l;

  BtNode<T> * r = findElement(root->right(), element);
  if (r) return r;

  return NULL;
}

// LeetCode 100.
template<typename T>
bool isSameTree(BtNode<T> * p, BtNode<T> * q) {
  if(p==NULL && q==NULL)
    return true;

  if(p!=NULL && q!=NULL)
    if (p->element()==q->element() && isSameTree(p->left(), q->left()) && isSameTree(p->right(), q->right()))
      return true;
    else
      return false;
  else
    return false;
}

// LeetCode 235.
template<typename T>
BtNode<T> * lowestCommonAncestor(BtNode<T> * root, BtNode<T> * p, BtNode<T> * q) { 
  T rv = root->element();
  T pv = p->element();
  T qv = q->element();

  BtNode<T> * ancestor = root;

  if (rv==pv || rv==qv)
    return root;

  if ((rv>pv && rv<qv) || (rv<qv && rv>qv))
    return root;
  else if (rv > pv)
    ancestor = lowestCommonAncestor(root->left(), p, q);
  else 
    ancestor = lowestCommonAncestor(root->right(), p, q);

  return ancestor;
}

// LeetCode 105
template<typename T>
BtNode<T> * constructBtFromPreorderInorderTraversal(std::vector<T> & preorder, std::vector<T> & inorder,
                                                    size_t l, size_t r, size_t & root_idx) {
  BtNode<T> * parent = new BtNode<T>(preorder[root_idx]);
  int i = l;
  for (; i<r; ++i)
    if (inorder[i] == preorder[root_idx])
      break;
  if (i > l) parent->left() = constructBtFromPreorderInorderTraversal(preorder, inorder, l, i, ++root_idx);
  if (r > i+1) parent->right() = constructBtFromPreorderInorderTraversal(preorder, inorder, i+1, r, ++root_idx);
  return parent;
}

template<typename T>
BtNode<T> * constructBtFromPreorderInorderTraversal(std::vector<T> & preorder, std::vector<T> & inorder) {
  if (preorder.empty() || inorder.empty()) return NULL;
  size_t ps = preorder.size(), is = inorder.size();
  if (ps != is) return NULL;
  size_t root_idx = 0;
  return constructBtFromPreorderInorderTraversal(preorder, inorder, 0, ps, root_idx);
}

// LeetCode 106
template<typename T>
BtNode<T> * constructBtFromInorderAndPostorderTraversal(std::vector<T> & inorder, std::vector<T> & postorder, 
                                                        int l, int r, int & root_idx) {
  T root_value = postorder[root_idx];
  BtNode<T> * root = new BtNode<T>(root_value);
  int i = r;
  for (; i>=0; --i)
    if (inorder[i] == root_value)
      break;
  if (r >= i+1) root->right() = constructBtFromInorderAndPostorderTraversal(inorder, postorder, i+1, r, --root_idx);
  if (i-1 >= l) root->left() = constructBtFromInorderAndPostorderTraversal(inorder, postorder, l, i-1, --root_idx);
  return root;
}

template<typename T>
BtNode<T> * constructBtFromInorderAndPostorderTraversal(std::vector<T> & inorder, std::vector<T> & postorder) {
  if (inorder.empty()) return NULL;
  int root_idx = postorder.size() - 1;
  return constructBtFromInorderAndPostorderTraversal(inorder, postorder, 0, root_idx, root_idx);
}

// LeetCode 108
template<typename T>
BtNode<T> * sortedArrayToBST(std::vector<T> & nums, int l, int r) {
  int m = l + (r-l)/2;
  BtNode<T> * root = new BtNode<T>(nums[m]);
  if (m > l) root->left() = sortedArrayToBST(nums, l, m);
  if (r > m+1) root->right() = sortedArrayToBST(nums, m+1, r);
  return root;
}

template<typename T>
BtNode<T> * sortedArrayToBST(std::vector<T> & nums) {
  if (nums.empty()) return NULL;
  return sortedArrayToBST(nums, 0, nums.size());
}

// LeetCode 109
template<typename T>
BtNode<T> * convertSortedListToBinarySearchTree(ListNode<T> * & inorder_node, size_t len) {
  if (!len) return NULL;
  BtNode<T> * btn = new BtNode<T>(0);
  btn->left() = convertSortedListToBinarySearchTree(inorder_node, len/2);
  btn->element() = inorder_node->val;
  inorder_node = inorder_node->next;
  btn->right() = convertSortedListToBinarySearchTree(inorder_node, len - len/2 -1);
  return btn;
}

template<typename T>
BtNode<T> * convertSortedListToBinarySearchTree(ListNode<T> * head) {
  size_t len = 0;
  ListNode<T> * ln = head;
  while (ln) {
    ++ len;
    ln = ln->next;
  }
  ListNode<T> * inorder_node = head;
  return convertSortedListToBinarySearchTree(inorder_node, len);
}

// LeetCode 114
template<typename T>
void flatten(BtNode<T> * root, BtNode<T> * & previous) {
  if (root) {
    BtNode<T> * right = root->right();
    BtNode<T> * left = root->left();
    if (left == NULL)
      previous = root;
    root->left() = NULL;
    root->right() = left;
    flatten(left, previous);
    previous->right() = right;
    flatten(right, previous);
  }
}

template<typename T>
void flatten(BtNode<T> * root) {
  BtNode<T> * previous = NULL;
  flatten(root, previous);
  return;
}

int main(int argc, char * argv[]) {

  if (argc != 2)
    std::cout << "Argument error! Please input a integer to select a binary tree." << std::endl;

  int tree_idx = atoi(argv[1]);
  size_t node_width_for_display = 2;
  BtNode<char> * bt = buildBinaryTree(tree_idx);

  std::cout << "You selected Binary Tree " << tree_idx << '.' << std::endl;
  bt->displayBinaryTree(node_width_for_display);
  std::cout << "Number of leaves of Binary Tree " << tree_idx << ": " << bt->countLeaf() << '.' << std::endl;
  std::cout << "Depth of Binary Tree " << tree_idx << ": " << bt->depth() << '.' << std::endl;

  BtNode<char> * cbt = bt->copyBinaryTree();
  std::cout << "Copy of Binary Tree " << tree_idx << ": " << std::endl;
  cbt->displayBinaryTree(node_width_for_display);

  std::cout << "Binary Tree " << tree_idx << " and its copy " << (isSameTree(bt, cbt) ? "is" : "is not") << " the same." << std::endl;
  BtNode<char> * nbt = buildBinaryTree(tree_idx+1);
  std::cout << "Binary Tree " << tree_idx << std::endl;
  bt->displayBinaryTree(node_width_for_display);
  std::cout << "and Binary Tree " << tree_idx+1 << std::endl;
  nbt->displayBinaryTree(node_width_for_display);
  std::cout << std::endl << (isSameTree(bt, nbt) ? " is" : " is not") << " the same." << std::endl;

  BtNode<char> * sbt = buildBinaryTree(tree_idx);
  std::cout << "Binary Tree " << tree_idx << std::endl;
  sbt->displayBinaryTree(node_width_for_display);
  std::cout << (sbt->isSymmetric() ? "is" : "is not") << " a symmetric tree." << std::endl;
  std::cout << "Binary Tree " << tree_idx << std::endl;
  sbt->displayBinaryTree(node_width_for_display);
  std::cout << (sbt->isSymmetricIteratively() ? "is" : "is not") << " a symmetric tree(Using iterative method)." << std::endl;

  std::cout << "Traverse Binary Tree " << tree_idx << " by level: ";
  bt->levelOrder();
  std::cout << std::endl;
  std::cout << "Traverse Binary Tree " << tree_idx << " by level(Multiple lines):" << std::endl;
  bt->levelOrder2();
  std::cout << std::endl;
  std::cout << "Traverse Binary Tree " << tree_idx << " by bottom-up level order:" << std::endl;
  bt->levelOrederBottomUp();
  std::cout << std::endl;
  std::cout << "Traverse Binary Tree " << tree_idx << " by zigzag level order(Multiple lines):" << std::endl;
  bt->zigzagLevelOrder();
  std::cout << std::endl;

  std::cout << "Binary Tree " << tree_idx << std::endl;
  bt->displayBinaryTree(node_width_for_display);
  std::cout << (bt->isBalanced() ? "is " : "is not ") << "balanced." << std::endl;
  std::cout << "Binary Tree " << tree_idx << std::endl;
  bt->displayBinaryTree(node_width_for_display);
  std::cout << (bt->isBalanced2() ? "is " : "is not ") << "balanced(Using Method 2)." << std::endl;

  std::cout << "Minimum depth of Binary Tree " << tree_idx << std::endl;
  bt->displayBinaryTree(node_width_for_display);
  std::cout << "is " << bt->minDepth() << '.' << std::endl;

  BtNode<int> * ibt = buildIntBinaryTree(tree_idx);
  int sum = 0;
  std::cout << "Integer Binary Tree " << tree_idx << std::endl;
  ibt->displayBinaryTree(node_width_for_display);
  for (sum=0; sum<=20; ++sum) {
    bool has_path = ibt->hasPathSum(sum);
    std::cout << "has " << (has_path ? "" : "not ") << "a path along which the sum of items is " << sum << "." << std::endl;
    if (has_path) {
      std::cout << "They are: " << std::endl;
      std::vector<std::vector<int> > paths = ibt->pathSum(sum);
      for (size_t i=0; i<paths.size(); ++i) {
        for (size_t j=0; j<paths[i].size(); ++j)
          std::cout << ' ' << paths[i][j];
        std::cout << std::endl;
      }
    }
  }

  std::cout << "Binary Tree inverted form Binary Tree " << tree_idx << std::endl;
  bt->displayBinaryTree(node_width_for_display);
  std::cout << "is:" << std::endl;
  bt->invert();
  bt->displayBinaryTree(node_width_for_display);

  BtNode<int> * ibst = buildIntBinaryTree(2);
  std::cout << "As to integer Binary Search Tree " << '2' << std::endl;
  ibst->displayBinaryTree(node_width_for_display);
  BtNode<int> * p = findElement(ibst, -7);
  BtNode<int> * q = findElement(ibst, -2);
  std::cout << "The lowest common ancestor of " << p->element() << " and " << q->element() << " is " 
            << lowestCommonAncestor(ibst, p, q)->element() << '.' << std::endl;

  // Test in-order iterative traversal.
  std::cout << std::endl;
  for (int i=0; i<16; ++i) {
    BtNode<char> * cbt = buildBinaryTree(i);
    std::cout << "The in-order recursive traversal of a tree: ";
    cbt->inOrder();
    std::cout << "The in-order iterative traversal of the tree: ";
    cbt->inorderIteratively();
    std::cout << "The in-order iterative traversal(2) of the tree: ";
    cbt->inorderIteratively2();
    std::cout << "The in-order iterative traversal(3) of the tree: ";
    cbt->inorderIteratively3();
    std::cout << std::endl;
  }

  // Test a tree is a BST or not.
  std::cout << "Binary Tree: " << std::endl;
  ibst->displayBinaryTree(node_width_for_display);
  std::cout << std::endl << (ibst->isBst() ? "is " : "is not ") << "binary search tree." << std::endl;
  std::cout << (ibst->isBst2() ? "is " : "is not ") << "binary search tree(Method 2)." << std::endl;
  std::cout << (ibst->isBst3() ? "is " : "is not ") << "binary search tree(Method 3)." << std::endl;
  BtNode<int> * ibst2 = buildIntBinaryTree(3);
  std::cout << "Binary Tree: " << std::endl;
  ibst2->displayBinaryTree(node_width_for_display);
  std::cout << std::endl << (ibst2->isBst() ? "is " : "is not ") << "binary search tree." << std::endl;
  std::cout << (ibst2->isBst2() ? "is " : "is not ") << "binary search tree(Method 2)." << std::endl;
  std::cout << (ibst2->isBst3() ? "is " : "is not ") << "binary search tree(Method 3)." << std::endl;

  // Construce Binary Tree from preorder and inorder traversal
  {
    //std::vector<int> preorder({4, 1, 2, 3, 5, 6, 7});
    //std::vector<int> inorder({1, 2, 3, 4, 6, 7, 5});
    std::vector<int> preorder({1, 3, 2, 5, 4});
    std::vector<int> inorder({1, 2, 3, 4, 5});
    std::cout << "From the given preorder and inorder traversal, I guess the binary tree is: " << std::endl;
    BtNode<int> * tibt = constructBtFromPreorderInorderTraversal(preorder, inorder);
    tibt->displayBinaryTree(node_width_for_display);
    std::cout << "Its postorder traversal: "; tibt->postOrder(); std::cout << std::endl;
    tibt->deleteBinaryTree(); tibt = NULL;
  }
  // Construce Binary Tree from postorder and inorder traversal
  {
    std::vector<int> inorder({1, 2, 3, 4, 5});
    std::vector<int> postorder({2, 4, 5, 3, 1});
    std::cout << "From the given postorder and inorder traversal, I guess the binary tree is: " << std::endl;
    BtNode<int> * tibt = constructBtFromInorderAndPostorderTraversal(inorder, postorder);
    if (tibt) {
      tibt->displayBinaryTree(node_width_for_display);
      std::cout << "Its preorder traversal: "; tibt->preOrder(); std::cout << std::endl;
      tibt->deleteBinaryTree(); tibt = NULL;
    }
  }
  // Convert Sorted Array to Binary Search Tree
  {
    std::vector<int> nums({1, 2, 3, 4, 5});
    std::cout << "From the given inorder traversal, I guess the height balanced binary search tree is: " << std::endl;
    BtNode<int> * tibt = sortedArrayToBST(nums);
    if (tibt) {
      tibt->displayBinaryTree(node_width_for_display);
      tibt->deleteBinaryTree(); tibt = NULL;
    }
  }
  // Convert Sorted List to Binary Search Tree
  {
    ListNode<int> * dummy = new ListNode<int>(0);
    ListNode<int> * node = dummy;
    for (int i=0; i<7; ++i) {
      node->next = new ListNode<int>(i);
      node = node->next;
    }
    ListNode<int> * l = dummy->next;
    delete dummy;
    std::cout << "From the given inorder traversal: ";
    printList(l);
    std::cout << "I guess the height balanced binary search tree is: " << std::endl;
    BtNode<int> * tibt = convertSortedListToBinarySearchTree(l);
    if (tibt) {
      tibt->displayBinaryTree(node_width_for_display);
      tibt->deleteBinaryTree(); tibt = NULL;
    }
  }
  // Flatten binary tree to linked list
  {
    BtNode<char> * bt_to_be_flattened = buildBinaryTree(tree_idx);
    std::cout << std::endl << "Flattened " << std::endl;
    bt_to_be_flattened->displayBinaryTree(node_width_for_display);
    std::cout << std::endl << "is " << std::endl;
    flatten(bt_to_be_flattened);
    bt_to_be_flattened->displayBinaryTree(node_width_for_display);
    bt_to_be_flattened->deleteBinaryTree();
  }
  {
    // Sum root to leaf numbers.
    std::cout << "Integer Binary Tree " << tree_idx << std::endl;
    ibt->displayBinaryTree(node_width_for_display);
    std::cout << "sum of whose all paths is: " << ibt->sumPaths() << '(' << ibt->sumPaths2() << ')' << std::endl;
  }


  bt->deleteBinaryTree();
  cbt->deleteBinaryTree();
  ibt->deleteBinaryTree();
  nbt->deleteBinaryTree();
  sbt->deleteBinaryTree();
  ibst->deleteBinaryTree();
  ibst2->deleteBinaryTree();
  return 0;
}
