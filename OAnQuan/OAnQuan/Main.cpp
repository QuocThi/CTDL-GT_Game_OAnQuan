# include <iostream>
# include <string>
using namespace std;

struct Node
{
	int Data;
	Node *pNext;
	Node *pPrev;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

void KhoiTao(List &l)
{
	l.pHead = l.pTail = NULL;
}

Node *TaoNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->Data = x;
		p->pNext = NULL;
		p->pPrev = NULL;
	}
	return p;
}

void AddTail(List &l, Node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
	l.pTail->pNext = l.pHead;
	l.pHead->pPrev = l.pTail;
}

void Nhap(List &l)
{
	for (int i = 1; i <= 12; i++)
	{
		if (i == 6 || i == 12)
		{
			Node *q = TaoNode(10);
			AddTail(l, q);
		}
		else
		{
			Node *p = TaoNode(5);
			AddTail(l, p);
		}
	}
}

void XuatDanSo(List &l, int &DiemSo1, int &DiemSo2)
{
	int m = 1;
	Node *p = l.pHead;
	do
	{
		if (m == 1 || m == 7)
		{
			cout << "[ ";
			cout << p->Data << " , ";
		}

		if (m == 5 || m == 11)
		{
			cout << p->Data << " ] ";
		}

		if (m == 6 || m == 12)
		{
			cout << "<";
			cout << p->Data;
			cout << "> ";
		}
		if ((m > 1 && m<5) || (m>7 && m<11))
		{
			cout << p->Data << " , ";
		}
		m++;
		p = p->pNext;
	} while (p != l.pHead);

	cout << "( " << DiemSo1 << " || " << DiemSo2 << " )" << endl;

}

bool TestPhu1(List &l)
{
	Node *p = l.pHead;
	int x = 0;
	for (int i = 0; i < 5; i++)
	{
		x = x + p->Data;
		p = p->pNext;
	}
	if (x == 0)
	{
		return true;
	}
	return false;
}

bool TestPhu2(List &l)
{
	Node *p = l.pTail->pPrev;
	int y = 0;
	for (int i = 0; i < 5; i++)
	{
		y = y + p->Data;
		p = p->pPrev;
	}
	if (y == 0)
	{
		return true;
	}
	return false;
}

void KiemTraToiLuot(List &l, int &DiemNguoi1, int &DiemNguoi2)
{
	if (TestPhu1(l) == true && DiemNguoi1 >= 5)
	{
		Node *k = l.pHead;
		for (int i = 0; i < 5; i++)
		{
			k->Data += 1;
			k = k->pNext;
		}
		DiemNguoi1 -= 5;
	}

	if (TestPhu2(l) == true && DiemNguoi2 >= 5)
	{
		Node *h = l.pTail->pPrev;
		for (int i = 0; i < 5; i++)
		{
			h->Data += 1;
			h = h->pPrev;
		}
		DiemNguoi2 -= 5;
	}
}

bool TrangThaiKetThuc(List &l, int &DiemNguoi1, int &DiemNguoi2)
{
	Node*Quan1 = l.pHead->pNext->pNext->pNext->pNext->pNext;
	Node*Quan2 = Quan1->pNext->pNext->pNext->pNext->pNext->pNext;
	if (Quan1->Data == 0 && Quan2->Data == 0)
	{
		return true;
	}

	if (DiemNguoi1 < 5 && TestPhu1(l) == true)
	{
		return true;
	}

	if (DiemNguoi2 < 5 && TestPhu2(l) == true)
	{
		return true;
	}
	return false;
}

void BenTrai(List &l, Node *OBatDau, int & DiemNguoi1, int & DiemNguoi2, int XacDinhNguoiChoi)
{
	Node*Quan1 = l.pHead->pNext->pNext->pNext->pNext->pNext;
	Node*Quan2 = Quan1->pNext->pNext->pNext->pNext->pNext->pNext;
	bool Test = false;

	while (Test == false)
	{
		Node *LuuOBatDau = OBatDau;
		int SoDanOBatDau = OBatDau->Data;

		for (int i = 0; i < SoDanOBatDau; i++)
		{
			OBatDau->pNext->Data += 1;
			LuuOBatDau->Data -= 1;
			OBatDau = OBatDau->pNext;
		}

		if (OBatDau->pNext->Data == 0)
		{
			if (OBatDau->pNext->pNext->Data != 0)
			{
				bool An = true;
				while (An == true)
				{
					Node*ViTriKeTiep = OBatDau->pNext;


					if (XacDinhNguoiChoi == true)
					{
						DiemNguoi1 = DiemNguoi1 + ViTriKeTiep->pNext->Data;
					}
					if (XacDinhNguoiChoi == false)
					{
						DiemNguoi2 = DiemNguoi2 + ViTriKeTiep->pNext->Data;
					}


					ViTriKeTiep->pNext->Data = 0;
					OBatDau = ViTriKeTiep->pNext;

					if (OBatDau->pNext->Data != 0)
					{
						An = false;
					}
					if (OBatDau->pNext->pNext->Data == 0)
					{
						An = false;
					}
				}
			}
			Test = true;
			break;
		}

		if (OBatDau->pNext == Quan1 || OBatDau->pNext == Quan2)
		{
			Test = true;
			break;
		}


		OBatDau = OBatDau->pNext;
		if (OBatDau->Data != 0)
		{
			int SoDanOBatDau2 = OBatDau->Data;
			Node *LuuOBatDau2 = OBatDau;
			for (int j = 0; j < SoDanOBatDau2; j++)
			{
				OBatDau->pNext->Data += 1;
				LuuOBatDau2->Data -= 1;
				OBatDau = OBatDau->pNext;
			}

		}


		if (OBatDau->pNext == Quan1 || OBatDau->pNext == Quan2)
		{
			Test = true;
			break;
		}


		if (OBatDau->pNext->Data == 0)
		{
			if (OBatDau->pNext->pNext->Data != 0)
			{
				bool An2 = true;
				while (An2 == true)
				{
					Node *ViTriKeTiep2 = OBatDau->pNext;
					if (XacDinhNguoiChoi == true)
					{
						DiemNguoi1 = DiemNguoi1 + ViTriKeTiep2->pNext->Data;
					}
					if (XacDinhNguoiChoi == false)
					{
						DiemNguoi2 = DiemNguoi2 + ViTriKeTiep2->pNext->Data;
					}
					ViTriKeTiep2->pNext->Data = 0;
					OBatDau = ViTriKeTiep2->pNext;

					if (OBatDau->pNext->Data != 0)
					{
						An2 = false;
					}
					if (OBatDau->pNext->pNext->Data == 0)
					{
						An2 = false;
					}

				}
			}
			Test = true;
			break;
		}

		if (OBatDau->pNext == Quan1 || OBatDau->pNext == Quan2)
		{
			Test = true;
			break;
		}

		OBatDau = OBatDau->pNext;
	}
}

void BenPhai(List &l, Node *OBatDau, int & DiemNguoi1, int & DiemNguoi2, int XacDinhNguoiChoi)
{
	Node*Quan1 = l.pHead->pNext->pNext->pNext->pNext->pNext;
	Node*Quan2 = Quan1->pNext->pNext->pNext->pNext->pNext->pNext;
	bool Test = false;


	while (Test == false)
	{

		Node *LuuOBatDau = OBatDau;
		int SoDanOBatDau = OBatDau->Data;

		for (int i = 0; i < SoDanOBatDau; i++)
		{
			OBatDau->pPrev->Data += 1;
			LuuOBatDau->Data -= 1;
			OBatDau = OBatDau->pPrev;
		}

		Node*ViTriKeTiep = new Node;

		if (OBatDau->pPrev->Data == 0)
		{
			if (OBatDau->pPrev->pPrev->Data != 0)
			{
				bool An = true;
				while (An == true)
				{
					ViTriKeTiep = OBatDau->pPrev;
					if (XacDinhNguoiChoi == true)
					{
						DiemNguoi1 = DiemNguoi1 + ViTriKeTiep->pPrev->Data;
					}
					if (XacDinhNguoiChoi == false)
					{
						DiemNguoi2 = DiemNguoi2 + ViTriKeTiep->pPrev->Data;
					}
					ViTriKeTiep->pPrev->Data = 0;
					OBatDau = ViTriKeTiep->pPrev;

					if (OBatDau->pPrev->Data != 0)
					{
						An = false;
					}
					if (OBatDau->pPrev->pPrev->Data == 0)
					{
						An = false;
					}

				}
			}
			Test = true;
			break;
		}

		if (OBatDau->pPrev == Quan1 || OBatDau->pPrev == Quan2)
		{
			Test = true;
			break;
		}

		OBatDau = OBatDau->pPrev;
		if (OBatDau->Data != 0)
		{
			int SoDanOBatDau2 = OBatDau->Data;
			Node *LuuOBatDau2 = OBatDau;
			for (int j = 0; j < SoDanOBatDau2; j++)
			{
				OBatDau->pPrev->Data += 1;
				LuuOBatDau2->Data -= 1;
				OBatDau = OBatDau->pPrev;
			}

		}

		//Node*ViTriKeTiep2 = new Node;

		if (OBatDau->pPrev->Data == 0)
		{
			if (OBatDau->pPrev->pPrev->Data != 0)
			{
				bool An2 = true;
				while (An2 == true)
				{
					Node *ViTriKeTiep2 = OBatDau->pPrev;
					if (XacDinhNguoiChoi == true)
					{
						DiemNguoi1 = DiemNguoi1 + ViTriKeTiep2->pPrev->Data;
					}
					if (XacDinhNguoiChoi == false)
					{
						DiemNguoi2 = DiemNguoi2 + ViTriKeTiep2->pPrev->Data;
					}
					ViTriKeTiep2->pPrev->Data = 0;
					OBatDau = ViTriKeTiep2->pPrev;

					if (OBatDau->pPrev->Data != 0)
					{
						An2 = false;
					}
					if (OBatDau->pPrev->pPrev->Data == 0)
					{
						An2 = false;
					}

				}
			}
			Test = true;
			break;
		}

		if (OBatDau->pPrev == Quan1 || OBatDau->pPrev == Quan2)
		{
			Test = true;
			break;
		}
		OBatDau = OBatDau->pPrev;
	}
}

void NguoiChoi1(List &l, int & DiemNguoi1, int &DiemNguoi2)
{
	cout << "Den luot Nguoi Choi 1. " << endl;
	bool XacDinhNguoiChoi1 = true;
	int n;
	char Huong1;
	Node *OBatDau = l.pHead;
	do
	{
		cout << "Nhap vi tri bat dau. Nhap huong di: " << endl;
		cin >> n;
		do
		{
			cin >> Huong1;
			if (Huong1 != 80 && Huong1 != 84)
			{
				cout << "Huong di khong hop le. Moi nhap lai: ";
			}
		} while (Huong1 != 80 && Huong1 != 84);

		for (int i = 0; i < (n - 1); i++)
		{
			OBatDau = OBatDau->pNext;
		}
		if (n >= 6 || OBatDau->Data == 0)
		{
			cout << "Vi tri khong hop le. ";
		}
	} while (n >= 6 || OBatDau->Data == 0);

	if (Huong1 == 84)
	{
		BenPhai(l, OBatDau, DiemNguoi1, DiemNguoi2, XacDinhNguoiChoi1);
		XuatDanSo(l, DiemNguoi1, DiemNguoi2);

	}

	if (Huong1 == 80)
	{
		BenTrai(l, OBatDau, DiemNguoi1, DiemNguoi2, XacDinhNguoiChoi1);
		XuatDanSo(l, DiemNguoi1, DiemNguoi2);
	}
}


void NguoiChoi2(List &l, int & DiemNguoi1, int &DiemNguoi2)
{
	cout << "Den luot Nguoi Choi 2. " << endl;
	bool XacDinhNguoiChoi2 = false;
	int z;
	char Huong2;
	Node *ViTriBatDau = l.pTail;
	do
	{
		cout << "Nhap vi tri bat dau. Nhap huong di: " << endl;
		cin >> z;
		do
		{
			cin >> Huong2;
			if (Huong2 != 80 && Huong2 != 84)
			{
				cout << "Huong di khong hop le. Moi nhap lai: ";
			}
		} while (Huong2 != 80 && Huong2 != 84);

		for (int u = 0; u < (z - 5); u++)
		{
			ViTriBatDau = ViTriBatDau->pPrev;
		}
		if (z < 6 || ViTriBatDau->Data == 0)
		{
			cout << "Vi tri khong hop le. ";
		}
	} while (z < 6 || ViTriBatDau->Data == 0);

	if (Huong2 == 80)
	{
		BenPhai(l, ViTriBatDau, DiemNguoi1, DiemNguoi2, XacDinhNguoiChoi2);
		XuatDanSo(l, DiemNguoi1, DiemNguoi2);

	}

	if (Huong2 == 84)
	{
		BenTrai(l, ViTriBatDau, DiemNguoi1, DiemNguoi2, XacDinhNguoiChoi2);
		XuatDanSo(l, DiemNguoi1, DiemNguoi2);
	}
}


int NuocDi(List &l, int &DiemNguoi1, int &DiemNguoi2)
{
	cout << "Nguoi choi 1 la nguoi bat dau truoc." << endl;
	cout << "Huong di: P la ben Phai. T la ben Trai." << endl;

	while (TrangThaiKetThuc(l, DiemNguoi1, DiemNguoi2) == false)
	{
		if (TestPhu1(l) == true)
		{
			KiemTraToiLuot(l, DiemNguoi1, DiemNguoi2);
		}
		NguoiChoi1(l, DiemNguoi1, DiemNguoi2);
		if (TrangThaiKetThuc(l, DiemNguoi1, DiemNguoi2) == true)
		{
			return 1;
		}
		if (TestPhu2(l) == true)
		{
			KiemTraToiLuot(l, DiemNguoi1, DiemNguoi2);
		}
		NguoiChoi2(l, DiemNguoi1, DiemNguoi2);
	}
	return 0;
}

void DiemSoChungCuoc(List &l, int &DiemNguoi1, int &DiemNguoi2)
{
	Node *p = l.pHead;
	for (int i = 0; i <= 4; i++)
	{
		DiemNguoi1 = DiemNguoi1 + p->Data;
		p = p->pNext;
	}
	p = p->pNext;

	for (int j = 0; j <= 5; j++)
	{
		DiemNguoi2 = DiemNguoi2 + p->Data;
		p = p->pNext;
	}

}

int main()
{
	List l;
	KhoiTao(l);
	int DiemNguoi1 = 0, DiemNguoi2 = 0;

	Nhap(l);
	NuocDi(l, DiemNguoi1, DiemNguoi2);

	DiemSoChungCuoc(l, DiemNguoi1, DiemNguoi2);

	if (DiemNguoi1 > DiemNguoi2)
	{
		cout << "1 WIN. " << endl;
	}
	else if (DiemNguoi1 < DiemNguoi2)
	{
		cout << "2 WIN. " << endl;
	}
	else
	{
		cout << "0 WIN. " << endl;
	}
	system("pause");
	return 0;
}