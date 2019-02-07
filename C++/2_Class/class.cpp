#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    private:
        int studentAge, studentStandard;
        string studentFName, studentLName;
    public:
        void set_age(int age){
            studentAge = age;
        }
        void set_standard(int standard){
            studentStandard = standard;
        }
        void set_first_name(string first_name){
            studentFName = first_name;
        }
        void set_last_name(string last_name){
            studentLName = last_name;
        }
        int get_age(){
            return studentAge;
        }
        int get_standard(){
            return studentStandard;
        }
        string get_first_name(){
            return studentFName;
        }
        string get_last_name(){
            return studentLName;
        }
        string to_string(){
            std::ostringstream finalString;
            finalString << studentAge << "," << studentFName << "," << studentLName << "," << studentStandard;
            return finalString.str();
        }
};


int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
