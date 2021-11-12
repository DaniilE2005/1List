#include <bits/stdc++.h>

using namespace std;

list<long long> mas;

int emptiness() {
    if (mas.size() == 0) {
        return 1;
    } else {
        return 0;
    }
}

void push_head(long long v) {
    Vertex vtx = new Vertex(v);
    vtx.next = head;
    head = vtx;
}

void push_tail(long long v) {
    Vertex vtx = new Vertex(v);
    tail.next = vtx;
    tail = vtx;
}

void push_i(long long v, long long index) {
    Vertex pre = head;
    for (int i = 0; i <= index-1; i++) {
        pre = pre.next;
1   }
    Vertex aft = pre.next;
    Vertex vtx = new Vertex(v);
    vtx.next = aft;
    pre.next = vtx;
}

void remove_head() {
    if (emptiness() != 1) {
        temp = head;
        head = head.next;
        delete temp;
    }
}

void remove_tail() {
    if (emptiness() != 1) {
        Vertex pre = head;
        while (temp.next != null) {
            pre = pre.next;
        }
        pre.next = null;
        delete temp;
        tail = pre;
    }
}

void remove_i(long long index) {
    if (emptiness() != 1) {
        Vertex pre = head;
        for (int i = 0; i < mas.size(); i++) {
            pre = pre.next;
        }
        Vertex del = pre.next;
        aft = del.next;
        pre.next = aft;
        delete del;
    }
}

void remove_k(long long v) {
    if (emptiness() != 1) {
        Vertex pre = head;
        for (int i = 0; i < mas.size(); i++) {
            pre = pre.next;
        }
        Vertex del = pre.next;
        aft = del.next;
        pre.next = aft;
        delete del;
    }
}

int search_k(long long v)  {
    if (emptiness() == 1) {
        return -1;
    } else {
        long long index = 0;
        temp = head;
        while (temp.item != v) {
            temp = temp.next;
            index++;
            if (temp == null) {
                return -1;
            }
        }
        return index;
    }
}

ostream& operator[](long long index) {
    if (emptiness() == 1) {
        return -1;
    } else {
        for (int i = 0; i < mas.size(); i++) {
            if (index == i) {
                return mas[i];
            }
        }
    }
}

void quick_sort(int b, int e) {
    long long l = b, r = e;
    long long piv = mas[(l+r)/2];
    while(l <= r) {
        while(mas[l] < piv) {
            l++;
        }
        while (mas[r] > piv) {
            r--;
        }
        if (l <= r) {
            swap(mas[l++], mas[r--]);
        }
    }
    if (r > b) {
        quick_sort(b, r);
    }
    if (e > l) {
        quick_sort(l, e);
    }
}

ostream& operator<<() {
    for (int i = 0; i < mas.size(); i++) {
        cout << mas[i] << " ";
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    long long n, type;
    cout << "Введите размер списка: ";
    cin >> n;
    mas.resize(n);
    cout << "Введите через пробел элементы списка: ";
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    long long v, index;
    emptiness();
    push_head(v);
    push_tail(v);
    push_i(v, index); //???
    remove_head();
    remove_tail();
    remove_i(index);
    remove_k(v);
    search_k(v);
    quick_sort(0, mas.size()-1);
    friend ostream& operator<<();
    ostream& operator[](index);
}