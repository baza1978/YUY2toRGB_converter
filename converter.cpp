//convert YUY2 format(ptrIn) stream to RGB stream (ptrOut)
//sz - image size (height*width)
void convertYUY2toRGB(const unsigned char * ptrIn,  unsigned char *ptrOut, int sz){

    for (int i = 0;  i < sz/2;  ++i)
    {
        int y0 = ptrIn[0];
        int u0 = ptrIn[1];
        int y1 = ptrIn[2];
        int v0 = ptrIn[3];
        ptrIn += 4;
        int c = y0 - 16;
        int d = u0 - 128;
        int e = v0 - 128;
        ptrOut[0] = min(( 298 * c + 516 * d + 128) /256,255); // blue
        ptrOut[1] = min(( 298 * c - 100 * d - 208 * e + 128) /256,255); // green
        ptrOut[2] = min(( 298 * c + 409 * e + 128)/256,255); // red
        c = y1 - 16;
        ptrOut[3] = min(( 298 * c + 516 * d + 128) /256,255); // blue
        ptrOut[4] = min(( 298 * c - 100 * d - 208 * e + 128) /256,255); // green
        ptrOut[5] = min(( 298 * c + 409 * e + 128) /256,255); // red
        ptrOut += 6;

    }

}
