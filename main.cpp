#include "txtSearch.h"
#define N 10
int main() {
  vector<string> words[N];
  int file_count = 0;
  cout << "�������ļ���: ";
  cin >> file_count;
  //���ļ�, ���ִʽ��vector����words����
  for (int i = 0; i < file_count; ++i) {
    string filename;
    cout << "������򿪵��ļ���:";
    cin >> filename;
    words[i] = word_split(filename);
  }
  /*��������: ��words������ȡvector,��vector���в��Ҽ���*/

  /*words������ȡvector��������ʵ��
  for (int i = 0; i < file_count; ++i) {
    cout << "file " << i << ": " << endl;
    for (const auto& word:words[i]) {
      cout << word << endl;
    }
  }
   */
  return 0;
}
