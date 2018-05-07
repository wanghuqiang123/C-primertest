#include<iostream>
#include<string>
using namespace std;
class TreeNode
{
private:
	string value;
	int count;
	TreeNode * left;
	TreeNode * right;
public:
	TreeNode() :value(""),count(1),left(nullptr), right(nullptr) { }
	
	TreeNode(const string& s = string(),TreeNode* lchild = nullptr,TreeNode* rchild = nullptr) :
	value(s), count(1), left(nullptr), right(nullptr) { }
	
	TreeNode(const TreeNode& obj) :value(obj.value),count(1),left(obj.left),right(obj.right)
	{
		if (left)
			left->copyTree();
		if (right)
			right->copyTree();
	}

	TreeNode* copyTree(void)  //拷贝以此节点为根的子树；
	{
		if (left)
			left->copyTree();
		if (right)
			right->copyTree();
		count++;
		return this;		//自己+的
	}

	int ReleaseTree(void)
	{
		if (left) 
		{
			if (!left->copyTree())
				delete left;
		}
		if (right)
		{
			if (!right->copyTree())
				delete right;
		}
		count--;
		return count;
	}

	~TreeNode()
	{
		if (count)
			ReleaseTree();
	}
};

class BinaryTree
{
private:
	TreeNode* root;
public:
	BinaryTree() :root(nullptr) { }
	BinaryTree(TreeNode* t = nullptr) :root(t) { }
	BinaryTree(const BinaryTree& obj):root(obj.root)
	{
		root->copyTree();
	}
	~BinaryTree()
	{
		if (!root->ReleaseTree())
			delete root;
	}
};

int main()
{

	return 0;
}