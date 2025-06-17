#include <iostream>
#include <string>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
#include <cstdlib>

void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

short readnumofquestion(string massage) {
	int n;
	cout << massage << endl;
	cin >> n;
	return n;
}
short readopquestion(string massage) {
	int n;
	do
	{
		cout << massage << endl;
		cin >> n;
	} while (n > 5 || n < 1);
	return n;
}
short readlevelquestion(string massage) {
	int n;
	do
	{
		cout << massage << endl;
		cin >> n;
	} while (n > 4 || n < 1);
	return n;
}
struct answe {
	int correctanswer;
	int wronganswer;
};
struct ques {
	int n1;
	int n2;
	char operation;
};
int random(int from, int to) {
	int ran = rand() % (int)(to - from + 1) + from;
	return ran;
}
void shapeofquestion(int n, int i) {
	cout << "Question [" << i << "/" << n << "]:\n\n";
}
ques questions(short level, short op) {
	ques x;
	if (level == 4) {
		level = (short)random(1, 3);
	}
	switch (level)
	{
	case 1:
		x.n1 = random(1, 10);
		x.n2 = random(1, 10);
		break;
	case 2:
		x.n1 = random(10, 50);
		x.n2 = random(10, 50);
		break;
	case 3:
		x.n1 = random(50, 100);
		x.n2 = random(50, 100);
		break;
	}
	switch (op)
	{
	case 1:
		x.operation = '+';
		break;
	case 2:
		x.operation = '-';
		break;
	case 3:
		x.operation = '*';
		break;
	case 4:
		x.operation = '/';
		break;

	}
	if (op == 5) {
		char operations[] = { '+', '-', '*', '/' };
		x.operation = operations[(int)random(0, 3)];
	}
	return { x.n1,x.n2,x.operation };
}
bool check(int answer, ques& x) {
	int correctansw;
	switch (x.operation)
	{
	case '+':
		correctansw = x.n1 + x.n2;
		break;
	case '-':
		correctansw = x.n1 - x.n2;
		break;
	case '*':
		correctansw = x.n1 * x.n2;
		break;
	case '/':
		correctansw = x.n1 / x.n2;
		break;
	}

	return correctansw == answer;
}
void shape(ques x) {
	cout << x.n1 << endl;
	cout << x.operation << endl;
	cout << x.n2 << endl;
}
void systemcolor(int answer, ques& x, answe& y) {

	if (check(answer, x)) {
		system("color 2F");
		y.correctanswer++;

	}
	else
	{
		system("color 4F");
		y.wronganswer++;
	}

}
void theendcolor(answe y) {
	if (y.correctanswer > y.wronganswer) {
		system("color 2F");
	}
	else if (y.correctanswer < y.wronganswer) {

		system("color 4F");
	}
	else {
		system("color 6F");
	}
}
answe playgame(int n, int op, int level) {
	int correctanswer = 0;
	ques x;
	answe y = { 0 ,0 };
	int answer;
	for (int i = 1; i <= n; i++) {
		shapeofquestion(n, i);
		x = questions(level, op);
		shape(x);
		cout << "-----------------------\n";
		cin >> answer;
		check(answer, x);
		systemcolor(answer, x, y);
	}
	return y;
}
void finalgameresult(answe y, short n, short level, short op) {
	cout << " ----------------------" << endl;
	cout << " Game result:\n";
	cout << " ----------------------" << endl;
	cout << "no of questions: " << n << "\n";
	switch (level)
	{
	case 1:
		cout << "question level:Easy\n";
		break;
	case 2:
		cout << "question level: medium" << "\n";
		break;
	case 3:
		cout << "question level: Hard\n";
		break;
	case 4:
		cout << "question level: mix\n";
		break;
	}
	switch (op)
	{
	case 1:
		cout << "the operation type is:'+'\n";
		break;
	case 2:
		cout << "the operation type is:'-'\n";
		break;
	case 3:
		cout << "the operation type is:'*'\n";
		break;
	case 4:
		cout << "the operation type is:'/'\n";
		break;
	default:
		cout << "the operation type is:'mix'\n";
	}

	cout << "player correct answer:" << y.correctanswer << "\n";
	cout << "player wrong answer:" << y.wronganswer << endl;
	cout << "-------------------------------------------\n";
}
void startgame() {
	char cont = 'Y';

	do {
		clearScreen();
		system("color 0F");
		int n = readnumofquestion("enter the number of question you want");
		short op = readopquestion("enter operation type [1]Add,[2]Sub,[3]Mult,[4]Div,[5]Mix");
		short level = readlevelquestion("enter question level [1]Easy,[2]Medium,[3]Hard,[4]Mix");
		answe y = playgame(n, op, level);
		theendcolor(y);
		finalgameresult(y, n, level, op);
		cout << "\t\tare you want to play again:Y/N\n ";
		cin >> cont;
	} while (cont == 'Y' || cont == 'y');
}
int main() {
	srand((unsigned)time(NULL));
	startgame();
	return 0;
}


