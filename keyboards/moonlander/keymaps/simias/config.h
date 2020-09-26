#pragma once

#define PERMISSIVE_HOLD

#define GB_BOOTROM H__NOTE(_C7), M__NOTE(_C8, 160)

#ifdef AUDIO_ENABLE
# define STARTUP_SONG SONG(GB_BOOTROM)
#endif

/* This breaks the scroll lock toggle shenanigans */
#undef ORYX_CONFIGURATOR
