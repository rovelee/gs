/*
 * CS:APP Data Lab
 *
 * <Rovelee>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  /*
   * x 异或 y 等价于 （x取反 与上 y）或上（x 与上 y取反），
   * 然后根据德摩根律，
   * 再取次反将或运算转换成与运算
   */
  return ~(~(~x & y) & ~(x & ~y));
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  /*
   * tmin = 0x80000000 = 1 << 31
   */
  return 1 << 31;
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
  /*
   * x       = 0x7fffffff 0xffffffff 0x00000000 0xfffffffe 0x80000000
   * ~x      = 0x80000000 0x00000000 0xffffffff 0x00000002 0x7fffffff
   * x+1     = 0c80000000 0x00000000 0x00000001 0xffffffff 0x80000001
   * ~x^x+1  = 0          0          0xfffffffe 0xfffffffd 0xfffffffe
   * !*4     = 1          1          0          0          0
   * !*4&*!!3= 1          0          0          0          0
   */
  int val1 = x + 1;
  int val2 = ~x ^ val1;
  return (!(!val1) & !val2);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
  /*
   * 当 x 的奇数位都为 1 时，有 2^16 中种组合（即16个偶数位的组合）。
   * 如果能够将偶数位全部变为1，然后取反得0，那么 x 的奇数位就全为1。
   */
  int e_8 = 0x55;
  int e_32 = e_8 + (e_8 << 8) + (e_8 << 16) + (e_8 << 24);
  return !(~(x | e_32));
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  /*
   * -x = 2^w - x
   * -0 = 0
   * 假设 w=4，x=0011，-x=1101，所以是取反再加1。
   */
  return ~x + 1;
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
  /*
   * 0011 0000 <= x <= 0011 1001
   * 先排除高28位不等于0x3的值，如果高 28 位右移4位后不等于0x3，则返回 0。
   * 然后判断低4位是否大于等于0，且小于等于9。
   * 可以注意到，低3位等于0或1时，如 0、1、8、9 一定符合条件。
   * 其他情况则要看第4位是否为0。如果为0则符合条件。
   */
  int is_high_24_eq_3 = !((x >> 4) ^ 3);
  int low_3 = x & 0x7;
  int is_low_3_eq_0_or_1 = (!(low_3 ^ 0) | !(low_3 ^ 1));
  int is_w4_eq_0 = !((x >> 3) & 1);
  int is_low_4_satisfy = is_low_3_eq_0_or_1 | is_w4_eq_0;
  return is_high_24_eq_3 & is_low_4_satisfy;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  /*
   * 三目运算，如果 x=1，则返回 y，否则返回 z。
   * 首先应该将 x 转换为 bool 值，即 0 或 1。
   * 如果 x 为 0，则 bx 是一个全为 0 的串;
   * 如果 x 为 1，则 bx 是一个全为 1 的串。
   * x & y = 0 或 y ，~x & z = z 或 0。
   * 返回这两个集合的交。
   */
  int bx = (!!x) << 31 >> 31;
  return (bx & y) | (~bx & z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  /*
   * 如果 x = y，x ^ y=0，返回 1。
   * 考虑 x<0，y>0，则返回 1。
   * 考虑 x>0, y<0, 则返回 0。
   * 考虑 x 和 y 同号：
   * 则 x 如果小于 y，则 -x 大于 -y ，
   * -x + y > -y + y = 2^w，
   * 即 -x + y 会溢出，
   * 且因为一正一负，所以符号位为一定为0,
   * 即如果(-x + y)的符号位为0，返回1。
   * 将可能返回 0 的值取反后和所有可能返回 1 的值的交做并后返回。
   * （注意：要先判断为0的值，将这个值放在与前时如果为0则无需再继续与运算后的运算）
   */
  int is_eq = !(x ^ y);
  int is_x_lt_0_and_y_gt_0 = ((x >> 31) & 1) & !((y >> 31) & 1);
  int is_x_gt_0_and_y_lt_0 = ((y >> 31) & 1) & !((x >> 31) & 1);
  int is_x_lt_y_same_sign = !((((~x + 1) + y) >> 31) & 1);
  int is_x_le_y = !is_x_gt_0_and_y_lt_0 &
                  (is_eq                |
                   is_x_lt_0_and_y_gt_0 |
                   is_x_lt_y_same_sign);
  return is_x_le_y;
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
  /*
   * 非运算只有在 x=0 时返回 1，其它情况下都返回 0。
   * 即 0->1，[1...0xfffffffe] -> 0，
   *  -x = ~x + 1，
   * 当 x = 0 时，x & -x = 0
   * 当 x ≠ 0 时，
   *  x & -x = 1 << k (k=0,1,2...31)，
   * 如： x=0x03，  -x=0xfd，x & -x = 1     (k=0)；
   *      x = 0x5e，-x=0xa2，x & -x = 0x02 （k=1）.
   * 为了将第 k 位的 1 取出作为判断标准，使用二分法进行或运算，32位需要5次移位和5次或运算，
   * 最后得到 k = 1 或 0，将 k+1 取底一位的值进行返回。
   */
  int k = x;

  int k_r = k >> 16;
  k = k | k_r;
  k_r = k >> 8;
  k = k | k_r;
  k_r = k >> 4;
  k = k | k_r;
  k_r = k >> 2;
  k = k | k_r;
  k_r = k >> 1;
  k = k | k_r;
  
  k = (k + 1) & 1;
  return k;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
  int minum = 1;
  int pv = x & 1;
  int pi = 1;
  return 0;
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
  return 2;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
  return 2;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
  return 2;
}
