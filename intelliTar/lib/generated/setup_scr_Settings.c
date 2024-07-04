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

void setup_scr_Settings(lv_ui *ui)
{
    // Write codes Settings
    ui->Settings = lv_obj_create(NULL);
    lv_obj_set_size(ui->Settings, 480, 320);
    lv_obj_clear_flag(guider_ui.Settings, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_scrollbar_mode(ui->Settings, LV_SCROLLBAR_MODE_OFF);

    // Write style for Settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Settings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Settings, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Settings_label_3
    ui->Settings_label_3 = lv_label_create(ui->Settings);
    lv_label_set_text(ui->Settings_label_3, "Auto");
    lv_label_set_long_mode(ui->Settings_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Settings_label_3, 322, 16);
    lv_obj_set_size(ui->Settings_label_3, 130, 32);
    lv_obj_set_scrollbar_mode(ui->Settings_label_3, LV_SCROLLBAR_MODE_OFF);

    // Write style for Settings_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Settings_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Settings_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Settings_label_3, &lv_font_arial_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Settings_label_3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Settings_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Settings_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Settings_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Settings_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Settings_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Settings_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Settings_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Settings_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Settings_cont_1
    ui->Settings_cont_1 = lv_obj_create(ui->Settings);
    lv_obj_set_pos(ui->Settings_cont_1, -2, -1);
    lv_obj_set_size(ui->Settings_cont_1, 483, 63);
    lv_obj_set_scrollbar_mode(ui->Settings_cont_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Settings_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Settings_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Settings_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Settings_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Settings_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Settings_cont_1, lv_color_hex(0x2F3243), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Settings_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Settings_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Settings_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Settings_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Settings_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Settings_btn_1
    ui->Settings_btn_1 = lv_btn_create(ui->Settings_cont_1);
    ui->Settings_btn_1_label = lv_label_create(ui->Settings_btn_1);
    lv_label_set_text(ui->Settings_btn_1_label, "Return\n");
    lv_label_set_long_mode(ui->Settings_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Settings_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Settings_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Settings_btn_1, 11, 10);
    lv_obj_set_size(ui->Settings_btn_1, 60, 35);
    lv_obj_set_scrollbar_mode(ui->Settings_btn_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Settings_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Settings_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Settings_btn_1, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Settings_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_btn_1, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Settings_btn_1, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Settings_btn_1, lv_color_hex(0x0d4b3b), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Settings_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Settings_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Settings_btn_1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Settings_btn_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Settings_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Settings_btn_1, &lv_font_simsun_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Settings_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Settings_label_1
    ui->Settings_label_1 = lv_label_create(ui->Settings_cont_1);
    lv_label_set_text(ui->Settings_label_1, "Settings");
    lv_label_set_long_mode(ui->Settings_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Settings_label_1, 175, 15);
    lv_obj_set_size(ui->Settings_label_1, 130, 32);
    lv_obj_set_scrollbar_mode(ui->Settings_label_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Settings_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Settings_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Settings_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Settings_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Settings_label_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Settings_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Settings_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Settings_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Settings_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Settings_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Settings_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Settings_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Settings_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Settings_ta_1
    ui->Settings_ta_1 = lv_textarea_create(ui->Settings);
    lv_textarea_set_text(ui->Settings_ta_1, "");
    lv_obj_set_pos(ui->Settings_ta_1, 167, 101);
    lv_obj_set_size(ui->Settings_ta_1, 230, 28);
    lv_obj_set_scrollbar_mode(ui->Settings_ta_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Settings_ta_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Settings_ta_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Settings_ta_1, &lv_font_montserratMedium_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Settings_ta_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Settings_ta_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Settings_ta_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Settings_ta_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Settings_ta_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Settings_ta_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Settings_ta_1, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Settings_ta_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Settings_ta_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Settings_ta_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Settings_ta_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Settings_ta_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_ta_1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Settings_ta_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Settings_ta_1, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Settings_ta_1, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_ta_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Write codes Settings_label_name
    ui->Settings_label_name = lv_label_create(ui->Settings);
    lv_label_set_text(ui->Settings_label_name, "WIFI Name:");
    lv_label_set_long_mode(ui->Settings_label_name, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Settings_label_name, 44, 97);
    lv_obj_set_size(ui->Settings_label_name, 128, 47);
    lv_obj_set_scrollbar_mode(ui->Settings_label_name, LV_SCROLLBAR_MODE_OFF);

    // Write style for Settings_label_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Settings_label_name, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_label_name, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Settings_label_name, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Settings_label_name, &lv_font_arial_17, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Settings_label_name, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Settings_label_name, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Settings_label_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Settings_label_name, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Settings_label_name, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Settings_label_name, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Settings_label_name, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Settings_label_name, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Settings_label_name, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Settings_ta_2
    ui->Settings_ta_2 = lv_textarea_create(ui->Settings);
    lv_textarea_set_text(ui->Settings_ta_2, "");
    lv_obj_set_pos(ui->Settings_ta_2, 166, 163);
    lv_obj_set_size(ui->Settings_ta_2, 230, 28);
    lv_obj_set_scrollbar_mode(ui->Settings_ta_2, LV_SCROLLBAR_MODE_OFF);

    // Write style for Settings_ta_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Settings_ta_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Settings_ta_2, &lv_font_montserratMedium_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Settings_ta_2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Settings_ta_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Settings_ta_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Settings_ta_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Settings_ta_2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Settings_ta_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Settings_ta_2, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Settings_ta_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Settings_ta_2, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Settings_ta_2, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Settings_ta_2, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Settings_ta_2, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_ta_2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Settings_ta_2, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Settings_ta_2, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Settings_ta_2, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_ta_2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Write codes Settings_label_pwd
    ui->Settings_label_pwd = lv_label_create(ui->Settings);
    lv_label_set_text(ui->Settings_label_pwd, "Password:");
    lv_label_set_long_mode(ui->Settings_label_pwd, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Settings_label_pwd, 51, 161);
    lv_obj_set_size(ui->Settings_label_pwd, 128, 47);
    lv_obj_set_scrollbar_mode(ui->Settings_label_pwd, LV_SCROLLBAR_MODE_OFF);

    // Write style for Settings_label_pwd, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Settings_label_pwd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Settings_label_pwd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Settings_label_pwd, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Settings_label_pwd, &lv_font_arial_17, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Settings_label_pwd, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Settings_label_pwd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Settings_label_pwd, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Settings_label_pwd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Settings_label_pwd, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Settings_label_pwd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Settings_label_pwd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Settings_label_pwd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Settings_label_pwd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // Update current screen layout.
    lv_obj_update_layout(ui->Settings);

    // Init events for screen.
    events_init_Settings(ui);
}
