#include <iostream>
#include <boost/thread/thread.hpp>

using namespace std;

void hello()
{
    cout << "hellolo World! I'm thread!" << endl;
}

void delay(int sec)
{
    boost::this_thread::sleep(boost::posix_time::seconds(sec));
}

class CSampleIO
{
    public:
        void TestThread()
        {
            cout<<"1 ";
            boost::this_thread::sleep(boost::posix_time::millisec(500));
        }

        void TestThreadSecond(int num)
        {
            cout<<num<<" ";
            boost::this_thread::sleep(boost::posix_time::millisec(500));
        }

        void TestThreadThird(int num, int num2)
        {
            cout<<num<<" ";
            boost::this_thread::sleep(boost::posix_time::millisec(500));
        }
};

int main()
{
    cout << "hi" << endl;
    cout << " 1 " << endl;
//    //스레드생성(인자는 계속 추가 시킬 수 있음)
//    boost::thread th1 = boost::thread( boost::bind(&CSampleIO::TestThread, &io)  );
//    boost::thread th2 = boost::thread( boost::bind(&CSampleIO::TestThreadSecond, &io, 2)  );
//    boost::thread th3 = boost::thread( boost::bind(&CSampleIO::TestThreadThird, &io, 3, NULL)  );
//    cout << " 2 " << endl;
//    //join에서 해당 스레드가 시작 됨
//    th1.detach();
//    th2.detach();
//    th3.join();

    boost::thread t(&hello);
    cout << "thread ID: " << t.get_id() << endl;
    delay(3);
    t.join();
    cout << "thread joined ID: " << t.get_id() << endl;
    return 0;
}
