#ifndef BASICDISPLAYVISITOR_H
#define BASICDISPLAYVISITOR_H


#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
private:
    bool unformatted;
public:
    BasicDisplayVisitor(bool unformatted = false);
    virtual void visit_TextFile(TextFile* file) ;
    virtual void visit_ImageFile(ImageFile* file) ;
};

#endif //BASICDISPLAYVISITOR_H