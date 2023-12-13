#include "Span.hpp"

int main()
{
    Span sp = Span(100);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    cout << "sp shortest: " << sp.shortestSpan() << endl;
    cout << "sp longest: " <<sp.longestSpan() << endl;
    Span n_sp(10);

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    n_sp.addNumber(v.begin(), v.end());
    cout << "n_sp largest:" << n_sp.longestSpan() << endl;
    cout << "n_sp shortest: " << n_sp.shortestSpan() << endl;
    
    return 0;
}