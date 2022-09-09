#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Viginer(string inf, string outf, int action) 
{
    ifstream fin;
    ofstream fout;
    string keyword;
    char original, result;
    int i = 0;
    cout << endl << "Введите ключевое слово: ";
    cin >> keyword;
    fin.open(inf + ".txt", ios::binary);
    fout.open(outf + ".txt", ios::binary);
        while (fin.get(original))
        {
            if (action == 1) 
            {
                result = (original) + keyword[i % keyword.size()];
                fout << result;
            }
            else 
            {
                result = original - keyword[i % keyword.size()];
                fout << result;
            }
            i++;
        }
    fin.close();
    fout.close();
}

int main()
{
    std::ios::sync_with_stdio(false);
    setlocale(LC_ALL, "Russian");
    int action;
    string inf, outf;

    while (1)
    {
        cout << endl
            << "МЕНЮ" << endl
            << "Выберите действие: " << endl
            << "1. Зашифровать по таблице Вижинера" << endl
            << "2. Дешифровать по таблице Вижинера" << endl
            << "0. Выход" << endl
            << "Ваше действие: ";
        cin >> action;
        switch (action)
        {
        case 0:
        {
            return 0;
            break;
        }
        case 1:
        {
            cout << endl << "Введите имя файла для зашифровки: ";
            cin >> inf;
            cout << endl << "Введите имя файла для вывода зашифровки: ";
            cin >> outf;
            Viginer(inf, outf, action);
            cout << endl << "Шифрование завершено" << endl;
            break;
        }
        case 2: 
        {
            cout << endl << "Введите имя файла для дешифровки: ";
            cin >> inf;
            cout << endl << "Введите имя файла для вывода дешифровки: ";
            cin >> outf;
            Viginer(inf, outf, action);
            cout << endl << "Дешифрование завершено" << endl;
            break;
        }
        }
    }
    return 0;
}
