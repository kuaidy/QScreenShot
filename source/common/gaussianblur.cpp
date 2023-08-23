#include "../../include/common/gaussianblur.h"

GaussianBlur::GaussianBlur()
{

}
//优化的高斯模糊算法,一维做两次计算
QImage GaussianBlur::ApplyGaussianBlur(const QImage &source,int radius){
    //典型高斯核
    //int kernel[5]={1,4,6,4,1};
    //计算指定半径上的权重分布
    const double sqrt2pi=sqrt(2.0*M_PI);
    double sigma=radius/3.0;
    double sigma2=2.0*sigma*sigma;
    double sigmap=sigma*sqrt2pi;
    std::vector<double> kernel;
    for (int i = -radius; i <=radius; ++i) {
        double res=exp(-(double)(i*i)/sigma2)/sigmap;
        kernel.push_back(res);
    }
    //归一化处理
    double sum=0;
    for (int n = 0; n < sizeof(kernel)/sizeof(int); ++n) {
        sum+=kernel[n];
    }
    QImage image=source.copy();
    if(abs(sum-1.0)<0.000001) return image;
    for (int n = 0; n < sizeof(kernel)/sizeof(int); ++n) {
        kernel[n]=kernel[n]/sum;
    }
    //y轴方向模糊
    for (int x = 0; x < image.width(); ++x) {
        for (int y = 0; y < image.height(); ++y) {
            int r=0,g=0,b=0;
            for (double nearPos = -radius; nearPos <= radius; ++nearPos) {
                //x轴方向
                double pos;
                if(y+nearPos<0){
                    pos=0;
                }else if(y+nearPos>image.height()){
                    pos=image.height();
                }else {
                    pos=y+nearPos;
                }

                //y轴方向
                QRgb colory=source.pixel(x,pos);
                r+=qRed(colory)*kernel[radius+nearPos];
                g+=qGreen(colory)*kernel[radius+nearPos];
                b+=qBlue(colory)*kernel[radius+nearPos];
            }
            image.setPixel(x,y,qRgb(r,g,b));
        }
    }
    //x轴方向模糊
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            int r=0,g=0,b=0;
            for (double nearPos = -radius; nearPos <= radius; ++nearPos) {
                //x轴方向
                double pos;
                if(x+nearPos<0){
                    pos=0;
                }else if(x+nearPos>image.width()){
                    pos=image.width();
                }else {
                    pos=x+nearPos;
                }

                //y轴方向
                QRgb colory=source.pixel(pos,y);
                r+=qRed(colory)*kernel[radius+nearPos];
                g+=qGreen(colory)*kernel[radius+nearPos];
                b+=qBlue(colory)*kernel[radius+nearPos];
            }
            image.setPixel(x,y,qRgb(r,g,b));
        }
    }
    return image;
}
