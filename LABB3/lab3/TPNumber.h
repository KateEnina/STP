#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;
class TPNumber
{
	private:
		float a;
		int b;
		int c; 
		float Power(int num, int pow);
		int CharInt(char c);
		char IntChar(int num);

	public:
		TPNumber(float a, int b, int c);
		TPNumber(string a, int b, int c);
		TPNumber Copy();
		TPNumber Reverse();
		TPNumber Sqr();

		string GetPString();
		string GetBString();
		string GetCString();
		void SetBString(string bs);
		void SetCString(string newc);

		float GetFloatPNumber()
		{
			return a;
		}
		int GetIntB()
		{
			return b;
		}
		int GetIntC()
		{
			return c;
		}
		void SetIntB(int b) {
			if (b < 2 || b>16)
				throw 1;
			this->b = b;
		}
		void SetIntC(int c) {
			if (c < 0)
				throw 1;
			this->c = c;
		}
		
		TPNumber Summ(TPNumber member);
		TPNumber Substruct(TPNumber member);
		TPNumber Multiply(TPNumber member);
		TPNumber Divide(TPNumber member);
}; 
