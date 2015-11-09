#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct Tree
{
	char c;
	Tree *left, *right;
};

Tree* build(string pre, string in)
{
	Tree *root = NULL;
	if (pre.length() > 0)
	{
		root = new Tree;
		char ch = pre[0];
		root->c = ch;
		int pos = in.find(ch);
		root->left = build(pre.substr(1, pos), in.substr(0, pos));
		root->right = build(pre.substr(pos + 1), in.substr(pos + 1));
	}
	return root;
}

void postOrder(Tree *t)
{
	if (t->left)
		postOrder(t->left);
	if (t->right)
		postOrder(t->right);
	printf("%c", t->c);
}

int main()
{
	string pre, in;
	while (cin >> pre >> in)
	{
		Tree *t = build(pre, in);
		postOrder(t);
		printf("\n");
	}
}