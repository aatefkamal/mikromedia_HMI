#ifndef MIKROMEDIA_HMI_43C_DEMO_OBJECTS
#define MIKROMEDIA_HMI_43C_DEMO_OBJECTS

#include "FT812_Types.h"

typedef enum {taNone, taLeft, taCenter, taRight, taCenterX, taCenterY, taRightX} TTextAlign;

typedef struct Screen TScreen;

typedef unsigned long TPointer;

typedef struct tagObjInfo {
  void     *Obj;
  char     Type;
  char     Order;
  char     Flags;

  char     HitTag;
  int      HitX;
  int      HitY;
} TObjInfo;

typedef struct tagTouchStat {
  char Pressed;

  char Tag;
  int  X;
  int  Y;

  TObjInfo ActObjInfo;
} TTouchStat;

typedef void (*TDrawHandler)(TPointer aObj);

typedef void (*TEvtAction)();

typedef struct tagEvtSound {
  char SndAct;
  char Effect;
  char Pitch;
  char Volume;
} TEvtSound;

typedef const struct tagCEvent {
  TEvtAction Action;
  TEvtSound  Sound;
} TCEvent;

typedef struct tagEvent {
  TEvtAction Action;
  TEvtSound  Sound;
} TEvent;

typedef const struct tagCRect {
  int Left;
  int Top;
  int Width;
  int Height;
} TCRect;

typedef struct tagRect {
  int Left;
  int Top;
  int Width;
  int Height;
} TRect;

typedef struct tagButton {
  TScreen      *OwnerScreen;
  char         Order;
  char         Visible;
  char         Opacity;
  char         Tag;
  int          Left;
  int          Top;
  int          Width;
  int          Height;
  char         Pen_Width;
  uintcolor_ft Pen_Color;
  uintcolor_ft Color;
  uintcolor_ft Press_Color;
  uintcolor_ft ColorTo;
  uintcolor_ft Press_ColorTo;
  char         Gradient;
  char         *Caption;
  TTextAlign   TextAlign;
  TPointer     FontName;
  uintcolor_ft Font_Color;
  char         FontHandle;
  long         Source;
  char         Active;
  TEvent       *OnUp;
  TEvent       *OnDown;
  TEvent       *OnClick;
  TEvent       *OnPress;
} TButton;

typedef struct tagLabel {
  TScreen  *OwnerScreen;
  char     Order;
  char     Visible;
  char     Opacity;
  char     Tag;
  int      Left;
  int      Top;
  int      Width;
  int      Height;
  char     *Caption;
  TPointer FontName;
  uintcolor_ft Font_Color;
  char     FontHandle;
  long     Source;
  char     Active;
  TEvent   *OnUp;
  TEvent   *OnDown;
  TEvent   *OnClick;
  TEvent   *OnPress;
} TLabel;

typedef struct tagImage {
  TScreen         *OwnerScreen;
  char            Order;
  char            Visible;
  char            Opacity;
  char            Tag;
  int             Left;
  int             Top;
  int             Width;
  int             Height;
  TPointer        Picture_Name;
  char            Picture_Type;
  char            Picture_Ratio;
  uintcolor_ft    Blend_Color;
  long            Source;
  int             RotationAngle;
  int             RotationCenterLeft;
  int             RotationCenterTop;
  float           ScaleX;
  float           ScaleY;
  char            Active;
  TEvent          *OnUp;
  TEvent          *OnDown;
  TEvent          *OnClick;
  TEvent          *OnPress;
} TImage;

typedef struct tagCircleButton {
  TScreen      *OwnerScreen;
  char         Order;
  char         Visible;
  char         Opacity;
  char         Tag;
  int          Left;
  int          Top;
  int          Radius;
  char         Pen_Width;
  uintcolor_ft Pen_Color;
  uintcolor_ft Color;
  uintcolor_ft Press_Color;
  char         *Caption;
  TTextAlign   TextAlign;
  TPointer     FontName;
  uintcolor_ft Font_Color;
  char         FontHandle;
  long         Source;
  char         Active;
  TEvent       *OnUp;
  TEvent       *OnDown;
  TEvent       *OnClick;
  TEvent       *OnPress;
} TCircleButton;

typedef struct tagBox {
  TScreen      *OwnerScreen;
  char         Order;
  char         Visible;
  char         Opacity;
  char         Tag;
  int          Left;
  int          Top;
  int          Width;
  int          Height;
  char         Pen_Width;
  uintcolor_ft Pen_Color;
  uintcolor_ft Color;
  uintcolor_ft Press_Color;
  uintcolor_ft ColorTo;
  uintcolor_ft Press_ColorTo;
  char         Gradient;
  char         Active;
  TEvent       *OnUp;
  TEvent       *OnDown;
  TEvent       *OnClick;
  TEvent       *OnPress;
} TBox;

typedef struct tagCheckBox {
  TScreen      *OwnerScreen;
  char         Order;
  char         Visible;
  char         Opacity;
  char         Tag;
  int          Left;
  int          Top;
  int          Width;
  int          Height;
  char         Pen_Width;
  uintcolor_ft Pen_Color;
  uintcolor_ft Background_Color;
  uintcolor_ft Color;
  uintcolor_ft Press_Color;
  char         *Caption;
  TTextAlign   TextAlign;
  TPointer     FontName;
  uintcolor_ft Font_Color;
  char         FontHandle;
  long         Source;
  char         Corner_Radius;
  char         Checked;
  char         Active;
  TEvent       *OnUp;
  TEvent       *OnDown;
  TEvent       *OnClick;
  TEvent       *OnPress;
} TCheckBox;

struct Screen {
  uintcolor_ft   Color;
  unsigned int   Width;
  unsigned int   Height;
  unsigned short ObjectsCount;
  unsigned short ButtonsCount;
  TButton        *const code *Buttons;
  unsigned short LabelsCount;
  TLabel         *const code *Labels;
  unsigned short ImagesCount;
  TImage         *const code *Images;
  unsigned short CircleButtonsCount;
  TCircleButton  *const code *CircleButtons;
  unsigned short BoxesCount;
  TBox           *const code *Boxes;
  unsigned short CheckBoxesCount;
  TCheckBox      *const code *CheckBoxes;
  unsigned long  DynResStart;
  unsigned short Active;
  unsigned short SniffObjectEvents;
  TEvent         *OnUp;
  TEvent         *OnDown;
  TEvent         *OnTagChange;
  TEvent         *OnPress;
};


// Object type constants
// Usage: VTFT stack internally
extern const VTFT_OT_BUTTON;
extern const VTFT_OT_LABEL;
extern const VTFT_OT_IMAGE;
extern const VTFT_OT_CIRCLEBUTTON;
extern const VTFT_OT_BOX;
extern const VTFT_OT_CHECKBOX;
// ~Object type constants

// Event type constants
// Usage: OnEvent
extern const VTFT_EVT_UP;
extern const VTFT_EVT_DOWN;
extern const VTFT_EVT_CLICK;
extern const VTFT_EVT_PRESS;
// ~Event type constants

// Sound action constants
// Usage: sound event action property and ProcessEvent
extern const VTFT_SNDACT_NONE;
extern const VTFT_SNDACT_PLAY;
extern const VTFT_SNDACT_STOP;
// ~Sound action constants

// Resource loading constants.
// Usage: DrawScreenO and LoadCurrentScreenResToGRAM
extern const VTFT_LOAD_RES_NONE;
extern const VTFT_LOAD_RES_STATIC;
extern const VTFT_LOAD_RES_DYNAMIC;
extern const VTFT_LOAD_RES_ALL;
// ~Resource loading constants

// Display effect constants
// Usage: DrawScreenO
extern const VTFT_DISPLAY_EFF_NONE;
extern const VTFT_DISPLAY_EFF_LIGHTS_FADE;
extern const VTFT_DISPLAY_EFF_LIGHTS_OFF;
// ~Display effect constants

// Stack flags
// Usage: internally used by VTFT stack
extern const VTFT_INT_REPAINT_ON_DOWN;
extern const VTFT_INT_REPAINT_ON_UP;
extern const VTFT_INT_BRING_TO_FRONT;
extern const VTFT_INT_INTRINSIC_CLICK_EFF;
// ~Stack flags

extern const TPointer DrawHandlerTable[44];


// Default configuration parameters
extern const TFT812PWM            VTFT_FT812_CONFIG_PWM;
extern const TFT812GPIO           VTFT_FT812_CONFIG_GPIO;
extern const TFT812Sound          VTFT_FT812_CONFIG_SOUND;
extern const TFT812Audio          VTFT_FT812_CONFIG_AUDIO;
extern const TFT812Display        VTFT_FT812_CONFIG_DISPLAY;
extern const TFT812Interrupt      VTFT_FT812_CONFIG_INTERRUPT;

extern TTouchStat TouchS;

extern TScreen Home;

extern TBox   Box34;
extern TImage Image75;
extern TImage Image76;
extern TBox   Box2;
extern TEvent Box2_OnClick;
extern TImage Image74;
extern TImage Image72;
extern TImage Image73;
extern TImage Image71;
extern TBox   Box1;
extern TEvent Box1_OnClick;
extern TImage Image43;
extern TImage Image42;
extern TImage Image40;
extern TImage Image5;
extern TImage Image41;
extern TImage Image64;
extern TImage Image45;
extern TImage Image44;
extern TBox   Box35;
extern TEvent Box35_OnClick;
extern TImage Image39;
extern TBox   Box12;
extern TEvent Box12_OnClick;
extern TBox   Box16;
extern TBox   Box15;
extern TBox   Box14;
extern TBox   Box21;
extern TEvent Box21_OnClick;
extern TBox   Box20;
extern TEvent Box20_OnClick;
extern TBox   Box13;
extern TEvent Box13_OnClick;
extern TBox   Box7;
extern TEvent Box7_OnClick;
extern TBox   Box5;
extern TEvent Box5_OnClick;
extern TBox   Box3;
extern TEvent Box3_OnClick;
extern TBox   Box31;
extern TEvent Box31_OnClick;
extern TImage Image1;
extern TImage Image17;
extern TImage Image16;
extern TImage Image9;
extern TImage Image8;
extern TImage Image7;
extern TImage Image6;
extern TImage Image14;
extern TImage Image12;
extern TImage Image10;
extern TImage Image3;
extern TImage Image4;
extern TEvent Image4_OnClick;
extern TImage Image38;
extern TImage Image37;
extern TEvent Image37_OnClick;
extern TImage Image36;
extern TEvent Image36_OnClick;
extern TImage Image35;
extern TEvent Image35_OnClick;
extern TImage Image29;
extern TImage Image30;
extern TImage Image31;
extern TImage Image27;
extern TImage Image25;
extern TImage Image23;
extern TImage Image21;
extern TLabel Label1;
extern TLabel Label2;
extern TLabel Label3;
extern TLabel Label4;
extern TLabel Label5;
extern TLabel Label7;
extern TLabel Label8;
extern TLabel Label9;
extern TLabel Label10;
extern TLabel Label11;
extern TLabel Label15;
extern TLabel Label16;
extern TLabel Label17;
extern TLabel Label20;
extern TLabel Label23;
extern TBox   Box28;
extern TEvent Box28_OnClick;
extern TLabel Label35;
extern TLabel Label36;
extern TLabel Label38;
extern TLabel Label40;
extern TLabel Label42;
extern TLabel Label61;
extern TLabel Label68;
extern TLabel Label69;
extern TLabel Label70;
extern TLabel Label73;
extern TLabel Label74;
extern TLabel Label75;
extern TLabel Label76;
extern TLabel Label77;
extern TLabel Label78;
extern TLabel Label58;
extern TLabel Label59;
extern TLabel Label60;

extern TLabel *const code Home_Labels[33];
extern TImage *const code Home_Images[38];
extern TBox   *const code Home_Boxes[16];

extern TScreen Temperature_Mode;

extern TBox          Box45;
extern TImage        Image60;
extern TBox          Box40;
extern TEvent        Box40_OnClick;
extern TBox          Box39;
extern TEvent        Box39_OnClick;
extern TBox          Box38;
extern TEvent        Box38_OnClick;
extern TBox          Box37;
extern TEvent        Box37_OnClick;
extern TImage        Image51;
extern TImage        Image50;
extern TImage        Image49;
extern TImage        Image48;
extern TImage        Image47;
extern TImage        Image46;
extern TImage        Image28;
extern TImage        Image2;
extern TButton       Button30;
extern TEvent        Button30_OnClick;
extern TBox          Box22;
extern TButton       Button47;
extern TBox          Box41;
extern TBox          Box42;
extern TBox          Box43;
extern TBox          Box44;
extern TBox          Box46;
extern TBox          Box47;
extern TBox          Box48;
extern TCircleButton CircleButton1;
extern TEvent        CircleButton1_OnPress;
extern TCircleButton CircleButton2;
extern TEvent        CircleButton2_OnPress;
extern TCircleButton CircleButton3;
extern TEvent        CircleButton3_OnPress;
extern TCircleButton CircleButton4;
extern TEvent        CircleButton4_OnPress;
extern TBox          Box23;
extern TBox          Box49;
extern TLabel        Label29;
extern TLabel        Label31;
extern TLabel        Label32;
extern TLabel        Label33;
extern TLabel        Label46;
extern TLabel        Label47;
extern TLabel        Label86;
extern TLabel        Label87;
extern TLabel        Label95;
extern TLabel        Label96;

extern TButton       *const code Temperature_Mode_Buttons[2];
extern TLabel        *const code Temperature_Mode_Labels[10];
extern TImage        *const code Temperature_Mode_Images[9];
extern TCircleButton *const code Temperature_Mode_CircleButtons[4];
extern TBox          *const code Temperature_Mode_Boxes[15];

extern TScreen Light_Mode;

extern TBox          Box61;
extern TImage        Image61;
extern TBox          Box55;
extern TEvent        Box55_OnClick;
extern TBox          Box53;
extern TEvent        Box53_OnClick;
extern TBox          Box52;
extern TEvent        Box52_OnClick;
extern TBox          Box51;
extern TEvent        Box51_OnClick;
extern TImage        Image59;
extern TImage        Image58;
extern TImage        Image57;
extern TImage        Image56;
extern TImage        Image55;
extern TImage        Image54;
extern TImage        Image53;
extern TImage        Image52;
extern TButton       Button31;
extern TEvent        Button31_OnClick;
extern TBox          Box50;
extern TButton       Button32;
extern TBox          Box56;
extern TBox          Box57;
extern TBox          Box58;
extern TBox          Box59;
extern TBox          Box60;
extern TBox          Box62;
extern TBox          Box63;
extern TCircleButton CircleButton5;
extern TEvent        CircleButton5_OnPress;
extern TCircleButton CircleButton6;
extern TEvent        CircleButton6_OnPress;
extern TCircleButton CircleButton7;
extern TEvent        CircleButton7_OnPress;
extern TCircleButton CircleButton8;
extern TEvent        CircleButton8_OnPress;
extern TBox          Box64;
extern TBox          Box65;
extern TLabel        Label48;
extern TLabel        Label49;
extern TLabel        Label50;
extern TLabel        Label51;
extern TLabel        Label52;
extern TLabel        Label53;
extern TLabel        Label88;
extern TLabel        Label89;
extern TLabel        Label97;
extern TLabel        Label98;

extern TButton       *const code Light_Mode_Buttons[2];
extern TLabel        *const code Light_Mode_Labels[10];
extern TImage        *const code Light_Mode_Images[9];
extern TCircleButton *const code Light_Mode_CircleButtons[4];
extern TBox          *const code Light_Mode_Boxes[15];

extern TScreen Keyboard_Screen;

extern TButton   Button37;
extern TButton   Button38;
extern TEvent    Button38_OnClick;
extern TBox      Box11;
extern TBox      Box24;
extern TEvent    Box24_OnClick;
extern TBox      Box76;
extern TEvent    Box76_OnClick;
extern TBox      Box77;
extern TEvent    Box77_OnClick;
extern TBox      Box78;
extern TEvent    Box78_OnClick;
extern TCheckBox CheckBox1;
extern TCheckBox CheckBox2;
extern TCheckBox CheckBox3;
extern TCheckBox CheckBox4;
extern TLabel    Label6;
extern TLabel    Label26;
extern TLabel    Label27;
extern TLabel    Label28;

extern TButton   *const code Keyboard_Screen_Buttons[2];
extern TLabel    *const code Keyboard_Screen_Labels[4];
extern TBox      *const code Keyboard_Screen_Boxes[5];
extern TCheckBox *const code Keyboard_Screen_CheckBoxes[4];

extern TScreen System_Log_Screen;

extern TBox    Box25;
extern TEvent  Box25_OnClick;
extern TImage  Image69;
extern TImage  Image70;
extern TBox    Box10;
extern TEvent  Box10_OnClick;
extern TImage  Image67;
extern TImage  Image68;
extern TBox    Box30;
extern TImage  Image66;
extern TImage  Image65;
extern TButton Button12;
extern TEvent  Button12_OnClick;
extern TBox    Box9;
extern TButton Button13;
extern TEvent  Button13_OnClick;
extern TButton Button14;
extern TEvent  Button14_OnClick;
extern TButton Button15;
extern TEvent  Button15_OnClick;
extern TButton Button16;
extern TEvent  Button16_OnClick;
extern TButton Button17;
extern TEvent  Button17_OnClick;
extern TButton Button18;
extern TEvent  Button18_OnClick;
extern TButton Button19;
extern TEvent  Button19_OnClick;
extern TButton Button20;
extern TEvent  Button20_OnClick;
extern TButton Button21;
extern TEvent  Button21_OnClick;
extern TButton Button22;
extern TEvent  Button22_OnClick;
extern TButton Button23;
extern TEvent  Button23_OnClick;
extern TButton Button24;
extern TEvent  Button24_OnClick;
extern TButton Button25;
extern TEvent  Button25_OnClick;
extern TButton Button26;
extern TEvent  Button26_OnClick;
extern TButton Button27;
extern TEvent  Button27_OnClick;
extern TButton Button28;
extern TEvent  Button28_OnClick;
extern TButton Button29;
extern TBox    Box36;
extern TLabel  Label24;
extern TLabel  Label25;
extern TLabel  Label54;
extern TLabel  Label55;

extern TButton *const code System_Log_Screen_Buttons[18];
extern TLabel  *const code System_Log_Screen_Labels[4];
extern TImage  *const code System_Log_Screen_Images[6];
extern TBox    *const code System_Log_Screen_Boxes[5];

extern TScreen Green_Power_Screen;

extern TButton Button33;
extern TButton Button34;
extern TEvent  Button34_OnClick;
extern TBox    Box26;
extern TBox    Box66;
extern TLabel  Label62;
extern TLabel  Label63;
extern TLabel  Label64;
extern TLabel  Label65;
extern TLabel  Label66;
extern TLabel  Label67;
extern TLabel  Label104;
extern TLabel  Label105;

extern TButton *const code Green_Power_Screen_Buttons[2];
extern TLabel  *const code Green_Power_Screen_Labels[8];
extern TBox    *const code Green_Power_Screen_Boxes[2];

extern TScreen Time_Screen;

extern TBox    Box67;
extern TImage  Image63;
extern TBox    Box74;
extern TImage  Image62;
extern TButton Button35;
extern TButton Button36;
extern TEvent  Button36_OnClick;
extern TBox    Box27;
extern TBox    Box68;
extern TBox    Box69;
extern TBox    Box70;
extern TBox    Box71;
extern TBox    Box72;
extern TBox    Box73;
extern TBox    Box75;
extern TLabel  Label56;
extern TLabel  Label30;
extern TLabel  Label57;
extern TLabel  Label82;
extern TLabel  Label83;
extern TLabel  Label84;
extern TLabel  Label85;
extern TLabel  Label90;
extern TLabel  Label91;
extern TLabel  Label92;
extern TLabel  Label93;
extern TLabel  Label94;
extern TLabel  Label99;
extern TLabel  Label100;
extern TLabel  Label79;
extern TLabel  Label80;
extern TLabel  Label81;

extern TButton *const code Time_Screen_Buttons[2];
extern TLabel  *const code Time_Screen_Labels[17];
extern TImage  *const code Time_Screen_Images[2];
extern TBox    *const code Time_Screen_Boxes[10];

extern TScreen Settings_Screen;

extern TBox    Box33;
extern TLabel  Label34;
extern TLabel  Label44;
extern TLabel  Label45;
extern TLabel  Label71;
extern TLabel  Label72;
extern TButton Button48;
extern TEvent  Button48_OnClick;
extern TBox    Box79;
extern TButton Button1;
extern TEvent  Button1_OnClick;
extern TButton Button2;
extern TEvent  Button2_OnClick;
extern TButton Button3;
extern TEvent  Button3_OnClick;
extern TButton Button4;
extern TEvent  Button4_OnClick;
extern TButton Button5;
extern TEvent  Button5_OnClick;
extern TButton Button6;
extern TEvent  Button6_OnClick;
extern TButton Button7;
extern TEvent  Button7_OnClick;
extern TButton Button8;
extern TEvent  Button8_OnClick;
extern TButton Button9;
extern TEvent  Button9_OnClick;
extern TButton Button10;
extern TEvent  Button10_OnClick;
extern TButton Button39;
extern TEvent  Button39_OnClick;
extern TButton Button40;
extern TEvent  Button40_OnClick;
extern TButton Button41;
extern TEvent  Button41_OnClick;
extern TButton Button42;
extern TEvent  Button42_OnClick;
extern TButton Button43;
extern TEvent  Button43_OnClick;
extern TButton Button44;
extern TEvent  Button44_OnClick;
extern TButton Button45;
extern TButton Button46;
extern TEvent  Button46_OnClick;

extern TButton *const code Settings_Screen_Buttons[19];
extern TLabel  *const code Settings_Screen_Labels[5];
extern TBox    *const code Settings_Screen_Boxes[2];

extern TScreen *CurrentScreen;

/////////////////////////
// User Event Handlers
void Box10OnClick();
void Box12OnClick();
void Box13OnClick();
void Box1OnClick();
void Box20OnClick();
void Box21OnClick();
void Box24OnClick();
void Box25OnClick();
void Box28OnClick();
void Box2OnClick();
void Box31OnClick();
void Box35OnClick();
void Box37OnClick();
void Box38OnClick();
void Box39OnClick();
void Box3OnClick();
void Box40OnClick();
void Box51OnClick();
void Box52OnClick();
void Box53OnClick();
void Box54OnClick();
void Box55OnClick();
void Box5OnClick();
void Box76OnClick();
void Box77OnClick();
void Box78OnClick();
void Box7OnClick();
void Button10OnClick();
void Button11OnClick();
void Button12OnClick();
void Button13OnClick();
void Button14OnClick();
void Button15OnClick();
void Button16OnClick();
void Button17OnClick();
void Button18OnClick();
void Button19OnClick();
void Button1OnClick();
void Button20OnClick();
void Button21OnClick();
void Button22OnClick();
void Button23OnClick();
void Button24OnClick();
void Button25OnClick();
void Button26OnClick();
void Button27OnClick();
void Button28OnClick();
void Button2OnClick();
void Button39OnClick();
void Button3OnClick();
void Button40OnClick();
void Button41OnClick();
void Button42OnClick();
void Button44OnClick();
void Button46OnClick();
void Button4OnClick();
void Button5OnClick();
void Button6OnClick();
void Button7OnClick();
void Button8OnClick();
void Button9OnClick();
void CircleButton1OnPress();
void CircleButton2OnPress();
void CircleButton3OnPress();
void CircleButton4OnPress();
void CircleButton5OnPress();
void CircleButton6OnPress();
void CircleButton7OnPress();
void CircleButton8OnPress();
/////////////////////////

/////////////////////////////////
// Captions
extern char Label1_Caption[];
extern char Label2_Caption[];
extern char Label3_Caption[];
extern char Label4_Caption[];
extern char Label5_Caption[];
extern char Label7_Caption[];
extern char Label8_Caption[];
extern char Label9_Caption[];
extern char Label10_Caption[];
extern char Label11_Caption[];
extern char Label15_Caption[];
extern char Label16_Caption[];
extern char Label17_Caption[];
extern char Label20_Caption[];
extern char Label23_Caption[];
extern char Label35_Caption[];
extern char Label36_Caption[];
extern char Label38_Caption[];
extern char Label40_Caption[];
extern char Label42_Caption[];
extern char Label61_Caption[];
extern char Label68_Caption[];
extern char Label69_Caption[];
extern char Label70_Caption[];
extern char Label73_Caption[];
extern char Label74_Caption[];
extern char Label75_Caption[];
extern char Label76_Caption[];
extern char Label77_Caption[];
extern char Label78_Caption[];
extern char Label58_Caption[];
extern char Label59_Caption[];
extern char Label60_Caption[];
extern char Button30_Caption[];
extern char Button47_Caption[];
extern char CircleButton1_Caption[];
extern char CircleButton2_Caption[];
extern char CircleButton3_Caption[];
extern char CircleButton4_Caption[];
extern char Label29_Caption[];
extern char Label31_Caption[];
extern char Label32_Caption[];
extern char Label33_Caption[];
extern char Label46_Caption[];
extern char Label47_Caption[];
extern char Label86_Caption[];
extern char Label87_Caption[];
extern char Label95_Caption[];
extern char Label96_Caption[];
extern char Button31_Caption[];
extern char Button32_Caption[];
extern char CircleButton5_Caption[];
extern char CircleButton6_Caption[];
extern char CircleButton7_Caption[];
extern char CircleButton8_Caption[];
extern char Label48_Caption[];
extern char Label49_Caption[];
extern char Label50_Caption[];
extern char Label51_Caption[];
extern char Label52_Caption[];
extern char Label53_Caption[];
extern char Label88_Caption[];
extern char Label89_Caption[];
extern char Label97_Caption[];
extern char Label98_Caption[];
extern char Button37_Caption[];
extern char Button38_Caption[];
extern char CheckBox1_Caption[];
extern char CheckBox2_Caption[];
extern char CheckBox3_Caption[];
extern char CheckBox4_Caption[];
extern char Label6_Caption[];
extern char Label26_Caption[];
extern char Label27_Caption[];
extern char Label28_Caption[];
extern char Button12_Caption[];
extern char Button13_Caption[];
extern char Button14_Caption[];
extern char Button15_Caption[];
extern char Button16_Caption[];
extern char Button17_Caption[];
extern char Button18_Caption[];
extern char Button19_Caption[];
extern char Button20_Caption[];
extern char Button21_Caption[];
extern char Button22_Caption[];
extern char Button23_Caption[];
extern char Button24_Caption[];
extern char Button25_Caption[];
extern char Button26_Caption[];
extern char Button27_Caption[];
extern char Button28_Caption[];
extern char Button29_Caption[];
extern char Label24_Caption[];
extern char Label25_Caption[];
extern char Label54_Caption[];
extern char Label55_Caption[];
extern char Button33_Caption[];
extern char Button34_Caption[];
extern char Label62_Caption[];
extern char Label63_Caption[];
extern char Label64_Caption[];
extern char Label65_Caption[];
extern char Label66_Caption[];
extern char Label67_Caption[];
extern char Label104_Caption[];
extern char Label105_Caption[];
extern char Button35_Caption[];
extern char Button36_Caption[];
extern char Label56_Caption[];
extern char Label30_Caption[];
extern char Label57_Caption[];
extern char Label82_Caption[];
extern char Label83_Caption[];
extern char Label84_Caption[];
extern char Label85_Caption[];
extern char Label90_Caption[];
extern char Label91_Caption[];
extern char Label92_Caption[];
extern char Label93_Caption[];
extern char Label94_Caption[];
extern char Label99_Caption[];
extern char Label100_Caption[];
extern char Label79_Caption[];
extern char Label80_Caption[];
extern char Label81_Caption[];
extern char Label34_Caption[];
extern char Label44_Caption[];
extern char Label45_Caption[];
extern char Label71_Caption[];
extern char Label72_Caption[];
extern char Button48_Caption[];
extern char Button1_Caption[];
extern char Button2_Caption[];
extern char Button3_Caption[];
extern char Button4_Caption[];
extern char Button5_Caption[];
extern char Button6_Caption[];
extern char Button7_Caption[];
extern char Button8_Caption[];
extern char Button9_Caption[];
extern char Button10_Caption[];
extern char Button39_Caption[];
extern char Button40_Caption[];
extern char Button41_Caption[];
extern char Button42_Caption[];
extern char Button43_Caption[];
extern char Button44_Caption[];
extern char Button45_Caption[];
extern char Button46_Caption[];

/////////////////////////////////
// Event Descriptors 
extern TEvent Box2_OnUpOnClick;
extern TEvent Box1_OnUpOnClick;
extern TEvent Box35_OnUpOnClick;
extern TEvent Box12_OnUpOnClick;
extern TEvent Box21_OnUpOnClick;
extern TEvent Box20_OnUpOnClick;
extern TEvent Box13_OnUpOnClick;
extern TEvent Box7_OnUpOnClick;
extern TEvent Box5_OnUpOnClick;
extern TEvent Box3_OnUpOnClick;
extern TEvent Box31_OnUpOnClick;
extern TEvent Image4_OnUpOnClick;
extern TEvent Image37_OnUpOnClick;
extern TEvent Image36_OnUpOnClick;
extern TEvent Image35_OnUpOnClick;
extern TEvent Box28_OnUpOnClick;
extern TEvent Box40_OnUpOnClick;
extern TEvent Box39_OnUpOnClick;
extern TEvent Box38_OnUpOnClick;
extern TEvent Box37_OnUpOnClick;
extern TEvent Button30_OnUpOnClick;
extern TEvent CircleButton1_OnUpOnPress;
extern TEvent CircleButton2_OnUpOnPress;
extern TEvent CircleButton3_OnUpOnPress;
extern TEvent CircleButton4_OnUpOnPress;
extern TEvent Box55_OnUpOnClick;
extern TEvent Box53_OnUpOnClick;
extern TEvent Box52_OnUpOnClick;
extern TEvent Box51_OnUpOnClick;
extern TEvent Button31_OnUpOnClick;
extern TEvent CircleButton5_OnUpOnPress;
extern TEvent CircleButton6_OnUpOnPress;
extern TEvent CircleButton7_OnUpOnPress;
extern TEvent CircleButton8_OnUpOnPress;
extern TEvent Button38_OnUpOnClick;
extern TEvent Box24_OnUpOnClick;
extern TEvent Box76_OnUpOnClick;
extern TEvent Box77_OnUpOnClick;
extern TEvent Box78_OnUpOnClick;
extern TEvent Box25_OnUpOnClick;
extern TEvent Box10_OnUpOnClick;
extern TEvent Button12_OnUpOnClick;
extern TEvent Button13_OnUpOnClick;
extern TEvent Button14_OnUpOnClick;
extern TEvent Button15_OnUpOnClick;
extern TEvent Button16_OnUpOnClick;
extern TEvent Button17_OnUpOnClick;
extern TEvent Button18_OnUpOnClick;
extern TEvent Button19_OnUpOnClick;
extern TEvent Button20_OnUpOnClick;
extern TEvent Button21_OnUpOnClick;
extern TEvent Button22_OnUpOnClick;
extern TEvent Button23_OnUpOnClick;
extern TEvent Button24_OnUpOnClick;
extern TEvent Button25_OnUpOnClick;
extern TEvent Button26_OnUpOnClick;
extern TEvent Button27_OnUpOnClick;
extern TEvent Button28_OnUpOnClick;
extern TEvent Button34_OnUpOnClick;
extern TEvent Button36_OnUpOnClick;
extern TEvent Button48_OnUpOnClick;
extern TEvent Button1_OnUpOnClick;
extern TEvent Button2_OnUpOnClick;
extern TEvent Button3_OnUpOnClick;
extern TEvent Button4_OnUpOnClick;
extern TEvent Button5_OnUpOnClick;
extern TEvent Button6_OnUpOnClick;
extern TEvent Button7_OnUpOnClick;
extern TEvent Button8_OnUpOnClick;
extern TEvent Button9_OnUpOnClick;
extern TEvent Button10_OnUpOnClick;
extern TEvent Button39_OnUpOnClick;
extern TEvent Button40_OnUpOnClick;
extern TEvent Button41_OnUpOnClick;
extern TEvent Button42_OnUpOnClick;
extern TEvent Button43_OnUpOnClick;
extern TEvent Button44_OnUpOnClick;
extern TEvent Button46_OnUpOnClick;
/////////////////////////////////

void DrawScreenO(TScreen *aScreen, char aOptions);
void DrawScreen(TScreen *aScreen);
void DrawButton(TButton *AButton);
void DrawLabel(TLabel *ALabel);
void DrawImage(TImage *AImage);
void DrawCircleButton(TCircleButton *ACircleButton);
void DrawBox(TBox *ABox);
void DrawCheckBox(TCheckBox *ACheckBox);
void ProcessVTFTStack();
void InitVTFTStack();

#endif