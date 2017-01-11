// computing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linked_list.h"

int main()
{
	auto ll = new LinkedList<std::string>();

	ll->Add("first");
	ll->Add("second");
	ll->Add("third");
	auto size = ll->Size();

	delete ll;	
	return 0;
}

