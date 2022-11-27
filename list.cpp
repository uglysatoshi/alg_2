#include "list.h"

// Конструктор класса List
template <typename T>
List <T> :: List()
{
    Size = 0;
    head = nullptr;
}

// Деструктор класса List
template <typename T>
List <T> :: ~List()
{
    clear();
};

// Функция добавления элемента в конец списка
template <typename T>
void List <T> :: push_back(T data)
{
    if(head == nullptr)
        head = new Node <T> (data);
    else
    {
        Node<T> *current = this -> head;

        while (current -> pNext != nullptr)
        {
            current = current -> pNext;
        }
        current -> pNext = new Node <T> (data);
    }
    Size++;
}

// Функция удаления элемента из начала списка
template <typename T>
void List <T> :: pop_front()
{
    Node <T> *temp = head;
    head = head -> pNext;
    delete temp;
    Size --;
}

// Функция очистки списка
template <typename T>
void List <T> :: clear()
{
    while(Size)
    {
        pop_front();
    }
}

// Функция добавления элемента в начало списка
template <typename T>
void List <T> :: push_front(T data)
{
    head = new Node <T>(data, head);
    Size ++;
}

// Функция добавления элемента в произвольное место списка
template <typename T>
void List <T> :: insert(T data, int index)
{
    if (index == 0)
        push_front(data);
    else 
    {
        Node <T> *previous =  this -> head;
        for (int i = 0; i < index - 1; i++)
            previous = previous -> pNext;
        previous -> pNext = new Node <T> (data, previous -> pNext);
        Size ++; 
    }   
}

// Функция удаления элемента из произвольного места списка
template <typename T>
void List <T> :: remove_at(int index)
{
    if (index == 0)
        pop_front();
    else 
    {
        Node <T> *previous = this -> head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous -> pNext;
        }
        Node <T> *toDelete = previous -> pNext;
        previous -> pNext  = toDelete -> pNext;
        delete toDelete;
        Size --;
    }
}

// Функция удаления последнего элемента списка
template <typename T>
void List <T> :: pop_back()
{
    remove_at(Size - 1);
}

// Функция конвертирования из string в time_t
time_t StringToTime(string str)
{
    string res = "";
    for (int i = 0; i < str.size(); i++)
    {
    if (str[i] >= '0' and str[i] <= '9')
    {
      res = res + str[i];
    }
    }
    return stoll(res);
}

// Функция конвертирования из time_t в string
string TimeToString(time_t t)
{
    string in = to_string(t);
    string res = in.substr(0, 4) + "." + in.substr(4, 2) + "." + in.substr(6, 2) + " " + in.substr(8, 2) + ":" + in.substr(10, 2);
    return res; 
}

// Функция вывода для переменной типа Values
void Values :: show()
{
    cout << "Номер счета: " << AccountNumber << endl;
    cout << "Код счета: " << AccountCode << endl;
    cout << "Фамилия владельца: " << UserLastname << endl;
    cout << "Сумма на счете: " << AccountDeposit << endl;
    cout << "Дата открытия счета: " << TimeToString(date) << endl;
    cout << "Годовой процент начисления: " << DepositRate << endl;
}

// Функция ввода переменной типа Values
template <typename T>
Values List<T> :: read()
{
    Values in;
    string temp1, temp2;
    cout << "Введите номер счета: "; cin >> in.AccountNumber;
    cout << "Введите код счета: "; cin >> in.AccountCode;
    cout << "Введите фамилию владельца: "; cin >> in.UserLastname;
    cout << "Введите сумму на счете: "; cin >> in.AccountDeposit;
    cout << "Введите дату в формате (гггг.мм.дд): "; cin >> temp1;
    cout << "Введите время в формате (чч:мм): "; cin >> temp2;
    temp1 = temp1 + temp2; in.date = StringToTime(temp1);
    cout << "Введите годовой процент начисления: "; cin >> in.DepositRate;
    cout << endl;
    return in;
}

// Функция вывода списка
template<typename T>
void List <T> :: show()
{
    Node <T> *item = head;
    while(item != NULL)
    {
        Values temp = item -> data;
        temp.show();
        item = item -> pNext;
        cout << endl;
    }
}

// Функция сортировки по дате
template <typename T>
void List <T>::SortByDate()
{
  if (Size < 2)
  {
    return;
  }
  int mCount = 0;
  int count = 1;
  Node <T> *temp1 = head;
  Node <T> *temp2 = head -> pNext;
  Values value1 = head -> data;
  Values value2 = (head -> pNext) -> data;
  while (mCount < Size)
  {
    temp1 = head;
    temp2 = head -> pNext;
    while (count < Size)
    {
      value1 = temp1->data;
      value2 = temp2->data;
      if (value2.date < value1.date)
      {
        temp1 -> data = value2;
        temp2 -> data = value1;
      }
      temp1 = temp2;
      temp2 = temp2->pNext;
      count++;
    }
    mCount++;
    count = 1;
  }
}

// Функция сортировки по номеру счета
template <typename T>
void List <T>:: SortByAccountNumber()
{
    if (Size < 2)
        return;
    int mCount = 0;
    int count = 1;
    Node <T> *temp1 = head;
    Node <T> *temp2 = head -> pNext;
    Values value1 = head -> data;
    Values value2 = (head -> pNext) -> data;
    while (mCount < Size)
    {
        temp1 = head;
        temp2 = head -> pNext;
        while (count < Size)
        {
            value1 = temp1->data;
            value2 = temp2->data;
            if (value2.AccountNumber < value1.AccountNumber)
            {
                temp1 -> data = value2;
                temp2 -> data = value1;
            }
            temp1 = temp2;
            temp2 = temp2->pNext;
            count++;
    }
    mCount++;
    count = 1;
    }
}

// Функция сортировки по фамилии
template <typename T>
void List <T>:: SortByUserLastname()
{
    if (Size < 2)
        return;
    int mCount = 0;
    int count = 1;
    Node <T> *temp1 = head;
    Node <T> *temp2 = head -> pNext;
    Values value1 = head -> data;
    Values value2 = (head -> pNext) -> data;
    while (mCount < Size)
    {
        temp1 = head;
        temp2 = head -> pNext;
        while (count < Size)
        {
            value1 = temp1->data;
            value2 = temp2->data;
            if (value2.UserLastname < value1.UserLastname)
            {
                temp1 -> data = value2;
                temp2 -> data = value1;
            }
            temp1 = temp2;
            temp2 = temp2->pNext;
            count++;
    }
    mCount++;
    count = 1;
    }
}

// Функция поиска по номеру счета
template <typename T>
void List <T> :: FindByAccountNumber(int n)
{
    Node <T> *temp = head;
    Values value = temp -> data;
    while (temp != NULL)
    {
        value = temp -> data;
        if (value.AccountNumber == n)
        {
           value.show();
           cout << endl; 
        }
        temp = temp -> pNext;
    }
}

// Функция поиска по фамилии
template <typename T>
void List <T> :: FindByUserLastname(string str)
{
    Node <T> *temp = head;
    Values value = temp -> data;
    while (temp != NULL)
    {
        value = temp -> data;
        if (value.UserLastname == str )
        {
            value.show();
            cout << endl;
        }
        temp = temp -> pNext;
    }
}

// Функция поиска по дате
template <typename T>
void List <T> :: FindByTime(string t)
{
    Node <T> *temp = head;
    Values value = temp -> data;
    time_t t1 = StringToTime(t);
    while (temp != NULL)
    {
        value = temp -> data;
        if (value.date == t1)
        {
            value.show();
            cout << endl;
        }
        temp = temp -> pNext;
    }
}

// Функция вывода инструкции для работы с меню
void switch_istructions()
{
    cout << "1 - Добавить элемент в начало списка" << endl;
    cout << "2 - Добавить элемент в конец списка" << endl;
    cout << "3 - Добавать элемент в произвольное место списка" << endl;
    cout << "4 - Отсортировать список по фамилии" << endl;
    cout << "5 - Отсортировать список по номеру счета" << endl;
    cout << "6 - Отсортировать список по дате" << endl;
    cout << "7 - Произвести поиск по фамилии" << endl;
    cout << "8 - Произвести поиск по номеру счета" << endl;
    cout << "9 - Произвести поиск по дате" << endl;
    cout << "10 - Удалить первый элемент списка" << endl;
    cout << "11 - Удалить последний элемент списка" << endl;
    cout << "12 - Удалить произвольный элемент списка" << endl;
    cout << "13 - Очистить список" << endl;
    cout << "14 - Вывести список" << endl;
    cout << "0 - Выход" << endl << endl;
}