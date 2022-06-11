#include <iostream>
#include <string>
using namespace std;

struct student_data
{
    string name;
    int ID;
    float Grade;
    student_data*next;
};
student_data * first;

//__________________________________________________________________
//First Function(add information of student)
void add_student (string name , int ID , float Grade) {
    student_data * new_student = new student_data ;
    new_student->name = name ;
    new_student->ID =ID;
    new_student->Grade=Grade;
    new_student->next=NULL;
    if (first==NULL){
        first=new_student;
    }
    else{
        student_data * last = first ;
        while (last->next!=NULL){
            last=last->next ;
        }
        last->next=new_student;
    }
}

//__________________________________________________________________
//Second Function(calculat avarage)
float average (student_data*f)
{
    float sum=0,counter=0;
    student_data * temp ;
    temp = f ;
    while (temp!=NULL){
        sum+=temp->Grade;
        counter++;
        temp=temp->next;
    }
    return sum/counter;
}
student_data *passed, *failed;

//__________________________________________________________________

//third Function(split)
void split (){
    student_data * temp1=first , *temp2=NULL , *temp3=NULL ;
    while (temp1!=NULL){
        student_data * new_st = new student_data ;
        new_st->name=temp1->name;
        new_st->ID=temp1->ID;
        new_st->Grade=temp1->Grade;
        new_st->next=NULL;
        if (temp1->Grade>=50){
            if (temp2==NULL){
                temp2=new_st;
                passed=temp2;
            }
            else{
                temp2->next=new_st;
                temp2=temp2->next;
            }
        }
        else
        {
            if (temp3==NULL){
                temp3=new_st;
                failed=temp3;
            }
            else{
                temp3->next=new_st;
                temp3=temp3->next;
            }
        }
        temp1=temp1->next;
    }
}
//__________________________________________________________________
//Forth Function(Maximum Grade)
void maximum(){
    int max_grade=0;
    student_data * temp1=passed ;
    while (temp1!=NULL){
        if (temp1->Grade>max_grade)
        {
            max_grade=temp1->Grade;

        }
        temp1=temp1->next;
    }

    temp1=passed;
    while (temp1!=NULL){
        if (temp1->Grade==max_grade)
        {
            cout<<"the maximum grade is : " << temp1->Grade<<" " << temp1->name << " " << temp1->ID << "\n" ;
        }
        temp1=temp1->next;
    }

}

//main function

int main()
{
    int i=2 ;
    while (i<=3)
    {
        student_data S;
        cout << "Enter information," << endl;
        cout << "Enter Name: ";
        cin >> S.name;
        cout << "Enter ID number: ";
        cin >> S.ID;
        cout << "Enter Grade: ";
        cin >> S.Grade;
        add_student(S.name,S.ID,S.Grade);
        i++;
    }
    cout<< "the average is "<<average(first)<<endl;
    split();
    cout<< "the average is "<<average(passed)<<endl;

    maximum();
    return 0;