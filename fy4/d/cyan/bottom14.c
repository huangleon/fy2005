// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{

	set("short", BLU"Ø¨¹Å»êá¦"NOR);
    set("long", @LONG
Ò»É²ÄÇ¼ä£¬Äã¾ÍÃ÷°×ÁËËÀµØ´æÔÚµÄÔ­Òò¡£ÓÐ¸ËÉî×ÏÉ«µÄ¾Þ´óÆìá¦²åÔÚÕâ
ÀïµÄÒ»·½¼ÀÌ³ÖÐÑë£¬Æìá¦ÉÏÓÃ¹Å×­Ãè»æ×Å[45m[1;37mÍöÕß²»Ï¢[2;37;0mËÄ¸ö´ó×Ö£¬ÖÜÎ§ÅÌÐý·ÉÎè
×ÅÎÞÊý°ëÃ÷°ë»ÞµÄ»êÁé£¬ÕûÃæ»êá¦ÕýÈçË®²¨°ãÆð·üµ´Ñú£¬ÏòÍâÉ¢³öÒ»ÖØÖØ¿Ý
Î®µòÁãµÄÆøÏ¢¡£
LONG
NOR
        );
	set("objects", ([
		__DIR__"npc/flag":1,
		__DIR__"obj/altar":1,
	]));
	set("no_fly",1);
	set("no_light",1);
	set("item_desc", ([

	"west":"É½ÒõÖÐ´¦´¦ÓÐÎí£¬ÄãÊ²Ã´Ò²·Ö±æ²»Çå³þ¡£\n",
	"east":"É½ÒõÖÐ´¦´¦ÓÐÎí£¬ÄãÊ²Ã´Ò²·Ö±æ²»Çå³þ¡£\n",
	"north":"É½ÒõÖÐ´¦´¦ÓÐÎí£¬ÄãÊ²Ã´Ò²·Ö±æ²»Çå³þ¡£\n",
	"south":"É½ÒõÖÐ´¦´¦ÓÐÎí£¬ÄãÊ²Ã´Ò²·Ö±æ²»Çå³þ¡£\n",

	]) );
	set("exits",([
  		"west" : __DIR__"bottom13",
	]) );

	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",-100);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;


	tell_object(me,CYN"Äã»ëÉí½ä±¸£¬Ð¡ÐÄÒíÒíµØÏòÎíÆøÖÐ×ßÈ¥£®£®£®\n"NOR);
	me->perform_busy(1);
	return ::valid_leave(who,dir);
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


