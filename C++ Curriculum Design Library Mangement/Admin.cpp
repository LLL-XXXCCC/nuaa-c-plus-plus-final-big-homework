#include "Admin.h"
#include "User.h"

Admin::Admin()
{
    currentAdmin = NULL;
    
    // ���ع���Ա���ݣ��������ʧ�ܣ��򴴽�Ĭ�Ϲ���Ա
    if (!Load_AdminData() || adminList.empty()) 
    {
        //����Ĭ�Ϲ���Ա�ṹ�壬��ʼ���˺ź�����
        AdminInfo defaultAdmin; 
        defaultAdmin.name = "admin";
        defaultAdmin.password = "password";
        
        adminList.push_back(defaultAdmin);  // ���Ĭ�Ϲ���Ա��adminList������
        Save_AdminData();   // ����Ĭ�Ϲ���Ա���ݵ��ļ�
    }
}

Admin::~Admin()
{
    Save_AdminData(); // ����ʱ��������
}

/*ÿ��coutǰ��/t/t���õ�¼������ӵ�����*/

bool Admin::Admin_Login()
{
    string inputName, inputPassword;
    cout << "\n\t\t���������Ա�˺ţ�";
    
    // ������뻺����
    while (cin.get() != '\n') continue;
    
    getline(cin, inputName);
    cout << "\t\t���������Ա���룺";
    getline(cin, inputPassword);
    
    for (size_t i = 0; i < adminList.size(); i++) 
    {
        // ���������˺ź������Ƿ������Ա�б��е�ƥ��
        if (adminList[i].name == inputName && adminList[i].password == inputPassword) 
        {
            currentAdmin = &adminList[i];   // adminList��ָ��ָ��ǰ��¼�Ĺ���Ա
            cout << "\n\t\t����¼�ɹ�����\n" << endl;
            return true;
        }
    }
    
    cout << "\n\t\t���˺Ż��������󣡡�\n" << endl;
    return false;
}

//���ļ�
bool Admin::Load_AdminData()
{
    ifstream inFile("admin.dat", ios::in);  //admin.dat�ļ��������Ա�˺ź�����
    if (!inFile) 
    {
        return false;
    }
    
    adminList.clear();  
    string name, password;
    
    // ���ļ��м��ع���Ա����
    while (getline(inFile, name)) 
    {
        if (getline(inFile, password)) 
        {
            AdminInfo admin;
            admin.name = name;
            admin.password = password;
            adminList.push_back(admin);
        }
    }
    
    inFile.close();
    return true;
}

//�������Ա���ݵ��ļ�
bool Admin::Save_AdminData()
{
    ofstream outFile("admin.dat", ios::out);
    if (!outFile) 
    {
        cout << "\n\t\t�޷����ļ��������Ա���ݣ�" << endl;
        return false;
    }
    
    for (const AdminInfo& admin : adminList) 
    {
        outFile << admin.name << endl;
        outFile << admin.password << endl;
    }
    
    outFile.close();
    return true;
}

//�޸�����:1.��֤������2.�������������һ��
void Admin::Change_Password()
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    string oldPwd, newPwd, confirmPwd;
    
    cout << "\n\t\t�����뵱ǰ���룺";
    // ȷ��������뻺����
    if (cin.fail())
    {
        cin.clear();
        while (cin.get() != '\n') continue;
    }
    else
    {
        // ������ܲ����Ļ��з�
        cin.ignore(10000, '\n');
    }
    
    getline(cin, oldPwd);
    
    if (oldPwd != currentAdmin->password) 
    {
        cout << "\n\t\t����������޷��޸ġ�\n" << endl;
        return;
    }
    
    cout << "\t\t�����������룺";
    getline(cin, newPwd);
    cout << "\t\t���ٴ����������룺";
    getline(cin, confirmPwd);
    
    if (newPwd != confirmPwd) 
    {
        cout << "\n\t\t��������������벻һ�£��޸�ʧ�ܡ�\n" << endl;
        return;
    }
    
    currentAdmin->password = newPwd;
    if (Save_AdminData()) 
    {
        cout << "\n\t\t�������޸ĳɹ�����\n" << endl;
    }

    else 
    {
        cout << "\n\t\t�������޸�ʧ�ܣ���\n" << endl;
    }
}

//����µĹ���Ա
void Admin::Add_NewAdmin()
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    string verifyPwd, newName, newPwd, confirmPwd;
    
    cout << "\n\t\t�����뵱ǰ����Ա���������֤��";
    // ȷ��������뻺����
    if (cin.fail())
    {
        cin.clear();
        while (cin.get() != '\n') continue;
    }
    else
    {
        // ������ܲ����Ļ��з�
        cin.ignore(10000, '\n');
    }
    
    getline(cin, verifyPwd);
    
    if (verifyPwd != currentAdmin->password) 
    {
        cout << "\n\t\t����������޷�����¹���Ա��\n" << endl;
        return;
    }
    
    cout << "\t\t�������¹���Ա�˺ţ�";
    getline(cin, newName);
    
    // ����˺��Ƿ��Ѵ���
    for (const AdminInfo& admin : adminList) 
    {
        if (admin.name == newName) 
        {
            cout << "\n\t\t���ù���Ա�˺��Ѵ��ڣ���\n" << endl;
            return;
        }
    }
    
    cout << "\t\t�������¹���Ա���룺";
    getline(cin, newPwd);
    cout << "\t\t���ٴ������¹���Ա���룺";
    getline(cin, confirmPwd);
    
    if (newPwd != confirmPwd) 
    {
        cout << "\n\t\t��������������벻һ�£����ʧ�ܡ�\n" << endl;
        return;
    }
    
    // �����µĹ���Ա������ӵ��б���
    AdminInfo newAdmin;
    newAdmin.name = newName;
    newAdmin.password = newPwd;
    adminList.push_back(newAdmin);
    
    if (Save_AdminData()) 
    {
        cout << "\n\t\t���¹���Ա��ӳɹ�����\n" << endl;
    } 
    
    else 
    {
        cout << "\n\t\t���¹���Ա���ʧ�ܣ���\n" << endl;
    }
}

// ��ʾ���й���Ա
void Admin::Show_AllAdmins()
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    cout << "\n\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                  ����Ա�б�                                        |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|  ���  |               ����Ա�˺�               |              ״̬               |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    
    if (adminList.empty()) 
    {
        cout << "\t|                               ���޹���Ա                                         |" << endl;
    } 
    
    // ��������Ա�б���ʾ��Ϣ
    else 
    {
        // ���ƿո�������������������
        for (size_t i = 0; i < adminList.size(); i++) 
        {
            string status = (currentAdmin == &adminList[i]) ? "��ǰ��¼" : "δ��¼";
            
            cout << "\t|   " << (i + 1);
            for (size_t j = 0; j < 5 - to_string(i + 1).length(); j++) 
            {
                cout << " ";
            }
            
            cout << "|  " << adminList[i].name;
            for (size_t j = 0; j < 35 - adminList[i].name.length(); j++) 
            {
                cout << " ";
            }
            
            cout << "|  " << status;
            for (size_t j = 0; j < 31 - status.length(); j++) 
            {
                cout << " ";
            }
            
            cout << "|" << endl;
        }
    }
    
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
}

void Admin::Delete_Admin()
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    if (adminList.size() <= 1) 
    {
        cout << "\n\t\t��ϵͳ������Ҫ����һ������Ա�˺ţ���\n" << endl;
        return;
    }
    
    Show_AllAdmins();
    
    string verifyPwd;
    cout << "\n\t\t�����뵱ǰ����Ա���������֤��";
    getline(cin, verifyPwd);
    
    if (verifyPwd != currentAdmin->password) 
    {
        cout << "\n\t\t����������޷�ɾ������Ա��\n" << endl;
        return;
    }
    
    int index;
    cout << "\t\t������Ҫɾ���Ĺ���Ա��ţ�";
    cin >> index;
    
    // ��ֹ����ѭ����������
    while (cin.fail() || index < 1 || index > (int)adminList.size())    // ������
    {
        cin.clear(); // ��������־
        cin.ignore(10000, '\n'); // �������뻺�����е���������
        cout << "\t\t������Ч�������������ţ�1-" << adminList.size() << "����";
        cin >> index;
    }
    
    index--; // ת��Ϊ��������
    
    // ����ɾ����ǰ��¼�Ĺ���Ա
    if (&adminList[index] == currentAdmin) 
    {
        cout << "\n\t\t������ɾ����ǰ��¼�Ĺ���Ա�˺ţ���\n" << endl;
        return;
    }
    
    // ȷ��ɾ��
    char confirm;
    cout << "\t\tȷ��ɾ������Ա \"" << adminList[index].name << "\" ��(Y/N)��";
    cin >> confirm;
    
    if (toupper(confirm) == 'Y') 
    {
        adminList.erase(adminList.begin() + index);
        
        if (Save_AdminData()) 
        {
            cout << "\n\t\t������Աɾ���ɹ�����\n" << endl;
        } 
        
        else 
        {
            cout << "\n\t\t������Աɾ��ʧ�ܣ���\n" << endl;
        }
    } 
    
    else 
    {
        cout << "\n\t\t����ȡ��ɾ��������\n" << endl;
    }
    
    // ������뻺����
    cin.ignore(10000, '\n');
}

// ɾ���û�����
void Admin::Delete_User(User* userSystem)
{
    if (!currentAdmin) 
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    // ��ʾ�����û�
    userSystem->Show_User();
    
    // ����Ƿ����û���ɾ��
    if (!userSystem->Has_Users()) 
    {
        cout << "\n\t\t��ϵͳ�����û���ɾ������\n" << endl;
        return;
    }
    
    string verifyPwd;
    cout << "\n\t\t�����뵱ǰ����Ա���������֤��";
    getchar(); // ������뻺����
    getline(cin, verifyPwd);
    
    if (verifyPwd != currentAdmin->password) 
    {
        cout << "\n\t\t����������޷�ɾ���û���\n" << endl;
        return;
    }
    
    int index;
    cout << "\t\t������Ҫɾ�����û���ţ�";
    cin >> index;
    
    // ������
    while (cin.fail() || index < 1)
    {
        cin.clear(); // ��������־
        cin.ignore(10000, '\n'); // �������뻺�����е���������
        cout << "\t\t������Ч�������������ţ�";
        cin >> index;
    }
    
    // ȷ��ɾ��
    char confirm;
    cout << "\t\tȷ��ɾ�����û���(Y/N)��";
    cin >> confirm;
    
    if (toupper(confirm) == 'Y') 
    {
        if (userSystem->Delete_UserByIndex(index - 1)) 
        {
            cout << "\n\t\t���û�ɾ���ɹ�����\n" << endl;
        } 
        else 
        {
            cout << "\n\t\t���û�ɾ��ʧ�ܣ���Ų����ڻ��޷�ɾ����ǰ��¼���û���\n" << endl;
        }
    } 
    else 
    {
        cout << "\n\t\t����ȡ��ɾ��������\n" << endl;
    }
    
    // ������뻺����
    cin.ignore(10000, '\n');
}
