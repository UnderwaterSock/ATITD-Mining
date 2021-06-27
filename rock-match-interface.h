#ifndef ROCKMATCH_INTERFACE_H
#define ROCKMATCH_INTERFACE_H
#include <vector>
#include "rock-types.h"

class rockmatch_interface {
 public:
    virtual ~rockmatch_interface() = 0;
    virtual bool add_rock(rockdata new_rock);
    virtual long unsigned int rock_count();
    virtual std::vector<int> rock_positions();
    virtual void remove_back();
};

#endif
