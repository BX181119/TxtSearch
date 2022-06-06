#include "txtSearch.h"

#define N 10
int main() {
  vector<string> file_words[N];
  vector<string> filenames = {"test1.txt", "tale.txt"};

  for (int i = 0; i < filenames.size(); ++i) {
    file_words[i] = word_to_vector(filenames[i]);
  }

  int choice;
  while (true) {
    cout << "1. 排序+查找" << endl;
    cout << "2. map" << endl;
    cout << "3. 字典树" << endl;
    cout << "0. 退出 " << endl;
    cin >> choice;
    if (!choice) break;

    int line_cnt;
    cout << "请输入待查询单词(组合)数： " << endl;
    cin >> line_cnt;

    while (line_cnt--) {
      string line;
      cin >> line;
      vector<string> words_to_search = split_str("+", line);
      for (int i = 0; i < filenames.size(); ++i) {
        cout << filenames[i] << ": ";
        search_word(choice, file_words[i], words_to_search);
      }
    }
  }
  return 0;
}
