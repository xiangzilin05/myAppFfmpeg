//
//  testC.c
//  myApp
//
//  Created by 林祥辉 on 2020/4/19.
//  Copyright © 2020 林祥辉. All rights reserved.
//

#include "testC.h"

void haha(){
    printf("this is a C function\n");
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL, AV_LOG_DEBUG, "hello av log\n");
    
    AVFormatContext *fmt_ctx = NULL;
    char *deviceName = ":0";
    AVDictionary *options = NULL;
    
    avdevice_register_all();
    AVInputFormat *iformat =av_find_input_format("avfoundation");
    int ret = avformat_open_input(&fmt_ctx, deviceName, iformat,  &options);
    
    char errors[1024];
    if (ret < 0) {
        av_strerror(ret, errors, 1024);
        printf(stderr, "Failed to open audio device, [%d] %s\n", ret, errors);
        return;
    }
    
    AVPacket pkt;
    av_init_packet(&pkt);
    int count = 0;
    while ((ret =av_read_frame(fmt_ctx, &pkt)
            && count++ < 500) == 0) {
        printf("pkt size is %d\n", pkt.size);
    }
    av_packet_unref(&pkt);
    
    return;
}
