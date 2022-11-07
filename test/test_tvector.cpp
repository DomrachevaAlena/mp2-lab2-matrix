#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);
  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<double> v(10);
	v[5] = 2.5;
	TDynamicVector<double> vCopy(v);
	EXPECT_EQ(v, vCopy);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<double> v(10);
	TDynamicVector<double> vCopy(v);
	v[7] = 5.3;
	EXPECT_NE(v, vCopy);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);
  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(-8));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(5);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> v1(5);
	ASSERT_NO_THROW(v = v1);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> v1(9);
	v = v1;
	EXPECT_EQ(v.size(), 9);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> v1(9);
	ASSERT_NO_THROW(v = v1);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v(10);
	v[1] = 8;
	v[6] = 4;
	TDynamicVector<int> v1(10);
	v1[1] = 8;
	v1[6] = 4;
	bool res = (v == v1);
	EXPECT_EQ(res, true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(10);
	v[1] = 8;
	v[6] = 4;
	bool res = (v == v);
	EXPECT_EQ(res, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v(10);
	v[1] = 8;
	v[6] = 4;
	TDynamicVector<int> v1(8);
	v1[1] = 8;
	v1[6] = 4;
	bool res = (v != v1);
	EXPECT_EQ(res, true);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(3);
	v = v + 2;
	int arr[] = {2,2,2};
	TDynamicVector<int> expV(arr, 3);
	EXPECT_EQ(v, expV);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(3);
	v = v - 2;
	int arr[] = {-2,-2,-2};
	TDynamicVector<int> expV(arr, 3);
	EXPECT_EQ(v, expV);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	int arr[] = { 1,1,1 };
	TDynamicVector<int> v(arr, 3);
	v = v * 9 ;
	int arr1[] = { 9,9,9 };
	TDynamicVector<int> expV(arr1, 3);
	EXPECT_EQ(v, expV);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	int arr[] = { 1,1,1 };
	TDynamicVector<int> v(arr, 3);
	int arr1[] = { 9,9,9 };
	TDynamicVector<int> v1(arr1, 3);
	int arr2[] = { 10,10,10 };
	TDynamicVector<int> expV(arr2, 3);
	EXPECT_EQ(v+v1,expV);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(8);
	TDynamicVector<int> v1(6);
	ASSERT_ANY_THROW(v + v1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	int arr[] = { 1,1,1 };
	TDynamicVector<int> v(arr, 3);
	int arr1[] = { 9,9,9 };
	TDynamicVector<int> v1(arr1, 3);
	int arr2[] = { -8,-8,-8 };
	TDynamicVector<int> expV(arr2, 3);
	EXPECT_EQ(v - v1, expV);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(8);
	TDynamicVector<int> v1(6);
	ASSERT_ANY_THROW(v - v1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	int arr[] = { 2,2,2 };
	TDynamicVector<int> v(arr, 3);
	int arr1[] = { 4,4,4 };
	TDynamicVector<int> v1(arr1, 3);
	EXPECT_EQ(v * v1, 24);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(8);
	TDynamicVector<int> v1(6);
	ASSERT_ANY_THROW(v * v1);
}


