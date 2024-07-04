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

void setup_scr_TurnerAutoHome(lv_ui *ui)
{
	//Write codes TurnerAutoHome
	ui->TurnerAutoHome = lv_obj_create(NULL);
	lv_obj_set_size(ui->TurnerAutoHome, 480, 320);
    //lv_obj_clear_flag(guider_ui.TurnerAutoHome, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_scrollbar_mode(ui->TurnerAutoHome, LV_SCROLLBAR_MODE_OFF);

	//Write style for TurnerAutoHome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->TurnerAutoHome, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TurnerAutoHome_cont_1
	ui->TurnerAutoHome_cont_1 = lv_obj_create(ui->TurnerAutoHome);
	lv_obj_set_pos(ui->TurnerAutoHome_cont_1, 0, 0);
	lv_obj_set_size(ui->TurnerAutoHome_cont_1, 480, 60);
	lv_obj_set_scrollbar_mode(ui->TurnerAutoHome_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for TurnerAutoHome_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->TurnerAutoHome_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->TurnerAutoHome_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->TurnerAutoHome_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->TurnerAutoHome_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->TurnerAutoHome_cont_1, lv_color_hex(0x2F3243), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->TurnerAutoHome_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->TurnerAutoHome_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->TurnerAutoHome_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->TurnerAutoHome_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->TurnerAutoHome_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TurnerAutoHome_btn_2
	ui->TurnerAutoHome_btn_2 = lv_btn_create(ui->TurnerAutoHome_cont_1);
	ui->TurnerAutoHome_btn_2_label = lv_label_create(ui->TurnerAutoHome_btn_2);
	lv_label_set_text(ui->TurnerAutoHome_btn_2_label, "Return\n");
	lv_label_set_long_mode(ui->TurnerAutoHome_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->TurnerAutoHome_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->TurnerAutoHome_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->TurnerAutoHome_btn_2, 12, 7);
	lv_obj_set_size(ui->TurnerAutoHome_btn_2, 60, 35);
	lv_obj_set_scrollbar_mode(ui->TurnerAutoHome_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style for TurnerAutoHome_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->TurnerAutoHome_btn_2, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->TurnerAutoHome_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->TurnerAutoHome_btn_2, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->TurnerAutoHome_btn_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->TurnerAutoHome_btn_2, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->TurnerAutoHome_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->TurnerAutoHome_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->TurnerAutoHome_btn_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->TurnerAutoHome_btn_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->TurnerAutoHome_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->TurnerAutoHome_btn_2, &lv_font_simsun_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->TurnerAutoHome_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TurnerAutoHome_sw_1
	ui->TurnerAutoHome_sw_1 = lv_switch_create(ui->TurnerAutoHome_cont_1);
	lv_obj_set_pos(ui->TurnerAutoHome_sw_1, 419, 14);
	lv_obj_set_size(ui->TurnerAutoHome_sw_1, 40, 19);
	lv_obj_set_scrollbar_mode(ui->TurnerAutoHome_sw_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for TurnerAutoHome_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->TurnerAutoHome_sw_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->TurnerAutoHome_sw_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->TurnerAutoHome_sw_1, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->TurnerAutoHome_sw_1, lv_color_hex(0x00bdff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->TurnerAutoHome_sw_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->TurnerAutoHome_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for TurnerAutoHome_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_sw_1, 223, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->TurnerAutoHome_sw_1, lv_color_hex(0x878787), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->TurnerAutoHome_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for TurnerAutoHome_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->TurnerAutoHome_sw_1, lv_color_hex(0xf78585), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->TurnerAutoHome_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->TurnerAutoHome_sw_1, 100, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write style for TurnerAutoHome_sw_1, Part: LV_PART_KNOB, State: LV_STATE_FOCUSED.
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_sw_1, 255, LV_PART_KNOB|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->TurnerAutoHome_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->TurnerAutoHome_sw_1, 0, LV_PART_KNOB|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->TurnerAutoHome_sw_1, 100, LV_PART_KNOB|LV_STATE_FOCUSED);

	//Write codes TurnerAutoHome_label_4
	ui->TurnerAutoHome_label_4 = lv_label_create(ui->TurnerAutoHome_cont_1);
	lv_label_set_text(ui->TurnerAutoHome_label_4, "Manual");
	lv_label_set_long_mode(ui->TurnerAutoHome_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->TurnerAutoHome_label_4, 320, 16);
	lv_obj_set_size(ui->TurnerAutoHome_label_4, 130, 32);
	lv_obj_set_scrollbar_mode(ui->TurnerAutoHome_label_4, LV_SCROLLBAR_MODE_OFF);

	//Write style for TurnerAutoHome_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->TurnerAutoHome_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->TurnerAutoHome_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->TurnerAutoHome_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->TurnerAutoHome_label_4, &lv_font_arial_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->TurnerAutoHome_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->TurnerAutoHome_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->TurnerAutoHome_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->TurnerAutoHome_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->TurnerAutoHome_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->TurnerAutoHome_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->TurnerAutoHome_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->TurnerAutoHome_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TurnerAutoHome_label_1
	ui->TurnerAutoHome_label_1 = lv_label_create(ui->TurnerAutoHome);
	lv_label_set_text(ui->TurnerAutoHome_label_1, "Auto Tuner\n");
	lv_label_set_long_mode(ui->TurnerAutoHome_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->TurnerAutoHome_label_1, 175, 17);
	lv_obj_set_size(ui->TurnerAutoHome_label_1, 130, 32);
	lv_obj_set_scrollbar_mode(ui->TurnerAutoHome_label_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for TurnerAutoHome_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->TurnerAutoHome_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->TurnerAutoHome_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->TurnerAutoHome_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->TurnerAutoHome_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->TurnerAutoHome_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->TurnerAutoHome_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->TurnerAutoHome_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->TurnerAutoHome_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->TurnerAutoHome_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->TurnerAutoHome_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->TurnerAutoHome_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->TurnerAutoHome_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes TurnerAutoHome_meter_1
	ui->TurnerAutoHome_meter_1 = lv_meter_create(ui->TurnerAutoHome);
	// add scale TurnerAutoHome_meter_1
	lv_meter_scale_t *Tunerhome_meter_1_scale_1 = lv_meter_add_scale(ui->TurnerAutoHome_meter_1);
	lv_meter_set_scale_ticks(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, 60, 2, 10, lv_color_hex(0x00ff71));
	lv_meter_set_scale_major_ticks(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, 6, 5, 16, lv_color_hex(0x29ff00), 10);
	lv_meter_set_scale_range(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, -50, 49, 180, 180);
    // add arc for TurnerAutoHome_meter_1
	lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_0;
	Tunerhome_meter_1_scale_1_arc_0 = lv_meter_add_arc(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0xff0000), 0);
	lv_meter_set_indicator_start_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_0, -50);
	lv_meter_set_indicator_end_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_0, -30);

	// add arc for TurnerAutoHome_meter_1
	lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_1;
	Tunerhome_meter_1_scale_1_arc_1 = lv_meter_add_arc(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0xff8b3f), 0);
	lv_meter_set_indicator_start_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_1, -30);
	lv_meter_set_indicator_end_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_1, -10);

	// add arc for TurnerAutoHome_meter_1
	lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_2;
	Tunerhome_meter_1_scale_1_arc_2 = lv_meter_add_arc(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0x00ff00), 0);
	lv_meter_set_indicator_start_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_2, -10);
	lv_meter_set_indicator_end_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_2, 0);

	// add arc for TurnerAutoHome_meter_1
	lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_3;
	Tunerhome_meter_1_scale_1_arc_3 = lv_meter_add_arc(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0x00ff00), 0);
	lv_meter_set_indicator_start_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_3, 0);
	lv_meter_set_indicator_end_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_3, 10);

	// add arc for TurnerAutoHome_meter_1
	lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_4;
	Tunerhome_meter_1_scale_1_arc_4 = lv_meter_add_arc(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0xff8b3f), 0);
	lv_meter_set_indicator_start_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_4, 10);
	lv_meter_set_indicator_end_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_4, 30);

	// add arc for TurnerAutoHome_meter_1
	lv_meter_indicator_t *Tunerhome_meter_1_scale_1_arc_5;
	Tunerhome_meter_1_scale_1_arc_5 = lv_meter_add_arc(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, 10, lv_color_hex(0xff0000), 0);
	lv_meter_set_indicator_start_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_5, 30);
	lv_meter_set_indicator_end_value(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1_arc_5, 50);

	// add needle line for TurnerAutoHome_meter_1.
	ui->TurnerAutoHome_meter_1_scale_1_ndline_0 = lv_meter_add_needle_line(ui->TurnerAutoHome_meter_1, Tunerhome_meter_1_scale_1, 5, lv_color_hex(0x000000), -10);
	lv_meter_set_indicator_value(ui->TurnerAutoHome_meter_1, ui->TurnerAutoHome_meter_1_scale_1_ndline_0, currentFrequency-targetFrequency);
	lv_obj_set_pos(ui->TurnerAutoHome_meter_1, 5, 58);
	lv_obj_set_size(ui->TurnerAutoHome_meter_1, 294, 295);
	lv_obj_set_scrollbar_mode(ui->TurnerAutoHome_meter_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for TurnerAutoHome_meter_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_meter_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->TurnerAutoHome_meter_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->TurnerAutoHome_meter_1, 200, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->TurnerAutoHome_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->TurnerAutoHome_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for TurnerAutoHome_meter_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->TurnerAutoHome_meter_1, lv_color_hex(0xff0000), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->TurnerAutoHome_meter_1, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);




	//Write codes TurnerAutoHome_label_3
	ui->TurnerAutoHome_label_3 = lv_label_create(ui->TurnerAutoHome);
	lv_label_set_text(ui->TurnerAutoHome_label_3, "Now:\nC\n");
	lv_label_set_long_mode(ui->TurnerAutoHome_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->TurnerAutoHome_label_3, 307, 129);
	lv_obj_set_size(ui->TurnerAutoHome_label_3, 106, 48);
	lv_obj_set_scrollbar_mode(ui->TurnerAutoHome_label_3, LV_SCROLLBAR_MODE_OFF);

	//Write style for TurnerAutoHome_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->TurnerAutoHome_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->TurnerAutoHome_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->TurnerAutoHome_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->TurnerAutoHome_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->TurnerAutoHome_label_3, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->TurnerAutoHome_label_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->TurnerAutoHome_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->TurnerAutoHome_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->TurnerAutoHome_label_3, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->TurnerAutoHome_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->TurnerAutoHome_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->TurnerAutoHome_label_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->TurnerAutoHome_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->TurnerAutoHome_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->TurnerAutoHome);

	
	//Init events for screen.
	events_init_TurnerAutoHome(ui);
}
