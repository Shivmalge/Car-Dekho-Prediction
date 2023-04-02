#include <iostream>
#include <string>
#include <vector>
#include "UserEntity.cpp"

using namespace std;


using namespace std;


class UserManager {
private:
    vector<UserEntity> userList;

public:
    void createUser(string username, string password) {
        UserEntity user(username, password);
        userList.push_back(user);
    }

    void updateUser(int index, string username, string password) {
        if (index >= 0 && index < userList.size()) {
            userList[index].setUsername(username);
            userList[index].setPassword(password);
        }
    }

    void deleteUser(int index) {
        if (index >= 0 && index < userList.size()) {
            userList.erase(userList.begin() + index);
        }
    }

    UserEntity* getUserByUsername(string username) {
        for (auto& user : userList) {
            if (user.getUsername() == username) {
                return &user;
            }
        }
        return nullptr;
    }

    int getUserCount() const {
        return userList.size();
    }
};