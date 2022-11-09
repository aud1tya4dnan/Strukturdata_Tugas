#include <iostream>
using namespace std;

class MHS {
    public:
    string MHSname;

    void printname() {
        cout<<"MHS name is : "<<MHSname;
    }
};


int main() {
    MHS mhs1;
    MHS mhs2;
    mhs1.MHSname = "Auditya";
    mhs1.printname();
    return 0;
}