#include <iostream>
#include <boost/thread/thread.hpp>
#include "BoostTestConfig.h"

using namespace std;

void hello()
{
    cout << "hellolo World! I'm thread!" << endl;
}

void delay(int sec)
{
    boost::this_thread::sleep(boost::posix_time::seconds(sec));
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << argv[0] << " Version " << BoostTest_VERSION_MAJOR << "." << BoostTest_VERSION_MINOR << endl;
    }
    cout << "hi" << endl;
    boost::thread t(&hello);
    cout << "thread ID: " << t.get_id() << endl;
    delay(3);
    t.join();
    cout << "thread joined ID: " << t.get_id() << endl;
    return 0;
}
