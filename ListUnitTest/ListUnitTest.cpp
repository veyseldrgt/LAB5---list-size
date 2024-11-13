#include "CppUnitTest.h"
#include <functional>
#include "../List/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListUnitTest
{
	TEST_CLASS(ListUnitTest)
	{
	public:
		TEST_METHOD(ConstructedListIsEmpty)
		{
			List<int> list;
			Assert::AreEqual(list.size(), (size_t)0U);
		}
		TEST_METHOD(DeleteListSize0)
		{
			List<int> list;
		}
		TEST_METHOD(DeleteListSize1ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 2);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(DeleteListSize2ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 3);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(DeleteListSize5ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 6);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(SizeEmpty)
		{
			List<int> list;
			Assert::AreEqual(list.size(), (size_t)0U);
		}
		TEST_METHOD(SizeOneElement)
		{
			List<int> list;
			list.pushFront(1);
			Assert::AreEqual(list.size(), (size_t)1U);
		}
		TEST_METHOD(SizeTwoElements)
		{
			List<int> list;
			list.pushFront(1);
			list.pushFront(2);
			Assert::AreEqual(list.size(), (size_t)2U);
		}
		TEST_METHOD(SizeThreeElements)
		{
			List<int> list;
			list.pushFront(4);
			list.pushFront(3);
			list.pushFront(23);
			Assert::AreEqual(list.size(), (size_t)3U);
		}
		TEST_METHOD(SizeTenElements)
		{
			List<int> list;
			list.pushFront(14);
			list.pushFront(31);
			list.pushFront(7);
			list.pushFront(4);
			list.pushFront(11);
			list.pushFront(23);
			list.pushFront(17);
			list.pushFront(38);
			list.pushFront(3);
			list.pushFront(45);
			Assert::AreEqual(list.size(), (size_t)10U);
		}
	};
}
