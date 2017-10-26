// ThreadDemo.cpp : Win32 Multithreaded C program.
#include <stdio.h>
#include <windows.h>
DWORD sum; // shared by the threads
DWORD WINAPI runner(LPVOID param); // threads call this function
int main() {
	DWORD pid;
	HANDLE h;
	int param = 2; // change this value 

	h = CreateThread(
		NULL, // default security attributes are set
		0, // default stack size
		runner, // thread function 
		&param, // parameter to the thread function
		0, // default creation flags
		&pid); // return the thread id

	if (h != NULL) {
		WaitForSingleObject(h, INFINITE); // wait for the thread
		CloseHandle(h);
		printf("sum of 1..%d = %d\n", param, sum);
	}
	return 0;
}

DWORD WINAPI runner(LPVOID param) {
	DWORD i;
	DWORD upper = *(DWORD*)param;
	for (i = 1; i <= upper; i++)
		sum += i;
	return 0;
}