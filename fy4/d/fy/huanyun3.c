#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", CYN"»·ÔÆµÀ"NOR);
    set("long", @LONG
»·ÔÆµÀÒÔÄÏÔÆ½ÖÎªÖĞÖá£¬¹á´©Õû¸ö·çÔÆÄÏ³Ç£¬¶«²àÊÇ½­ºşÈË³£È¥µÄ¿ÍÕ»ÌúÆÌ¼À
½£Í¤µÈ£¬Î÷²àÔòÊÇµÆºì¾ÆÂÌµÄÑÌ»¨Ö®µØ£¬ÈÈÄÖ·Ç·²¡£ËäÈ»À´À´ÍùÍùµÄºÃ¶à¶¼ÊÇ³õ´³
½­ºşµÄÄĞÄĞÅ®Å®£¬Ë­¸ÒËµ²»»áÓĞ½«À´µÄ½«ÏàÍõºî£¬¸ßÉ®ÆæÏÀ¡£Õâ¶ùÏòÎ÷±ãÊÇÎÅÃû´ó
½­ÄÏ±±µÄ[33mÇ§½ğÂ¥[32mÁË¡£´ºÏüÒ»¿ÌÖµÇ§½ğ£¬ÄãÊÇ·ñÏëÈ¥Ïú»êÆ¬¿Ì£¿
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"huanyun2",
	"south" : __DIR__"huanyun21",
	"west" : __DIR__"qianjin",
	"east" : __DIR__"mudan",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",-60);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}

