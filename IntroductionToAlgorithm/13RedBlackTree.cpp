

#if 0
/*
 * copyright@nciaebupt 转载请保留此标记
 * 所有代码已经在linux g++ 下编译通过，直接拷贝运行即可 如有问题欢迎指正
 * 红黑树（red-black tree）是许多“平衡的”查找树中的一种。
 * 红黑树的性质:
 * １、每个结点或是红的，或是黑的。
 * ２、根结点是黑的。
 * ３、每个叶结点（NIL）是黑的。
 * ４、如果一个结点是红的，则它的两个儿子都是黑的。
 * ５、对每个结点，从该结点到其子孙的所有路径上包含相同数目的黑结点。
 * 红黑树的结点比普通的二叉查找树的结点多了一个颜色属性。
 */
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

//将RED,BLACK颜色值定义成枚举类型
enum RBCOLOR {RED,BLACK};
//定义红黑树节点的数据结构
struct RBTreeNode
{
	int key;
	RBCOLOR color;
	RBTreeNode * left;
	RBTreeNode * right;
	RBTreeNode * parent;
};
//定义红黑树的数据结构
struct RBTree
{
	RBTreeNode * root;
	//RBTreeNode * NIL = new RBTreeNode;
	RBTreeNode * NIL;
};
void RBTreeInsertFixup(RBTree * T,RBTreeNode * z);
void RBTreeDeleteFixup(RBTree * T,RBTreeNode * x);
//实现红黑树的左旋操作
void RBLeftRotate(RBTree * T,RBTreeNode * x)
{
	RBTreeNode * y = x->right;
	x->right = y->left;
	if(y->left != T->NIL)
		y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == T->NIL)
		T->root = y;
	else if(x->parent->left ==x)
			x->parent->left = y;
		 else
			x->parent->right =y;
	y->left = x;
	x->parent = y;
}
//实现红黑树的右旋操作
void RBRightRotate(RBTree * T,RBTreeNode * x)
{
	RBTreeNode * y = x->left;
    if(x->left == T->NIL)
        return;
	x->left = y->right;
	if(y->right != T->NIL)
    {
        y->right->parent = x;
    }

	y->parent = x->parent;
	if(x->parent == T->NIL)
		T->root = y;
	else
	{
		if(x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
	}

	y->right = x;
	x->parent = y;
}
//红黑树插入
void RBTreeInsert(RBTree * T,RBTreeNode * z)
{
	RBTreeNode * y = T->NIL;
	RBTreeNode * x = T->root;
	while(x != T->NIL)
	{
		y = x;
		if(z->key <= x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if(y == T->NIL)
		T->root = z;
	else
	{
		if(z->key <= y->key)
		{
			y->left = z;
		}
		else
		{
			y->right = z;
		}
	}

	RBTreeInsertFixup(T,z);
}

//红黑树插入对节点重新着色
void RBTreeInsertFixup(RBTree * T,RBTreeNode * z)
{

	RBTreeNode * y;
	if(z->parent == T->NIL)//z是根节点
	{
        z->color = BLACK;
        return;
	}
	if(z->parent->color == BLACK)//这种情况下是平衡的
	{
	    return;
	}
	//一直循环，直到z的父节点的颜色为黑色
	while(z->parent->color == RED)
	{
		if(z->parent == z->parent->parent->left)//当z的父节点是z祖父节点的左孩子时
		{
			y = z->parent->parent->right;//y是z的叔叔
			//case1:z的叔叔y 的颜色为红色
			if(y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
			    if(z == z->parent->right)//case2:z的叔叔y 的颜色为黑色并且z是它父节点的右孩子
                {
                   z = z->parent;
                   RBLeftRotate(T,z);
                }
                //case3:z的叔叔y 的颜色为黑色并且z是它父节点的左孩子
                z->parent->color =BLACK;
                z->parent->parent->color = RED;
                RBRightRotate(T,z->parent->parent);
			}
		}//当z的父节点是z祖父节点的右孩子时
		else //如果z的父节点是其祖父节点的右孩子
		{
			y = z->parent->parent->left;//y是z的叔叔节点
			if(y->color == RED)//case1：z的叔叔节点为红色，则z的父节点BLACK，祖父节点RED，叔叔节点BLACK均变色
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
            {
                if(z == z->parent->left)//case2:z的叔叔y的颜色为黑色并且z是它父节点的左孩子
                {
                    z = z->parent;
                    RBRightRotate(T,z);
                }
                //case3:z的叔叔y的颜色为黑色并且z是它父节点的右孩子
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                RBLeftRotate(T,z->parent->parent);
            }
		}
	}
	T->root->color = BLACK;
}
//红黑树的最小值
RBTreeNode * RBTreeMin(RBTree * T,RBTreeNode * x)
{
	while(x->left != T->NIL)//最小元素就是树的最左结点
	{
		x = x->left;
	}
	return x;
}
//红黑树中某个节点的后继
RBTreeNode * Successor(RBTree * T,RBTreeNode * x)
{
	if(x->right != T->NIL)//如果x有右子树，那么x的后继就是其右子树中的最小元素
	{
		return RBTreeMin(T,x->right);
	}
	else//如果x没有右子树，那么x的后继就是离它最近的、并且把它当做左子树部分的祖先
	{
		RBTreeNode * y = x->parent;
		while(y != T->NIL && x != y->left)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
}
//红黑树中删除节点
RBTreeNode * RBTreeDelete(RBTree * T,RBTreeNode * z)
{
	RBTreeNode * y; //y是要删除的那个节点
	RBTreeNode * x; //x是要删除的节点y的子节点
	//首先确定要删除的节点y（y可能就是z也可能是z的后继）
	if(z->left == T->NIL || z->right == T->NIL)//这个条件包含两种情况：如果z的左右子树都
	//为空那么直接删除z，要删除的节点就是z；如果z的左右子树有一个为空，那么就用不为空的
	//那个子节点代替z，要删除的节点也是z
	{
		y = z;
	}
	else//如果z的左右子树都不为空，那么要删除的节点就是z的后继
	{
		y = Successor(T,z);
	}
	//确定y的子节点x（x可能为空）
	if(y->left != T->NIL)
		x = y->left;
	else
		x = y->right;
	//y只有一个孩子的情况,用孩子节点x代替y(此时若y != z则x->parent 也指向 y->parent)
	if(x != T->NIL)
		x->parent = y->parent;
	//y没有孩子或者只有一个孩子时，y的父节点与x建立链接(此时若y != z则y->parent->left/right也指向 x)
	if(y->parent == T->NIL)
		T->root = x;
	else
	{
		if(y->parent->left == y)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	//y有两个孩子时，交换y与z的key
	if(y != z)
	{
		z->key = y->key;
	}
	if(y->color == BLACK)
		RBTreeDeleteFixup(T,y);
	return y;
}
//红黑树删除操作对节点重新着色
void RBTreeDeleteFixup(RBTree * T,RBTreeNode * x)
{
	RBTreeNode * brother;
	while(x != T->root && x->color == BLACK)
	{
		//the x is its parent's left child
		if(x == x->parent->left)
		{
			brother = x->parent->right;//get x's brother
			//case1:当前节点是黑色，且兄弟节点为红色(此时父节点和兄弟节点的子节点分为黑)
			if(brother->color == RED)
			{
				brother->color = BLACK;
				x->parent->color = RED;
				RBLeftRotate(T,x->parent);
				brother = x->parent->right;
			}
			//当前节点是黑色，且兄弟节点为黑色
			if(brother->left->color == BLACK && brother->right->color == BLACK)//case2:当前节点是黑色，且兄弟是黑色，且兄弟节点的两个子节点全为黑色
			{
				brother->color = RED;
				x = x->parent;
			}
			else if(brother->left->color == RED && brother->right->color == BLACK)//case3:当前节点是黑色，且兄弟是黑色，且兄弟节点的左子节点为红右子结点为黑色
			{
				brother->color = RED;
				brother->left->color = BLACK;
				RBRightRotate(T,brother);
				brother = x->parent->right;
			}
			//case4:当前节点是黑色，且兄弟是黑色，且brother的右孩子为红色
			brother->color = x->parent->color;
			x->parent->color = BLACK;
			brother->right->color = BLACK;
			RBLeftRotate(T,x->parent);
			x = T->root;
		}
		else //if(x == x->parent->right)//x是其父节点的右孩子
		{
			brother = x->parent->left;//得到x的兄弟节点brother
			if(!brother || brother == T->NIL)
                return;
			if(brother->color == RED)//case1:当前节点是黑色，且兄弟节点为红色(此时父节点和兄弟节点的子节点分为黑)
			{
				brother->color = BLACK;
				x->parent->color = RED;
				RBRightRotate(T,x->parent);
				brother = x->parent->left;
			}
			//当前节点是黑色，且兄弟节点为黑色
			if(brother->right->color == BLACK && brother->left->color == BLACK)//case2:当前节点是黑色，且兄弟是黑色，且兄弟节点的两个子节点全为黑色
			{
				brother->color = RED;
				x = x->parent;
			}
			else if(brother->right->color == BLACK)//case3:当前节点是黑色，且兄弟是黑色，且兄弟节点的左子节点为红右子结点为黑色
			{
				brother->left->color = BLACK;
				brother->color = RED;
				RBLeftRotate(T,brother);
				brother = x->parent->left;
			}
			//case4:当前节点是黑色，且兄弟是黑色，且brother的右孩子为红色
            brother->color = x->parent->color;
            x->parent->color = BLACK;
            brother->right->color = BLACK;
            if(x->parent->left != NULL)
                RBRightRotate(T,x->parent);
            x = T->root;
		}
	}
	x->color = BLACK;
}
//红黑树查找值为key的某个节点
RBTreeNode * RBTreeSearch(RBTree * T,int key)
{
	RBTreeNode * x = T->root;
	while(x != T->NIL && x->key != key)
	{
		if(key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}
//中序遍历红黑树
void InorderRBTreeWalk(RBTree * T,RBTreeNode * x)
{
	if(x != T->NIL)
	{
		InorderRBTreeWalk(T,x->left);
		cout<<x->key<<endl;
		InorderRBTreeWalk(T,x->right);
	}
}
int main(int argc, char **argv)
{
	//15,5,3,12,10,13,6,7,16,20,18,23
	RBTree * T = new RBTree;

	T->NIL = new RBTreeNode;

	T->NIL->color = BLACK;
	T->NIL->key = 10000;
	T->NIL->left = NULL;
	T->NIL->parent = NULL;
	T->NIL->right = NULL;
    T->root = T->NIL;

	vector<int> vi;

	vi.push_back(12);
	vi.push_back(15);
	vi.push_back(5);
	vi.push_back(3);
	vi.push_back(10);
	vi.push_back(13);
	vi.push_back(6);
	vi.push_back(7);
	vi.push_back(16);
	vi.push_back(20);
	vi.push_back(18);
	vi.push_back(23);

    //建立红黑树
	for(vector<int>::iterator it = vi.begin(); it != vi.end();++it)
	{
		RBTreeNode * p = new RBTreeNode;
		p->color = RED;
		p->key = *it;
		p->left = T->NIL;
		p->parent = T->NIL;
		p->right = T->NIL;
		cout<<"Insert key : "<<p->key<<endl;
		RBTreeInsert(T,p);
	}
	cout<<"---------------------------------"<<endl;
	//中序遍历红黑树
	InorderRBTreeWalk(T,T->root);
	/*
	cout<<"---------------------------------"<<endl;
	//查找红黑树中key为16的节点
	RBTreeNode * x = RBTreeSearch(T,16);
	//当key为20的节点不为空时删除它
	if(x != T->NIL)
	{
	    cout<<"The key to be deleted is :"<<x->key<<endl;
		RBTreeDelete(T,x);
	}
	//中序遍历红黑树
	InorderRBTreeWalk(T,T->root);
	*/
	cout<<"---------------------------------------"<<endl;
	for(vector<int>::iterator it = vi.begin(); it != vi.end();++it)
	{
	    RBTreeNode * x = RBTreeSearch(T,*it);
        if(x != T->NIL)
        {
            cout<<"The key to be deleted is :"<<x->key<<endl;
            RBTreeDelete(T,x);
        }
        InorderRBTreeWalk(T,T->root);
        cout<<"---------------------------------------"<<endl;
	}

    system("pause");
	return 0;
}

#endif
