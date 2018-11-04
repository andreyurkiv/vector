//
// Created by dinamic on 11/4/18.
//

#include <iostream>

#include "gtest/gtest.h"
#include "my_vector.h"

TEST(Constructor, DefaultConstructor){
    my_vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
}

TEST(Constructor, Constructor_Fill){
    my_vector<int> vec(4, 1);
    my_vector<int> vec1 {1,1,1,1};
    EXPECT_TRUE(vec == vec1);
}

TEST(Constructor, IteratorConstructor){
    my_vector<int> vec {1,2,3,4};
    my_vector<int> vec1(vec.begin(), vec.end());
    EXPECT_TRUE(vec == vec1);
}

TEST(Constructor, InitializerListConstructor){
    my_vector<int> vec;
    my_vector<int> vec1 {};
    EXPECT_TRUE(vec == vec1);
}

TEST(Constructor, CopyConstructor){
    my_vector<int> vec {3,2,1};
    my_vector<int> vec1(vec);
    EXPECT_TRUE(vec == vec1);
}

TEST(Assignment, RegularAssignment){
    my_vector<int> vec {1,2,3};
    my_vector<int> vec1 = vec;
    EXPECT_TRUE(vec == vec1);
}

TEST(Indexing, RegularBrackets){
    my_vector<int> vec {1,2,3,4,5};
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[4], 5);
}

TEST(Indexing, RegularBracketsException){
    my_vector<int> vec {1,2,3,4,5};
    EXPECT_NO_THROW(vec[10]);
}

TEST(Indexing, AtIndexing){
    my_vector<int> vec {1,2,3,4};
    EXPECT_EQ(vec.at(0),1);
    EXPECT_EQ(vec.at(3),4);
}

TEST(Indexing, AtException){
    my_vector<int> vec {1,2,3,4,5};
    EXPECT_THROW(vec.at(10), std::out_of_range);
}

TEST(Indexing, Front){
    my_vector<int> vec {1,2,3,4};
    EXPECT_EQ(vec.front(), 1);
}

TEST(Indexing, Back){
    my_vector<int> vec {1,2,3,4};
    EXPECT_EQ(vec.back(), 4);
}

TEST(Iterators, General){
    my_vector<int> vec {1,2,3,4};
    EXPECT_EQ(*vec.begin(), *(vec.rend()-1));
    EXPECT_EQ(*(vec.end()-1), *vec.rbegin());
}

//TEST(Iterators, Constant){
//    my_vector<int> vec {1,2,3,4};
//    EXPECT_EQ(vec.cbegin(), *(vec.rcend()-1));
//    EXPECT_EQ(*(vec.cend()-1), *vec.rcbegin());
//}

TEST(Sizing, IsEmpty){
    my_vector<int> v;
    EXPECT_TRUE(v.is_empty());
}

TEST(Sizing, SizeCapacity) {
    my_vector<int> v = {1,2,3};
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 6);
}

TEST(Sizing, ShrinkToFit){
    my_vector<int> v = {1,2,3};
    v.shrink_to_fit();
    EXPECT_EQ(v.size(), v.capacity());
}

TEST(Sizing, Reserve){
    my_vector<int> v = {1,2};
    v.reserve(15);
    EXPECT_EQ(v.capacity(), 15);
}

TEST(Sizing, Resize) {
    my_vector<int> v = {1,2,3};
    v.resize(2);
    EXPECT_EQ(v.size(),2);
}

TEST(Swapping, FirstElement){
    my_vector<int> a = {1,2,3};
    my_vector<int> b = {4,5};
    a.swap(b);
    EXPECT_EQ(a[0], 4);
    EXPECT_EQ(b[0], 1);
}

TEST(Sizing, Clear) {
    my_vector<int> a = {1,2,3,4};
    a.clear();
    EXPECT_EQ(a.size(), 0);
}

TEST(Modification, PopBack) {
    my_vector<int> a = {1,2,3,4,5};
    a.pop_back();
    EXPECT_EQ(a.back(), 4);
}

TEST(Modification, PushBack) {
    my_vector<int> a = {1,2,3,4,5};
    a.push_back(6);
    EXPECT_EQ(a.back(), 6);
}

TEST(Modification, EmplaceBack) {
    my_vector<int> a = {1,3,4};
    a.emplace_back(1);
    EXPECT_EQ(a.back(), 1);
}

TEST(Comparison, Equality) {
    my_vector<int> a = {1,2,3};
    my_vector<int> b = {1,2,3};
    EXPECT_TRUE(a == b);
}

TEST(Comparison, NotEqual) {
    my_vector<int> a = {1,2,3};
    my_vector<int> b = {1,3,3};
    EXPECT_TRUE(a != b);
}


TEST(Comparison, Less) {
    my_vector<int> a = {1,2,2};
    my_vector<int> b = {1,2,3};
    EXPECT_TRUE(a < b);
}

TEST(Comparison, LessEqual) {
    my_vector<int> a = {1,2,3};
    my_vector<int> b = {1,2,3};
    EXPECT_TRUE(a <= b);
}

TEST(Comparison, More) {
    my_vector<int> a = {1,2,4};
    my_vector<int> b = {1,2,3};
    EXPECT_TRUE(a > b);
}

TEST(Comparison, MoreEqual) {
    my_vector<int> a = {1,2,3};
    my_vector<int> b = {1,2,3};
    EXPECT_TRUE(a >= b);
}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
