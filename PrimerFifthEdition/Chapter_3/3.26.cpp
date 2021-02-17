// mid = beg + (end - beg) / 2;
// mid是迭代器，用迭代器 + difference_type来赋值没问题

// mid = (beg + end) / 2;
// (beg + end) / 2是 difference_type，不能给iterator赋值
