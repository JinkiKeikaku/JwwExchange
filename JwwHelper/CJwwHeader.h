#pragma once
#include "JwwCommon.h"

class CJwwHeader {
public:
	CJwwHeader();
	void Read(CArchive& ar);
	void Write(CArchive& ar);
	CJwwHeader* Clone();
public:
	//	static int s_jwwDataVersion;
	CString m_strMemo;
	CString m_aStrLayName[16][16];
	CString m_aStrGLayName[16];
	CString m_astrUDColorName_SXF[257];
	CString m_astrUDLTypeName_SXF[33];


	DWORD m_jwwDataVersion = JWW_VERSION;

	DWORD m_nZumen;

	DWORD m_nWriteGLay;
	DWORD m_anGLay[16];
	DWORD m_anWriteLay[16];
	double m_adScale[16];
	DWORD m_anGLayProtect[16];
	DWORD m_aanLay[16][16];
	DWORD m_aanLayProtect[16][16];

	DWORD m_lnSunpou1;
	DWORD m_lnSunpou2;
	DWORD m_lnSunpou3;
	DWORD m_lnSunpou4;
	DWORD m_lnSunpou5;
	DWORD nWid;
	double m_DPPrtGenten_x;
	double m_DPPrtGenten_y;
	double m_dPrtBairitsu;
	DWORD m_nPrtSet;
	DWORD m_nMemoriMode;
	double m_dMemoriHyoujiMin;

	double m_dMemoriX;
	double m_dMemoriY;
	double m_DpMemoriKijunTen_x;
	double m_DpMemoriKijunTen_y;


	double m_dKageLevel;
	double m_dKageIdo;
	DWORD m_nKage9_15JiFlg;
	double m_dKabeKageLevel;

	double m_dTenkuuZuLevel;
	double m_dTenkuuZuEnkoR;

	DWORD m_nMMTani3D;

	//◆ 保存時の画⾯倍率(読込むと前画⾯倍率になる)
	double m_dBairitsu;
	double m_DPGenten_x;
	double m_DPGenten_y;
	//◆ 範囲記憶倍率と基準点(X, Y)
	double m_dHanniBairitsu;
	double m_DPHanniGenten_x;
	double m_DPHanniGenten_y;

	//◆ マークジャンプ倍率、基準点(X, Y)およびレイヤグループ
	double m_dZoomJumpBairitsu[8];
	double m_DPZoomJumpGenten_x[8];
	double m_DPZoomJumpGenten_y[8];
	DWORD m_nZoomJumpGLay[8];

	double m_dMojiBG;//(Ver.4.04以前はダミー）//⽂字列範囲を背景⾊で描画するときの範囲増寸法
	DWORD m_nMojiBG;

	//複線間隔
	double m_adFukusenSuuchi[10];
	//◆ 両側複線の留線出の寸法
	double m_dRyoygawaFukusenTomeDe;


	//◆ ⾊番号ごとの画⾯表⽰⾊、線幅
	//● 画⾯表⽰⾊(0︓背景⾊、1〜8︓線⾊、9︓グレー⾊)
	//● 線幅(1〜16)
	DWORD m_aPenColor[10];
	DWORD m_anPenWidth[10];
	//◆ ⾊番号ごとのプリンタ出⼒⾊、線幅、実点半径
	//● プリンタ出⼒⾊(0︓背景⾊、1〜8︓線⾊、9︓グレー⾊)
	//● 線幅(1〜500)
	//● 実点半径(0.1〜10)
	DWORD m_aPrtPenColor[10];
	DWORD m_anPrtPenWidth[10];
	double m_adPrtTenHankei[10];

	//◆ 線種番号2から9までのパターン、1ユニットのドット数、ピッチ、プリンタ出⼒ピッチ
	DWORD m_alLType[8];
	DWORD m_anTokushuSenUintDot[8];
	DWORD m_anTokushuSenPich[8];
	DWORD m_anPrtTokushuSenPich[8];
	//◆ ランダム線1から5までのパターン、画⾯表⽰振幅・ピッチ、プリンタ出⼒振幅・ピッチ
	DWORD m_alLType_Rnd[5];
	DWORD m_anRandSenWide_Rnd[5];
	DWORD m_anTokushuSenPich_Rnd[5];
	DWORD m_anPrtRandSenWide_Rnd[5];
	DWORD m_anPrtTokushuSenPich_Rnd[5];
	//◆ 倍⻑線種番号6から9までのパターン、1ユニットのドット数、ピッチ、プリンタ出⼒ピッチ
	DWORD m_alLType_Double[4];
	DWORD m_anTokushuSenUintDot_Double[4];
	DWORD m_anTokushuSenPich_Double[4];
	DWORD m_anPrtTokushuSenPich_Double[4];

	//◆ 実点を画⾯描画時の指定半径で描画
	DWORD m_nDrawGamenTen;
	//◆ 実点をプリンタ出⼒時、指定半径で書く
	DWORD m_nDrawPrtTen;
	//◆ BitMap・ソリッドを最初に描画する
	DWORD m_nBitMapFirstDraw; //⼗位︓ソリッド描画順


	//◆ 逆描画
	DWORD m_nGyakuDraw;
	//◆ 逆サーチ
	DWORD m_nGyakuSearch;
	//◆ カラー印刷
	DWORD m_nColorPrint;
	//◆ レイヤ順の印刷
	DWORD m_nLayJunPrint;
	//◆ ⾊番号順の印刷
	DWORD m_nColJunPrint;
	//◆ レイヤグループまたはレイヤごとのプリンタ連続出⼒指定
	DWORD m_nPrtRenzoku;
	//◆ プリンタ共通レイヤ(表⽰のみレイヤ)のグレー出⼒指定
	DWORD m_nPrtKyoutsuuGray;
	//◆ プリンタ出⼒時に表⽰のみレイヤは出⼒しない
	//	Ver.6.00以降は印刷時における既定線⾊の線幅の基準値の「dpi」。
	DWORD m_nPrtDispOnlyNonDraw;
	//◆ 作図時間（Ver.2.23以降）
	DWORD m_lnDrawTime;
	//◆ 2.5Dの始点位置が設定されている時のフラグ（Ver.2.23以降）
		//● ⼀位︓透視図の視点位置設定済みフラグ
		//● ⼗位︓⿃瞰図の視点位置設定済みフラグ
		//● 百位︓アイソメ図の視点位置設定済みフラグ
	DWORD nEyeInit;
	//◆ 2.5Dの透視図・⿃瞰図・アイソメ図の視点⽔平角（Ver.2.23以降）
	DWORD m_dEye_H_Ichi_1;
	DWORD m_dEye_H_Ichi_2;
	DWORD m_dEye_H_Ichi_3;
	//◆ 2.5Dの透視図の視点⾼さ・視点離れ（Ver.2.23以降）
	double m_dEye_Z_Ichi_1;
	double m_dEye_Y_Ichi_1;
	//◆ 2.5Dの⿃瞰図の視点⾼さ・視点離れ（Ver.2.23以降）
	double m_dEye_Z_Ichi_2;
	double m_dEye_Y_Ichi_2;
	//◆ 2.5Dのアイソメ図の視点垂直角（Ver.2.23以降）
	double m_dEye_V_Ichi_3;
	//◆ 線の⻑さ指定の最終値（Ver.2.25以降）
	double m_dSenNagasaSnpou;
	//◆ 矩形寸法横寸法・縦寸法指定の最終値（Ver.2.25以降）
	double m_dBoxSunpouX;
	double m_dBoxSunpouY;
	//◆ 円の半径指定の最終値（Ver.2.25以降）
	double m_dEnHankeiSnpou;
	//◆ ソリッドを任意⾊で書くフラグ、ソリッドの任意⾊の既定値（Ver.2.30以降）
	DWORD m_nSolidNinniColor;
	DWORD m_SolidColor; //RGB
	//◆ SXF対応拡張線⾊定義（Ver.4.20以降）
		//● 画⾯表⽰⾊
		//● 画⾯表⽰線幅
		//● 線⾊名
		//● プリンタ出⼒⾊
		//● プリンタ出⼒線幅
		//● 点半径
	DWORD m_aPenColor_SXF[257];
	DWORD m_anPenWidth_SXF[257];
	DWORD m_aPrtPenColor_SXF[257];
	DWORD m_anPrtPenWidth_SXF[257];
	double m_adPrtTenHankei_SXF[257];
	//◆ SXF対応拡張線種定義（Ver.4.20以降）
	//● パターン
	//● 1ユニットのドット数
	//● ピッチ
	//● プリンタ出⼒ピッチ
	//● 線種名
	//● セグメント数
	//● ピッチ線分の⻑さ、空⽩⻑さの繰り返し
	DWORD m_alLType_SXF[33];
	DWORD m_anTokushuSenUintDot_SXF[33];
	DWORD m_anTokushuSenPich_SXF[33];
	DWORD m_anPrtTokushuSenPich_SXF[33];
	DWORD m_anUDLTypeSegment_SXF[33];
	double m_aadUDLTypePitch_SXF[33][10];
	//◆ ⽂字種1から10までの⽂字幅、⾼さ、間隔、⾊番号
	double m_adMojiX[10];
	double m_adMojiY[10];
	double m_adMojiD[10];
	DWORD m_anMojiCol[10];
	//◆ 書込み⽂字の⽂字幅、⾼さ、間隔、⾊番号、⽂字番号
	double m_dMojiSizeX;
	double m_dMojiSizeY;
	double m_dMojiKankaku;
	DWORD m_nMojiColor;
	DWORD m_nMojiShu;
	//◆ ⽂字位置整理の⾏間、⽂字数
	double m_dMojiSeiriGyouKan;
	double m_dMojiSeiriSuu;
	//◆ ⽂字基準点のずれ位置使⽤のフラグ
	DWORD m_nMojiKijunZureOn;
	//◆ ⽂字基準点の横⽅向のずれ位置左、中、右
	double m_adMojiKijunZureX[3];
	//◆ ⽂字基準点の縦⽅向のずれ位置下、中、上
	double m_adMojiKijunZureY[3];

};

