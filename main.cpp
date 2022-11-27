#include "list.cpp"

int main()
{
    List <Values> list;  
    int choice;
    int temp1;
    string temp2;
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
                temp2 = "";
                break;
            case 8:
                cout << "Введите номер счета: "; cin >> temp1;
                list.FindByAccountNumber(temp1);
                temp1 = 0;
                break;
            case 9:
                cout << "Введите дату в формате (гггг.мм.дд чч:мм): "; cin >> temp2;
                list.FindByTime(temp2);
                temp2 = "";
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
                temp1 = 0;
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
    list.clear();
    return 0;
} 