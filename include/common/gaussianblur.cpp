#include "gaussianblur.h"

GaussianBlur::GaussianBlur()
{

}
//优化的高斯模糊算法
QImage GaussianBlur::ApplyGaussianBlur(const QImage &source,int minx,int miny,int maxx,int maxy){
    //一维空间的典型高斯核
    constexpr int kernel[5]={1,4,6,4,1};
    //
    constexpr int radius=sizeof(kernel)/sizeof(int)/2;
    int totalWeight=0;
    for (int weight:kernel) {
        totalWeight+=weight;
    }
    //x轴和y轴两个方向的高斯核，总权重需要乘以2
    totalWeight*=2;

    QImage image=source.copy();

    for (int x = minx; x < maxx; ++x) {
        for (int y = miny; y < maxy; ++y) {
            int r=0,g=0,b=0;
            for (int nearPos = -radius; nearPos < radius; ++nearPos) {
                //x轴方向
                QRgb colorx=source.pixel(x+nearPos,y);
                r+=qRed(colorx)*kernel[radius+nearPos];
                g+=qGreen(colorx)*kernel[radius+nearPos];
                b+=qBlue(colorx)*kernel[radius+nearPos];
                //y轴方向
                QRgb colory=source.pixel(x,y+nearPos);
                r+=qRed(colory)*kernel[radius+nearPos];
                g+=qGreen(colory)*kernel[radius+nearPos];
                b+=qBlue(colory)*kernel[radius+nearPos];
            }
            image.setPixel(x,y,qRgb(r/totalWeight,g/totalWeight,b/totalWeight));
        }
    }
    return image;
}
