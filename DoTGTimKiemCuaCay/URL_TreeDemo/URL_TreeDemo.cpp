#include "randomURL.h"
#include "treeDataStructure.h"


void input(Tree& url, string urlList[], int n)
{
	for (int i = 0; i < n; i++)
	{
		url.Insert(urlList[i], url.root);
	}
}

void main()
{
	Tree url;
	string urlList[LENGTH_URL_LIST]; //=1000
	int lengthList = LENGTH_URL_LIST;
	randomUrlList(urlList, lengthList); //Sinh ra 1 danh sách 1000 URL

	input(url, urlList, lengthList);

	ThoiGianThucThiTree(url, urlList, lengthList);
}
