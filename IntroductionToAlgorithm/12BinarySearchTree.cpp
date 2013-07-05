
#if 0
/*
 * 查找树（search tree）是一种数据结构，它支持多种集合操作，
 * 包括SEARCH，MINIMUM，MAXIMUM，PREDECESSOR，SUCCESSOR，INSERT和DELETE。
 * 二叉查找树是用二叉树结构来组织的查找树。
 * 它满足这样的性质：每个结点的左子树中所有的元素都小于等于该结点的值，
 * 而该结点同时小于等于它的右子树中的所有元素的值。
 */
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

//二叉查找树的节点定义
struct BSTreeNode
{
	int key;
	BSTreeNode * left;
	BSTreeNode * right;
	BSTreeNode * parent;
};
//二叉查找树定义
struct BSTree
{
	BSTreeNode * root;
};
//设置一个哨兵节点
BSTreeNode * NIL = new BSTreeNode;
//二叉查找树的插入
bool Insert(BSTree * T,BSTreeNode * bsnode)
{
	BSTreeNode * x = NIL;//x 一直是y的父节点
	BSTreeNode * y = T->root;//y是移动变量，用来找bsnode的位置。
	//一直向下查找直到 当y到达叶子节点的下一个节点，x为y的父节点
	while(y != NIL)
	{
		x = y;
		if(bsnode->key <= y->key)
		{
			y = y->left;
		}else
		{
			y = y->right;
		}
	}
	if(x == NIL)//当tree为空时
	{
		T->root = bsnode;
		bsnode->parent = NIL;
	}
	else
	{	//根据bsnode的值来决定放在叶子节点的左边还是右边
		if(bsnode->key <= x->key)
		{
			x->left = bsnode;
			bsnode->parent = x;
		}
		else
		{
			x->right = bsnode;
			bsnode->parent = x;
		}
	}
	return true;
}
//二叉查找树的中序遍历
bool InorderTreeWalk(BSTreeNode * x)
{
	if( x != NIL)
	{
		InorderTreeWalk(x->left);
		cout<<x->key<<endl;
		InorderTreeWalk(x->right);
	}
	return true;
}
//二叉查找树的查找
BSTreeNode * BSTreeSearch(BSTreeNode * x,int key)
{
	while(x != NIL && x->key != key)
	{
		if(key <= x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}
//二叉查找树的最小值
BSTreeNode * BSTreeMin(BSTreeNode * x)
{
	while(x->left != NIL)
	{
		x = x->left;
	}
	return x;
}
//二叉查找树的最大值
BSTreeNode * BSTreeMax(BSTreeNode * x)
{
	while(x->right != NIL)
	{
		x = x->right;
	}
	return x;
}
//查找某个节点的后继
BSTreeNode * Successor(BSTreeNode * x)
{
	if(x->right != NIL)//如果节点x有右节点，x的后继便是它右子树中的最小元素
	{
		return BSTreeMin(x->right);
	}
	//如果节点x没有右子树，则x的后继便是离它最近的并把它当成左子树部分的祖先
	BSTreeNode * y = x->parent;
	while(y != NIL && x != y->left)
	{
		x = y;
		y = y->parent;
	}
	return y;
}
//查找某个节点的前驱
BSTreeNode * Predecessor(BSTreeNode * x)
{
	if(x->left != NIL)//如果节点x有左节点，x的后继便是它左子树中的最大元素
		return BSTreeMax(x->left);
	//如果节点x没有左子树，则x的后继便是离它最近的并把它当成右子树部分的祖先
	BSTreeNode * y = x->parent;
	while(y != NIL && x != y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}
//二叉查找树删除某个节点
BSTreeNode * BSTreeDelete(BSTree * T,BSTreeNode * z)
{
	BSTreeNode * y;
	BSTreeNode * x;
	//确定要删除的节点y，y可能是z，也可能是z的后继
	if(z->left == NIL || z->right == NIL)
		y = z;
	else
		y = Successor(z);
	//确定y的子节点x，x可能为NIL
	if(y->left != NIL)
		x = y->left;
	else
		x = y->right;
	//z只有一个孩子的情况
	if(x != NIL)
		x->parent = y->parent;
	//z没有孩子或者只有一个孩子时，y的父节点与x建立链接
	if(y->parent == NIL)
		T->root = x;
	else
	{
		if(y->parent->left = y)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	//z有两个孩子的时候，将z与y的key交换
	if( y != z)
	{
		z->key = y->key;
	}
}
int main(int argc, char **argv)
{	//15,5,3,12,10,13,6,7,16,20,18,23
	BSTree * T =new BSTree;
	T->root = NIL;
	vector<int> vi;
	vi.push_back(15);
	vi.push_back(5);
	vi.push_back(3);
	vi.push_back(12);
	vi.push_back(10);
	vi.push_back(13);
	vi.push_back(6);
	vi.push_back(7);
	vi.push_back(16);
	vi.push_back(20);
	vi.push_back(18);
	vi.push_back(23);
	for(int i = 0; i < vi.size(); ++i)
	{
		BSTreeNode * bsnode = new BSTreeNode;
		bsnode->key = vi[i];
		bsnode->left = NIL;
		bsnode->right = NIL;
		bsnode->parent = NIL;
		Insert(T,bsnode);
	}
	/*
	//中序遍历二叉查找树
	InorderTreeWalk(T->root);
	*/
	/*
	//在二叉查找树中查找关键字为18的node
	BSTreeNode * pkey = BSTreeSearch(T->root,18);
	cout<<pkey<<" "<<pkey->key<<endl;
	*/
	/*
	//查找二叉查找树中的最小值
	BSTreeNode * pmin = BSTreeMin(T->root);
	cout<<pmin<<" "<<pmin->key<<endl;
	*/
	/*
	//查找二叉查找树的最大值
	BSTreeNode * pmax = BSTreeMax(T->root);
	cout<<pmax<<" "<<pmax->key<<endl;
	*/
	/*
	//查找关键字13的后继
	BSTreeNode * pkey = BSTreeSearch(T->root,18);
	BSTreeNode * psuc = Successor(pkey);
	cout<<pkey->key<<" "<<psuc->key<<endl;
	*/
	/*
	//查找关键字13的前驱
	BSTreeNode * pkey = BSTreeSearch(T->root,13);
	BSTreeNode * ppre = Predecessor(pkey);
	cout<<pkey->key<<" "<<ppre->key<<endl;
	*/
	//中序遍历二叉查找树,删除元素18后再次遍历二叉查找树
	InorderTreeWalk(T->root);
	BSTreeNode * pz = BSTreeSearch(T->root,18);
	BSTreeNode * pdel = BSTreeDelete(T,pz);
	InorderTreeWalk(T->root);

    system("pause");
	return 0;
}


#endif







