
// FileInputOutputDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "FileInputOutput.h"
#include "FileInputOutputDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileInputOutputDlg 대화 상자



CFileInputOutputDlg::CFileInputOutputDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FILEINPUTOUTPUT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileInputOutputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFileInputOutputDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOAD, &CFileInputOutputDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CFileInputOutputDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD2, &CFileInputOutputDlg::OnBnClickedBtnLoad2)
	ON_BN_CLICKED(IDC_BTN_SAVE2, &CFileInputOutputDlg::OnBnClickedBtnSave2)
	ON_BN_CLICKED(IDC_BTN_LOAD3, &CFileInputOutputDlg::OnBnClickedBtnLoad3)
	ON_BN_CLICKED(IDC_BTN_SAVE3, &CFileInputOutputDlg::OnBnClickedBtnSave3)
END_MESSAGE_MAP()


// CFileInputOutputDlg 메시지 처리기

BOOL CFileInputOutputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFileInputOutputDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFileInputOutputDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFileInputOutputDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileInputOutputDlg::OnBnClickedBtnLoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFile file;
	file.Open("test.txt",CFile::modeRead); // 읽기모드 오픈

	char temp[100] = { 0, };
	
	file.Read(temp, 100); // 위와 같이 써야 error 가 나오지 않음

	
	CString str = temp;

//	SetDlgItemText(IDC_EDIT_NAME, str); // 에디터 갱신

	CString strTo;
	int idx = 0;
	//tokenis 로 '/' 값을 짤라서 사용
	strTo = str.Tokenize("/", idx);
	SetDlgItemText(IDC_EDIT_NAME,strTo); //에디터 갱신

	strTo = str.Tokenize("/", idx);
	SetDlgItemText(IDC_EDIT_AGE, strTo);

	strTo = str.Tokenize("/", idx);
	SetDlgItemText(IDC_EDIT_PHONE, strTo);



	
	file.Close(); // 메모리 해제
	

}


void CFileInputOutputDlg::OnBnClickedBtnSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFile file;
	
	// 파일 열기,만들기,읽기
	file.Open("test.txt", CFile::modeCreate|CFile::modeWrite); //creat 파일 만듬

	//edit 문자 얻어오기
	CString str;
	GetDlgItemText(IDC_EDIT_NAME,str);
	file.Write(str.GetBuffer(), str.GetLength());
	file.Write("/",1);

	GetDlgItemText(IDC_EDIT_AGE, str);
	file.Write(str.GetBuffer(), str.GetLength());
	file.Write("/",1);

	
	GetDlgItemText(IDC_EDIT_PHONE, str);
	file.Write(str.GetBuffer(), str.GetLength());
	file.Write("/", 1);




	// test.txt 파일에 문자 쓰기
	//file.Write(str.GetBuffer(),str.GetLength()); // str 주소, 길이


	// 메모리 반환
	file.Close(); // 항상 할달 하거나 파일 입출력시 close 작성 후 수행
}


void CFileInputOutputDlg::OnBnClickedBtnLoad2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFile file;
	file.Open("test2.txt",CFile::modeRead);

	CArchive ar(&file,CArchive::load); // 읽을때 
	

	CString str;
	ar >> str;
	SetDlgItemText(IDC_EDIT_NAME, str);
	

	
	ar >> str;
	SetDlgItemText(IDC_EDIT_AGE, str);



	ar >> str;
	SetDlgItemText(IDC_EDIT_PHONE, str);

	
	
	ar.Close();
	file.Close();

}


void CFileInputOutputDlg::OnBnClickedBtnSave2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CFile file;
	file.Open("test2.txt",CFile::modeCreate| CFile::modeWrite);
	
	CArchive ar(&file,CArchive::store); // 파일 입출력을 도와주는 값. 파일의 주소 & store 저장

	CString str;
	GetDlgItemText(IDC_EDIT_NAME, str); //ar 값이 스스로 구분 지어줌 그러므로 file 입력으로는 쓰기 어려움
	ar << str;

	GetDlgItemText(IDC_EDIT_AGE, str);
	ar << str;

	GetDlgItemText(IDC_EDIT_PHONE, str);
	ar << str;

	ar.Close();
	file.Close();

}


void CFileInputOutputDlg::OnBnClickedBtnLoad3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFile file;

	file.Open("test3.txt", CFile::modeRead);

	
	CArchive ar(&file, CArchive::load);
	
	bool bLoop = true;
	CString str;

	while (bLoop)
	{
		bLoop = ar.ReadString(str); // 한줄씩 읽어옴 읽는 값이 없으면 false 를 return 하게 된다.

		int idx = 0;


		if (bLoop)
		{
			CString name, age, phone;

			name  = str.Tokenize("/", idx);
			age   = str.Tokenize("/", idx);
			phone = str.Tokenize("/", idx);



			CListBox* pList = ((CListBox*)GetDlgItem(IDC_LIST1));

			pList->AddString(str);

		}

	}

	

	file.Close();
}


void CFileInputOutputDlg::OnBnClickedBtnSave3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFile file;

	file.Open("test3.txt", CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);// modeNOtruacete 이것을 이용해 파일이 있을 시 
	file.SeekToEnd(); // 커서가 파일 끝으로 가라

	CString str;
	CString strTotal;

	//이름
	GetDlgItemText(IDC_EDIT_NAME, str);
	strTotal += str;
	strTotal += "/";

	//나이
	GetDlgItemText(IDC_EDIT_AGE, str);
	strTotal += str;
	strTotal += "/";


	//전화번호
	GetDlgItemText(IDC_EDIT_PHONE, str);
	strTotal += str;
	strTotal += "/";
	strTotal += "\r\n";

	file.Write(strTotal, strTotal.GetLength());

	file.Close();



	CListBox* pList = ((CListBox*)GetDlgItem(IDC_LIST1));

	pList->AddString(strTotal);


}
