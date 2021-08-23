// q会被拷贝，shared_ptr的引用计数+1
// q被移动，shared_ptr变为nullptr,对资源的所有权被移交
// 等同于合成的拷贝函数
// 等同于合成的移动函数
// q被销毁，shared_ptr的引用计数-1
