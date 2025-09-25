/*
这个函数更多的是展示菜单的格式化输出，具体的判断条件在main函数中实现
*/

#include "Menu.h"

Menu::Menu()
{
    
}

Menu::~Menu()
{

}

void Menu::DisplayHeader()
{
    cout << "\n\n";
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         图 书 管 理 系 统                                     |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
}

void Menu::DisplayFooter()
{
    cout << "\n";
}

int Menu::Main_Menu()
{
    int n;
    
    DisplayHeader();
    
    cout << "\n\t\t\t          欢迎使用图书管理系统！" << endl;
    cout << "\t\t\t   初始管理员登录信息：账号：admin 密码：password\n" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【1】 管理员登录                                      |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【2】 用户登录                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【3】 用户注册                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【4】 退出系统                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t请选择功能（1-4）：";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}

int Menu::Admin_Menu()
{
    int n;
    
    DisplayHeader();
    
    cout << "\n\t\t\t          欢迎进入管理员界面！" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【1】 显示所有图书                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【2】 添加图书                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【3】 删除图书                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【4】 显示所有用户                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【5】 删除用户                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【6】 管理员账号管理                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【7】 返回主菜单                                      |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t请选择功能（1-7）：";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}

int Menu::User_Menu()
{
    int n;
    
    DisplayHeader();
    
    cout << "\n\t\t\t          欢迎进入用户界面！" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【1】 显示所有图书                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【2】 搜索图书                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【3】 借阅图书                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【4】 归还图书                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【5】 查看已借阅图书                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【6】 账户管理                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【7】 返回主菜单                                      |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t请选择功能（1-7）：";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}

int Menu::Admin_ManageMenu()
{
    int n;
    
    DisplayHeader();
    
    cout << "\n\t\t\t          管理员账号管理界面" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【1】 查看所有管理员                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【2】 添加新管理员                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【3】 修改当前密码                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【4】 删除管理员                                      |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【5】 返回管理员菜单                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t请选择功能（1-5）：";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}

int Menu::User_AccountMenu()
{
    int n;
    
    DisplayHeader();
    
    cout << "\n\t\t\t          用户账户管理界面" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【1】 查看个人信息                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【2】 账户充值                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【3】 升级为高级用户                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         【4】 返回用户菜单                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t请选择功能（1-4）：";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}
