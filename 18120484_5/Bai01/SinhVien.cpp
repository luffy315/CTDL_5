#include <iostream>

using namespace std;

struct SinhVien {
	char hoTen[51];
	char MSSV[10];
	float diemLT;
	float diemTH;
	float diemTB;
};

struct NodeSV {
	SinhVien data;
	NodeSV* next;
};

void swapSV(SinhVien& sv1, SinhVien& sv2) {
	char temp[51];
	strcpy(temp, sv1.hoTen);
	strcpy(sv1.hoTen, sv2.hoTen);
	strcpy(sv2.hoTen, temp);
	strcpy(temp, sv1.MSSV);
	strcpy(sv1.MSSV, sv2.MSSV);
	strcpy(sv2.MSSV, temp);
	float temp2;
	temp2 = sv1.diemLT;
	sv1.diemLT = sv2.diemLT;
	sv2.diemLT = temp2;
	temp2 = sv1.diemTH;
	sv1.diemTH = sv2.diemTH;
	sv2.diemTH = temp2;
	temp2 = sv1.diemTB;
	sv1.diemTB = sv2.diemTB;
	sv2.diemTB = temp2;
}

void KhoiTaoDSSV(NodeSV*& head) {
	head = NULL;
}

void ThemSV(NodeSV*& head) {
	NodeSV* sv = new NodeSV;
	// nhập thông tin sinh viên cần thêm
	cout << "Ho ten: ";
	cin.getline(sv->data.hoTen, 51);
	cout << "MSSV: ";
	cin.getline(sv->data.MSSV, 10);
	/*cout << "Diem LT: ";
	cin >> sv->data.diemLT;
	cout << "Diem TH: ";
	cin >> sv->data.diemTH;
	cout << "Diem TB: ";
	cin >> sv->data.diemTB;*/
	sv->next = NULL;
	// thêm sinh viên vào dslk
	if (head == NULL) head = sv;
	else {
		sv->next = head;
		head = sv;
	}
}

void NhapDSSV(NodeSV*& head) {
	cout << "Nhap so luong sinh vien can them: ";
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		ThemSV(head);
	}
}

void SapXepTheoMSSV(NodeSV*& head) {
	NodeSV* p1;
	NodeSV* p2;
	for (p1 = head; p1->next != NULL; p1 = p1->next) {
		p2 = p1->next;
		while (p2) {
			if (strcmp(p1->data.MSSV, p2->data.MSSV) == 1)
				swapSV(p1->data, p2->data);
			p2 = p2->next;
		}
	}
}

void XuatDSSV(NodeSV* head) {
	NodeSV* p = head;
	while (p) {
		cout << "Ho ten SV: " << p->data.hoTen << endl;
		cout << "MSSV: " << p->data.MSSV << endl;
		p = p->next;
	}
	cout << "-----------------";
}

int main() {
	NodeSV* head;
	KhoiTaoDSSV(head);
	NhapDSSV(head);
	SapXepTheoMSSV(head);
	cout << "DSSV sau khi sap theo MSSV tang dan\n";
	XuatDSSV(head);
}