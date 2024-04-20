#include <iostream>
#include <string>
using namespace std;

// Phần 1: Khai báo và khởi tạo mảng chứa MSSV
string danhsachMSSV[5] = { "", "2301CT1234", "2302CT3456", "2305CT3999", "2304CT0002" };

// Phần 2: Nhập MSSV của người dùng vào phần tử đầu tiên của mảng
void nhapMSSV() {
    cout << "Nhap ma so sinh vien cua ban: ";
    getline(cin, danhsachMSSV[0]);
}

// Phần 3: In ra mảng MSSV theo thứ tự mặc định
void inMSSV() {
    cout << "Danh sach MSSV:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << danhsachMSSV[i] << endl;
    }
}

// Phần 4: Sắp xếp mảng MSSV theo chỉ số từ thấp đến cao
void sapXepMSSV() {
    for (int i = 0; i < 5 - 1; ++i) {
        for (int j = 0; j < 5 - i - 1; ++j) {
            string mssv1 = danhsachMSSV[j];
            string mssv2 = danhsachMSSV[j + 1];

            int index1 = stoi(mssv1.substr(0, 4));
            int index2 = stoi(mssv2.substr(0, 4));
            int tail1 = stoi(mssv1.substr(7));
            int tail2 = stoi(mssv2.substr(7));

            if (index1 > index2 || (index1 == index2 && tail1 > tail2)) {
                swap(danhsachMSSV[j], danhsachMSSV[j + 1]);
            }
        }
    }
}

// Phần 5: Tìm và in địa chỉ của phần tử chứa MSSV lớn nhất
void timMSSVLonNhat() {
    string *ptrArrayMSSV = danhsachMSSV;
    string *maxMSSV = ptrArrayMSSV;

    for (int i = 1; i < 5; ++i) {
        if (*ptrArrayMSSV < danhsachMSSV[i]) {
            maxMSSV = ptrArrayMSSV + i;
        }
    }

    cout << "Dia chi cua phan tu chua MSSV lon nhat: " << maxMSSV << endl;
    cout << "MSSV lon nhat: " << *maxMSSV << endl;
}

int main() {
    nhapMSSV(); // Phần 2
    inMSSV(); // Phần 3

    sapXepMSSV(); // Phần 4
    cout << "\nDanh sach MSSV sau khi sap xep:" << endl;
    inMSSV(); // In mảng đã sắp xếp

    timMSSVLonNhat(); // Phần 5

    return 0;
}
