#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", CYN"»·ÔÆµÀ"NOR);
    set("long", @LONG
»·ÔÆµÀÒÔÄÏÔÆ½ÖÎªÖĞÖá£¬¹á´©Õû¸ö·çÔÆÄÏ³Ç£¬¶«²àÊÇ½­ºşÈË³£È¥µÄ¿ÍÕ»ÌúÆÌ¼À
½£Í¤µÈ£¬Î÷²àÔòÊÇµÆºì¾ÆÂÌµÄÑÌ»¨Ö®µØ£¬ÈÈÄÖ·Ç·²¡£ËäÈ»À´À´ÍùÍùµÄºÃ¶à¶¼ÊÇ³õ´³
½­ºşµÄÄĞÄĞÅ®Å®£¬Ë­¸ÒËµ²»»áÓĞ½«À´µÄ½«ÏàÍõºî£¬¸ßÉ®ÆæÏÀ¡£Â·¶«²àÊÇ[1;31m·ïÇó»Ë¿ÍÕ»[0;32m£¬
±ğ¿´ËüĞ¡£¬³õÈë·çÔÆµÄ¶¼ÊÇ´ÓÕâ¶ùÆğ²½Ì¤Èë½­ºş¡£Î÷²à²»ÖªÊÇÊ²Ã´È¥´¦£¬Ö»ÊÇ³£³£
¿ÉÒÔÌıµ½Ï²ÇìµÄÑÌ»¨±¬ÖñÖ®Éù¡£
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"huanyun5",
	"east" :__DIR__"fqkhotel",
	"west" :__DIR__"marry_room",
	"south" :__DIR__"huanyun8",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",60);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}

