using BigInt = long;
inline bool eq(const BigInt&, const BigInt&)
{
} // 内联函数和constexpr函数一般放到头文件中
void putValues(int* arr, int size); // 函数声明也放到头文件
