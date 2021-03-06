--- plugins/ffmpeg/ffmpeg.c.orig	2014-01-28 01:24:09.000000000 +0400
+++ plugins/ffmpeg/ffmpeg.c	2014-02-23 16:32:57.108250350 +0400
@@ -26,20 +26,11 @@
 #include "../../deadbeef.h"
 #include "../../strdupa.h"
 
-#if !FFMPEG_OLD
-
 #include <libavformat/avformat.h>
 #include <libavcodec/avcodec.h>
 #include <libavutil/avutil.h>
 #include <libavutil/avstring.h>
 
-#else
-
-#include <ffmpeg/avformat.h>
-#include <ffmpeg/avcodec.h>
-#include <ffmpeg/avutil.h>
-#include <ffmpeg/avstring.h>
-
 #define AVERROR_EOF AVERROR(EPIPE)
 
 #if LIBAVFORMAT_VERSION_MAJOR < 53
@@ -50,8 +41,6 @@
 #define AV_VERSION_INT(a, b, c) (a<<16 | b<<8 | c)
 #endif
 
-#endif
-
 #if LIBAVFORMAT_VERSION_INT >= AV_VERSION_INT(54, 6, 0)
 #define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000
 #define av_find_stream_info(ctx) avformat_find_stream_info(ctx,NULL)
@@ -239,7 +228,7 @@ ffmpeg_init (DB_fileinfo_t *_info, DB_pl
     _info->fmt.bps = bps;
     _info->fmt.channels = info->ctx->channels;
     _info->fmt.samplerate = samplerate;
-    if (info->ctx->sample_fmt == AV_SAMPLE_FMT_FLT || info->ctx->sample_fmt == AV_SAMPLE_FMT_FLTP) {
+    if (info->ctx->sample_fmt == AV_SAMPLE_FMT_FLT) {
         _info->fmt.is_float = 1;
     }
 
@@ -307,7 +296,7 @@ ffmpeg_read (DB_fileinfo_t *_info, char 
     _info->fmt.channels = info->ctx->channels;
     _info->fmt.samplerate = info->ctx->sample_rate;
     _info->fmt.bps = av_get_bits_per_sample_format (info->ctx->sample_fmt);
-    _info->fmt.is_float = (info->ctx->sample_fmt == AV_SAMPLE_FMT_FLT || info->ctx->sample_fmt == AV_SAMPLE_FMT_FLTP);
+    _info->fmt.is_float = (info->ctx->sample_fmt == AV_SAMPLE_FMT_FLT);
 
     int samplesize = _info->fmt.channels * _info->fmt.bps / 8;
 
