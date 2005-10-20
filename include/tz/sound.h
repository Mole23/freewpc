
#ifndef _MACH_SOUND_H
#define _MACH_SOUND_H

#define SND_DEAD_END_CRASH_DAMAGE 0x1B 
#define SND_TEST_BACKWARD 0x50 
#define SND_TEST_FORWARD 0x51 
#define SND_TEST_CANCEL 0x52 
#define SND_TEST_CONFIRM 0x53 
#define SND_TEST_ALERT 0x54 
#define SND_TEST_HS_RESET 0x56 
#define SND_TEST_ENTER 0x57 
#define SND_TEST_ESCAPE 0x58 
#define SND_TEST_SCROLL 0x59 
#define SND_GET_VERSION 0x5F 
#define SND_VOLUME_CHANGE 0x79 
#define SND_START_EXTENDED 0x7A 
#define SND_TILT_1 0x7D 
#define SND_STOP_MUSIC 0x7E 
#define SND_CAMERA_PICTURE_EJECT_2 0x81 
#define SND_SLINGSHOT 0x84
#define SND_CLOCK_WIND_1 0x86 
#define SND_CLOCK_WIND_2 0x87 
#define SND_CLOCK_WIND_3 0x88 
#define SND_NO_CREDITS_2 0x8A 
#define SND_CUCKOO 0x8D 
#define SND_POWERFIELD_HIT_2 0x8F 
#define SND_POWERFIELD_HIT_3 0x90 
#define SND_POWERFIELD_HIT_1 0x91 
#define SND_POWERFIELD_HIT_6 0x93 
#define SND_POWERFIELD_HIT_5 0x94 
#define SND_ROBOT_FLICKS_GUN 0x95 
#define SND_GLASS_BREAKS 0x96
#define SND_SHOOTER_PULL 0x97
#define SND_SLOT_PULL 0x9E
#define SND_SLOT_REEL 0x9F
#define SND_CAMERA_PICTURE_EJECT_1 0xA1 
#define SND_JACKPOT_INCREASED_3 0xA7 
#define SND_JACKPOT_INCREASED_1 0xA8 
#define SND_JACKPOT_INCREASED_2 0xA9 
#define SND_PLAYER_PIANO_UNUSED 0xAD
#define SND_HORN1 0xAE 
#define SND_HORN2 0xB0 
#define SND_HORN3 0xB1 
#define SND_HORN4 0xB2 
#define SND_INSIDE_LEFT_INLANE 0xB5
#define SND_DRAIN 0xB6
#define SND_SPIRAL_EB_LIT 0xB7 
#define SND_PIANO_MULTIBALL_BUILDUP 0xB8 
#define SND_LEFT_RAMP_ENTER 0xBA 
#define SND_LEFT_RAMP_MADE 0xBB 
#define SND_CLOCK_BELL 0xBD
#define SND_ODD_CHANGE_BEGIN 0xBE 
#define SND_JET_BUMPER_ADDED 0xBF 
#define SND_HITCHHIKER_COUNT 0xC0
#define SND_TWILIGHT_ZONE_SOUND 0xC2 
#define SND_SPIRAL_AWARDED 0xC3
#define SND_PARTIAL_CREDIT_POSTED 0xC4 
#define SND_CAMERA_AWARD_SHOWN 0xC7
#define SND_NEXT_CAMERA_AWARD_SHOWN 0xC8
#define SND_LOCK_KICKOUT 0xCF 
#define SND_SLOT_KICKOUT_1 0xD0 
#define SND_SLOT_KICKOUT_2 0xD1 
#define SND_TILT_WARNING 0xD2
#define SND_TILT 0xD3 
#define SND_SLAM_TILT 0xD4
#define SND_SKILL_SHOT_RED 0xD5 
#define SND_SKILL_SHOT_ORANGE 0xD6 
#define SND_SKILL_SHOT_YELLOW 0xD7 
#define SND_SKILL_SHOT_MISSED 0xD8 
#define SND_STATIC 0xDD 
#define SND_NO_CREDITS 0xE0 
#define SND_SLOT_PAYOUT 0xE1 
#define SND_TSM_HIT_1 0xE2 
#define SND_TSM_HIT_2 0xE3 
#define SND_TSM_HIT_3 0xE4 
#define SND_SUPER_SKILL_SHOT_RED 0xE5 
#define SND_SUPER_SKILL_SHOT_ORANGE 0xE6 
#define SND_SUPER_SKILL_SHOT_YELLOW 0xE7 
#define SND_SUPER_SKILL_SHOT_MISSED 0xE8 
#define SND_RAMP_ENTERS_POWERFIELD 0xE9 
#define SND_LIGHT_SLOT_TIMED 0xEA 
#define SND_LOOP_ENTER 0xEB
#define SND_SPIRAL_SAME_SIDE_EXIT 0xEC 
#define SND_ROCKET_KICK_REVVING 0xED 
#define SND_ROBOT_AWARD 0xEF
#define SND_LOCK_KICKOUT_2 0xF0 
#define SND_JET_BUMPER_ADDED_2 0xF1
#define SND_REPLAY_AWARDED 0xF2 
#define SND_JACKPOT_BACKGROUND 0xF7
#define SND_RIGHT_RAMP_DEFAULT_ENTER 0xFA 
#define SND_PIANO_ENTRY_TUNE 0xFB 
#define SND_LOAD_GUMBALL_NOW 0xFC 
#define SND_HEEHEE 0x101
#define SND_THUD 0x102
#define SND_ADDAMS_FASTLOCK_STARTED 0x103
#define SND_CLOCK_CHAOS_HIT1 0x104
#define SND_CLOCK_CHAOS_END_BOOM 0x107
#define SND_CLOCK_HIT_RECOVERY_1 0x108
#define SND_GREED_ROUND_BOOM 0x109
#define SND_TOWN_SQUARE_AWARD 0x10A
#define SND_RUDY_BLEH 0x10B
#define SND_HITCHHIKER_DRIVE_BY 0x10C
#define SND_EXPLOSION_1 0x10D
#define SND_EXPLOSION_2 0x10E
#define SND_EXPLOSION_3 0x10F
#define SND_HERES_YOUR_EB 0x110
#define SND_CLOCK_GONG 0x111
#define SND_RABBLE_RABBLE 0x112
#define SND_IM_TALKING_TINA 0x113
#define SND_GUMBALL_LOADED 0x114
#define SND_DEAD_END_SCREECH 0x115
#define SND_FIST_BOOM1 0x119
#define SND_FIST_BOOM2 0x11A
#define SND_ROCKET_KICK_DONE 0x11B
#define SND_TOWN_SQUARE_SCREAM_1 0x11C
#define SND_TOWN_SQUARE_SCREAM_2 0x11D
#define SND_TOWN_SQUARE_SCREAM_3 0x11E
#define SND_HAHA_POWERFIELD_EXIT 0x120
#define SND_POWER_DIES 0x121
#define SND_FEEL_LUCKY 0x122
#define SND_POWER_GRUNT_2 0x123
#define SND_POWER_HUH_4 0x124
#define SND_POWER_HUH_3 0x125
#define SND_MISS_AND_YOU_LOSE_IT_ALL 0x126
#define SND_NOOOOOOOO 0x127
#define SND_ITS_NOT_YOURS 0x128
#define SND_POWERBALL_QUOTE 0x129
#define SND_PUT_IT_BACK 0x12A
#define SND_ARE_YOU_READY_TO_BATTLE 0x12B
#define SND_STOP_IT 0x12C
#define SND_TOO_HOT_TO_HANDLE 0x12D
#define SND_I_WANT_IT_BACK 0x12E
#define SND_BE_CAREFUL 0x132
#define SND_BEYOND_THIS_DOOR_SIGHT 0x133
#define SND_BEYOND_THIS_DOOR_SOUND 0x134
#define SND_BEYOND_THIS_DOOR_MIND 0x135
#define SND_THIS_CLOCK_IS_WORTH_MILLIONS 0x137
#define SND_YOUVE_JUST_CROSSED_OVER 0x138
#define SND_FEEL_THE_POWER 0x13D
#define SND_SEE_WHAT_GREED 0x13E
#define SND_THERE_IS_MADNESS 0x13F
#define SND_PLAYER_ONE 0x140
#define SND_PLAYER_TWO 0x141
#define SND_PLAYER_THREE 0x142
#define SND_PLAYER_FOUR 0x143
#define SND_NOTE_THE_HITCHHIKER 0x144
#define SND_THIS_SHOT_REQUIRES_SKILL_DUP 0x145
#define SND_SPIRAL_AWAITS_YOU 0x146
#define SND_SUPER_SKILL 0x147
#define SND_TEN_MILLION_POINTS 0x148
#define SND_NOT_AN_ORDINARY_DAY 0x14A
#define SND_IN_AN_ORDINARY_PLACE 0x14B
#define SND_NOT_AN_ORDINARY_GAME 0x14C
#define SND_OR_AN_ORDINARY_PLAYER 0x14D
#define SND_THE_STAKES_ARE_HIGHER 0x14E
#define SND_THIS_IS_NO_ORDINARY_GUMBALL 0x14F
#define SND_TIME_IS_A_ONEWAY_STREET 0x150
#define SND_YOU_UNLOCK_THIS_DOOR 0x151
#define SND_AN_OPPORTUNITY_AWAITS 0x153
#define SND_POWER_GRUNT_1 0x154
#define SND_POWER_GROWL 0x155
#define SND_POWER_HUH_6 0x156
#define SND_SPIRAL_BREAKTHRU 0x159
#define SND_CAREFUL 0x15A
#define SND_DONT_TOUCH_DOOR_1 0x15C
#define SND_DONT_TOUCH_DOOR_2 0x15D
#define SND_GET_THE_EXTRA_BALL 0x15E
#define SND_FASTER 0x15F
#define SND_FIVE 0x160
#define SND_LOOK_TO_THE_FUTURE 0x161
#define SND_LUCKY 0x162
#define SND_OH_NO 0x163
#define SND_ONE 0x164
#define SND_PUT_IT_BACK_2 0x166
#define SND_THE_ROBOTS_CAN_HELP 0x167
#define SND_ENTER_THE_SPIRAL 0x168
#define SND_THREE 0x169
#define SND_TWO 0x16A
#define SND_YOU_WANT_MORE 0x16B
#define SND_YES 0x16C
#define SND_YOU_CAN_DO_IT 0x16D
#define SND_MORE 0x16E
#define SND_JACKPOT 0x16F
#define SND_FOUR 0x170
#define SND_DONT_TOUCH_THE_DOOR_AD_INF 0x171
#define SND_OOH_GIMME_SHELTER 0x172
#define SND_RETURN_TO_YOUR_HOMES 0x173
#define SND_DO_NOT_PANIC 0x174
#define SND_HEY_ITS_ONLY_PINBALL 0x175
#define SND_QUIT_PLAYING_WITH_THE_CLOCK 0x176
#define SND_GREEEED 0x177
#define SND_COUSIN_IT 0x178
#define SND_ROBOT_WALK 0x17E
#define SND_ROBOT_WALK_2 0x17F
#define SND_GOING_MY_WAY 0x180
#define SND_WELCOME_RACE_FANS 0x181
#define SND_GO_FOR_THE_HILL 0x182
#define SND_ITS_SUNNY_DRIVE_TIME 0x183
#define SND_PICTURE_THE_FUTURE 0x184
#define SND_BIG_RISK_BIG_REWARD 0x185
#define SND_THINGS_ARE_NOT_WHAT 0x186
#define SND_MOST_UNUSUAL_CAMERA 0x187
#define SND_ITS_TIME_TO_TUNE_IN 0x188
#define SND_ONE_OF_LIFES_PAYOFFS 0x18A
#define SND_NEVER_UNDERESTIMATE_POWER 0x18B
#define SND_JUST_TAKEN_A_DETOUR 0x18C
#define SND_SLOW_START_4 0x18D
#define SND_WITH_THE_DEVIL 0x18F
#define SND_SEE_WHAT_GREED_DUP 0x190
#define SND_YOU_HAVE_COME_TO_THE_END 0x194
#define SND_SURVIVAL_IS_EVERYTHING 0x195
#define SND_KACHING 0x196
#define SND_SUPER_ROBOT_2 0x197
#define SND_SUPER_SKILL_INTRO 0x198
#define SND_HORN_1 0x199
#define SND_HORN_2 0x19A
#define SND_HORN_3 0x19B
#define SND_SUPER_SKILL_AWARD 0x19D
#define SND_GUMBALL_ENTER 0x19E
#define SND_GUMBALL_COMBO 0x19F
#define SND_GUMBALL_LOADED_1 0x1A0
#define SND_FAST_LOCK_STARTED 0x1A1
#define SND_POWER_GRUNT_1_DUP 0x1A2
#define SND_UNKNOWN_LIGHTNING 0x1A3

#endif /* _MACH_SOUND_H */
