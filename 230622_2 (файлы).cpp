// 230622_2 (файлы)
// 
// имя файла состоит из названия файла и расширения (*.*)
// расширения могут быть любой длины, но традиционно 2-3 символа
// имя файла лежит во внешней памяти, а не в оперативной
// полное имя = путь файла от корня
// относительный путь = относительно папки в которой находится
// все действия с файлами выполняются через механизм потоков: принтер, клавиатура, файл - это потоки
// данные передаются через буфер
// для работы с файлами понадобятся бинарные потоки
// стандартная библиотека STDIO.h
// альтернативные библиотеки fstream, ifstream, ofstream
// после завершения работы с файлами его нужно закрыть, т.к. доступ к файлу не восстановится
// доступ к файлу осущ с помощью указателя на структуру файла
 

#include <iostream>
#include <stdio.h>
#include <io.h>

using namespace std;

void shop()
{
	const int n = 5;
	int arr[n];
	const char* path = "D:\\Климов\\mytext.txt";
	FILE* f;// доступ к файлу осущ с помощью указателя на структуру файла
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 5;
	}
	if ((fopen_s(&f, path, "w")) != NULL)// mytext.txt - файл будет создан только в папке где программа, 
		//fopen("D:\\Климов\\mytext.txt", "w") - запишется в указанную папку - fopen небезопасно для других компиляторов
		//fopen_s(&f,"mytext.txt", "w")) == NULL) - fopen_s более безопасная запись для других компиляторов
	{
		cout << "File couldn't be created! " << endl;
	}
	else
	{
		//char* str; //int a;
		//fscanf(f,"%s%d", &a) - считывает данные из файла (f - указатель, "%s(строка)%d(число)" - формат, &a - куда записываем файл)
		//cout << "OK!" << endl;
		for (int i = 0; i < n; i++)
		{
			fprintf(f, "%1d", arr[i]);
			fprintf(f, "\n");
		}
		if (fclose(f) == EOF)// End Of File (EOF)
		{
			cout << "File couldn't be closed " << endl;
		}
		else
		{
			cout << "File was closed " << endl;

		}
	}
	///*	потоки ввода : с клавиатуры, вывода - в консоль
	//	r - открытие текстового файла только для чтения (если файла не сущ - ошибка )
	//	w - открытие текстового файла для записи (если файл не сущ - будет создан, если сущ - содержимое будет перезаписано)
	//	a - открытие текстового файла для добавления (если файл не сущ - будет создан, если сущ - содержимое будет дозаписано в конец файла)
	//	r+ - открытие текстового файла для чтения и записи без изменения размера
	//	w+ - открытие текстового файла для чтения и записи 
	//	a+ - открытие текстового файла для чтения и записи с конца файла
	//	rb - открытие двоичного файла для чтения
	//	wb - открытие двоичного файла для записи. Файл будет перезаписан
	//	b - открытие двоичного файла для добавления
	//    r+b/b+ - открытие двоичного файла для чтения и записи без изменения размера
	//	w+b/wb+ - открытие двоичного файла для чтения и записи
	//	a+b/ab+ - открытие двоичного файла для чтения и записи с конца*/
	//


};

void per_string()
{
	// построчное чтение и запись из файла

	const char* path = "D:\\Климов\\CPP повторение\\lorem.txt";
	FILE* f;// доступ к файлу осущ с помощью указателя на структуру файла

	char buf[80];
	int len;


	//fgets(char* s, int sizeByte, FILE* f);
	//fputs(char* s, FILE* f);

	if (fopen_s(&f, path, "r") != NULL)
	{
		cout << "File cannot be opened!" << endl;
	}
	else
	{
		while (!feof(f))
		{
			fgets(buf, 79, f);
			len = strlen(buf);
			if (buf[len - 1] == '\n')
				buf[len - 1] = '\0';
			cout << buf << endl;
		}
		fclose(f);
	}


};

void write_binary()
{
	// запись в бинарные файлы

	const char* path = "D:\\Климов\\CPP повторение\\binary.dat";
	FILE* f;// доступ к файлу осущ с помощью указателя на структуру файла

	const int n = 5;
	int arr[5] = { -11,5,10,12,128 };

	if (fopen_s(&f, path, "wb") != NULL)
	{
		cout << "The file couldn't be opened!\nCode: " << endl;

	}
	else
	{
		/*for (int i = 0; i < n; i++)
		{
			fwrite(&arr[i], sizeof(int), 1, f);
		}*/
		fwrite(&arr[0], sizeof(int), n, f);
		fclose(f);
	}


};

void read_binary()
{
	// чтение из бинарного файла

	const char* path = "D:\\Климов\\CPP повторение\\binary.dat";
	FILE* f;// доступ к файлу осущ с помощью указателя на структуру файла

	const int n = 5;
	//int arr[5] = { -11,5,10,12,128 };
	int a;
	int done = fopen_s(&f, path, "rb");

	if (done != NULL)
	{
		cout << "The file couldn't be opened!\nCode: " << done << endl;

	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fread(&a, sizeof(float), 1, f);
			cout << a << " ";
		}
		cout << endl;
		fclose(f);
	}

};

void write_binary2()
{
	// функция fseek

	const char* path = "D:\\Климов\\CPP повторение\\binary.dat";
	FILE* f;// доступ к файлу осущ с помощью указателя на структуру файла

	int* a, min, max;
	int n = 5, imax, imin, i;
	float* ar = new float[n];
	for (i = 0; i < n; i++)
	{
		ar[i] = rand() % 10 + (float)(rand() % 100) / 100;
	}

	//fgetpos
	//fseek(FILE* f, long int ofset, enum origin)
	// SEEK_SET - с начала файла
	// SEEK_CUR - с текущей позиции
	// SEEK_END - с конца позиции
	// returns int
	// 0 - успешно, !0 - возникла ошибка
	int done = fopen_s(&f, path, "wb");
	if (done != 0)
	{

	}

	//int done = fopen_s(&f, path, "rb");

	if (done != NULL)
	{
		cout << "The file couldn't be opened!\nCode: " << done << endl;

	}
	else
	{
		a = new int[n];
		fread(a, sizeof(int), n, f);
		for (imax = imin = 0, max = min = a[0], i = 1; i < n; i++)
		{
			if (a[i] > max) { max = a[i]; imax = i; }
			if (a[i] < min) { min = a[i]; imin = i; }

		}
		cout << a[imin] << endl;
		cout << a[imax] << endl;

		fseek(f, sizeof(int) + imax * sizeof(int), SEEK_SET);
		fwrite(&min, sizeof(int), 1, f);

		fseek(f, sizeof(int) + imax * sizeof(int), SEEK_SET);
		fwrite(&max, sizeof(int), 1, f);


		fclose(f);
		delete[] a;
	}
	//read_binary();

}

void find_file()
{
	setlocale(LC_ALL, "Rus");
	// <io.h> 
	// поиск файлов
	// 1 этап findfirst
	// 2 этап findnext
	// структура finddata

	char path[100];
	char mask[20];

	cout << "Enter full path: ";
	cin >> path;// путь

	cout << "Enter mask (for example, *.txt): ";
	cin >> mask;// маска

	strcat_s(path, mask);
	cout << path << endl;

	struct _finddata_t fileinfo;
	//fileinfo.attrib;
	//fileinfo.time_create
	//fileinfo.time_access
	//fileinfo.time_write
	//_A_NORMAL, _A_RDONLY, _A_ARCH
	intptr_t done1 = _findfirst(path, &fileinfo);//_findfirst("D:\\Климов\\CPP повторение\\*.txt", &fileinfo);

	// //поиск первого файла
	//if (done1 != -1)
	//	cout << fileinfo.name << endl;
	// //поиск второго файла
	//done1 = _findnext(done1, &fileinfo);
	//	if (done1 != -1)
	//		cout << fileinfo.name << endl;

	//поиск всех файлов по указанному пути и маске

	do
	{
		cout << fileinfo.name << endl;

	} while (_findnext(done1, &fileinfo) == 0);
	_findclose(done1);

	// проблемы с именами на кириллице!!!!

}


int main()
{
	// Предварительно создайте на диске папку Example 
	//Поместите в нее три пустых файла с расширением .dat
	// затем напишите следующую программу:
	// Пользовател ь вводит с клавиатуры размер массива и числа в массиве целых чисел
	//этот массив записывает в первый файл как есть
	// во второй файл - в обратном виде
	// в третий - только нечетные элементы

	const char* path = "D:\\Климов\\CPP повторение\\Example\\binary.dat";
	const char* path2 = "D:\\Климов\\CPP повторение\\Example\\binary2.dat";
	const char* path3 = "D:\\Климов\\CPP повторение\\Example\\binary3.dat";

	FILE* f;// доступ к файлу осущ с помощью указателя на структуру файла
	
	// создаем динамический массив с указанием значений пользователем
	int n;
	cout << "Enter size of massive: " << endl;
	cin >> n;
	//const int n = 5;
	int* arr = new int;
	cout << "Enter numbers of massive: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int j = 0; j < n; j++)
	{
		cout << arr[j];
	}
	//cout << endl;
	
	// записываем в первый файл массив как есть
	if (fopen_s(&f, path, "wb") != NULL)
	{
		cout << "The file couldn't be opened!\nCode: " << endl;
	}
	else
	{
		fwrite(&arr[0], sizeof(int), n, f);
		fclose(f);
	}
	// записываем во второй файл массив как есть
	if (fopen_s(&f, path2, "wb") != NULL)
	{
		cout << "The file couldn't be opened!\nCode: " << endl;
	}
	else
	{
		fwrite(&arr[0], sizeof(int), n, f);
		fclose(f);
	}
	// записываем в третий файл массив как есть
	if (fopen_s(&f, path3, "wb") != NULL)
	{
		cout << "The file couldn't be opened!\nCode: " << endl;
	}
	else
	{
		fwrite(&arr[0], sizeof(int), n, f);
		fclose(f);
	}

	// для проверки правильности записи считываем из файла значения и выводим в консоль
	int done = fopen_s(&f, path, "rb");
	int a;
	if (done != NULL)
	{
		cout << "The file couldn't be opened!\nCode: " << done << endl;

	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fread(&a, sizeof(float), 1, f);
			cout << a << " ";
		}
		cout << endl;
		fclose(f);
	}



	return 0;

}

