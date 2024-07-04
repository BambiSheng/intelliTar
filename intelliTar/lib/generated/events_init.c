/*
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

extern int MetroPointerAngle;
extern int bpm;
extern int targetFrequency;
extern int currentFrequency;
extern int switchState;
extern int continueState;
extern int pauseState;
extern int displayerMode;
extern int displayerState;
extern int displayerbpm;
extern int LEDState;

extern int isddlistRefreshed;
extern int isddlistClicked;

int kbDisplay = 0;
int kb1Display = 0;
int kbState = 0;
int kb1State = 0;
static void screen_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Tunerhome_del == true)
            {
                setup_scr_Tunerhome(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Tunerhome, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.Tunerhome_del = true;
        }
        break;
    }
    default:
        break;
    }
}
static void screen_btn_2_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Metronomehome_del == true)
            {
                setup_scr_Metronomehome(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Metronomehome, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.Metronomehome_del = true;
        }
        break;
    }
    default:
        break;
    }
}
static void screen_btn_3_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Pagehome_del == true)
            {
                setup_scr_Pagehome(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Pagehome, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.Pagehome_del = true;
        }
        break;
    }
    default:
        break;
    }
}
static void screen_btn_4_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Settings_del == true)
            {
                setup_scr_Settings(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Settings, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.Settings_del = true;
        }
        break;
    }
    default:
        break;
    }
}
void events_init_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_btn_1, screen_btn_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->screen_btn_2, screen_btn_2_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->screen_btn_3, screen_btn_3_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->screen_btn_4, screen_btn_4_event_handler, LV_EVENT_ALL, NULL);
}
static void Tunerhome_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.screen_del == true)
            {
                setup_scr_screen(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.screen_del = true;
        }
        break;
    }
    default:
        break;
    }
}
static void Tunerhome_btnm_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t *obj = lv_event_get_target(e);
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        switch (id)
        {
        case 0:
        {
            targetFrequency = 255;
            lv_meter_set_indicator_value(guider_ui.Tunerhome_meter_1, guider_ui.Tunerhome_meter_1_scale_1_ndline_0, (currentFrequency - targetFrequency));
            lv_label_set_text(guider_ui.Tunerhome_label_2, "C");
            break;
        }
        case 1:
        {
            targetFrequency = 322;
            lv_meter_set_indicator_value(guider_ui.Tunerhome_meter_1, guider_ui.Tunerhome_meter_1_scale_1_ndline_0, (currentFrequency - targetFrequency));
            lv_obj_set_style_pad_bottom(guider_ui.Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(guider_ui.Tunerhome_label_2, "E");
            break;
        }
        case 2:
        {
            targetFrequency = 392;
            lv_meter_set_indicator_value(guider_ui.Tunerhome_meter_1, guider_ui.Tunerhome_meter_1_scale_1_ndline_0, (currentFrequency - targetFrequency));
            lv_obj_set_style_pad_bottom(guider_ui.Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(guider_ui.Tunerhome_label_2, "G");
            break;
        }
        case 3:
        {
            targetFrequency = 440;
            lv_meter_set_indicator_value(guider_ui.Tunerhome_meter_1, guider_ui.Tunerhome_meter_1_scale_1_ndline_0, (currentFrequency - targetFrequency));
            lv_obj_set_style_pad_bottom(guider_ui.Tunerhome_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(guider_ui.Tunerhome_label_2, "A");
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}
static void Tunerhome_sw_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.TurnerAutoHome_del == true)
            {
                setup_scr_TurnerAutoHome(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.TurnerAutoHome, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.TurnerAutoHome_del = true;
        }
        break;
    }
    default:
        break;
    }
}
void events_init_Tunerhome(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Tunerhome_btn_1, Tunerhome_btn_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Tunerhome_btnm_1, Tunerhome_btnm_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Tunerhome_sw_1, Tunerhome_sw_1_event_handler, LV_EVENT_ALL, NULL);
}
static void Metronomehome_btn_4_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.screen_del == true)
            {
                setup_scr_screen(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.screen_del = true;
        }
        break;
    }
    default:
        break;
    }
}
static void Metronomehome_slider_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
    {
        MetroPointerAngle = lv_slider_get_value(guider_ui.Metronomehome_slider_1);
        lv_meter_set_indicator_value(guider_ui.Metronomehome_meter_1, guider_ui.Metronomehome_meter_1_scale_1_ndline_0, MetroPointerAngle); // Set the current value
        // lv_obj_remove_style_all(guider_ui.Metronomehome_spangroup_1);
        lv_spangroup_del_span(guider_ui.Metronomehome_spangroup_1, lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1));
        lv_spangroup_del_span(guider_ui.Metronomehome_spangroup_1, lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1));
        char temp_char[10];
        itoa(MetroPointerAngle, temp_char, 10);

        lv_span_t *Metronomehome_spangroup_1_span;
        Metronomehome_spangroup_1_span = lv_spangroup_new_span(guider_ui.Metronomehome_spangroup_1);
        lv_span_set_text(Metronomehome_spangroup_1_span, temp_char);
        lv_style_set_text_color(&Metronomehome_spangroup_1_span->style, lv_color_hex(0x2f3243));
        lv_style_set_text_decor(&Metronomehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
        lv_style_set_text_font(&Metronomehome_spangroup_1_span->style, &lv_font_Alatsi_Regular_18);
        Metronomehome_spangroup_1_span = lv_spangroup_new_span(guider_ui.Metronomehome_spangroup_1);
        lv_span_set_text(Metronomehome_spangroup_1_span, " bpm");
        lv_style_set_text_color(&Metronomehome_spangroup_1_span->style, lv_color_hex(0x000000));
        lv_style_set_text_decor(&Metronomehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
        lv_style_set_text_font(&Metronomehome_spangroup_1_span->style, &lv_font_montserratMedium_17);
        lv_obj_set_pos(guider_ui.Metronomehome_spangroup_1, 370, 234);
        lv_obj_set_size(guider_ui.Metronomehome_spangroup_1, 89, 44);
        lv_obj_set_scrollbar_mode(guider_ui.Metronomehome_spangroup_1, LV_SCROLLBAR_MODE_OFF);

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
        lv_obj_add_style(guider_ui.Metronomehome_spangroup_1, &style_Metronomehome_spangroup_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_spangroup_refr_mode(guider_ui.Metronomehome_spangroup_1);
        break;
    }
    default:
        break;
    }
}
static void Metronomehome_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        MetroPointerAngle--;
        lv_meter_set_indicator_value(guider_ui.Metronomehome_meter_1, guider_ui.Metronomehome_meter_1_scale_1_ndline_0, MetroPointerAngle); // Set the current value
        // Write the load screen code.
        if (lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1) != NULL)
            lv_spangroup_del_span(guider_ui.Metronomehome_spangroup_1, lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1));
        if (lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1) != NULL)
            lv_spangroup_del_span(guider_ui.Metronomehome_spangroup_1, lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1));
        char temp_char[10];
        itoa(MetroPointerAngle, temp_char, 10);

        lv_span_t *Metronomehome_spangroup_1_span;
        Metronomehome_spangroup_1_span = lv_spangroup_new_span(guider_ui.Metronomehome_spangroup_1);
        lv_span_set_text(Metronomehome_spangroup_1_span, temp_char);
        lv_style_set_text_color(&Metronomehome_spangroup_1_span->style, lv_color_hex(0x2f3243));
        lv_style_set_text_decor(&Metronomehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
        lv_style_set_text_font(&Metronomehome_spangroup_1_span->style, &lv_font_Alatsi_Regular_18);
        Metronomehome_spangroup_1_span = lv_spangroup_new_span(guider_ui.Metronomehome_spangroup_1);
        lv_span_set_text(Metronomehome_spangroup_1_span, " bpm");
        lv_style_set_text_color(&Metronomehome_spangroup_1_span->style, lv_color_hex(0x000000));
        lv_style_set_text_decor(&Metronomehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
        lv_style_set_text_font(&Metronomehome_spangroup_1_span->style, &lv_font_montserratMedium_17);
        lv_obj_set_pos(guider_ui.Metronomehome_spangroup_1, 370, 234);
        lv_obj_set_size(guider_ui.Metronomehome_spangroup_1, 89, 44);
        lv_obj_set_scrollbar_mode(guider_ui.Metronomehome_spangroup_1, LV_SCROLLBAR_MODE_OFF);
        break;
    }
    default:
        break;
    }
}
static void Metronomehome_btn_2_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        MetroPointerAngle++;
        lv_meter_set_indicator_value(guider_ui.Metronomehome_meter_1, guider_ui.Metronomehome_meter_1_scale_1_ndline_0, MetroPointerAngle); // Set the current value
                                                                                                                                            // Write the load screen code.
        if (lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1) != NULL)
            lv_spangroup_del_span(guider_ui.Metronomehome_spangroup_1, lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1));
        if (lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1) != NULL)
            lv_spangroup_del_span(guider_ui.Metronomehome_spangroup_1, lv_spangroup_get_child(guider_ui.Metronomehome_spangroup_1, -1));
        char temp_char[10];
        itoa(MetroPointerAngle, temp_char, 10);

        lv_span_t *Metronomehome_spangroup_1_span;
        Metronomehome_spangroup_1_span = lv_spangroup_new_span(guider_ui.Metronomehome_spangroup_1);
        lv_span_set_text(Metronomehome_spangroup_1_span, temp_char);
        lv_style_set_text_color(&Metronomehome_spangroup_1_span->style, lv_color_hex(0x2f3243));
        lv_style_set_text_decor(&Metronomehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
        lv_style_set_text_font(&Metronomehome_spangroup_1_span->style, &lv_font_Alatsi_Regular_18);
        Metronomehome_spangroup_1_span = lv_spangroup_new_span(guider_ui.Metronomehome_spangroup_1);
        lv_span_set_text(Metronomehome_spangroup_1_span, " bpm");
        lv_style_set_text_color(&Metronomehome_spangroup_1_span->style, lv_color_hex(0x000000));
        lv_style_set_text_decor(&Metronomehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
        lv_style_set_text_font(&Metronomehome_spangroup_1_span->style, &lv_font_montserratMedium_17);
        lv_obj_set_pos(guider_ui.Metronomehome_spangroup_1, 370, 234);
        lv_obj_set_size(guider_ui.Metronomehome_spangroup_1, 89, 44);
        lv_obj_set_scrollbar_mode(guider_ui.Metronomehome_spangroup_1, LV_SCROLLBAR_MODE_OFF);
        break;
    }
    default:
        break;
    }
}
static void Metronomehome_btn_5_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        if (switchState == 0)
        {
            switchState = 1;
            lv_label_set_text(guider_ui.Metronomehome_btn_5_label, "ON");
            break;
        }
        if (switchState == 1)
        {
            switchState = 0;
            lv_label_set_text(guider_ui.Metronomehome_btn_5_label, "OFF");
            break;
        }
        // Write the load screen code.
        break;
    }
    default:
        break;
    }
}
void events_init_Metronomehome(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Metronomehome_btn_4, Metronomehome_btn_4_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Metronomehome_slider_1, Metronomehome_slider_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Metronomehome_btn_1, Metronomehome_btn_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Metronomehome_btn_2, Metronomehome_btn_2_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Metronomehome_btn_5, Metronomehome_btn_5_event_handler, LV_EVENT_ALL, NULL);
}
static void Pagehome_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}
static void Pagehome_btn_4_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.screen_del == true)
            {
                setup_scr_screen(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.screen_del = true;
        }
        break;
    }
    default:
        break;
    }
}
static void Pagehome_ddlist_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_RELEASED:
        isddlistRefreshed = 1;
        break;
    default:
        break;
    }
}

static void Pagehome_btn_2_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Musicsheetpresenter_del == true)
            {
                setup_scr_Musicsheetpresenter(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Musicsheetpresenter, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.Musicsheetpresenter_del = true;
        }
        break;
    }
    default:
        break;
    }
}
static void Pagehome_btn_5_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        if (displayerMode == 0)
        {
            displayerMode = 1;
            lv_label_set_text(guider_ui.Pagehome_btn_5_label, "TRIG");
            lv_obj_add_flag(guider_ui.Pagehome_spangroup_1, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.Pagehome_slider_1, LV_OBJ_FLAG_HIDDEN);
            break;
        }
        if (displayerMode == 1)
        {
            displayerMode = 0;
            lv_label_set_text(guider_ui.Pagehome_btn_5_label, "AUTO");
            lv_obj_clear_flag(guider_ui.Pagehome_spangroup_1, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_ui.Pagehome_slider_1, LV_OBJ_FLAG_HIDDEN);
            break;
        }
        break;
    }
    default:
        break;
    }
}
static void Pagehome_btn_6_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        if (LEDState == 0)
        {
            LEDState = 1;
            lv_label_set_text(guider_ui.Pagehome_btn_6_label, "GUIDE");
            lv_obj_set_style_bg_color(guider_ui.Pagehome_btn_6, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        }
        else if (LEDState == 1)
        {
            LEDState = 2;
            lv_label_set_text(guider_ui.Pagehome_btn_6_label, "FFT");
            lv_obj_set_style_bg_color(guider_ui.Pagehome_btn_6, lv_color_hex(0xD01FBB), LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        }
        else if (LEDState == 2)
        {
            LEDState = 0;
            lv_label_set_text(guider_ui.Pagehome_btn_6_label, "NONE");
            lv_obj_set_style_bg_color(guider_ui.Pagehome_btn_6, lv_color_hex(0x009ea9), LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        }
        break;
    }
    default:
        break;
    }
}
static void Pagehome_slider_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_spangroup_del_span(guider_ui.Pagehome_spangroup_1, lv_spangroup_get_child(guider_ui.Pagehome_spangroup_1, -1));
        lv_spangroup_del_span(guider_ui.Pagehome_spangroup_1, lv_spangroup_get_child(guider_ui.Pagehome_spangroup_1, -1));
        // lv_spangroup_del_span(guider_ui.Pagehome_spangroup_1, lv_spangroup_get_child(guider_ui.Pagehome_spangroup_1, -1));
        displayerbpm = lv_slider_get_value(guider_ui.Pagehome_slider_1);
        char temp_char[10];
        itoa(displayerbpm, temp_char, 10);
        guider_ui.Pagehome_spangroup_1 = lv_spangroup_create(guider_ui.Pagehome);
        lv_spangroup_set_align(guider_ui.Pagehome_spangroup_1, LV_TEXT_ALIGN_LEFT);
        lv_spangroup_set_overflow(guider_ui.Pagehome_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
        lv_spangroup_set_mode(guider_ui.Pagehome_spangroup_1, LV_SPAN_MODE_BREAK);
        // create spans
        lv_span_t *Pagehome_spangroup_1_span;
        Pagehome_spangroup_1_span = lv_spangroup_new_span(guider_ui.Pagehome_spangroup_1);
        lv_span_set_text(Pagehome_spangroup_1_span, temp_char);
        lv_style_set_text_color(&Pagehome_spangroup_1_span->style, lv_color_hex(0xffffff));
        lv_style_set_text_decor(&Pagehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
        lv_style_set_text_font(&Pagehome_spangroup_1_span->style, &lv_font_Alatsi_Regular_19);
        Pagehome_spangroup_1_span = lv_spangroup_new_span(guider_ui.Pagehome_spangroup_1);
        lv_span_set_text(Pagehome_spangroup_1_span, " bpm");
        lv_style_set_text_color(&Pagehome_spangroup_1_span->style, lv_color_hex(0xffffff));
        lv_style_set_text_decor(&Pagehome_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
        lv_style_set_text_font(&Pagehome_spangroup_1_span->style, &lv_font_montserratMedium_17);
        lv_obj_set_pos(guider_ui.Pagehome_spangroup_1, 149, 261);
        lv_obj_set_size(guider_ui.Pagehome_spangroup_1, 96, 36);
        lv_obj_set_scrollbar_mode(guider_ui.Pagehome_spangroup_1, LV_SCROLLBAR_MODE_OFF);

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
        lv_obj_add_style(guider_ui.Pagehome_spangroup_1, &style_Pagehome_spangroup_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_spangroup_refr_mode(guider_ui.Pagehome_spangroup_1);
        break;
    }
    default:
        break;
    }
}
void events_init_Pagehome(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Pagehome, Pagehome_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Pagehome_btn_4, Pagehome_btn_4_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(lv_dropdown_get_list(ui->Pagehome_ddlist_1), Pagehome_ddlist_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Pagehome_btn_2, Pagehome_btn_2_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Pagehome_btn_5, Pagehome_btn_5_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Pagehome_slider_1, Pagehome_slider_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Pagehome_btn_6, Pagehome_btn_6_event_handler, LV_EVENT_ALL, NULL);
}
static void TurnerAutoHome_btn_2_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.screen_del == true)
            {
                setup_scr_screen(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.screen_del = true;
        }
        break;
    }
    default:
        break;
    }
}
static void TurnerAutoHome_sw_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Tunerhome_del == true)
            {
                setup_scr_Tunerhome(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Tunerhome, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.Tunerhome_del = true;
        }
        break;
    }
    default:
        break;
    }
}
void events_init_TurnerAutoHome(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->TurnerAutoHome_btn_2, TurnerAutoHome_btn_2_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->TurnerAutoHome_sw_1, TurnerAutoHome_sw_1_event_handler, LV_EVENT_ALL, NULL);
}
static void Musicsheetpresenter_btn_3_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        if (displayerState == 0)
        {
            displayerState = 1;
            lv_label_set_text(guider_ui.Musicsheetpresenter_btn_3_label, "CONTINUE");
            break;
        }
        if (displayerState == 1)
        {
            displayerState = 0;
            lv_label_set_text(guider_ui.Musicsheetpresenter_btn_3_label, "PAUSED");
            break;
        }
        break;
    }
    default:
        break;
    }
}
static void Musicsheetpresenter_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Pagehome_del == true)
            {
                setup_scr_Pagehome(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Pagehome, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.Pagehome_del = true;
        }
        continueState = 0;
        pauseState = 0;
        break;
    }
    default:
        break;
    }
}

void events_init_Musicsheetpresenter(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Musicsheetpresenter_btn_3, Musicsheetpresenter_btn_3_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Musicsheetpresenter_btn_1, Musicsheetpresenter_btn_1_event_handler, LV_EVENT_ALL, NULL);
}
static void Settings_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.screen_del == true)
            {
                setup_scr_screen(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
            guider_ui.screen_del = true;
        }
        break;
    }
    default:
        break;
    }
}

static void Settings_ta_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        kbState = 1;
        if (kb1State == 1)
        {
            lv_obj_add_flag(guider_ui.kb1, LV_OBJ_FLAG_HIDDEN);
        }
        if (kbDisplay == 0)
        {
            guider_ui.kb = lv_keyboard_create(lv_scr_act());
            lv_keyboard_set_textarea(guider_ui.kb, guider_ui.Settings_ta_1);
            lv_keyboard_set_mode(guider_ui.kb, LV_KEYBOARD_MODE_TEXT_UPPER);
            lv_obj_set_size(guider_ui.kb, 480, 100);
            lv_obj_set_align(guider_ui.kb, LV_ALIGN_CENTER);
            lv_obj_set_pos(guider_ui.kb, 0, 110); // Set the position of the keyboard
            kbDisplay = 1;
        }
        else
        {
            lv_obj_clear_flag(guider_ui.kb, LV_OBJ_FLAG_HIDDEN);
        }

        break;
    }
    case LV_EVENT_READY:
    {
        kbState = 0;
        lv_obj_add_flag(guider_ui.kb, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}
static void Settings_ta_2_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        kb1State = 1;
        if (kbState == 1)
        {
            lv_obj_add_flag(guider_ui.kb, LV_OBJ_FLAG_HIDDEN);
        }
        if (kb1Display == 0)
        {
            guider_ui.kb1 = lv_keyboard_create(lv_scr_act());
            lv_keyboard_set_textarea(guider_ui.kb1, guider_ui.Settings_ta_2);
            lv_keyboard_set_mode(guider_ui.kb1, LV_KEYBOARD_MODE_TEXT_UPPER);
            lv_obj_set_size(guider_ui.kb1, 480, 100);
            lv_obj_set_align(guider_ui.kb1, LV_ALIGN_CENTER);
            lv_obj_set_pos(guider_ui.kb1, 0, 110); // Set the position of the keyboard
            kb1Display = 1;
        }
        else
        {
            lv_obj_clear_flag(guider_ui.kb1, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    }
    case LV_EVENT_READY:
    {
        kb1State = 0;
        lv_obj_add_flag(guider_ui.kb1, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}
void events_init_Settings(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Settings_btn_1, Settings_btn_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Settings_ta_1, Settings_ta_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Settings_ta_2, Settings_ta_2_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{
}
