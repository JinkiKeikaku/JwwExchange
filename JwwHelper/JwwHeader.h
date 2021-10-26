#pragma once
using namespace System;
#include "CJwwHeader.h"
namespace JwwHelper {
	public ref class JwwHeader
	{
	internal:
		JwwHeader() { m_pHeader = new CJwwHeader(); }
		JwwHeader(CJwwHeader* pHeader) { m_pHeader = pHeader; }
	public:
		~JwwHeader() { this->!JwwHeader(); }
		!JwwHeader() { delete m_pHeader; }

//		CJwwHeader* CloneHeader() { return m_pHeader->Clone(); }
	public:
		property int m_jwwDataVersion {
			int get() { return m_pHeader->m_jwwDataVersion; }
		};
		property String^ m_strMemo {
			String^ get() {
				return gcnew String(CA2W(m_pHeader->m_strMemo.GetString()));
			}
			void set(String^ value) { 
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pHeader->m_strMemo = astr;
			}
		};
		property String^ m_aStrLayName[int]{
			String ^ get(int index) {
				return gcnew String(CA2W(m_pHeader->m_aStrLayName[index / 16][index % 16]));
			}
			void set(int index, String ^ value) {
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pHeader->m_aStrLayName[index / 16][index % 16] = astr;
			}
		};
		property String^ m_aStrGLayName[int]{
			String ^ get(int index) {
				return gcnew String(CA2W(m_pHeader->m_aStrGLayName[index]));
			}
			void set(int index, String ^ value) {
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pHeader->m_aStrGLayName[index] = astr;
			}
		};
		property String^ m_astrUDColorName_SXF[int]{
			String ^ get(int index) {
				return gcnew String(CA2W(m_pHeader->m_astrUDColorName_SXF[index]));
			}
			void set(int index, String ^ value) {
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pHeader->m_astrUDColorName_SXF[index] = astr;
			}
		};

		property String^ m_astrUDLTypeName_SXF[int]{
			String ^ get(int index) {
				return gcnew String(CA2W(m_pHeader->m_astrUDLTypeName_SXF[index]));
			}
			void set(int index, String ^ value) {
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pHeader->m_astrUDLTypeName_SXF[index] = astr;
			}
		};
		property int m_nZumen {
			int get() { return m_pHeader->m_nZumen; }
			void set(int value) { m_pHeader->m_nZumen = value; }
		};
		property int m_nWriteGLay {
			int get() { return m_pHeader->m_nWriteGLay; }
			void set(int value) { m_pHeader->m_nWriteGLay = value; }
		};
		property int m_anGLay[int]{
			int get(int index) { return m_pHeader->m_anGLay[index]; }
			void set(int index, int value) { m_pHeader->m_anGLay[index] = value; }
		};
		property int m_anWriteLay[int]{
			int get(int index) { return m_pHeader->m_anWriteLay[index]; }
			void set(int index, int value) { m_pHeader->m_anWriteLay[index] = value; }
		};
		property double m_adScale[int]{
			double get(int index) { return m_pHeader->m_adScale[index]; }
			void set(int index, double value) { m_pHeader->m_adScale[index] = value; }
		};
		property int m_anGLayProtect[int]{
			int get(int index) { return m_pHeader->m_anGLayProtect[index]; }
			void set(int index, int value) { m_pHeader->m_anGLayProtect[index] = value; }
		};
		property int m_aanLay[int]{
			int get(int index) { return m_pHeader->m_aanLay[index / 16][index % 16]; }
			void set(int index, int value) { m_pHeader->m_aanLay[index / 16][index % 16] = value; }
		};
		property int m_lnSunpou1 {
			int get() { return m_pHeader->m_lnSunpou1; }
			void set(int value) { m_pHeader->m_lnSunpou1 = value; }
		};
		property int m_lnSunpou2 {
			int get() { return m_pHeader->m_lnSunpou2; }
			void set(int value) { m_pHeader->m_lnSunpou2 = value; }
		};
		property int m_lnSunpou3 {
			int get() { return m_pHeader->m_lnSunpou3; }
			void set(int value) { m_pHeader->m_lnSunpou3 = value; }
		};
		property int m_lnSunpou4 {
			int get() { return m_pHeader->m_lnSunpou4; }
			void set(int value) { m_pHeader->m_lnSunpou4 = value; }
		};
		property int m_lnSunpou5 {
			int get() { return m_pHeader->m_lnSunpou5; }
			void set(int value) { m_pHeader->m_lnSunpou5 = value; }
		}
		property int nWid {
			int get() { return m_pHeader->nWid; }
			void set(int value) { m_pHeader->nWid = value; }
		}
		property double m_DPPrtGenten_x {
			double get() { return m_pHeader->m_DPPrtGenten_x; }
			void set(double value) { m_pHeader->m_DPPrtGenten_x = value; }
		}
		property double m_DPPrtGenten_y {
			double get() { return m_pHeader->m_DPPrtGenten_y; }
			void set(double value) { m_pHeader->m_DPPrtGenten_y = value; }
		}
		property double m_dPrtBairitsu {
			double get() { return m_pHeader->m_dPrtBairitsu; }
			void set(double value) { m_pHeader->m_dPrtBairitsu = value; }
		}
		property int m_nPrtSet {
			int get() { return m_pHeader->m_nPrtSet; }
			void set(int value) { m_pHeader->m_nPrtSet = value; }
		}
		property int m_nMemoriMode {
			int get() { return m_pHeader->m_nMemoriMode; }
			void set(int value) { m_pHeader->m_nMemoriMode = value; }
		}
		property double m_dMemoriHyoujiMin {
			double get() { return m_pHeader->m_dMemoriHyoujiMin; }
			void set(double value) { m_pHeader->m_dMemoriHyoujiMin = value; }
		}
		property double m_dMemoriX {
			double get() { return m_pHeader->m_dMemoriX; }
			void set(double value) { m_pHeader->m_dMemoriX = value; }
		}
		property double m_dMemoriY {
			double get() { return m_pHeader->m_dMemoriY; }
			void set(double value) { m_pHeader->m_dMemoriY = value; }
		}
		property double m_DpMemoriKijunTen_x {
			double get() { return m_pHeader->m_DpMemoriKijunTen_x; }
			void set(double value) { m_pHeader->m_DpMemoriKijunTen_x = value; }
		}
		property double m_DpMemoriKijunTen_y {
			double get() { return m_pHeader->m_DpMemoriKijunTen_y; }
			void set(double value) { m_pHeader->m_DpMemoriKijunTen_y = value; }
		}
		property double m_dKageLevel {
			double get() { return m_pHeader->m_dKageLevel; }
			void set(double value) { m_pHeader->m_dKageLevel = value; }
		}
		property double m_dKageIdo {
			double get() { return m_pHeader->m_dKageIdo; }
			void set(double value) { m_pHeader->m_dKageIdo = value; }
		}
		property int m_nKage9_15JiFlg {
			int get() { return m_pHeader->m_nKage9_15JiFlg; }
			void set(int value) { m_pHeader->m_nKage9_15JiFlg = value; }
		}
		property double m_dKabeKageLevel {
			double get() { return m_pHeader->m_dKabeKageLevel; }
			void set(double value) { m_pHeader->m_dKabeKageLevel = value; }
		}
		property double m_dTenkuuZuLevel {
			double get() { return m_pHeader->m_dTenkuuZuLevel; }
			void set(double value) { m_pHeader->m_dTenkuuZuLevel = value; }
		}
		property double m_dTenkuuZuEnkoR {
			double get() { return m_pHeader->m_dTenkuuZuEnkoR; }
			void set(double value) { m_pHeader->m_dTenkuuZuEnkoR = value; }
		}
		property int m_nMMTani3D {
			int get() { return m_pHeader->m_nMMTani3D; }
			void set(int value) { m_pHeader->m_nMMTani3D = value; }
		}
		property double m_dBairitsu {
			double get() { return m_pHeader->m_dBairitsu; }
			void set(double value) { m_pHeader->m_dBairitsu = value; }
		}
		property double m_DPGenten_x {
			double get() { return m_pHeader->m_DPGenten_x; }
			void set(double value) { m_pHeader->m_DPGenten_x = value; }
		}
		property double m_DPGenten_y {
			double get() { return m_pHeader->m_DPGenten_y; }
			void set(double value) { m_pHeader->m_DPGenten_y = value; }
		}
		property double m_dHanniBairitsu {
			double get() { return m_pHeader->m_dHanniBairitsu; }
			void set(double value) { m_pHeader->m_dHanniBairitsu = value; }
		}
		property double m_DPHanniGenten_x {
			double get() { return m_pHeader->m_DPHanniGenten_x; }
			void set(double value) { m_pHeader->m_DPHanniGenten_x = value; }
		}
		property double m_DPHanniGenten_y {
			double get() { return m_pHeader->m_DPHanniGenten_y; }
			void set(double value) { m_pHeader->m_DPHanniGenten_y = value; }
		}

		property double m_dZoomJumpBairitsu[int]{
			double get(int index) { return m_pHeader->m_dZoomJumpBairitsu[index]; }
			void set(int index, double value) { m_pHeader->m_dZoomJumpBairitsu[index] = value; }
		}
			property double m_DPZoomJumpGenten_x[int]{
				double get(int index) { return m_pHeader->m_DPZoomJumpGenten_x[index]; }
				void set(int index, double value) { m_pHeader->m_DPZoomJumpGenten_x[index] = value; }
		}
			property double m_DPZoomJumpGenten_y[int]{
				double get(int index) { return m_pHeader->m_DPZoomJumpGenten_y[index]; }
				void set(int index, double value) { m_pHeader->m_DPZoomJumpGenten_y[index] = value; }
		}
			property int m_nZoomJumpGLay[int]{
				int get(int index) { return m_pHeader->m_nZoomJumpGLay[index]; }
				void set(int index, int value) { m_pHeader->m_nZoomJumpGLay[index] = value; }
		}
			property double m_dMojiBG {
			double get() { return m_pHeader->m_dMojiBG; }
			void set(double value) { m_pHeader->m_dMojiBG = value; }
		}
		property int m_nMojiBG {
			int get() { return m_pHeader->m_nMojiBG; }
			void set(int value) { m_pHeader->m_nMojiBG = value; }
		}
		property double m_adFukusenSuuchi[int]{
			double get(int index) { return m_pHeader->m_adFukusenSuuchi[index]; }
			void set(int index, double value) { m_pHeader->m_adFukusenSuuchi[index] = value; }
		}
			property double m_dRyoygawaFukusenTomeDe {
			double get() { return m_pHeader->m_dRyoygawaFukusenTomeDe; }
			void set(double value) { m_pHeader->m_dRyoygawaFukusenTomeDe = value; }
		}


		property int m_aPenColor[int]{
			int get(int index) { return m_pHeader->m_aPenColor[index]; }
			void set(int index, int value) { m_pHeader->m_aPenColor[index] = value; }
		}
			property int m_anPenWidth[int]{
				int get(int index) { return m_pHeader->m_anPenWidth[index]; }
				void set(int index, int value) { m_pHeader->m_anPenWidth[index] = value; }
		}
			property int m_aPrtPenColor[int]{
				int get(int index) { return m_pHeader->m_aPrtPenColor[index]; }
				void set(int index, int value) { m_pHeader->m_aPrtPenColor[index] = value; }
		}
			property int m_anPrtPenWidth[int]{
				int get(int index) { return m_pHeader->m_anPrtPenWidth[index]; }
				void set(int index, int value) { m_pHeader->m_anPrtPenWidth[index] = value; }
		}
			property double m_adPrtTenHankei[int]{
				double get(int index) { return m_pHeader->m_adPrtTenHankei[index]; }
				void set(int index, double value) { m_pHeader->m_adPrtTenHankei[index] = value; }
		};

		//◆ 線種番号2から9までのパターン、1ユニットのドット数、ピッチ、プリンタ出⼒ピッチ
		property int m_alLType[int]{
			int get(int index) { return m_pHeader->m_alLType[index]; }
			void set(int index, int value) { m_pHeader->m_alLType[index] = value; }
		};
		property int m_anTokushuSenUintDot[int]{
			int get(int index) { return m_pHeader->m_anTokushuSenUintDot[index]; }
			void set(int index, int value) { m_pHeader->m_anTokushuSenUintDot[index] = value; }
		};
		property int m_anTokushuSenPich[int]{
			int get(int index) { return m_pHeader->m_anTokushuSenPich[index]; }
			void set(int index, int value) { m_pHeader->m_anTokushuSenPich[index] = value; }
		};
		property int m_anPrtTokushuSenPich[int]{
			int get(int index) { return m_pHeader->m_anPrtTokushuSenPich[index]; }
			void set(int index, int value) { m_pHeader->m_anPrtTokushuSenPich[index] = value; }
		};
		//◆ ランダム線1から5までのパターン、画⾯表⽰振幅・ピッチ、プリンタ出⼒振幅・ピッチ
		property int m_alLType_Rnd[int]{
			int get(int index) { return m_pHeader->m_alLType_Rnd[index]; }
			void set(int index, int value) { m_pHeader->m_alLType_Rnd[index] = value; }
		};
		property int m_anRandSenWide_Rnd[int]{
			int get(int index) { return m_pHeader->m_anRandSenWide_Rnd[index]; }
			void set(int index, int value) { m_pHeader->m_anRandSenWide_Rnd[index] = value; }
		};
		property int m_anTokushuSenPich_Rnd[int]{
			int get(int index) { return m_pHeader->m_anTokushuSenPich_Rnd[index]; }
			void set(int index, int value) { m_pHeader->m_anTokushuSenPich_Rnd[index] = value; }
		};
		property int m_anPrtRandSenWide_Rnd[int]{
			int get(int index) { return m_pHeader->m_anPrtRandSenWide_Rnd[index]; }
			void set(int index, int value) { m_pHeader->m_anPrtRandSenWide_Rnd[index] = value; }
		};
		property int m_anPrtTokushuSenPich_Rnd[int]{
			int get(int index) { return m_pHeader->m_anPrtTokushuSenPich_Rnd[index]; }
			void set(int index, int value) { m_pHeader->m_anPrtTokushuSenPich_Rnd[index] = value; }
		};
		//◆ 倍⻑線種番号6から9までのパターン、1ユニットのドット数、ピッチ、プリンタ出⼒ピッチ
		property int m_alLType_Double[int]{
			int get(int index) { return m_pHeader->m_alLType_Double[index]; }
			void set(int index, int value) { m_pHeader->m_alLType_Double[index] = value; }
		};
		property int m_anTokushuSenUintDot_Double[int]{
			int get(int index) { return m_pHeader->m_anTokushuSenUintDot_Double[index]; }
			void set(int index, int value) { m_pHeader->m_anTokushuSenUintDot_Double[index] = value; }
		};
		property int m_anTokushuSenPich_Double[int]{
			int get(int index) { return m_pHeader->m_anTokushuSenPich_Double[index]; }
			void set(int index, int value) { m_pHeader->m_anTokushuSenPich_Double[index] = value; }
		};
		property int m_anPrtTokushuSenPich_Double[int]{
			int get(int index) { return m_pHeader->m_anPrtTokushuSenPich_Double[index]; }
			void set(int index, int value) { m_pHeader->m_anPrtTokushuSenPich_Double[index] = value; }
		};

		//◆ 実点を画⾯描画時の指定半径で描画
		property int m_nDrawGamenTen {
			int get() { return m_pHeader->m_nDrawGamenTen; }
			void set(int value) { m_pHeader->m_nDrawGamenTen = value; }
		};
		//◆ 実点をプリンタ出⼒時、指定半径で書く
		property int m_nDrawPrtTen {
			int get() { return m_pHeader->m_nDrawPrtTen; }
			void set(int value) { m_pHeader->m_nDrawPrtTen = value; }
		};
		//◆ BitMap・ソリッドを最初に描画する //⼗位︓ソリッド描画順
		property int m_nBitMapFirstDraw {
			int get() { return m_pHeader->m_nBitMapFirstDraw; }
			void set(int value) { m_pHeader->m_nBitMapFirstDraw = value; }
		};


		//◆ 逆描画
		property int m_nGyakuDraw {
			int get() { return m_pHeader->m_nGyakuDraw; }
			void set(int value) { m_pHeader->m_nGyakuDraw = value; }
		};
		//◆ 逆サーチ
		property int m_nGyakuSearch {
			int get() { return m_pHeader->m_nGyakuSearch; }
			void set(int value) { m_pHeader->m_nGyakuSearch = value; }
		};
		//◆ カラー印刷
		property int m_nColorPrint {
			int get() { return m_pHeader->m_nColorPrint; }
			void set(int value) { m_pHeader->m_nColorPrint = value; }
		}
		//◆ レイヤ順の印刷
		property int m_nLayJunPrint {
			int get() { return m_pHeader->m_nLayJunPrint; }
			void set(int value) { m_pHeader->m_nLayJunPrint = value; }
		}
		//◆ ⾊番号順の印刷
		property int m_nColJunPrint {
			int get() { return m_pHeader->m_nColJunPrint; }
			void set(int value) { m_pHeader->m_nColJunPrint = value; }
		}
		//◆ レイヤグループまたはレイヤごとのプリンタ連続出⼒指定
		property int m_nPrtRenzoku {
			int get() { return m_pHeader->m_nPrtRenzoku; }
			void set(int value) { m_pHeader->m_nPrtRenzoku = value; }
		}
		//◆ プリンタ共通レイヤ(表⽰のみレイヤ)のグレー出⼒指定
		property int m_nPrtKyoutsuuGray {
			int get() { return m_pHeader->m_nPrtKyoutsuuGray; }
			void set(int value) { m_pHeader->m_nPrtKyoutsuuGray = value; }
		}
		//◆ プリンタ出⼒時に表⽰のみレイヤは出⼒しない
		//	Ver.6.00以降は印刷時における既定線⾊の線幅の基準値の「dpi」。
		property int m_nPrtDispOnlyNonDraw {
			int get() { return m_pHeader->m_nPrtDispOnlyNonDraw; }
			void set(int value) { m_pHeader->m_nPrtDispOnlyNonDraw = value; }
		}
		//◆ 作図時間（Ver.2.23以降）
		property int m_lnDrawTime {
			int get() { return m_pHeader->m_lnDrawTime; }
			void set(int value) { m_pHeader->m_lnDrawTime = value; }
		}
		//◆ 2.5Dの始点位置が設定されている時のフラグ（Ver.2.23以降）
			//● ⼀位︓透視図の視点位置設定済みフラグ
			//● ⼗位︓⿃瞰図の視点位置設定済みフラグ
			//● 百位︓アイソメ図の視点位置設定済みフラグ
		property int nEyeInit {
			int get() { return m_pHeader->nEyeInit; }
			void set(int value) { m_pHeader->nEyeInit = value; }
		}
		//◆ 2.5Dの透視図・⿃瞰図・アイソメ図の視点⽔平角（Ver.2.23以降）
		property int m_dEye_H_Ichi_1 {
			int get() { return m_pHeader->m_dEye_H_Ichi_1; }
			void set(int value) { m_pHeader->m_dEye_H_Ichi_1 = value; }
		}
		property int m_dEye_H_Ichi_2 {
			int get() { return m_pHeader->m_dEye_H_Ichi_2; }
			void set(int value) { m_pHeader->m_dEye_H_Ichi_2 = value; }
		}
		property int m_dEye_H_Ichi_3 {
			int get() { return m_pHeader->m_dEye_H_Ichi_3; }
			void set(int value) { m_pHeader->m_dEye_H_Ichi_3 = value; }
		}
		//◆ 2.5Dの透視図の視点⾼さ・視点離れ（Ver.2.23以降）
		property double m_dEye_Z_Ichi_1 {
			double get() { return m_pHeader->m_dEye_Z_Ichi_1; }
			void set(double value) { m_pHeader->m_dEye_Z_Ichi_1 = value; }
		}
		property double m_dEye_Y_Ichi_1 {
			double get() { return m_pHeader->m_dEye_Y_Ichi_1; }
			void set(double value) { m_pHeader->m_dEye_Y_Ichi_1 = value; }
		}
		//◆ 2.5Dの⿃瞰図の視点⾼さ・視点離れ（Ver.2.23以降）
		property double m_dEye_Z_Ichi_2 {
			double get() { return m_pHeader->m_dEye_Z_Ichi_2; }
			void set(double value) { m_pHeader->m_dEye_Z_Ichi_2 = value; }
		}
		property double m_dEye_Y_Ichi_2 {
			double get() { return m_pHeader->m_dEye_Y_Ichi_2; }
			void set(double value) { m_pHeader->m_dEye_Y_Ichi_2 = value; }
		}
		//◆ 2.5Dのアイソメ図の視点垂直角（Ver.2.23以降）
		property double m_dEye_V_Ichi_3 {
			double get() { return m_pHeader->m_dEye_V_Ichi_3; }
			void set(double value) { m_pHeader->m_dEye_V_Ichi_3 = value; }
		}
		//◆ 線の⻑さ指定の最終値（Ver.2.25以降）
		property double m_dSenNagasaSnpou {
			double get() { return m_pHeader->m_dSenNagasaSnpou; }
			void set(double value) { m_pHeader->m_dSenNagasaSnpou = value; }
		}
		//◆ 矩形寸法横寸法・縦寸法指定の最終値（Ver.2.25以降）
		property double m_dBoxSunpouX {
			double get() { return m_pHeader->m_dBoxSunpouX; }
			void set(double value) { m_pHeader->m_dBoxSunpouX = value; }
		}
		property double m_dBoxSunpouY {
			double get() { return m_pHeader->m_dBoxSunpouY; }
			void set(double value) { m_pHeader->m_dBoxSunpouY = value; }
		}
		//◆ 円の半径指定の最終値（Ver.2.25以降）
		property double m_dEnHankeiSnpou {
			double get() { return m_pHeader->m_dEnHankeiSnpou; }
			void set(double value) { m_pHeader->m_dEnHankeiSnpou = value; }
		}
		//◆ ソリッドを任意⾊で書くフラグ、ソリッドの任意⾊の既定値（Ver.2.30以降）
		property int m_nSolidNinniColor {
			int get() { return m_pHeader->m_nSolidNinniColor; }
			void set(int value) { m_pHeader->m_nSolidNinniColor = value; }
		}
		property int m_SolidColor {
			int get() { return m_pHeader->m_SolidColor; }
			void set(int value) { m_pHeader->m_SolidColor = value; }
		}
		//◆ SXF対応拡張線⾊定義（Ver.4.20以降）
			//● 画⾯表⽰⾊
			//● 画⾯表⽰線幅
			//● 線⾊名
			//● プリンタ出⼒⾊
			//● プリンタ出⼒線幅
			//● 点半径
		property int m_aPenColor_SXF[int]{
			int get(int index) { return m_pHeader->m_aPenColor_SXF[index]; }
			void set(int index, int value) { m_pHeader->m_aPenColor_SXF[index] = value; }
		};
		property int m_anPenWidth_SXF[int]{
			int get(int index) { return m_pHeader->m_anPenWidth_SXF[index]; }
			void set(int index, int value) { m_pHeader->m_anPenWidth_SXF[index] = value; }
		};
		property int m_aPrtPenColor_SXF[int]{
			int get(int index) { return m_pHeader->m_aPrtPenColor_SXF[index]; }
			void set(int index, int value) { m_pHeader->m_aPrtPenColor_SXF[index] = value; }
		};
		property int m_anPrtPenWidth_SXF[int]{
			int get(int index) { return m_pHeader->m_anPrtPenWidth_SXF[index]; }
			void set(int index, int value) { m_pHeader->m_anPrtPenWidth_SXF[index] = value; }
		};
		property double m_adPrtTenHankei_SXF[int]{
			double get(int index) { return m_pHeader->m_adPrtTenHankei_SXF[index]; }
			void set(int index, double value) { m_pHeader->m_adPrtTenHankei_SXF[index] = value; }
		};

		//◆ SXF対応拡張線種定義（Ver.4.20以降）
		//● パターン
		//● 1ユニットのドット数
		//● ピッチ
		//● プリンタ出⼒ピッチ
		//● 線種名
		//● セグメント数
		//● ピッチ線分の⻑さ、空⽩⻑さの繰り返し
		property int m_alLType_SXF[int]{
			int get(int index) { return m_pHeader->m_alLType_SXF[index]; }
			void set(int index, int value) { m_pHeader->m_alLType_SXF[index] = value; }
		};
		property int m_anTokushuSenUintDot_SXF[int]{
			int get(int index) { return m_pHeader->m_anTokushuSenUintDot_SXF[index]; }
			void set(int index, int value) { m_pHeader->m_anTokushuSenUintDot_SXF[index] = value; }
		};
		property int m_anTokushuSenPich_SXF[int]{
			int get(int index) { return m_pHeader->m_anTokushuSenPich_SXF[index]; }
			void set(int index, int value) { m_pHeader->m_anTokushuSenPich_SXF[index] = value; }
		};
		property int m_anPrtTokushuSenPich_SXF[int]{
			int get(int index) { return m_pHeader->m_anPrtTokushuSenPich_SXF[index]; }
			void set(int index, int value) { m_pHeader->m_anPrtTokushuSenPich_SXF[index] = value; }
		};
		property int m_anUDLTypeSegment_SXF[int]{
			int get(int index) { return m_pHeader->m_anUDLTypeSegment_SXF[index]; }
			void set(int index, int value) { m_pHeader->m_anUDLTypeSegment_SXF[index] = value; }
		};
		property double m_aadUDLTypePitch_SXF[int]{
			double get(int index) { return m_pHeader->m_aadUDLTypePitch_SXF[index / 10][index % 10]; }
			void set(int index, double value) { m_pHeader->m_aadUDLTypePitch_SXF[index / 10][index % 10] = value; }
		};

		//◆ ⽂字種1から10までの⽂字幅、⾼さ、間隔、⾊番号
		property double m_adMojiX[int]{
			double get(int index) { return m_pHeader->m_adMojiX[index]; }
			void set(int index, double value) { m_pHeader->m_adMojiX[index] = value; }
		};
		property double m_adMojiY[int]{
			double get(int index) { return m_pHeader->m_adMojiY[index]; }
			void set(int index, double value) { m_pHeader->m_adMojiY[index] = value; }
		};
		property double m_adMojiD[int]{
			double get(int index) { return m_pHeader->m_adMojiD[index]; }
			void set(int index, double value) { m_pHeader->m_adMojiD[index] = value; }
		};
		property int m_anMojiCol[int]{
			int get(int index) { return m_pHeader->m_anMojiCol[index]; }
			void set(int index, int value) { m_pHeader->m_anMojiCol[index] = value; }
		};

		//◆ 書込み⽂字の⽂字幅、⾼さ、間隔、⾊番号、⽂字番号
		property double m_dMojiSizeX {
			double get() { return m_pHeader->m_dMojiSizeX; }
			void set(double value) { m_pHeader->m_dMojiSizeX = value; }
		};
		property double m_dMojiSizeY {
			double get() { return m_pHeader->m_dMojiSizeY; }
			void set(double value) { m_pHeader->m_dMojiSizeY = value; }
		};
		property double m_dMojiKankaku {
			double get() { return m_pHeader->m_dMojiKankaku; }
			void set(double value) { m_pHeader->m_dMojiKankaku = value; }
		};
		property int m_nMojiColor {
			int get() { return m_pHeader->m_nMojiColor; }
			void set(int value) { m_pHeader->m_nMojiColor = value; }
		};
		property int m_nMojiShu {
			int get() { return m_pHeader->m_nMojiShu; }
			void set(int value) { m_pHeader->m_nMojiShu = value; }
		};
		//◆ ⽂字位置整理の⾏間、⽂字数
		property double m_dMojiSeiriGyouKan {
			double get() { return m_pHeader->m_dMojiSeiriGyouKan; }
			void set(double value) { m_pHeader->m_dMojiSeiriGyouKan = value; }
		};
		property double m_dMojiSeiriSuu {
			double get() { return m_pHeader->m_dMojiSeiriSuu; }
			void set(double value) { m_pHeader->m_dMojiSeiriSuu = value; }
		};
		//◆ ⽂字基準点のずれ位置使⽤のフラグ
		property int m_nMojiKijunZureOn {
			int get() { return m_pHeader->m_nMojiKijunZureOn; }
			void set(int value) { m_pHeader->m_nMojiKijunZureOn = value; }
		};
		//◆ ⽂字基準点の横⽅向のずれ位置左、中、右
		property double m_adMojiKijunZureX[int]{
			double get(int index) { return m_pHeader->m_adMojiKijunZureX[index]; }
			void set(int index, double value) { m_pHeader->m_adMojiKijunZureX[index] = value; }
		};
		//◆ ⽂字基準点の縦⽅向のずれ位置下、中、上
		property double m_adMojiKijunZureY[int]{
			double get(int index) { return m_pHeader->m_adMojiKijunZureY[index]; }
			void set(int index, double value) { m_pHeader->m_adMojiKijunZureY[index] = value; }
		};

	internal:
		CJwwHeader* m_pHeader;
	};

}