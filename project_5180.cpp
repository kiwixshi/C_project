#include <iostream>
#include <string>

using namespace std;

//defining student class
class Student{
    public:
        string name, type;
        int roll_num, sub_marks;
        float cgpa;
        void setDetails(string x, string y, int l,int m, float n){
            name = x;
            type = y;
            roll_num = l;
            sub_marks = m;
            cgpa = n;
        }
        void printDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"Residence Type: "<<type<<endl;
            cout<<"Roll number: "<<roll_num<<endl;
            cout<<"Mark in Subject: "<<sub_marks<<endl;
            cout<<"CGPA: "<<cgpa<<endl;
            cout<<"\n";
        }
};

int find_avg(Student array[50], int n){
    int i;
    float sum=0, avg;
    for (i=0; i<n; i++){
        sum += array[i].sub_marks;
    }
    avg = sum/n;
    return avg;
}

//main code
int main() { 
    int i, j=1,n, roll_num, marks, attribute, studs=0;
    string name, type;
    float cgpa;
    Student database[50];
    //while loop
    while (j!= 0){
        cout<<"\n--------------------------------------------------------------------------------------\n"<<endl;
        cout<<"These are the following operations of this management system"<<endl
            <<"1-Add Students\n2-Print a Student's Details\n3-Print several Student's Details\n4-List of high and low-achievers in class\n5-Find Class Average\n6-Compare student marks with class average\n7-Update Student Details\n0-Quit\n"<<endl;
        cin>>j;
        if (j==0){
            break;
        }
        //Add Studs
        else if (j==1){
            cout<<"How many students do you want to add to the database?"<<endl;
            cin>>n;
            cout<<"Enter the details of student in the order of name, residency type, roll number, mark in your subject and cgpa"<<endl;
            for (i=studs; i<n+studs; i++){
                cin>>name>>type>>roll_num>>marks>>cgpa;
                database[i].setDetails(name, type, roll_num, marks, cgpa);
            } 
            studs += n;
        }
        //Print Details
        else if (j==2) {
            cout<<"Enter the number of the student whose details you would like to see: "<<endl; 
            if (i>n){
                cout<<"this student does not exist, kindly enter a vaild number"<<endl;
            }else{
                cin>>i;
                database[i-1].printDetails();
                cout<<"\n";
            }
        }
        //Prints a certain number of students
        else if(j==3){
            cout<<"How many students' details do you want to print out? "<<endl;
            cin>>n;
            cout<<"\n";
            for (i=0; i<n; i++){
                database[i].printDetails();
            }
        }
        //High and Low Achievers
        else if(j==4){
            cout<<"How many students do you want to check in order to produce the list? "<<endl; 
            cin>>n;
            cout<<"\nHIGH ACHIEVERS\n"<<endl;
            for (i=0;i<n;i++){
                if (database[i].cgpa > 9.0){
                    database[i].printDetails();
                }
            }
            cout<<"\nLOW ACHIEVERS\n"<<endl;
            for (i=0;i<n;i++){
                if (database[i].cgpa < 7.0){
                    database[i].printDetails();
                }
            }
        }
        //Class Average
        else if(j==5){
            float avg;
            cout<<"Enter the strength of the class: "<<endl;
            cin>>n;
            avg = find_avg(database, n);
            cout<<"\nThe average is: "<<avg<<endl;
        }
        //Comparison
        else if (j==6){
            float difference, avg;
            cout<<"Enter the strength of the class: "<<endl;
            cin>>n;
            avg = find_avg(database, n);
            cout<<"Enter the serial number of the student whose details you would like to check: "<<endl;
            cin>>i;
            if (i>n){
                cout<<"this student does not exist, kindly enter a vaild number"<<endl;
            }else{
                difference = (database[i-1].sub_marks-avg);
                if (difference <0){
                    difference *= -1;
                    cout<<"The student scored "<<difference<<" less than the class average"<<endl;
                }else{
                    cout<<"The student scored "<<difference<<" more than the class average"<<endl;
                }
            }
        }
        //Update student details
        else if(j==7){
            cout<<"Which attribute of the student would you like to edit?\n1-Name\n2-Residence Type\n3-Roll Number\n4-Mark in Subject\n5-CGPA"<<endl;
            cin>>attribute;
            cout<<"Enter the serial number of the student whose details you would like to check: "<<endl;
            cin>>i;
            i--;
            if (i>n){
                cout<<"this student does not exist, kindly enter a vaild number"<<endl;
            }else{
                cout<<"Enter the updated detail"<<endl;
                switch(attribute){
                    case 1:{
                        cin>>database[i].name;
                        break;
                    }
                    case 2:{
                        cin>>database[i].type;
                        break;
                    }
                    case 3:{
                        cin>>database[i].roll_num;
                        break;
                    }
                    case 4:{
                        cin>>database[i].sub_marks;
                        break;
                    }
                    case 5:{
                        cin>>database[i].cgpa;
                        break;
                    }
                }
            }
        }       
        else{
            cout<<"Kindly select a valid operation"<<endl;
        }
    }
}
