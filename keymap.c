#include QMK_KEYBOARD_H

// Layer names
enum{
  _COLEMAKDH, // Base Colemak Mod-DH
  _SYMB, // Symbols
  _NAVI, // Navigation
  _NUMB, // Numbers
  _FUNC, // Functions keys
  _MOUS, // Mouse
  _WSPC, // Workspace
  _ADJUST // Adjust
};

// Custom keycodes
enum custom_keycodes {
  COLEMAKDH = SAFE_RANGE,
  ASC_SAR,
  ASC_DAR,
  ASC_SQT,
  ASC_DQT,
  ASC_CIRC,
  ASC_TILD,
  ASC_HAP,
  ASC_SAD,
  ASC_BKT,
  ASC_COP,
  ASC_CCL,
  ASC_DDS,
  ASC_SSL
};


// Shortcuts to make keymap more readable
// - Adjustment Layer:
#define KC_ADHO LT(_ADJUST, KC_HOME)  // Home / _ADJUST layer
#define KC_ADPU LT(_ADJUST, KC_PGUP)  // Page Up / _ADJUST layer
// - Home row modifiers:
#define KC_GU_A LGUI_T(KC_A)          // A / Left Gui
#define KC_CT_S LCTL_T(KC_S)          // R / Left Ctrl
#define KC_AL_R LALT_T(KC_R)          // S / Left Alt
#define KC_LS_T LSFT_T(KC_T)          // T / Left Shift
#define KC_GU_O RGUI_T(KC_O)          // O / Right Gui
#define KC_AL_I LALT_T(KC_I)          // E / Left Alt (left alt because used as Emacs M- )
#define KC_CT_E RCTL_T(KC_E)          // I / Right Ctrl
#define KC_RS_N RSFT_T(KC_N)          // N / Right Shift
#define KC_AR_X RALT_T(KC_X)          // X / Right Alt
#define KC_AR_DO RALT_T(KC_DOT)       // . / Right Alt
#define KC_HY_G HYPR_T(KC_G)          // G / Hypr
#define KC_HY_M HYPR_T(KC_M)          // M / Hypr

// - Thumbs keys/modifiers:
#define KC_SYSP LT(_SYMB, KC_SPC)     // Space / _symbols
#define KC_FUEN LT(_FUNC, KC_ENT)     // Enter / _functions
#define KC_NUTA LT(_NUMB, KC_TAB)     // Tab / _numbers
#define KC_NABS LT(_NAVI, KC_BSPC)    // Backspace / _navigation
#define KC_MOES LT(_MOUS, KC_ESC)     // Esc / _mouse
#define KC_WSDE LT(_WSPC, KC_DEL)     // Del / _workspace
#define KC_GUDE LGUI_T(KC_DEL)     // Del / _workspace

// - Toggle layers:
#define TG_NUM TG(_NUMB)
/* #define TG_NAV TG(_NAVI) */

// - Awesome WM macros:
#define KC_AW1 LGUI(KC_1)
#define KC_AW2 LGUI(KC_2)
#define KC_AW3 LGUI(KC_3)
#define KC_AW4 LGUI(KC_4)
#define KC_AW5 LGUI(KC_5)
#define KC_AW6 LGUI(KC_6)
#define KC_AW7 LGUI(KC_7)
#define KC_AW8 LGUI(KC_8)
#define KC_AW9 LGUI(KC_9)
// - Clipboard, Undo/Redo and "select all" (should work almost everywhere, including Emacs)
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
//#define U_UND KC_UNDO
//#define U_RDO KC_AGIN
#define U_UND LCTL(KC_Z) // Doesn't work on Emacs
#define U_RDO LCTL(LSFT(KC_Z)) // Doesn't work on Emacs
/* #define U_ALL C(KC_A) // Emacs need to rebind mark-whole-buffer to: C-a */

//- Macros
#define KC_PTAB RCS(KC_TAB)
#define KC_NTAB C(KC_TAB)

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

// Send custom strings or change default base layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case ASC_SAR:
        SEND_STRING("->");
        return false;
      case ASC_DAR:
        SEND_STRING("=>");
        return false;
      case ASC_SQT:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("'"));
        return false;
      case ASC_DQT:
        // SS_RALT(SS_LSFT()): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT(SS_LSFT("\"")));
        return false;
      case ASC_CIRC:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("^"));
        return false;
      case ASC_TILD:
        // SS_RALT(SS_LSFT()): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT(SS_LSFT("~")));
        return false;
      case ASC_HAP:
        SEND_STRING(":-) ");
        return false;
      case ASC_SAD:
        SEND_STRING(":-( ");
        return false;
      case ASC_BKT:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("`"));
        return false;
      case ASC_COP:
        SEND_STRING("/*");
        return false;
      case ASC_CCL:
        SEND_STRING("*/");
        return false;
      case ASC_DDS:
        SEND_STRING("../");
        return false;
      case ASC_SSL:
        SEND_STRING("//");
        return false;
      case COLEMAKDH:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_COLEMAKDH);
        }
        return false;
        break;
    }
  }
  return true;
};

// Fine tuning of TAPPING_TERM valuer on some home row modifiers to avoid errors during typing.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  // Pinkies
  case KC_GU_O:
    return TAPPING_TERM + 300;
  case KC_GU_A:
    return TAPPING_TERM + 150;

  // Ring fingers
  case KC_AL_I:
  case KC_AL_R:
  case KC_AR_X:
  case KC_AR_DO:
    return TAPPING_TERM + 200;

  // Middle fingers
  case KC_CT_S:
  case KC_CT_E:
    return TAPPING_TERM - 30;

  // Index fingers
  case KC_LS_T:
  case KC_RS_N:
    return TAPPING_TERM - 40;

  // Right thumbs
  case KC_SYSP:
    return TAPPING_TERM - 80;
  case KC_NUTA:
  case KC_FUEN:
    return TAPPING_TERM - 20;

  // All other keys
  default:
    return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // -----------------------------------------------------------------------------
    // Colemak Mod-DH
    // -----------------------------------------------------------------------------
    [_COLEMAKDH] = LAYOUT_split_3x5_3(
    // left hand                                                                    // right hand
    KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,                                               KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,
    KC_GU_A ,KC_AL_R ,KC_CT_S ,KC_LS_T ,KC_HY_G ,                                               KC_HY_M ,KC_RS_N ,KC_CT_E ,KC_AL_I ,KC_GU_O ,
    KC_Z    ,KC_AR_X ,KC_C    ,KC_D    ,KC_V    ,                                               KC_K    ,KC_H    ,KC_COMM ,KC_AR_DO,KC_SLSH ,
                                    KC_MOES ,KC_NABS ,KC_GUDE ,                     KC_FUEN, KC_SYSP ,KC_NUTA
    ),


    // -----------------------------------------------------------------------------
    // Symbols
    // -----------------------------------------------------------------------------
    [_SYMB] = LAYOUT_split_3x5_3(
    // left hand                                                                    // right hand
    KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                                                       ASC_CIRC,KC_AMPR ,KC_ASTR ,ASC_COP ,ASC_CCL ,
    KC_PIPE ,KC_PMNS ,ASC_SQT ,ASC_DQT ,KC_GRV  ,                                                       KC_QUOT ,KC_COLN ,ASC_TILD,ASC_SAR ,ASC_DAR ,
    KC_BSLS ,KC_UNDS ,KC_LCBR ,KC_LBRC ,KC_EQL  ,                                                       ASC_BKT ,KC_RBRC ,KC_RCBR ,ASC_DDS ,ASC_SSL ,
                                    KC_RPRN ,KC_LPRN ,ASC_HAP ,                     XXXXXXX, _______ ,XXXXXXX
    ),



    // -----------------------------------------------------------------------------
    // Navigation
    // -----------------------------------------------------------------------------
    [_NAVI] = LAYOUT_split_3x5_3(
    // left hand                                                                    // right hand
    XXXXXXX ,KC_TAB  ,KC_PTAB ,KC_NTAB ,KC_SPC  ,                                                       XXXXXXX ,RCS(KC_LEFT)  ,C(KC_LEFT)   ,C(KC_RGHT)   ,RCS(KC_RGHT)   ,
    KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,KC_ENT  ,                                                       XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,
    U_UND   ,U_CUT   ,U_CPY   ,U_PST   ,U_RDO   ,                                                       _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,
                                    _______ ,XXXXXXX ,XXXXXXX ,                             XXXXXXX ,XXXXXXX ,XXXXXXX
    ),

    // -----------------------------------------------------------------------------
    // Mouse
    // -----------------------------------------------------------------------------
    [_MOUS] = LAYOUT_split_3x5_3(
    // left hand                                                                     // right hand
    XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,KC_COMM ,                                                        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    XXXXXXX ,KC_4    ,KC_5    ,KC_6    ,KC_0    ,                                                        XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_U ,KC_MS_R ,
    XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,KC_DOT  ,                                                        XXXXXXX ,KC_WH_L ,KC_WH_D ,KC_WH_U ,KC_WH_R ,
                                    XXXXXXX ,XXXXXXX ,_______ ,                              KC_BTN3 ,KC_BTN1 ,KC_BTN2
    ),

    // -----------------------------------------------------------------------------
    // Numeric keypad layer
    // -----------------------------------------------------------------------------
    [_NUMB] = LAYOUT_split_3x5_3(
    // left hand                                                                    // right hand
    KC_PMNS ,KC_7    ,KC_8    ,KC_9    ,KC_PPLS ,                                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    KC_DOT  ,KC_4    ,KC_5    ,KC_6    ,KC_PAST ,                                                       KC_HYPR ,KC_RSFT ,KC_RCTL ,KC_LALT ,KC_RGUI ,
    KC_PSLS ,KC_1    ,KC_2    ,KC_3    ,KC_EQL  ,                                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RALT ,XXXXXXX ,
                                    KC_COMM ,KC_0    ,KC_BSPC ,                             XXXXXXX ,XXXXXXX ,_______
    ),

    // -----------------------------------------------------------------------------
    // Function layer and some extra keys on right hand
    // -----------------------------------------------------------------------------
    [_FUNC] = LAYOUT_split_3x5_3(
    // left hand                                                                    // right hand
    KC_F12  ,KC_F7   ,KC_F8   ,KC_F9   ,KC_CAPS ,                                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,
    KC_F11  ,KC_F4   ,KC_F5   ,KC_F6   ,KC_PSCR ,                                                       KC_HYPR ,KC_RSFT ,KC_RCTL ,KC_LALT ,KC_RGUI ,
    KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_INS  ,                                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RALT ,XXXXXXX ,
                                    XXXXXXX ,XXXXXXX ,XXXXXXX ,                             _______, XXXXXXX ,XXXXXXX
    ),


    // -----------------------------------------------------------------------------
    // Workspace (AwesomeWM navigation) - CURRENTLY DISABLED
    // -----------------------------------------------------------------------------
    [_WSPC] = LAYOUT_split_3x5_3(
    // left hand                                                                    // right hand
    G(KC_Q) ,KC_AW7  ,KC_AW8  ,KC_AW9  ,XXXXXXX ,                                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    XXXXXXX ,KC_AW4  ,KC_AW5  ,KC_AW6  ,XXXXXXX ,                                                       XXXXXXX ,KC_RSFT ,KC_RCTL ,KC_LALT ,KC_RGUI ,
    XXXXXXX ,KC_AW1  ,KC_AW2  ,KC_AW3  ,XXXXXXX ,                                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RALT ,XXXXXXX ,
                                    XXXXXXX ,XXXXXXX ,XXXXXXX ,                             _______, XXXXXXX ,XXXXXXX
    ),


    // -----------------------------------------------------------------------------
    // Adjust layer (RGB, Reset and base layer switch)
    // -----------------------------------------------------------------------------
    [_ADJUST] = LAYOUT_split_3x5_3(
    // left hand                                                                    // right hand
    QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                    _______ ,_______ ,_______ ,                             _______ ,_______ ,_______
    ),
};




// -----------------------------------------------------------------------------
// Combos
// -----------------------------------------------------------------------------
enum combos {
  /* BG_DEL, */
  /* JM_ENT, */
  DH_ESC
};

/* const uint16_t PROGMEM bg_combo[] = {KC_B, KC_G, COMBO_END}; */
/* const uint16_t PROGMEM jm_combo[] = {KC_J, KC_M, COMBO_END}; */
const uint16_t PROGMEM dh_combo[] = {KC_D, KC_H, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  /* [BG_DEL] = COMBO(bg_combo, KC_DEL), */
  /* [JM_ENT] = COMBO(jm_combo, KC_ENT), */
  [DH_ESC] = COMBO(dh_combo, KC_ESC)
};


// Enable tapping_force_hold only for home row mods
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_LS_T:
  case KC_CT_S:
  case KC_AL_R:
  case KC_GU_A:
  case KC_RS_N:
  case KC_CT_E:
  case KC_AL_I:
  case KC_GU_O:
  case KC_AR_X:
  case KC_AR_DO:
    return true;
  default:
    return false;
  }
}
