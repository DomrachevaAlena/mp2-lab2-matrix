#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<double> m(10);
	m[5][2] = 2.5;
	TDynamicMatrix<double> mCopy(m);
	EXPECT_EQ(m, mCopy);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<double> m(10);
	TDynamicMatrix<double> mCopy(m);
	m[7][4] = 5.3;
	EXPECT_NE(m, mCopy);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(6);
	EXPECT_EQ(6, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(6);
	m[0][1] = 4;
	EXPECT_EQ(4, m[0][1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(3);
	ASSERT_ANY_THROW(m.at(-1,-8));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(3);
	ASSERT_ANY_THROW(m.at(MAX_MATRIX_SIZE + 1, MAX_MATRIX_SIZE + 2));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(3);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(3);
	ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);
	m = m1;
	EXPECT_EQ(m.size(), 5);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);
	ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(5);
	m[1][4] = 8;
	m[2][3] = 4;
	TDynamicMatrix<int> m1(5);
	m1[1][4] = 8;
	m1[2][3] = 4;
	bool res = (m == m1);
	EXPECT_EQ(res, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);
	m[1][4] = 8;
	m[2][3] = 4;
	bool res = (m == m);
	EXPECT_EQ(res, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(6);
	m[1][4] = 8;
	m[2][3] = 4;
	TDynamicMatrix<int> m1(5);
	m1[1][4] = 8;
	m1[2][3] = 4;
	bool res = (m == m1);
	EXPECT_EQ(res, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3);
	m[1][1] = 1;
	TDynamicMatrix<int> m1(3);
	m1[2][2] = 5;
	TDynamicMatrix<int> expM(3);
	expM[1][1] = 1;
	expM[2][2] = 5;
	EXPECT_EQ(m + m1, expM);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3);
	m[1][1] = 1;
	m[1][2] = 0;
	TDynamicMatrix<int> m1(3);
	m1[1][1] = 0;
	m1[1][2] = 4;
	TDynamicMatrix<int> expM(3);
	expM[1][1] = 1;
	expM[1][2] = -4;
	EXPECT_EQ(m - m1, expM);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);
	ASSERT_ANY_THROW(m - m1);
}

