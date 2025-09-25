#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Menu
{
    private:
        void DisplayHeader();    // ��ʾϵͳ����
        void DisplayFooter();    // ��ʾϵͳҳ��

    public:
        Menu();
        ~Menu();
        int Main_Menu();          // ��ӡ���˵�
        int Admin_Menu();         // ��ӡ����Ա�˵�
        int Admin_ManageMenu();   // ��ӡ����Ա����˵�
        int User_Menu();          // ��ӡ�û��˵�
        int User_AccountMenu();   // ��ӡ�û��˻�����˵�
};

#endif
