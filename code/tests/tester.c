#define UNIT_MAX_MODULES 1
#include "unit.h"

/* TEST CATEGORIES */
#include "cases/sample.h"

int main() {
    UNIT_CREATE("skeleton");

    UNIT_MODULE(sample);

    int32_t ret_code = UNIT_RUN();
    return ret_code;
}
