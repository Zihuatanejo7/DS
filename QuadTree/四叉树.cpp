//# include <iostream>
//# include <vector>
//# include  <sstream>
//# include  <string>
//using namespace std;
//
////struct TreeNode
////{
////	vector<double> val;
////
////	TreeNode* left;
////	TreeNode* right;
////	TreeNode* top;
////	TreeNode* bottom;
////
////	TreeNode() :val({ 0,0,0,0 }), left(nullptr), right(nullptr), top(nullptr), bottom(nullptr) {};
////	TreeNode(vector<double>val, TreeNode* left = nullptr, TreeNode* right = nullptr, TreeNode* top = nullptr, TreeNode* bottom = nullptr) :val(val), left(left), right(right), top(top), bottom(bottom) {};
////
////
////	TreeNode* insertLsLc(vector<double> val);
////	TreeNode* insertRsLc(vector<double> val);
////	TreeNode* insertTsLc(vector<double> val);
////	TreeNode* insertBsLc(vector<double> val);
////};
//
//// 节点
//class TreeNode
//{
//public:
//	vector<double> val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode* top;
//	TreeNode* bottom;
//
//	TreeNode() :val({ 0,0,0,0 }), left(nullptr), right(nullptr), top(nullptr), bottom(nullptr) {};
//	TreeNode(vector<double>val, TreeNode* left = nullptr, TreeNode* right = nullptr, TreeNode* top = nullptr, TreeNode* bottom = nullptr) :val(val), left(left), right(right), top(top), bottom(bottom) {};
//	TreeNode* insertLsLc(vector<double> val);
//	TreeNode* insertRsLc(vector<double> val);
//	TreeNode* insertTsLc(vector<double> val);
//	TreeNode* insertBsLc(vector<double> val);
//
//	~TreeNode();
//};
//
//TreeNode* TreeNode::insertLsLc(vector<double> val)
//{
//	return left = new TreeNode(val);
//}
//
//TreeNode* TreeNode::insertRsLc(vector<double> val)
//{
//	return right = new TreeNode(val);
//}
//
//TreeNode* TreeNode::insertTsLc(vector<double> val)
//{
//	return top = new TreeNode(val);
//}
//
//TreeNode* TreeNode::insertBsLc(vector<double> val)
//{
//	return bottom = new TreeNode(val);
//}
//
//TreeNode::~TreeNode()
//{
//	if (left != NULL)
//	{
//		delete left;
//		left = NULL;
//	}
//
//	if (right != NULL)
//	{
//		delete right;
//		right = NULL;
//	}
//
//	if (top != NULL)
//	{
//		delete top;
//		top = NULL;
//	}
//	if (bottom != NULL)
//	{
//		delete bottom;
//		bottom = NULL;
//	}
//}
//
//
//
//// 树根
//class QuaTree
//{
//public:
//	TreeNode* root;
//	QuaTree() :root(NULL) {}
//	~QuaTree();
//	
//	TreeNode* insertAsRoot(vector<double> val);
//	void BuildTree(TreeNode* root, int level, int depth);
//	TreeNode* insertAsLc(TreeNode* x, vector<double> val);
//	TreeNode* insertAsRc(TreeNode* x, vector<double> val);
//	TreeNode* insertAsTc(TreeNode* x, vector<double> val);
//	TreeNode* insertAsBc(TreeNode* x, vector<double> val);
//	void Preorder(TreeNode* root);
//};
//
//TreeNode* QuaTree::insertAsRoot(vector<double> val)
//{
//	return root = new TreeNode(val);
//}
//
//TreeNode* QuaTree::insertAsLc(TreeNode* x, vector<double> val)
//{
//	x->insertLsLc(val);
//	return x->left;
//}
//
//TreeNode* QuaTree::insertAsRc(TreeNode* x, vector<double> val) 
//{
//	x->insertRsLc(val);
//	return x->right;
//}
//
//TreeNode* QuaTree::insertAsTc(TreeNode* x, vector<double> val) 
//{
//	x->insertTsLc(val);
//	return x->top;
//}
//
//TreeNode* QuaTree::insertAsBc(TreeNode* x, vector<double> val) 
//{
//	x->insertBsLc(val);
//	return x->bottom;
//}
//
//// QuaTree 析构函数
//QuaTree::~QuaTree()
//{
//	{
//		if (root != NULL)
//		{
//			delete root;
//			root = NULL;
//		}
//	}
//}
//
//// 建树
//void QuaTree::BuildTree(TreeNode* root, int level, int depth)
//{
//	for (int i = level; i < depth; i++)
//	{
//		BuildTree(this->insertAsLc(root, { (root->val)[0],((root->val)[0] + (root->val)[1]) / 2, ((root->val)[2] + (root->val)[3]) / 2 ,(root->val)[3] }), level + 1, depth);
//		BuildTree(this->insertAsRc(root, { ((root->val)[0] + (root->val)[1]) / 2,(root->val)[1], ((root->val)[2] + (root->val)[3]) / 2 ,(root->val)[3] }), level + 1, depth);
//		BuildTree(this->insertAsTc(root, { (root->val)[0],((root->val)[0] + (root->val)[1]) / 2,(root->val)[2],((root->val)[2] + (root->val)[3]) / 2 }), level + 1, depth);
//		BuildTree(this->insertAsBc(root, { ((root->val)[0] + (root->val)[1]) / 2,(root->val)[1],(root->val)[2],((root->val)[2] + (root->val)[3]) / 2 }), level + 1, depth);
//	}
//}
//
//// 数字转字符
//string  num2str(double i)
//{
//	stringstream ss;
//	ss << i;
//	return ss.str();
//}
//
//// 前序遍历
//void QuaTree::Preorder(TreeNode* root)
//{
//	if (NULL == root)
//		return;
//
//	string Buff;
//	for (int i = 0; i < 4; i++)
//	{
//		Buff += num2str((root->val)[i]);
//	}
//	cout << Buff << endl;
//	Preorder(root->left);
//	Preorder(root->right);
//	Preorder(root->top);
//	Preorder(root->bottom);
//
//}
//
//int main()
//{
//	QuaTree* p = new QuaTree();
//	TreeNode* root = p->insertAsRoot({ -180,180,-90,90 });
//	p->BuildTree(root, 0, 3);
//	p->Preorder(root);
//	return 0;
//}

# include <string>
# include <vector>
# include <iostream>
using namespace std;

int main()
{
	vector<double> msg;
}