#ifndef LIST
#define LIST

// Объявление библиотек
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string TimeToString(time_t t);
time_t StringToTime(string str);

// Объявление класса Values
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

// Объявление класса Node
template <class T>
class Node
{
    public:
        Node <T> *pNext; // Указатель класа Node на следующий элемент списка
        T data; // Шаблонная переменная для хранения данных
        // Конструктор класса Node
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

// Объявление класса List
template <class T>
class List
{
    public:
        List();
        ~List();
		Values read();
        void FindByTime(string str);
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
        int Size; // Переменная для расчета размера списка
        Node <T> *head; // Указатель класса Node на голову списка
};

#endif