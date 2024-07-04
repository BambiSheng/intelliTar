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
#include <stdlib.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"

extern int MetroPointerAngle;
void setup_scr_Metronomehome(lv_ui *ui)
{
    // Write codes Metronomehome
    ui->Metronomehome = lv_obj_create(NULL);
    lv_obj_set_size(ui->Metronomehome, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Metronomehome, LV_SCROLLBAR_MODE_OFF);

    // Write style for Metronomehome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Metronomehome, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Metronomehome, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Metronomehome_cont_1
    ui->Metronomehome_cont_1 = lv_obj_create(ui->Metronomehome);
    lv_obj_set_pos(ui->Metronomehome_cont_1, 0, 0);
    lv_obj_set_size(ui->Metronomehome_cont_1, 480, 58);
    lv_obj_set_scrollbar_mode(ui->Metronomehome_cont_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Metronomehome_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Metronomehome_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Metronomehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Metronomehome_cont_1, lv_color_hex(0xff0027), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Metronomehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Metronomehome_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Metronomehome_cont_1, lv_color_hex(0x2F3243), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Metronomehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Metronomehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Metronomehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Metronomehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Metronomehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Metronomehome_btn_4
    ui->Metronomehome_btn_4 = lv_btn_create(ui->Metronomehome_cont_1);
    ui->Metronomehome_btn_4_label = lv_label_create(ui->Metronomehome_btn_4);
    lv_label_set_text(ui->Metronomehome_btn_4_label, "Return\n");
    lv_label_set_long_mode(ui->Metronomehome_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Metronomehome_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Metronomehome_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Metronomehome_btn_4, 12, 7);
    lv_obj_set_size(ui->Metronomehome_btn_4, 60, 35);
    lv_obj_set_scrollbar_mode(ui->Metronomehome_btn_4, LV_SCROLLBAR_MODE_OFF);

    // Write style for Metronomehome_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Metronomehome_btn_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Metronomehome_btn_4, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Metronomehome_btn_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Metronomehome_btn_4, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Metronomehome_btn_4, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Metronomehome_btn_4, lv_color_hex(0x0d4b3b), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Metronomehome_btn_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Metronomehome_btn_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Metronomehome_btn_4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Metronomehome_btn_4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Metronomehome_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Metronomehome_btn_4, &lv_font_simsun_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Metronomehome_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Metronomehome_meter_1
    ui->Metronomehome_meter_1 = lv_meter_create(ui->Metronomehome);
    // add scale Metronomehome_meter_1_scale_1
    lv_meter_scale_t *Metronomehome_meter_1_scale_1 = lv_meter_add_scale(ui->Metronomehome_meter_1);
    lv_meter_set_scale_ticks(ui->Metronomehome_meter_1, Metronomehome_meter_1_scale_1, 54, 2, 10, lv_color_hex(0x00ff71));
    lv_meter_set_scale_major_ticks(ui->Metronomehome_meter_1, Metronomehome_meter_1_scale_1, 9, 5, 15, lv_color_hex(0x29ff00), 10);
    lv_meter_set_scale_range(ui->Metronomehome_meter_1, Metronomehome_meter_1_scale_1, 40, 120, 300, 120);

    // add needle line for Metronomehome_meter_1_scale_1.
    ui->Metronomehome_meter_1_scale_1_ndline_0 = lv_meter_add_needle_line(ui->Metronomehome_meter_1, Metronomehome_meter_1_scale_1, 5, lv_color_hex(0x000000), -10);
    lv_meter_set_indicator_value(ui->Metronomehome_meter_1, ui->Metronomehome_meter_1_scale_1_ndline_0, MetroPointerAngle); // Set the current value
    lv_obj_set_pos(ui->Metronomehome_meter_1, 126, 59);
    lv_obj_set_size(ui->Metronomehome_meter_1, 228, 228);
    lv_obj_set_scrollbar_mode(ui->Metronomehome_meter_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Metronomehome_meter_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Metronomehome_meter_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Metronomehome_meter_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Metronomehome_meter_1, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Metronomehome_meter_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Metronomehome_meter_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Metronomehome_meter_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Metronomehome_meter_1, lv_color_hex(0xff0000), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Metronomehome_meter_1, &lv_font_montserratMedium_12, LV_PART_TICKS | LV_STATE_DEFAULT);

    // Write codes Metronomehome_slider_1
    ui->Metronomehome_slider_1 = lv_slider_create(ui->Metronomehome);
    lv_slider_set_range(ui->Metronomehome_slider_1, 40, 120);
    lv_slider_set_value(ui->Metronomehome_slider_1, MetroPointerAngle, false);
    lv_obj_set_pos(ui->Metronomehome_slider_1, 138, 285);
    lv_obj_set_size(ui->Metronomehome_slider_1, 214, 9);
    lv_obj_set_scrollbar_mode(ui->Metronomehome_slider_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Metronomehome_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Metronomehome_slider_1, 74, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Metronomehome_slider_1, lv_color_hex(0x2FDAAE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Metronomehome_slider_1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Metronomehome_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Metronomehome_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Metronomehome_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Metronomehome_slider_1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Metronomehome_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Metronomehome_slider_1, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style for Metronomehome_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Metronomehome_slider_1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Metronomehome_slider_1, lv_color_hex(0x2195f6), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Metronomehome_slider_1, 50, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write codes Metronomehome_label_1
    ui->Metronomehome_label_1 = lv_label_create(ui->Metronomehome);
    lv_label_set_text(ui->Metronomehome_label_1, "Metronome");
    lv_label_set_long_mode(ui->Metronomehome_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Metronomehome_label_1, 175, 17);
    lv_obj_set_size(ui->Metronomehome_label_1, 130, 32);
    lv_obj_set_scrollbar_mode(ui->Metronomehome_label_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Metronomehome_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Metronomehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Metronomehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Metronomehome_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Metronomehome_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Metronomehome_label_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Metronomehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Metronomehome_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Metronomehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Metronomehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Metronomehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Metronomehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Metronomehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Metronomehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Metronomehome_btn_1
    ui->Metronomehome_btn_1 = lv_btn_create(ui->Metronomehome);
    ui->Metronomehome_btn_1_label = lv_label_create(ui->Metronomehome_btn_1);
    lv_label_set_text(ui->Metronomehome_btn_1_label, "-");
    lv_label_set_long_mode(ui->Metronomehome_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Metronomehome_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Metronomehome_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Metronomehome_btn_1, 26, 134);
    lv_obj_set_size(ui->Metronomehome_btn_1, 81, 75);
    lv_obj_set_scrollbar_mode(ui->Metronomehome_btn_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Metronomehome_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Metronomehome_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Metronomehome_btn_1, lv_color_hex(0x2FDAAE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Metronomehome_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Metronomehome_btn_1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Metronomehome_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Metronomehome_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Metronomehome_btn_1, &lv_font_montserratMedium_70, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Metronomehome_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Metronomehome_btn_2
    ui->Metronomehome_btn_2 = lv_btn_create(ui->Metronomehome);
    ui->Metronomehome_btn_2_label = lv_label_create(ui->Metronomehome_btn_2);
    lv_label_set_text(ui->Metronomehome_btn_2_label, "+");
    lv_label_set_long_mode(ui->Metronomehome_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Metronomehome_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Metronomehome_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Metronomehome_btn_2, 373, 135);
    lv_obj_set_size(ui->Metronomehome_btn_2, 86, 81);
    lv_obj_set_scrollbar_mode(ui->Metronomehome_btn_2, LV_SCROLLBAR_MODE_OFF);

    // Write style for Metronomehome_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Metronomehome_btn_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Metronomehome_btn_2, lv_color_hex(0x2FDAAE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Metronomehome_btn_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Metronomehome_btn_2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Metronomehome_btn_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Metronomehome_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Metronomehome_btn_2, &lv_font_montserratMedium_70, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Metronomehome_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Metronomehome_spangroup_1
    ui->Metronomehome_spangroup_1 = lv_spangroup_create(ui->Metronomehome);
    lv_spangroup_set_align(ui->Metronomehome_spangroup_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Metronomehome_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Metronomehome_spangroup_1, LV_SPAN_MODE_BREAK);
    // create spans
    lv_span_t *Metronomehome_spangroup_1_span;
    Metronomehome_spangroup_1_span = lv_spangroup_new_span(ui->Metronomehome_spangroup_1);

    char temp_char[10];
    itoa(MetroPointerAngle , temp_char, 10);
    lv_span_set_text(Metronomehome_spangroup_1_span, temp_char);
    lv_style_set_text_color(&Metronomehome_spangroup_1_span->style, lv_color_hex(0x2f3243));
    lv_style_set_text_decor(&Metronomehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&Metronomehome_spangroup_1_span->style, &lv_font_Alatsi_Regular_18);
    Metronomehome_spangroup_1_span = lv_spangroup_new_span(ui->Metronomehome_spangroup_1);
    lv_span_set_text(Metronomehome_spangroup_1_span, " bpm");
    lv_style_set_text_color(&Metronomehome_spangroup_1_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&Metronomehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&Metronomehome_spangroup_1_span->style, &lv_font_montserratMedium_17);
    lv_obj_set_pos(ui->Metronomehome_spangroup_1, 370, 234);
    lv_obj_set_size(ui->Metronomehome_spangroup_1, 89, 44);
    lv_obj_set_scrollbar_mode(ui->Metronomehome_spangroup_1, LV_SCROLLBAR_MODE_OFF);

    // Write style state: LV_STATE_DEFAULT for &style_Metronomehome_spangroup_1_main_main_default
    static lv_style_t style_Metronomehome_spangroup_1_main_main_default;
    ui_init_style(&style_Metronomehome_spangroup_1_main_main_default);

    lv_style_set_border_width(&style_Metronomehome_spangroup_1_main_main_default, 2);
    lv_style_set_border_opa(&style_Metronomehome_spangroup_1_main_main_default, 255);
    lv_style_set_border_color(&style_Metronomehome_spangroup_1_main_main_default, lv_color_hex(0x000000));
    lv_style_set_radius(&style_Metronomehome_spangroup_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_Metronomehome_spangroup_1_main_main_default, 247);
    lv_style_set_bg_color(&style_Metronomehome_spangroup_1_main_main_default, lv_color_hex(0x71d1f9));
    lv_style_set_pad_top(&style_Metronomehome_spangroup_1_main_main_default, 1);
    lv_style_set_pad_right(&style_Metronomehome_spangroup_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Metronomehome_spangroup_1_main_main_default, 5);
    lv_style_set_pad_left(&style_Metronomehome_spangroup_1_main_main_default, 10);
    lv_style_set_shadow_width(&style_Metronomehome_spangroup_1_main_main_default, 0);
    lv_obj_add_style(ui->Metronomehome_spangroup_1, &style_Metronomehome_spangroup_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Metronomehome_spangroup_1);
    // Update current screen layout.
    lv_obj_update_layout(ui->Metronomehome);
    

    //Write codes Metronomehome_btn_5
	ui->Metronomehome_btn_5 = lv_btn_create(ui->Metronomehome);
	ui->Metronomehome_btn_5_label = lv_label_create(ui->Metronomehome_btn_5);
	lv_label_set_text(ui->Metronomehome_btn_5_label, "OFF");
	lv_label_set_long_mode(ui->Metronomehome_btn_5_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Metronomehome_btn_5_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Metronomehome_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Metronomehome_btn_5, 389, 67);
	lv_obj_set_size(ui->Metronomehome_btn_5, 50, 50);
	lv_obj_set_scrollbar_mode(ui->Metronomehome_btn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style for Metronomehome_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Metronomehome_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Metronomehome_btn_5, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Metronomehome_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Metronomehome_btn_5, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Metronomehome_btn_5, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->Metronomehome_btn_5, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->Metronomehome_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->Metronomehome_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->Metronomehome_btn_5, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->Metronomehome_btn_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Metronomehome_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Metronomehome_btn_5, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Metronomehome_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    
    // Init events for screen.
    events_init_Metronomehome(ui);
}
