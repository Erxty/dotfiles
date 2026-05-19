#pragma once

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=8" };
static const char dmenufont[]       = "monospace:size=10";

static MAYBE_CONST char normbgcolor[]           = "#313131";
static MAYBE_CONST char normbordercolor[]       = "#313131";
static MAYBE_CONST char normfgcolor[]           = "#d1d1d1";
static MAYBE_CONST char selfgcolor[]            = "#d1d1d1";
static MAYBE_CONST char selbordercolor[]        = "#313131";
static MAYBE_CONST char selbgcolor[]            = "#313131";
static MAYBE_CONST char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

#define CENTER_NEW_FLOATING_WINDOWS 1 // so, basically, it does what it says. (make 0 to turn off)
#define NEW_FLOATING_WINDOWS_APPEAR_UNDER_CURSOR 1 // so, basically, it does what it says. (make 0 to turn off)

#if GAPS
static const unsigned int gappx = 5;
#endif

#if BAR_HEIGHT
static const int user_bh = 0;
#endif

#if BAR_PADDING
static const int vertpad = 0;       /* vertical padding of bar */
static const int sidepad = 20;       /* horizontal padding of bar */
#endif

/* tagging */
static const char *tags[] = { "ένα", "δύο", "τρία", "τέσσερα", "πέντε" };

#if OCCUPIED_TAGS_DECORATION
static const char *occupiedtags[] = { "/ένα", "/δύο", "/τρία", "/τέσσερα", "/πέντε" };
#endif

#if INFINITE_TAGS
#define MOVE_CANVAS_STEP 120 /* Defines how many pixel will be jumped when using movecanvas function */
#endif

#if INFINITE_TAGS && IT_SHOW_COORDINATES_IN_BAR
#define COORDINATES_DIVISOR 10 /* Defines by what number coordinates on the bar will be divided, can be used for making numbers smaller which makes navigation easier */
#endif

#if MOVE_RESIZE_WITH_KEYBOARD
#define MOVE_WITH_KEYBOARD_STEP 50 /* Defines by how many pixels windows will be resized with keyboard */
#define RESIZE_WITH_KEYBOARD_STEP 50 /* Defines by how many pixels windows will be resized with keyboard */
#endif

#if AUTOSTART
/* vxwm will execute this on startup (can be skipped with -ignoreautostart vxwm flag). */

static const char *const autostart[] = {
	"picom &",
	"setxkbmap fi",
	"xwallpaper --zoom Pictures/wallpapers/dark-turqoise.jpeg &",
	"xrandr --newmode \"1152x864@100\" 143.47 1152 1232 1360 1568 864 865 868 915",
	"sleep 1 && xrandr --addmode DP-1 1152x864@100",
	"sleep 2 && xrandr --output DP-1 --mode 1152x864@100 --scale 1.2",
	"dunst &",
	"pipewire &",
	"xrdb ~/.Xresources &",
	NULL /* must end with NULL */
};
#endif

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
#if LOCK_MOVE_RESIZE_REFRESH_RATE
static const int refreshrate = 100;  /* refresh rate (per second) for client move/resize, set it to your monitor refresh rate or double of that*/
#endif //LOCK_MOVE_RESIZE_REFRESH_RATE
static const Layout layouts[] = {
	/* symbol     arrange function */
  { "][",      NULL },    /* no layout function means floating behavior */
	{ "[]",      tile },    /* first entry is default */
	{ "0",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTERNATE_MODKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ Mod1Mask,                     KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]  = { "dmenu_riced", NULL };
static const char *terminal[]  = { "urxvt", NULL };
static const char *explorer[]  = { "dolphin", NULL };
static const char *browser[]   = { "helium", NULL };
static const char *editor[]    = { "kate", NULL };
static const char *ssarea[]    = { "flameshot", "gui", NULL};
static const char *ssfull[]    = { "flameshot", "full", NULL};
static const char *powercmd[]  = { "dmenu_power", NULL};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_q,      spawn,          {.v = terminal } },
	{ MODKEY,						XK_f,	   spawn,	   {.v = browser } },
	{ MODKEY,						XK_e,	   spawn,	   {.v = explorer } },
	{ MODKEY,						XK_s,	   spawn,	   {.v = editor } },
	{ MODKEY|ShiftMask,				XK_m,	   spawn,	   {.v = powercmd} },

	{ MODKEY|ShiftMask,				XK_s,	   spawn,	   {.v = ssarea } },
	{ MODKEY|ShiftMask,				XK_a,	   spawn,	   {.v = ssfull } },

	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ ALTERNATE_MODKEY,             XK_Tab,    focusstack,     {.i = +1 } },
	{ ALTERNATE_MODKEY|ShiftMask,   XK_Tab,    focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_k,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_l,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_i,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_o,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_0,      view,           {0} },
	{ MODKEY,                       XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} }, //default toggle floating bind.
	{ MODKEY,                       XK_Tab,    view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_y,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_u,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_y,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_u,      tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
#if XRDB
  { MODKEY,                         XK_F5,     xrdb,           {.v = NULL } },
#endif
#if FULLSCREEN
  { ALTERNATE_MODKEY,               XK_f,      togglefullscr,  {0} },
#endif
#if ENHANCED_TOGGLE_FLOATING
  { MODKEY|ShiftMask,               XK_q,      enhancedtogglefloating, {0} }, //enhanced toggle floating bind.
#endif
#if GAPS
  { MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
  { MODKEY,                       XK_plus,   setgaps,        {.i = +1 } },
  { MODKEY|ShiftMask,             XK_plus,   setgaps,        {.i = 0  } },
#endif
#if MOVE_RESIZE_WITH_KEYBOARD
  { MODKEY,					              XK_Down,	moveresize,		{.v = (int []){ 0, MOVE_WITH_KEYBOARD_STEP, 0, 0 }}}, // Move window to down
  { MODKEY,					              XK_Up,		moveresize,		{.v = (int []){ 0, -MOVE_WITH_KEYBOARD_STEP, 0, 0 }}}, // Move window to up
  { MODKEY,					              XK_Right,	moveresize,		{.v = (int []){ MOVE_WITH_KEYBOARD_STEP, 0, 0, 0 }}}, // Move window to right
  { MODKEY,					              XK_Left,	moveresize,		{.v = (int []){ -MOVE_WITH_KEYBOARD_STEP, 0, 0, 0 }}}, // Move window to left
  { ALTERNATE_MODKEY|ControlMask,	      XK_Down,	moveresize,		{.v = (int []){ 0, 0, 0, RESIZE_WITH_KEYBOARD_STEP }}}, // Resize window
  { ALTERNATE_MODKEY|ControlMask,		  XK_Up,		moveresize,		{.v = (int []){ 0, 0, 0, -RESIZE_WITH_KEYBOARD_STEP }}}, // Resize window
  { ALTERNATE_MODKEY|ControlMask,	      XK_Right,	moveresize,		{.v = (int []){ 0, 0, RESIZE_WITH_KEYBOARD_STEP, 0 }}}, // Resize window
  { ALTERNATE_MODKEY|ControlMask,	      XK_Left,	moveresize,		{.v = (int []){ 0, 0, -RESIZE_WITH_KEYBOARD_STEP, 0 }}}, // Resize window
#endif
#if INFINITE_TAGS
  { MODKEY,                       XK_r,      homecanvas,       {0} }, // Return to x:0, y:0 position
  { MODKEY|ShiftMask,             XK_Left,   movecanvas,       {.i = 0} }, // Move your position to left
  { MODKEY|ShiftMask,             XK_Right,  movecanvas,       {.i = 1} }, // Move your position to right
  { MODKEY|ShiftMask,             XK_Up,     movecanvas,       {.i = 2} }, // Move your position up
  { MODKEY|ShiftMask ,           XK_Down,   movecanvas,       {.i = 3} }, // Move your position down
  { ALTERNATE_MODKEY,             XK_c,      centerwindow,     {0} },
  { MODKEY|ControlMask,           XK_z,      pinwindow,        {0} },
#endif
#if DIRECTIONAL_FOCUS
	{ ALTERNATE_MODKEY,             XK_Left,   focusdir,       {.i = 0 } }, // left
	{ ALTERNATE_MODKEY,             XK_Right,  focusdir,       {.i = 1 } }, // right
	{ ALTERNATE_MODKEY,             XK_Up,     focusdir,       {.i = 2 } }, // up
	{ ALTERNATE_MODKEY,             XK_Down,   focusdir,       {.i = 3 } }, // down
#endif
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
#if INFINITE_TAGS
  { ClkRootWin,             MODKEY,            Button1,        movecanvasmouse,     {.f = 1.5 } },
  { ClkClientWin,    		MODKEY|ShiftMask,  Button1,        movecanvasmouse,     {.f = 1.5 } },
  /* .f = 1 is moving multiplier, for example if set to 0.5, canvas will move 2 times slower, if set to 2, canvas will move 2 times faster. 
     If you want inverted canvas move then set the value to a negative value. */
#endif
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = terminal } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

