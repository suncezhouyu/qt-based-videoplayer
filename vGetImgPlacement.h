#pragma once
/*窗口-图像 宽高比 的 比较
  假如窗口的宽高比 大于 图像的 宽高比,那么
  图像上下顶住窗口,但左右不接触窗口(函数返回true）
  反之，图像顶住窗口的左右两侧，但不接触窗口上下（函数返回 false）*/
bool bWidgetImg_WidthHeightRatio_Comparison(int, int, int, int);

/*把SAR图像嵌入窗口内，
  这个函数获取SAR图像嵌入后，在窗口的位置*/
void vGetImgPlacement(int,int,int,int,int &,int &,int &,int &);