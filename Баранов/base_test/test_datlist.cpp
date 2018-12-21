#include "Monom.h"
#include "DatList.h"
#include <gtest.h>

TEST(DatList, can_create_list)
{
	ASSERT_NO_THROW(DatList<Monom> list);
}
TEST(DatList,is_not_empty)
{
	DatList<Monom> list;
	Monom elem(2,2);
	list.Push(elem);
	EXPECT_TRUE(!list.IsEmpty());
}
TEST(DatList, is_empty)
{
	DatList<Monom> list;
	EXPECT_TRUE(list.IsEmpty());
}

TEST(Datlist, can_get_last_elem)
{
	DatList<Monom> list;
	Monom elem(2, 2);
	list.Push(elem);
	ASSERT_NO_THROW(list.Get());
}
TEST(Datlist, can_pop_index)
{
	DatList<Monom> list;
	Monom elem(2, 2);
	list.Push(elem);
	ASSERT_NO_THROW(list.Pop(0));
}
TEST(Datlist, cant_pop_incorect_index)
{
	DatList<Monom> list;
	Monom elem(2, 2);
	list.Push(elem);
	ASSERT_ANY_THROW(list.Pop(1));
}
TEST(DatList, can_get_sise)
{
	DatList<Monom> list;
	Monom elem(2, 2);
	list.Push(elem);
	EXPECT_EQ(1,list.GetSize());
}


