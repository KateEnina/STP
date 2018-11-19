#include "stdafx.h"
#include <string>

using namespace std;

template <typename T>
class TMemory
	{
	public:
		TMemory()
		{
			FNumber = T();
			FState = false;
		}

		~TMemory() {};

		T Write(T e)
		{
			FNumber =  e;
			FState = true;
			return e;
		}

		T Take()
		{
			T obj = FNumber;
			FState = true;
			return obj;
		}
		
		void Add( T e)
		{
			FNumber = FNumber.summ(e);
			FState = true;
		}

		void Clear()
		{
			FNumber = T();
			FState = false;
		}

		string GetFState()
		{
			switch (FState)
			{
			case true:
				return std::string("_On");
				break;

			case false:
				return std::string("_Off");
				break;
			}
		}

		T GetFNumber()
		{
			return FNumber;
		}
				
	private:
		bool FState;
		T FNumber;
};
