#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"


int main()
{	
	ICalc* calc1 = load_proxy();
	calc1->AddRef();		

	ICalc* calc2 = calc1;
	calc2->AddRef();		


	calc2->Release();		
	calc1->Release();		
}





