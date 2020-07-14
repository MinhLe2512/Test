#pragma warning(disable:4996)
#include <iostream>
using namespace std;

struct Date {
	int day, month, year;
};
class veMayBay {
	char* tenchuyen;
	Date d;
	int giave;
public:
	veMayBay() {
		tenchuyen = new char[100];
		tenchuyen = 0;
		d.day = d.month = 1;
		d.year = 2000;
		giave = 0;
	}
	~veMayBay() {
		giave = 0;
		d.day = d.month = d.year = 0;
		delete[]tenchuyen;
		tenchuyen = NULL;
	}
	void Nhap() {
		tenchuyen = new char[11];
		cout << "Ten chuyen:";
		cin.getline(tenchuyen, 11);
		cin.getline(tenchuyen, 11);
		cout << "\nDate:";
		cin >> d.day >> d.month >> d.year;
		cout << "\nGia Ve:";
		cin >> giave;
	}
	void Xuat() {
		cout << tenchuyen << " " << d.day << " " << d.month << " " << d.year << " " << giave << endl;
	}
	int& getGiaVe() {
		return giave;
	}
};
class Nguoi {
protected:
	char* hoten;
	char* gioitinh;
	int tuoi;
public:
	Nguoi() {
		hoten = new char[21];
		gioitinh = new char[21];
		hoten = 0;
		gioitinh = NULL;
		tuoi = 0;
	}
	~Nguoi() {
		delete[]hoten;
		delete[]gioitinh;
		hoten = gioitinh = NULL;
		tuoi = 0;
	}
	void Nhap() {
		cout << "\nHo ten:";
		hoten = new char[21];
		cin.getline(hoten, 21);
		cin.getline(hoten, 21);
		cout << "\nGioi tinh:";
		gioitinh = new char[21];
		cin.getline(gioitinh, 21);
		cout << "\nTuoi:";
		cin >> tuoi;
	}
	void Xuat() {
		cout << hoten << " " << gioitinh << " " << tuoi << endl;
	}
	Nguoi& operator=(const Nguoi& a) {
		this->hoten = a.hoten;
		this->gioitinh = a.gioitinh;
		this->tuoi = a.tuoi;
	}
};
class HanhKhach :public Nguoi {
	veMayBay* ve;
	int num;
	int total;
public:
	HanhKhach() {
		/*hoten = 0;
		gioitinh = 0;
		tuoi = 0;*/
		num = 0;
		ve = new veMayBay[num + 1];
		total = 0;
	}
	~HanhKhach() {
		/*hoten = 0;
		gioitinh = 0;
		tuoi = 0;*/
		num = 0;
		delete[]ve;
		ve = NULL;
	}
	void Nhap() {
		Nguoi::Nhap();
		cout << "\nSo luong ve:";
		cin >> num;
		ve = new veMayBay[num + 1];
		for (int i = 0; i < num ; i++) {
			cout << "\nVe thu " << i + 1 << endl;
			ve[i].Nhap();
			total += ve[i].getGiaVe();
		}
	}
	void Xuat() {
		Nguoi::Xuat();
		for (int i = 0; i < num; i++) {
			ve[i].Xuat();
		}
		cout << "So luong ve:" << num << endl;
		cout << "Tong tien:" << this->total << endl;
	}

	bool operator <(const HanhKhach& a) {
		if (this->total < a.total) {
			return true;
		}
		else {
			return false;
		}
	}
	HanhKhach& operator=(const HanhKhach& a) {
		this->hoten = new char[21];
		strcpy(this->hoten, a.hoten);
		this->tuoi = a.tuoi;
		this->gioitinh = new char[21];
		strcpy(this->gioitinh, a.gioitinh);
		this->num = a.num;
		this->total = a.total;
		this->ve = new veMayBay[num + 1];
		for (int i = 0; i < num; i++) {
			this->ve[i] = a.ve[i];
		}
		return *this;
	}
	HanhKhach& doi(const HanhKhach& a) {
		*this = a;
		return *this;
	}
};

void sort(HanhKhach a[], int n) {
	HanhKhach tmp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] < a[j + 1]) {
				tmp.doi(a[j]);
				a[j].doi(a[j + 1]);
				a[j + 1].doi(tmp);
			}
		}
	}
}

int main() {
	int n, tong = 0;
	cout << "Number of customers:" << endl;
	cin >> n;
	HanhKhach* a = new HanhKhach[n + 1];
	for (int i = 0; i < n; i++) {
		cout << "Hanh khach " << i + 1 << endl;
		a[i].Nhap();
	}
	sort(a, n);
	for (int i = 0; i < n; i++) {
		a[i].Xuat();
	}
}