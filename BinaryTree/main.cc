#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

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
  for (sum=0; sum<=20; ++sum)
    std::cout << "has " << (ibt->hasPathSum(sum) ? "" : "not ") << "a path along which the sum of items is " << sum << "." << std::endl;

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

  bt->deleteBinaryTree();
  cbt->deleteBinaryTree();
  nbt->deleteBinaryTree();
  sbt->deleteBinaryTree();
  ibst->deleteBinaryTree();
  ibst2->deleteBinaryTree();
  return 0;
}
