#pragma once
#include "url_Header.h"

struct URL
{
	string data;
	int depth;
};

struct BNode
{
	URL url;
	BNode* next, * into, * prev;
	void init()
	{
		next = into = prev = nullptr;
	}
};

struct Tree
{
	BNode* root = nullptr;
	void init(BNode*& node)
	{
		node = new BNode;
		node->init();
	}
	void Insert(string value, BNode*& parent)
	{
		if (parent == nullptr)
		{
			init(parent);
			parent->url.data = value;
			parent->url.depth = 1;
			return;
		}
		int dep = parent->url.depth;
		if (value.find(parent->url.data) != -1 && value != parent->url.data)
		{
			Insert(value, parent->into, parent, ++dep);
		}
		else
		{
			Insert(value, parent->next, parent, dep);
		}
	}
	void Insert(string value, BNode*& present, BNode* parent, int dep) //dep: depth (do sau cua url)
	{
		if (present == nullptr)
		{
			init(present);
			BNode* last = parent;
			present->url.data = value;
			present->url.depth = dep;
			present->prev = last;
			return;
		}
		if (value.find(present->url.data) != -1 && value != present->url.data)
		{
			Insert(value, present->into, present, ++dep);
		}
		else
		{
			Insert(value, present->next, present, dep);
		}

	}
	bool Search(BNode* node, string value)
	{
		if (node == nullptr)
			return false;
		if (value == node->url.data)
		{
			return true;
		}
		bool check = Search(node->into, value);
		if (check) return true;
		bool check2 = Search(node->next, value);

		return check2;
	}
};

void ThoiGianThucThiTree(Tree url, string urlList[], int lengthList);
