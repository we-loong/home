#include "stdafx.h"
#include "CResourceImg.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

CResourceImg::CResourceImg()
	: m_pImageData( NULL )
{
}

CResourceImg::CResourceImg( const byte* szBuffer, const uint32 nSize )
{
	InitImageData( szBuffer, nSize );
}

CResourceImg::~CResourceImg()
{
	stbi_image_free( m_pImageData );
	m_pImageData = NULL;
}

void CResourceImg::InitImageData( const byte * szBuffer, const uint32 nSize )
{
	int32 nWidth, nHeight, nrChannels;
	m_pImageData = (byte*)stbi_load_from_memory( szBuffer, nSize, &nWidth, &nHeight, &nrChannels, 0 );
	m_nWidth = (uint32)nWidth;
	m_nHeight = (uint32)nHeight;
	switch( nrChannels )
	{
	case 1:
		m_nFormat = eIF_RED;
		break;
	case 3:
		m_nFormat = eIF_RGB;
		break;
	case 4:
		m_nFormat = eIF_RGBA;
		break;
	}
}

void CResourceImg::OnFileLoaded( const char* szFileName, const byte * szBuffer, uint32 nSize)
{
	InitImageData( szBuffer, nSize );
}
