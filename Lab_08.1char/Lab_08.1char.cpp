#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s) 
{
    int k = 0;
    int pos = 0; // pos = позиція початку пошуку
    char* t;

    while ((t = strchr(s + pos, 'n'))) // t = вказівник на 'n'
    {
        pos = t - s + 1; // pos = наступний символ після 'n'
        if (s[pos + 1] == 'o') // перевірка, чи s[i+1] = 'o'
            k++;
    }
    return k;
}

char* Change(char* s) // s = вказівник на початок рядка
{
    char* t = new char[strlen(s) * 2 + 1]; // додаткова пам'ять для можливих замін
    char* p;
    int pos1 = 0, // pos1 = позиція початку пошуку
        pos2 = 0;
    *t = '\0';

    while ((p = strchr(s + pos1, 'n'))) // p = вказівник на 'n'
    {
        if (s[p - s + 2] == 'o') // перевірка, чи після 'n' йде 'o'
        {
            pos2 = p - s + 3; // pos2 = позиція наступного символа після 'o'
            strncat(t, s + pos1, pos2 - pos1 - 3); // копіювання до 'n'
            strcat(t, "**"); // заміна на "**"
            pos1 = pos2;
        }
        else
        {
            pos2 = p - s + 1; // pos2 = позиція наступного символа після 'n'
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }

    strcat(t, s + pos1); // копіювання решти рядка
    strcpy(s, t); // запис результату в початковий рядок
    return t;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of 'n o'" << endl;
    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    delete[] dest;
    return 0;
}
