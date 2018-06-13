#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	short a;
	cout << "1 - fruits\n2 - colors\n3 - dictionary\n";
	cin >> a;

	system("cls");

	switch (a) {
	case 1: {
		map<string, string> fruits;
		fruits["apple"] = "green";
		fruits["banana"] = "yellow";
		fruits["apple"] = "red";
		fruits["peach"] = "yellow";
		fruits["ananas"] = "brown";


		for (map<string, string>::iterator it = fruits.begin(); it != fruits.end(); it++)
			cout << it->first << "\t" << it->second << endl;

	}break;

	case 2: {
		map<int, string> colors;
		colors[1] = "green";
		colors[6] = "yellow";
		colors[3] = "red";
		colors[2] = "yellow";
		colors[9] = "brown";
		colors.erase(9);

		for (map<int, string>::iterator it = colors.begin(); it != colors.end(); it++)
			cout << it->first << "\t" << it->second << endl;

		auto it = colors.find(3);
		cout << it->second << endl;
		colors.erase(it->first);

		for (map<int, string>::iterator it = colors.begin(); it != colors.end(); it++)
			cout << it->first << "\t" << it->second << endl;
	}break;

	case 3: {
		map<string, string> dict;
		ifstream in_file("dictionary.txt");
		string word, description;

		if (!in_file) {
			cerr << "file open error\n";
		}
		else {
			while (!in_file.eof()) {
				getline(in_file, word, '/');
				getline(in_file, description);
				dict[word] = description;
			}
		}


		for (auto it = dict.begin(); it != dict.end(); it++)
			cout << it->first << "\t" << it->second << endl;


		while (true) {
			cout << "1 - add a word" << endl
				<< "2 - delete" << endl
				<< "3 - search" << endl
				<< "4 - edit" << endl
				<< "0 - exit" << endl;
			cin >> a;
			system("cls");

			switch (a) {
			case 1:
			{
				cout << "введите слово: "; cin >> word;
				cout << "введите описание слова: "; cin >> description;
				dict[word] = description;
				for (auto it = dict.begin(); it != dict.end(); it++)
					cout << it->first << "\t" << it->second << endl;
			}break;

			case 2:
			{
				cout << "введите слово для удаления: "; cin >> word;
				auto itr = dict.find(word);
				if (itr != dict.end())
					dict.erase(itr->first);

				for (auto it = dict.begin(); it != dict.end(); it++)
					cout << it->first << "\t" << it->second << endl;

			}break;
			case 3: {
				cout << "enter a word to search" << endl;
				cin >> word;
				for (auto it = dict.begin(); it != dict.end(); it++)
				{
					if (strstr(it->first.c_str(), word.c_str()))
						cout << it->first << "\t" << it->second << endl << endl;

				}
			}break;

			case 4:
			{
				cout << "вы хотите поменять само слово - 1; полностью описание - 2?\n:";
				cin >> a;
				switch (a)
				{
				case 1:
				{
					string newWord;
					cout << "введите слово, которое вы хотите поменять: "; cin >> word;
					cout << "введите новое слово, на которое вы хотите поменять: "; cin >> newWord;
					auto itr = dict.find(word);
					if (itr != dict.end())
					{
						dict[newWord] = itr->second;
						dict.erase(itr->first);
					}
					for (auto it = dict.begin(); it != dict.end(); it++)
						cout << it->first << "\t" << it->second << endl;
				}break;

				case 2:
				{
					string newDesc;
					cout << "введите слово, описание которого вы хотите поменять: "; cin >> word;
					cout << "введите новое описание для этого слова: "; cin.ignore();
					getline(cin, newDesc);
					auto itr = dict.find(word);
					if (itr != dict.end())
					{
						dict[word] = newDesc;
					}
					for (auto it = dict.begin(); it != dict.end(); it++)
						cout << it->first << "\t" << it->second << endl;
					system("pause");
				}break;


				}
			}break;

			case 0:
			{
				exit(1);
			}break;

			}
		}
	}break;

	case 4:
	{
		map <string, int> text;
		string word;

		ifstream in;
		in.open("in.txt");

		while (in >> word)
		{
			text[word]++;
		}

		int count = 0;
		for (auto it = text.begin(); it != text.end(); it++)
		{
			cout << it->first << ": " << it->second << endl;
		}

		/*cout << "\n--------------------\n";
		for (auto it = text.begin(); it != text.end(); it++)
		{
			cout << it->first << ": " << text.count(it->first) << endl;
		}*/

		
	}break;

	case 5:
	{
		ifstream in;
		in.open("in.txt");

		map <char, int> texts;
		cout << "\n-------------------------------------------------------------\n";
		char s;
		while (in >> s)
		{
			texts[s]++;
		}

		for (auto its = texts.begin(); its != texts.end(); its++)
		{
			cout << its->first << ": " << its->second << endl;
		}
	}break;
	}
	system("pause");
	return 0;
}