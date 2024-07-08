#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Teacher
{
    string name;
    int ID;
    vector < string >teaching_course_name;
    vector < string > students_name;
    vector < int > students_ID;
};
struct Student
{
    string name;
    int ID;
    double GPA;
    vector < string > registered_lessons_name;
};
struct Faculty
{
    string name;
    vector < string > teachers_list;
    vector < string > students_list;
    vector < string > lessons_list;
    vector < int > students_ID;
};
struct Lesson
{
    string name;
    int ID;
    vector <string> teachers_names;
    vector <string> students_names;
};

vector < Teacher > teachers;
vector < Student > students;
vector < Faculty > faculties;
vector < Lesson > lessons;

void
addFaculty ()
{
    Faculty newfaculty;
    cout << "Enter faculty name: ";
    cin >> newfaculty.name;
    faculties.push_back (newfaculty);
    cout<<"Faculty added successfuly"<<endl;
}
void
addLesson ()
{   for(int i=0;i<5;i++){
        Lesson newlesson;
        cout << "Enter lesson name: ";
        cin >> newlesson.name;
        cout << "Enter lesson's ID: ";
        cin >> newlesson.ID;
        if(faculties.size()==0){
            cout<<"Daneshkade i nadarim.\nDars sabt nashod"<<endl;
            break;
        }
        else{
            cout<<"In dars baraye che daneshkade ast?\nNam anra vared konid: ";
            string f;
            cin>>f; bool found = false;
            for(int j=0;j<(int)faculties.size();j++){
                if (faculties[j].name == f) {
                    found = true;
                    faculties[j].lessons_list.push_back(newlesson.name);
                    break;
                }
            }
            if(found){
                lessons.push_back (newlesson);
                cout<<"Lesson added successfuly"<<endl;
            }
            else cout<<"daneshkade i ba in nam nadarim\ndars sabt nashod\n";
        }
    }
}
void
addTeacher ()
{
    Teacher newteacher;
    cout << "Enter teacher name: ";
    cin >> newteacher.name;
    cout << "Enter teacher ID: ";
    cin >> newteacher.ID;

    cout << "Which faculty do you wanna attend? ";
    string daneshkade;
    cin >> daneshkade;
    bool found1=false;
    if(faculties.size()==0){
        cout<<"We have no faculties"<<endl<<"Teacher didn't add successfully"<<endl;
    }
    else{
        for (int i = 0; i < (int)faculties.size (); i++)
        {
            if (daneshkade == faculties[i].name)
            {   found1=true;
                faculties[i].teachers_list.push_back (newteacher.name);
                break;
            }
        }
        if(!found1) cout<<"daneshkade yaft nashod\nostad ezafe nashod\n";
        else
        {

            cout << "How many lessons do you wanna teach? ";
            int m;
            cin >> m;
            for (int i = 0; i < m; i++)
            {
                cout << "Enter lesson's name: ";

                string course;
                cin>>course;
                int a = 0;
                for (int j = 0; j <(int) lessons.size (); j++)
                {
                    if (course == lessons[j].name)
                        a++;
                }
                if (a == 0)
                    cout << "lesson is not added yet" << endl;
                else
                    newteacher.teaching_course_name.push_back (course);
                for(int i=0;i<(int)lessons.size();i++){
                    if(course==lessons[i].name){
                        lessons[i].teachers_names.push_back(newteacher.name);
                        break;
                    }
                }

            }teachers.push_back (newteacher);
        }
    }
}
void
addStudent ()
{
    Student newstudent;
    cout << "Enter student name: ";
    cin >> newstudent.name;
    cout << "Enter student ID: ";
    cin >> newstudent.ID;
    cout << "Enter student's last term gpa: ";
    cin >> newstudent.GPA;
    if(faculties.size()==0)
        cout<<"We have no faculties\nStudent didn't add successfully"<<endl;
    else{
        cout<<"Available faculities: ";
        for(int i=0;i<(int)faculties.size();i++){
            cout<<faculties[i].name<<" ";
        }
        cout << "\nWhich faculty do you wanna attend? ";
        string daneshkade;
        cin >> daneshkade;
        bool found1=false;
        for(int i=0;i<(int)faculties.size();i++){
            if(daneshkade==faculties[i].name)
                found1=true;
        }
        if(!found1) cout<<"daneshkade yaft nashod\ndaneshjoo ezafe nashod\n";
        else{

            for (int i = 0; i < (int)faculties.size (); i++)
            {
                if (daneshkade == faculties[i].name)
                {
                    faculties[i].students_list.push_back (newstudent.name);
                    faculties[i].students_ID.push_back(newstudent.ID);
                }
            }
            students.push_back (newstudent);
            cout << "Student added successfully" << endl;

        }

    }
}

void sabte_dars(){
    bool found=false;
    cout<<"Available students: ";
    for(int i=0;i<(int)students.size();i++){
        cout<<students[i].name<<" ";
    }
    cout<<"\nEnter student name: ";
    string str; cin>>str;
    for(int i=0;i<(int)students.size();i++){
        if(str==students[i].name){
            found = true;
            if(students[i].GPA<14){
                cout<<"Available lessons: ";
                for(int y=0;y<(int)lessons.size();y++){
                    cout<<lessons[y].name<<" ";
                }
                cout<<"\nEnter 3 lessons name. ";
                for(int j=0;j<3;j++){
                    cout<<"Enter lesson name: ";
                    string q;
                    cin>>q;
                    bool found1=false;
                    for(int k=0;k<(int)lessons.size();k++){
                        if(q==lessons[k].name){ found1 = true;
                            lessons[k].students_names.push_back(students[i].name);
                            students[i].registered_lessons_name.push_back(q);
                            cout<<"Dars ezafe shod\n";
                        }
                    }
                    if(!found1) cout<<"Dars yaft nashod\n";
                    else{ int a=0;
                        cout<<"Available Teachers for this lesson: ";
                        for(int u=0;u<(int)lessons.size();u++){
                            if(q==lessons[u].name){
                                for(int v=0;v<(int)lessons[u].teachers_names.size();v++){
                                    cout<<lessons[u].teachers_names[v]<<" ";
                                    a++;
                                }
                            }
                        } if(a==0) cout<<"No teachers for this lesson\n";
                        else{
                            cout<<"\nBa kodoom ostad?\nEsme ostado vared kon: ";
                            string t; cin>>t; bool ff=false;
                            for(int m=0;m<(int)lessons.size();m++){
                                if(q==lessons[m].name){
                                    for(int u=0;u<(int)lessons[m].teachers_names.size();u++){
                                        if(t==lessons[m].teachers_names[u]){ ff=true;
                                            for(int y=0;y<(int)teachers.size();y++){
                                                if(t==teachers[y].name){
                                                    teachers[y].students_name.push_back(students[i].name);
                                                    teachers[y].students_ID.push_back(students[i].ID);
                                                    cout<<"Ostad ezafe shod\n";
                                                }
                                            }
                                        }
                                    }
                                    if(!ff) cout<<"Ostad yaft nashod\n";
                                }
                            }
                        }
                    }
                }
            }

            else if(students[i].GPA>=14 && students[i].GPA<=17){
                int m; cout<<"Chanta dars(3 , 4)? "; cin>>m;
                if(m==3||m==4){
                    cout<<"Available lessons: ";
                    for(int y=0;y<(int)lessons.size();y++){
                        cout<<lessons[y].name<<" ";
                    }
                    cout<<"\nEnter "<<m<<" lessons name: ";
                    for(int j=0;j<m;j++){
                        cout<<"Enter lesson name: ";
                        string w;
                        cin>>w;
                        bool found2=false;
                        for(int k=0;k<(int)lessons.size();k++){
                            if(w==lessons[k].name){ found2=true;
                                lessons[k].students_names.push_back(students[i].name);
                                students[i].registered_lessons_name.push_back(w);
                                cout<<"Dars ezafe shod\n";
                            }
                        }
                        if(!found2) cout<<"Dars yaft nashod\n";
                        else{ int a=0;
                            cout<<"Available Teachers for this lesson: ";
                            for(int u=0;u<(int)lessons.size();u++){
                                if(w==lessons[u].name){
                                    for(int v=0;v<(int)lessons[u].teachers_names.size();v++){
                                        cout<<lessons[u].teachers_names[v]<<" ";
                                        a++;
                                    }
                                }
                            }if(a==0) cout<<"No teachers for this lesson\n";
                            else{
                                cout<<"\nBa kodoom ostad?\nEsme ostado vared kon: ";
                                string t; cin>>t; bool ff=false;
                                for(int m=0;m<(int)lessons.size();m++){
                                    if(w==lessons[m].name){
                                        for(int u=0;u<(int)lessons[m].teachers_names.size();u++){
                                            if(t==lessons[m].teachers_names[u]){ ff=true;
                                                for(int y=0;y<(int)teachers.size();y++){
                                                    if(t==teachers[y].name){
                                                        teachers[y].students_name.push_back(students[i].name);
                                                        teachers[y].students_ID.push_back(students[i].ID);
                                                        cout<<"Ostad ezafe shod\n";
                                                    }
                                                }
                                            }
                                        }
                                        if(!ff) cout<<"Ostad yaft nashod\n";
                                    }
                                }
                            }
                        }
                    }
                }else cout<<"Enter 3,4 lessons\n";
            }


            else {
                int n; cout<<"Chanta dars(3 , 4 , 5)? "; cin>>n;
                if(n>=3 && n<=5){
                    cout<<"Available lessons: ";
                    for(int y=0;y<(int)lessons.size();y++){
                        cout<<lessons[y].name<<" ";
                    }
                    cout<<"\nEnter "<<n<<" lessons name: ";
                    for(int j=0;j<n;j++){
                        cout<<"Enter lesson name: ";
                        string r;
                        cin>>r;
                        bool found3=false;
                        for(int k=0;k<(int)lessons.size();k++){
                            if(r==lessons[k].name){ found3=true;
                                lessons[k].students_names.push_back(students[i].name);
                                students[i].registered_lessons_name.push_back(r);
                                cout<<"Dars ezafe shod\n";
                            }
                        }
                        if(!found3) cout<<"Dars yaft nashod\n";
                        else{ int a=0;
                            cout<<"Available Teachers for this lesson: ";
                            for(int u=0;u<(int)lessons.size();u++){
                                if(r==lessons[u].name){
                                    for(int v=0;v<(int)lessons[u].teachers_names.size();v++){
                                        cout<<lessons[u].teachers_names[v]<<" ";
                                        a++;
                                    }
                                }
                            }if(a==0) cout<<"No teachers for this lesson\n";
                            else{
                                cout<<"\nBa kodoom ostad?\nEsme ostado vared kon: ";
                                string t; cin>>t; bool ff=false;
                                for(int m=0;m<(int)lessons.size();m++){
                                    if(r==lessons[m].name){
                                        for(int u=0;u<(int)lessons[m].teachers_names.size();u++){
                                            if(t==lessons[m].teachers_names[u]){ ff=true;
                                                for(int y=0;y<(int)teachers.size();y++){
                                                    if(t==teachers[y].name){
                                                        teachers[y].students_name.push_back(students[i].name);
                                                        teachers[y].students_ID.push_back(students[i].ID);
                                                        cout<<"Ostad ezafe shod\n";}}
                                            } }if(!ff) cout<<"Ostad yaft nashod\n";}
                                }
                            }
                        }
                    }
                }
                else cout<<"Enter 3,4,5 lessons\n";
            }
        }
    }
    if(!found) cout<<"Daneshjoo yaft nashod\n";
    else cout<<"Sabte darsha anjam shod\n";
}
void hazfe_dars(){
    cout<<"Available students: ";
    for(int i=0;i<(int)students.size();i++){
        cout<<students[i].name<<" ";
    }
    cout<<"\nEnter Students name: ";
    string a; cin>>a;
    cout<<"Available courses: ";
    for(int i=0;i<(int)students.size();i++){
        if(a==students[i].name){
            for(int j=0;j<(int)students[i].registered_lessons_name.size();j++){
                cout<<students[i].registered_lessons_name[j]<<" ";}
        }
    }
    cout<<"\nEnter lesson's name to delete: ";
    string b; cin>>b;
    for(int i=0;i<(int)students.size();i++){
        if(a==students[i].name){
            for(int j=0;j<(int)students[i].registered_lessons_name.size();j++){
                if(b==students[i].registered_lessons_name[j]){
                    students[i].registered_lessons_name.erase(students[i].registered_lessons_name.begin()+j);

                }
            }
            for(int k=0;k<(int)lessons.size();k++){
                if(b==lessons[k].name){
                    for(int u=0;u<1;u++){
                        for(int l=0;l<(int)lessons[k].students_names.size();l++){
                            if(a==lessons[k].students_names[l]){
                                lessons[k].students_names.erase(lessons[k].students_names.begin()+l);
                            }
                        }
                    }
                }
            }
            for(int k=0;k<(int)teachers.size();k++){
                for(int l=0;l<(int)teachers[k].teaching_course_name.size();l++){
                    if(b==teachers[k].teaching_course_name[l]){
                        for(int m=0;m<(int)teachers[k].students_name.size();m++){
                            if(a==teachers[k].students_name[m]){
                                teachers[k].students_name.erase(teachers[k].students_name.begin()+m);
                                teachers[k].students_ID.erase(teachers[k].students_ID.begin()+m);
                                cout<<"hazf";
                            }
                        }
                    }
                }
            }
        }
    }

}

void bazyabi_students(){
    cout<<"________________________\nStudents:"<<endl;
    for (int i = 0; i < (int)students.size (); i++)
    {   int c=0;
        cout << "Name: " << students[i].name << " ID: " << students[i].ID << " GPA: " << students[i].GPA<<" Lessons: ";
        for(int j=0;j<(int)students[i].registered_lessons_name.size();j++){
            cout<<students[i].registered_lessons_name[j]<<" ";
            c++;
        }
        if(c==0) cout<<"No lessons";
        cout<<endl;

    }cout <<"\n_________________________"<< endl;
}
void bazyabi_faculties(){
    cout << "________________________\nfaculties:" << endl;
    for (int i = 0; i < (int)faculties.size (); i++)
    {   int a=0,b=0,c=0;
        cout << "Name: " << faculties[i].name << " Teacher(s): ";
        for (int j = 0; j <(int) faculties[i].teachers_list.size (); j++)
        {
            cout << faculties[i].teachers_list[j] << " ";
            a++;
        }
        if(a==0) cout<<"No teachers ";
        cout << "Student(s): ";
        for (int j = 0; j <(int) faculties[i].students_list.size (); j++)
        {
            cout << faculties[i].students_list[j] << " "; b++;
        }
        if(b==0) cout<<"No students ";
        cout<<"Lesson(s): ";
        for(int j=0;j<(int)faculties[i].lessons_list.size();j++){
            cout<<faculties[i].lessons_list[j]<<" ";
            c++;
        }
        if(c==0) cout<<"No lessons";
        cout<<endl;
    }cout <<"\n____________________________"<< endl;
}
void bazyabi_lessons(){
    cout<<"______________________\nLessons:"<<endl;
    for (int i = 0; i < (int)lessons.size (); i++)
    {   int a=0,b=0;
        cout << "Name: " << lessons[i].name << " ID: " << lessons[i].ID << " Teacher's name: ";
        for(int j=0;j<(int)lessons[i].teachers_names.size();j++){
            cout<<lessons[i].teachers_names[j]<<" ";
            b++;
        }
        if(b==0) cout<<"No teachers ";
        cout<<"Student(s): ";
        for(int j=0;j<(int)lessons[i].students_names.size();j++){
            cout<<lessons[i].students_names[j]<<" ";
            a++;}

        if(a==0) cout<<"No students";cout<<endl;

    }cout << "________________________"<<endl;
}
void bazyabi_teachers(){
    cout<<"___________________________\nTeachers:"<<endl;
    for (int i = 0; i <(int) teachers.size (); i++)
    {   int a=0;
        cout << "Name: " << teachers[i].name << " ID: " << teachers[i].ID << " Lesson(s): ";
        for (int j = 0; j <(int) teachers[i].teaching_course_name.size (); j++)
        {
            cout << teachers[i].teaching_course_name[j] << " ";
            a++;
        } cout<<endl;
        if(a==0) cout<<"No lessons ";


    }
    cout <<"\n_______________________"<< endl;
}
void bazyabi_daneshkade(){
    cout<<"____________________\nAvailable faculities: ";
    for(int j=0;j<(int)faculties.size();j++){
        cout<<faculties[j].name<<" ";
    }
    cout<<"\nEnter faculty's name: ";
    string str;
    cin>>str; bool found=false;
    for(int j=0;j<(int)faculties.size();j++){
        if(str==faculties[j].name){    found = true;
            cout<<"Students: ";
            for(int i=0;i<(int)faculties.size();i++){
                int a=0;
                if(str==faculties[i].name){
                    for(int j=0;j<(int)faculties[i].students_list.size();j++){
                        cout<<faculties[i].students_list[j]<<" "<<faculties[i].students_ID[j]<<" ";
                        a++;
                    }
                    if(a==0) cout<<"No students";

                }
            }
        }
    } if(!found) cout<<"Unavailable faculty!\n";
    cout<<"\n-----------------------"<<endl;
}
void bazyabi_dars(){
    cout<<"_________________________\nAvailable lessons: ";
    for(int j=0;j<(int)lessons.size();j++){
        cout<<lessons[j].name<<" ";
    }
    cout<<"\nEnter lesson's name: ";
    string str;
    cin>>str;
    cout<<"Students: ";
    for(int i=0;i<(int)lessons.size();i++){
        int a=0;
        if(str==lessons[i].name){
            for(int j=0;j<(int)lessons[i].students_names.size();j++){
                cout<<lessons[i].students_names[j]<<" ";
                a++;
            }
            if(a==0) cout<<"No students";
        }
    }
    cout<<"\n____________________________"<<endl;
}
void bazyabi_ostad(){
    cout<<"___________________________\nAvailable Teachers: ";
    for(int j=0;j<(int)teachers.size();j++){
        cout<<teachers[j].name<<" ";
    }
    cout<<"\nEnter teacher's name: ";
    string str;
    cin>>str;
    cout<<"Students: \n";
    for(int i=0;i<(int)teachers.size();i++){
        int a=0;
        if(str==teachers[i].name){
            for(int j=0;j<(int)teachers[i].students_name.size();j++){
                cout<<teachers[i].students_name[j]<<" "<<teachers[i].students_ID[j];
                a++;
                cout<<endl;}
            if(a==0) cout<<"No students\n";
        }
    } //cout<<endl;
    cout<<"________________________"<<endl;
}
void liste_doroos_daneshkade(){
    cout<<"__________________________\nAvailable faculities: ";
    for(int j=0;j<(int)faculties.size();j++){
        cout<<faculties[j].name<<" ";
    }
    cout<<"\nEnter faculty's name: ";
    string str;
    cin>>str;
    bool found = false;
    for(int j=0;j<(int)faculties.size();j++){
        if(str==faculties[j].name){
            found=true;
            cout<<"Lessons: ";
            for(int i=0;i<(int)faculties.size();i++){
                int a=0;
                if(str==faculties[i].name){
                    for(int j=0;j<(int)faculties[i].lessons_list.size();j++){
                        cout<<faculties[i].lessons_list[j]<<" ";
                        a++;
                    }
                    if(a==0) cout<<"No lessons";
                }
            }
        }

    }
    if(!found) cout<<"This faculty doesn't exist";
    cout<<"\n________________________"<<endl;

}
void liste_doroos_daneshjoo(){
    cout<<"__________________________\nAvailable students: ";
    for(int j=0;j<(int)students.size();j++){
        cout<<students[j].name<<" ";
    }
    cout<<"\nEnter student's name: ";
    string str;
    cin>>str;
    cout<<"Lessons: ";
    for(int i=0;i<(int)students.size();i++){
        int a=0;
        if(str==students[i].name){
            for(int j=0;j<(int)students[i].registered_lessons_name.size();j++){
                cout<<students[i].registered_lessons_name[j]<<" "; a++;
            }
            if(a==0) cout<<"No lessons";
        }
    }
    cout<<"\n________________________"<<endl;

}
void jostojoo_daneshjoo(string str ){
    bool found=false;
    for(int i=0;i<(int)students.size();i++){
        if(str==students[i].name){
            cout<<"danashjoo mojood ast\n";
            found=true;
        }
    }
    if(!found)
        cout<<"daneshjoo peida nashod\n";
}
void jostojoo_dars(string str ){
    bool found=false;
    for(int i=0;i<(int)lessons.size();i++){
        if(str==lessons[i].name){
            cout<<"dars mojood ast\n";
            found=true;
        }
    }
    if(!found)
        cout<<"dars peida nashod\n";
}
void jostojoo_daneshkade(string str ){
    bool found=false;
    for(int i=0;i<(int)faculties.size();i++){
        if(str==faculties[i].name){
            cout<<"danashkade mojood ast\n";
            found=true;
        }
    }
    if(!found)
        cout<<"daneshkade peida nashod\n";
}
void jostojoo_ostad(string str ){
    bool found=false;
    for(int i=0;i<(int)teachers.size();i++){
        if(str==teachers[i].name){
            cout<<"ostad mojood ast\n";
            found=true;
        }
    }
    if(!found)
        cout<<"ostad peida nashod\n";
}

void menu();
void sabte_etelaat(){
    char ch;
    do{
        cout<<"a.sabte daneshjoo"<<endl;
        cout<<"b.sabte 5 dars"<<endl;
        cout<<"c.sabte ostad"<<endl;
        cout<<"d.sabte daneshkade"<<endl;
        cout<<"e.khorooj"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;

        switch (ch)
        {
        case 'a':
            addStudent();
            break;
        case 'b':
            addLesson();
            break;
        case 'c':
            addTeacher();
            break;
        case 'd':
            addFaculty();
            break;
        case 'e':
            cout<<"Goodbye\n";
            break;
        default:
            cout<<"Invalid choice! try again. \n";
        }
    } while(ch!='e');
    menu();
}
void entekhab_vahed(){
    char ch;
    do{
        cout<<"a.sabte dars baraye daneshjoo"<<endl;
        cout<<"b.hazfe dars baraye daneshjoo"<<endl;
        cout<<"c.khorooj"<<endl;
        cout<<"Enter your choice: ";
        cin >> ch;
        switch(ch)
        {
        case 'a':
            sabte_dars();
            break;
        case 'b':
            hazfe_dars();
            break;
        case 'c':
            cout<<"khorooj\n";
            break;
        default:
            cout<<"Invalid choice! try again. \n";
        }

    }while(ch!='c');
    menu();
}
void bazyabi_etelaat(){
    string str,str1,str2;
    char ch;
    do{
        cout<<"a.List"<<endl;
        cout<<"b.Search"<<endl;
        cout<<"c.khorooj"<<endl;
        cout<<"Enter your choice: ";
        cin >> ch;
        switch(ch)
        {
        case 'a':
            do{
                cout<<"i.students\n";
                cout<<"ii.daneshkade ha\n";
                cout<<"iii.doroos\n";
                cout<<"iv.asatid\n";
                cout<<"v.liste daneshjooyan yek daneshkade\n";
                cout<<"vi.liste daneshjooyan yek dars\n";
                cout<<"vii.liste daneshjooyan yek ostad\n";
                cout<<"viii.liste doroos yek daneshkade\n";
                cout<<"ix.liste doroos entekhabi yek daneshjoo\n";
                cout<<"ixx.khorooj\n";
                cout<<"Enter your choice: ";
                cin>>str;
                if(str=="i"){
                    bazyabi_students();
                }
                else if(str=="ii"){
                    bazyabi_faculties();
                }
                else if(str=="iii"){
                    bazyabi_lessons();
                }
                else if(str=="iv"){
                    bazyabi_teachers();
                }
                else if(str=="v"){
                    bazyabi_daneshkade();
                }
                else if(str=="vi"){
                    bazyabi_dars();
                }
                else if(str=="vii"){
                    bazyabi_ostad();
                }
                else if(str=="viii"){
                    liste_doroos_daneshkade();
                }
                else if(str=="ix"){
                    liste_doroos_daneshjoo();
                }
                else if(str=="ixx"){
                    cout<<"Goodbye\n";
                    break;
                }
                else{
                    cout<<"Invalid choice! try again. \n";
                }
            }while(str!="ixx");
            break;
        case 'b':
            do{
                cout<<"i.daneshjoo\n";
                cout<<"ii.dars\n";
                cout<<"iii.daneshkade\n";
                cout<<"iv.ostad\n";
                cout<<"iiv.khorooj\n";
                cout<<"Enter your choice: ";
                cin>>str1;
                if(str1=="i"){
                    cout<<"Enter student's name:";
                    cin>>str2;
                    jostojoo_daneshjoo(str2);
                }
                else if(str1=="ii"){
                    cout<<"Enter lesson's name:";
                    cin>>str2;
                    jostojoo_dars(str2);
                }
                else if(str1=="iii"){
                    cout<<"Enter faculty's name:";
                    cin>>str2;
                    jostojoo_daneshkade(str2);
                }
                else if(str1=="iv"){
                    cout<<"Enter teacher's name:";
                    cin>>str2;
                    jostojoo_ostad(str2);
                }
                else if(str1=="iiv"){
                    cout<<"Goodbye\n";
                    break;
                }
                else{
                    cout<<"Invalid choice! try again. \n";
                }
            }while(str1!="iiv");
            break;
        case 'c': break;
        default:
            cout<<"Invalid choice! try again. \n";
        }
    }while(ch!='c');
    menu();
}
void namayesh_jadvali(){
    cout<<"Available students: ";
    for(int j=0;j<(int)students.size();j++){
        cout<<students[j].name<<" ";
    }
    cout<<"\nEnter student's name: ";
    string str;
    cin>>str;
    bool found=false;

    for(int i=0;i<(int)students.size();i++){
        if(str==students[i].name){
            found=true;
        }
    }
    if(!found) cout<<"We don't have this student\n";
    else{
        cout<<"________________________________________________________________________________________\n";
        cout<<"Student|";
        for(int i=0;i<(int)lessons.size();i++){
            cout<<lessons[i].name<<"|";
        }
        cout<<"doroos entekhabi|moaddel ghabl|";

        cout<<"\n   "<<str<<"  |";

        for(int i=0;i<(int)lessons.size();i++){int a=0;
            for(int j=0;j<(int)students.size();j++){
                if(str==students[j].name){
                    for(int k=0;k<(int)students[j].registered_lessons_name.size();k++){
                        if(lessons[i].name==students[j].registered_lessons_name[k])
                            a++;
                    }
                    if(a==0) cout<<"   0  |";
                    else cout<<"   1  |";
                }
            }
        }
        for(int i=0;i<(int)students.size();i++){
            if(str==students[i].name)
                cout<<"      "<<students[i].registered_lessons_name.size()<<"         |";
        }
        for(int i=0;i<(int)students.size();i++){
            if(str==students[i].name)
                cout<<"    "<<students[i].GPA<<"     |\n";
        }
        cout<<"----------------------------------------------------------------------------------------\n";
    }

}
void sabt_dar_file(){
    ofstream file("students.txt",ios::app);
    if(file.is_open()){
        file.clear();
        for(int i=0;i<(int)students.size();i++){
            file<<"Name: "<<students[i].name<<" ID: "<<students[i].ID<<" GPA: "<<students[i].GPA<<endl;
            file<<"courses: ";
            for(int j=0;j<(int)students[i].registered_lessons_name.size();j++){
                file<<students[i].registered_lessons_name[j]<<" ";
            }
            file<<endl;


        }
        file.close();
        cout<<"Students added successfully!"<<endl;
    }
    else cout<<"Unable to open file!\n";
}
void bazyabi_az_file(){
    cout<<"___________________________________________________\n";
    ifstream file("students.txt");
    if(file.is_open()){
        string name;
        while(file){
            getline(file,name);
            cout<<name<<endl;
        }
        file.close();
        cout<<"________________________________________________\n";
    }
    else cout<<"Unable to open file\n";
}
void menu(){
    int choice;
    do{
        cout << "menu:" << endl;
        cout << "1.sabte etelaat" << endl;
        cout << "2.entekhab vahed" << endl;
        cout << "3.bazyabi etelaat" << endl;
        cout << "4.namayesh jadval doroos va daneshjoo" << endl;
        cout << "5.sabte etelaat dar file matni" << endl;
        cout << "6.bazyabie etelaat az file matni" << endl;
        cout << "0.3bar 0 ra bezanid ta kharej shavad" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sabte_etelaat();
            break;
        case 2:
            entekhab_vahed();
            break;
        case 3:
            bazyabi_etelaat();
            break;
        case 4:
            namayesh_jadvali();
            break;
        case 5:
            sabt_dar_file();
            break;
        case 6:
            bazyabi_az_file();
            break;
        case 0:
            break;
        default:
            cout<<"Invalid choice! try again.\n";
        }
    }while(choice!=0);
}

int
main ()
{
    menu();
    return 0;
}
