#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void word_split(vector<string> WordVector);
int main()
{
	//���������������ļ�
	vector<string>WordVector;
	word_split(WordVector);
	vector<string>WordVector1;
	word_split(WordVector1);
	return 0;
}
void word_split(vector<string> WordVector)
{
	fstream fs;
	char filename[20] = { 0 };
	cout << "������򿪵��ļ���:";
	cin >> filename;
	fs.open(filename);
	cout << "�򿪳ɹ�" << filename << endl;
	char buf[1024] = { 0 };
	string line, word;
	while (fs.getline(buf, 1024))
	{
		size_t pos;
		line = buf;
		pos = line.find_first_of(",.;:'?!()/\"\n");
		while (pos != string::npos)
		{
			line.erase(pos, 1);
			pos = line.find_first_of(",.;:'?!()/\"\n");
		}
		pos = line.find(" ");
		while (pos != string::npos)
		{
			word = line.substr(0, pos);
			WordVector.push_back(word);
			line.erase(0, pos + 1);
			pos = line.find(" ");
		}
	}
		//vector<string>::iterator it;
		//for (it = WordVector.begin(); it != WordVector.end(); it++)
		//{
		//	cout << (*it).c_str() << endl;
		//}
		//cout << "�ܵĸ���:" << WordVector.size();
		fs.close();
}