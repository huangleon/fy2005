#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
    set("short", "·çÔÆ¸ó");
    set("long", @LONG
·çÔÆ¸óµÄÖ÷ÈË¾ÍÊÇµ±ÄêÌìÏÂ´óÃû¶¦¶¦µÄĞ¡Àî·Éµ¶¡£ËäÈ»ÀîÌ½»¨ÒÑ¾­ÒşÍË¶àÊ±£¬
µ«ÊÇ»¹ÓĞ¿ÍÈËÄ½ÃûÀ´µ½´Ë¸ó£¬ÒÔÇóÒ»ÃæÖ®Ôµ¡£¸óÖĞ´óºì²¨Ë¹µØÌºÆÌµØ£¬¸»ÀöÌÃ»Ê¡£
ÖìºìµÄ´óÃÅÁ½²à¸÷¹ÒÒ»·ùÊ¯¿ÌµÄ¶ÔÁª¶ù£º
[33m
                	Ò»ÃÅÆß½øÊ¿
                	¸¸×ÓÈıÌ½»¨
[2;37;0m
LONG
    );
    set("valid_startroom", 1);
    set("item_desc", ([
//		"sign": (: look_sign :),
      ]) );

    set("exits", ([
	"west"    	: __DIR__"tiandoor",
	"up"		: __DIR__"fyyage",
      ]) );

    set("objects", ([
		__DIR__"npc/fywaiter" : 1,
      ]) );
    set("NONPC",1);
    set("coor/x",40);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fynorth");
    setup();

    // To "load" the board, don't ever "clone" a bulletin board.
    call_other( "/obj/board/common_fy", "???" );
}

