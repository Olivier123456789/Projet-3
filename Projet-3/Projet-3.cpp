#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

int main()
{
    //// Write file

    std::ofstream write_file("example.bin", std::ios::binary);

    if (!write_file.is_open())
    {
        throw std::runtime_error("File can't be opened");
    }

    std::string text = "Hello World!";

    write_file.write(text.data(), text.size());
    write_file.close();

    //// Read file

    std::ifstream read_file("example.bin", std::ios::binary);

    if (!read_file.is_open())
    {
        throw std::runtime_error("File can't be opened");
    }

    constexpr std::size_t buffer_size = 500;
    char buffer[buffer_size];

    read_file.read(buffer, buffer_size);

    std::streamsize bytes_read = read_file.gcount();

    std::string result(buffer, static_cast<std::size_t>(bytes_read));

    // Reset stream flags after reaching EOF
    read_file.clear();

    // Move cursor 10 bytes from beginning of file
    read_file.seekg(10, std::ios::beg);

    // Get cursor position
    std::streampos cursor_position = read_file.tellg();

    read_file.close();
}