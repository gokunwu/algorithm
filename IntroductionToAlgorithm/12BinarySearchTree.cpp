
#if 0
/*
 * ��������search tree����һ�����ݽṹ����֧�ֶ��ּ��ϲ�����
 * ����SEARCH��MINIMUM��MAXIMUM��PREDECESSOR��SUCCESSOR��INSERT��DELETE��
 * ������������ö������ṹ����֯�Ĳ�������
 * ���������������ʣ�ÿ�����������������е�Ԫ�ض�С�ڵ��ڸý���ֵ��
 * ���ý��ͬʱС�ڵ��������������е�����Ԫ�ص�ֵ��
 */
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

//����������Ľڵ㶨��
struct BSTreeNode
{
	int key;
	BSTreeNode * left;
	BSTreeNode * right;
	BSTreeNode * parent;
};
//�������������
struct BSTree
{
	BSTreeNode * root;
};
//����һ���ڱ��ڵ�
BSTreeNode * NIL = new BSTreeNode;
//����������Ĳ���
bool Insert(BSTree * T,BSTreeNode * bsnode)
{
	BSTreeNode * x = NIL;//x һֱ��y�ĸ��ڵ�
	BSTreeNode * y = T->root;//y���ƶ�������������bsnode��λ�á�
	//һֱ���²���ֱ�� ��y����Ҷ�ӽڵ����һ���ڵ㣬xΪy�ĸ��ڵ�
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
	if(x == NIL)//��treeΪ��ʱ
	{
		T->root = bsnode;
		bsnode->parent = NIL;
	}
	else
	{	//����bsnode��ֵ����������Ҷ�ӽڵ����߻����ұ�
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
//������������������
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
//����������Ĳ���
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
//�������������Сֵ
BSTreeNode * BSTreeMin(BSTreeNode * x)
{
	while(x->left != NIL)
	{
		x = x->left;
	}
	return x;
}
//��������������ֵ
BSTreeNode * BSTreeMax(BSTreeNode * x)
{
	while(x->right != NIL)
	{
		x = x->right;
	}
	return x;
}
//����ĳ���ڵ�ĺ��
BSTreeNode * Successor(BSTreeNode * x)
{
	if(x->right != NIL)//����ڵ�x���ҽڵ㣬x�ĺ�̱������������е���СԪ��
	{
		return BSTreeMin(x->right);
	}
	//����ڵ�xû������������x�ĺ�̱�����������Ĳ������������������ֵ�����
	BSTreeNode * y = x->parent;
	while(y != NIL && x != y->left)
	{
		x = y;
		y = y->parent;
	}
	return y;
}
//����ĳ���ڵ��ǰ��
BSTreeNode * Predecessor(BSTreeNode * x)
{
	if(x->left != NIL)//����ڵ�x����ڵ㣬x�ĺ�̱������������е����Ԫ��
		return BSTreeMax(x->left);
	//����ڵ�xû������������x�ĺ�̱�����������Ĳ������������������ֵ�����
	BSTreeNode * y = x->parent;
	while(y != NIL && x != y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}
//���������ɾ��ĳ���ڵ�
BSTreeNode * BSTreeDelete(BSTree * T,BSTreeNode * z)
{
	BSTreeNode * y;
	BSTreeNode * x;
	//ȷ��Ҫɾ���Ľڵ�y��y������z��Ҳ������z�ĺ��
	if(z->left == NIL || z->right == NIL)
		y = z;
	else
		y = Successor(z);
	//ȷ��y���ӽڵ�x��x����ΪNIL
	if(y->left != NIL)
		x = y->left;
	else
		x = y->right;
	//zֻ��һ�����ӵ����
	if(x != NIL)
		x->parent = y->parent;
	//zû�к��ӻ���ֻ��һ������ʱ��y�ĸ��ڵ���x��������
	if(y->parent == NIL)
		T->root = x;
	else
	{
		if(y->parent->left = y)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	//z���������ӵ�ʱ�򣬽�z��y��key����
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
	//����������������
	InorderTreeWalk(T->root);
	*/
	/*
	//�ڶ���������в��ҹؼ���Ϊ18��node
	BSTreeNode * pkey = BSTreeSearch(T->root,18);
	cout<<pkey<<" "<<pkey->key<<endl;
	*/
	/*
	//���Ҷ���������е���Сֵ
	BSTreeNode * pmin = BSTreeMin(T->root);
	cout<<pmin<<" "<<pmin->key<<endl;
	*/
	/*
	//���Ҷ�������������ֵ
	BSTreeNode * pmax = BSTreeMax(T->root);
	cout<<pmax<<" "<<pmax->key<<endl;
	*/
	/*
	//���ҹؼ���13�ĺ��
	BSTreeNode * pkey = BSTreeSearch(T->root,18);
	BSTreeNode * psuc = Successor(pkey);
	cout<<pkey->key<<" "<<psuc->key<<endl;
	*/
	/*
	//���ҹؼ���13��ǰ��
	BSTreeNode * pkey = BSTreeSearch(T->root,13);
	BSTreeNode * ppre = Predecessor(pkey);
	cout<<pkey->key<<" "<<ppre->key<<endl;
	*/
	//����������������,ɾ��Ԫ��18���ٴα������������
	InorderTreeWalk(T->root);
	BSTreeNode * pz = BSTreeSearch(T->root,18);
	BSTreeNode * pdel = BSTreeDelete(T,pz);
	InorderTreeWalk(T->root);

    system("pause");
	return 0;
}


#endif







