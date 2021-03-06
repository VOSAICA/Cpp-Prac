// (a) Sales_data& combine(Sales_data);
//     i.combine(s)
//     没啥问题
//
// (b) Sales_data& combine(Sales_data&);
//     i.combine(s)
//     error
//     s被转化为Sales_data，但是一个临时变量，不是引用
//
// (c) Sales_data& combine(const Sales_data&) const;
//     i.combine(s)
//     本来conbine就不是给const Sales_data用的，别看了
