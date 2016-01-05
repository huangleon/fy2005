// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "ð©ÔÂ¹¬");
        set("long", @LONG
×ªµ½·åÉÏ£¬·½Öª´Ë´¦±ðÓÐÒìÈ¤£¬¾°É«²»±È´ÓÇ°¡£Ö»¼ûÊý×ùÐüÀ¸·ÉºçËÆºá¿ç
ÄÏ±±£¬½«ÏàË¼Ò»ÏßµÄÉ½¶¥¾¡ÊýÏàÁ¬£¬ÀÈÍâÉ½·çÁÏÇÍ£¬ÔÆÉúÎíÎè£¬Æ¾À¸¶øÍû£¬Ò»
ÂöÉ½Ë®¾¡ÈëÑÛÁ±¡£Ç°·½²»Ô¶´¦¾ÍÊÇÒ»¸öÐüÀÈÈë¿Ú£¬Ì§ÑÛ¿´È¥£¬Ö»¼ûÀÈÇ°Ê¯·»ÉÏ
¿Ì×ÅÊý¸ö´ó×Ö£º

¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡[1;37mð©¡¡¡¡¡¡¡¡ÔÂ¡¡¡¡¡¡¡¡¡¡¹¬[0;32m

LONG
NOR
        );
	set("objects", ([
//		__DIR__"obj/rock4" : 1,
	]));
	set("item_desc", ([
//		"Ê¯·»": (: look_stone :),
	]) );
	set("exits",([
  		"northdown" : __DIR__"shipai",
  		"east" : __DIR__"cansan",
  		"west" : __DIR__"zoulang",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",20);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
}

string look_stone()
{
	object me = this_player();
	tell_object(me,"Ê¯·»±³Ãæµñ×ÅÒ»ÐÐÐ¡×Ö£º\n³¢²ØÌÓÇéì¶ÀÈÏÂ£¬²»ÈÕÈ´×Ù¼£È«ÎÞ£®£®ÌìÓûÁîÎÒ¶ÏÇéÒ®£¿\n");
	me->set_temp("annie/xiangsi_master",1);
	return " ";
}

/*

¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨X¨Y
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦©¦©¦
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨^¨k¨k¨k¨_

¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 08.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/


