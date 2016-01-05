#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "Ð¡ÇÅÁ÷Ë®");
        set("long", @LONG
Ò»ÌõÇå³ºµÄÐ¡ÏªÉÏºá¿ç×ÅÒ»×ùÄ¾ÇÅ¡£ÇÅµÄÄÇ±ßÊÇÒ»Æ¬Ã¯Ê¢µÄÖñÁÖ¡£ÔÚÖñÁÖÓëÃ·
»¨µÄÑÚÓ³Ö®ÖÐ£¬Ò»×ù¾«ÇÉµÄ×¯ÔºÈôÒþÈôÏÖ¡£²à¶úÇãÌý£¬ÇÙÔÏ¶¡¶¬£¬ÓÐÈËÕýÔÚ[33m¸§ÇÙ[32m£¬
»¹ÓÐÐ©Å®Í¯µÄæÒÄÖÐ¦Éù¡£
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"gate",
  		"east" : __DIR__"another_sky",
		]));
		set("item_desc",([
			"¸§ÇÙ":	"Ô°×ÓÀïµÄ¸§ÇÙÄãÔõÃ´"MAG"¿´"NOR"µÃµ½ÄØ£¿Ó¦¸ÃÊÇ¡£¡£¡££¿£¿\n",
		]));
        set("outdoors", "resort");

		set("coor/x",0);
		set("coor/y",-30);
		set("coor/z",0);
		setup();
       
}


void init(){
	add_action("do_listen","listen");
}



int do_listen(){
	tell_object(this_player(),CYN"
Ô°ÄÚºöÈ»´«À´Ò»ÕóÇÙÉù£¬É½Ö®Î¡Î¡£¬Ë®Ö®ÑóÑó£¬¸«·¥Ö®¶¡¶¡£¬éÖ¸èÖ®ÒÓÄË£¬
ÒþÒþÏÖÓÚÖ¸ÏÂ£¬ÁîÈËÍüÈ´ÁËºì³¾µÄ·³ÄÕ¡£

Ö»ÎÅÔ°ÄÚÓÐÈËËµµÀ£ºÔ¶À´ÊÇ¿Í£¬Çë½ø´äÖñÉ½×¯Ò»Ðð¡£\n"NOR);
	this_player()->set_temp("resort_qin",1);
	return 1;
}


