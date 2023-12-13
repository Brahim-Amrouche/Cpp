#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    // list implementation
    cout << "list output" <<endl;
    list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    cout << lst.back() << endl;
    lst.pop_back();
    cout << lst.size() << endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    list<int>::iterator l_it = lst.begin();
    list<int>::iterator l_ite = lst.end();
    ++l_it;
    --l_it;
    while(l_it != l_ite)
    {
        cout << *l_it << endl;
        ++l_it;
    }
    list<int> l(lst);
    return 0;
}