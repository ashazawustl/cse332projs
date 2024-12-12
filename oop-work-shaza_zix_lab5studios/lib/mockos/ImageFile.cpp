#include "mockos/ImageFile.h"
#include "mockos/AbstractFileVisitor.h"

using namespace std;

ImageFile::ImageFile(string file_name) : file_name(file_name), file_contents(), image_size('0')
{

}

unsigned int ImageFile::getSize()
{
    return file_contents.size();
}

string ImageFile::getName()
{
    return file_name;
}

int ImageFile::write(vector<char> new_contents)
{
    const char zero_char = '0';
    // check if new_contents is empty
    if (new_contents.empty())
    {
        return empty_content;
    }

    // check the size char located in the last element
    char last_char = new_contents.back();
    int converted_ascii_value = static_cast<int>(last_char) - ascii_of_zero;
    if (converted_ascii_value < 0 || converted_ascii_value > 9)
    {
        return invalid_size_char;
    }
    // size char is valid from here

    file_contents.clear();
    this->image_size = last_char;

    unsigned int pixels_added = 0;
    for (int i = 0; i < new_contents.size() - 1; ++i)
    {
        char pixel = new_contents[i];
        if (pixel != 'X' && pixel != ' ')
        {
            file_contents.clear();
            this->image_size = zero_char;
            return invalid_pixel;
        }
        file_contents.push_back(pixel);
        pixels_added++;
    }

    if (sqrt(pixels_added) != converted_ascii_value)
    {
        file_contents.clear();
        this->image_size = zero_char;
        //cout << "pixels_added: " << pixels_added << endl;
        //cout << "converted_ascii_value: " << converted_ascii_value << endl;

        return write_content_size_mismatch;
    }

    return write_success;
}

int ImageFile::append(vector<char> new_contents)
{
    return unsupported_operation;
}

int ImageFile::convertToIndex(unsigned int x, unsigned int y, const unsigned int size)
{
    return y * size + x;
}

vector<char> ImageFile::read()
{
    //commented to demonstrate previous studio use: prior to the implementation of the AbstractFileVisitor system, the reading needed to take place manually through this function, hence the presence of the converttoIndex above
    // const unsigned int size_int = static_cast<unsigned int>(this -> image_size) - ascii_of_zero;
    // if (size_int == 0) // file is empty
    // {
    //     return;
    // }
    // for (int y = size_int - 1; y >= beginning_index; --y)
    // {
    //     for (int x = beginning_index; x < size_int; ++x)
    //     {
    //         int index = convertToIndex(x, y, size_int);
    //         cout << file_contents[index] << " ";
    //     }
    //     cout << endl;
    // }
    return this->file_contents;
}

void ImageFile::accept(AbstractFileVisitor* visitor)
{
    if (visitor != nullptr) {
        visitor -> visit_ImageFile(this);
    } else {
        throw empty_visitor_pointer;
    }
}

//clone method for the prototype pattern
AbstractFile* ImageFile::clone(string newName) {
    ImageFile* copy = new ImageFile(newName);
    copy->write(this->file_contents); //copy content
    return copy;
}

ImageFile::~ImageFile()
{
}
