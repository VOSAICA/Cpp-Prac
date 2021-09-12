// 模板内class模板实参默认为类成员，当想要使用类内类型时，必须用typename
template <typename T>
typename T::value_type top(const T& c)
{
    if (!c.empty())
    {
        return c.back();
    }
    return typename T::value_type();
}

// typename是后来引入的，和class没什么别的差距了
