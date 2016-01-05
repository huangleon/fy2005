inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ºÍãÙºÓ");
        set("long", @LONG
´©¹ıÉ³Ä®£¬±ãµ½ÁËÈû±±Ö®µØ¡£ºÍãÙºÓ¹ö¹öµÄºÓË®£¬ÔÚÁùÔÂµÄ²ĞÑôÏÂ·¢×Å¹â¡£µ½
ÁËÉÏÓÎ£¬ºÓË®Ë«·Ö£¬Î÷ÃæµÄÒ»Ö§±ãÊÇÓñÁú¹şÊ²ºÓ£¬Ë®Á÷´¦µØÊÆ¸ü¼ûÆéá«ÏÕ¾ş£¬¼¤Æğ
ÁË±¼ÌÚµÄÀË»¨¡£ºÍãÙºÓµÄÄÏ²àÊÇ[33mÌ«Æ½Õò[32m£¬Ô­ÏÈÖ»ÊÇ¸öæäÕ¾£¬Ğª½ÅµÄÈË¶àÁË£¬½¥½¥¾Í
¿ªÆğÁË¼¸¼ÒµêÆÌ¡£ºÓ±±²àÍ¨Ïò[33máÔÔÀËÂ[32m£¬ÈËÑÌº±ÖÁ£¬¶àÓĞÉ½Ôô³öÃ»¡£
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"kunlun2",
		"southeast" : __DIR__"yangguan2",
		"southwest": AREA_TAIPING"mroad1",
		"north":	__DIR__"qingtongxia",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",-500);
        set("coor/y",500);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
