/*
 * Documentation
 * Name        : Shrikrishna Ranbhare
 * Date        : 18/7/26
 * Description : Steganography Project - Encode/Decode hidden messages in BMP images
 */

#include <stdio.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int argc, char *argv[])
{
    EncodeInfo encodeInfo;
    DecodeInfo decodeInfo;

    if (argc < 2)
    {
        fprintf(stderr, "📌 Usage:\n");
        fprintf(stderr, "   To encode : %s -e <input.bmp> <secret.txt|.c|.sh> [optional output.bmp]\n", argv[0]);
        fprintf(stderr, "   To decode : %s -d <stego_image.bmp> [optional output_file]\n", argv[0]);
        return 0;
    }
    // Determine operation type
    OperationType op_type = check_operation_type(argv);

    if (argc < 2)
    {
    }
    if (op_type == e_encode)
    {
        // Expected: ./lsb_steg -e <input.bmp> <secret.txt> [output.bmp]
        if (argc >= 4 && argc <= 5)
        {
            if (read_and_validate_encode_args(argv, &encodeInfo) == e_success)
            {
                if (do_encoding(&encodeInfo) == e_success)
                {
                    close_encode_files(&encodeInfo);
                    printf("\n🚀 Hidden data encoded into the image successfully!\n");
                    printf("🎉 ✅ ENCODING COMPLETED — FILE READY FOR DELIVERY ✅\n");
                    printf("_________________________________________________________\n");
                }
                else
                {
                    close_encode_files(&encodeInfo);
                    fprintf(stderr, "❌ ERROR: Failed to perform encoding\n");
                    return e_failure;
                }
            }
            else
            {
                fprintf(stderr, "❌ ERROR: Validation of encoding arguments failed\n");
            }
        }
        else
        {
            fprintf(stderr, "❌ ERROR: Invalid number of arguments for encoding\n");
            fprintf(stderr, "📌 Usage: %s -e <input.bmp> <secret.txt|.c|.sh> [optional output.bmp]\n", argv[0]);
        }
    }
    else if (op_type == e_decode)
    {
        // Expected: ./lsb_steg -d <stego_image.bmp> [output.txt]
        if (argc >= 3 && argc <= 4)
        {
            if (read_and_validate_decode_args(argv, &decodeInfo) == e_success)
            {
                if (do_decoding(&decodeInfo) == e_success)
                {
                    close_decode_files(&decodeInfo);
                    printf("\n🧠 Hidden data successfully extracted from the image!\n");
                    printf("🎉 ✅ DECODING COMPLETED — DATA RECOVERED SUCCESSFULLY ✅\n");
                    printf("_________________________________________________________\n");

                    // Display the decoded message
                    display_decoded_message(&decodeInfo);
                }
                else
                {
                    close_decode_files(&decodeInfo);
                    fprintf(stderr, "❌ ERROR: Failed to perform decoding\n");
                }
            }
            else
            {
                fprintf(stderr, "❌ ERROR: Validation of decoding arguments failed\n");
            }
        }
        else
        {
            fprintf(stderr, "❌ ERROR: Invalid number of arguments for decoding\n");
            fprintf(stderr, "📌 Usage: %s -d <stego_image.bmp> [optional output.txt]\n", argv[0]);
        }
    }
    else
    {
        fprintf(stderr, "❌ ERROR: Unsupported operation\n");
        fprintf(stderr, "➡️  Use -e for encoding or -d for decoding\n");
        fprintf(stderr, "📌 Usage:\n");
        fprintf(stderr, "   To encode : %s -e <input.bmp> <secret.txt|.c|.sh> [optional output.bmp]\n", argv[0]);
        fprintf(stderr, "   To decode : %s -d <stego_image.bmp> [optional output_file]\n", argv[0]);
    }

    return 0;
}