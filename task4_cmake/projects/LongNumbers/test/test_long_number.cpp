#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "long_number.hpp"

using biv::LongNumber;

// Тесты для конструкторов и базовых операций
TEST(LongNumberBasic, DefaultConstructorIsZero) {
    LongNumber num;
    ASSERT_EQ(num.get_digits_number(), 1);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorForNull) {
    LongNumber num("0");
    ASSERT_EQ(num.get_digits_number(), 1);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorForNulls) {
    LongNumber num("0000");
    ASSERT_EQ(num.get_digits_number(), 1);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorForNegativeNull) {
    LongNumber num("-0");
    ASSERT_EQ(num.get_digits_number(), 1);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorPositive) {
    LongNumber num("12345");
    ASSERT_EQ(num.get_digits_number(), 5);
    ASSERT_EQ(num.get_rank_number(0), 5);
    ASSERT_EQ(num.get_rank_number(4), 1);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorNegative) {
    LongNumber num("-67890");
    ASSERT_EQ(num.get_digits_number(), 5);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_TRUE(num.is_negative());
}

TEST(LongNumberComparasion, ZeroEqualZero) {
    LongNumber a("0");
    LongNumber b("0");
    ASSERT_TRUE(a == b);
}

TEST(LongNumberComparasion, PositiveEqualPositive) {
    LongNumber a("100");
    LongNumber b("100");
    ASSERT_TRUE(a == b);
}

TEST(LongNumberComparasion, NegativeEqualNegative) {
    LongNumber a("-100");
    LongNumber b("-100");
    ASSERT_TRUE(a == b);
}

TEST(LongNumberComparasion, PositiveNotEqualNegative) {
    LongNumber a("100");
    LongNumber b("-100");
    ASSERT_TRUE(a != b);
}

TEST(LongNumberComparasion, PositiveGreaterThanPositive) {
    LongNumber a("100");
    LongNumber b("99");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberComparasion, PositiveGreaterThanZero) {
    LongNumber a("100");
    LongNumber b("0");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberComparasion, PositiveGreaterThanNegative) {
    LongNumber a("100");
    LongNumber b("-100");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberComparasion, ZeroGreaterThanNegative) {
    LongNumber a("0");
    LongNumber b("-12");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberComparasion, NegativeGreaterThanNegative) {
    LongNumber a("-99");
    LongNumber b("-100");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberConstructors, CopyConstructor) {
    LongNumber original("-12345");
    LongNumber copy(original);    
    ASSERT_TRUE(original == copy)
        << original << " " << copy;
}

TEST(LongNumberConstructors, CopyConstructorExtended) {
    LongNumber original("-12345");
    LongNumber copy(original);
    
    EXPECT_EQ(original.get_digits_number(), copy.get_digits_number());
    EXPECT_EQ(original.is_negative(), copy.is_negative());
    for (int i = 0; i < original.get_digits_number(); ++i) {
        EXPECT_EQ(original.get_rank_number(i), copy.get_rank_number(i));
    }
}

TEST(LongNumberArithmetic, SimpleAddition) {
    LongNumber a("123");
    LongNumber b("1234");
    ASSERT_TRUE(a + b == LongNumber("1357"));
}

TEST(LongNumberArithmetic, PositivePlusZero) {
    LongNumber a("123");
    LongNumber b("0");
    ASSERT_TRUE(a + b == a);
}

TEST(LongNumberArithmetic, NegativePlusZero) {
    LongNumber a("-123");
    LongNumber b("0");
    ASSERT_TRUE(a + b == a);
}

TEST(LongNumberArithmetic, AdditionOpposite) {
    LongNumber a("-52");
    LongNumber b("52");
    ASSERT_TRUE(a + b == LongNumber());
}

TEST(LongNumberArithmetic, AdditionNegatives) {
    LongNumber a("-753");
    LongNumber b("-314");
    ASSERT_TRUE(a + b == LongNumber("-1067"));
}

TEST(LongNumberArithmetic, CommutativeAdditionTest) {
    LongNumber a("531");
    LongNumber b("-43");
    ASSERT_TRUE(a + b == b + a);
}

TEST(LongNumberCompareAbs, PositiveDiffLength) {
    LongNumber a("123");
    LongNumber b("1234");
    ASSERT_FALSE(a.compare_abs(b));
    ASSERT_TRUE(b.compare_abs(a));
}

TEST(LongNumberCompareAbs, PositiveSameLength) {
    LongNumber a("642");
    LongNumber b("641");
    ASSERT_TRUE(a.compare_abs(b));
    ASSERT_FALSE(b.compare_abs(a));
}

TEST(LongNumberCompareAbs, PositiveAndZero) {
    LongNumber a("11");
    LongNumber b("0");
    ASSERT_TRUE(a.compare_abs(b));
}

TEST(LongNumberCompareAbs, TwoEqualPositives) {
    LongNumber a("542");
    LongNumber b("542");
    ASSERT_FALSE(a.compare_abs(b));
}

TEST(LongNumberCompareAbs, NegativeDiffLength) {
    LongNumber a("-314");
    LongNumber b("-3466");
    ASSERT_FALSE(a.compare_abs(b));
    ASSERT_TRUE(b.compare_abs(a));
}

TEST(LongNumberCompareAbs, NegativeSameLength) {
    LongNumber a("-256");
    LongNumber b("-255");
    ASSERT_TRUE(a.compare_abs(b));
    ASSERT_FALSE(b.compare_abs(a));
}

TEST(LongNumberCompareAbs, NegativeAndZero) {
    LongNumber a("-69");
    LongNumber b("0");
    ASSERT_TRUE(a.compare_abs(b));
}

TEST(LongNumberCompareAbs, TwoEqualNegatives) {
    LongNumber a("-36");
    LongNumber b("-36");
    ASSERT_FALSE(a.compare_abs(b));
}


TEST(LongNumberArithmeticBasic, SimpleSubstraction) {
    LongNumber a = "1234";
    LongNumber b = "123";
    ASSERT_TRUE(a - b == LongNumber("1111"));
}

TEST(LongNumberArithmeticBasic, AddSubAllCases) {
    LongNumber n123("123");
    LongNumber n1234("1234");
    ASSERT_TRUE(n123 + n1234 == LongNumber("1357")) << "123 + 1234 = 1357";

    LongNumber n1("1");
    LongNumber nminus1("-1");
    LongNumber n0("0");
    LongNumber n999("999");
    LongNumber n1000("1000");
    LongNumber nminus1000("-1000");
    ASSERT_TRUE(nminus1 + n1 == n0) << "-1 + 1 = 0";
    ASSERT_TRUE(nminus1 + n0 == nminus1) << "-1 + 0 = -1";
    ASSERT_TRUE(n1 + n0 == n1) << "1 + 0 == 1";
    ASSERT_TRUE(n1000 - n999 == n1) << "1000 - 999 = 1";
    ASSERT_TRUE(nminus1000 + n999 == nminus1) << "-1000 + 999 = -1";
    ASSERT_TRUE(n999 - n1000 == nminus1) << "999 - 1000 = -1";
    ASSERT_TRUE(n1 + n999 == n1000) << "1 + 999 = 1000";
}

TEST(LongNumberArithmeticBasic, AdditionCommutativity) {
    LongNumber n431("431");
    LongNumber n753("753");
    ASSERT_TRUE(n431 + n753 == n753 + n431) << "431 + 753 = 753 + 431 = 1184";

    LongNumber nminus575("-575");
    LongNumber nminus51("-51");
    ASSERT_TRUE(nminus575 + nminus51 == nminus51 + nminus575) << "-575 + (-51) = -626 vs -51 + (-575) = -626";
    ASSERT_TRUE(n753 + nminus51 == nminus51 + n753) << "753 + (-51) = 702 vs -51 + 753 = 702";
    ASSERT_TRUE(n753 + nminus575 == nminus575 + n753) << "753 + (-575) = 178 vs -575 + 753 = 178";
}

TEST(LongNumberArithmeticAdvanced, MultiplyingCommutativity) {
    LongNumber n431("431");
    LongNumber n753("753");
    ASSERT_TRUE(n431 * n753 == n753 * n431) << "431 * 753 = 324,843 vs 753 * 431 = 324,843";

    LongNumber nminus575("-575");
    LongNumber nminus51("-51");
    ASSERT_TRUE(nminus575 * nminus51 == nminus51 * nminus575) << "-575 * -51 = 29,325 vs -51 * -575 = 29,325";
    ASSERT_TRUE(n753 * nminus51 == nminus51 * n753) << "753 * -51 = -38,403 vs -51 * 753 = -38,403";
    ASSERT_TRUE(n753 * nminus575 == nminus575 * n753) << "753 * -575 = -432,975 vs -575 * 753 = -432,975";
}

TEST(LongNumberArithmeticAdvanced, MultiplyAllCases) {
    LongNumber n2("2");
    LongNumber n3("3");
    LongNumber n6("6");
    LongNumber nminus6("-6");
    LongNumber n0("0");
    LongNumber n123("123");
    LongNumber nminus123("-123");
    LongNumber n456("456");
    LongNumber n56088("56088");
    LongNumber nminus56088("-56088");
    LongNumber n999("999");
    LongNumber n999x999("998001");
    LongNumber nminus1("-1");
    LongNumber n1("1");

    ASSERT_TRUE(n2 * n3 == n6) << "2 * 3 = 6";
    ASSERT_TRUE(n2 * nminus6 == nminus6 * n2) << "2 * (-6) = (-6) * 2 = -12";
    ASSERT_TRUE(nminus123 * nminus1 == n123) << "-123 * -1 = 123";

    ASSERT_TRUE(n123 * n0 == n0) << "123 * 0 = 0";
    ASSERT_TRUE(nminus6 * n0 == n0) << "-6 * 0 = 0";

    ASSERT_TRUE(n123 * n1 == n123) << "123 * 1 = 123";
    ASSERT_TRUE(n123 * nminus1 == nminus123) << "123 * -1 = -123";

    ASSERT_TRUE(n123 * n456 == n56088) << "123 * 456 = 56088";
    ASSERT_TRUE(nminus123 * n456 == nminus56088) << "-123 * 456 = -56088";
    ASSERT_TRUE(n999 * n999 == n999x999) << "999 * 999 = 998001";
}

TEST(LongNumberArithmeticAdvanced, DivideAllCases) {
    LongNumber n12("12"); LongNumber n15("15"); LongNumber n7("7"); LongNumber n10("10"); 
    LongNumber n4("4"); LongNumber n3("3"); LongNumber nminus3("-3"); LongNumber n0("0");
    LongNumber n123("123"); LongNumber nminus123("-123"); LongNumber n456("456"); LongNumber n87("87");
    LongNumber n333("333"); LongNumber n5("5"); LongNumber n2("2"); LongNumber n1("1");

    ASSERT_TRUE(n12 / n4 == n3) << "12 / 4 = 3";
    ASSERT_TRUE(n15 / n4 == n3) << "15 / 4 = 3";
    ASSERT_TRUE(n7 / n3 == n2) << "7 / 3 = 2";
    ASSERT_TRUE(n10 / nminus3 == LongNumber("-3")) << "10 / (-3) = -3";
    ASSERT_TRUE(nminus123 / n3 == LongNumber("-41")) << "-123 / 3 = -41";
    ASSERT_TRUE(nminus123 / nminus123 == n1) << "-123 / -123 = 1";
    ASSERT_TRUE(n456 / n123 == n3) << "456 / 123 = 3";
    ASSERT_TRUE(n5 / n10 == n0) << "5 / 10 = 0";
}

TEST(LongNumberArithmeticAdvanced, ModAllCases) {
    LongNumber n12("12"); LongNumber n15("15"); LongNumber n7("7"); LongNumber n10("10");
    LongNumber n4("4"); LongNumber n3("3"); LongNumber nminus3("-3"); LongNumber n0("0");
    LongNumber n123("123"); LongNumber nminus123("-123"); LongNumber n456("456"); LongNumber n87("87");
    LongNumber n333("333"); LongNumber n5("5"); LongNumber n2("2"); LongNumber n1("1");
    LongNumber nminus5("-5"); LongNumber nminus2("-2");
    
    // положительные делимое и делитель
    ASSERT_TRUE(n12  % n4   == n0)  << "12 % 4 = 0";
    ASSERT_TRUE(n15  % n4   == n3)  << "15 % 4 = 3";
    ASSERT_TRUE(n7   % n3   == n1)  << "7 % 3 = 1";
    ASSERT_TRUE(n5   % n10  == n5)  << "5 % 10 = 5";
    ASSERT_TRUE(n456 % n123 == n87) << "456 % 123 = 87";
    ASSERT_TRUE(n0   % n123 == n0)  << "0 % 123 = 0";

    // положительное делимое, отрицательный делитель
    ASSERT_TRUE(n10 % nminus3 == n1) << "10 % (-3) = 1";
    ASSERT_TRUE(n15 % LongNumber("-4") == n3) << "15 % (-4) = 3";

    // отрицательное делимое, положительный делитель
    ASSERT_TRUE(nminus123 % n3  == n0)      << "-123 % 3 = 0";
    ASSERT_TRUE(nminus5   % n3  == nminus2) << "-5 % 3 = -2";
    ASSERT_TRUE(nminus5   % n10 == nminus5) << "-5 % 10 = -5";

    // отрицательное делимое и отрицательный делитель
    ASSERT_TRUE(nminus5   % LongNumber("-3")  == nminus2) << "-5 % -3 = -2";
    ASSERT_TRUE(nminus123 % LongNumber("-10") == nminus3) << "-123 % -10 = -3";
}