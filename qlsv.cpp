#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

int res = 0;
using namespace std;


struct Sinhvien
{
    /* data */
    int msv;
    char ten[30];
    double diemtoan, diemvan, diemanh;

    void Nhap() {
        cout << "Nhap ma so sinh vien: ";
        cin >> msv;
        cout << "Nhap ho va ten sinh vien: ";
        fflush(stdin);
        gets_s(ten);
        do
        {
            cout << "Nhap diem toan: ";
            cin >> diemtoan;
            cout << "Nhap diem van: ";
            cin >> diemvan;
            cout << "Nhap diem anh: ";
            cin >> diemanh;

            if (diemtoan < 0 || diemvan < 0 || diemanh < 0 || diemanh>10 || diemtoan>10 || diemvan>10) {
                cout << "Moi ban nhap lai diem khong hop le\n";
            }
        } while (diemtoan < 0 || diemvan < 0 || diemanh < 0 || diemanh>10 || diemtoan>10 || diemvan>10);
    }
    double DiemTB() {
        return ((diemtoan + diemvan + diemanh) / 3);
    }
    void Xuat() {
        cout << setw(2) << ++res << setw(8) << msv << setw(10) << ten << setw(12) << diemtoan;
        cout << setw(12) << diemvan << setw(12) << diemanh << setw(12) << DiemTB() << endl;
    }
};

typedef Sinhvien SV;

// hàm nhập số lượng sinh viên

void NhapSL(int& n) {
    do
    {
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        if (n < 0) {
            cout << "Moi ban nhap lai\n";
        }
    } while (n < 0);
}

// ham nhap danh sach sinh vien

void NhapSV(SV* sv, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        do
        {
            cout << "Nhap thong tinh sinh vien thu " << i + 1 << ": " << endl;
            sv[i].Nhap();
            for (int j = 0; j < i; j++) {
                if (sv[j].msv == sv[i].msv) {
                    cout << "Moi ban nhap lai\n";
                    cnt++;
                }
            }
        } while (res != 0);

    }
}


// hàm tiêu đề
void Tieude() {
    cout << setw(2) << "STT " << setw(8) << "MSV" << setw(10) << setw(10) << "Ho Ten" << setw(12) << "Diem toan";
    cout << setw(12) << "Diem van" << setw(12) << "Diem anh" << setw(12) << "Diem TB";
}

// hàm xuất sinh viên
void XuatSV(SV* sv, int n) {
    Tieude();
    for (int i = 0; i < n; i++) {
        sv[i].Xuat();
    }
}

//hàm thêm sinh viên
void Them_SV(SV* sv, int& n) {
    n++;
    int cnt = 0;
    do
    {
        cnt = 0;
        cout << "Nhap thong tin sinh vien: ";
        sv[n - 1].Nhap();
        for (int i = 0; i < n; i++) {
            if (sv[i].msv == sv[n - 1].msv) {
                cout << "Ma so sinh vien khong hop le. Moi ban nhap lai!";
                cnt++;
            }
        }
    } while (cnt != 0);

}

// hàm xoá sinh viên
void Xoa(SV* sv, int n) {
    int soct;
    int cnt = 0;
    cout << "Nhap ma so sinh vien ban can xoa: ";
    cin >> soct;
    for (int i = 0; i < n; i++) {
        if (sv[i].msv == soct) {
            cnt++;
            for (int j = 0; j < n; i++) {
                sv[j] = sv[j + 1];
            }
        }
    }
    if (cnt == 0) {
        cout << "Ma so sinh vien khong hop le!";
    }
    else n--;
}

// hàm tìm kiếm sv
void TiemKiem(SV* sv, int n) {
    int ms, cnt = 0;
    cout << "Nhap ma sinh vien can tim kiem: ";
    cin >> ms;
    for (int i = 0; i < n; i++) {
        if (sv[i].msv == ms) {
            sv[i].Xuat();
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "Ma So Sinh Vien khong co trong danh sach!" << endl;
    }
}
void Menu() {
    cout << "==========================================" << "\n";
    cout << " MENU " << "\n";
    cout << "==========================================" << "\n";
    cout << " 1. Nhap danh sach sinh vien" << "\n";
    cout << " 2. Hien thi danh sach sinh vien" << "\n";
    cout << " 3. Them thong tin 1 sinh vien" << "\n";
    cout << " 4. Xoa thong tin 1 sinh vien" << "\n";
    cout << " 5. Tim sinh vien boi ma so sinh vien" << "\n";
    cout << "0. Thoat" << endl;
}
void Press() {
    system("pause");
    system("cls");
}
// hàm tính điểm trung từng môn 
double diemTBmon(SV *sv, int n){
    double sum1 =0, sum2 =0, sum3=0;
    for(int i=0;i<n;i++){
        sum1 += sv[i].diemtoan;
        sum2 += sv[i].diemvan;
        sum3 += sv[i].diemanh;
    }
    return {(sum1/n,sum2/n,sum3/n)};
}

int main() {
    int n = 0;
    char chon;
    SV* sv;
    sv = new SV[100];
    int luachon;
    do
    {
        Menu();
        cout << "Moi ban nhap lua chon!\n";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            NhapSL(n);
            NhapSV(sv, n);
            Press();
            break;
        }
        case 2:
        {
            XuatSV(sv, n);
            Press();
        }
        case 3:
        {
            Them_SV(sv, n);
            Press();
            break;
        }
        case 4:
        {
            Xoa(sv, n);
            Press();
            break;
        }
        case 5:
        {
            TiemKiem(sv, n);
            Press();
            break;
        }
        default:
            cout << "Ban da nhap sai lua chon!" << endl;
            Press();
            break;
        }
        cout << "Ban co muon lua chon tiep khong(y/n): ";
        cin >> chon;
        if (chon == 'n')
            cout << "Tam biet ban\n";
    } while (chon == 'y' || chon == 'Y');
    delete[] sv;
}


