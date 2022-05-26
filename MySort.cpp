/*
 * @Author: Metaphor
 * @LastEditTime: 2022-05-26 22:12:30
 * Copyright (c) 2022 by 廖虹宇|上海大学.计算机工程与科学学院, All Rights Reserved. 
 */
#include "MySort.h"
int **IndexesTable;

void MySort(vector<string> &words, int low, int high, int level)
{
    string e = words[low];
    int i = low, j = high;
    while (i<j)
    {
        while (i < j && words[j][level] >= e[level]) j--;
        if (i<j) words[i++] = words[j];
        while (i < j && words[i][level] <= e[level]) i++;
        if (i<j) words[j--] = words[i];
    }
    words[i] = e;
    if (low < i - 1)
        MySort(words, low, i - 1, level);
    if (i+1 < high)
        MySort(words, i + 1, high, level);
}

void init(vector<string> &words, int n)
{
    char t = '\0';
    for (int i = 0; i < words.size(); i++)
    {
        char c = words[i][n];
        if (c == t)
            continue;
        if (c >= 'a' && c <= 'z')
        {
            IndexesTable[n + 1][c - 'a'] = i;
            continue;
        }
        if (c >= 'A' && c <= 'Z')
        {
            IndexesTable[n + 1][c - 'A' + 26] = i;
        }
        t = c;
    }
}

void MySort(vector<string> &words)
{
    MySort(words, 0, words.size(), 0);
    init(words, 0);
    for (int level = 1; level < MAX_LEVEL - 1; level++)
    {
        for (int i = 0; i < 26; i++)
        {
            int s = IndexesTable[level][i];
            int e = IndexesTable[level][i + 1];
            MySort(words, s, e, level);
        }
        init(words, level);
    }
}
