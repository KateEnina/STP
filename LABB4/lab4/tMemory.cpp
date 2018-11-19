#pragma once
#include "stdafx.h"
#include "TMemory.h"
#include "../../Lab1/ProjectX/tFrac.h"
#include "../../lab2/lab2/tComplex.h"
#include "../../lab3/lab3/TPNumber.h"

template<>
TMemory<TFrac>::TMemory()
{
	FNumber = TFrac(0, 1);
	FState = false;
}

template<>
TMemory<TComplex>::TMemory()
{
	FNumber = TComplex(float (1.0), (float)1.0);
	FState = false;
}

template<>
TMemory<TPNumber>::TMemory()
{
	FNumber = TPNumber(1.0, 10, 3);
	FState = false;
}