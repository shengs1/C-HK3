#include <iostream>
using namespace std;

class SP {
private:
    double thuc;
    double ao;
public:
    SP(double r = 0, double i = 0) : thuc(r), ao(i) {}

    SP operator + (const SP& C) const {
        return SP(thuc + C.thuc, ao + C.ao);
    }

    SP operator - (const SP& C) const {
        return SP(thuc - C.thuc, ao - C.ao);
    }

    SP operator * (const SP& C) const {
        return SP(thuc * C.thuc - ao * C.ao, thuc * C.ao + ao * C.thuc);
    }

    SP operator / (const SP& C) const {
        double mauso = C.thuc * C.thuc + C.ao * C.ao;
        return SP((thuc * C.thuc + ao * C.ao) / mauso, (ao * C.thuc - thuc * C.ao) / mauso);
    }

    void display() const {
        if (ao >= 0)
            cout << thuc << " + " << ao << "i" << endl;
        else
            cout << thuc << " - " << -ao << "i" << endl;
    }
};

int main() {
    SP a(5, -7);
    SP b(4, 2);
    SP result;

    result = a + b;
    cout << "a + b = ";
    result.display();

    result = a - b;
    cout << "a - b = ";
    result.display();

    result = a * b;
    cout << "a * b = ";
    result.display();

    result = a / b;
    cout << "a / b = ";
    result.display();

    return 0;
}
