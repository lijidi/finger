// CZKFPEngX.h  : Declaration of ActiveX Control wrapper class(es) created by Microsoft Visual C++

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CZKFPEngX

class CZKFPEngX : public CWnd
{
protected:
	DECLARE_DYNCREATE(CZKFPEngX)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xCA69969C, 0x2F27, 0x41D3, { 0x95, 0x4D, 0xA4, 0x8B, 0x94, 0x1C, 0x3B, 0xA7 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// Attributes
public:

// Operations
public:

	long get_EnrollCount()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_EnrollCount(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL VerFinger(VARIANT * regTemplate, VARIANT verTemplate, BOOL ADoLearning, BOOL * ARegFeatureChanged)
	{
		BOOL result;
		static BYTE parms[] = VTS_PVARIANT VTS_VARIANT VTS_BOOL VTS_PBOOL ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, regTemplate, &verTemplate, ADoLearning, ARegFeatureChanged);
		return result;
	}
	BOOL VerRegFingerFile(LPCTSTR regTemplateFile, VARIANT verTemplate, BOOL ADoLearning, BOOL * ARegFeatureChanged)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_BOOL VTS_PBOOL ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, regTemplateFile, &verTemplate, ADoLearning, ARegFeatureChanged);
		return result;
	}
	void PrintImageAt(long hdc, long x, long y, long aWidth, long aHeight)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, hdc, x, y, aWidth, aHeight);
	}
	void PrintImageEllipseAt(long hdc, long x, long y, long aWidth, long aHeight, unsigned long bkColor)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_UI4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, hdc, x, y, aWidth, aHeight, bkColor);
	}
	void BeginEnroll()
	{
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL SaveTemplate(LPCTSTR FileName, VARIANT ATemplate)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FileName, &ATemplate);
		return result;
	}
	void SaveBitmap(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	void SaveJPG(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	long InitEngine()
	{
		long result;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_SensorIndex()
	{
		long result;
		InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_SensorIndex(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x25, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void CancelEnroll()
	{
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long CreateFPCacheDB()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void FreeFPCacheDB(long fpcHandle)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, fpcHandle);
	}
	long AddRegTemplateToFPCacheDB(long fpcHandle, long FPID, VARIANT pRegTemplate)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_VARIANT ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, FPID, &pRegTemplate);
		return result;
	}
	long RemoveRegTemplateFromFPCacheDB(long fpcHandle, long FPID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, FPID);
		return result;
	}
	long AddRegTemplateFileToFPCacheDB(long fpcHandle, long FPID, LPCTSTR pRegTemplateFile)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, FPID, pRegTemplateFile);
		return result;
	}
	long get_Threshold()
	{
		long result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Threshold(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL DongleIsExist()
	{
		BOOL result;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long DongleUserID()
	{
		long result;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL DongleSeed(long * lp2, long * p1, long * p2, long * p3, long * p4)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, lp2, p1, p2, p3, p4);
		return result;
	}
	BOOL DongleMemRead(long * p1, long * p2, VARIANT * buf)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PVARIANT ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, p1, p2, buf);
		return result;
	}
	BOOL DongleMemWrite(long * p1, long * p2, VARIANT * buf)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PVARIANT ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, p1, p2, buf);
		return result;
	}
	BOOL VerFingerFromFile(LPCTSTR regTemplateFile, LPCTSTR verTemplateFile, BOOL ADoLearning, BOOL * ARegFeatureChanged)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BOOL VTS_PBOOL ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, regTemplateFile, verTemplateFile, ADoLearning, ARegFeatureChanged);
		return result;
	}
	CString get_VerTplFileName()
	{
		CString result;
		InvokeHelper(0x2b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_VerTplFileName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_RegTplFileName()
	{
		CString result;
		InvokeHelper(0x2c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_RegTplFileName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT GetTemplate()
	{
		VARIANT result;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	BOOL GetFingerImage(VARIANT * AFingerImage)
	{
		BOOL result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, AFingerImage);
		return result;
	}
	long get_OneToOneThreshold()
	{
		long result;
		InvokeHelper(0x31, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_OneToOneThreshold(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x31, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL IsOneToOneTemplate(VARIANT ATemplate)
	{
		BOOL result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, &ATemplate);
		return result;
	}
	void ModifyTemplate(VARIANT * ATemplate, BOOL AOneToOne)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_BOOL ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ATemplate, AOneToOne);
	}
	void FlushFPImages()
	{
		InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_Active()
	{
		BOOL result;
		InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Active(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x20, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_IsRegister()
	{
		BOOL result;
		InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IsRegister(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x28, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_EnrollIndex()
	{
		long result;
		InvokeHelper(0x2f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_EnrollIndex(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_SensorSN()
	{
		CString result;
		InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_SensorSN(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x32, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_FPEngineVersion()
	{
		CString result;
		InvokeHelper(0x33, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_FPEngineVersion(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x33, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ImageWidth()
	{
		long result;
		InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ImageWidth(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x34, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ImageHeight()
	{
		long result;
		InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ImageHeight(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x35, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_SensorCount()
	{
		long result;
		InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_SensorCount(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x36, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_TemplateLen()
	{
		long result;
		InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_TemplateLen(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x37, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_EngineValid()
	{
		BOOL result;
		InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_EngineValid(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x38, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL DecodeTemplate(LPCTSTR ASour, VARIANT * ADest)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ASour, ADest);
		return result;
	}
	BOOL EncodeTemplate(VARIANT ASour, BSTR * ADest)
	{
		BOOL result;
		static BYTE parms[] = VTS_VARIANT VTS_PBSTR ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, &ASour, ADest);
		return result;
	}
	void BeginCapture()
	{
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void CancelCapture()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void EndEngine()
	{
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	VARIANT DecodeTemplate1(LPCTSTR ASour)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, ASour);
		return result;
	}
	CString EncodeTemplate1(VARIANT ASour)
	{
		CString result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, &ASour);
		return result;
	}
	long AddRegTemplateStrToFPCacheDB(long fpcHandle, long FPID, LPCTSTR ARegTemplateStr)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, FPID, ARegTemplateStr);
		return result;
	}
	BOOL VerFingerFromStr(BSTR * regTemplateStr, LPCTSTR verTemplateStr, BOOL ADoLearning, BOOL * ARegFeatureChanged)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR VTS_BSTR VTS_BOOL VTS_PBOOL ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, regTemplateStr, verTemplateStr, ADoLearning, ARegFeatureChanged);
		return result;
	}
	CString GetTemplateAsString()
	{
		CString result;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL IsOneToOneTemplateStr(LPCTSTR ATemplate)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ATemplate);
		return result;
	}
	void ModifyTemplateStr(BSTR * ATemplate, BOOL AOneToOne)
	{
		static BYTE parms[] = VTS_PBSTR VTS_BOOL ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ATemplate, AOneToOne);
	}
	void SaveTemplateStr(LPCTSTR FileName, LPCTSTR ATemplateStr)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName, ATemplateStr);
	}
	void GetTemplateCount(long AFPHandle, long * AOneToOneCnt, long * ATotalCnt)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AFPHandle, AOneToOneCnt, ATotalCnt);
	}
	long IdentificationInFPCacheDB(long fpcHandle, VARIANT pVerTemplate, long * Score, long * ProcessedFPNumber)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, &pVerTemplate, Score, ProcessedFPNumber);
		return result;
	}
	long IdentificationFromFileInFPCacheDB(long fpcHandle, LPCTSTR pVerTemplateFile, long * Score, long * ProcessedFPNumber)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, pVerTemplateFile, Score, ProcessedFPNumber);
		return result;
	}
	long IdentificationFromStrInFPCacheDB(long fpcHandle, LPCTSTR AVerTemplateStr, long * Score, long * ProcessedFPNumber)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, AVerTemplateStr, Score, ProcessedFPNumber);
		return result;
	}
	void SetAutoIdentifyPara(BOOL AAutoIdentify, long ACacheDBHandle, long AScore)
	{
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_I4 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AAutoIdentify, ACacheDBHandle, AScore);
	}
	void SetImageDirection(BOOL AIsImageChange)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AIsImageChange);
	}
	BOOL IsOneToOneTemplateFile(LPCTSTR ATemplateFileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ATemplateFileName);
		return result;
	}
	void ModifyTemplateFile(LPCTSTR ATemplateFileName, BOOL AOneToOne)
	{
		static BYTE parms[] = VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ATemplateFileName, AOneToOne);
	}
	VARIANT GetVerTemplate()
	{
		VARIANT result;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	long GetVerScore()
	{
		long result;
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL AddImageFile(LPCTSTR AFileName, long ADPI)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, AFileName, ADPI);
		return result;
	}
	void SetOneToOnePara(long ADoLearning, long AMatchSecurity)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ADoLearning, AMatchSecurity);
	}
	VARIANT CompressTemplate(LPCTSTR ATemplate)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, ATemplate);
		return result;
	}
	VARIANT ConvertAttTemplate(VARIANT ATemplate)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &ATemplate);
		return result;
	}
	BOOL get_ForceSecondMatch()
	{
		BOOL result;
		InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ForceSecondMatch(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x47, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL AddBitmap(long BitmapHandle, long ValidRectX1, long ValidRectY1, long ValidRectX2, long ValidRectY2, long DPI)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, BitmapHandle, ValidRectX1, ValidRectY1, ValidRectX2, ValidRectY2, DPI);
		return result;
	}
	void UsingXTFTemplate(BOOL ADoUsingXTFTemplate)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ADoUsingXTFTemplate);
	}
	long ExtractImageFromURU4000(LPSTR AOriImageBuf, long Size, BOOL AAutoIdentify, VARIANT * iResult)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN VTS_I4 VTS_BOOL VTS_PVARIANT ;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AOriImageBuf, Size, AAutoIdentify, iResult);
		return result;
	}
	VARIANT ConvertToBiokey(VARIANT OriTemplate)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &OriTemplate);
		return result;
	}
	BOOL GenRegTemplateAsStringFromFile(LPCTSTR AImageFileName, long ADPI, BSTR * ADest)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, AImageFileName, ADPI, ADest);
		return result;
	}
	BOOL GenVerTemplateAsStringFromFile(LPCTSTR AImageFileName, long ADPI, BSTR * ADest)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, AImageFileName, ADPI, ADest);
		return result;
	}
	long ExtractImageFromURU(LPCTSTR AOriImageStr, long Size, BOOL AAutoIdentify, VARIANT * iResult)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BOOL VTS_PVARIANT ;
		InvokeHelper(0x2b3, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AOriImageStr, Size, AAutoIdentify, iResult);
		return result;
	}
	CString get_Vendor()
	{
		CString result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ProduceName()
	{
		CString result;
		InvokeHelper(0xcf, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long SetTemplateLen(VARIANT * ATemplate, long ALen)
	{
		long result;
		static BYTE parms[] = VTS_PVARIANT VTS_I4 ;
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ATemplate, ALen);
		return result;
	}
	long ControlSensor(long ACode, long AValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xd1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ACode, AValue);
		return result;
	}
	long get_IsSupportAuxDevice()
	{
		long result;
		InvokeHelper(0xd2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long ExtractImageFromTerminal(VARIANT AOriImage, long Size, BOOL AAutoIdentify, VARIANT * iResult)
	{
		long result;
		static BYTE parms[] = VTS_VARIANT VTS_I4 VTS_BOOL VTS_PVARIANT ;
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_I4, (void*)&result, parms, &AOriImage, Size, AAutoIdentify, iResult);
		return result;
	}
	long CreateFPCacheDBEx()
	{
		long result;
		InvokeHelper(0xd4, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void FreeFPCacheDBEx(long fpcHandle)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, fpcHandle);
	}
	long AddRegTemplateToFPCacheDBEx(long fpcHandle, long FPID, VARIANT pRegTemplate, VARIANT pRegTemplate10)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, FPID, &pRegTemplate, &pRegTemplate10);
		return result;
	}
	long RemoveRegTemplateFromFPCacheDBEx(long fpcHandle, long FPID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xd7, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, FPID);
		return result;
	}
	long AddRegTemplateFileToFPCacheDBEx(long fpcHandle, long FPID, LPCTSTR pRegTemplateFile, LPCTSTR pRegTemplate10File)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xd8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, FPID, pRegTemplateFile, pRegTemplate10File);
		return result;
	}
	VARIANT GetTemplateEx(LPCTSTR AFPEngineVersion)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xd9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, AFPEngineVersion);
		return result;
	}
	long AddRegTemplateStrToFPCacheDBEx(long fpcHandle, long FPID, LPCTSTR ARegTemplateStr, LPCTSTR ARegTemplate10Str)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xda, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fpcHandle, FPID, ARegTemplateStr, ARegTemplate10Str);
		return result;
	}
	CString GetTemplateAsStringEx(LPCTSTR AFPEngineVersion)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xdb, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, AFPEngineVersion);
		return result;
	}
	VARIANT GetVerTemplateEx(LPCTSTR AFPEngineVersion)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xdc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, AFPEngineVersion);
		return result;
	}
	BOOL MF_GET_SNR(long commHandle, long DeviceAddress, unsigned char mode, unsigned char RDM_halt, unsigned char * snr, unsigned char * Value)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_UI1 VTS_UI1 VTS_PUI1 VTS_PUI1 ;
		InvokeHelper(0xdd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, commHandle, DeviceAddress, mode, RDM_halt, snr, Value);
		return result;
	}
	BOOL MF_GetSerNum(long commHandle, long DeviceAddress, unsigned char * buffer)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PUI1 ;
		InvokeHelper(0xde, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, commHandle, DeviceAddress, buffer);
		return result;
	}
	BOOL MF_SetSerNum(long commHandle, long DeviceAddress, unsigned char * newValue, unsigned char * buffer)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PUI1 VTS_PUI1 ;
		InvokeHelper(0xdf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, commHandle, DeviceAddress, newValue, buffer);
		return result;
	}
	BOOL MF_GetVersionNum(long commHandle, long DeviceAddress, unsigned char * VersionNum)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PUI1 ;
		InvokeHelper(0xe0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, commHandle, DeviceAddress, VersionNum);
		return result;
	}
	BOOL MF_PCDRead(long commHandle, long DeviceAddress, unsigned char mode, unsigned char blkIndex, unsigned char blkNum, unsigned char * key, unsigned char * buffer)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_UI1 VTS_UI1 VTS_UI1 VTS_PUI1 VTS_PUI1 ;
		InvokeHelper(0xe1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, commHandle, DeviceAddress, mode, blkIndex, blkNum, key, buffer);
		return result;
	}
	BOOL MF_PCDWrite(long commHandle, long DeviceAddress, unsigned char mode, unsigned char blkIndex, unsigned char blkNum, unsigned char * key, unsigned char * buffer)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_UI1 VTS_UI1 VTS_UI1 VTS_PUI1 VTS_PUI1 ;
		InvokeHelper(0xe2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, commHandle, DeviceAddress, mode, blkIndex, blkNum, key, buffer);
		return result;
	}
	long get_ReservedParam()
	{
		long result;
		InvokeHelper(0xe4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL get_IsReturnNoLic()
	{
		BOOL result;
		InvokeHelper(0xe3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IsReturnNoLic(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xe3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_LastQuality()
	{
		long result;
		InvokeHelper(0xe5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_LowestQuality()
	{
		long result;
		InvokeHelper(0xe6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_LowestQuality(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xe6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}


};
