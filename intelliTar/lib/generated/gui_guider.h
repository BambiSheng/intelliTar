/*
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

    typedef struct
    {

        lv_obj_t *screen;
        bool screen_del;
        lv_obj_t *screen_cont_1;
        lv_obj_t *screen_label_1;
        lv_obj_t *screen_datetext_1;
        lv_obj_t *screen_img_1;
        lv_obj_t *screen_btn_1;
        lv_obj_t *screen_btn_1_label;
        lv_obj_t *screen_btn_2;
        lv_obj_t *screen_btn_2_label;
        lv_obj_t *screen_btn_3;
        lv_obj_t *screen_btn_3_label;
        lv_obj_t *screen_btn_4;
        lv_obj_t *screen_btn_4_label;
        lv_obj_t *screen_imgbtn_1;
        lv_obj_t *screen_imgbtn_1_label;
        lv_obj_t *screen_imgbtn_2;
        lv_obj_t *screen_imgbtn_2_label;
        lv_obj_t *screen_imgbtn_3;
        lv_obj_t *screen_imgbtn_3_label;
        lv_obj_t *screen_imgbtn_4;
        lv_obj_t *screen_imgbtn_4_label;
        lv_obj_t *Tunerhome;
        bool Tunerhome_del;
        lv_obj_t *Tunerhome_cont_1;
        lv_obj_t *Tunerhome_btn_1;
        lv_obj_t *Tunerhome_btn_1_label;
        lv_obj_t *Tunerhome_label_3;
        lv_obj_t *Tunerhome_label_1;
        lv_obj_t *Tunerhome_meter_1;
        lv_meter_indicator_t *Tunerhome_meter_1_scale_1_ndline_0;
        lv_obj_t *Tunerhome_btnm_1;
        lv_obj_t *Tunerhome_sw_1;
        lv_obj_t *Tunerhome_label_2;
        lv_obj_t *Metronomehome;
        bool Metronomehome_del;
        lv_obj_t *Metronomehome_cont_1;
        lv_obj_t *Metronomehome_btn_4;
        lv_obj_t *Metronomehome_btn_4_label;
        lv_obj_t *Metronomehome_meter_1;
        lv_meter_indicator_t *Metronomehome_meter_1_scale_1_ndline_0;
        lv_obj_t *Metronomehome_slider_1;
        lv_obj_t *Metronomehome_label_1;
        lv_obj_t *Metronomehome_btn_1;
        lv_obj_t *Metronomehome_btn_1_label;
        lv_obj_t *Metronomehome_btn_2;
        lv_obj_t *Metronomehome_btn_2_label;
        lv_obj_t *Metronomehome_spangroup_1;
        lv_obj_t *Metronomehome_btn_5;
        lv_obj_t *Metronomehome_btn_5_label;
        lv_obj_t *Pagehome;
        bool Pagehome_del;
        lv_obj_t *Pagehome_cont_1;
        lv_obj_t *Pagehome_btn_4;
        lv_obj_t *Pagehome_btn_4_label;
        lv_obj_t *Pagehome_ddlist_1;
        lv_obj_t *Pagehome_btn_2;
        lv_obj_t *Pagehome_btn_2_label;
        lv_obj_t *Pagehome_label_2;
        lv_obj_t *Pagehome_label_1;
        lv_obj_t *Pagehome_btn_5;
        lv_obj_t *Pagehome_btn_5_label;
        lv_obj_t *Pagehome_btn_6;
        lv_obj_t *Pagehome_btn_6_label;
        lv_obj_t *Pagehome_slider_1;
        lv_obj_t *Pagehome_spangroup_1;
        lv_obj_t *TurnerAutoHome;
        bool TurnerAutoHome_del;
        lv_obj_t *TurnerAutoHome_cont_1;
        lv_obj_t *TurnerAutoHome_btn_2;
        lv_obj_t *TurnerAutoHome_btn_2_label;
        lv_obj_t *TurnerAutoHome_sw_1;
        lv_obj_t *TurnerAutoHome_label_4;
        lv_obj_t *TurnerAutoHome_label_1;
        lv_obj_t *TurnerAutoHome_meter_1;
        lv_meter_indicator_t *TurnerAutoHome_meter_1_scale_1_ndline_0;
        lv_obj_t *TurnerAutoHome_label_3;
        lv_obj_t *Musicsheetpresenter;
        bool Musicsheetpresenter_del;
        lv_obj_t *Musicsheetpresenter_cont_1;
        lv_obj_t *Musicsheetpresenter_btn_2;
        lv_obj_t *Musicsheetpresenter_btn_2_label;
        lv_obj_t *Musicsheetpresenter_btn_3;
        lv_obj_t *Musicsheetpresenter_btn_3_label;
        lv_obj_t *Musicsheetpresenter_btn_1;
        lv_obj_t *Musicsheetpresenter_btn_1_label;
        lv_obj_t *Musicsheetpresenter_label_1;
        lv_obj_t *Settings;
        bool Settings_del;
        lv_obj_t *Settings_label_3;
        lv_obj_t *Settings_cont_1;
        lv_obj_t *Settings_btn_1;
        lv_obj_t *Settings_btn_1_label;
        lv_obj_t *Settings_label_2;
        lv_obj_t *Settings_label_1;
        lv_obj_t *Settings_ta_1;
        lv_obj_t *Settings_label_name;
        lv_obj_t *Settings_ta_2;
        lv_obj_t *Settings_label_pwd;
        lv_obj_t *kb;
        lv_obj_t *kb1;
    } lv_ui;

    void ui_init_style(lv_style_t *style);
    void init_scr_del_flag(lv_ui *ui);
    void setup_ui(lv_ui *ui);
    extern lv_ui guider_ui;

    void setup_scr_screen(lv_ui *ui);
    void setup_scr_Tunerhome(lv_ui *ui);
    void setup_scr_Metronomehome(lv_ui *ui);
    void setup_scr_Pagehome(lv_ui *ui);
    void setup_scr_TurnerAutoHome(lv_ui *ui);
    void setup_scr_Musicsheetpresenter(lv_ui *ui);
    void setup_scr_Settings(lv_ui *ui);
    LV_IMG_DECLARE(_Cover_alpha_308x238);
    LV_IMG_DECLARE(_tuner_alpha_59x58);
    LV_IMG_DECLARE(_metro_alpha_68x47);
    LV_IMG_DECLARE(_tone_alpha_56x43);
    LV_IMG_DECLARE(_setup_alpha_36x34);

    LV_FONT_DECLARE(lv_font_Acme_Regular_25)
    LV_FONT_DECLARE(lv_font_montserratMedium_16)
    LV_FONT_DECLARE(lv_font_Alatsi_Regular_22)
    LV_FONT_DECLARE(lv_font_montserratMedium_12)
    LV_FONT_DECLARE(lv_font_simsun_14)
    LV_FONT_DECLARE(lv_font_montserratMedium_20)
    LV_FONT_DECLARE(lv_font_arial_15)
    LV_FONT_DECLARE(lv_font_arial_17)
    LV_FONT_DECLARE(lv_font_montserratMedium_70)
    LV_FONT_DECLARE(lv_font_Alatsi_Regular_18)
    LV_FONT_DECLARE(lv_font_montserratMedium_17)
    LV_FONT_DECLARE(lv_font_simsun_18)
    LV_FONT_DECLARE(lv_font_montserratMedium_14)
    LV_FONT_DECLARE(lv_font_montserratMedium_18)
    LV_FONT_DECLARE(lv_font_Alatsi_Regular_19)
    LV_FONT_DECLARE(lv_font_simsun_16)
    LV_FONT_DECLARE(lv_font_simsun_12)
#ifdef __cplusplus
}
#endif
#endif
