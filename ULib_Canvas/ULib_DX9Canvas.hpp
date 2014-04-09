#pragma once
#include "stdafx.h"
#include "ULib_BaseCanvas.hpp"

#ifdef DIRECT3D_VERSION
#if 0x0900 == DIRECT3D_VERSION
class ULib_DX9Canvas :
	public ULib_BaseCanvas
{
public:
	ULib_DX9Canvas(void){}
	virtual ~ULib_DX9Canvas(void){}
#pragma region Override IExCanvas
	HRESULT virtual Update()
	{
		if (S_OK == this->ULib_BaseCanvas::Update() /*�˴�����̬�� etc.*/)
		{
			switch (m_typWrkMod)
			{
			case DataOutput:
				{
					//TODO.
					return S_OK;
				}
			case DataInput:
				{
					LPDIRECT3DDEVICE9 pDx9Device = GutGetGraphicsDeviceDX9();
					if (pDx9Device)
					{
						//����һ����Ⱦ���� 
						IDirect3DSurface9* pSurface; 
						//�˴�������OpenGL��ͬ, ����Pixle����Ϊһ��DWORD,����BYTE,�ʺ궨��ʹ��ARGB���ײ��ֽ�����С�˴��ΪB,G,R,A, ��Ȼ��OpenGL��ͬ(Win32ƽ̨��)
						pDx9Device->CreateOffscreenPlainSurface(m_canvasWidth, m_canvasHeight, (D3DFORMAT)m_dataFormat, D3DPOOL_DEFAULT, &pSurface,0);

						//��д��
						D3DLOCKED_RECT rc;  
						memset(&rc,0,sizeof(rc));  
						pSurface->LockRect(&rc,NULL,D3DLOCK_DISCARD); 

						DWORD* pBits = (DWORD*)rc.pBits;
						memcpy(pBits, m_pTargetTexturePixels, m_canvasWidth * m_canvasHeight * sizeof(DWORD));

						//�ͷ�д��
						pSurface->UnlockRect();
						//��ȡD3DĬ�Ͻ������еĺ�̨���� 
						IDirect3DSurface9* backBuffer = 0; 
						pDx9Device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer); 
						//ʹ���Զ�����Ⱦ��������̨���� 
						pDx9Device->StretchRect(pSurface, 0, backBuffer, 0, D3DTEXF_NONE); 
						//GetBackBuffer���õĻ�����Ҫ���ͷ� 
						backBuffer->Release(); 

						pDx9Device->Present(NULL, NULL, NULL, NULL);
						return S_OK;
					}else
					{
						return E_FAIL;
					}
				}
			default:
				{
					return E_FAIL;
				}
			}
		}else
		{
			return E_FAIL;
		}
	}
#pragma endregion Override IExCanvas
};
#endif
#endif
