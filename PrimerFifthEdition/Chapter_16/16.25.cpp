extern template class vector<string>; // 实例化声明
template class vector<Sales_data>;    // 实例化定义

// 这两个模板的定义将出现在程序的其他文件中
// 此时类模板的实例化会实例化类的所有成员，所以用来显式实例化类模板的类型实参必须支持模板的所有成员
