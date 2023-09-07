#include <iostream>
using namespace std;

class Operator 
{
    public:
        virtual int Cal(int *a, int n, int result_pre) = 0;    
};

class Cong : public Operator
{
    int Cal(int *a, int n, int result_pre)
    {   
        int sum = result_pre;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        return sum;
    }
};

class Tru : public Operator
{
    int Cal(int *a, int n, int result_pre) 
    {
        int miner = result_pre;
        for (int i = 0; i < n; i++)
        {
            miner -= a[i];
        }
        return miner;
    }
};

class Nhan : public Operator
{
    int Cal(int *a, int n, int result_pre) 
    {
        int multi = result_pre;
        for (int i = 0; i < n; i++)
        {
            multi *= a[i];
        }
        return multi;
    }
};

class Chia : public Operator
{
    int Cal(int *a, int n, int result_pre) 
    {
        float div = result_pre;
        for (int i = 0; i < n; i++)
        {
            div /= a[i];
        }
        return div;
    }
};

class Calculator
{
    public:
        int size;
        int capable;
        int *results;  
        Operator *PhepTinh;

        Calculator()
        {
            size = 0;
            capable = 20;
            results = new int[capable];
            PhepTinh = nullptr;
        }

        ~Calculator()
        {
            delete[] results;
        }

        void Save_Result(int result)
        {   
            int *newResult = new int[capable]; //mang 
            for (int i = 0; i < size; i++)
            {
                newResult[i] = results[i];
            } 
            delete[] results;
            results = newResult;
            results[size++] = result;
        }


        void Out_Save()
        {
            cout << "Cac gia tri da luu truoc do: ";
            for (int i = 0; i < size; i++)
            {
                cout << results[i] << " ";
            }
            cout << endl;
        }

        void Choose_Ope(Operator *temp)
        {
            PhepTinh = temp;
        }

        Operator *Chosen_Ope() 
        {
            return PhepTinh;
        }
        
};

int main()
{
    //Nhap mang
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i + 1 << "]: ";
        cin >> a[i];
    }

    //Xuat mang
    cout << "Mang da nhap: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
    Cong *PhepCong = new Cong;
    Tru *PhepTru = new Tru;
    Nhan *PhepNhan = new Nhan;
    Chia *PhepChia = new Chia;

    int result_pre = 0;
    int result = 0;
    char pheptinh; 
    Calculator Call_Ope;

    while (true)
    {
        cout << "\nPhep tinh se nhap: ";
        cin >> pheptinh;

        if (pheptinh == '1')
        {
            break;
        }
        else if (pheptinh == '+')
        {
            Call_Ope.Choose_Ope(PhepCong);
        }
        else if (pheptinh == '-')
        {
            Call_Ope.Choose_Ope(PhepTru);
        }
        else if (pheptinh == '*')
        {
            Call_Ope.Choose_Ope(PhepNhan);
        }
        else if (pheptinh == '/')
        {
            Call_Ope.Choose_Ope(PhepChia);
        }
        if (Call_Ope.Chosen_Ope() != nullptr)
        {
            result = Call_Ope.Chosen_Ope()->Cal(a, n, result_pre);
            result_pre = result;
            Call_Ope.Save_Result(result);
            cout << "Ket qua: " << result << endl; 
        }
    }        
    Call_Ope.Out_Save();
    delete PhepCong;
    delete PhepTru;
    delete PhepNhan;
    delete PhepChia;
    delete[] a;
}