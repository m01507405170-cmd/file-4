#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person
{
string name;
int age;
};

int main()
{
int n;
cout << "Enter number of persons: ";
cin >> n;


vector<Person> persons(n);

ofstream file("persons.txt");

for (int i = 0; i < n; i++)
{
    cout << "Enter name: ";
    cin >> persons[i].name;

    cout << "Enter age: ";
    cin >> persons[i].age;

    file << persons[i].name << " " << persons[i].age << endl;
}

file.close();

ifstream in("persons.txt");

vector<Person> people;
Person p;

while (in >> p.name >> p.age)
{
    people.push_back(p);
}

in.close();

if (people.empty())
    return 0;

Person younger = people[0];
Person older = people[0];

for (int i = 1; i < people.size(); i++)
{
    if (people[i].age < younger.age)
        younger = people[i];

    if (people[i].age > older.age)
        older = people[i];
}

ofstream result("results.txt");

result << "Younger: " << younger.name << " "
       << younger.age << endl;

result << "Older: " << older.name << " "
       << older.age << endl;

result.close();

cout << "Results saved successfully.";

return 0;

}
