#pragma once
#include "../../lab3/lab3/TPNumber.h"


enum TOprtn { None, Add, Sub, Mul, Dvd };
enum TFunc { Rev, Sqr };

template<class T>
class TProc 
{
	private:
		T lop_res;
		T rop;
		TOprtn operation;

	public:
		TProc()
		{
			lop_res = T();
			rop = T();
			operation = TOprtn::None;
		}

		~TProc() {};

		void ResetProc()
		{
			lop_res = T();
			rop = T();
			operation = None;
		}

		void ResetOperation()
		{
			operation = None;
		}

		void RunOperation()
		{
			switch (operation)
			{
				case TOprtn::None:
					break;

				case TOprtn::Add:
					lop_res = lop_res + rop;
					break;

				case TOprtn::Dvd:
					lop_res = lop_res / rop;
					break;

				case TOprtn::Mul:
					lop_res = lop_res * rop;
					break;

				case TOprtn::Sub:
					lop_res = lop_res - rop;
					break;

				default:
					break;
			}
		}

		void RunFunc(enum TFunc func)
		{
			switch (func) {
				case Rev:
					rop = rop.Obratnoe ();
					break;
				case Sqr:
					rop = rop.Square();
					break;
				default:
					break;
			}
		}

		T GetLop_Res() 
		{
			return lop_res;
		}

		void SetLop_Res(T e)
		{
			lop_res = e;
		}

		T GetRop() 
		{
			return rop;
		}

		void SetRop(T e)
		{
			rop = e;
		}

		TOprtn GetOprtn()
		{
			return operation;
		}

		void SetOprtn(TOprtn oprtn)
		{
			operation = oprtn;
		}
};
