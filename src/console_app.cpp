#include <sequences/sequence.h>
#include <Windows.h>
#include <conio.h>
#include<stdlib.h>
#include<cstdio>
using namespace std;
using namespace sequence;
void color_text(int k) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

void print_menu_seq_list(int pos) {
	char s_menu[5][74]{ "1 �������� ���������� � ����� ������������������\n", "2 ������� ���������� �� ������ �� ���������� ������\n",
	 "3 ������� ������ �� �����\n", "4 ����� ���������� � ������������ ������ ��� �������� �������� ������\n", "5 �����\n" };
	for (int i = 1; i <= 5; i++)
	{
		if (i == pos) {
			color_text(80);
			cout << s_menu[i - 1];
			color_text(15);
			continue;
		}
		cout << s_menu[i - 1];
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SequenceList s;
	int pos_sl = 1;
	print_menu_seq_list(pos_sl);
	
	while (1)
	{
		int act = 224;
		while (act == 224 || act == 13)
		{
			if (getch() == 13)
				act = 13;
			else
				act = getch();
			switch (act) {
			case 72:
				pos_sl -= 1;
				if (pos_sl == 0)
					pos_sl = 5;
				break;
			case 80:
				pos_sl += 1;
				if (pos_sl == 6)
					pos_sl = 1;
				break;
			case 13:
				
			//			
				system("cls");
				print_menu_seq_list(pos_sl);
							int seq_num;

							switch (pos_sl) {
							case 5:
								return 0;
								break;
								case 1:
								{
									cout << "������� ��������� ���������: ������ ���� �����������/��� ��� ���������(�������������� - 1, �������������� - 2) ���������� ������\n";
									int t, n;
									double fm, a;
									cin >> fm >> a >> t >> n;
									if (t == 1) {
										SequencePtr pr = make_shared<ArifProgression>(a, fm, n);
										s.add_progression(pr);
									}
									else if (t == 2) {
										SequencePtr pr = make_shared<GeomProgression>(a, fm, n);
										s.add_progression(pr);
									}
									break;
								}
								case 2:
								{
									cout << "������� ����� ������������������, � ������� �� �� ������ ��������\n";
									cin >> seq_num;
									if (seq_num > s.get_index())
									{
										cout << "��������� ����� ������, ��� ����� ��������� ������������������ � ������\n";
										cout << "������� ��� �����������" << endl;
										getch();
										break;
									}
									if (s.get_index() == 0)
									{
										cout << "������ �������" << endl;
										cout << "������� ��� �����������" << endl;
										getch();
										break;
									}
									cout << "������� ����� ���������, ������� ����� �������\n";
									int num2;
									cin >> num2;
									
									if (num2 >= s.get_index()) {
										cout << "��������� ����� ������, ��� ����� ��������� ��������� � ������\n";									}
									else {
										s.remove(num2 - 1);
									}
								}
								break;
								case 3:
								{
									std::cout << s << endl;
									cout << "������� ��� �����������" << endl;
									getch();
								}
								break;
								case 4:
								{
									int num2;
									cout << "������� ����� ������, �� ������� ����� ������ ������������ �����\n";
									cin >> num2;
									SequencePtr prog = make_shared<ArifProgression>(1, 1, 1);
									prog = s.get_prog_with_max_sum(num2);
									cout << prog << endl;
									cout << "������� ��� �����������" << endl;
									getch();
								}
								break;
								
								}
								break;
							}

						
					
				
				
			system("cls");
			print_menu_seq_list(pos_sl);
		}

	}
}