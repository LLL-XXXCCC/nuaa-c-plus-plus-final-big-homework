/*Admin����vector��ʽ�洢����user��book���������ʽ�洢*/

/*���õ�VS Code��̣����ļ�����VS Codeֻ�ܰ���CPP�ļ���������*/
#include "Book.cpp"
#include "User.cpp"
#include "Admin.cpp"
#include "Menu.cpp"
#include <iostream>

/*����������������Ļ����Ͱ�include cppɾ�ˣ����������include h*/
// #include "Book.h"
// #include "User.h"
// #include "Admin.h"
// #include "Menu.h"

using namespace std;

// �޸����������ͨ�ú���
int getMenuChoice() 
{
    int choice;
    cin >> choice;
    
    // ��������Ƿ���Ч�������Ч���������״̬��������Ч����
    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(10000, '\n');
        return 0; // ����0��ʾ������һ���˵�
    }
    
    // ����������룬��ֹӰ�����getline
    cin.ignore(10000, '\n');
    return choice;
}

int main()
{
    // ��鲢�������Ŀ¼
    system("mkdir -p \"output\"");

    User user;
    Book book(&user);  // �����û�ϵͳָ���ͼ��ϵͳ
    Admin admin;
    Menu menu;
    
    int T = 1, n, N;
    
    //����Աϵͳ
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
                    case 1: // ��ʾ����ͼ��
                        book.Show_Book();
                        break;

                    case 2: // ���ͼ��
                        book.Add_Book();
                        break;

                    case 3: // ɾ��ͼ��
                        book.Del_Book();
                        break;

                    case 4: // ��ʾ�����û�
                        user.Show_User();
                        break;

                    case 5: // ɾ���û�
                        admin.Delete_User(&user);
                        break;

                    case 6: // ����Ա�˺Ź���
                    {
                        bool inAdminManageMenu = true;
                        
                        while (inAdminManageMenu) 
                        {
                            switch (menu.Admin_ManageMenu()) 
                            {
                                case 1: // �鿴���й���Ա
                                    admin.Show_AllAdmins();
                                    break;

                                case 2: // ����¹���Ա
                                    // ����Ҫ����� getchar()�������ڲ��ᴦ��
                                    admin.Add_NewAdmin();
                                    break;

                                case 3: // �޸ĵ�ǰ����
                                    // ����Ҫ����� getchar()�������ڲ��ᴦ��
                                    admin.Change_Password();
                                    break;

                                case 4: // ɾ������Ա
                                    // �������ͬ����Ҫ�������������������ʽ��ͬ
                                    getchar(); // ��Ȼ�����������Ϊ Delete_Admin ����������ͬ
                                    admin.Delete_Admin();
                                    break;

                                case 5: // ���ع���Ա�˵�
                                    inAdminManageMenu = false;
                                    break;

                                default:
                                    cout << "\n\t\t����Ч��ѡ���\n" << endl;
                            }
                            
                            if (inAdminManageMenu) 
                            {
                                cout << "\n\t\t��0���ع���Ա�˵�������������������Ա�˺Ų�����";
                                // ʹ���µ����뺯������ֹ�����ַ���ʱ������
                                int choice = getMenuChoice();
                                if (choice == 0) 
                                {
                                    inAdminManageMenu = false;
                                }
                            }
                        }
                    }
                        break;

                    case 7: // �������˵�
                        n = 0;
                        break;

                    default:
                        cout << "\n\t\t����Ч��ѡ�񣡡�\n" << endl;
                }
                
                if (n != 0) 
                {
                    cout << "\n\t\t��0�������˵�������������������Ա������";
                    // ʹ���µ����뺯������ֹ������ĸʱ����ѭ��
                    n = getMenuChoice();
                }
            }
            continue;
        }

        // �û���¼ϵͳ
        else if (N == 2) 
        {
            n = user.User_login();
            while (n)
            {
                switch (menu.User_Menu())
                {
                    case 1: // ��ʾ����ͼ��
                        book.Show_Book();
                        break;

                    case 2: // ����ͼ��
                        book.Search_Book();
                        break;

                    case 3: // ����ͼ��
                        book.Borrow_Book();
                        break;

                    case 4: // �黹ͼ��
                        book.Return_Book();
                        break;

                    case 5: // �鿴�ѽ���ͼ��
                        user.Show_BorrowedBooks();
                        break;

                    case 6: // �˻�����
                        {
                            bool inAccountMenu = true;
                            while (inAccountMenu)
                            {
                                switch (menu.User_AccountMenu())
                                {
                                    case 1: // �鿴������Ϣ
                                        user.Show_CurrentUserInfo();
                                        break;

                                    case 2: // �˻���ֵ
                                        user.TopUp_Account();
                                        break;

                                    case 3: // ����Ϊ�߼��û�
                                        user.Upgrade_ToPremium();
                                        break;

                                    case 4: // �����û��˵�
                                        inAccountMenu = false;
                                        break;

                                    default:
                                        cout << "\n\t\t����Ч��ѡ�񣡡�\n" << endl;
                                }
                                
                                if (inAccountMenu)
                                {
                                    cout << "\n\t\t��0�����û��˵����������������˻�������";
                                    // ʹ���µ����뺯������ֹ������ĸʱ����ѭ��
                                    int choice = getMenuChoice();
                                    if (choice == 0) 
                                    {
                                        inAccountMenu = false;
                                    }
                                }
                            }
                        }
                        break;
                    case 7: // �������˵�
                        n = 0;
                        break;
                    default:
                        cout << "\n\t\t����Ч��ѡ�񣡡�\n" << endl;
                }
                
                if (n != 0) 
                {
                    cout << "\n\t\t��0�������˵����������������û�������";
                    // ʹ���µ����뺯������ֹ������ĸʱ����ѭ��
                    n = getMenuChoice();
                }
            }
            continue;
        }

        // �û�ע��ϵͳ
        else if (N == 3)
        {
            user.Add_User();    // ��װ���˵�
            continue;
        }

        // �˳�ϵͳ
        else if (N == 4) 
        {
            cout << "\n\t\t��лʹ��ͼ�����ϵͳ���ټ���\n" << endl;
            return 0;
        }

        else
        {
            cout << "\n\t\t����Ч��ѡ�����������룡��\n" << endl;
        }
    }

    return 0;
}
