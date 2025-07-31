#include "main.h"
#include "Util.h"
#include "Define.h"
#include "../lib/json/json.h"
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string>
#include <cstring>
#include <dlfcn.h> // library load

Util util;

int main() {

    // current time get
    std::string asd = util.time_get();

    std::string pw = util.get_input("user password: ");
    std::cout << pw << std::endl;


    // Json lib
    void* LibHandle = NULL;
    LibHandle = dlopen(JSON_LIB, RTLD_NOW);
    if(!LibHandle){
        DBG_PRINT("Failed to load JSON library: %s\n", dlerror());
        return FAIL;
    }

    Json::Value resroot;
    resroot["CKA_CLASS"] = "CKO_SECRET_KEY";
    resroot["CKA_KEY_TYPE"] = "CKK_AES";
    resroot["CKA_LABEL"] = "key_label";
    resroot["CKA_TOKEN"] = "false";
    Json::StreamWriterBuilder abuilder;
    std::string create_json_file = Json::writeString(abuilder, resroot);

    std::cout << create_json_file << std::endl;

    dlclose(LibHandle); 

    return 0;
}