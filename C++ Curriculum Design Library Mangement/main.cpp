/*Admin采用vector形式存储，而user和book以链表的形式存储*/

/*我用的VS Code编程，多文件连编VS Code只能包含CPP文件才能运行*/
#include "Book.cpp"
#include "User.cpp"
#include "Admin.cpp"
#include "Menu.cpp"
#include <iostream>

/*如果用其他编译器的话，就把include cpp删了，换成下面的include h*/
// #include "Book.h"
// #include "User.h"
// #include "Admin.h"
// #include "Menu.h"

using namespace std;

// 修复输入问题的通用函数
int getMenuChoice() 
{
    int choice;
    cin >> choice;
    
    // 检查输入是否有效，如果无效则清除错误状态并丢弃无效输入
    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(10000, '\n');
        return 0; // 返回0表示返回上一级菜单
    }
    
    // 清除多余输入，防止影响后续getline
    cin.ignore(10000, '\n');
    return choice;
}

int main()
{
    // 检查并创建输出目录
    system("mkdir -p \"output\"");

    User user;
    Book book(&user);  // 传递用户系统指针给图书系统
    Admin admin;
    Menu menu;
    
    int T = 1, n, N;
    
    //管理员系统
    while (T == 1)
    {
        N = menu.Main_Menu();
        
        if (N == 1)
        {
            n = admin.Admin_Login();
            while (n)
            {
                switch (menu.Admin_Menu())
                {
                    case 1: // 显示所有图书
                        book.Show_Book();
                        break;

                    case 2: // 添加图书
                        book.Add_Book();
                        break;

                    case 3: // 删除图书
                        book.Del_Book();
                        break;

                    case 4: // 显示所有用户
                        user.Show_User();
                        break;

                    case 5: // 删除用户
                        admin.Delete_User(&user);
                        break;

                    case 6: // 管理员账号管理
                    {
                        bool inAdminManageMenu = true;
                        
                        while (inAdminManageMenu) 
                        {
                            switch (menu.Admin_ManageMenu()) 
                            {
                                case 1: // 查看所有管理员
                                    admin.Show_AllAdmins();
                                    break;

                                case 2: // 添加新管理员
                                    // 不需要额外的 getchar()，函数内部会处理
                                    admin.Add_NewAdmin();
                                    break;

                                case 3: // 修改当前密码
                                    // 不需要额外的 getchar()，函数内部会处理
                                    admin.Change_Password();
                                    break;

                                case 4: // 删除管理员
                                    // 这个函数同样需要清除缓冲区，但它处理方式不同
                                    getchar(); // 依然保留这个，因为 Delete_Admin 函数有所不同
                                    admin.Delete_Admin();
                                    break;

                                case 5: // 返回管理员菜单
                                    inAdminManageMenu = false;
                                    break;

                                default:
                                    cout << "\n\t\t《无效的选项！》\n" << endl;
                            }
                            
                            if (inAdminManageMenu) 
                            {
                                cout << "\n\t\t按0返回管理员菜单，按其他键继续管理员账号操作：";
                                // 使用新的输入函数，防止输入字符串时的歧义
                                int choice = getMenuChoice();
                                if (choice == 0) 
                                {
                                    inAdminManageMenu = false;
                                }
                            }
                        }
                    }
                        break;

                    case 7: // 返回主菜单
                        n = 0;
                        break;

                    default:
                        cout << "\n\t\t【无效的选择！】\n" << endl;
                }
                
                if (n != 0) 
                {
                    cout << "\n\t\t按0返回主菜单，按其他键继续管理员操作：";
                    // 使用新的输入函数，防止输入字母时的死循环
                    n = getMenuChoice();
                }
            }
            continue;
        }

        // 用户登录系统
        else if (N == 2) 
        {
            n = user.User_login();
            while (n)
            {
                switch (menu.User_Menu())
                {
                    case 1: // 显示所有图书
                        book.Show_Book();
                        break;

                    case 2: // 搜索图书
                        book.Search_Book();
                        break;

                    case 3: // 借阅图书
                        book.Borrow_Book();
                        break;

                    case 4: // 归还图书
                        book.Return_Book();
                        break;

                    case 5: // 查看已借阅图书
                        user.Show_BorrowedBooks();
                        break;

                    case 6: // 账户管理
                        {
                            bool inAccountMenu = true;
                            while (inAccountMenu)
                            {
                                switch (menu.User_AccountMenu())
                                {
                                    case 1: // 查看个人信息
                                        user.Show_CurrentUserInfo();
                                        break;

                                    case 2: // 账户充值
                                        user.TopUp_Account();
                                        break;

                                    case 3: // 升级为高级用户
                                        user.Upgrade_ToPremium();
                                        break;

                                    case 4: // 返回用户菜单
                                        inAccountMenu = false;
                                        break;

                                    default:
                                        cout << "\n\t\t【无效的选择！】\n" << endl;
                                }
                                
                                if (inAccountMenu)
                                {
                                    cout << "\n\t\t按0返回用户菜单，按其他键继续账户操作：";
                                    // 使用新的输入函数，防止输入字母时的死循环
                                    int choice = getMenuChoice();
                                    if (choice == 0) 
                                    {
                                        inAccountMenu = false;
                                    }
                                }
                            }
                        }
                        break;
                    case 7: // 返回主菜单
                        n = 0;
                        break;
                    default:
                        cout << "\n\t\t【无效的选择！】\n" << endl;
                }
                
                if (n != 0) 
                {
                    cout << "\n\t\t按0返回主菜单，按其他键继续用户操作：";
                    // 使用新的输入函数，防止输入字母时的死循环
                    n = getMenuChoice();
                }
            }
            continue;
        }

        // 用户注册系统
        else if (N == 3)
        {
            user.Add_User();    // 封装好了的
            continue;
        }

        // 退出系统
        else if (N == 4) 
        {
            cout << "\n\t\t感谢使用图书管理系统，再见！\n" << endl;
            return 0;
        }

        else
        {
            cout << "\n\t\t【无效的选择，请重新输入！】\n" << endl;
        }
    }

    return 0;
}
