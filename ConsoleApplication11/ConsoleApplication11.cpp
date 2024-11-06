#include <iostream>
using namespace std;

class Time {
private:
	int hours = 12;
	int minutes = 0;
	int seconds = 0;
public:
	void settime(int hours1, int minutes1, int seconds1) {
		if (hours1 >= 0 && hours1 < 24)hours = hours1;
		else hours = 0;
		if (minutes1 >= 0 && minutes1 < 60)minutes = minutes1;
		else minutes = 0;
		if (seconds1 >= 0 && seconds1 < 60)seconds = seconds1;
		else seconds = 0;
	}
	void settime(int seconds1) {
		hours = seconds1 / 3600;
		seconds1 = seconds1 - hours * 3600;
		minutes = seconds1 / 60;
		seconds1 = seconds1 - minutes * 60;
		seconds = seconds1;
	}
	void print() {
		cout << hours << ":";
		if (minutes < 10)cout << "0" << minutes << ":";
		else cout << minutes << ":";
		if (seconds < 10)cout << "0" << seconds << endl;
		else cout << seconds << endl;
	}
	int getfullseconds()
	{
		int seconds1 = hours * 3600 + minutes * 60 + seconds;
		return seconds1;
	}
	int operator[](unsigned number) {
		switch (number)
		{
		case 1: return hours;
		case 2: return minutes;
		case 3: return seconds;
		default: return -1;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Time vremya;

	cout << "Стандартное время: ";
	vremya.print();

	int hours;
	int minutes;
	int seconds;
	cout << "Введите часы: ";
	cin >> hours;
	cout << "Введите минуты: ";
	cin >> minutes;
	cout << "Введите секунды: ";
	cin >> seconds;
	vremya.settime(hours, minutes, seconds);
	cout << "Заданное время: ";
	vremya.print();

	int timeinseconds;
	cout << "Введите время в секундах: ";
	cin >> timeinseconds;
	vremya.settime(timeinseconds);
	cout << "Заданное время: ";
	vremya.print();

	cout << "Перевод времени в секунды: " << vremya.getfullseconds() << endl;

	cout << vremya[1] << endl;

	Time time[5];
	time[0].settime(11368);
	time[1].settime(134);
	time[2].settime(11234);
	time[3].settime(19871);
	time[4].settime(11702);
	cout << "Время в массиве: " << endl;
	time[0].print();
	time[1].print();
	time[2].print();
	time[3].print();
	time[4].print();

	int a;
	int b;
	cout << "Введите диапазон часов(от первого числа до второго): ";
	cin >> a;
	cout << "Введите диапазон часов(от первого числа до второго): ";
	cin >> b;
	cout << "Время в этом диапазоне часов:" << endl;
	for (int i = 0; i < 5; i++)
	{
		if ((time[i][1] > a && time[i][1] < b) || (time[i][1] >= a && time[i][1] < b) && time[i][2] >= 1)time[i].print();
	}
}