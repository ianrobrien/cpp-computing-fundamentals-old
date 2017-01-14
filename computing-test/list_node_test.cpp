#include "stdafx.h"
#include "CppUnitTest.h"
#include "list_node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace computingtest
{		
	TEST_CLASS(ListNodeTest)
	{
	public:
		
		TEST_METHOD(InitallyEmpty)
		{
			ListNode<int> list_node(4);
			Assert::IsFalse(list_node.GetNext());
		}

	};
}