#include <room.h>
inherit ROOM;
#include "/questnpc/lovestory1/event_place.h"

void create()
{
  set("short","Îèö§Ì¨");
  set("long",@LONG
ÕâÀï±ãÊÇ¼ÃÄÏ³ÇÃ¿Äê¼Àìë¿×Ê¥ÈËµÄ¼ÀÌ¨£¬Ì¨ÉÏÓÐÁ½¿é[33mÊ¯±®[32m£¬Ò»¿é¿Ì×ÅÎèö§Ì¨£¬
ÁíÒ»¿é¿Ì×Å¡°Ê¥ÏÍÀÖÈ¤¡±£¬¾ÝËµµ±Äê¿××ÓµÄÃÅÉú·®³ÙËæ¿××ÓÓÎÓÚÎèö§Ì¨ÏÂ£¬±ãÇó½Ì
¡°³çµÂ¡¢ÐÞí«¡¢±æ»ó¡±Ö®µÀ£¬¿××ÓÒ»Ò»½â´ð£¬Ëì³É¼Ñ»°¡£°ÙÄê²×É££¬¾­ºóÈË¶à´ÎÐÞ
ÝÝ£¬Îèö§Ì¨Àú¾ÃÈçÐÂ£¬¸ß¸ßËÊÁ¢¡£¶«Î÷Á½²à£¬½ÔÊÇÐ©ÈÈÄÖµÄºÀÕ¬¡£
LONG
  );
  	set("exits",([
         "northdown":__DIR__"street2",
         "southdown":__DIR__"street4",
//         "eastdown" : __DIR__"pighome",
//         "westdown":__DIR__"qiyuan1",
               ]));
        set("objects", ([
        	BOOKS"chant_30" : 1,
                        ]) );
    	set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",60);
	set("coor/z",20);
	setup();


}


int valid_enter(object me)
{

	if(me->query("lovestory1"))
		add_trigger_count(me);
	return 1;
}
