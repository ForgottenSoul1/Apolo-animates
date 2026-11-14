//
// Created by serba on 11/14/2026.
//

#ifndef APOLO_ANIMATES_COMPUTATION_NODE_H
#define APOLO_ANIMATES_COMPUTATION_NODE_H
#include "raster_canvas.h"

typedef struct ComputationNode {
    private:

    RasterCanvas output;
    size_t numberInputs;
    struct ComputationNodes * inputs;
    size_t numberInputs;
    struct ComputationNodes * inputs;


    private:


} ComputationNode;


#endif //APOLO_ANIMATES_COMPUTATION_NODE_H
