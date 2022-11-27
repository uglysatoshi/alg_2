#include "list.cpp"

int main()
{
    List <Values> list;  // Создание списка хранящего значения класса Values
    int choice; // Переменная для работы со switch
    int temp1; // Переменная для работы с данными типа int для ввода 
    string temp3; // Переменная для работы с данными типа string для ввода
    string temp2; // Переменная для работы с данными типа string для ввода
    switch_istructions(); 
    do
    {
        cout << "Select: "; cin >> choice;
        switch(choice)
        {
            case 1:
                list.push_front(list.read());
                break;
            case 2:
                list.push_back(list.read());
                break;
            case 3:
                cout << "Введите индекс элемента списка: "; cin >> temp1;
                list.insert(list.read(), temp1);
                break;
            case 4:
                list.SortByUserLastname();
                break;
            case 5:
                list.SortByAccountNumber();
                break;
            case 6:
                list.SortByDate();
                break;
            case 7:
                cout << "Введите фамилию: "; cin >> temp2;
                list.FindByUserLastname(temp2);
                break;
            case 8:
                cout << "Введите номер счета: "; cin >> temp1;
                list.FindByAccountNumber(temp1);
                break;
            case 9:
                cin.ignore();
                cout << "Введите дату в формате (гггг.мм.дд чч:мм): "; getline(cin, temp3, '\n');
                list.FindByTime(temp3);
                break;
            case 10:
                list.pop_front();
                break;
            case 11:
                list.pop_back();
                break;
            case 12:
                cout << "Введите индекс элемента списка: "; cin >> temp1;
                list.remove_at(temp1);
                break;
            case 13:
                list.clear();
                break;
            case 14:
                list.show();
                break;
            case 0:
                break;
            default:
                cout << "Введён отсутствующий в меню пункт" << endl;
                break;
        }
    }
    while (choice != 0);
    list.clear(); // Очистка динамически выделенной памяти
    return 0; // Завершение работы программы
} 