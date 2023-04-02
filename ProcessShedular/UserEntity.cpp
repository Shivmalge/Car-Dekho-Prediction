#include <vector>
#include <string>


using namespace std;


class UserEntity {
private:
    string username;
    string password;

public:
    UserEntity(string username, string password) {
        this->username = username;
        this->password = password;
    }

    string getUsername() const {
        return username;
    }

    void setUsername(string username) {
        this->username = username;
    }

    string getPassword() const {
        return password;
    }

    void setPassword(string password) {
        this->password = password;
    }
};