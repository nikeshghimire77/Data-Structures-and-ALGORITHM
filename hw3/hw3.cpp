#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include <algorithm>
#include <iomanip>

using namespace std;


class student {
    string id;
    string first, last, DOB, position;
    int exp, salary;

public:
    student(string id, string first, string last, string DOB, int exp, int salary, string position) {
        this->id = id;
        this->first = first;
        this->last = last;
        this->DOB = DOB;
        this->exp = exp;
        this->salary = salary;
        this->position = position;
    }


    string getId() {
        return id;
    }
    string getFirstname() {
        return first;
    }
    string getLastname() {
        return last;
    }
    string getDOB() {
        return DOB;
    }
    int getExp() {
        return exp;
    }
    int getSalary() {
        return salary;
    }
    string getPosition() {
        return position;
    }
};

struct node {
    student* data;
    node* next;
};


student* parse(string s, string delimiter) {
    size_t pos = 0;
    int index = -1;
    string student_data[9];
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        index+=1;
        if(index>=8){
            break;
        }
        token = s.substr(0, pos);
        student_data[index] = token;
        s.erase(0, pos + delimiter.length());
        
    }
    student_data[++index] = s;
    stringstream dob_stream;
    dob_stream << student_data[3];
    dob_stream << " ";
    dob_stream <<student_data[4];
    dob_stream << " ";
    dob_stream <<student_data[5];
    // cout<<student_data[0]<<endl;
    // cout<<student_data[1]<<endl;
    // cout<<student_data[2]<<endl;
    // cout<<student_data[3]<<endl;
    // cout<<student_data[4]<<endl;
    // cout<<student_data[5]<<endl;
    // cout<<student_data[6]<<endl;
    // cout<<student_data[7]<<endl;
    // cout<<student_data[8]<<endl;
    // cout<<"End"<<endl;
    return new student(student_data[0], student_data[1], student_data[2], dob_stream.str(), stoi(student_data[6]), stoi(student_data[7]), student_data[8]);
}

bool check(node *head, string id) {
    while(head!=NULL) {
        if(head->data->getId() == id)
            return true;
        head = head->next;
    }
    return false;
}

node* reverse(node* head) {
    if(head == NULL || head->next == NULL)
        return head;
    node* temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

node* delByIndex(node *head, int start_index, int end_index) {
    node* start_node = head;
    while(start_index>1) {
        start_node = start_node->next;
        start_index--;
    }
    cout<<start_node->data->getId()<<endl;
    node* end_node = head;
    while(end_index>0) {
        end_node = end_node->next;
        end_index--;
    }
    cout<<end_node->data->getId()<<endl;
    if(start_index==0) {
        head = end_node->next;
    } else {
        start_node->next =  end_node->next;
    }
    return head;
}

node* delById(node *head, string id) {
    node* temp = head;
    node* prev = NULL;
    while(1) {
        cout<<"Temp ID:"<<temp->data->getId()<<endl;
        cout<<"ID to find:" <<id<<endl;
        if(stoi(id)==stoi(temp->data->getId())){
            break;
        }
        if(temp->next==NULL){
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(prev != NULL) {
        prev->next = temp->next;
    } else{
        head = head-> next;
    }
    return head;

}

node* delAtBegin(node *head) {
    if(head == NULL) {
        return NULL;
    }
    return head->next;
}

node* delAtEnd(node *head) {
    if(head == NULL) {
        return NULL;
    }

    if(head->next==NULL) {
        head = NULL;
        return head;
    }

    node* temp = head;
    node *t;
    while(temp->next != NULL) {
        t = temp;
        temp = temp->next;
    }
    t->next = NULL;
    return head;
}

node* addAtEndNode(node* head, student* temp) {
    node* node1 = new node();
    node1->next = NULL;
    node1->data = temp;

    if(head == NULL) {
        return node1;
    }

    node* temp2 = head;
    while(temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = node1;
    return head;
}

node* addAtEnd(node *head, node* temp) {
    if(head == NULL) {
        return temp;
    }

    node* temp2 = head;
    while(temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    return head;
}

node* addAtBegin(node *head, node* temp) {
    node* temp2 = temp;
    while(temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2-> next = head;
    return temp;
}

node* addBefore(node *head, node* temp,int index) {
    if(index == 0) {

        return addAtBegin(head,temp);
    }
    node* temp2 = head;
    while(--index>0) {
        temp2 = temp2->next;
    }

    node* temp_last = temp;
    while(temp_last->next != NULL) {
        temp_last = temp_last->next;
    }
    temp_last->next = temp2->next;
    temp2->next = temp;
    return head;
}

node* addAfter(node *head, node* temp,int index) {
    node* temp2 = head;
    while(index-->0) {
        temp2 = temp2->next;
    }
    node* temp_last = temp;
    while(temp_last->next != NULL) {
        temp_last = temp_last->next;
    }
    temp_last->next = temp2->next;
    temp2->next = temp;
    return head;
}

node* sortLL(node* head, bool comp(student*, student*)) {
    if(head == NULL) {
        return head;
    }
    node* newhead = new node();
    newhead->next = head;
    head = head->next;
    newhead->next->next = NULL;
    while(head!=NULL) {
        node* search = newhead;
        while(search->next!=NULL && comp(search->next->data, head->data))
            search = search->next;
        node* temp = head->next;
        head->next = search->next;
        search->next = head;
        head = temp;
    }
    return newhead->next;
}

bool compareWithId(student* stu1, student* stu2) {
    return stu1->getId() <= stu2->getId();
}

bool compareWithfirstname(student* stu1, student* stu2) {
    return stu1->getFirstname() <= stu2->getFirstname();
}

bool compareWithlastname(student* stu1, student* stu2) {
    return stu1->getLastname() <= stu2->getLastname();
}

bool compareWithDOB(student* stu1, student* stu2) {
    string dob1 = stu1->getDOB().substr(6) + stu1->getDOB().substr(0,2) + stu1->getDOB().substr(4,2);
    string dob2 = stu2->getDOB().substr(6) + stu2->getDOB().substr(0,2) + stu2->getDOB().substr(4,2);
    return dob1 <= dob2;
}

bool compareWithExp(student* stu1, student* stu2) {
    return stu1->getExp() <= stu2->getExp();
}
bool compareWithSalary(student* stu1, student* stu2) {
    return stu1->getSalary() <= stu2->getSalary();
}
bool compareWithPosition(student* stu1, student* stu2) {
    return stu1->getPosition() <= stu2->getPosition();
}

string printLL(node* head) {
    node* temp = head;
    string s="";
    while(temp!=NULL) {
        student* tstu = temp->data;
        ostringstream exp_stream;
        ostringstream salary_stream;
        salary_stream << tstu->getSalary();
        exp_stream << tstu->getExp();
        string exp = exp_stream.str();
        string salary = salary_stream.str();
        s += tstu->getId() +" " + tstu->getFirstname() + " " + tstu->getLastname() +" "
             +tstu->getDOB() + " " + exp + " " + salary + " "
             +tstu->getPosition() + "\n";
        temp = temp->next;
    }
    return s;
}

bool isStudentRecord(string s, string d = " ") {
    int num_spaces = 0;
    for(int i=0;i<s.length();i++) {
        if(s[i]==' '){
            num_spaces++;
        }
    }
    return num_spaces > 7;
}

bool isDuplicate(string record, node*head) {
    if (head == NULL) {
        return false;
    }
    student* tstu = parse(record, " ");
    bool duplicate = false;
    string id = tstu-> getId();
    while(head->next != NULL) {
        if(head->data->getId() == id) {
            duplicate = true;
            break;
        }
        head = head-> next;
    }
    return duplicate;
}

int main(int argc, char *argv[]) {

    // Incorrect Usage
    if (argc < 2) {
        cout << "Usage: densemultiple \"A=<file>;B=<file>;C=<file>\"" << endl;
        return -1;
    }

    ArgumentManager am(argc, argv);

    string input1 = am.get("input");
    string output = am.get("output");
    string input2 = am.get("command");

    ifstream file1(input1.c_str()), file2(input2.c_str());
    ofstream file3(output.c_str());

    if (!file1 || !file2 || !file3) {
        cout << "error";
        return -1;
    }

    string record;
    node* head = NULL;
    node* original = NULL;
    int recordSize = 0;
    string delimiter = " ";
    while(getline(file1, record)) {
        cout<<"Line:"+record<<endl;
        if(record.length()==0){
            continue;
        }
        student* tstu = parse(record, delimiter);
        head = addAtEndNode(head, tstu);
        original = addAtEndNode(original, tstu);
    }
    string current_command;
    while(getline(file2, current_command)) {
        cout<<"Command: "+current_command<<endl;
        if (current_command.find("sort") != string::npos) {
            if(current_command.substr(5) == "id") {
                head = sortLL(head, compareWithId);
            } else if(current_command.substr(5) == "first name") {
                head = sortLL(head, compareWithfirstname);
            } else if(current_command.substr(5) == "last name") {
                head = sortLL(head, compareWithlastname);
            } else if(current_command.substr(5) == "DOB") {
                head = sortLL(head, compareWithDOB);
            } else if(current_command.substr(5) == "years worked") {
                head = sortLL(head, compareWithExp);
            } else if(current_command.substr(5) == "salary") {
                head = sortLL(head, compareWithSalary);
            } else if(current_command.substr(5) == "position") {
                head = sortLL(head, compareWithPosition);
            } else {
                cout<<"error"<<endl;
            }
            file3 << printLL(head);
            file3<<"\n";
        } else if(current_command.find("add") != string::npos) {
            double prevLen = file2.tellg();
            getline(file2, record);
            cout<<"Record: "+ record<<endl;
            double len = file2.tellg();
            node* t = NULL;
            if(!isStudentRecord(record)){
                file3 << printLL(head);
                file3 <<"\n";
                file2.clear();
                file2.seekg(prevLen);
                continue;
            }
            student* tstu = parse(record, delimiter);
            t = addAtEndNode(t,tstu);
            while(getline(file2, record)&&isStudentRecord(record)) {
                len = file2.tellg();
                if(!isDuplicate(record,t) && !isDuplicate(record,head)){
                    cout<<record<<"\n";
                    tstu = parse(record, delimiter);
                    t = addAtEndNode(t,tstu);
                }
            }
            string currentId = tstu->getId();
            node* temp = head;
            bool flag = false;
            while(temp!=NULL){
                if(stoi(temp->data->getId())==stoi(currentId)){
                    flag= true;
                }
                temp = temp->next;
            }
            if(flag) {
                continue;
                file2.seekg(len);
            }
            if(current_command.find("add at beginning") != string::npos){
                head = addAtBegin(head,t);
            } else if(current_command.find("add at end") != string::npos){
                head = addAtEnd(head,t);
            } else if(current_command.find("add after") != string::npos) {
                string last_element = current_command.substr(current_command.find("add after")+10);
                cout<<"Last Element :"<<last_element<<endl;
                head = addAfter(head,t,stoi(last_element));
            } else if(current_command.find("add before") != string::npos) {
                string last_element = current_command.substr(current_command.find("add before")+11);
                head = addBefore(head,t,stoi(last_element));
            } else {
                cout<<"error";
            }
            file3 << printLL(head);
            file3 <<"\n";
            file2.seekg(len);
        } else if(current_command.find("delete") != string::npos) {
            if(current_command.find("delete at beginning") != string::npos){
                head = delAtBegin(head);
            } else if(current_command.find("delete at end") != string::npos){
                head = delAtEnd(head);
            } else if(current_command.find("to") != string::npos) {
                string useful_str = current_command.substr(7);
                string last_element(current_command.substr(current_command.rfind("to ") + 2));
                string first_element(useful_str.substr(0,useful_str.find("to ")));
                stringstream start_index_stream(first_element);
                stringstream end_index_stream(last_element);
                int start_index = 0;
                int end_index = 0;
                end_index_stream >> end_index;
                start_index_stream >> start_index;
                head = delByIndex(head,start_index,end_index);
            } else if(current_command.find("delete ") != string::npos) {
                string id = current_command.substr(7);
                cout<<"ID: " + id<<endl;
                head = delById(head,id);
            } else {
                cout<<"error";
            }
            cout<< printLL(head);
            file3 << printLL(head);
            file3<<"\n";
        } else if(current_command.find("output original") != string::npos) {
            file3 << printLL(original);
            file3<<"\n";
        } else {
            cout<<"######### Error ########"<<"\n";
        }
    }
}

