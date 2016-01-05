inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "´óÑ©É½");
        set("long", @LONG
´óÑ©É½µÄÃû×Ö½Ğ¡°ÄîÇà¹±¸ÂÈÕËÉ¹±²¼¡±£¬ÓÉÈı×ùÍêÈ«¸ô¿ª£¬µ«Ïà¾à²»Ô¶£¬³ÊÆ·
×ÖĞÎÅÅÁĞµÄÑ©·å×é³É¡£±±·å[37mÏÉÄËÈÕ[32m£¬ÄÏ·å[37mÑëÂõÓÂ[32m£¬¶«·å[37mÏÄÅµ¶à¼ª[32m¡£Èı×ùÑ©·å½à°×£¬
ÇÍ°Î£¬ËÆÀû½£Ö±²åÔÆÏö¡£¹ÊÀÏÏà´«£¬×ªÈı´ÎÈıâïÖ÷Ñ©É½£¬ÄÜÏû³ıÍÀÉ±°ËÌõÈËÂíµÄ×ï
¶ñ¡£×ªÊ®Îå´ÎÉñÉ½½ÅÏÂµÄ³å¹ÅËÂ¾ÍÏàµ±ÓÚÄîÒ»ÒÚÂïÄØµÄ¹¦µÂ¡£
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"mount1",
		"south":  __DIR__"mount2",
		"east":  __DIR__"mount3",
		"westdown": __DIR__"diyugu2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1700);
        set("coor/y",620);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
