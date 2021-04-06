// 输入迭代器
// == != ++ *(只出现在赋值运算符右侧) ->
// e.g. istream_iterator

// 输出迭代器
// ++ *(只出现在赋值运算符左侧)
// e.g. ostream_iterator

// 前向迭代器
// 包含输入和输出迭代器的全部
// e.g. forward_list

// 双向迭代器
// 前向迭代器的全部加--
// e.g. 除了forward_list的全部标准库容器

// 随机访问迭代器
// < <= > >= + += - -= -(两个迭代器相减) iter[n] *iter[n]
// e.g. array, deque, string, vector
