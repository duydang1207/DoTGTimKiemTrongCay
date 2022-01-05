#include "randomURL.h"
#include "treeDataStructure.h"

void randomURL(string urlList[], int pos, int len)
{
	char temp;
	for (int i = 0; i < len; i++)
	{
		temp = SET[rand() % LENGHSET];
		urlList[pos] += temp;
	}
	urlList[pos] += "/";
}

void randomUrlList(string urlList[], int n) // dùng chung cho all ctdl
{
	urlList[0] = formURL; //URL gốc
	for (int i = 1; i < n; i++)
	{
		int len = i / (n / 10) + 1; //nếu số phần tử cần sinh là 1000 (n = 1000) thì len = i / 100 + 1,
									// nghĩa là 100 url đầu tiên sẽ có là formURL + 1 kí tự (đc lấy từ mảng SET)
									// 100 url tiếp theo sẽ là formURL + 2 kí tứ (đc lất từ mảng SET)  
		urlList[i] = formURL;
		randomURL(urlList, i, len);
	}
}

//void randomUrlList(string urlList[], int n) //Dùng cho Cây nhị phân
//{
//	urlList[0] = formURL; //URL gốc
//	if (n > 1)
//	{
//		urlList[1] = urlList[0];
//		randomURL(urlList, 1, 1);
//		urlList[2] = urlList[0];
//	}
//	for (int i = 3; i < n; i++)
//	{
//		if (i % 2 == 0)
//			urlList[i] = urlList[i - 3];
//		else
//		{
//			int len = 1;
//			urlList[i] = urlList[i - 2];
//			randomURL(urlList, i, len);
//		}
//	}
//}

