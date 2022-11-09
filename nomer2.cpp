#include <bits/stdc++.h>
using namespace std;

class Mahasiswa
{

private:
    string NamaMHS;

public:
    void tampilNama()
    {
        cout << "Nama Mahasiswa : " << NamaMHS;
    }

    string getNama()
    {
        return NamaMHS;
    }

    Mahasiswa(string nama)
    {
        NamaMHS = nama;
    }
};

int main()
{

    Mahasiswa mhs1("Auditya");

    mhs1.tampilNama();

    cout << " ";

    cout << mhs1.getNama();

    return 0;
}