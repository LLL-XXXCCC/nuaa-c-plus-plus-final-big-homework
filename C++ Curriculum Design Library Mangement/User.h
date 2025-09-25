/*
����֮�����û����鼮�Ĵ洢�������������ʽ
*/

#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class User
{
    public:
        struct Nuser
        {
            string name;
            string sex;
            string old;
            string tel;
            string pwd;
            bool isPremium;       // �Ƿ�Ϊ�߼��û�
            double balance;       // �˻����
            vector<string> borrowedBooks; // ���ĵ�ͼ���б�
            
            Nuser* next;
        };

    private:
        Nuser* head;
        Nuser* currentUser;   // ��ǰ��¼���û�

    public:
        User();
        ~User();
        void Create_Node();    // ����userͷ
        void Show_User();      // ��ӡ�û��б�
        void Add_User();       // ע���û�
        bool User_login();     // �ж�����
        bool Save_Users();     // �����û����ݵ��ļ�
        bool Load_Users();     // ���ļ������û�����
        
        void Borrow_Book(string bookName, string bookNumber);  // ����ͼ��
        void Return_Book(string bookName);                     // �黹ͼ��
        void TopUp_Account();                                  // ��ֵ�˻�
        void Upgrade_ToPremium();                              // ����Ϊ�߼��û�
        void Show_CurrentUserInfo();                           // ��ʾ��ǰ�û���Ϣ
        void Show_BorrowedBooks();                             // ��ʾ�ѽ���ͼ��
        bool Can_BorrowBook();                                 // �ж��û��Ƿ��ܽ���
        bool Has_Users()                                       // �ж��Ƿ����û�
        {
            return head != NULL && head->next != NULL;
        }

        bool Delete_UserByIndex(int index);                    // ������ɾ���û�
        Nuser* Get_CurrentUser() 
        { 
            return currentUser; 
        }
        // ��ȡ��ǰ�û�

        bool Is_UserLoggedIn() 
        { 
            return currentUser != NULL; 
        } // �ж��Ƿ����û���¼
};

#endif
