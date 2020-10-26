#include <iostream>
#include <string>

using namespace std;

int main()
{
	int case_counter[8] = {0,1,2,3,4,5,6,7};
	string mail_name;
	int i = 1;//Переходы между кейсами
	int j = 0;//Номер буквы в слове
	int length = 0;//длина слова
	int numbers_of_domains = 0;//кол-во доменов
	const int max = 63;//Максимальное кол-во символов в адресе

	string s;

	cin >> mail_name;

	do {
		switch (case_counter[i]) {
		case 1:
			if (('A' <= mail_name[j]) && (mail_name[j] <= 'Z') || (('a' <= mail_name[j]) && (mail_name[j] <= 'z')) || (('0' < mail_name[j]) && (mail_name[j] <= '9')) || (mail_name[j] == '_')
				|| (mail_name[j] == '-'))
			{
				s += mail_name[j];
				length++;
				i = 2;
			}
			else if ((mail_name[j] == '\n') || (mail_name[j] == '@'))
			{
				s += mail_name[j];
				i = 5;
			}
			else
			{
				s += mail_name[j];
				i = 5;
			}
			break;
		case 2:
			if((('A' <= mail_name[j]) && (mail_name[j] <= 'Z') || (('a' <= mail_name[j]) && (mail_name[j] <= 'z')) || (('0' < mail_name[j]) && (mail_name[j] <= '9')) || (mail_name[j] == '_')
				|| (mail_name[j] == '-'))&&(length<=max))
			{
				s += mail_name[j];
				length++;
				i = 2;
			}
			else if ((mail_name[j] == '@')&&(length<=max))
			{
				s += mail_name[j];
				length++;
				i = 3;
			}
			else
			{
				s += mail_name[j];
				i = 5;
			};
			break;
		case 3:
			if (('A' <= mail_name[j]) && (mail_name[j] <= 'Z') || (('a' <= mail_name[j]) && (mail_name[j] <= 'z')) || (('0' < mail_name[j]) && (mail_name[j] <= '9')) || (mail_name[j] == '_')
				|| (mail_name[j] == '-')&&(length <= max))
			{
				s += mail_name[j];
				length++;
				i = 3;
			}
			else if ((mail_name[j] == '.')&&(length <= max))
			{
				s += mail_name[j];
				length++;
				numbers_of_domains++;
				i = 4;
			}
			else if ((mail_name[j] == '\0')&&(length<=max))
			{
				i = 6;
				numbers_of_domains++;
			}
			else
			{
				s += mail_name[j];
				i = 5;
			};
			break;
		case 4:
			if ((('A' <= mail_name[j]) && (mail_name[j] <= 'Z') || (('a' <= mail_name[j]) && (mail_name[j] <= 'z')) || (('0' < mail_name[j]) && (mail_name[j] <= '9')) || (mail_name[j] == '_')
				|| (mail_name[j] == '-'))&& (length <= max))
			{
				s += mail_name[j];
				length++;
				i = 3;
			}
			else
			{
				s += mail_name[j];
				i = 5;
			}
			break;
		case 5:
			cout << "The email adrees: " << s << " is not correct!" << endl;
			i = 0;
			break;
		case 6:
			if (numbers_of_domains >= 2)
			{
				cout << "good!" << endl;
				i = 7;
			}
			else
			{
				i = 5;
			}
			break;
		case 7:
			cout << "The email adress: " << s << " is correct!" << endl;
			i = 0;
			break;
		}
			j++;
	} while (case_counter[i] != 0);
}