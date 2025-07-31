#include "main.h"
#include "Util.h"
#include "Define.h"
#include "../lib/json/json.h"
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string>
#include <cstring>

Util util;

int main() {

    // current time get
    std::string asd = util.time_get();

    std::string pw = util.get_input("user password: ");
    std::cout << pw << std::endl;

    return 0;
}