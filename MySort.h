/*
 * @Author: Metaphor
 * @LastEditTime: 2022-05-26 22:12:08
 * Copyright (c) 2022 by 廖虹宇|上海大学.计算机工程与科学学院, All Rights Reserved. 
 */
#ifndef _MYSORT_H
#define _MYSORT_H
#include "txtSearch.h"
#define MAX_LEVEL 3
extern int **IndexesTable;


void MySort(vector<string> &words, int low, int high, int level);
void init(vector<string> &words, int n);
void MySort(vector<string> &words);
#endif