#!/bin/sh

host=$1
gst-launch-0.10 --gst-debug-level=1 v4l2src device=/dev/video0 ! \
    ffmpegcolorspace !\
    videoscale ! \
    videorate ! \
    vpuenc codec=6 ! \
rtph264pay ! \
    udpsink host=${host} port=9978
