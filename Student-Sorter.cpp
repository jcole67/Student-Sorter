//CS_117_20895SP21V
//Assignment 4
//Jordan Cole

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Class                                                            //Create structures
{
    string name;
    int units;
    char grade;
};

struct Student
{
    int id;
    string name;
    int num;
    double gpa;
    Class classes[20];
};

int get_info(struct Student[], int);                                    //Function Protos
void display(struct Student[], int);
double get_gpa(struct Student);
void sort_id(struct Student[], int);
void sort_name(struct Student[], int);
void sort_gpa(struct Student[], int);
int search_id(struct Student[], int, int);
int search_name(struct Student[], string, int);


int main()
{
    const int const_100 = 100;
    Student user_students[const_100];
    int user_count;

    user_count = get_info(user_students, const_100);                    //Call get_info function to receive student data

    cout << "List of students entered: " << endl;
    cout << endl;
    for (int i = 0; i < user_count; i++)
    {
        user_students[i].gpa = get_gpa(user_students[i]);               //Calculate gpa's before displaying data
    }
    cout << fixed << setprecision(1);
    display(user_students, user_count);                                 //Display all student data unsorted

    cout << "List of students sorted on ID: " << endl;
    cout << endl;
    sort_id(user_students, user_count);                                 //Sort student data by id
    display(user_students, user_count);                                 //Display sorted student data

    cout << "Enter an ID to search for: ";
    int user_id;
    cin >> user_id;
    cin.ignore();
    
    int find = search_id(user_students, user_id, user_count);           //Search for student based on user-entered id
    if (find < 0)
    {
        cout << "Student not found" << endl;
    }
    else
    {
        cout << "Student: " << user_students[find].id << " " << user_students[find].name << endl;
        
        for (int j = 0; j < user_students[find].num; j++)
        {
            cout << user_students[find].classes[j].name << ", " << user_students[find].classes[j].units << " units, Grade " << user_students[find].classes[j].grade << endl;
        }
        cout << "GPA: " << user_students[find].gpa << endl;
    }

    cout << endl;
    cout << "List of students sorted on name: " << endl;
    cout << endl;
    sort_name(user_students, user_count);                               //Sort student data by name
    display(user_students, user_count);                                 //Display sorted student data

    cout << "Enter a name to search for: ";
    string user_name;
    getline(cin, user_name);
    
    find = search_name(user_students, user_name, user_count);           //Call search_name function to find user-entered name
    if (find < 0)
    {
        cout << "Student not found" << endl;
    }
    else
    {
        cout << "Student: " << user_students[find].id << " " << user_students[find].name << endl;
        
        for (int j = 0; j < user_students[find].num; j++)
        {
            cout << user_students[find].classes[j].name << ", " << user_students[find].classes[j].units << " units, Grade " << user_students[find].classes[j].grade << endl;
        }
        cout << "GPA: " << user_students[find].gpa << endl;
    }

    cout << endl;
    cout << "List of students sorted by GPA: " << endl;
    cout << endl;
    sort_gpa(user_students, user_count);                                //Sort student data by gpa
    display(user_students, user_count);                                 //Display sorted student data

    return 0;
}

int get_info(struct Student user_students[], int const_100)             //Function body: get_info
{
    int id;
    for (int i = 0; i < const_100; i++)
    {
        cout << "Enter student ID: ";
        cin >> id;
        cin.ignore();
        if (id == -99)
        {
            cout << endl;
            return i;
        }
        user_students[i].id = id;

        cout << "Enter student name: ";
        getline(cin, user_students[i].name);
        
        string name = user_students[i].name.substr(0, user_students[i].name.find(' '));        
        
        cout << "Enter number of classes taken by " << name << ": ";
        cin >> (user_students[i].num);
        cin.ignore();
        
        for (int ii = 0; ii < user_students[i].num; ii++)
        {
            cout << "Enter name of class " << (ii + 1) << " : ";
            getline(cin, user_students[i].classes[ii].name);
            cout << "Enter units for " << user_students[i].classes[ii].name << " : ";
            cin >> user_students[i].classes[ii].units;
            cin.ignore();
            cout << "Enter letter grade received for " << user_students[i].classes[ii].name << " : ";
            cin >> user_students[i].classes[ii].grade;
            cin.ignore();
        }
        
        user_students[i].gpa = 0.0;
    }
}

void display(struct Student user_students[], int size)                  //Function body: display
{
    for (int i = 0; i < size; i++)
    {
        cout << "Student: " << user_students[i].id << " " << user_students[i].name << endl;

        for (int j = 0; j < user_students[i].num; j++)
        {
            cout << user_students[i].classes[j].name << ", " << user_students[i].classes[j].units << " units, Grade " << user_students[i].classes[j].grade << endl;
        }

        cout << "GPA: " << user_students[i].gpa << endl;
        cout << endl;
    }
}

double get_gpa(struct Student s)                                        //Function body: get_gpa
{
    double gpa = 0; 
    double temp = 0;
    double sum = 0;
    
    for (int i = 0; i < s.num; i++)
    {
        if (s.classes[i].grade == 'A')
            temp += s.classes[i].units * 4;
        else if (s.classes[i].grade == 'B')
            temp += s.classes[i].units * 3;
        else if (s.classes[i].grade == 'C')
            temp += s.classes[i].units * 2;
        else if (s.classes[i].grade == 'D')
            temp += s.classes[i].units * 1;
        else
            temp += s.classes[i].units * 0;
        sum += s.classes[i].units;
    }
    gpa = (temp / sum);
    return gpa;
}

void sort_id(struct Student user_students[], int n)                     //Function body: sort_id
{
    Student s;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (user_students[i].id > user_students[j].id)
            {
                s = user_students[i];
                user_students[i] = user_students[j];
                user_students[j] = s;
            }
        }
    }
}

void sort_name(struct Student user_students[], int n)                   //Function body: sort_name
{
    Student s;

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            if (user_students[i].name > user_students[j].name)
            {
                s = user_students[i];
                user_students[i] = user_students[j];
                user_students[j] = s;
            }
        }
}

void sort_gpa(struct Student user_students[], int n)                    //Function body: sort_gpa
{
    Student s;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (user_students[i].gpa < user_students[j].gpa)
            {
                s = user_students[i];
                user_students[i] = user_students[j];
                user_students[j] = s;
            }
        }
    }
}

int search_name(struct Student user_students[], string s, int n)        //Function body: search_name
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (s == (user_students[m].name))
            return m;

        if (s > (user_students[m].name))
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

int search_id(struct Student user_students[], int s, int n)              //Function body: search_id
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (s == (user_students[m].id))
            return m;

        if (s > (user_students[m].id))
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}
