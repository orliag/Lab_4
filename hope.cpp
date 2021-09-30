#include <iostream>
#include <vector>
#include <list>

using namespace std;

// тиссиль торадин тлен освольд

template<class T>
bool upr_is_even(T a) {
    if (a % 2 == 0) 
        return true;
    else return false;
}

template<class T>
bool bpr_is_chaging(T a, T b) {
    if (a * b > 0) return false;
    else return true;
}



template<class Iterator, class UPred>
bool all_of(Iterator first, Iterator last, UPred fun) {
    while (first != last) {
        if (!fun(*first)) return false;
        first++;
    }return true;
}


template<class Iterator, class UPred>
bool any_of(Iterator first, Iterator last, UPred fun) {
    while (first != last) {
        if (fun(*first)) return true;
        first++;
    }return false;
}


template<class Iterator, class UPred>
bool none_of(Iterator first, Iterator last, UPred fun) {
    while (first != last) {
        if (fun(*first)) return false;
        first++;
    }return true;

}


template<class Iterator, class UPred>
bool one_of(Iterator first, Iterator last, UPred fun) {
    bool flag = false;
    while (first != last) {
        if (fun(*first))
            if (!flag) flag = true;
            else return false;
        first++;
    }return flag;
}

template<class Iterator, class BPred>
bool is_sorted(Iterator first, Iterator last, BPred fun) {
    if (first == last) return true;
    Iterator pr = first++; 
    while (first != last) {
        if (!fun(*pr, *first)) return false;
        first++; pr++;
    }
    return true;    
}

template<class Iterator, class UPred>
bool is_partitioned(Iterator first, Iterator last, UPred fun) {
    bool flag = false;
    while ((first != last)and(!flag)) {
        if (fun(*first) != true) flag = true;
        first++;
    }
    while (first != last) {
        if (fun(*first) ) return false;
        first++;
    }
    return true;
}

template<class Iterator, class T>
Iterator find_not(Iterator first, Iterator last, const T& value) {
    while (first != last) {
        if (*first != value) {
            return first;
        }
        first++;
    }
    return last;
}

template<class Iterator, class T>
Iterator find_backwards(Iterator first, Iterator last, const T& value) {
    Iterator end = last;
    while (last != first) {
        last--;
        if (*last == value) {
            return last;
        }
    }
    return end;
}

template<class Iterator>
bool is_palindrome(Iterator first, Iterator last) {
    while (first != last) {
        last--;
        if (*first != *last)   return false;
        if (first == last) return true;
        first++;
    }
    return true;
}


int main()
{
 
	int n = 7;
    list <int> v = {-1};

    cout << all_of(v.begin(), v.end(), upr_is_even<int>) << endl;
    cout << any_of(v.begin(), v.end(), upr_is_even<int>) << endl;
    cout << none_of(v.begin(), v.end(), upr_is_even<int>) << endl;
    cout << one_of(v.begin(), v.end(), upr_is_even<int>) << endl;
    cout << is_sorted(v.begin(), v.end(), bpr_is_chaging<int>) << endl <<endl;
    cout << is_partitioned(v.begin(), v.end(), upr_is_even<int>) << endl;
    cout << *find_not(v.begin(), v.end(), 3)<< endl;
    //cout << *find_backwards(v.begin(), v.end(), 3) << endl;
    cout << is_palindrome(v.begin(), v.end()) << endl;

}