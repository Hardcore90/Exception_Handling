#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <execution>

using namespace std;


void divide(double num)
{
    if (num == 0)
    {
        throw std::invalid_argument("Нельзя делить на 0!");
    }
    cout << "Результат деления 1024 на " << num << "равен " << 1024 / num << endl;
}

int ReadFile()
{
    std::fstream in("D:\Hello.txt");
    if (!in)
    {
        return -1;
    }
    else 
    {
        return 0;
    }
    
}

class Exception : public exception
{
private:
    string MSG;
public:
    Exception(const string msg = "FileWasNotOpenedException") : exception()
    {
        MSG = msg;
    };

    const char* what() const noexcept override
    {
        return MSG.c_str();
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Задание №1\n\nНапишите функцию divide, в которую в качестве параметра будет приниматься число и внутри этой функции будет производиться деление 1024 на это число.Стоит учесть возможную ошибку деления на ноль - ее нужно будет обработать и сообщить вызывающему коду об этом.\n\n";

    double num;
    cout << "Введите число: "; cin >> num;
    try 
    {
        divide(num);
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    

    cout << "\n\nЗадание №2\n\nСоздайте свой собственный тип исключения FileWasNotOpenedException, а также функцию для чтения данных из файла.\n\nВнутри функции должно выбрасываться исключение FileWasNotOpenedException если файл не был открыт, а в функции main должно будет перехватываться.\n\n";

    try {
        int a = ReadFile();
        if (!a)
        {
            throw Exception("FileWasNotOpenedException\n\n");
        }
        else
        {
            cout << "Файл открыт\n\n" << endl;
        }
    }
    catch (const exception& error) 
    {
        cout << error.what();
    }
    

    system("pause");
}