#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include <QImage>
#include <cmath>
#include <vector>

class GaussianBlur
{
public:
    GaussianBlur();
    //优化的高斯模糊算法
    QImage ApplyGaussianBlur(const QImage &source,int radius);
};

#endif // GAUSSIANBLUR_H
