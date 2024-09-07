#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include <cstdlib>
using namespace std;
class StudentManager;
class subject{
    public:
    string pcb[3]={"Physics","Chemistry","Biology"};
    string pcm[3]={"Physics","Chemistry","Maths"};
    string arts[6]={"Home Science","Fine arts","Psycology","Political Science","History","Geography"};
    string commerce[4]={"Accountancy","Economics","Buisness studies","Mathematics"};
};
class Student{
    string name;
    int roll;
    vector<int>marks;
    protected:
    float per;
    public:
    string stream;
    Student(string n, int r): name(n), roll(r){
    }
    virtual void show(){
        cout<<"polymorphism showcase";
    }
    void setStream(string s){
        stream=s;
    }
    friend ostream& operator<<(ostream& os, const Student& obj);
    friend void search(StudentManager &sm);
    friend void addstd(string name,int r, StudentManager &sm);
    friend int find(StudentManager& sm,int ch,int r);
    friend void editstd(Student &std)
    {
        cout<<"Choose field to update:\n1.Name\n2.Roll number\n3.Stream\n4.Marks\n";
        int ch; cin>>ch;
        if(ch==1){
            string n;
            cout<<"Enter new name-"; cin>>n;
            std.name= n;}
        else if(ch==2){
            int r;
            cout<<"Enter new roll-number-"; cin>>r;}
        else if(ch==3){
            int ch; string s[]={"PCM","PCB","ARTS","COMMERCE"};
            cout<<"Choose stream:\n1.PCM\n2.PCB\n3.ARTS\n4.COMMERCE\n"; cin>>ch;
            std.stream= s[ch-1];}
        else if(ch==4){
            cout<<"Add new marks-\n"; int sum=0,i=0; subject sb; int mrs;
            for(auto& m : std.marks){
                if(std.stream=="PCM"){
                    cout<<sb.pcm[i]<<"-"; cin>>mrs; m=mrs;
                }
                else if(std.stream=="PCB"){
                    cout<<sb.pcb[i]<<"-"; cin>>mrs; m=mrs;
                }
                else if(std.stream=="ARTS"){
                    cout<<sb.arts[i]<<"-"; cin>>mrs; m=mrs;
                }
                else if(std.stream=="COMMERCE"){
                    cout<<sb.commerce[i]<<"-"; cin>>mrs; m=mrs;
                }
                i++; sum=sum+mrs;
                }
                std.per=(float)sum/(float)i;
            }
    }
};
ostream& operator<<(ostream& os, const Student& obj){
    os<<"Name-"<<obj.name<<"\tRoll no.-"<<obj.roll<<"\tStream-"<<obj.stream<<"\tPercentage:-"<<obj.per<<endl;
    return os;
}
class PCB: public Student{
    public:
    string subject[3]={"Physics","Chemistry","Biology"};
    PCB(string n, int r) : Student(n,r){
        setStream("PCB");
    }
    ~PCB(){}
};

class PCM: public Student{
    public:
    string subject[3]={"Physics","Chemistry","Maths"};
    PCM(string n, int r) : Student(n, r) {
        setStream("PCM");
    }
    void show() override { cout<<"POLYMORPHISM";}
    ~PCM(){}
};

class ARTS: public Student{
    public:
    string subject[6]={"Home Science","Fine arts","Psycology","Political Science","History","Geography"};
    ARTS(string n, int r) : Student(n, r){
        setStream("ARTS");
    }
    ~ARTS(){};
};

class COMMERCE: public Student{
    public:
    string subject[4]={"Accountancy","Economics","Buisness studies","Mathematics"};
    COMMERCE(string n, int r) : Student(n, r){
        setStream("COMMERCE");
    }
    ~COMMERCE(){};
};
class StudentManager{
    public:
    vector<PCB> pcbs;
    vector<PCM> pcms;
    vector<ARTS> art;
    vector<COMMERCE> coms;
    StudentManager() {
        pcbs.reserve(10);
        pcms.reserve(10);
        art.reserve(10);
        coms.reserve(10);
    }
    void pcm(){
        for(const auto& pcm: pcms){
            cout<<pcm;
        }
    }
    void pcb(){
        for(int i=0;i<pcbs.size();i++){
            cout<<pcbs[i];
        }
    }
    void arts(){
        for(int i=0;i<art.size();i++){
            cout<<art[i];
        }
    }
    void com(){
        for(int i=0;i<coms.size();i++){
            cout<<coms[i];
        }
    }
    void print(){
        pcm();
        pcb();
        arts();
        com();
    }
};
void menu(StudentManager& sm);
void addstd(string name,int r, StudentManager &sm) {
    cout<<"Choose stream: \n1.PCM\n2.PCB\n3.ARTS\n4.COMMERCE\n";
    int s;
    int sum=0;
    cin>>s;
    int marks;
    subject subs;
    if(s==1){
        PCM pcm(name,r);
        int i=0;
        cout<<"Add Marks:\n";
        for(const auto& sub : subs.pcm){
            cout<<sub<<"-"; cin>>marks; pcm.marks.push_back(marks);
            sum=sum+marks; i++;
        }
        float per=(float)sum/(float)i;
        pcm.per=per;
        sm.pcms.push_back(pcm);
    }
    else if(s==2){
        int i=0;
        PCB pcb(name,r);
        cout<<"Add Marks:\n";
        for(const auto& sub : subs.pcb){
            cout<<sub<<"-"; cin>>marks; i++;
            pcb.marks.push_back(marks); sum=sum+marks;
        }
        float per=(float)sum/(float)i;
        pcb.per=per;
        sm.pcbs.push_back(pcb);
    }
    else if(s==3){
        int i=0;
        ARTS art(name,r);
        cout<<"Add Marks:\n";
        for(const auto& sub : subs.arts){
            cout<<sub<<"-"; cin>>marks; i++;
            art.marks.push_back(marks); sum=sum+marks;
        }
        float per=(float)sum/(float)i;
        art.per=per;
        sm.art.push_back(art);
    }
    else if(s==4){
        int i=0;
        COMMERCE com(name,r);
        cout<<"Add Marks:\n";
        for(const auto& sub : subs.commerce){
            cout<<sub<<"-"; cin>>marks; i++;
            com.marks.push_back(marks); sum=sum+marks;
        }
        float per=(float)sum/(float)i;
        com.per=per;
        sm.coms.push_back(com);
    }
    else{
        cout<<"\nChoose Correctly\n";
        addstd(name,r,sm);
    }
}
void add(StudentManager& sm){
    string name; int r;
    cout<<"Fill details-\n";
    cout<<"Name-"; cin>>name;
    cout<<"Roll Number-"; cin>>r;
    addstd(name,r,sm);
    menu(sm);
}
void search(StudentManager& sm){
    int flag=-1;
    cout<<"Choose which stream:\n1.PCM\n2.PCB\n3.ARTs\n4.COMMERCE"; int ch;
    cin>>ch;
    int r=-1;
    string name={"\0"};
    cout<<"Choose-\n1.Search by name\n2.Search by roll number"; int c; cin>>c;
    if(c==1){
        cout<<"Enter name-"; cin>>name;
    }
    else if(c==2){
        cout<<"Enter roll number-"; cin>>r;
    }
    else{
        cout<<"Wrong Choice. Try Again";
        search(sm);
    }
    if(ch==1){
        for(const auto& std : sm.pcms){
            if((std.roll==r)||(std.name==name)){
                cout<<std;
            }
        }
        flag++;
    }
    else if(ch==2){
        for(const auto& std : sm.pcbs){
            if((std.roll==r)||(std.name==name)){
                cout<<std;
            }
        }
        flag++;
    }
    else if(ch==3){
        for(const auto& std : sm.art){
            if((std.roll==r)||(std.name==name)){
                cout<<std;
            }
        }
        flag++;
    }
    else if(ch==4){
        for(const auto& std : sm.coms){
            if((std.roll==r)||(std.name==name)){
                cout<<std;
            }
        }
        flag++;
    }
    else
    {
        cout<<"Wrong Choice. Try again";
        search(sm);
    }
    if(flag==-1){ cout<<"Nothing Found"; }
    menu(sm);
}
int find(StudentManager& sm,int ch,int r){
    int i=0;
    if(ch==1){
        for(const auto& std : sm.pcms){
            if(std.roll==r){
                break;
            }
            i++;
        }
    }
    else if(ch==2){
        for(const auto& std : sm.pcbs){
            if(std.roll==r){
                break;
            }
            i++;
        }
    }
    else if(ch==3){
        for(const auto& std : sm.art){
            if(std.roll==r){
                break;
            }
            i++;
        }
    }
    else if(ch==4){
        for(const auto& std : sm.coms){
            if(std.roll==r){
                break;
            }
            i++;
        }
    }
    return i;
}
void edit(StudentManager& sm){
    cout<<"Choose Stream:-\n1.PCM\n2.PCB\n3.ARTS\n4.COMMERCE\n";
    int ch; cin>>ch;
    cout<<"Enter roll number-";
    int r; cin>>r;
    int i=find(sm,ch,r);
    if(ch==1){
        editstd(sm.pcms[i]);
    }
    else if(ch==2){
        editstd(sm.pcbs[i]);
    }
    else if(ch==3){
        editstd(sm.art[i]);
    }
    else if(ch==4){
        editstd(sm.coms[i]);
    }
    menu(sm);
}
void deletestd(StudentManager& sm){
    cout<<"Choose stream-\n1.PCM\n2.PCB\n3.ARTS\n4.COMMERCE\n";
    int ch; cin>>ch;
    cout<<"Enter Roll number-"; int r; cin>>r;
    int i=find(sm,ch,r);
    if(ch==1){
        sm.pcms.erase(sm.pcms.begin()+i);
    }
    else if(ch==2){
        sm.pcbs.erase(sm.pcbs.begin()+i);
    }
    else if(ch==3){
        sm.art.erase(sm.art.begin()+i);
    }
    else if(ch==4){
        sm.coms.erase(sm.coms.begin()+i);
    }
    menu(sm);
}
void menu(StudentManager& sm){
    cout<<"\t\tTHIS IS STUDENT MANAGEMENT\n1.Add Student\n2.Search Student\n3.Display Students\n4.Update Student data\n5.Delete data\n6.Exit\n";
    int ch;
    cin>>ch;
    switch (ch)
    {
        case 1: add(sm); break;
        case 2: search(sm); break;
        case 3:
        system("cls");
        sm.print();
        cout<<endl;
        menu(sm);
        break;
        case 4: edit(sm); break;
        case 5: deletestd(sm); break;
        case 6: exit(0);
        default:cout<<"Invalid Choice! Try Again.\n"; menu(sm);
    }
}
int main(){
    system("cls");
    StudentManager sm;
    menu(sm);
}