
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>
#include<ctype.h>

using namespace std;
string sentenceRecreator(string, vector<string>);
bool sentenceAfterCheck(vector<string>, int, string, int, string&);
int main() {
	ifstream Dict;
	vector<string> dictionary;
	Dict.open("dictionary.txt");
	bool empty = false;
	while (!empty) {
		if (!Dict.good()) {
			empty = true;
		}
		string temp = "";
		getline(Dict, temp);
		dictionary.push_back(temp);


	}
	Dict.close();
	string sentence;
	getline(cin, sentence);
	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
	sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
	cout << sentence;

	cout << endl << sentenceRecreator(sentence, dictionary);
	system("pause>0");
}
string sentenceRecreator(string str, vector<string> dict)
{


	
	string answer = "";
	int position = 0;//position in the original string
	int length = 1;//length of substring
	string temp = "";
	while (position < str.length())
	{
		temp = str.substr(position, length);
		if (binary_search(dict.begin(), dict.end(), temp))
		{
			if (sentenceAfterCheck(dict, position, str, temp.length(), answer)) {
				
				return answer.insert(0,temp+" ");
				
			}
			else {
				length++;
			}
		}
		else {
			length++;
		}
	}
	

}

bool sentenceAfterCheck(vector<string> dict, int firstPosition, string str, int firstLength, string& answer)
{
	
	int length = 1;
	int position = firstPosition + firstLength;
	
	if (position >= str.length() - 1) {
		if (position == str.length()) return true;
		return false;
	}

	string temp2 = "";
	while (true)
	{
		temp2 = str.substr(position, length);
		if (binary_search(dict.begin(), dict.end(), temp2) || temp2 == "")
		{
			if (sentenceAfterCheck(dict, position, str, length, answer)) {
				answer.insert(0, temp2+" ");
				return true;
			}
				
			else {
				length++;
			}
		}
		else if (length <= temp2.length()) {
			length++;
		}
		else {
			return false;
		}
	}
}

