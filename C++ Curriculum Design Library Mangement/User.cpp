#include "User.h"

User::User()
{
    head = NULL;
    currentUser = NULL;
    Create_Node();
    Load_Users(); // ��ʼ��ʱ�����û�����
}

User::~User()
{
    Save_Users(); // ����ʱ��������
    
    // �ͷ������ڴ�
    Nuser* current = head;
    while (current != NULL) 
    {
        Nuser* temp = current;
        current = current->next;
        delete temp;
    }
}

// �����û�����ͷ�ڵ�
void User::Create_Node()
{
    if (head == NULL) 
    {
        head = new Nuser;
        head->next = NULL;
    }
}

// ������֪ʶ���������Ҹ�ʽ�����
void User::Show_User()
{
    cout << "\n\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                  �û���Ϣ�б�                                      |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|  �û���        |  �Ա�  |  ����  |        �绰        |  �û�����  |  ��������    |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    
    if (head->next == NULL)
    {
        cout << "\t|                            �����û���Ϣ                                        |" << endl;
    }

    else
    {
        Nuser* pshow = head;
        while (pshow->next != NULL)
        {
            pshow = pshow->next;
            string userType = pshow->isPremium ? "�߼��û�" : "��ͨ�û�";
            cout << "\t|  " << pshow->name;
            // ���ո�ʹ������
            for (size_t i = 0; i < 14 - pshow->name.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << pshow->sex;

            for (size_t i = 0; i < 6 - pshow->sex.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << pshow->old;

            for (size_t i = 0; i < 6 - pshow->old.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << pshow->tel;

            for (size_t i = 0; i < 18 - pshow->tel.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << userType;

            for (size_t i = 0; i < 10 - userType.length(); i++) 
            {
                cout << " ";
            }
            cout << "|  " << pshow->borrowedBooks.size() << "           |" << endl;
        }
    }
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
}

// ����ڵ㼴�����µ��û�
void User::Add_User()
{
    Nuser* insert = head;
    while (insert->next != NULL)
    {
        insert = insert->next;
    }
    Nuser* pnew = new Nuser;
    pnew->next = NULL;
    pnew->isPremium = false;
    pnew->balance = 0.0;
    
    cout << "\n\t\t�������û�������";
    getchar();
    // ʹ��getline��������ո�
    getline(cin, pnew->name);
    cout << "\t\t�������Ա�";

    getline(cin, pnew->sex);
    cout << "\t\t���������䣺";

    getline(cin, pnew->old);
    cout << "\t\t������绰��";

    getline(cin, pnew->tel);
    cout << "\t\t���������룺";

    getline(cin, pnew->pwd);
    
    insert->next = pnew;
    cout << "\n\t\t����ϲ����ע��ɹ���\n" << endl;
    
    // ����û����������浽�ļ�
    Save_Users();
}

// �ж��û���¼�����Ƿ���ȷ
bool User::User_login()
{
    getchar();
    string s1, s2;
    cout << "\n\t\t�û�����";
    getline(cin, s1);
    cout << "\t\t���룺";
    getline(cin, s2);
    
    Nuser* pserch = head;
    while (pserch->next != NULL && pserch->next->name != s1)
    {
        pserch = pserch->next;
    }

    if (pserch->next == NULL)
    {
        cout << "\n\t\t���û��������ڣ���\n" << endl;
        return false;
    }

    if ((pserch->next != NULL) && (s2 == pserch->next->pwd))
    {
        currentUser = pserch->next;
        cout << "\n\t\t����¼�ɹ�����\n" << endl;
        return true;
    }

    else
    {
        cout << "\n\t\t����¼ʧ�ܣ���\n" << endl;
        return false;
    }
}

// �����û����ݵ��ļ�������
bool User::Save_Users() 
{
    ofstream outFile("users.dat", ios::out);
    if (!outFile) 
    {
        cout << "\n\t\t�޷����ļ������û����ݣ�" << endl;
        return false;
    }
    
    Nuser* current = head->next;
    while (current != NULL) 
    {
        outFile << current->name << endl;
        outFile << current->sex << endl;
        outFile << current->old << endl;
        outFile << current->tel << endl;
        outFile << current->pwd << endl;
        outFile << (current->isPremium ? "1" : "0") << endl;  // �����û�����
        outFile << current->balance << endl;                   // �������
        outFile << current->borrowedBooks.size() << endl;      // ��������鼮����
        
        // ��������鼮
        for (const string& book : current->borrowedBooks)   //��仰�Ǳ��������鼮��д���ļ���
        {
            outFile << book << endl;
        }
        
        current = current->next;
    }
    
    outFile.close();
    return true;
}

// ���ļ������û����ݣ�д��
bool User::Load_Users() 
{
    ifstream inFile("users.dat", ios::in);
    if (!inFile) 
    {
        // ����ļ������ڣ�����false����������
        return false;
    }
    
    // �����������
    while (head->next != NULL) 
    {
        Nuser* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    
    // ��ȡ�ļ�����������
    string name, sex, old, tel, pwd, isPremium, balance;
    string bookCount;
    Nuser* last = head;
    
    while (getline(inFile, name)) 
    {
        getline(inFile, sex);
        getline(inFile, old);
        getline(inFile, tel);
        getline(inFile, pwd);
        getline(inFile, isPremium);
        getline(inFile, balance);
        getline(inFile, bookCount);
        
        Nuser* newNode = new Nuser;
        newNode->name = name;
        newNode->sex = sex;
        newNode->old = old;
        newNode->tel = tel;
        newNode->pwd = pwd;
        newNode->isPremium = (isPremium == "1");
        newNode->balance = stod(balance);
        newNode->next = NULL;
        
        // ��ȡ�����鼮
        int count = stoi(bookCount);
        for (int i = 0; i < count; i++)
        {
            string book;
            getline(inFile, book);
            newNode->borrowedBooks.push_back(book);
        }
        
        last->next = newNode;
        last = newNode;
    }
    
    inFile.close();
    return true;
}

// �ж���ͨ��߼��û��Ƿ��ܽ���ͼ��
void User::Borrow_Book(string bookName, string bookNumber)
{
    if (!currentUser)
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    // ����Ƿ���Խ���
    if (!Can_BorrowBook())
    {
        if (!currentUser->isPremium)
        {
            cout << "\n\t\t����ͨ�û�ֻ�ܽ���1���飬���Ѵﵽ���ޣ���" << endl;
            cout << "\t\t����������Ϊ�߼��û�������޽���Ȩ�ޡ�\n" << endl;
        }
        return;
    }
    
    // ��ӵ������б�
    currentUser->borrowedBooks.push_back(bookName + " (" + bookNumber + ")");
    
    cout << "\n\t\t���ɹ�����"" << bookName << ""����\n" << endl;
    
    // �����û�����
    Save_Users();
}

// �ж��û��Ƿ���Ի��� 
void User::Return_Book(string bookName)
{
    if (!currentUser)
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    bool found = false;
    for (auto it = currentUser->borrowedBooks.begin(); it != currentUser->borrowedBooks.end(); it++)
    {
        if (it->find(bookName) != string::npos)
        {
            currentUser->borrowedBooks.erase(it);
            found = true;
            break;
        }
    }
    
    if (found)
    {
        cout << "\n\t\t���ɹ��黹"" << bookName << ""����\n" << endl;
        Save_Users();
    }
	
    else
    {
        cout << "\n\t\t����δ����"" << bookName << ""����\n" << endl;
    }
}

// ��ֵ
void User::TopUp_Account()
{
    if (!currentUser)
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    double amount;
    cout << "\n\t\t��ǰ��" << currentUser->balance << " Ԫ" << endl;
    cout << "\t\t�������ֵ��";
    cin >> amount;
    
    if (amount <= 0)
    {
        cout << "\n\t\t����ֵ���������0����\n" << endl;
        return;
    }
    
    currentUser->balance += amount;
    Save_Users();
    
    cout << "\n\t\t����ֵ�ɹ�����ǰ��" << currentUser->balance << " Ԫ��\n" << endl;
}

// ����Ϊ�߼��û�
void User::Upgrade_ToPremium()
{
    if (!currentUser)
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    if (currentUser->isPremium)
    {
        cout << "\n\t\t�����Ѿ��Ǹ߼��û�����\n" << endl;
        return;
    }
    
    const double premiumFee = 50.0;
    
    cout << "\n\t\t����Ϊ�߼��û���Ҫ֧�� " << premiumFee << " Ԫ" << endl;
    cout << "\t\t��ǰ��" << currentUser->balance << " Ԫ" << endl;
    
    if (currentUser->balance < premiumFee)
    {
        cout << "\n\t\t�����㣬���ȳ�ֵ����\n" << endl;
        return;
    }
    
    char choice;
    cout << "\t\tȷ������Ϊ�߼��û���(Y/N)��";
    cin >> choice;
    
    if (toupper(choice) == 'Y')
    {
        currentUser->balance -= premiumFee;
        currentUser->isPremium = true;
        Save_Users();
        
        cout << "\n\t\t����ϲ�������ɹ����������Ǹ߼��û���" << endl;
        cout << "\t\t���߼��û��������޽���ͼ�顿\n" << endl;
    }

    else
    {
        cout << "\n\t\t����ȡ��������\n" << endl;
    }
}

// ��ʾ��ǰ�û���Ϣ
void User::Show_CurrentUserInfo()
{
    if (!currentUser)
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    cout << "\n\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                  �û�������Ϣ                                      |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t| �û�����" << currentUser->name;

	// ���ո�ʹ������
    for (size_t i = 0; i < 73 - currentUser->name.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| �Ա�" << currentUser->sex;

	// ���ո�ʹ������
    for (size_t i = 0; i < 75 - currentUser->sex.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| ���䣺" << currentUser->old;

	// ���ո�ʹ������
    for (size_t i = 0; i < 75 - currentUser->old.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| �绰��" << currentUser->tel;

	// ���ո�ʹ������
    for (size_t i = 0; i < 75 - currentUser->tel.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    
    string userType = currentUser->isPremium ? "�߼��û�" : "��ͨ�û�";
    cout << "\t| �û����ͣ�" << userType;
    for (size_t i = 0; i < 71 - userType.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| �˻���" << currentUser->balance << " Ԫ";

    string balanceStr = to_string(currentUser->balance);
    for (size_t i = 0; i < 69 - balanceStr.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t| �ѽ����鼮������" << currentUser->borrowedBooks.size();

    string bookCountStr = to_string(currentUser->borrowedBooks.size());
    for (size_t i = 0; i < 65 - bookCountStr.length(); i++) 
	{
		cout << " ";
	}
    cout << "|" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
}

// ��ʾ�ѽ���ͼ��
void User::Show_BorrowedBooks()
{
    if (!currentUser)
    {
        cout << "\n\t\t�����ȵ�¼����\n" << endl;
        return;
    }
    
    cout << "\n\t+------------------------------------------------------------------------------------+" << endl;
    cout << "\t|                                �ѽ���ͼ���б�                                      |" << endl;
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
    
    if (currentUser->borrowedBooks.empty())
    {
        cout << "\t|                                 ���޽���ͼ��                                     |" << endl;
    }
	
    else
    {
        for (size_t i = 0; i < currentUser->borrowedBooks.size(); i++)
        {
            cout << "\t| " << (i + 1) << ". " << currentUser->borrowedBooks[i];
            for (size_t j = 0; j < 80 - currentUser->borrowedBooks[i].length() - 3 - to_string(i + 1).length(); j++)
            {
                cout << " ";
            }
                
            cout << "|" << endl;
        }
    }
    
    cout << "\t+------------------------------------------------------------------------------------+" << endl;
}

//���ѽ����鼮���������ж��û��Ƿ���Խ���
bool User::Can_BorrowBook()
{
    if (!currentUser)
        return false;
    
    // �߼��û��������޽���
    if (currentUser->isPremium)
        return true;
    
    // ��ͨ�û�ֻ�ܽ���1��
    return currentUser->borrowedBooks.size() < 1;
}

// ������ɾ���û�
bool User::Delete_UserByIndex(int index)
{
    if (index < 0 || head == NULL || head->next == NULL)
        return false;
    
    Nuser* current = head;
    int currentIndex = 0;
    
    // �ҵ�Ҫɾ���Ľڵ��ǰһ���ڵ�
    while (current->next != NULL && currentIndex < index)
    {
        current = current->next;
        currentIndex++;
    }
    
    // ����Ҳ�������������һ���ڵ�Ϊ�գ�����ʧ��
    if (current->next == NULL || currentIndex != index)
        return false;
    
    // ����Ƿ�Ҫɾ����ǰ��¼���û�
    if (current->next == currentUser)
        return false;
    
    // ɾ���ڵ�
    Nuser* toDelete = current->next;
    current->next = toDelete->next;
    
    delete toDelete;
    
    // ������º���û�����
    Save_Users();
    
    return true;
}
