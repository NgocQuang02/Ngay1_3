#include <iostream>
using namespace std;

class TinhToan
{
    public:
        virtual int tinh(int *a, int n, int result_pre) = 0;    
};

class Cong : public TinhToan
{
    public:
        int tinh(int *a, int n, int result_pre) override
        {   
            int sum = result_pre;
            for (int i = 0; i < n; i++)
            {
                sum += a[i];
            }
            return sum;
        }
};

class Tru : public TinhToan
{
    public:
        int tinh(int *a, int n, int result_pre) override
        {
            int miner = result_pre;
            for (int i = 0; i < n; i++)
            {
                miner -= a[i];
            }
            return miner;
        }
};

class Nhan : public TinhToan
{
    public:
        int tinh(int *a, int n, int result_pre) override
        {
            int multi = result_pre;
            for (int i = 0; i < n; i++)
            {
                multi *= a[i];
            }
            return multi;
        }

};

class Chia : public TinhToan
{
    public: 
        int tinh(int *a, int n, int result_pre) override
        {
            float div = result_pre;
            for (int i = 0; i < n; i++)
            {
                div /= a[i];
            }
            return div;
        }
};

// class calculator
// {
//     public:
//         int result_pre;
//         int setResult_pre
//         {
//             return result_pre;
//         }
// };


int main()
{
    int n;
    //Nhap mang
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i+1 << "]: ";
        cin >> a[i];
    }

    //Xuat mang
    cout << "Mang da nhap: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    Cong PhepCong;
    Tru PhepTru;
    Nhan PhepNhan;
    Chia PhepChia;
    // Save save; 

    int result_pre = 0;
    char pheptinh;

    while (true)
    {
        cout << "\nPhep tinh se nhap: ";
        cin >> pheptinh;

        if (pheptinh == '1')
        {
            break;
        }

        if (pheptinh == '+')
        {
            result_pre = PhepCong.tinh(a, n, result_pre);
            cout << "Ket qua: " << result_pre;
        }
        else if (pheptinh == '-')
        {
            result_pre = PhepTru.tinh(a, n, result_pre);
            cout << "Ket qua: " << result_pre;
        }
        else if (pheptinh == '*')
        {
            result_pre = PhepNhan.tinh(a, n, result_pre);
            cout << "Ket qua: " << result_pre;
        }
        else if (pheptinh == '/')
        {
            result_pre = PhepChia.tinh(a, n, result_pre);
            cout << "Ket qua: " << result_pre;
        }
    }    
    //cout << save.Save_Pre(a, n, result_pre);
    delete[] a;
}
