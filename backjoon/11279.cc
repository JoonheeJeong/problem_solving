#include <iostream>
#include <vector>

using namespace std;

class Max_heap {
    vector<int> v;
    int size;
    void trickle_up(int i);
    void trickle_down(int i);
public:
    Max_heap() : size(0) {}
    void insert(int val);
    int remove();
};

void Max_heap::trickle_up(int i)
{
    int parent = (i-1)/2;
    int bottom = v[i];
    while (i > 0 && v[parent] < bottom) {
        v[i] = v[parent];
        i = parent;
        parent = (i-1)/2;
    }
    v[i] = bottom;
}

void Max_heap::insert(int val)
{
    v.push_back(val);
    trickle_up(size++);
}

void Max_heap::trickle_down(int i)
{
    int top = v[i];
    while (i < size/2) {
        int left_child = 2*i + 1;
        int right_child = left_child + 1;
        int larger_child;
        if (right_child < size && v[left_child] < v[right_child])
            larger_child = right_child;
        else
            larger_child = left_child;
        if (top >= v[larger_child])
            break;
        v[i] = v[larger_child];
        i = larger_child;
    }
    v[i] = top;
}

int Max_heap::remove()
{
    if (size == 0)
        return 0;
    int ret = v[0];
    v[0] = v[--size];
    v.pop_back();
    trickle_down(0);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    Max_heap max_heap;
    while (n--) {
       int k;
       cin >> k;
       if (k == 0)
           cout << max_heap.remove() << "\n";
       else
           max_heap.insert(k);
    }

    return 0;
}
