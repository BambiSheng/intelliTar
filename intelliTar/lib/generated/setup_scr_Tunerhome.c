/*
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"

extern int currentFrequency;
extern int targetFrequency;
extern int frequency;

void setup_scr_Tunerhome(lv_ui *ui)
{
    // Write codes Tunerhome
    ui->Tunerhome = lv_obj_create(NULL);
    lv_obj_set_size(ui->Tunerhome, 480, 320);
    //lv_obj_clear_flag(guider_ui.Tunerhome, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_scrollbar_mode(ui->Tunerhome, LV_SCROLLBAR_MODE_OFF);

    // Write style for Tunerhome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Tunerhome, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Tunerhome, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Tunerhome_cont_1
    ui->Tunerhome_cont_1 = lv_obj_create(ui->Tunerhome);
    lv_obj_set_pos(ui->Tunerhome_cont_1, 0, 0);
    lv_obj_set_size(ui->Tunerhome_cont_1, 480, 58);
    lv_obj_set_scrollbar_mode(ui->Tunerhome_cont_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Tunerhome_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Tunerhome_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Tunerhome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Tunerhome_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Tunerhome_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Tunerhome_cont_1, lv_color_hex(0x2F3243), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Tunerhome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Tunerhome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Tunerhome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Tunerhome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Tunerhome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Tunerhome_btn_1
    ui->Tunerhome_btn_1 = lv_btn_create(ui->Tunerhome_cont_1);
    ui->Tunerhome_btn_1_label = lv_label_create(ui->Tunerhome_btn_1);
    lv_label_set_text(ui->Tunerhome_btn_1_label, "Return\n");
    lv_label_set_long_mode(ui->Tunerhome_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Tunerhome_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Tunerhome_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Tunerhome_btn_1, 10, 7);
    lv_obj_set_size(ui->Tunerhome_btn_1, 60, 35);
    lv_obj_set_scrollbar_mode(ui->Tunerhome_btn_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Tunerhome_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Tunerhome_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Tunerhome_btn_1, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Tunerhome_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_btn_1, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Tunerhome_btn_1, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Tunerhome_btn_1, lv_color_hex(0x0d4b3b), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Tunerhome_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Tunerhome_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Tunerhome_btn_1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Tunerhome_btn_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Tunerhome_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Tunerhome_btn_1, &lv_font_simsun_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Tunerhome_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Tunerhome_label_3
    ui->Tunerhome_label_3 = lv_label_create(ui->Tunerhome_cont_1);
    lv_label_set_text(ui->Tunerhome_label_3, "Auto");
    lv_label_set_long_mode(ui->Tunerhome_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Tunerhome_label_3, 322, 16);
    lv_obj_set_size(ui->Tunerhome_label_3, 130, 32);
    lv_obj_set_scrollbar_mode(ui->Tunerhome_label_3, LV_SCROLLBAR_MODE_OFF);

    // Write style for Tunerhome_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Tunerhome_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Tunerhome_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Tunerhome_label_3, &lv_font_arial_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Tunerhome_label_3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Tunerhome_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Tunerhome_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Tunerhome_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Tunerhome_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Tunerhome_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Tunerhome_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Tunerhome_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Tunerhome_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Tunerhome_label_1
    ui->Tunerhome_label_1 = lv_label_create(ui->Tunerhome);
    lv_label_set_text(ui->Tunerhome_label_1, "Tuner");
    lv_label_set_long_mode(ui->Tunerhome_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Tunerhome_label_1, 175, 17);
    lv_obj_set_size(ui->Tunerhome_label_1, 130, 32);
    lv_obj_set_scrollbar_mode(ui->Tunerhome_label_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Tunerhome_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Tunerhome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Tunerhome_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Tunerhome_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Tunerhome_label_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Tunerhome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Tunerhome_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Tunerhome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Tunerhome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Tunerhome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Tunerhome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Tunerhome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Tunerhome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Tunerhome_meter_1
    ui->Tunerhome_meter_1 = lv_meter_create(ui->Tunerhome);
    // add scale Tunerhome_meter_1_scale_1
    lv_meter_scale_t *Tunerhome_meter_1_scale_1 = lv_meter_add_scale(ui->Tunerhome_meter_1);
    lv_meter_set_scale_ticks(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, 60, 2, 10, lv_color_hex(0x00ff71));
    lv_meter_set_scale_major_ticks(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, 6, 5, 16, lv_color_hex(0x29ff00), 10);
    lv_meter_set_scale_range(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, -50, 49, 180, 180);
    // add arc for Tunerhome_meter_1_scale_1
    lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_0;
    Tunerhome_meter_1_scale_1_arc_0 = lv_meter_add_arc(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0xff0000), 0);
    lv_meter_set_indicator_start_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_0, -50);
    lv_meter_set_indicator_end_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_0, -30);

    // add arc for Tunerhome_meter_1_scale_1
    lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_1;
    Tunerhome_meter_1_scale_1_arc_1 = lv_meter_add_arc(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0xff8b3f), 0);
    lv_meter_set_indicator_start_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_1, -30);
    lv_meter_set_indicator_end_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_1, -10);

    // add arc for Tunerhome_meter_1_scale_1
    lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_2;
    Tunerhome_meter_1_scale_1_arc_2 = lv_meter_add_arc(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0x00ff00), 0);
    lv_meter_set_indicator_start_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_2, -10);
    lv_meter_set_indicator_end_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_2, 0);

    // add arc for Tunerhome_meter_1_scale_1
    lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_3;
    Tunerhome_meter_1_scale_1_arc_3 = lv_meter_add_arc(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0x00ff00), 0);
    lv_meter_set_indicator_start_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_3, 0);
    lv_meter_set_indicator_end_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_3, 10);

    // add arc for Tunerhome_meter_1_scale_1
    lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_4;
    Tunerhome_meter_1_scale_1_arc_4 = lv_meter_add_arc(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0xff8b3f), 0);
    lv_meter_set_indicator_start_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_4, 10);
    lv_meter_set_indicator_end_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_4, 30);

    // add arc for Tunerhome_meter_1_scale_1
    lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_5;
    Tunerhome_meter_1_scale_1_arc_5 = lv_meter_add_arc(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0xff0000), 0);
    lv_meter_set_indicator_start_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_5, 30);
    lv_meter_set_indicator_end_value(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1_arc_5, 50);

    // add needle line for Tunerhome_meter_1_scale_1.
    ui->Tunerhome_meter_1_scale_1_ndline_0 = lv_meter_add_needle_line(ui->Tunerhome_meter_1, Tunerhome_meter_1_scale_1, 5, lv_color_hex(0x000000), -10);
    lv_meter_set_indicator_value(ui->Tunerhome_meter_1, ui->Tunerhome_meter_1_scale_1_ndline_0, currentFrequency - targetFrequency);
    lv_obj_set_pos(ui->Tunerhome_meter_1, 5, 58);
    lv_obj_set_size(ui->Tunerhome_meter_1, 294, 295);
    lv_obj_set_scrollbar_mode(ui->Tunerhome_meter_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Tunerhome_meter_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Tunerhome_meter_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Tunerhome_meter_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_meter_1, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Tunerhome_meter_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Tunerhome_meter_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Tunerhome_meter_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Tunerhome_meter_1, lv_color_hex(0xff0000), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Tunerhome_meter_1, &lv_font_montserratMedium_12, LV_PART_TICKS | LV_STATE_DEFAULT);

    // Write codes Tunerhome_btnm_1
    ui->Tunerhome_btnm_1 = lv_btnmatrix_create(ui->Tunerhome);
    static const char *Tunerhome_btnm_1_text_map[] = {
        "C",
        "E",
        "\n",
        "G",
        "A",
        "",
    };
    lv_btnmatrix_set_map(ui->Tunerhome_btnm_1, Tunerhome_btnm_1_text_map);
    lv_obj_set_pos(ui->Tunerhome_btnm_1, 306, 97);
    lv_obj_set_size(ui->Tunerhome_btnm_1, 138, 120);
    lv_obj_set_scrollbar_mode(ui->Tunerhome_btnm_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Tunerhome_btnm_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Tunerhome_btnm_1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Tunerhome_btnm_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Tunerhome_btnm_1, lv_color_hex(0xc9c9c9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Tunerhome_btnm_1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Tunerhome_btnm_1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Tunerhome_btnm_1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Tunerhome_btnm_1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui->Tunerhome_btnm_1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui->Tunerhome_btnm_1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_btnm_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Tunerhome_btnm_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Tunerhome_btnm_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Tunerhome_btnm_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Tunerhome_btnm_1, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Tunerhome_btnm_1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Tunerhome_btnm_1, lv_color_hex(0xc9c9c9), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Tunerhome_btnm_1, lv_color_hex(0xffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Tunerhome_btnm_1, &lv_font_montserratMedium_16, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_btnm_1, 4, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Tunerhome_btnm_1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Tunerhome_btnm_1, lv_color_hex(0x2195f6), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Tunerhome_btnm_1, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);

    // Write codes Tunerhome_sw_1
    ui->Tunerhome_sw_1 = lv_switch_create(ui->Tunerhome);
    lv_obj_set_pos(ui->Tunerhome_sw_1, 413, 17);
    lv_obj_set_size(ui->Tunerhome_sw_1, 40, 19);
    lv_obj_set_scrollbar_mode(ui->Tunerhome_sw_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Tunerhome_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Tunerhome_sw_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Tunerhome_sw_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Tunerhome_sw_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Tunerhome_sw_1, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Tunerhome_sw_1, lv_color_hex(0x00bdff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_sw_1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Tunerhome_sw_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Tunerhome_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Tunerhome_sw_1, 223, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Tunerhome_sw_1, lv_color_hex(0x878787), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Tunerhome_sw_1, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);

    // Write style for Tunerhome_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Tunerhome_sw_1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Tunerhome_sw_1, lv_color_hex(0xf78585), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Tunerhome_sw_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_sw_1, 100, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write style for Tunerhome_sw_1, Part: LV_PART_KNOB, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->Tunerhome_sw_1, 255, LV_PART_KNOB | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->Tunerhome_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->Tunerhome_sw_1, 0, LV_PART_KNOB | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->Tunerhome_sw_1, 100, LV_PART_KNOB | LV_STATE_FOCUSED);

    // Write codes Tunerhome_label_2
    ui->Tunerhome_label_2 = lv_label_create(ui->Tunerhome);
    if (targetFrequency >= 255 && targetFrequency <= 265)
    {
        lv_label_set_text(ui->Tunerhome_label_2, "C");
    }
    else if (targetFrequency == 322)
    {
        lv_label_set_text(ui->Tunerhome_label_2, "E");
    }
    else if (targetFrequency == 392)
    {
        lv_label_set_text(ui->Tunerhome_label_2, "G");
    }
    else if (targetFrequency == 440)
    {
        lv_label_set_text(ui->Tunerhome_label_2, "A");
    }
    else
    {
        lv_label_set_text(ui->Tunerhome_label_2, " ");
    }
    lv_label_set_long_mode(ui->Tunerhome_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Tunerhome_label_2, 90, 216);
    lv_obj_set_size(ui->Tunerhome_label_2, 100, 32);
    lv_obj_set_scrollbar_mode(ui->Tunerhome_label_2, LV_SCROLLBAR_MODE_OFF);

    // Write style for Tunerhome_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Tunerhome_label_2, lv_color_hex(0xff0027), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Tunerhome_label_2, &lv_font_montserratMedium_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Tunerhome_label_2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Tunerhome_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Update current screen layout.
    lv_obj_update_layout(ui->Tunerhome);

    // Init events for screen.
    events_init_Tunerhome(ui);
}
