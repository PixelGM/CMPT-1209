#include <iostream>

using namespace std;

int main()
{
	int sum;

	_asm
	{
		mov eax, 100111b
		mov ebx, 27d
		add eax, ebx
		mov sum, eax

		nop
	}

	cout << sum << endl;
}