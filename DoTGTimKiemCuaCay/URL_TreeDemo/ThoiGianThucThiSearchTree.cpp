#include "url_Header.h"
#include "treeDataStructure.h"

void SearchingTime(Tree url, string urlList[], int n)
{
	double sum = 0, max = 0, min = 1;

	if (n == 0)
	{
		cout << "\n\tURL List == NULL";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		auto begin = std::chrono::high_resolution_clock::now();

		bool check = url.Search(url.root, urlList[i]);

		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

		double temp = elapsed.count() * 1e-9;
		if (temp > max) max = temp;
		if (temp < min) min = temp;
		sum += temp;
	}

	//Xuất ra thời gian thực thi Max, Min và Avg
	double avg = sum / n;
	cout << endl;
	cout << "\n\tThe number of URLs: " << n;
	cout << "\n\tMax execution time: " << max;
	cout << "\n\tMin execution time: " << min;
	cout << "\n\tAverage execution time: " << avg;
}

void ThoiGianThucThiTree(Tree url, string urlList[], int lengthList)
{
	lengthList = 100;
	int count = 0;
	for (int time = 0; time < 10; time++)
	{
		SearchingTime(url, urlList, lengthList);
		lengthList += 100;
	}
}