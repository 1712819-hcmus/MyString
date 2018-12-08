#include"ThuVien.h"


#pragma region Member Functions 
MyString::MyString()
{
	C = NULL;
}
MyString::MyString(const MyString& Src)
{
	int Len = strlen(Src.C);
	C = new char[Len + 1];
	strcpy(C, Src.C);
}
MyString::MyString(const MyString& Src, int Index, int Count)
{
	int Len = strlen(Src.C);
	if (Index < Len)
	{
		C = new char[Count+1];
		if (Index + Count > Len)
			Count = Len - Index;
		for (int i = 0; i < Count; i++)
			C[i] = Src.C[Index + i];
		C[Count] = NULL;
	}
}
MyString::MyString(const char* Src)
{
	C = new char[strlen(Src) + 1];
	strcpy(C, Src);
}
MyString::MyString(const char* Src, int Count)
{
	C = new char[Count + 1];
	int Len = strlen(Src);
	if (Count > Len)
		Count = Len;
	for (int i = 0; i < Count; i++)
		C[i] = Src[i];
	C[Count] = NULL;
}
MyString::MyString(int Size, char Temp)
{
	C = new char[Size + 1];
	for (int i = 0; i < Size; i++)
		C[i] = Temp;
	C[Size] = NULL;
}
MyString::MyString(iterator First, iterator Last)
{
	vector<char> Src;
	for (auto i = First; i != Last; i++)
		Src.push_back(*i);
	int Len = Src.size();
	C = new char[Len + 1];
	C[Len] = NULL;
	for (int i = 0; i < Len; i++)
		C[i] = Src[i];
}
MyString::~MyString()
{
	delete[] C;
	C = NULL;
}
MyString& MyString:: operator=(const MyString& Src)
{
	if (this != NULL)
	{
		int Len = strlen(Src.C);
		delete[] C;
		C = new char[Len + 1];
		for (int i = 0; i < Len; i++)
			C[i] = Src.C[i];
		C[Len] = NULL;
	}
	return *this;
}
MyString& MyString::operator=(const char* Src)
{
	int Len = strlen(Src);
	C = new char[Len + 1];
	strcpy(C, Src);
	return *this;
}
MyString& MyString::operator=(const char Src)
{
	C = new char[2];
	C[0] = Src;
	C[1] = NULL;
	return *this;
}
#pragma endregion




#pragma region  Non-member functions overloads 
bool MyString::operator==(const MyString& Src)
{
	return operator==(Src.C);
}
bool MyString::operator==(const char* Src)
{
	return strcmp(C, Src) == 0?true : false;
}
bool MyString::operator!=(const MyString& Src)
{
	return operator!=(Src.C);
}
bool MyString::operator!=(const char* Src)
{
	return strcmp(C, Src) != 0 ? true : false;
}
bool MyString::operator<(const MyString& Src)
{
	return operator<(Src.C);
}
bool MyString::operator<(const char* Src)
{
	return strcmp(C, Src) <0 ? true : false;
}
bool MyString::operator<=(const MyString& Src)
{
	return operator<=(Src.C);
}
bool MyString::operator<=(const char* Src)
{
	return strcmp(C, Src) <= 0 ? true : false;
}
bool MyString::operator>(const MyString& Src)
{
	return operator>(Src.C);
}
bool MyString::operator>(const char* Src)
{
	return strcmp(C, Src) > 0 ? true : false;
}
bool MyString::operator>=(const MyString& Src)
{
	return operator>=(Src.C);
}
bool MyString::operator>=(const char* Src)
{
	return strcmp(C, Src) >= 0 ? true : false;
}
istream& operator>>(istream& Indev, MyString& Src)
{
	Src.C = new char[10000];
	int i = 0;
	char Temp = ' ';
	while (Temp !='\n')
	{
		Temp = getchar();
		Src.C[i] = Temp;
		i++;
	}
	Src.C[i-1] = NULL;  //  Do i nhận giá trị getchar cuối cùng là khoảng trắng ' '
	return Indev;
}
ostream& operator<<(ostream& Outdev, const MyString& Src)
{
	int Len = strlen(Src.C);
	for (int i = 0; i < Len; i++)
		Outdev << Src.C[i];
	return Outdev;
}
MyString& MyString:: operator+(MyString&Src)
{
	return operator+(Src.C);
}
MyString& MyString::operator+(const char* Src)
{
	int Len1 = strlen(C);
	int Len2 = strlen(Src);
	MyString* Temp = new MyString;
	Temp->C = new char[Len1 + Len2 + 1];
	for (int i = 0; i < Len1; i++)
		Temp->C[i] = C[i];
	for (int i = Len1; i < Len1 + Len2; i++)
		Temp->C[i] = Src[i - Len1];
	Temp->C[Len1 + Len2] = NULL;
	return *Temp;
}
istream& getline(istream& Indev, MyString& Src)
{
	Indev >> Src;
	return Indev;
}
#pragma endregion




#pragma region Capacity  
int MyString::length()
{
	return strlen(C);
}
int MyString::size()
{
	return strlen(C);
}
int MyString::capacity()
{
	return strlen(C)+1;
}
void MyString::clear()
{
	int Len = strlen(C);
	for (int i = 0; i < Len; i++)
		C[i] = NULL;
	C = NULL;
}
bool MyString::empty()
{
	if (C == NULL)
		return true;
	else
		return false;
}
MyString& MyString:: resize(int Size)
{
	int Len = strlen(C);
	if(Size<Len)
	{
		char* Temp = new char[Len + 1];
		strcpy(Temp, C);
		C = new char[Size + 1];
		for (int i = 0; i < Size; i++)
			C[i] = Temp[i];
		C[Size] = NULL;
		delete[] Temp;
	}
	return *this;
}
MyString& MyString::resize(int Size,char Replace)
{
	int Len = strlen(C);
	if (Size != Len)
	{
		char* Temp = new char[Len + 1];
		strcpy(Temp, C);
		C = new char[Size + 1];
		for (int i = 0; i < Size; i++)
			C[i] = Temp[i];
		if (Size > Len)
		{
			for (int i = Len; i < Size; i++)
				C[i] = Replace;
		}
		C[Size] = NULL;
		delete[] Temp;
	}
	return *this;
}
const int MyString::max_size()
{
	return MAX;
}
#pragma endregion




#pragma region Element access 
char& MyString::front()
{
	return C[0];
}
const char& MyString::front()const
{
	return C[0];
}
char& MyString::back()
{
	return C[strlen(C) - 1];
}
const char& MyString::back()const
{
	return C[0];
}

char& MyString::at(int pos)
{
	int Len = strlen(C);
	if (pos >= Len)
		throw  MyStringException("Error method at");
	else
		return C[pos];
}
char& MyString::operator[](const int Pos)
{
	int Len = strlen(C);
	if (Pos >= Len || Pos < 0)
		throw MyStringException("Error operrator[]");
	else
		return C[Pos];
}
const char& MyString::operator[](const int Pos)const
{
	int Len = strlen(C);
	if (Pos >= Len || Pos < 0)
		throw MyStringException("Error operrator[]");
	else
		return C[Pos];
}

#pragma endregion
 



#pragma region Modifiers 
MyString& MyString:: operator+=(const MyString& Src)
{
	return operator+=(Src.C);
}
MyString& MyString::operator+=(const char* Src)
{

	int Len1 = strlen(C);
	int Len2 = strlen(Src);
	char* Temp = new char[Len1 + 1];
	Temp = strcpy(Temp, C);  
	delete[] C;
	C = new char[Len1 + Len2 + 1];
	for (int i = 0; i < Len1; i++)
	{
		C[i] = Temp[i];
	}
	delete[] Temp;
	for (int i = Len1; i < Len1 + Len2; i++)
		C[i] = Src[i - Len1];
	C[Len1 + Len2] = NULL;
	return *this;
}
MyString& MyString::operator+=(char c)
{
	char* Src = new char[2];
	Src[0] = c;
	Src[1] = NULL;
	return operator+=(Src);
}
void MyString::swap(MyString& Src)
{
	char*Temp = new char[strlen(C)+1];
	Temp = strcpy(Temp, C);
	C = strcpy(C, Src.C);
	Src.C = strcpy(Src.C, Temp);
	delete[] Temp;
}
void MyString::push_back(const char Src)
{

	int Len = strlen(C);
	char* Temp = new char[Len + 1];
	Temp = strcpy(Temp, C);
	//C = new char(Len + 2);
	for (int i = 0; i <Len; i++)
		C[i] = Temp[i];
	C[Len] = Src;
	C[Len + 1] = NULL;
	delete[] Temp;
}
void MyString::pop_back()
{
	int Len = strlen(C);
	C[Len-1] = NULL;
}
MyString& MyString:: append(const MyString& Src)
{
	int Len = strlen(C) + strlen(Src.C);
	strcat(C, Src.C);
	C[Len] = NULL;
	return *this;
}
MyString& MyString::append(const char* Src)
{
	int Len = strlen(C) + strlen(Src);
	strcat(C, Src);
	C[Len] = NULL;
	return *this;
}
MyString& MyString::append(const MyString& Src, int SubPos, int SubLen)
{
	char* Temp = new char[SubLen + 1];
	for (int i = SubPos; i < SubPos + SubLen; i++)
		Temp[i - SubPos] = Src.C[i];
	Temp[SubLen] = NULL;
	strcat(C, Temp);
	delete[] Temp;
	return *this;
}
MyString& MyString::append(const char* Src, int Size )
{
	char* Temp = new char[Size + 1];
	for (int i = 0; i < Size; i++)
		Temp[i] = Src[i];
	Temp[Size] = NULL;
	strcat(C, Temp);
	delete[]Temp;
	return *this;
}
MyString& MyString:: append(int Count, char c)
{
	char* Temp = new char[Count + 1];
	for (int i = 0; i < Count; i++)
		Temp[i] = c;
	Temp[Count] = NULL;
	strcat(C, Temp);
	delete[]Temp;
	return *this;
}
MyString& MyString::append(iterator Start, iterator End)
{
	vector<char>Temp;
	for (MyString::iterator i = Start; i != End; i++)
		Temp.push_back(*i);
	int Len = Temp.size();
	char* TempCopy = new char[Len + 1];
	for (int i = 0; i < Len; i++)
		TempCopy[i] = Temp[i];
	TempCopy[Len] = NULL;
	strcat(C, TempCopy);
	return *this;
}
MyString& MyString::assign(const MyString& Src)
{
	int Len = strlen(Src.C);
	C = new char[Len + 1];
	strcpy(C, Src.C);
	return *this;
}
MyString& MyString::assign(const MyString& Src, int SubPos, int SubLen)
{
	C = new char[SubLen + 1];
	for (int i = SubPos; i < SubLen + SubPos; i++)
		C[i - SubPos] = Src.C[i];
	C[SubLen] = NULL;
	return *this;
}
MyString& MyString::assign(const char* Src, int Count)
{
	C = new char[Count + 1];
	C[Count] = NULL;
	for (int i = 0; i < Count; i++)
		C[i] = Src[i];
	return *this;
}
MyString& MyString::assign(int Count, char c)
{
	C = new char[Count + 1];
	for (int i = 0; i < Count; i++)
		C[i] = c;
	C[Count] = NULL;
	return *this;
}
MyString& MyString::assign(iterator Start, iterator End)
{
	vector<char>Temp;
	for (MyString::iterator i = Start; i != End; i++)
		Temp.push_back(*i);
	int Len = Temp.size();
	C = new char[Len + 1];
	for (int i = 0; i < Len; i++)
		C[i] = Temp[i];
	C[Len] = NULL;
	return *this;
}
MyString& MyString::insert(int Pos, const MyString& Src)
{
	return insert(Pos, Src.C);
}
MyString& MyString::insert(int Pos, const MyString& Src1, int SubPos, int SubLen)
{
	char* Src = new char[SubLen + 1];
	Src[SubLen] = NULL;
	for (int i = SubPos; i < SubPos + SubLen; i++)
		Src[i - SubPos] = Src1.C[i];
	return insert(Pos, Src);
}
MyString& MyString::insert(int Pos, const char* Src)
{
	int Len1 = strlen(C);
	int Len2 = strlen(Src);
	if (Pos > Len1)
		Pos = Len1 - 1;
	char* Temp = new char[Len1 + 1];
	strcpy(Temp, C);
	C = new char[Len1 + Len2 + 1];
	for (int i = 0; i < Pos; i++)
		C[i] = Temp[i];
	strcpy(C + Pos + Len2, Temp + Pos);
	for (int i = Pos; i < Pos + Len2; i++)
		C[i] = Src[i - Pos];
	C[Len1 + Len2] = NULL;
	return *this;
}
MyString& MyString::insert(int Pos, const char* Src1, int n)
{
	char * Src = new char[n + 1];
	Src[n] = NULL;
	for (int i = 0; i < n; i++)
		Src[i] = Src1[i];
	return insert(Pos, Src);
}
MyString& MyString::insert(int Pos, int Count, char c)
{
	char* Src = new char[Count + 1];
	Src[Count] = NULL;
	for (int i = 0; i < Count; i++)
		Src[i] = c;
	return insert(Pos, Src);
}
MyString::iterator MyString::insert(iterator P, char c)
{
	int j = 0;
	for (auto i = begin(); i != end(); i++, j++)
	{
		if (i == P)
			break;
	}
	insert(j, 1,c);
	return begin() + j;
}
MyString& MyString::erase(int Index, int Count)
{
	int Len = strlen(C);
	if (Index < Len)
	{
		if (Len - Index < Count)
			Count = Len - Index - 1;
		char* Temp = new char[Len + 1];
		strcpy(Temp, C);
		C = new char[Len - Count + 1];
		for (int i =
 0; i < Index; i++)
			C[i] = Temp[i];
		strcpy(C + Index, Temp + Index + Count);
		delete[]Temp;
	}
	return *this;
}
MyString::iterator MyString:: erase(iterator P)
{
	int j = 0;
	for (auto i = begin(); i != end(); i++, j++)
	{
		if (i == P)
			break;
	}
	erase(j, 1);
	return begin() + j;
}
MyString::iterator MyString::erase(iterator Fist, iterator Last)
{
	int Temp1 = 0, Temp2 = 0;
	int j = 0;
	for (auto i = begin(); i != end(); i++, j++)
	{
		if (i == Fist)
			Temp1 = j;
		else if (i == Last)
			Temp2 = j;
	}
	erase(Temp1, Temp2 - Temp1);
	return begin() + Temp2 - Temp1;
}
MyString& MyString::replace(int Index, int Count, const MyString& Src)
{
	return replace(Index, Count, Src.C);
}
MyString& MyString::replace(int Index, int Count, const char* Src)
{
	int Len1 = strlen(C);
	int Len2 = strlen(Src);
	if (Index + Count > Len1)
		Count = Len1 - Index;
	char* Temp = new char[Len1 + 1];
	strcpy(Temp, C);
	C = new char[Len1 + Len2 - Count + 1];
	for (int i = 0; i < Index; i++)
		C[i] = Temp[i];
	if (Count + Index < Len1)
		strcpy(C + Index + Len2, Temp + Index + Count);
	for (int i = Index; i < Index + Len2; i++)
		C[i] = Src[i - Index];
	C[Len1 + Len2 - Count] = NULL;
	return *this;
}
MyString& MyString::replace(iterator First, iterator Last, const MyString& Src)
{
	return replace(First, Last, Src.C);
}
MyString& MyString::replace(int Pos, int Count, const MyString& Src1, int SubPos, int SubCount)
{
	char* Src = new char[SubCount + 1];
	Src[SubCount] = NULL;
	for (int i = SubPos; i < SubCount+SubPos; i++)
		Src[i - SubPos] = Src1.C[i];
	return replace(Pos, Count, Src);
}
MyString& MyString::replace(iterator First, iterator Last, const char* Src)
{

	int Temp1 = 0, Temp2 = 0;
	int j = 0;
	for (auto i = begin(); i != end(); i++, j++)
	{
		if (i == First)
			Temp1 = j;
		else if (i == Last)
			Temp2 = j;
	}
	return replace(Temp1, Temp2 - Temp1, Src);
}
MyString& MyString::replace(int Pos, int Len, const char* Src1, int Count)
{
	char* Src = new char[Count + 1];
	Src[Count] = NULL;
	for (int i = 0; i < Count; i++)
		Src[i] = Src1[i];
	return replace(Pos, Len, Src);
}
MyString& MyString::replace(iterator First, iterator Last, const char* Src1, int Count)
{
	int Temp1 = 0, Temp2 = 0;
	int j = 0;
	for (auto i = begin(); i != end(); i++, j++)
	{
		if (i == First)
			Temp1 = j;
		else if (i == Last)
			Temp2 = j;
	}
	return replace(Temp1, Temp2 - Temp1, Src1, Count);
}
MyString& MyString::replace(int Pos, int Len, int n, char c)
{
	char* Src = new char[n + 1];
	Src[n] = NULL;
	for (int i = 0; i < n; i++)
		Src[i] = c;
	return replace(Pos, Len, Src);
}
MyString& MyString::replace(iterator First, iterator Last, int n, char c)
{
	char* Src = new char[n + 1];
	Src[n] = NULL;
	for (int i = 0; i < n; i++)
		Src[i] = c;
	return replace(First, Last, Src);
}
#pragma endregion



#pragma region MyString operations 
int MyString::compare(MyString& Src)const
{
	return strcmp(C, Src.C);
}
int MyString::compare(int Pos, int Len, const MyString& Src) const
{
	char* Temp = new char[Len + 1];
	for (int i = Pos; i < Pos + Len; i++)
		Temp[i - Pos] = C[i];
	Temp[Len] = NULL;
	return strcmp(Temp, Src.C);
}
int MyString::compare(int Pos, int Len, const MyString& Src, int SubPos, int SubLen)const
{
	char* Temp1 = new char[Len + 1];
	for (int i = Pos; i < Pos + Len; i++)
		Temp1[i - Pos] = C[i];
	Temp1[Len] = NULL;
	char* Temp2 = new char[SubLen + 1];
	for (int i = SubPos; i < SubPos + SubLen; i++)
		Temp2[i - SubPos] = Src.C[i];
	Temp2[SubLen] = NULL;
	return strcmp(Temp1, Temp2);
}
int MyString::compare(const char* Src)const
{
	return strcmp(Src, C);
}
int MyString::compare(int Pos, int Len, const char* Src, int n)const
{
	char* Temp = new char[Len + 1];
	for (int i = Pos; i < Pos + Len; i++)
		Temp[i - Pos] = C[i];
	Temp[Len] = NULL;
	char* Temp1 = new char[n + 1];
	for (int i = 0; i < n; i++)
		Temp1[i] = Src[i];
	Temp1[n] = NULL;
	return strcmp(Temp, Temp1);
}
int MyString::find(const char* Src,int Index)const
{
	int Len1 = strlen(C);
	int Len2 = strlen(Src);
	if (Len1 - Index < Len2)
		return MAX;
	for (int i = Index; i < Len1 - Len2 + 1; i++)
	{
		int Dem = 0;
		int Pos = i;
		for (int j = 0; j < Len2; j++)
		{
			if (C[Pos] != Src[j])
				break;
			else
			{
				Pos++;
				Dem++;
			}
			if (Dem == Len2)
				return i;
		}
	}
	return MAX;
}
int MyString::find(const MyString& Src, int Index )const
{
	int Len1 = strlen(C);
	int Len2 = strlen(Src.C);
	if (Len1 - Index < Len2)
		return -1;
	for (int i = Index; i < Len1 - Len2 + 1; i++)
	{
		int Dem = 0;
		int Pos = i;
		for (int j = 0; j < Len2; j++)
		{
			if (C[Pos] != Src.C[j])
				break;
			else
			{
				Pos++;
				Dem++;
			}
			if (Dem == Len2)
				return i;
		}
	}
	return -1;
}
int MyString::find(char c, int Pos )const
{
	int Len = strlen(C);
	for (int i = Pos; i < Len; i++)
		if (C[i] == c)
			return i;
	return -1;
}
int MyString::find(const char* S, int Index, int Len2)const
{
	char* Src = new char[Len2 + 1];
	for (int i = 0; i < Len2; i++)
		Src[i] = S[i];
	Src[Len2] = NULL;
	int Len1 = strlen(C);
	if (Len1 - Index < Len2)
		return -1;
	for (int i = Index; i < Len1 - Len2 + 1; i++)
	{
		int Dem = 0;
		int Pos = i;
		for (int j = 0; j < Len2; j++)
		{
			if (C[Pos] != Src[j])
				break;
			else
			{
				Pos++;
				Dem++;
			}
			if (Dem == Len2)
				return i;
		}
	}
	return -1;

}
int MyString::rfind(const char* Src, int Index)const
{
	int Len1 = strlen(C);
	if (Index == MAX || Index>Len1)
		Index = Len1- 1;
	int Len2 = strlen(Src);
	if (Index - 1 < Len2)
		return MAX;
	for (int i = Index;  i >=Len2-1; i--)
	{
		int Dem = 0;
		int Pos = i;
		for (int j = Len2-1; j >=0; j--)
		{
			if (C[Pos] != Src[j])
				break;
			else
			{
				Pos--;
				Dem++;
			}
			if (Dem == Len2)
				return i-Len2+1;
		}
	}
	return MAX;
}
int MyString::rfind(const MyString& Src, int Pos )const
{
	return rfind(Src.C, Pos);
}
int MyString::rfind(const char* Src1, int Pos, int n)const
{
	char* Src = new char[n + 1];
	Src[n] = NULL;
	for (int i = 0; i < n; i++)
		Src[i] = Src1[i];
	return rfind(Src, Pos);
}
int MyString::rfind(char c, int Index)const
{

	int Len = strlen(C);
	if (Index == MAX || Index > Len)
		Index = Len - 1;
	for (int i = Index; i >= 0; i--)
		if (C[i] == c)
			return i;

}
int MyString::find_first_of(const char* Src, int Pos)const
{
	int Len1 = strlen(C);
	int Len2 = strlen(Src);
	for (int i = 0; i < Len1; i++)
		for (int j = 0; j < Len2; j++)
			if (Src[j] == C[i])
				return i;
	return MAX;
}
int MyString::find_first_of(const MyString& Src, int Pos )const
{
	return find_first_of(Src.C, Pos);
}
int MyString::find_first_of(const char* Src1, int Pos, int n)const
{
	char* Src = new char[n + 1];
	Src[n] = NULL;
	for (int i = 0; i < n; i++)
		Src[i] = Src1[i];
	return find_first_of(Src, Pos);
}
int MyString::find_first_of(char c, int Pos)const
{
	int Len = strlen(C);
	for (int i = Pos; i < Len; i++)
		if (C[i] == c)
			return i;
	return MAX;
}
int MyString::find_last_of(const char* Src, int Pos )const
{
	int Len1 = strlen(C);
	if (Pos > Len1)
		Pos = Len1 - 1;
	int Len2 = strlen(Src);
	for (int i = Pos; i > -1; i--)
		for (int j = 0; j < Len2; j++)
			if (Src[j] == C[i])
				return i;
	return MAX;
}
int MyString::find_last_of(const MyString& Src, int Pos)const
{
	return find_last_of(Src.C, Pos);
}
int MyString::find_last_of(const char* Src1, int Pos, int n)const
{
	char* Src = new char[n + 1];
	Src[n] = NULL;
	for (int i = 0; i < n; i++)
		Src[i] = Src1[i];
	return find_last_of(Src, Pos);
}
int MyString::find_last_of(char c, int Pos )const
{
	for (int i = Pos; i>=0; i--)
		if (C[i] == c)
			return i;
	return MAX;
}
bool IsNot(char c, const char* Src)
{
	int Len = strlen(Src);
	for (int i = 0; i < Len; i++)
		if (c == Src[i])
			return false;
	return true;
}
int MyString::find_first_not_of(const char* Src, int Pos )const
{
	int Len1 = strlen(C);
	for (int i = 0; i < Len1; i++)
		if (IsNot(C[i], Src))
			return i;
	return MAX;
}
int MyString::find_first_not_of(const MyString& Src, int Pos)const
{
	return find_first_not_of(Src.C, Pos);
}
int MyString::find_first_not_of(const char* Src1, int Pos, int n)const
{
	char* Src = new char[n + 1];
	Src[n] = NULL;
	for (int i = 0; i < n; i++)
		Src[i] = Src1[i];
	return find_first_not_of(Src, Pos);
}
int MyString::find_first_not_of(char c, int Pos)const
{
	int Len = strlen(C);
	for (int i = Pos; i < Len; i++)
		if (C[i] != c)
			return i;
	return MAX;
}
int MyString::find_last_not_of(const char* Src, int Pos)const
{
	int Len1 = strlen(C);
	if (Pos > Len1)
		Pos = Len1 - 1;
	for (int i = Pos; i >=0; i--)
		if (IsNot(C[i], Src))
			return i;
	return MAX;
}
int MyString::find_last_not_of(const MyString& Src, int Pos)const
{
	return find_last_not_of(Src.C, Pos);
}
int MyString::find_last_not_of(const char* Src1, int Pos, int n)const
{
	char* Src = new char[n + 1];
	Src[n] = NULL;
	for (int i = 0; i < n; i++)
		Src[i] = Src1[i];
	return find_last_not_of(Src, Pos);
}
int MyString::find_last_not_of(char c, int Pos)const
{
	int Len = strlen(C);
	for (int i = Pos; i >=0; i--)
		if (C[i] != c)
			return i;
	return MAX;
}
int MyString::copy(char* Src, int Len, int Pos)
{
	for (int i = Pos; i < Pos + Len; i++)
		Src[i - Pos] = C[i];
	return Len;
}
const char* MyString::c_str()const
{
	return C;
}
const char* MyString::data()const
{
	return C;
}
MyString MyString::substr(int Pos , int Len )
{
	int Len1 = strlen(C);
	if (Len > Len1)
		Len = Len1;
	MyString Temp;
	Temp.C = new char[Len + 1];
	Temp.C[Len] = NULL;
	for (int i = Pos; i < Pos + Len; i++)
		Temp.C[i-Pos] = C[i];
	return Temp;
}
#pragma endregion



#pragma region Iterator
MyString::iterator MyString:: begin()
{
	return C + 0;
}
const MyString::iterator MyString::begin()const
{
	return C + 0;
}
MyString::iterator MyString:: end()
{
	int Length = strlen(C);
	return C + Length;
}
const MyString::iterator MyString::end() const
{
	int Length = strlen(C);
	return C + Length;
}
MyString::reverse_iterator MyString::rbegin()
{
	int Length = strlen(C);
	return C + Length-1;
}
const MyString::reverse_iterator MyString::rbegin()const
{
	int Length = strlen(C);
	return C + Length-1;
}
MyString::reverse_iterator MyString::rend()
{
	return C -1;
}
const MyString::reverse_iterator MyString::rend() const
{
	return C -1;
}
const MyString::iterator MyString::cbegin() noexcept
{
	return C + 0;
}
const MyString::iterator MyString::cend() noexcept
{
	int Length = strlen(C);
	return C + Length;
}
const MyString::reverse_iterator MyString::crbegin() noexcept
{
	int Length = strlen(C);
	return C + Length-1;
}
const MyString::reverse_iterator MyString::crend() noexcept
{
	return C-1;
}

#pragma endregion




#pragma region Setting class iterator of class Mystring

MyString::iterator::iterator(char* x)
{
	Location = x;
}
MyString::iterator::iterator()
{
	Location = NULL;
}
MyString::iterator MyString::iterator::operator=(char* Src)
{
	Location = Src;
	return *this;
}
char MyString::iterator::operator*()
{
	return *Location;
}
MyString::iterator& MyString::iterator::operator+=(int Idex)
{
	Location += Idex;
	return *this;
}
MyString::iterator&  MyString::iterator::operator++()
{
	Location++;
	return *this;
}
MyString::iterator MyString::iterator::operator++(int)
{
	iterator Temp = *this;
	++(*this);
	return Temp;
}
MyString::iterator& MyString::iterator::operator--()
{
	Location--;
	return *this;
}
MyString::iterator MyString::iterator::operator--(int)
{
	iterator Temp = *this;
	--(*this);
	return Temp;
}
bool MyString::iterator::operator==(iterator Src)
{
	return Location == Src.Location;
}
bool MyString::iterator::operator!=(iterator Src)
{
	return Location != Src.Location;
}
MyString::iterator& MyString::iterator::operator+(int Idex)
{
	iterator Temp;
	Temp.Location = Location + Idex;
	return Temp;
}
const MyString::iterator MyString::iterator::operator+(int Idex)const
{
	iterator Temp;
	Temp.Location = Location + Idex;
	return Temp;
}
const MyString::iterator MyString::iterator::operator-(int Idex)const
{
	iterator Temp;
	Temp.Location = Location - Idex;
	return Temp;
}

#pragma endregion




#pragma region  Setting class reverse_iterator of class Mystring
MyString::reverse_iterator::reverse_iterator(char* x)
{
	Location = x;
}
MyString::reverse_iterator::reverse_iterator()
{
	Location = NULL;
}
MyString::reverse_iterator MyString::reverse_iterator::operator=(char* Src)
{
	Location = Src;
	return *this;
}
char MyString::reverse_iterator::operator*()
{
	return *Location;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator+=(int Idex)
{
	Location -= Idex;
	return *this;
}
MyString::reverse_iterator&  MyString::reverse_iterator::operator++()
{
	Location--;
	return *this;
}
MyString::reverse_iterator MyString::reverse_iterator::operator++(int)
{
	reverse_iterator Temp = *this;
	++(*this);
	return Temp;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator--()
{
	Location++;
	return *this;
}
MyString::reverse_iterator MyString::reverse_iterator::operator--(int)
{
	reverse_iterator Temp = *this;
	--(*this);
	return Temp;
}
bool MyString::reverse_iterator::operator==(reverse_iterator Src)
{
	return Location == Src.Location;
}
bool MyString::reverse_iterator::operator!=(reverse_iterator Src)
{
	return Location != Src.Location;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator+(int Idex)
{
	reverse_iterator Temp;
	Temp.Location = Location - Idex;
	return Temp;
}
const MyString::reverse_iterator MyString::reverse_iterator::operator+(int Idex)const
{
	reverse_iterator Temp;
	Temp.Location = Location - Idex;
	return Temp;
}
const MyString::reverse_iterator MyString::reverse_iterator::operator-(int Idex)const
{
	reverse_iterator Temp;
	Temp.Location = Location + Idex;
	return Temp;
}

#pragma endregion








