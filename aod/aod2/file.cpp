#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <fcntl.h>
#include <stdlib.h>

using namespace std;

// Метод работы алгоритма - В начале работы алгоритм смотрит наличие файла file.txt,
// при наличии такового считывает оттуда заранее приготовленные данные таблицы,
// при отсутствии/пусом файле программа начинает с пустой хеш-таблицей
// В дальнейшем данные обьедененные в struct Node будут по ключю распределяться в
// хеш таблицу (вектор), начальный размер которой 20, при невозможности добавить еще 1 элемент
// Таблица увеличивается в 2 раза и рехешируется.
struct Node{			//Структура хранящая нужные по условию данные
	int key = -1;		//Номер билета, он же ключ
	string FIO;		//ФИО
	string adress;		//Адресс

	void SetParams(int a, string b, string c)	//Присваивание параметров структуре
	{
		this->key = a;
		this->FIO = b;
		this->adress = c;
	}

	string MakeString()	//Превращение данных в string, который добивается символом `
	{			//до длины в 100 символов
		string tmp = "";
		if(key != -1)
			tmp = to_string(key) + ' ' + FIO + " " + adress;
		for(int i = 0; i < 100 - tmp.length(); i++)
			tmp += '~';
		return tmp;
	}
};


int HeshFunc(int a);
void ReadNode(char *s);
void Resize();
void WriteToFile();
void AddKey();
void ShowIndexes();
void RemoveKey();
void FindKey();
void PushNode(int a, string b, string c);



vector <Node> g_Hesh(20);	//Хэш таблица

void ReadNode(char *s)		//Считывает данные узла таблицы из строки
{
	while(*s != '~')
		{
			string temp = "";
			string temp1 = "";
			string temp2 = "";
			while(*s != ' ')
				temp += *s++;
			while(*s != ' ')
				temp1 += *s++;
			while(*s != '~')
				temp2 += *s++;
			PushNode(atoi(temp.c_str()), temp1, temp2);
		}

}

void PushNode(int a, string b, string c)	//Добавляет следующий элемент в таблицу
{
	int key = HeshFunc(a);
	while(g_Hesh[key].key != -1 && key < g_Hesh.size())	//Если узел занят то идем дальше
		key++;
	if(key == g_Hesh.size())	//Если нет свободного
	{
		Resize();		//то увеличиваем размер таблицы, делаем рехеш
		PushNode(a, b, c);	//И пытаемся снова
	}
	else
		g_Hesh[key].SetParams(a,b,c);	//Если все хорошо добавляем в  таблицу

}

void Resize()		//Увеличение размера и рехеш
{
	vector <Node> tmp(g_Hesh.size());	//дополнительная таблица
	g_Hesh.resize(g_Hesh.size() * 2);	//Увеличиваем размер вдвое
	for(int i = 0; i < g_Hesh.size(); i++)	//Копируем элементы и обнуляем оригинальную
	{
		tmp.push_back(g_Hesh[i]);
		g_Hesh[i].SetParams(-1,"a","b");
	}
	for(int i = 0; i < tmp.size(); i++)	//Последовательно для каждого элемента доп
	{					//таблицы добавляем в новую таблицу
		if(tmp[i].key != -1)
		{
			int a = tmp[i].key;
			string b = tmp[i].FIO;
			string c = tmp[i].adress;
			PushNode(a,b,c);	
		}
	}
}

int HeshFunc(int a)				//Ну тут ясно
{
	return a % g_Hesh.size();
}

void WriteToFile()				//В конце работы программы производится запись
{						//таблицы в файл
	FILE *ptr;
	ptr = fopen("file.txt", "wb");
	for(int i = 0; i < g_Hesh.size(); i++)
	{
		string tmp = g_Hesh[i].MakeString();	//string и FILE* не очень дружат, поэтому
		for(int j = 0; j < 100; j++)		//запись посимвольная
			fwrite(&tmp[j],1,1,ptr);
	}
	fclose(ptr);
}

void AddKey()						//Добавление элемента пользователем
{
	int tmp;
	string tmp2;
	string tmp3;
	cout << "Введите номер билета\n";
	cin >> tmp;
	cout << "ФИО\n";
	cin >> tmp2;
	cout << "Адресс\n";
	cin >> tmp3;
	PushNode(tmp, tmp2, tmp3);
}

void RemoveKey()					//Удаление узла по ключю
{
	int tmp;
	int key;
	cout << "Номер билета?\n";
	cin >> tmp;
	key = HeshFunc(tmp);
	while(tmp != g_Hesh[key].key && key < g_Hesh.size())
	{
		if (g_Hesh[key].key == -1)
		{
			cout << "Ошибка, нет ключа\n";
			return;
		}
		else
			key++;
	}
	if(key == g_Hesh.size())
		cout << "Ошибка, нет ключа\n";
	else
		g_Hesh[key].key = -1;
}

void ShowIndexes()					//Вывод занятых элементов
{
	cout << "Занятые ячейки: ";
	for(int i = 0; i < g_Hesh.size(); i++)
		if(g_Hesh[i].key != -1)
			cout << i << " ";
}
void FindKey()						//Поиск элемента по ключу
{
	int tmp;
	int key;
	cout << "Номер билета?\n";
	cin >> tmp;
	key = HeshFunc(tmp);
	while(tmp != g_Hesh[key].key && key < g_Hesh.size())	//Пока не конец и не совпал ключ
	{
		if (g_Hesh[key].key == -1)			//Если пустой, значит ключа не было
		{
			cout << "Ошибка, нет ключа\n";
			return;
		}
		else
			key++;					//Идем проверять дальше
	}
	if(key == g_Hesh.size())				//Если не нашли то нет такого
		cout << "Ошибка, нет ключа\n";
	else
		cout << keyш*100 << '\n';			//Иначе выводим сдвиг
}

int main()
{
	FILE *ptr;
	char tt;
	ptr = fopen("file.txt","rb");				//Файл для чтения
	string s = "";
	int i = 1;
	if(ptr != nullptr)					//Если не пустой то посимвольно
	{							//считываем 100 символов в строку
		while(!feof(ptr))				//и отправляем на добавление
		{
			for(int j = 0; j < 100; j++)
			{
				fread(&tt,1,1,ptr);
				s += tt;
			}
			ReadNode((char *)s.c_str());
			s = "";
		}
		fclose(ptr);
	}
	while(i != 0)
	{
		cout << "Ввести ключ, удалить ключ, найти ключ или вывести занятые ячейки таблицы? 1/2/3/4\nЧтобы выйти - 0\n";
		cin >> i;
		if(i == 1)
			AddKey();
		else if(i == 2)
			RemoveKey();
		else if(i == 3)
			FindKey();
		else if(i == 4)
			ShowIndexes();
		else cout << "Неверный ввод";
	}
	WriteToFile();
	return (0);
}
