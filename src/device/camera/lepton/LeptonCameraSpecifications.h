//
// Created by Derek Lun on 5/23/2015.
//

#ifndef OBSTACLE_AVOIDANCE_LEPTONCAMERADIMENSIONS_H
#define OBSTACLE_AVOIDANCE_LEPTONCAMERADIMENSIONS_H

#include <camera/ICameraSpecifications.h>


/**
 * A global variable representing the camera constants for the Lepton.
 */
static const ICameraSpecifications LeptonCameraSpecifications = {
    60,  // pixelHeight
    80,  // pixelWidth
    37,  // FOVDegreesVertical
    51   // FOVDegreesHorizontal
};

#endif //OBSTACLE_AVOIDANCE_LEPTONCAMERADIMENSIONS_H
