// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>
#include <timeapi.h>

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "TCHAR.H"
#include <iostream>
using namespace std;

// �궨��
 #define  _CRT_SECURE_NO_WARNINGS
#if WIN32
	#define interface __interface
#else
	#define interface class
#endif
