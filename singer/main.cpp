//
//  main.cpp
//  singer
//
//  Created by 20161104586 on 2018/6/29.
//  Copyright © 2018年 20161104586. All rights reserved.
//

#include <iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 10
#define true 1
#define false 0
int n=0;
typedef struct node
{
    long num;
    string name;
    string sex;
    string performancename;//表演节目名称
    string type;
    string Class;
    string tel;
    string ratername;//评委姓名
    string ratersex;//评委性别
    string ratertel;//评委电话
    long raternum;//评委编号
    int mark[10];
    int sum;
    float aver;
    struct node *next;
}LNode;
class Singer
{
private:
    LNode data[MAXSIZE];
public:
    Singer(){};
    void add(LNode *head);//增加评委
    void output(LNode *head);//输出评委
    void sort(LNode *head);//评委编号排序
    void infix(LNode *head,LNode *sin);//插入评委
    void polling(LNode *head,long raternum);//评委编号查询
    void keep(LNode *head,char filename[]);//保存评委及分数到文件
    void read(char filename[],LNode*head);//读取评委及分数文件
    void print(LNode *head);//显示
    void grade(LNode *head);//评分
    void rank(LNode *head);//排序
    void insert(LNode *head,LNode *sin);//插入学生信息
    void inquire(LNode *head,long num);//编号查询
    void save(LNode *head,char filename[]);
    void import(char filename[],LNode*head);
};
void menu()
{
    cout<<"1.---------创建选手信息"<<endl;
    cout<<"2.---------评委打分"<<endl;
    cout<<"3.---------打印所有信息"<<endl;
    cout<<"4.---------成绩排序"<<endl;
    cout<<"5.---------按编号查询"<<endl;
    cout<<"6.---------追加选手数据"<<endl;
    cout<<"7.---------保存信息表到文件"<<endl;
    cout<<"8.---------从文件导入信息"<<endl;
    cout<<"9.---------录入评委"<<endl;
    cout<<"a.---------显示评委"<<endl;
    cout<<"b.---------评委排序"<<endl;
    cout<<"c.---------插入评为信息"<<endl;
    cout<<"d.---------评委编号查询"<<endl;
    cout<<"e.---------保存评委及分数到文件"<<endl;
    cout<<"f.---------读取评委及分数文件"<<endl;
    cout<<"0.---------退出"<<endl;
    cout<<"输入您的选择："<<endl;
}
LNode *Create()//创建信息
{
    LNode *p1,*p2,*head;
    head=NULL;
    p1=head;
    while(true)
    {
        p2=p1;
        p1=new LNode;
        cout<<"请输入选手姓名：";
        cin>>p1->name;
        if(p1->name=="0")
            break;
        cout<<"请输入编号: ";
        cin>>p1->num;
        cout<<"请输入性别：";
        cin>>p1->sex;
        cout<<"请输入表演名称：";
        cin>>p1->performancename;
        cout<<"请输入类型：";
        cin>>p1->type;
        cout<<"请输入班级：";
        cin>>p1->Class;
        cout<<"请输入选手的电话号码：";
        cin>>p1->tel;
        n++;
        if(n==1)
        {
            head=p1;
            p1->next=NULL;
        }
        else
        {
            p2->next=p1;
            p1->next=NULL;
        }
    }
    cout<<"输入结束"<<endl;
    return head;
}
LNode *add()//创建评委信息
{
    LNode *p1,*p2,*head;
    head=NULL;
    p1=head;
    while(true)
    {
        p2=p1;
        p1=new LNode;
        cout<<"请输入评委姓名：";
        cin>>p1->ratername;
        if(p1->ratername=="0")
            break;
        cout<<"请输入评委编号: ";
        cin>>p1->raternum;
        cout<<"请输入评委性别: ";
        cin>>p1->ratersex;
        cout<<"请输入评委的电话号码：";
        cin>>p1->ratertel;
        n++;
        if(n==1)
        {
            head=p1;
            p1->next=NULL;
        }
        else
        {
            p2->next=p1;
            p1->next=NULL;
        }
    }
    cout<<"输入结束"<<endl;
    return head;
}
void Singer ::print(LNode *head)
{
    LNode *p=head;
    if(p!=NULL)
    {
        cout<<setw(15)<<"姓名"<<setw(10)<<"编号"<<setw(10)<<"性别"<<setw(50)<<"表演名称"<<setw(20)<<"类型"<<setw(20)<<"班级"<<setw(15)<<"选手的电话号码"<<setw(10)<<"平均分"<<endl;
        do
        {
            cout<<setw(15)<<p->name<<setw(10)<<p->num<<setw(10)<<p->sex<<setw(50)<<p->performancename<<setw(20)<<p->type<<setw(20)<<p->Class<<setw(15)<<p->tel<<setw(10)<<p->aver<<endl;
            p=p->next;
        }
        while(p!=NULL);
    }
    else
    {
        cout<<"没有信息!"<<endl;
    }
}
//输出评为信息
void Singer ::output(LNode *head)
{
    LNode *p=head;
    if(p!=NULL)
    {
        cout<<setw(15)<<"\t"<<"评委姓名"<<"\t"<<setw(10)<<"评委编号"<<"\t"<<setw(10)<<"评委性别"<<"\t"<<setw(15)<<"评委的电话号码"<<endl;
        do
        {
            cout<<setw(15)<<p->ratername<<setw(10)<<p->raternum<<setw(10)<<p->ratersex<<setw(15)<<p->ratertel<<endl;
            p=p->next;
        }
        while(p!=NULL);
    }
    else
    {
        cout<<"没有信息!"<<endl;
    }
}
void Singer ::grade(LNode *head)//评委打分
{
    LNode *p;
    p=head;
    if(p!=NULL)
    {
        do
        {
            int i,max,min;
            int sum=0;
            max=-1;
            min=11;
            cout<<"请输入"<<p->num<<"号选手"<<p->name<<"的得分"<<endl;
            for(i=0;i<10;i++)
            {
                cout<<"第"<<i+1<<"个评委的评分：";
                cin>>p->mark[i];
                if(p->mark[i]>max)
                    max=p->mark[i];
                if(p->mark[i]<min)
                    min=p->mark[i];
                sum+=p->mark[i];
            }
            p->sum=sum;
            p->aver=(p->sum-max-min)/8.0;
            cout<<endl;
            cout<<"总分"<<p->sum<<"平均分："<<p->aver<<endl;
            p=p->next;
            cout<<endl;
        }
        while(p!=NULL);
    }
    else
    {
        cout<<"\n所有选手的评分输入完毕。";
    }
}
void Singer ::rank(LNode *head)//平均分排序
{
    LNode *p,*q,*tail,*h;
    if(!head)
        return;
    tail=NULL;
    h=new LNode;
    h->next=head;
    while(h->next!=tail)
    {
        p=h;
        q=p->next;
        while(q->next!=tail)
        {
            if(p->next->aver<q->next->aver)
            {
                p->next=q->next;
                q->next=q->next->next;
                p->next->next=q;
                p=p->next;
            }
            else
            {
                q=q->next;
                p=p->next;
            }
        }
        tail=q;
    }
    head=p->next;
    p=h->next;
    cout<<setw(10)<<"编号"<<setw(10)<<"姓名"<<setw(10)<<"性别"<<setw(50)<<"表演名称"<<setw(20)<<"类型"<<setw(20)<<"班级"<<setw(15)<<"选手的电话号码"<<setw(10)<<"总分"<<setw(15)<<"平均分"<<endl;
    do
    {
        cout<<setw(10)<<p->num<<setw(10)<<p->name<<setw(10)<<p->sex<<setw(50)<<p->performancename<<setw(20)<<p->type<<setw(20)<<p->Class<<setw(15)<<p->tel<<setw(10)<<p->sum<<setw(15)<<p->aver<<endl;
        p=p->next;
    }
    while(p!=NULL);
}
//评委编号排序
void Singer ::sort(LNode *head)
{
    LNode *p,*q,*tail,*h;
    if(!head)
        return;
    tail=NULL;
    h=new LNode;
    h->next=head;
    while(h->next!=tail)
    {
        p=h;
        q=p->next;
        while(q->next!=tail)
        {
            if(p->next->raternum<q->next->raternum)
            {
                p->next=q->next;
                q->next=q->next->next;
                p->next->next=q;
                p=p->next;
            }
            else
            {
                q=q->next;
                p=p->next;
            }
        }
        tail=q;
    }
    head=p->next;
    p=h->next;
    cout<<setw(15)<<"\t"<<"评委姓名"<<"\t"<<setw(10)<<"评委编号"<<"\t"<<setw(10)<<"评委性别"<<"\t"<<setw(15)<<"评委的电话号码"<<endl;
    do
    {
        cout<<setw(15)<<p->ratername<<setw(10)<<p->raternum<<setw(10)<<p->ratersex<<setw(15)<<p->ratertel<<endl;
        p=p->next;
    }
    while(p!=NULL);
}
void Singer ::insert(LNode *head,LNode *sin)//增加信息
{
    LNode *p0,*p1;
    p1=head;
    p0=sin;
    if(head==NULL)
    {
        head=p0;
        p0->next=NULL;
    }
    else
    {
        while(p1->next!=NULL)
        {
            if(p0->num==p1->num)
            {
                cout<<"编号为"<<p0->num<<"的选手已存在！"<<endl;
            }
            p1=p1->next;
        }
        p1->next=p0;
        p0->next=NULL;
        n++;
    }
    grade(p0);
    cout<<"成功输入信息！"<<endl;
}
void Singer ::infix(LNode *head,LNode *sin)//增加评委信息
{
    LNode *p0,*p1;
    p1=head;
    p0=sin;
    if(head==NULL)
    {
        head=p0;
        p0->next=NULL;
    }
    else
    {
        while(p1->next!=NULL)
        {
            if(p0->raternum==p1->raternum)
            {
                cout<<"编号为"<<p0->raternum<<"的选手已存在！"<<endl;
            }
            p1=p1->next;
        }
        p1->next=p0;
        p0->next=NULL;
        n++;
    }
    cout<<"成功输入信息！"<<endl;
}
void Singer ::inquire(LNode *head,long num)//按编号查询
{
    LNode *p=head;
    if(p==NULL)
    {
        cout<<"信息为空!"<<endl;
        return;
    }
    else
    {
        if(p->num==num)
        {
            if(true)
            {
                cout<<"编号是"<<num<<"的选手是:"<<endl;
                cout<<setw(15)<<"姓名"<<setw(10)<<"性别"<<setw(50)<<"表演名称"<<setw(20)<<"类型"<<setw(20)<<"班级"<<setw(15)<<"选手的电话号码"<<setw(7)<<"成绩"<<endl;
            }
            cout<<setw(15)<<p->name<<setw(10)<<p->sex<<setw(50)<<p->performancename<<setw(20)<<p->type<<setw(20)<<p->Class<<setw(15)<<p->tel<<setw(7)<<p->aver<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"查无此人"<<endl;
}
void Singer ::polling(LNode *head,long raternum)//按编号查询
{
    LNode *p=head;
    if(p==NULL)
    {
        cout<<"信息为空!"<<endl;
        return;
    }
    else
    {
        if(p->raternum==raternum)
        {
            if(true)
            {
                cout<<"编号是"<<raternum<<"的评委是:"<<endl;
                cout<<setw(15)<<"\t"<<"评委姓名"<<"\t"<<setw(10)<<"评委编号"<<"\t"<<setw(10)<<"评委性别"<<"\t"<<setw(15)<<"评委的电话号码"<<endl;
            }
            cout<<setw(15)<<p->ratername<<setw(10)<<p->raternum<<setw(10)<<p->ratersex<<setw(15)<<p->ratertel<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"查无此人"<<endl;
}
void Singer ::save(LNode *head,char filename[])//保存信息到文件中
{
    LNode *p=head;
    if(head==NULL)
    {
        cout<<"没有可以保存的信息"<<endl;
        return;
    }
    else
    {
        ofstream outfile("/Users/dorgen/Desktop/play.csv",ios::out);
        if(!outfile)
        {
            cout<<"打开数据文件出错！"<<endl;
            return;
        }
        do
        {
            if(false)
                outfile<<endl;
            outfile<<p->name<<"\t"<<p->num<<"\t"<<p->sex<<"\t"<<p->performancename<<"\t"<<p->type<<"\t"<<p->Class<<"\t"<<p->tel<<"\t"<<p->aver;
            p=p->next;
        }
        while(p!=NULL);
        outfile.close();
        cout<<"保存成功！保存到"<<filename<<endl;
    }
}
void Singer ::keep(LNode *head,char filename[])//保存评委信息到文件中
{
    LNode *p=head;
    if(head==NULL)
    {
        cout<<"没有可以保存的信息"<<endl;
        return;
    }
    else
    {
        ofstream outfile("/Users/dorgen/Desktop/rater.csv",ios::out);
        if(!outfile)
        {
            cout<<"打开数据文件出错！"<<endl;
            return;
        }
        do
        {
            if(false)
                outfile<<endl;
            outfile<<p->ratername<<"\t"<<p->raternum<<"\t"<<p->ratersex<<"\t"<<p->ratertel;
            p=p->next;
        }
        while(p!=NULL);
        outfile.close();
        cout<<"保存成功！保存到"<<filename<<endl;
    }
}
void Singer ::import(char filename[],LNode*head)//读取信息
{
    ifstream infile;
    infile.open("/Users/dorgen/Desktop/play.csv",ios::in);
    if(!infile)
    {
        cout<<"打开文件失败！"<<endl;
    }
    head=NULL;
    n=0;
    LNode *p1;
    LNode *p;
    while(!infile.eof())
    {
        p=new LNode;
        if(n>=1)
            p1->next=p;
        infile>>p->name>>p->num>>p->sex>>p->performancename>>p->type>>p->Class>>p->tel>>p->aver;
        p->next=NULL;
        if(n==0)
            head=p;
        p1=p;
        n++;
    }
    infile.close();
    cout<<"导入成功"<<endl;
}
void Singer ::read(char filename[],LNode*head)//读取信息
{
    ifstream infile;
    infile.open("/Users/dorgen/Desktop/rater.csv",ios::in);
    if(!infile)
    {
        cout<<"打开文件失败！"<<endl;
    }
    head=NULL;
    n=0;
    LNode *p1;
    LNode *p;
    while(!infile.eof())
    {
        p=new LNode;
        if(n>=1)
            p1->next=p;
        infile>>p->ratername>>p->raternum>>p->ratersex>>p->ratertel;
        p->next=NULL;
        if(n==0)
            head=p;
        p1=p;
        n++;
    }
    infile.close();
    cout<<"导入成功"<<endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Singer singer;
    LNode *head=NULL;
    LNode newsin;
    string name;
    void grade(LNode*);
    ifstream infile;
    char filename[20];
    long num;
    long raternum;
    char choose;
    int quit=false;
    char c;
    while(true)
    {
        menu();
        cin>>choose;
        switch(choose)
        {
            case '1':
                if(false)
                {
                    cout<<"你所创建的链表，原有链表将丢失，是否继续！（Y/N）";
                    cin>>c;
                    if(!(c=='y')||(c=='Y'))
                    {
                        continue;
                    }
                    else
                    {
                        n=0;
                        head=Create();
                        system("pause");
                        break;
                    }
                }
                else
                {
                    head=Create();
                    system("pause");
                    break;
                }
            case '2':
                singer.grade(head);
                system("pause");
                break;
            case '3':
                singer.print(head);
                system("pause");
                break;
            case '4':
                cout<<"程序排序结果为："<<endl;
                singer.rank(head);
                system("pause");
                break;
            case '5':
                cout<<"请输入编号："<<endl;
                cin>>num;
                singer.inquire(head,num);
                system("pause");
                break;
            case '6':
                cout<<"新增选手的姓名:"<<endl;
                cin>>newsin.name;
                cout<<"新增选手的编号："<<endl;
                cin>>newsin.num;
                cout<<"新增选手的性别："<<endl;
                cin>>newsin.sex;
                cout<<"新增选手的表演名称："<<endl;
                cin>>newsin.performancename;
                cout<<"新增选手的类型："<<endl;
                cin>>newsin.type;
                cout<<"新增选手的班级："<<endl;
                cin>>newsin.Class;
                cout<<"新增选手的电话："<<endl;
                cin>>newsin.tel;
                singer.insert(head,&newsin);
                system("pause");
                break;
            case '7':
                cout<<"请输入文件名："<<endl;
                cin>>filename;
                singer.save(head,filename);
                system("pause");
                break;
            case '8':
                cout<<"请输入文件名："<<endl;
                cin>>filename;
                singer.import(filename,head);
                system("pause");
                break;
            case '9':
                head=add();
                system("pause");
                break;
            case 'a':
                singer.output(head);
                system("pause");
                break;
            case 'b':
                cout<<"评委排序结果为："<<endl;
                singer.sort(head);
                system("pause");
                break;
            case 'c':
                cout<<"新增评委的姓名:"<<endl;
                cin>>newsin.ratername;
                cout<<"新增评委的编号："<<endl;
                cin>>newsin.raternum;
                cout<<"新增评委的性别："<<endl;
                cin>>newsin.ratersex;
                cout<<"新增评委的电话："<<endl;
                cin>>newsin.ratertel;
                singer.infix(head,&newsin);
                system("pause");
                break;
            case 'd':
                cout<<"请输入评委编号："<<endl;
                cin>>raternum;
                singer.polling(head,raternum);
                system("pause");
                break;
            case 'e':
                cout<<"请评委输入文件名："<<endl;
                cin>>filename;
                singer.keep(head,filename);
                system("pause");
                break;
            case 'f':
                cout<<"请输入文件名："<<endl;
                cin>>filename;
                singer.read(filename,head);
                system("pause");
                break;
            case '0':
                quit=true;
                break;
            default:
                cout<<"输入错误！"<<endl;
        }
        if(quit)
            break;
    }
    return 0;
}
