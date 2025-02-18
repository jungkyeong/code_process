#include "main.h"
#include "Util.h"

Util util;

int main() {

    util.write_to_file("test.txt", (void*)file_data, 3);

    void* read_file_data = nullptr; 
    int read_file_len = util.read_from_file("test.txt", &read_file_data);
    if(read_file_len <=0 || read_file_data == nullptr){
        printf("file read fail \n");
        return 0;
    }

    printf("file read length: %d \n", read_file_len);
    printf("file read data: %s \n", (char*)read_file_data);
    free(read_file_data);

    return 0;
}