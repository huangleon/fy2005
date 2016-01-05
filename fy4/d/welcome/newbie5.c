// Silencer@fy4 workgroup

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW"·çÔÆµÀ"NOR);
	set("long", @LONG
Ç°Ãæ¾ÍÒª½øÈë·çÔÆÊÀ½çÁË£¬ÍùÏÂ¿´È¥£¬°×ÔÆçÔÈÆ£¬Ò»×ùĞÛÎ°µÄ¾Ş³ÇÀïÈËÀ´ÈËÍù£¬
ºÃ²»ÈÈÄÖ£¬Äã²»½ûÓĞĞ©ĞÄ»Å¡£ºÃÔÚ·çÔÆÀïÓĞµÄÊÇÈÈÇéÓÑÉÆµÄÅóÓÑ£¬¶øÌìÉñÃÇÒ²¾¡ĞÄ
´´ÔìÁËÒ»¸öÓÑÉÆµÄÌìµØ¡£ÓÃÃüÁî[1;31m£é[0;32m¿´Ò»ÏÂÄãµÄ×°±¸£¬·¢ÏÖÄãĞĞÄÒÀï¶àÁËĞ©¶«Î÷£¬ÓÃ
[1;31m£ì£ï£ï£ë[0;32mÃüÁî¿ÉÒÔ¿´Ò»ÏÂËüÃÇµÄÓÃÍ¾¡£Ç°Í¾Âş³¤£¬²»×öºÃ×¼±¸¿É²»ĞĞÅ¶¡£½øÈë·çÔÆ
³ÇÓĞÁ½ÌõÂ·£¬[1;32m£î£å£÷£â£é£å[0;32mÊÇ¸øĞÂÊÖµÄ£¬ÓĞ¸öÓĞÈ¤µÄ£ñ£õ£å£ó£ô»¹ÄÜ¼Óµã¶ù¾­ÑéÆÀ
¼Û£¬Ë³±ãÄÃµã¶ùĞ¡ÅÌ²ø¹ıÈÕ×Ó£¬ĞÂ°æ·çÔÆÓĞĞí¶à±ä»¯£¬½¨ÒéÄã´ÓÕâÌõÂ·¿ªÊ¼£®
[1;32m£ö£å£ô£å£ò£á£î[0;32mÊÇ¸øÇá³µÊìÂ·ÒÑ¾­À´¹ıÕâ¶ùµÄ£¬¿ÉÒÔÌø¹ıĞÂÊÖµÄÕâÒ»½×¶Î£¬µ«ÊÇÒ»
ÇĞ¶¼µÃ°×ÊÖÆğ¼Ò£¬µ½Ê±ºò¿É²»Òª±§Ô¹Á½ÊÖ¿Õ¿ÕÅ¶¡£
LONG
	);
	set("exits", ([
  		"newbie" :  AREA_FY"fqkhotel",
  		"veteran" :  AREA_FY"fqkhotel",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",700);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}

int init(){
	object food, drink, drug, intro, me;
	me = this_player();
	if (me->query_temp("first_time_login"))
	{
		food = new("/obj/food_item/newbie_food");
		drink = new("/obj/food_item/newbie_drink");
		drug = new("/obj/medicine/newbie_drug"); 
		intro = new("/obj/item/newbie_letter");
		if (food)	food->move(me);
		if (drink)	drink->move(me);
		if (drug)	drug->move(me);
		if (intro)	intro->move(me);
	}
}


int valid_leave(object me, string dir) {

	if (dir == "newbie") 
		REWARD_D->riddle_set(me,"ĞÂÊÖÈëÃÅ",1);
		
	return ::valid_leave(me, dir);
}