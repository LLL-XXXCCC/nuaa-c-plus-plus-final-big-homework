#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// ǰ������ User ��
class User;

class Admin
{
    private:
        struct AdminInfo    
        {
            string name;    // ����Ա�˺�
            string password;    // ����Ա����
        };
        
        vector<AdminInfo> adminList;  // ��adminList�����д洢�������Ա�˺�
        AdminInfo* currentAdmin;      // AdminInfoָ�룬ָ��ǰ��¼�Ĺ���Ա�˺�
    
    public:
        Admin();
        ~Admin();
        bool Admin_Login();                 // ����Ա��¼
        bool Load_AdminData();              // ���ļ����ع���Ա����
        bool Save_AdminData();              // �������Ա���ݵ��ļ�
        void Change_Password();             // �޸Ĺ���Ա����
        void Add_NewAdmin();                // ����¹���Ա
        void Show_AllAdmins();              // ��ʾ���й���Ա
        void Delete_Admin();                // ɾ������Ա
        void Delete_User(User* userSystem); // ɾ���û�
        bool Is_AdminLoggedIn()             // ����Ƿ��й���Ա��¼
        {
            return currentAdmin != NULL; 
        } 
};

#endif
