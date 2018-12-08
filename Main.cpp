#include"ThuVien.h"
int main()
{
	MyString x = "NGUYEN THE TINH";
	MyString y = "Creating MyString";
	MyString z = "1712819";
	for (MyString::iterator i = x.begin(); i != x.end(); i++)
		cout << *i;
	cout << '\n';
	for (auto i = y.cbegin(); i != y.cend(); i++)
		cout <<*i;
	cout << '\n';
	for (MyString::reverse_iterator i = z.rbegin(); i != z.rend(); i++)
		cout << *i;
	cout << '\n';
	system("pause");
	return 0;
}

