#include <iostream>
#include <exception>
#include <string>
using namespace std;
 
string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функции:
    * нормальный возврат строкового значения
    * выброс исключения system_error
    * выброс другого исключения с сообщением.
    */
}
 
class TimeServer {
public:
    string GetCurrentTime() {
        try
        {
            LastFetchedTime = AskTimeServer();
            return LastFetchedTime;
        }
        catch (const system_error&)
        {
            return LastFetchedTime;
        }
        catch (...) {
            throw;
        }
    }
 
private:
    string LastFetchedTime = "00:00:00";
};
 
int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}