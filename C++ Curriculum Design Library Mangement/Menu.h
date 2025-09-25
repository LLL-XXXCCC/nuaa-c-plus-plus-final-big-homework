#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Menu
{
    private:
        void DisplayHeader();    // 显示系统标题
        void DisplayFooter();    // 显示系统页脚

    public:
        Menu();
        ~Menu();
        int Main_Menu();          // 打印主菜单
        int Admin_Menu();         // 打印管理员菜单
        int Admin_ManageMenu();   // 打印管理员管理菜单
        int User_Menu();          // 打印用户菜单
        int User_AccountMenu();   // 打印用户账户管理菜单
};

#endif
