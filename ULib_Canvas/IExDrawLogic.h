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
	HRESULT virtual Initialize(IN CONST CHAR *device, IN int canvasWidth, IN int canvasHeight) = 0;
	HRESULT virtual Release() = 0;
	HRESULT virtual RenderFrame() = 0;
};
