# Image Steganography Using C

## 📌 Project Description

**Image Steganography Using C** is a console-based application that allows users to securely hide secret text messages inside 24-bit BMP images and retrieve them when needed. The project implements the **Least Significant Bit (LSB) technique** to embed secret data into image pixel values while maintaining the visual quality of the original image.

The application provides separate encoding and decoding functionalities through a command-line interface. It demonstrates the practical application of file handling, bitwise operations, and data hiding techniques in C programming.

## ✨ Features

- **Encode:** Hide secret text messages inside 24-bit BMP images.
- **Decode:** Extract hidden messages from encoded BMP images.
- **LSB Technique:** Embed data by modifying the least significant bits of image pixel data.
- **Visual Quality Preservation:** Minimize visible changes to the original image.
- **File Handling:** Read and write BMP image files and manage encoded data.
- **Command-Line Interface:** Perform encoding and decoding operations through the terminal.
- **Modular Implementation:** Organize functionality into separate C source and header files.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Concepts:** File Handling, Bitwise Operations, Pointers, Structures, and Command-Line Arguments
- **Image Format:** 24-bit BMP
- **Development Environment:** GCC Compiler and Linux/Ubuntu

## ⚙️ How It Works

The application uses the Least Significant Bit (LSB) steganography technique.

1. **Encoding:** Reads the input BMP image and secret message.
2. **Embedding:** Converts message data into bits and stores them in the least significant bits of selected image pixel bytes.
3. **Output Generation:** Creates a new BMP image containing the hidden message.
4. **Decoding:** Reads the encoded image and extracts the embedded bits to reconstruct the original secret message.

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Linux/Ubuntu environment or another compatible C development environment
- A valid 24-bit BMP image

## ⚙️ Compilation

Compile the C source files using GCC:

```bash
gcc *.c
```

This generates the default executable named `a.out`. If your executable is named `out`, compile using:

```bash
gcc *.c -o out
```

## 🚀 Usage

### 1. Encoding a Secret Message

Hide the contents of `secret.txt` inside the `beautiful.bmp` image and generate the output image `stego.bmp`.

```bash
./out -e beautiful.bmp secret.txt stego.bmp
```

**Arguments:**
- `-e`: Encoding mode
- `beautiful.bmp`: Source BMP image
- `secret.txt`: Text file containing the secret message
- `stego.bmp`: Output image containing the hidden message

### 2. Decoding a Secret Message

Extract the hidden message from the encoded image:

```bash
./out -d stego.bmp
```

**Arguments:**
- `-d`: Decoding mode
- `stego.bmp`: Encoded BMP image containing the hidden message

**Note:** Ensure that the source image is a supported 24-bit BMP file and that the input files exist before running the program.

Follow the command-line prompts to select encoding or decoding and provide the required input files and message details.

*Note: Update the compilation command and usage instructions if your project uses a Makefile or specific command-line arguments.*

## 📂 Project Structure

```text
Image-Steganography/
├── encode.c
├── encode.h
├── decode.c
├── decode.h
├── common.h
├── test_encode.c
├── types.h
└── README.md
```

*Adjust the filenames and directory structure to match your actual repository.*

## 🎯 Learning Outcomes

- Understanding image steganography and the LSB algorithm.
- Applying bitwise operations to encode and decode binary data.
- Improving C programming skills through file handling and modular design.
- Working with BMP image file formats and pixel data.
- Developing a practical command-line application.

## 🔒 Limitations

- Supports 24-bit BMP images.
- The hidden message capacity depends on the available image data and the implementation.
- Modifying or compressing the encoded image may corrupt the hidden message.
- LSB steganography hides the existence of data but does not encrypt it. For sensitive information, encryption should be used alongside steganography.

## 👨‍💻 Author

**Shrikrishna Ranbhare**

Electronics and Communication Engineering
