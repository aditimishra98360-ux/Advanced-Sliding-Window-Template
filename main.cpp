struct Info
{
    ll mi = LONG_LONG_MAX;
    ll val = 0;
    // ll ma = LONG_LONG_MIN;
    // ll g = 0;
};
 
Info operator+(const Info &a, const Info &b)
{
    Info c;
    c.val = a.val;
    // c.ma = max(a.ma, b.ma);
    c.mi = min(a.mi, b.mi);
    // c.g = __gcd(a.g, b.g);
    return c;
}
void restart(Info &a)
{
    // a.ma = a.val;
    a.mi = a.val;
    // a.g = a.val;
}
 
struct AggStack
{
    // Each element is stored as (value, current_min)
    stack<Info> st;
 
    // Push a new number; compute the new min.
    void push(Info x)
    {
        if (!st.empty())
        {
            Info y = st.top();
            Info z = x + y;
            st.push(z);
        }
        else
        {
            st.push(x); // first element, so push as-is
        }
    }
 
    // Pop the top element.
    void pop()
    {
        st.pop();
    }
 
    // Return the current minimum.
    Info agg() const
    {
        return st.top();
    }
};
struct AggQueue
{
    AggStack in, out;
 
    // Push a new number into the queue.
    void push(Info x)
    {
        in.push(x);
    }
 
    // Pop the oldest number.
    void pop()
    {
        if (out.st.empty())
        {
            while (!in.st.empty())
            {
                Info v = in.st.top();
                in.pop();
                restart(v);
                out.push(v);
            }
        }
        out.pop();
    }
    // Query the current minimum.
    Info query() const
    {
        if (in.st.empty())
            return out.agg();
        if (out.st.empty())
            return in.agg();
        return in.agg() + out.agg();
    }
};
