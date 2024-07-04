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

void setup_scr_Pagehome(lv_ui *ui)
{
    // Write codes Pagehome
    ui->Pagehome = lv_obj_create(NULL);
    lv_obj_set_size(ui->Pagehome, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Pagehome, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Pagehome, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Pagehome_cont_1
    ui->Pagehome_cont_1 = lv_obj_create(ui->Pagehome);
    lv_obj_set_pos(ui->Pagehome_cont_1, -1, -2);
    lv_obj_set_size(ui->Pagehome_cont_1, 482, 62);
    lv_obj_set_scrollbar_mode(ui->Pagehome_cont_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Pagehome_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Pagehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Pagehome_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Pagehome_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome_cont_1, lv_color_hex(0x2F3243), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Pagehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Pagehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Pagehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Pagehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Pagehome_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Pagehome_btn_4
    ui->Pagehome_btn_4 = lv_btn_create(ui->Pagehome_cont_1);
    ui->Pagehome_btn_4_label = lv_label_create(ui->Pagehome_btn_4);
    lv_label_set_text(ui->Pagehome_btn_4_label, "Return\n");
    lv_label_set_long_mode(ui->Pagehome_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Pagehome_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Pagehome_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Pagehome_btn_4, 13, 9);
    lv_obj_set_size(ui->Pagehome_btn_4, 57, 38);
    lv_obj_set_scrollbar_mode(ui->Pagehome_btn_4, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Pagehome_btn_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome_btn_4, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Pagehome_btn_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_btn_4, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Pagehome_btn_4, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Pagehome_btn_4, lv_color_hex(0x0d4b3b), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Pagehome_btn_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Pagehome_btn_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Pagehome_btn_4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Pagehome_btn_4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Pagehome_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Pagehome_btn_4, &lv_font_simsun_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Pagehome_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Pagehome_ddlist_1
    ui->Pagehome_ddlist_1 = lv_dropdown_create(ui->Pagehome);
    lv_dropdown_set_options(ui->Pagehome_ddlist_1, "list1\nlist2\nlist3");
    lv_obj_set_pos(ui->Pagehome_ddlist_1, 258, 68);
    lv_obj_set_size(ui->Pagehome_ddlist_1, 153, 35);
    lv_obj_set_scrollbar_mode(ui->Pagehome_ddlist_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Pagehome_ddlist_1, lv_color_hex(0x0D3055), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Pagehome_ddlist_1, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Pagehome_ddlist_1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Pagehome_ddlist_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Pagehome_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Pagehome_ddlist_1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Pagehome_ddlist_1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Pagehome_ddlist_1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_ddlist_1, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Pagehome_ddlist_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Pagehome_ddlist_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_CHECKED for &style_Pagehome_ddlist_1_extra_list_selected_checked
    static lv_style_t style_Pagehome_ddlist_1_extra_list_selected_checked;
    ui_init_style(&style_Pagehome_ddlist_1_extra_list_selected_checked);

    lv_style_set_text_color(&style_Pagehome_ddlist_1_extra_list_selected_checked, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_Pagehome_ddlist_1_extra_list_selected_checked, &lv_font_montserratMedium_12);
    lv_style_set_border_width(&style_Pagehome_ddlist_1_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_Pagehome_ddlist_1_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_Pagehome_ddlist_1_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_radius(&style_Pagehome_ddlist_1_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_Pagehome_ddlist_1_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_Pagehome_ddlist_1_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_obj_add_style(lv_dropdown_get_list(ui->Pagehome_ddlist_1), &style_Pagehome_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED | LV_STATE_CHECKED);

    // Write style state: LV_STATE_DEFAULT for &style_Pagehome_ddlist_1_extra_list_main_default
    static lv_style_t style_Pagehome_ddlist_1_extra_list_main_default;
    ui_init_style(&style_Pagehome_ddlist_1_extra_list_main_default);

    lv_style_set_max_height(&style_Pagehome_ddlist_1_extra_list_main_default, 90);
    lv_style_set_text_color(&style_Pagehome_ddlist_1_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_Pagehome_ddlist_1_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_border_width(&style_Pagehome_ddlist_1_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_Pagehome_ddlist_1_extra_list_main_default, 255);
    lv_style_set_border_color(&style_Pagehome_ddlist_1_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_radius(&style_Pagehome_ddlist_1_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_Pagehome_ddlist_1_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_Pagehome_ddlist_1_extra_list_main_default, lv_color_hex(0xffffff));
    lv_obj_add_style(lv_dropdown_get_list(ui->Pagehome_ddlist_1), &style_Pagehome_ddlist_1_extra_list_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for &style_Pagehome_ddlist_1_extra_list_scrollbar_default
    static lv_style_t style_Pagehome_ddlist_1_extra_list_scrollbar_default;
    ui_init_style(&style_Pagehome_ddlist_1_extra_list_scrollbar_default);

    lv_style_set_radius(&style_Pagehome_ddlist_1_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_Pagehome_ddlist_1_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_Pagehome_ddlist_1_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_obj_add_style(lv_dropdown_get_list(ui->Pagehome_ddlist_1), &style_Pagehome_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Write codes Pagehome_btn_2
    ui->Pagehome_btn_2 = lv_btn_create(ui->Pagehome);
    ui->Pagehome_btn_2_label = lv_label_create(ui->Pagehome_btn_2);
    lv_label_set_text(ui->Pagehome_btn_2_label, "Start！");
    lv_label_set_long_mode(ui->Pagehome_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Pagehome_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Pagehome_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Pagehome_btn_2, 168, 147);
    lv_obj_set_size(ui->Pagehome_btn_2, 145, 40);
    lv_obj_set_scrollbar_mode(ui->Pagehome_btn_2, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Pagehome_btn_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome_btn_2, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Pagehome_btn_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_btn_2, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Pagehome_btn_2, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Pagehome_btn_2, lv_color_hex(0x0d4b3b), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Pagehome_btn_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Pagehome_btn_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Pagehome_btn_2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Pagehome_btn_2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Pagehome_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Pagehome_btn_2, &lv_font_simsun_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Pagehome_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Pagehome_label_2
    ui->Pagehome_label_2 = lv_label_create(ui->Pagehome);
    lv_label_set_text(ui->Pagehome_label_2, "Choose your songs!");
    lv_label_set_long_mode(ui->Pagehome_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Pagehome_label_2, 9, 77);
    lv_obj_set_size(ui->Pagehome_label_2, 280, 32);
    lv_obj_set_scrollbar_mode(ui->Pagehome_label_2, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Pagehome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Pagehome_label_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Pagehome_label_2, &lv_font_montserratMedium_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Pagehome_label_2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Pagehome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Pagehome_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Pagehome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Pagehome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Pagehome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Pagehome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Pagehome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Pagehome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Pagehome_label_1
    ui->Pagehome_label_1 = lv_label_create(ui->Pagehome);
    lv_label_set_text(ui->Pagehome_label_1, "Sheet music presenter");
    lv_label_set_long_mode(ui->Pagehome_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Pagehome_label_1, 84, 19);
    lv_obj_set_size(ui->Pagehome_label_1, 280, 32);
    lv_obj_set_scrollbar_mode(ui->Pagehome_label_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Pagehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Pagehome_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Pagehome_label_1, &lv_font_montserratMedium_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Pagehome_label_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Pagehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Pagehome_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Pagehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Pagehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Pagehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Pagehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Pagehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Pagehome_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Pagehome_btn_5
    ui->Pagehome_btn_5 = lv_btn_create(ui->Pagehome);
    ui->Pagehome_btn_5_label = lv_label_create(ui->Pagehome_btn_5);
    lv_label_set_text(ui->Pagehome_btn_5_label, "AUTO");
    lv_label_set_long_mode(ui->Pagehome_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Pagehome_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Pagehome_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Pagehome_btn_5, 17, 255);
    lv_obj_set_size(ui->Pagehome_btn_5, 88, 48);
    lv_obj_set_scrollbar_mode(ui->Pagehome_btn_5, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Pagehome_btn_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome_btn_5, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Pagehome_btn_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_btn_5, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Pagehome_btn_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Pagehome_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Pagehome_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Pagehome_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);


    // Write codes Pagehome_btn_6
    ui->Pagehome_btn_6 = lv_btn_create(ui->Pagehome);
    ui->Pagehome_btn_6_label = lv_label_create(ui->Pagehome_btn_6);
    lv_label_set_text(ui->Pagehome_btn_6_label, "NONE");
    lv_label_set_long_mode(ui->Pagehome_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Pagehome_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Pagehome_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Pagehome_btn_6, 362, 180);
    lv_obj_set_size(ui->Pagehome_btn_6, 88, 48);
    lv_obj_set_scrollbar_mode(ui->Pagehome_btn_6, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Pagehome_btn_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome_btn_6, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Pagehome_btn_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_btn_6, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Pagehome_btn_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Pagehome_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Pagehome_btn_6, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Pagehome_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Pagehome_slider_1
    ui->Pagehome_slider_1 = lv_slider_create(ui->Pagehome);
    lv_slider_set_range(ui->Pagehome_slider_1, 0, 120);
    lv_slider_set_value(ui->Pagehome_slider_1, 40, false);
    lv_obj_set_pos(ui->Pagehome_slider_1, 280, 274);
    lv_obj_set_size(ui->Pagehome_slider_1, 160, 11);
    lv_obj_set_scrollbar_mode(ui->Pagehome_slider_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Pagehome_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Pagehome_slider_1, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome_slider_1, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_slider_1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Pagehome_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Pagehome_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Pagehome_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Pagehome_slider_1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_slider_1, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style for Pagehome_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Pagehome_slider_1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Pagehome_slider_1, lv_color_hex(0x2195f6), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Pagehome_slider_1, 50, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write codes Pagehome_spangroup_1
    ui->Pagehome_spangroup_1 = lv_spangroup_create(ui->Pagehome);
    lv_spangroup_set_align(ui->Pagehome_spangroup_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Pagehome_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Pagehome_spangroup_1, LV_SPAN_MODE_BREAK);
    // create spans
    lv_span_t *Pagehome_spangroup_1_span;
    Pagehome_spangroup_1_span = lv_spangroup_new_span(ui->Pagehome_spangroup_1);
    lv_span_set_text(Pagehome_spangroup_1_span, "80");
    lv_style_set_text_color(&Pagehome_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&Pagehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&Pagehome_spangroup_1_span->style, &lv_font_Alatsi_Regular_19);
    Pagehome_spangroup_1_span = lv_spangroup_new_span(ui->Pagehome_spangroup_1);
    lv_span_set_text(Pagehome_spangroup_1_span, " bpm");
    lv_style_set_text_color(&Pagehome_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&Pagehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&Pagehome_spangroup_1_span->style, &lv_font_montserratMedium_17);
    lv_obj_set_pos(ui->Pagehome_spangroup_1, 149, 261);
    lv_obj_set_size(ui->Pagehome_spangroup_1, 96, 36);
    lv_obj_set_scrollbar_mode(ui->Pagehome_spangroup_1, LV_SCROLLBAR_MODE_OFF);

    // Write style state: LV_STATE_DEFAULT for &style_Pagehome_spangroup_1_main_main_default
    static lv_style_t style_Pagehome_spangroup_1_main_main_default;
    ui_init_style(&style_Pagehome_spangroup_1_main_main_default);

    lv_style_set_border_width(&style_Pagehome_spangroup_1_main_main_default, 2);
    lv_style_set_border_opa(&style_Pagehome_spangroup_1_main_main_default, 255);
    lv_style_set_border_color(&style_Pagehome_spangroup_1_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_radius(&style_Pagehome_spangroup_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_Pagehome_spangroup_1_main_main_default, 247);
    lv_style_set_bg_color(&style_Pagehome_spangroup_1_main_main_default, lv_color_hex(0x2F92DA));
    lv_style_set_pad_top(&style_Pagehome_spangroup_1_main_main_default, 8);
    lv_style_set_pad_right(&style_Pagehome_spangroup_1_main_main_default, 6);
    lv_style_set_pad_bottom(&style_Pagehome_spangroup_1_main_main_default, 8);
    lv_style_set_pad_left(&style_Pagehome_spangroup_1_main_main_default, 10);
    lv_style_set_shadow_width(&style_Pagehome_spangroup_1_main_main_default, 0);
    lv_obj_add_style(ui->Pagehome_spangroup_1, &style_Pagehome_spangroup_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Pagehome_spangroup_1);
    // Update current screen layout.
    lv_obj_update_layout(ui->Pagehome);

    // Init events for screen.
    events_init_Pagehome(ui);
}
