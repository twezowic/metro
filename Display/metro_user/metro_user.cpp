#include"User.h"
#include"User_admin.h"

#include <iostream>

int main()
{
    User_admin adm("a", "b", "c", "123", "2ad@sda");
    User user("a", "b", "c", "123412", "2ad@sda");
    /*cout << adm.getPassword(user);*/
    adm.helloWorld();
    user.helloWorld();
}
