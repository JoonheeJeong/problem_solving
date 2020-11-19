#include <iostream>

using namespace std;

class Min_heap {
    int arr[100000];
    int size;

    void trickle_up(int i);
    void trickle_down(int i);
public:
    Min_heap() : size(0) {}
    void insert(int val);
    int remove();
};

void Min_heap::trickle_up(int i)
{
    int bottom = arr[i];
    int parent = (i-1) / 2;
    while (i > 0 && arr[parent] > bottom) {
        arr[i] = arr[parent];
        i = parent;
        parent = (i-1) / 2;
    }
    arr[i] = bottom;
}

void Min_heap::insert(int val)
{
    arr[size] = val;
    trickle_up(size++);
}

void Min_heap::trickle_down(int i)
{
    int top = arr[i];
    while (i < size/2) {
        int left_child = 2*i + 1;
        int right_child = left_child + 1;
        int less_child;
        if (right_child < size && arr[right_child] < arr[left_child])
            less_child = right_child;
        else
            less_child = left_child;
        if (top <= arr[less_child])
            break;
        arr[i] = arr[less_child];
        i = less_child;
    }
    arr[i] = top;
}

int Min_heap::remove()
{
    if (size == 0)
        return 0;
    int ret = arr[0];
    arr[0] = arr[--size];
    trickle_down(0);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Min_heap min_heap;
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        if (k == 0)
            cout << min_heap.remove() << "\n";
        else
            min_heap.insert(k);
    }
    return 0;
}
