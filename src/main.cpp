#include "main.h"
#include "Util.h"
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string>
#include <cstring>

Util util;

int main() {

    // Init OpenSSL
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    
    // test data
    const char* data = "Hello, OpenSSL!";
    unsigned char encrypted[128];
    unsigned char decrypted[128];
    
    // encrypt
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)"0123456789012345", (unsigned char*)"1234567890123456");
    
    int len;
    int ciphertext_len;
    EVP_EncryptUpdate(ctx, encrypted, &len, (unsigned char*)data, strlen(data));
    ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, encrypted + len, &len);
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    
    std::cout << "Encrypted: ";
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", encrypted[i]);
    }
    std::cout << std::endl;
    
    // decrypt
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)"0123456789012345", (unsigned char*)"1234567890123456");
    
    int decrypted_len;
    EVP_DecryptUpdate(ctx, decrypted, &len, encrypted, ciphertext_len);
    decrypted_len = len;
    EVP_DecryptFinal_ex(ctx, decrypted + len, &len);
    decrypted_len += len;
    EVP_CIPHER_CTX_free(ctx);
    
    decrypted[decrypted_len] = '\0';  // null-terminate the decrypted string
    
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}