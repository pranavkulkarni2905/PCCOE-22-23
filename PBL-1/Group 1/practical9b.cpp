/*
Author:Pranav Kulkarni SYCOA288

*/
#include <iostream>
#include <iomanip>
#include <map> 

using namespace std;


class Person
{
public:
    string name;
    string dob;
    long int tel;

public:
    void Input();
    
};

void Person::Input()
{
    cout << "  Enter the name: ";
    cin >> name;
    cout << "  Enter the Date of Birth (Format: DD/MM/YYYY): ";
    cin >> dob;
    cout << "  Enter the telephone number: ";
    cin >> tel;
}

// # Class Map
class Map
{
private:
    map<int, Person> m; // ...Map [key,data] pair
public:
    void add();
    void display();
    void search();
    void del(); // ...Delete Function
    void update();
};

// # Add Data
void Map::add()
{
    int key;
    Person p;
    cout << "\n# Enter the ID: ";
    cin >> key;
    cout << "# Enter the Person Data:\n";
    p.Input();
    m.insert(pair<int, Person>(key, p));
}

// # Display Data
void Map::display()
{
    cout << "\n------------------------------------------------\n";
	cout<<"\nId\tName\tDOB\tTelephone";
    cout << "\n------------------------------------------------\n";
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
    	Person p=i->second;
    	cout<<i->first<<"\t"<<p.name<<"\t"<<p.dob<<"\t"<<p.tel<<"\n";
        cout << "\n------------------------------------------------\n";
    }
}

// # Search Data
void Map::search()
{
    int key, flag = 0;
    cout << "\n# Enter the ID of the person you want to search: ";
    cin >> key;
    // # Iterator
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        if (i->first == key)
        {
            flag = 1;
            cout << "\n* Data Found..!" << endl;
            cout << "\n--------------------------------------\n";
			cout<<"\nName\tDOB\tTelephone";
            cout << "\n--------------------------------------\n";
            Person p=i->second;
            cout<<p.name<<"\t"<<p.dob<<"\t"<<p.tel;
            cout << "\n--------------------------------------\n";
            break;
        }
    }
    if (flag == 0)
        cout << "\n# Entered ID does not exist in the database..!\n";
}

// # Delete Data
void Map::del()
{
    int key, flag = 0;
    cout << "\n# Enter the ID of the person you want to delete: ";
    cin >> key;
    // # Iterator
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        if (i->first == key)
        {
            flag = 1;
            m.erase(key);
            cout << "\n# Data deleted Successfully..!" << endl;
            break;
        }
    }
    if (flag == 0)
        cout << "\n# Entered ID does not exist in the database..!\n";
}

// # Update Data
void Map::update()
{
    int key, flag = 0;
    cout << "\n# Enter the ID of the person you want to update: ";
    cin >> key;
    // # Iterator
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        if (i->first == key)
        {
            flag = 1;
            m.erase(key);
            Person p;
            cout << "\n# Enter updated data: " << endl;
            p.Input();
            m.insert(pair<int, Person>(key, p));
            cout << "\n# Data updated Successfully..!" << endl;
            break;
        }
    }
    if (flag == 0)
        cout << "\n# Entered ID does not exist in the database..!\n";
}

// # Main Function
int main()
{
    // # STL MAP
    cout << "\n# STL MAP #\n";
    Map t;
    int ch;
    do
    {
        cout << "\n--- MENU ---";
        cout << "\n1.Add Record"
             << "\n2.Display Record"
             << "\n3.Search Record"
             << "\n4.Delete Record"
             << "\n5.Update Record"
             << "\n6.Exit";
        cout << "\nEnter your choice..";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n# Add Record: " << endl;
            t.add();
            break;

        case 2:
            cout << "\n# Display Record: " << endl;
            t.display();
            break;

        case 3:
            cout << "\n# Search Record: " << endl;
            t.search();
            break;

        case 4:
            cout << "\n# Delete Record: " << endl;
            t.del();
            break;

        case 5:
            cout << "\n# Updata Record: " << endl;
            t.update();
            break;

        case 6:
            cout << "\n* You are exit...!\n\n";
            exit(0);
            break;

        default:
            cout << "\n* Invalid Choice..!" << endl;
            break;
        }
    } while (1);
    return 0;
}
