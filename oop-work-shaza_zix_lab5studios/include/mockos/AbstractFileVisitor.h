#ifndef ABSTRACTFILEVISITOR_H
#define ABSTRACTFILEVISITOR_H
#include "TextFile.h"
#include "ImageFile.h"

class AbstractFileVisitor
{
 public:
//general functions for visiting image and text files
 virtual void visit_TextFile(TextFile * text_file) = 0;
 virtual void visit_ImageFile(ImageFile * image_file) = 0;

 virtual ~AbstractFileVisitor() = 0;

};

#endif //ABSTRACTFILEVISITOR_H