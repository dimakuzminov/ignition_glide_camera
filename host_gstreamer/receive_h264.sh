#!/bin/sh
VIDEO_UDP_PORT=9978

gst-launch-0.10 --gst-debug-level=1 udpsrc  port=$VIDEO_UDP_PORT caps='application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=(string)H264' ! \
rtph264depay ! \
ffdec_h264 ! \
ffmpegcolorspace ! \
videoscale ! \
ffmpegcolorspace ! \
ximagesink sync=false
