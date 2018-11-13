#include "vGetImgPlacement.h"
#include <math.h>

bool bWidgetImg_WidthHeightRatio_Comparison(int iWidgetWidth, int iWidgetHeight, int iImgWidth, int iImgHeight)
{
	float fWidgetRatio = float(iWidgetWidth) / iWidgetHeight;
	float fImgRatio = float(iImgWidth) / iImgHeight;

	if(fWidgetRatio > fImgRatio)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void vGetImgPlacement(int iWidgetWidth,int iWidgetHeight,int iImgWidth,int iImgHeight,
	int & iLeftPos,int & iTopPos, int & iNewImgWidth, int & iNewImgHeight)
{
	if(bWidgetImg_WidthHeightRatio_Comparison(iWidgetWidth, iWidgetHeight, iImgWidth, iImgHeight))
	{
		//ͼ�����š�����ͼ��ʹͼ��ĸ��봰�ڵĸ���ȣ���ͼ��Ŀ�Ҳ��������
		double dZoom = double(iWidgetHeight) / double(iImgHeight);
		iNewImgWidth = dZoom * iImgWidth;
		iLeftPos = abs(iWidgetWidth - iNewImgWidth)/2;
		iTopPos = 0;
		iNewImgHeight = iWidgetHeight;
	}
	else
	{
		//ͼ����
		double dZoom = double(iWidgetWidth) / double(iImgWidth);
		iNewImgHeight = dZoom * iImgHeight;
		iLeftPos = 0;
		iTopPos = abs(iWidgetHeight - iNewImgHeight)/2;
		iNewImgWidth = iWidgetWidth;
	}
}