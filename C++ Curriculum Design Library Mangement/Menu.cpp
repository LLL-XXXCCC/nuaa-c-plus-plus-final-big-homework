/*
��������������չʾ�˵��ĸ�ʽ�������������ж�������main������ʵ��
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
    cout << "\t|                         ͼ �� �� �� ϵ ͳ                                     |" << endl;
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
    
    cout << "\n\t\t\t          ��ӭʹ��ͼ�����ϵͳ��" << endl;
    cout << "\t\t\t   ��ʼ����Ա��¼��Ϣ���˺ţ�admin ���룺password\n" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��1�� ����Ա��¼                                      |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��2�� �û���¼                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��3�� �û�ע��                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��4�� �˳�ϵͳ                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t��ѡ���ܣ�1-4����";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}

int Menu::Admin_Menu()
{
    int n;
    
    DisplayHeader();
    
    cout << "\n\t\t\t          ��ӭ�������Ա���棡" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��1�� ��ʾ����ͼ��                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��2�� ���ͼ��                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��3�� ɾ��ͼ��                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��4�� ��ʾ�����û�                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��5�� ɾ���û�                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��6�� ����Ա�˺Ź���                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��7�� �������˵�                                      |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t��ѡ���ܣ�1-7����";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}

int Menu::User_Menu()
{
    int n;
    
    DisplayHeader();
    
    cout << "\n\t\t\t          ��ӭ�����û����棡" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��1�� ��ʾ����ͼ��                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��2�� ����ͼ��                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��3�� ����ͼ��                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��4�� �黹ͼ��                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��5�� �鿴�ѽ���ͼ��                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��6�� �˻�����                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��7�� �������˵�                                      |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t��ѡ���ܣ�1-7����";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}

int Menu::Admin_ManageMenu()
{
    int n;
    
    DisplayHeader();
    
    cout << "\n\t\t\t          ����Ա�˺Ź������" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��1�� �鿴���й���Ա                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��2�� ����¹���Ա                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��3�� �޸ĵ�ǰ����                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��4�� ɾ������Ա                                      |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��5�� ���ع���Ա�˵�                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t��ѡ���ܣ�1-5����";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}

int Menu::User_AccountMenu()
{
    int n;
    
    DisplayHeader();
    
    cout << "\n\t\t\t          �û��˻��������" << endl;
    
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��1�� �鿴������Ϣ                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��2�� �˻���ֵ                                        |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��3�� ����Ϊ�߼��û�                                  |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t|                         ��4�� �����û��˵�                                    |" << endl;
    cout << "\t|                                                                               |" << endl;
    cout << "\t+-------------------------------------------------------------------------------+" << endl;
    
    cout << "\n\t\t��ѡ���ܣ�1-4����";
    cin >> n;
    
    DisplayFooter();
    
    return n;
}
