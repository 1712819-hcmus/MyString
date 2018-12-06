#pragma once
#ifndef __THUVIEN__H
#define __THUVIEN__H
#include<iostream>
#include<vector>
#include<exception>
#include<list>
#define MAX 4294967291
using namespace std;
	class MyString {
	private:
		char* C;
	public:
		char* Get()
		{
			return C;
		}

		// class Iterator
		class iterator
		{
			char* Location;

		public:
			iterator(char* x);
			iterator();
			iterator operator=(char* Src);
			char operator*();
			iterator& operator+=(int Idex);
			iterator&  operator++();
			iterator  operator++(int);
			iterator& operator--();
			iterator  operator--(int);
			bool operator==(iterator Src);
			bool operator!=(iterator Src);
			iterator& operator+(int Idex);
			const iterator operator+(int Idex)const;
			const iterator operator-(int Idex)const;
		};


		// Member Functions
		MyString();
		MyString(const MyString&);
		MyString(const MyString&, int, int);
		MyString(const char*);
		MyString(const char*, int);
		MyString(int, char);
		MyString(iterator, iterator);
		~MyString();
		MyString& operator=(const MyString& Src);
		MyString& operator=(const char* Src);
		MyString& operator=(const char Src);

		//Capacitity
		int length();
		int size();
		int capacity();
		void clear();
		bool empty();
		MyString& resize(int);
		MyString& resize(int, char);
		const int max_size();

		// element access
		char& front();
		const char& front() const;
		char& back();
		const char& back() const;
		char& at(int);
		char& operator[](const int);
		const char& operator[](const int)const;

		//Modifiers
		MyString& operator+=(const MyString& Src);
		MyString& operator+=(const char*);
		MyString& operator+=(char);
		void swap(MyString& Src);
		void push_back(const char Src);
		void pop_back();
		MyString& append(const MyString&);
		MyString& append(const char*);
		MyString& append(const MyString&, int, int);
		MyString& append(const char*, int);
		MyString& append(int, char);
		MyString& append(iterator Start, iterator End);
		MyString& assign(const MyString&);
		MyString& assign(const MyString&, int , int );
		MyString& assign(const char*, int);
		MyString& assign(int , char);
		MyString& assign(iterator, iterator);
		MyString& insert(int, const MyString&);
		MyString& insert(int, const MyString&,int ,int);
		MyString& insert(int, const char*);
		MyString& insert(int , const char*, int);
		MyString& insert(int, int, char);
		iterator insert(iterator, char);
		MyString& erase(int , int);
		iterator erase(iterator);
		iterator erase(iterator, iterator);
		MyString& replace(int, int, const MyString&);
		MyString& replace(iterator, iterator, const MyString&);
		MyString& replace(int, int, const MyString&, int, int);
		MyString& replace(int, int, const char*);
		MyString& replace(iterator, iterator, const char*);
		MyString& replace(int, int, const char*, int);
		MyString& replace(iterator, iterator, const char*, int);
		MyString& replace(int, int, int, char);
		MyString& replace(iterator, iterator, int, char);




		// Non-member function overloads

		bool operator==(const MyString&);
		bool operator==(const char*);
		bool operator!=(const MyString&);
		bool operator!=(const char*);
		bool operator<(const MyString&);
		bool operator<(const char*);
		bool operator<=(const MyString&);
		bool operator<=(const char*);
		bool operator>(const MyString&);
		bool operator>(const char*);
		bool operator>=(const MyString&);
		bool operator>=(const char*);
		friend istream& operator>>(istream& Indev, MyString& Src);
		friend ostream& operator<<(ostream& Outdev, const MyString& Src);
		MyString& operator+(MyString&Src);
		MyString& operator+(const char* );
		friend istream& getline(istream&, MyString&);


		// MyString operations
		int compare(MyString& Src)const;
		int compare(int Pos, int Len, const MyString& Src) const;
		int compare(int Pos, int Len, const MyString& Src, int SubPos, int SubLen)const;
		int compare(const char* Src)const;
		int compare(int Pos, int Len, const char* Src, int n)const;
		int find(const char* Src, int Pos=0)const;
		int find(const MyString& Src, int Pos = 0)const;
		int find(char c, int Pos = 0)const;
		int find(const char* Src, int Pos, int n)const;
		int rfind(const MyString&, int Pos =MAX)const;
		int rfind(const char*, int Pos = MAX)const;
		int rfind(const char*, int, int)const;
		int rfind(char, int Pos = MAX)const;
		int find_first_of(const char*, int Pos = 0)const;
		int find_first_of(const MyString&, int Pos = 0)const;
		int find_first_of(const char*, int ,int)const;
		int find_first_of(char, int Pos = 0)const;
		int find_last_of(const char*, int Pos = MAX)const;
		int find_last_of(const MyString&, int Pos = MAX)const;
		int find_last_of(const char*, int, int)const;
		int find_last_of(char, int Pos = MAX)const;
		int find_first_not_of(const char*, int Pos = 0)const;
		int find_first_not_of(const MyString&, int Pos = 0)const;
		int find_first_not_of(const char*, int, int)const;
		int find_first_not_of(char, int Pos = 0)const;
		int find_last_not_of(const char*, int Pos = MAX)const;
		int find_last_not_of(const MyString&, int Pos = MAX)const;
		int find_last_not_of(const char*, int, int)const;
		int find_last_not_of(char, int Pos = MAX)const;
		int copy(char*, int, int Pos = 0);
		const char* c_str()const;
		const char* data()const;
		MyString substr(int Pos = 0, int Len = MAX);





		//iterator
		iterator begin();
		const iterator begin()const;
		iterator end();
		const iterator end() const;
		
		friend istream& getline(istream&, MyString&);

	};




	//   Class Exception to handlers 
	class MyStringException
	{
	private:
		const char* Ex;
	public:
		MyStringException(const char* Error) :Ex(Error) {}
		const char* Get()
		{
			return Ex;
		}
	};

#endif // DEBUG