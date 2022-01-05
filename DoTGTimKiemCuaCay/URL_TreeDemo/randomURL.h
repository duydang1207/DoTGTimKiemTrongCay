#pragma once
#include "url_Header.h"

const char SET[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // Các kí tự dùng để sinh nn
const int LENGHSET = strlen(SET); //Độ dài mảng kí tự SET
const int LENGTH_URL_LIST = 1000; //Số lượng phần tử cần sinh ngẫu nhiên vào mảng string
const int NUM_CHILD_URL = 2;
const string formURL = "https://url.hcmute.edu.vn/"; //Các url được sinh nn sẽ có cấu trúc là urlList[i] = "https://url.hcmute.edu.vn/" + ...

void randomURL(string urlList[], int pos, int len);
void randomUrlList(string urlList[], int n);
