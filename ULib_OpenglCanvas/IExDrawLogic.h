#pragma once

#include "stdafx.h"

/************************************************************************/
/*
����˵���������߼���ʵ�ָýӿڣ���ҳ�����ǡ����ʱ��ִ����
*/
/************************************************************************/
interface IExDrawLogic
{
public:
	HRESULT virtual Init(IN int canvasWidth, IN int canvasHeight) = 0;
	HRESULT virtual UnInit() = 0;
	HRESULT virtual RenderFrame() = 0;
};
