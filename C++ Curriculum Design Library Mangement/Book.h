#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "User.h"
using namespace std;

class Book
{
    public:
        struct Nbook            // ͼ������
        {
            string book_number; // ����   
            string book_name;   // ����
            string book_author; // ����
            string book_concern;// ������
            string book_surplus;// ���
            Nbook* next;        // ָ����һ���ڵ�
        };
    
    private:
        Nbook* head;
        User* userSystem;  // ָ���û�ϵͳ��ָ�룬���ڽ��鹦��
    
    public:
        Book();
        Book(User* userSys);  // ��ӹ��캯���������û�ϵͳָ��
        ~Book();
        void SetUserSystem(User* userSys)   // �����û�ϵͳָ��
        { 
            userSystem = userSys; 
        }  
        
        void Create_Node();    // �����ձ�ͷ
        void Show_Book();      // ��ӡͼ����Ϣ
        void Add_Book();       // ���ͼ��
        void Del_Book();       // ɾ��ͼ��
        void Search_Book();    // ����ͼ��
        bool Save_Books();     // ����ͼ�����ݵ��ļ�
        bool Load_Books();     // ���ļ�����ͼ������
        
        void Borrow_Book();    // ����ͼ��
        void Return_Book();    // �黹ͼ��
        bool Check_BookAvailable(const string& bookName);  // ���ͼ���Ƿ�ɽ�
        bool Update_BookQuantity(const string& bookName, int delta);  // ����ͼ�����������/�黹��
};

#endif
