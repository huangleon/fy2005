// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Ç§·ğµî");
        set("long", @LONG
ÓÖÃûÀ¥Â¬¸ó£¬µñÊÎÏàµ±¾«ÖÂ£¬Ã÷¼äĞü¶îÓĞ¡°Î÷·½Ê¥ÈË¡±µÄÊúØÒ£¬µîÇ°ÔÂÌ¨¿í³¨£¬
Ê¯À¸¾«ÃÀ¡£µîÕıÖĞµÄÉñíèÀï£¬¹©·îÀ¥Â¬Í­·ğ£¬×øÓÚ¶à²ãÁ«»¨×ùÉÏ£¬µî¶«ÓĞ°×ÓñÄÏÎŞ
°¢ÃÖÍÓ·ğÒ»×ğ£¬ËÄÖÜ±Ú»­¾«ÃÀ£¬ÓÈÆäÒıÈË×¢Ä¿µÄÊÇµØÉÏµÄËÄÊ®°Ë¸ö°¼ÏİµÄ[33m½Å¿Ó[32m¡£
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"neimen",
  "southdown" : __DIR__"lishi",
  "east" : __DIR__"baiyi",
  "west" : __DIR__"dizang",
]));
        set("objects", ([
                BOOKS"dodge_50" : 1,
       ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",20);
	setup();

}
