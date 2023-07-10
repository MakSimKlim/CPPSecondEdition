// 230710_ООП (Конструктор).

//
// спец метод для инициализации объекта  - конструктор (это функция, котораяя имеет заголовок(имя класса), имя как у класса 
// не возвращает значения, он только создает объект, коструктор должен быть открыт!!!)
// всегда один конструктор пустой, второй с параметрами
// констрктор может обращаться ко всем методам класса ( как открытым, так и  закрытым)
// конструктор можно перегружать!!!
// если в классе ни одного конструктора, то компилятор создаст его автоматически!!!
// это тконструктор будет без параметров, все данные будут автоматически неинициализирован
// если конструктор существует (хоть с параметрами, хоть нет), конструктор по умолчанию не создается
// когда уничтожаются данные после завершения программы, необходимо очистить динамическую память 
// (утечка данных если память занята и продолжает использоваться после завершения программы)
// очень опасно например с работой с базой данных, которую можно в итоге за дедосить
// для этого и нужен деструктор!!!!
// деструктор - спец метод котор вызывается, когда объект уничтожается `
// он вызывается неявно
// он необязателен, если не используется динамическая память (указатели, динамические массивы)
//
// можно создавать массивы из объектов класса!!!
//
// можно создавать указатели на объекты класса, а также передавать объекты через ссылки
// 
// при обращении к методам через указатель пишем -> а не разыменовываем указатель!!!


#include <iostream>

const int maxNameLength = 100;

using namespace std;

class Book
{
	char name[maxNameLength];
	char publisher[maxNameLength];
	char author[maxNameLength];

public:
	// конструктор
	Book()
	{
		SetName("");
		SetPublisher("");
		SetAuthor("");
	}
	// перегрузка конструктора
	Book(const char* newName, const char* newPub, const char* newAuthor)
	{
		SetName(newName);
		SetPublisher(newPub);
		SetAuthor(newAuthor);
	}
	// перегруженный конструктор с неполными параметрами
	Book(const char* Name, const char* Author)
	{
		SetName(Name);
		SetPublisher("");
		SetAuthor(Author);
	
	}


	void SetName(const char* newName)
	{
		memcpy_s(name, maxNameLength, newName, maxNameLength);
	}
	const char GetName()
	{
		return name;
	}
	void SetPublisher(const char* newName)
	{
		memcpy_s(publisher, maxNameLength, newName, maxNameLength);
	}
	const char GetPublisher()
	{
		return publisher;
	}
	void SetAuthor(const char* newName)
	{
		memcpy_s(author, maxNameLength, newName, maxNameLength);
	}
	const char GeAuthor()
	{
		return author;
	}
	//деструктор 
	~Book();//в данном случае в Book статическая память и его можно не писать

private:

};

int main()
{
	Book b;
	Book c{ "War and Peace", "Tolstoy" };

	// указатель в классах
	Book* pc = &c;



	// массив книг
	int size = 10;
	Book* books = new Book[size]
	{
		{"Captain's Daughter", "EKSMO", "Pushkin"},
		{"Crime and Punishment, "Pub1", "Dostoevsky"}
		// если размер массив больше указанного кол-ва, то дозаполняется конструктором по умолчанию
	};


	cout << pc->GetName() << endl;// -> доступ к функции на которую указывает указатель


	cout << b.GetName() << endl;

	return 0;
}

