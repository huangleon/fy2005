inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "¾ÞÑÒ");
        set("long", @LONG
³àÍÁºÓµÄÄÏ°¶ÓÐÒ»¿é¾Þ´óµÄÑÒÊ¯£¬ÈçÓ¥Õ¹³á¸©î«ºÓË®£¬²ØÓï³ÆÎª¡°Öª»ðÔúÀÉ¡±£¬
ÒâÎª¡°´óºÈÒ»Éù£¬µ²²»×¡ÁË¡±£¬ÊÇ´«ËµÖÐ¹±¸ÂÈÕËÉ¹±µÄÃÅÉñ¡£ºÓ±ßÓÃÆ¬Ê¯¶Ñ³ÉµÄÂï
ÄØ¶Ñ±È±È½ÔÊÇ£¬Ã¿ÄêÈø¸Â´ïÍÞ£¬µ±µØÈË¶¼ÒªÈÆÊ¯×ªÉ½£¬ÔÚºÓÀïãåÔ¡¸üÒÂ¡£ºÓµÄ±±°¶
·¿ÎÝÁÛ´ÎèÎ±È£¬ÊÇÒ»¸ö[33m±ßÔ¶Ð¡³Ç[32m¡£ºÓµÄÄÏ°¶Ñ­É½ÊÆ¶øÉÏ£¬ÊÇÖøÃûµÄº£×ÓÉ½¡£
LONG
        );
        set("exits", ([ 
		"southup":  __DIR__"echu",
	]));
	set("item_desc", ([
		"river":	"Ë®Á÷ÍÄ¼±£¬µ«ÊÇ²»Éî£¬Äã¿ÉÒÔÊÔ×ÅÉæ¹ýÈ¥(wade)¡£\n",
		"³àÍÁºÓ":	"Ë®Á÷ÍÄ¼±£¬µ«ÊÇ²»Éî£¬Äã¿ÉÒÔÊÔ×ÅÉæ¹ýÈ¥(wade)¡£\n",
	]) );
	
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2020);
        set("coor/y",640);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


void init() {
	add_action("do_wade","wade");
	remove_call_out("greeting");
	call_out("greeting", 4, this_player());
}


void greeting(object me)
{
	object ob;
	ob=this_object();
	if( !me || environment(me) != this_object() ) return;
	message_vision(CYN"\n\n¶Ô°¶ÎûÎû¹þ¹þµØ´«À´Ï´ÒÂ¸¾ÈËÃÇµÄËµÐ¦Éù£¬Ëæ×ÅºÓË®»©»©µØÆ®ÏòÔ¶·½¡£¡£¡£\n\n"NOR,me);
	
}

int do_wade(string arg) {
	
	object me;
	
	me=this_player();
	if (!arg || arg == "Ð¡ºÓ" || arg== "river") {
		if (me->query_temp("zangbei/wade_2"))
			return notify_fail("ÄãÒÑ¾­ÔÚºÓË®ÖÐÑëÁË¡£\n");
		message_vision("$NÍÑÏÂÑ¥×Ó×ßÈëºÓË®ÖÐ£¬¼èÄÑµØÏò¶Ô°¶ÉæÈ¥¡£\n\n",me);
		call_out("pass_river",6,me);
		me->start_busy(3);
		me->set_temp("zangbei/wade_2",1);
		return 1;
	}
	tell_object(me,"ÄãÒª×öÊ²Ã´£¿\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"bank");
	if (!objectp(room)) room=load_object(__DIR__"bank");
	tell_object(me,HIG"ÄãÖÕÓÚ×ßµ½ÁË³àÍÁºÓµÄ¶Ô°¶¡£\n"NOR);
	message("vision",HIG""+me->name()+"Ë®ÁÜÁÜµØ´ÓºÓÀï×ßÁËÉÏÀ´¡£\n"NOR,room);
	me->move(room);
	me->delete_temp("zangbei/wade_2");
	return 1;
}