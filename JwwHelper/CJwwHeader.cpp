#include "pch.h"
#include "CJwwHeader.h"
#include "CData.h"



CJwwHeader::CJwwHeader() {
	//	s_jwwDataVersion = JWW_VERSION;
}

void CJwwHeader::Read(CArchive& ar) {
	ar >> m_jwwDataVersion;	// 7.02の内部データ値は700
	CData::s_FileVersion = m_jwwDataVersion;
	ar >> m_strMemo;	//◆ ファイルメモ
	ar >> m_nZumen;
	ar >> m_nWriteGLay;
	for (int nGLay = 0; nGLay < 16; nGLay++) {
		ar >> m_anGLay[nGLay];
		ar >> m_anWriteLay[nGLay];
		ar >> m_adScale[nGLay];
		ar >> m_anGLayProtect[nGLay];
		for (int nLay = 0; nLay < 16; nLay++) {
			ar >> m_aanLay[nGLay][nLay];
			ar >> m_aanLayProtect[nGLay][nLay];
		}
	}
	//◆ ダミー
	DWORD dummy;
	for (int i = 0; i < 14; i++) { ar >> dummy; }

	ar >> m_lnSunpou1;
	ar >> m_lnSunpou2;
	ar >> m_lnSunpou3;
	ar >> m_lnSunpou4;
	ar >> m_lnSunpou5;

	ar >> dummy;
	ar >> nWid;
	ar >> m_DPPrtGenten_x;
	ar >> m_DPPrtGenten_y;
	ar >> m_dPrtBairitsu;

	ar >> m_nPrtSet;
	ar >> m_nMemoriMode;
	ar >> m_dMemoriHyoujiMin;

	ar >> m_dMemoriX;
	ar >> m_dMemoriY;
	ar >> m_DpMemoriKijunTen_x;
	ar >> m_DpMemoriKijunTen_y;

	//◆ レイヤ名
	for (int n = 0; n <= 15; n++) {
		for (int k = 0; k <= 15; k++) {
			ar >> m_aStrLayName[n][k];
		}
	}
	//◆ レイヤグループ名
	for (int n = 0; n <= 15; n++) {
		ar >> m_aStrGLayName[n];
	}

	ar >> m_dKageLevel;
	ar >> m_dKageIdo;
	ar >> m_nKage9_15JiFlg;
	ar >> m_dKabeKageLevel;

	//◆ 天空図の条件（Ver.3.00以降)
	if (m_jwwDataVersion >= 300) {
		ar >> m_dTenkuuZuLevel;
		ar >> m_dTenkuuZuEnkoR;
	}
	else {
		m_dTenkuuZuLevel = 0.0;
		m_dTenkuuZuEnkoR = 50.0;
	}
	//◆ 2.5Dの計算単位(0以外はmm単位で計算)
	ar >> m_nMMTani3D;

	//◆ 保存時の画⾯倍率(読込むと前画⾯倍率になる)
	ar >> m_dBairitsu;
	ar >> m_DPGenten_x;
	ar >> m_DPGenten_y;
	//◆ 範囲記憶倍率と基準点(X, Y)
	ar >> m_dHanniBairitsu;
	ar >> m_DPHanniGenten_x;
	ar >> m_DPHanniGenten_y;


	//◆ マークジャンプ倍率、基準点(X, Y)およびレイヤグループ
	if (m_jwwDataVersion >= 300) { //Ver.3.00以降
		for (int n = 0; n < 8; n++) {
			ar >> m_dZoomJumpBairitsu[n];
			ar >> m_DPZoomJumpGenten_x[n];
			ar >> m_DPZoomJumpGenten_y[n];
			ar >> m_nZoomJumpGLay[n];
		}
	}
	else {
		for (int n = 0; n < 4; n++) {
			ar >> m_dZoomJumpBairitsu[n];
			ar >> m_DPZoomJumpGenten_x[n];
			ar >> m_DPZoomJumpGenten_y[n];
		}
		for (int n = 4; n < 8; n++) {
			m_dZoomJumpBairitsu[n] = 1.0;
			m_DPZoomJumpGenten_x[n] = 0.0;
			m_DPZoomJumpGenten_y[n] = 0.0;
		}
	}

	double dDm11;
	m_dMojiBG = 0;
	m_nMojiBG = 0;
	if (m_jwwDataVersion >= 300) { //Ver.3.00以降
		ar >> dDm11; //ダミー
		ar >> dDm11; //ダミー
		ar >> dDm11; //ダミー
		ar >> dummy; //ダミー
		ar >> dDm11; //ダミー
		ar >> dDm11; //ダミー
		ar >> m_dMojiBG;//(Ver.4.04以前はダミー）
		ar >> m_nMojiBG;
	}

	for (int n = 0; n <= 9; n++) {
		ar >> m_adFukusenSuuchi[n];
	}
	ar >> m_dRyoygawaFukusenTomeDe;

	for (int n = 0; n < 10; n++) {
		ar >> m_aPenColor[n];
		ar >> m_anPenWidth[n];
	}
	for (int n = 0; n < 10; n++) {
		ar >> m_aPrtPenColor[n];
		ar >> m_anPrtPenWidth[n];
		ar >> m_adPrtTenHankei[n];
	}

	for (int n = 0; n < 8; n++) {
		ar >> m_alLType[n];
		ar >> m_anTokushuSenUintDot[n];
		ar >> m_anTokushuSenPich[n];
		ar >> m_anPrtTokushuSenPich[n];
	}
	for (int n = 0; n < 5; n++) {
		ar >> m_alLType_Rnd[n];
		ar >> m_anRandSenWide_Rnd[n];
		ar >> m_anTokushuSenPich_Rnd[n];
		ar >> m_anPrtRandSenWide_Rnd[n];
		ar >> m_anPrtTokushuSenPich_Rnd[n];
	}

	for (int n = 0; n < 4; n++) {
		ar >> m_alLType_Double[n];
		ar >> m_anTokushuSenUintDot_Double[n];
		ar >> m_anTokushuSenPich_Double[n];
		ar >> m_anPrtTokushuSenPich_Double[n];
	}

	ar >> m_nDrawGamenTen;
	ar >> m_nDrawPrtTen;
	ar >> m_nBitMapFirstDraw;

	ar >> m_nGyakuDraw;
	ar >> m_nGyakuSearch;
	ar >> m_nColorPrint;
	ar >> m_nLayJunPrint;
	ar >> m_nColJunPrint;
	ar >> m_nPrtRenzoku;
	ar >> m_nPrtKyoutsuuGray;
	ar >> m_nPrtDispOnlyNonDraw;

	ar >> m_lnDrawTime;

	ar >> nEyeInit;
	ar >> m_dEye_H_Ichi_1;
	m_dEye_H_Ichi_1 /= 100;
	ar >> m_dEye_H_Ichi_2;
	m_dEye_H_Ichi_2 /= 100;
	ar >> m_dEye_H_Ichi_3;
	m_dEye_H_Ichi_3 /= 100;
	ar >> m_dEye_Z_Ichi_1;
	ar >> m_dEye_Y_Ichi_1;
	ar >> m_dEye_Z_Ichi_2;
	ar >> m_dEye_Y_Ichi_2;
	ar >> m_dEye_V_Ichi_3;
	ar >> m_dSenNagasaSnpou;
	ar >> m_dBoxSunpouX;
	ar >> m_dBoxSunpouY;
	ar >> m_dEnHankeiSnpou;

	ar >> m_nSolidNinniColor;
	ar >> m_SolidColor; //RGB


	if (m_jwwDataVersion >= 420) { //Ver.4.25以降
		for (int n = 0; n <= 256; n++) { ////// 画⾯表⽰⾊
			ar >> m_aPenColor_SXF[n] >> m_anPenWidth_SXF[n];
		}
		for (int n = 0; n <= 256; n++) { ////// プリンタ出⼒⾊
			ar >> m_astrUDColorName_SXF[n];
			ar >> m_aPrtPenColor_SXF[n]
				>> m_anPrtPenWidth_SXF[n]
				>> m_adPrtTenHankei_SXF[n];
		}
		for (int n = 0; n <= 32; n++) { ////// 線種パターン
			ar >> m_alLType_SXF[n]
				>> m_anTokushuSenUintDot_SXF[n]
				>> m_anTokushuSenPich_SXF[n]
				>> m_anPrtTokushuSenPich_SXF[n];
		}
		for (int n = 0; n <= 32; n++) { ////// 線種パラメータ
			ar >> m_astrUDLTypeName_SXF[n] >> m_anUDLTypeSegment_SXF[n];
			for (int j = 0; j < 10; j++) {
				ar >> m_aadUDLTypePitch_SXF[n][j];
			}
		}
	}
	else {
		for (int n = 0; n <= 256; n++) { ////// 画⾯表⽰⾊
			m_aPenColor_SXF[n] = 0;
			m_anPenWidth_SXF[n] = 0;
		}
		for (int n = 0; n <= 256; n++) { ////// プリンタ出⼒⾊
			m_astrUDColorName_SXF[n] = "";
			m_aPrtPenColor_SXF[n] = 0;
			m_anPrtPenWidth_SXF[n] = 0;
			m_adPrtTenHankei_SXF[n] = 1.0;
		}
		for (int n = 0; n <= 32; n++) { ////// 線種パターン
			m_alLType_SXF[n] = 0xFFFFFFFF;
			m_anTokushuSenUintDot_SXF[n] = 16;
			m_anTokushuSenPich_SXF[n] = 1;
			m_anPrtTokushuSenPich_SXF[n] = 10;
		}
		for (int n = 0; n <= 32; n++) { ////// 線種パラメータ
			m_astrUDLTypeName_SXF[n] = "";
			for (int j = 0; j < 10; j++) {
				m_aadUDLTypePitch_SXF[n][j] = 0.0;
			}
		}

	}
	for (int i = 0; i < 10; i++) {
		ar >> m_adMojiX[i] >> m_adMojiY[i];
		ar >> m_adMojiD[i] >> m_anMojiCol[i];
	}
	ar >> m_dMojiSizeX >> m_dMojiSizeY;
	ar >> m_dMojiKankaku;
	ar >> m_nMojiColor >> m_nMojiShu;
	ar >> m_dMojiSeiriGyouKan >> m_dMojiSeiriSuu;
	ar >> m_nMojiKijunZureOn;
	ar >> m_adMojiKijunZureX[0];
	ar >> m_adMojiKijunZureX[1];
	ar >> m_adMojiKijunZureX[2];
	ar >> m_adMojiKijunZureY[0];
	ar >> m_adMojiKijunZureY[1];
	ar >> m_adMojiKijunZureY[2];
}


void CJwwHeader::Write(CArchive& ar) {
	m_jwwDataVersion = 700;	// 書き込みのバージョンは固定
	ar << m_jwwDataVersion;
	CData::s_FileVersion = m_jwwDataVersion;
	ar << m_strMemo;	//◆ ファイルメモ
	ar << m_nZumen;
	ar << m_nWriteGLay;
	for (int nGLay = 0; nGLay < 16; nGLay++) {
		ar << m_anGLay[nGLay];
		ar << m_anWriteLay[nGLay];
		ar << m_adScale[nGLay];
		ar << m_anGLayProtect[nGLay];
		for (int nLay = 0; nLay < 16; nLay++) {
			ar << m_aanLay[nGLay][nLay];
			ar << m_aanLayProtect[nGLay][nLay];
		}
	}
	//◆ ダミー
	DWORD dummy = 0;
	for (int i = 0; i < 14; i++) { ar << dummy; }

	ar << m_lnSunpou1;
	ar << m_lnSunpou2;
	ar << m_lnSunpou3;
	ar << m_lnSunpou4;
	ar << m_lnSunpou5;

	ar << dummy;
	ar << nWid;
	ar << m_DPPrtGenten_x;
	ar << m_DPPrtGenten_y;
	ar << m_dPrtBairitsu;

	ar << m_nPrtSet;
	ar << m_nMemoriMode;
	ar << m_dMemoriHyoujiMin;

	ar << m_dMemoriX;
	ar << m_dMemoriY;
	ar << m_DpMemoriKijunTen_x;
	ar << m_DpMemoriKijunTen_y;

	//◆ レイヤ名
	for (int n = 0; n <= 15; n++) {
		for (int k = 0; k <= 15; k++) {
			ar << m_aStrLayName[n][k];
		}
	}
	//◆ レイヤグループ名
	for (int n = 0; n <= 15; n++) {
		ar << m_aStrGLayName[n];
	}

	ar << m_dKageLevel;
	ar << m_dKageIdo;
	ar << m_nKage9_15JiFlg;
	ar << m_dKabeKageLevel;

	//◆ 天空図の条件（Ver.3.00以降)
	if (m_jwwDataVersion >= 300) {
		ar << m_dTenkuuZuLevel;
		ar << m_dTenkuuZuEnkoR;
		m_dTenkuuZuEnkoR /= 2.0;
	}
	//◆ 2.5Dの計算単位(0以外はmm単位で計算)
	ar << m_nMMTani3D;

	//◆ 保存時の画⾯倍率(読込むと前画⾯倍率になる)
	ar << m_dBairitsu;
	ar << m_DPGenten_x;
	ar << m_DPGenten_y;
	//◆ 範囲記憶倍率と基準点(X, Y)
	ar << m_dHanniBairitsu;
	ar << m_DPHanniGenten_x;
	ar << m_DPHanniGenten_y;


	//◆ マークジャンプ倍率、基準点(X, Y)およびレイヤグループ
	if (m_jwwDataVersion >= 300) { //Ver.3.00以降
		for (int n = 0; n < 8; n++) {
			ar << m_dZoomJumpBairitsu[n];
			ar << m_DPZoomJumpGenten_x[n];
			ar << m_DPZoomJumpGenten_y[n];
			ar << m_nZoomJumpGLay[n];
		}
	}
	else {
		for (int n = 0; n < 4; n++) {
			ar << m_dZoomJumpBairitsu[n];
			ar << m_DPZoomJumpGenten_x[n];
			ar << m_DPZoomJumpGenten_y[n];
		}
	}

	double dDm11 = 0;
	if (m_jwwDataVersion >= 300) { //Ver.3.00以降
		ar << dDm11; //ダミー
		ar << dDm11; //ダミー
		ar << dDm11; //ダミー
		ar << dummy; //ダミー
		ar << dDm11; //ダミー
		ar << dDm11; //ダミー
		ar << m_dMojiBG;//(Ver.4.04以前はダミー）
		ar << m_nMojiBG;
	}

	for (int n = 0; n <= 9; n++) {
		ar << m_adFukusenSuuchi[n];
	}
	ar << m_dRyoygawaFukusenTomeDe;

	for (int n = 0; n < 10; n++) {
		ar << m_aPenColor[n];
		ar << m_anPenWidth[n];
	}
	for (int n = 0; n < 10; n++) {
		ar << m_aPrtPenColor[n];
		ar << m_anPrtPenWidth[n];
		ar << m_adPrtTenHankei[n];
	}

	for (int n = 0; n < 8; n++) {
		ar << m_alLType[n];
		ar << m_anTokushuSenUintDot[n];
		ar << m_anTokushuSenPich[n];
		ar << m_anPrtTokushuSenPich[n];
	}
	for (int n = 0; n < 5; n++) {
		ar << m_alLType_Rnd[n];
		ar << m_anRandSenWide_Rnd[n];
		ar << m_anTokushuSenPich_Rnd[n];
		ar << m_anPrtRandSenWide_Rnd[n];
		ar << m_anPrtTokushuSenPich_Rnd[n];
	}

	for (int n = 0; n < 4; n++) {
		ar << m_alLType_Double[n];
		ar << m_anTokushuSenUintDot_Double[n];
		ar << m_anTokushuSenPich_Double[n];
		ar << m_anPrtTokushuSenPich_Double[n];
	}

	ar << m_nDrawGamenTen;
	ar << m_nDrawPrtTen;
	ar << m_nBitMapFirstDraw;

	ar << m_nGyakuDraw;
	ar << m_nGyakuSearch;
	ar << m_nColorPrint;
	ar << m_nLayJunPrint;
	ar << m_nColJunPrint;
	ar << m_nPrtRenzoku;
	ar << m_nPrtKyoutsuuGray;
	ar << m_nPrtDispOnlyNonDraw;

	ar << m_lnDrawTime;

	ar << nEyeInit;
	ar << m_dEye_H_Ichi_1;
	m_dEye_H_Ichi_1 /= 100;
	ar << m_dEye_H_Ichi_2;
	m_dEye_H_Ichi_2 /= 100;
	ar << m_dEye_H_Ichi_3;
	m_dEye_H_Ichi_3 /= 100;
	ar << m_dEye_Z_Ichi_1;
	ar << m_dEye_Y_Ichi_1;
	ar << m_dEye_Z_Ichi_2;
	ar << m_dEye_Y_Ichi_2;
	ar << m_dEye_V_Ichi_3;
	ar << m_dSenNagasaSnpou;
	ar << m_dBoxSunpouX;
	ar << m_dBoxSunpouY;
	ar << m_dEnHankeiSnpou;

	ar << m_nSolidNinniColor;
	ar << m_SolidColor; //RGB
	for (int n = 0; n <= 256; n++) { ////// 画⾯表⽰⾊
		ar << m_aPenColor_SXF[n]
			<< m_anPenWidth_SXF[n];
	}
	for (int n = 0; n <= 256; n++) { ////// プリンタ出⼒⾊
		ar << m_astrUDColorName_SXF[n];
		ar << m_aPrtPenColor_SXF[n]
			<< m_anPrtPenWidth_SXF[n]
			<< m_adPrtTenHankei_SXF[n];
	}
	for (int n = 0; n <= 32; n++) { ////// 線種パターン
		ar << m_alLType_SXF[n]
			<< m_anTokushuSenUintDot_SXF[n]
			<< m_anTokushuSenPich_SXF[n]
			<< m_anPrtTokushuSenPich_SXF[n];
	}
	for (int n = 0; n <= 32; n++) { ////// 線種パラメータ
		ar << m_astrUDLTypeName_SXF[n] << m_anUDLTypeSegment_SXF[n];
		for (int j = 0; j < 10; j++) {
			ar << m_aadUDLTypePitch_SXF[n][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		ar << m_adMojiX[i] << m_adMojiY[i];
		ar << m_adMojiD[i] << m_anMojiCol[i];
	}
	ar << m_dMojiSizeX << m_dMojiSizeY;
	ar << m_dMojiKankaku;
	ar << m_nMojiColor << m_nMojiShu;
	ar << m_dMojiSeiriGyouKan << m_dMojiSeiriSuu;
	ar << m_nMojiKijunZureOn;
	ar << m_adMojiKijunZureX[0];
	ar << m_adMojiKijunZureX[1];
	ar << m_adMojiKijunZureX[2];
	ar << m_adMojiKijunZureY[0];
	ar << m_adMojiKijunZureY[1];
	ar << m_adMojiKijunZureY[2];

}

CJwwHeader* CJwwHeader::Clone() {
	CMemFile mem;
	CArchive store(&mem, CArchive::store);
	Write(store);
	store.Close();
	DWORD len = mem.GetLength();
	BYTE* buf = mem.Detach();
	mem.Close();
	CMemFile tmp(buf, len);
	CArchive load(&tmp, CArchive::load);
	CJwwHeader* h = new CJwwHeader();
	h->Read(load);
	load.Close();
	tmp.Close();
	free(buf);
	return h;
}

