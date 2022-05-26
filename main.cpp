#include "txtSearch.h"
#define N 10
int main() {
  vector<string> words[N];
  int file_count = 0;
  cout << "请输入文件数: ";
  cin >> file_count;
  //读文件, 将分词结果vector存入words数组
  for (int i = 0; i < file_count; ++i) {
    string filename;
    cout << "请输入打开的文件名:";
    cin >> filename;
    words[i] = word_split(filename);
  }
  /*后续操作: 从words数组中取vector,对vector进行查找计数*/

  /*words数组中取vector遍历单词实例
  for (int i = 0; i < file_count; ++i) {
    cout << "file " << i << ": " << endl;
    for (const auto& word:words[i]) {
      cout << word << endl;
    }
  }
   */
  return 0;
}
