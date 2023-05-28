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
	char s_menu[5][74]{ "1 вставить прогрессию в конец последовательности\n", "2 удалить прогрессию из списка по указанному номеру\n",
	 "3 вывести список на экран\n", "4 поиск прогрессии с максимальной суммой при заданном значении членов\n", "5 выход\n" };
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
									cout << "Введите параметры прогресии: первый член знаменатель/шаг тип прогресии(арифметическая - 1, геометрическая - 2) количество членов\n";
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
									cout << "Введите номер последовательности, с которой вы вы хотите работать\n";
									cin >> seq_num;
									if (seq_num > s.get_index())
									{
										cout << "Введенный номер больше, чем номер последней последовательности в списке\n";
										cout << "Нажмите для продолжения" << endl;
										getch();
										break;
									}
									if (s.get_index() == 0)
									{
										cout << "Нечего удалять" << endl;
										cout << "Нажмите для продолжения" << endl;
										getch();
										break;
									}
									cout << "Введите номер прогресии, которую нужно удалить\n";
									int num2;
									cin >> num2;
									
									if (num2 >= s.get_index()) {
										cout << "Введенный номер больше, чем номер последней прогресии в списке\n";									}
									else {
										s.remove(num2 - 1);
									}
								}
								break;
								case 3:
								{
									std::cout << s << endl;
									cout << "Нажмите для продолжения" << endl;
									getch();
								}
								break;
								case 4:
								{
									int num2;
									cout << "Введите число членов, по которым нужно искать максимальную сумму\n";
									cin >> num2;
									SequencePtr prog = make_shared<ArifProgression>(1, 1, 1);
									prog = s.get_prog_with_max_sum(num2);
									cout << prog << endl;
									cout << "Нажмите для продолжения" << endl;
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