#include <iostream>
#include <vector>
using namespace std;

//task1
class List
{
private:
    vector<int> data;
public:
    virtual void insert(int value) = 0;
    virtual int remove() = 0;
};

class Stack : public List
{
private:
    vector<int> data;
public:
    Stack(){}

    void insert(int value) override
    {
        data.push_back(value);
    }
    
    int remove() override
    {
        int value = data.back();
        data.pop_back();
        return value;
    }
    
    void print()
    {
        for (int i = 0; i < data.size(); i++)
        {
            cout<<data[i]<<" ";
        }
    }
};

class Queue : public List
{
private:
    vector<int> data;
public:
    void insert(int value) override
    {
        data.push_back(value);
    }
    
    int remove() override
    {
        int value = data.front();
        data.erase(data.begin());
        return  value;
    }
    
    void print()
    {
        for (int i = 0; i < data.size(); i++)
        {
            cout<<data[i]<<" ";
        }
    }
};



//task2
class Pet
{
public:
    
    virtual void sound()
    {
        cout<<"animal voice"<<endl;
    }
    
    virtual void show()
    {
        cout<<"animal's name"<<endl;
    }
    
    virtual void type()
    {
        cout<<"animal breed"<<endl;
    }
    
};

class Dog : public Pet
{
private:
    string name;
    string breed;
public:
    Dog(string name, string breed):
    name(name),
    breed(breed)
    {}
    
    void sound() override
    {
        cout<<"Dog voice: woof-woof"<<endl;
    }
    
    void show() override
    {
        cout<<"Dog's name: "<<name<<endl;
    }
    
    void type() override
    {
        cout<<"Breed of dog: "<<breed<<endl;
    }
};

class Cat : public Pet
{
private:
    string name;
    string breed;
public:
    Cat(string name, string breed):
    name(name),
    breed(breed)
    {}
    
    void sound() override
    {
        cout<<"Cat voice: meow"<<endl;
    }
    
    void show() override
    {
        cout<<"Cat name: "<<name<<endl;
    }
    
    void type() override
    {
        cout<<"Breed of cat: "<<breed<<endl;
    }
};

//task3

class File
{
public:
    virtual ~File()
    {
        cout<<"File destructor"<<endl;
    }
};

class TextFile : public File
{
public:
    ~TextFile()
    {
        cout<<"TextFile destructor"<<endl;
    }
};

class VideoFile : public File
{
public:
    ~VideoFile()
    {
        cout<<"VideoFile destructor"<<endl;
    }
};

int main()
{
//    Створити базовий клас список.
//    Реалізувати на базі списку стек і чергу з віртуальними функціями вставки та витягування.
    
    Stack stack;
    stack.insert(1);
    stack.insert(2);
    stack.insert(3);
    stack.print();
    cout<<endl;
    int removedValue = stack.remove();
    stack.print();
    cout<<endl;
    int newVal = removedValue +1;
    cout<<newVal<<endl;
    
    Queue queue;
    queue.insert(1);
    queue.insert(2);
    queue.insert(3);
    queue.print();
    cout<<endl;
    int removedVal = queue.remove();
    queue.print();
    cout<<endl;
    int newValue = removedVal + 5;
    cout<<newValue<<endl;
    
    
    
//    Створити базовий клас "Домашня тварина" з віртуальними методами sound, show і type. Далі створіть похідні класи "Собака", "Кішка". За допомогою конструктора встановіть ім'я кожної тварини та її характеристики.
//    Реалізуйте для кожного з класів override-функції:
//    sound - видає звук тварини (пишемо текстом у консоль);
//    show - відображає ім'я тварини;
//    type - відображає назву її підвиду.
    
    Pet* dog = new Dog{"Bublik", "French Bulldog"};
    dog->sound();
    dog->show();
    dog->type();
    delete dog;
    
    cout<<endl;
    
    Pet* cat = new Cat{"Tihon", "British cat"};
    dog->sound();
    dog->show();
    dog->type();
    delete cat;
    
    
    
    
//    Створіть базовий клас "Файл" з віртуальним деструктором. Створіть похідні класи "Текстовий файл" і "Відео файл", які успадковують базовий клас і перевизначають його деструктор. Створіть масив вказівників на об'єкти базового класу, в якому збережено об'єкти різних типів файлів. Потім видаліть кожен об'єкт з масиву і переконайтеся, що віртуальні деструктори викликаються правильно.
    
    File* textFile = new TextFile;
    delete textFile;
    File* videoFile = new VideoFile;
    delete videoFile;
    
}
