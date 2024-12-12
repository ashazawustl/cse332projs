#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
    string file_name = file->getName();
    cout << file_name;
    for (int i = 0; i < max_file_name_length - file_name.length(); i++)
    {
        cout << " ";
    }
    string file_type = "text";
    cout << file_type;
    for (int i = 0; i < file_type_max_length - file_type.length(); i++)
    {
        cout << " ";
    }
    cout << file->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
    string file_name = file->getName();
    cout << file_name;
    for (int i = 0; i < max_file_name_length - file_name.length(); i++)
    {
        cout << " ";
    }
    string file_type = "image";
    cout << file_type;
    for (int i = 0; i < file_type_max_length - file_type.length(); i++)
    {
        cout << " ";
    }
    cout << file->getSize() << endl;
}
