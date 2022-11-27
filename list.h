#ifndef LIST
#define LIST

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string TimeToString(time_t t);
time_t StringToTime(string str);

class Values
{
    public:
    int AccountNumber = 0;
    string AccountCode;
    string UserLastname;
    string AccountDeposit;
    time_t date = 0;
    string DepositRate;

    void show();
    Values read();
};

template <class T>
class Node
{
    public:
        Node <T> *pNext;
        T data;
        Node(T newData = T(), Node <T> *pNext = nullptr)
        {
            data.AccountNumber = newData.AccountNumber;
            data.AccountCode = newData.AccountCode;
            data.UserLastname = newData.UserLastname;
            data.AccountDeposit = newData.AccountDeposit;
            data.date = newData.date;
            data.DepositRate = newData.DepositRate;
            this -> data = data;
            this -> pNext = pNext;
        };
        Node <T> *head;
};


template <class T>
class List
{
    public:
        List();
        ~List();
		Values read();
        void FindByTime(string t);
        void FindByUserLastname(string str);
        void FindByAccountNumber(int n);
        void SortByUserLastname();
        void SortByAccountNumber();
		void SortByDate();
		void show();
        void pop_back();
        void remove_at(int index);
        void insert(T data, int index);
        void push_front(T data);
        void clear();
        void pop_front();
        void push_back(T data);
    private:
        int Size;
        Node <T> *head;
};

#endif