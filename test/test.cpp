// priority_queue::empty
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue < int >mypq;
    int sum(0);

    for (int i = 1; i <= 10; i++)
        mypq.push(i);

    mypq.push(1);

    while (!mypq.empty()) {
        cout << mypq.top() << endl;
        //sum += mypq.top();
        mypq.pop();
    }

    //cout << "total: " << sum << endl;

    return 0;
}
