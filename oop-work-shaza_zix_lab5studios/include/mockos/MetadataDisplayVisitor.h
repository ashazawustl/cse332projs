#ifndef METADATA_DISPLAY_VISITOR_H
#define METADATA_DISPLAY_VISITOR_H

#include "AbstractFileVisitor.h"
#include "AbstractCommand.h"
#include <iostream>

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
    void visit_TextFile(TextFile* file) ;
    void visit_ImageFile(ImageFile* file) ;
};

enum
{
    file_type_max_length = 10
};

#endif // METADATA_DISPLAY_VISITOR_H
