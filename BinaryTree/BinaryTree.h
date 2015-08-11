#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <queue>
#include <stack>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>

class ShadowBtNode {
  public:
    ShadowBtNode() { }
    ShadowBtNode(std::string formatted_element, int level, int column, ShadowBtNode * left=NULL, ShadowBtNode * right=NULL)
      : formatted_element_(formatted_element), level_(level), column_(column), left_(left), right_(right) { }

    std::string formatted_element_;
    int level_;
    int column_;
    ShadowBtNode * left_;
    ShadowBtNode * right_;
};

template <typename T>
class BtNode {        // Don't need "<T>".
  public:
    BtNode(const T & element, BtNode * left=NULL, BtNode * right=NULL)     // Don't need "<T>".
      : element_(element), left_(left), right_(right) { };
    const T & element() const { return element_; }
    BtNode * left() const { return left_; }      // Don't need "<T>". 
    BtNode * right() const { return right_; }     // Don't need "<T>". 
    BtNode * & left() { return left_; }      // Don't need "<T>". 
    BtNode * & right() { return right_; }     // Don't need "<T>". 

    int countLeaf();
    BtNode * copyBinaryTree();
    void deleteBinaryTree();    // Set 'this' to NULL is client's responsibility.
    void displayBinaryTree(size_t node_width);    // node_width is the maximum width of the nodes' element.
    void levelOrder();
    bool isSymmetric();
    bool isSymmetricIteratively();
    void levelOrder2();     // Output multiple lines.
    int depth();
    void levelOrederBottomUp();
    bool isBalanced();
    bool isBalanced2();
    int minDepth();
    bool hasPathSum(int sum);
    void invert();

  private:
    void countLeaf(BtNode * btn, int & count);
    BtNode * copyBinaryTree(BtNode * btn);
    void deleteBinaryTree(BtNode * btn);    // Set 'this' to NULL is client's responsibility.
    ShadowBtNode * buildShadowBinaryTree(BtNode * btn, int level, int & column);
    void deleteShadowBinaryTree(ShadowBtNode * sbt);
    bool isMirrorTree(BtNode * p, BtNode * q);
    int depth(BtNode * btn);
    bool isBalanced(BtNode * btn);
    bool isBalanced2(BtNode * btn, int & height);
    int minDepth(BtNode * btn);
    bool hasPathSum(BtNode * btn, int sum);
    BtNode * invert(BtNode * btn);

    T element_;
    BtNode * left_;      // Don't need "<T>". 
    BtNode * right_;     // Don't need "<T>". 
};

template<typename T>
int BtNode<T>::countLeaf() {
  int count = 0;
  countLeaf(this, count);
  return count;
}

template<typename T>
void BtNode<T>::countLeaf(BtNode<T> * btn, int & count) {
  if (btn == NULL)
    return;

  if (btn->left()==NULL && btn->right()==NULL)
    ++ count;
  else {
    countLeaf(btn->left(), count);
    countLeaf(btn->right(), count);
  }
}

template<typename T>
int BtNode<T>::depth() {
  return depth(this);
}

template<typename T>
BtNode<T> * BtNode<T>::copyBinaryTree() {
  return copyBinaryTree(this);
}

template<typename T>
BtNode<T> * BtNode<T>::copyBinaryTree(BtNode<T> * btn) {
  if (btn == NULL)
    return NULL;

  BtNode<T> * new_left = copyBinaryTree(btn->left());
  BtNode<T> * new_right = copyBinaryTree(btn->right());

  BtNode<T> * new_btn = new BtNode<T>(btn->element(), new_left, new_right);

  return new_btn;
}

template<typename T>
void BtNode<T>::deleteBinaryTree() {
  deleteBinaryTree(this);
}

template<typename T>
void BtNode<T>::deleteBinaryTree(BtNode<T> * btn) {
  if (btn != NULL) {
    deleteBinaryTree(btn->left());
    deleteBinaryTree(btn->right());
    delete btn;
  }
}

template<typename T>
void BtNode<T>::displayBinaryTree(size_t node_width) {
  int column_for_sbt = 0;
  ShadowBtNode * sbt = buildShadowBinaryTree(this, 0, column_for_sbt);

  int level = 0;
  int column = 0;

  std::queue<ShadowBtNode*> q;
  q.push(sbt);
  while (q.empty() == false) {
    ShadowBtNode * sbtn = q.front();
    q.pop();

    //std::cout << sbtn->formatted_element_ << sbtn->level_ << " " << sbtn->column_ << std::endl;
    if (sbtn->level_ > level) {
      std::cout << std::endl;
      ++ level;
      column = 0;
    }

    if (sbtn->column_ > column) {
      std::cout << std::setw((sbtn->column_ - column) * (node_width+1)) << " ";
      column = sbtn->column_;
    }
    std::cout << std::setw(node_width+1) << sbtn->formatted_element_;

    ++ column;

    if (sbtn->left_ != NULL)
      q.push(sbtn->left_);
    if (sbtn->right_ != NULL)
      q.push(sbtn->right_);
  }

  std::cout << std::endl;
  deleteShadowBinaryTree(sbt);
}

// Key: Figure out how to calculate column.
// Method below is not so elegant and a little obscure, a better one is at bottom of the file.
template<typename T>
ShadowBtNode * BtNode<T>::buildShadowBinaryTree(BtNode<T> * btn, int level, int & column) {
  if (btn == NULL)
    return  NULL;

  ShadowBtNode * new_sbt = new ShadowBtNode;
  std::stringstream ss;
  ss << btn->element();
  new_sbt->formatted_element_ = ss.str();
  new_sbt->level_ = level;

  ShadowBtNode * new_left = buildShadowBinaryTree(btn->left(), level+1, column);

  if (new_left != NULL)
    ++ column;
  new_sbt->column_ = column;
  new_sbt->left_ = new_left;
  ++ column;

  ShadowBtNode * new_right = buildShadowBinaryTree(btn->right(), level+1, column);
  if (new_right == NULL)
    -- column;
  new_sbt->right_ = new_right;

  return new_sbt;
}

template <typename T>
void BtNode<T>::deleteShadowBinaryTree(ShadowBtNode * sbt) {
  if (sbt != NULL) {
    deleteShadowBinaryTree(sbt->left_);
    deleteShadowBinaryTree(sbt->right_);
    delete(sbt);
  }
}

template<typename T>
void BtNode<T>::levelOrder() {
  // "this" is surely not null.
  std::queue<BtNode<T>*> q;
  q.push(this);
  while (q.empty() == false) {
    BtNode<T> * btn = q.front();
    q.pop();

    std::cout << btn->element() << " ";

    if (btn->left())
      q.push(btn->left());
    if (btn->right())
      q.push(btn->right());
  }
}

template <typename T>
bool BtNode<T>::isMirrorTree(BtNode<T> * p, BtNode<T> * q) {
  if (p==NULL && q==NULL)
    return true;

  if (p!=NULL && q!=NULL)
    if (p->element()==q->element() && isMirrorTree(p->left(), q->right()) && isMirrorTree(p->right(), q->left()))
      return true;
    else
      return false;
  else
    return false;

}

// LeetCode 101: Version 0.
template<typename T>
bool BtNode<T>::isSymmetric() {
  if (isMirrorTree(this->left(), this->right()))
    return true;
}

// LeetCode 101: Version 1.
template<typename T>
bool BtNode<T>::isSymmetricIteratively() {
  //if (root == NULL)
  //  return true;

  std::queue<BtNode<T>*> ql;
  std::queue<BtNode<T>*> qr;
  ql.push(this->left());
  qr.push(this->right());
  while (ql.empty()==false && qr.empty()==false) {
    BtNode<T> * nl = ql.front();
    ql.pop();
    BtNode<T> * nr = qr.front();
    qr.pop();
    if (nl!=NULL && nr!=NULL)
      if (nl->element() == nr->element()) {
        ql.push(nl->left());
        ql.push(nl->right());

        qr.push(nr->right());
        qr.push(nr->left());
      } else
        return false;
    else if (!(nl==NULL && nr==NULL))
      return false;
  }

  if (ql.empty()==true && qr.empty()==true)
    return true;
  else
    return false;
}

// LeetCode 102.
template<typename T>
void BtNode<T>::levelOrder2() {

  std::queue<BtNode<T>*> q;
  q.push(this);
  q.push(NULL);

  while (q.empty() == false) {
    BtNode<T> * btn = q.front();
    q.pop();

    std::cout << btn->element() << " ";

    if (q.front() == NULL)
      std::cout << std::endl;

    if (btn->left())
      q.push(btn->left());
    if (btn->right())
      q.push(btn->right());

    if (q.front() == NULL)
      if (q.size() == 1)
        break;
      else {
        q.pop();
        q.push(NULL);
      }
  }
}

// LeetCode 104.
template <typename T>
int BtNode<T>::depth(BtNode<T> * btn) {
  if (btn == NULL)
    return -1;

  int left_depth = depth(btn->left());
  int right_depth = depth(btn->right());
  int depth = left_depth>right_depth ? left_depth : right_depth;
  return ++depth;
}

// LeetCode 107.
template<typename T>
void BtNode<T>::levelOrederBottomUp() {

  std::stack<BtNode<T>*> stk;
  stk.push(NULL);
  stk.push(this);
  stk.push(NULL);

  std::queue<BtNode<T>*> q;
  q.push(this);
  q.push(NULL);

  while (q.empty() == false) {
    BtNode<T> * btn = q.front();
    q.pop();

    if (btn->right()) {
      q.push(btn->right());
      stk.push(btn->right());
    }
    if (btn->left()) {
      q.push(btn->left());
      stk.push(btn->left());
    }

    if (q.front() == NULL)
      if (q.size() == 1)
        break;
      else {
        q.push(NULL);
        stk.push(NULL);
        q.pop();
      }
  }

  stk.pop();      // Note: Pop "NULL".
  while (stk.empty() == false) {
    BtNode<T> * btn = stk.top();
    if (btn != NULL) {
      std::cout << btn->element() << " ";
      stk.pop();
    } else {
      stk.pop();
      std::cout << std::endl;
    }
  }
}

template <typename T>
bool BtNode<T>::isBalanced(BtNode<T> * btn) {
  if (btn->left()==NULL && btn->right()==NULL)
    return true;
  else if (!(btn->left()!=NULL && btn->right()!=NULL))
    if (btn->depth() > 1)       // Condition 0.
      return false;
    else 
      return true;
  else  // Conditin 1 and 2.
    return std::abs(btn->left()->depth() - btn->right()->depth())<=1 && isBalanced(btn->left()) && isBalanced(btn->right());
}

// LeetCode 110: Version 0.
template <typename T>
bool BtNode<T>::isBalanced(){
  if (isBalanced(this))
    return true;
}

template <typename T>
bool BtNode<T>::isBalanced2(BtNode<T> * btn, int & height) {
  if (btn == NULL)
    return true;

  int hl = 0;
  if (isBalanced2(btn->left(), hl) == false)
    return false;

  int hr = 0;
  if (isBalanced2(btn->right(), hr) == false)
    return false;

  height = (hl>hr?hl:hr) + 1;

  if (std::abs(hl - hr) > 1)
    return false;

  return true;
}

// LeetCode 110: Version 1.
template<typename T>
bool BtNode<T>::isBalanced2() {

  int height = 0;
  return isBalanced2(this, height);

}

template<typename T>
int BtNode<T>::minDepth(BtNode<T> * btn) {
  /* My original method.\n  if (btn->left()!=NULL && btn->right()!=NULL) {\n    int dl = minDepth(btn->left());\n    int dr = minDepth(btn->right());\n    int d = dl<dr ? dl : dr;\n    return ++d;\n  } else if (btn->left()==NULL && btn->right()==NULL)\n      return 0;\n  else {\n    int dl = -1;\n    int dr = -1;\n    if (btn->left())\n    dl = minDepth(btn->left());\n    if (btn->right())\n    dr = minDepth(btn->right());\n    int d = dl>dr ? dl : dr;\n    return ++d;\n  } */
  if (btn == NULL)
    return -1;

  int mdl = minDepth(btn->left());
  int mdr = minDepth(btn->right());

  if (mdl!=-1 && mdr!=-1)
    return (mdl<mdr ? mdl : mdr) + 1;
  else if (mdl==-1 && mdr==-1)
    return 0;
  else 
    return (mdl>mdr ? mdl : mdr) + 1;
}

// LeetCode 111.
template<typename T>
int BtNode<T>::minDepth() {
  return minDepth(this);
}

template<typename T>
bool BtNode<T>::hasPathSum(BtNode<T> * btn, int sum) {
  if (btn->left()==NULL && btn->right()==NULL)
    if (sum == btn->element())
      return true;

  sum -= btn->element();

  if (btn->left())
    if (hasPathSum(btn->left(), sum) == true)
      return true;

  if (btn->right())
    if (hasPathSum(btn->right(), sum) == true)
      return true;

  return false;
}

// LeetCode 112.
template<typename T>
bool BtNode<T>::hasPathSum(int sum) {
  if (hasPathSum(this, sum) == true)
    return true;
  else
    return false;
}

template<typename T>
BtNode<T> * BtNode<T>::invert(BtNode<T> * btn) {
  if (btn == NULL)
    return NULL;

  invert(btn->left());
  invert(btn->right());

  BtNode<T> * tmp = btn->left();
  btn->left() = btn->right();
  btn->right() = tmp;
  //btn->left() ^= btn->right();
  //btn->right() ^= btn->left();
  //btn->left() ^= btn->right();

  return btn;
}

// LeetCode 226.
template<typename T>
void BtNode<T>::invert() {
  invert(this);
}

#endif  // __BINARY_TREE_H__


// Another buildShadowTree which is not so easy to understand.
//template <typename T>
//tnodeShadow *buildShadowTree(tnode<T> *t, int level, int& column)
//{
//	// pointer to new shadow tree node
//	tnodeShadow *newNode = NULL;
//	// ostr used to perform format conversion
//	ostringstream ostr;
//
//	if (t != NULL)
//	{
//		// create the new shadow tree node
//		newNode = new tnodeShadow;
//
//		// allocate node for left child at next level in tree; attach node
//		tnodeShadow *newLeft = buildShadowTree(t->left, level+1, column);
//		newNode->left = newLeft;
//
//		// initialize data members of the new node
//		ostr << t->nodeValue << ends;	// format conversion
//		newNode->nodeValueStr = ostr.str();
//		newNode->level = level;
//		newNode->column = column;       // Same column with that of the left child?
//    std::cout << "Shadow " << t->nodeValue << " " << level << " " << column << std::endl;
//
//		// update column to next cell in the table
//		column++;
//
//		// allocate node for right child at next level in tree; attach node
//		tnodeShadow *newRight = buildShadowTree(t->right, level+1, column);
//		newNode->right = newRight;
//	}
//
//	return newNode;
//}
