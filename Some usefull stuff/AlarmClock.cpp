#include <Windows.h>
#include <iostream>
#include <string>
#define sound Beep(400,1000); Sleep(1000); Beep(400,1000); Sleep(1000); Beep(400,1000); Sleep(1000)
#define time_now_set std::to_string(t.wHour) + ":" + std::to_string(t.wMinute) + ":" + std::to_string(t.wSecond);

void Alarm_clock()
{
	SYSTEMTIME t;
	std::string timer;
	std::string time_now;

	std::cout << "\nRules:\n0:0:0\n---\n1:1:1\n---\n12:12:12\n---\n1:20:0\n---\nIf you wrote a wrong number, reboot up a program\n";
	std::cout << "\nEnter Alarm clock time trigger: ";
	std::cin >> timer;
	while (timer != time_now)
	{
		GetLocalTime(&t);
		time_now = time_now_set;
		Sleep(1000);
	}
	std::cout << "\nCheck Time!\n";
	sound;
}


int main()
{
	Alarm_clock();
	return 0;
}