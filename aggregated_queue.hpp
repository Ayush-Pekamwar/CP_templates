using ll = long long;

template <class T, auto F>
struct AggStack
{
    // stores {element,
    //         agg_val_by_applying_F_top_to_bottom}
    stack<pair<T, T>> S;

    void push(T val)
    {
        if (S.empty())
            S.push({val, val});
        else
            S.push({val, F(val, S.top().second)});
    }

    //> get value at the top
    T top()
    {
        return S.top().first;
    }
    //> get value at the top and pop
    T pop()
    {
        T ret = S.top().first;
        S.pop();
        return ret;
    }

    bool empty()
    {
        return S.empty();
    }
    bool size()
    {
        return S.size();
    }

    //> get aggregated value
    T get()
    {
        return S.top().second;
    }

    void swap(AggStack<T, F> &ST)
    {
        S.swap(ST.S);
    };
};

template <class T, auto F>
struct AggQueue
{
    AggStack<T, F> In, Out;

    //> always push element in 'In' Stack
    void push(T val)
    {
        In.push(val);
    }

    //> always pop from 'Out' Stack
    T pop()
    {
        if (Out.empty())
        {
            while (!In.empty())
                Out.push(In.pop());
        }
        return Out.pop();
    }

    //* returns aggregation of all values in the queue
    T get()
    {
        if (In.empty())
            return Out.get();
        if (Out.empty())
            return In.get();

        return F(In.get(), Out.get());
    }
};

/*
// example case:
    //OR
    AggQueue<int, [](int a, int b) { return a | b; }> Q

    //AND
    AggQueue<int, [](int a, int b) { return a & b; }> Q;

    //MAX
    AggQueue<int, [](int a, int b) { return max(a, b); }> Q;

    //MIN
    AggQueue<int, [](int a, int b) { return min(a, b); }> Q;

    //GCD
    AggQueue<int, [](int a, int b) { return __gcd(a, b); }> Q;


*/