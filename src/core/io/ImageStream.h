//
// Created by paul on 09/02/16.
//

#ifndef OBSTACLE_DETECTION_IMAGESTREAM_H
#define OBSTACLE_DETECTION_IMAGESTREAM_H

#include "types/Image16bit.h"

/**
 * DEPRECATED
 *
 * Represents a stream of images of a constant size that can
 *  come from a file system, from a database, or live from a camera.
 */
class ImageStream {

public:

    /**
     * Returns the next image in this stream as soon as it is
     *  available. If the image is coming from an I/O operation, this
     *  call may block until the I/O operation in this stream completes.
     *
     * @return A new image. If this function is called twice within the
     *  refresh period of the stream, rather than return the same image
     *  twice, the stream should block until it can produce a new, updated
     *  image.
     *
     * @throws EndOfStreamException - if called when hasNext() == false.
     */
    virtual Image16bit nextImage() = 0;

    /**
     * @return Whether there remain any images in this stream.
     */
    virtual bool hasNext() const = 0;

    /**
     * Should always return the same value.
     * @return The width of the images produced by this image stream, in pixels.
     */
    virtual int getImageWidth() const = 0;

    /**
     * Should always return the same value.
     * @return The height of the images produced by this image stream, in pixels.
     */
    virtual int getImageHeight() const = 0;

};

#endif //OBSTACLE_DETECTION_IMAGESTREAM_H
