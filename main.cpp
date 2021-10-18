#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

class QuanLyDangNhap
{
public:
    QuanLyDangNhap()
    {

        quyenTruyCap = 0;
    }

    void dangNhap()
    {
        cout << "Nhap tai khoan va mat khau.\nTai Khoan:";
        cin >> taiKhoanTmp;
        int userID = checkFile(taiKhoanTmp,"users.txt");
        if(userID != 0)
        {
            cout << "Mat khau:";
            cin >> matKhauTmp;

            int passwordID = checkFile(matKhauTmp,"passwords.txt");
            if(userID == passwordID)
            {
                cout << "Chao mung ban den voi chuong trinh.";
                cin.get();
            }
            else
            {
                cout << "Sai mat khau." << endl;
                dangNhap();
            }
        }
        else
        {
            cout << "Ten dang nhap khong dung." << endl;
            dangNhap();
        }
    }
    bool checkFile(string attempt, const char* p_fileName)
    {
        string line;
        fstream file;
        long long maHoaKiTu;
        file.open(p_fileName, ios::in);
        while(1)
        {
            // getline(file, maHoaKiTu); không thể dùng như này
            //  ==> 
            file >> maHoaKiTu;
            if(maHoaKiTu == 0)
            {
                if(attempt == line){
                    file.close();
                    return true;
                }
                else{
                    line.erase(line.begin(),line.end());// tim hieu 2 ham
                }
            }
            else{

            line += (char)giaiMa(maHoaKiTu);
            }

            if(file.peek() == EOF)//EOF = end of file // peek la ham co san trong c++, tim them tai lieu doc => ghi vao bao cao
            {
                file.close();
                return false;
            }
        }

    }
    void saveFile(string p_line,const char* p_fileName ) // giam bo nho
    {
        fstream file;
        file.open(p_fileName, ios::app);
        for(int i=0; i<p_line.length(); i++)
        {
            file << maHoa(p_line[i]);
            file << "\n";

        }
        file<<"0\n"; // de ngan cach cac mat khau/tk
        file.close();
    }
    long long maHoa (int p_letter) //Dung long long de co the luu dc nhin gia tri hon
    {
        return powf(p_letter,4);

    }
    int giaiMa(long long p_letter) // vi` giai ma nen chi can int la` du
    {
        return powf(p_letter,1/4.f); // .f de trinh bien dich biet chung ta can tra ve du lieu dang float

    }
private:

    string taiKhoanTmp;
    string matKhauTmp;
    bool quyenTruyCap;
};

int main()
{
    QuanLyDangNhap app;
    app.dangNhap();
}
