// Silencer@fy4 workgroup
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"¹ÊÏçÖ®Â·"NOR);
	set("long", @LONG
³¤³¤µÄğ®µÀµ½ÕâÀïÍ»È»Ò»ÁÁ£¬Ô­À´ÊÇÒ»¸öÊ®×Ö²æÂ·£¬ÕıÇ°·½µÄÂ·Æ½Ì¹¹âÃ÷£¬¶ø
ÆäËûÈıÌõÂ·»òÆéá«£¬»òÏÕ¾ş£¬»ò¾£¼¬´ÔÉú¡£¡£¡£ËÄ¿é¹ÅÀÏµÄÄ¾ÅÆ²åÔÚ¸÷×ÔµÄÂ·¿Ú£¬
Â·µÄÔ¶·½¾¿¾¹ÊÇÊ²Ã´ÔÚµÈ´ı×ÅÄã£¿¾¿¾¹¸ÃÑ¡ÔñÄÄÒ»ÌõÄØ£¿£¨ÇëÑ¡Ôñ·çÔÆÖĞµÄÃñ×å£¬
ÃüÁîÎª[37m£ó£å£ô£ò£á£ã£å[32m£¬ºó¸úÄãÏ£ÍûµÄÃñ×åÑ¡Ïî[1;32mºº×å¡¢Âú×å¡¢ÃÉ¹Å×å¡¢Ãç×å[0;32m£¬¸÷Ãñ
×åµÄ²îÒì²ÎÔÄ[37m£è£å£ì£ğ¡¡£î£å£÷£â£é£å[32mÖĞµÄÃñ×åÆª£¨Ñ¡Ïî7£©¡££©
LONG
	);
	set("exits", ([
//  		"down" :  "/d/fy/fqkhotel",
		 "down" :  __DIR__"newbie4",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",850);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}


int init(){
	add_action("do_setrace", "setrace");
}


int valid_leave(object me, string dir) {

	if (dir == "down")
	if ( !me->query_temp("race_setup"))
		return notify_fail("ÇëÔÚ½øÈë·çÔÆÊÀ½çÇ°Ñ¡¶¨Ò»¸öÃñ×å¡£
¸ñÊ½£º setrace <Ãñ×åÃû£¨ºº×Ö»òÆ´Òô£©>\n");
	
	return ::valid_leave(me, dir);
}

int do_setrace(string arg)
{
	object me;
	
	me = this_player();
	
	if( !arg ) 
		return notify_fail("ÄãÏ£Íû¼ÓÈëÄÄÒ»¸öÃñ×å£¿
¸ñÊ½£º setrace <Ãñ×åÃû£¨ºº×Ö»òÆ´Òô£©>\n");
		
	switch (arg) {
	case "ºº×å" :
	case "hanzu" :
			me->set("national","ºº×å");
			break;
        case "Âú×å" :
        case "manzu" :
                        me->set("national","Âú×å");
                        break;
        case "ÃÉ¹Å×å" :
        case "mengguzu" :
                        me->set("national","ÃÉ¹Å×å");
                        break;
        case "Ãç×å" :
        case "miaozu" :
                        me->set("national","Ãç×å");
                        break;
        default :
			return notify_fail("Ã»ÓĞÕâ¸öÃñ×å
¸ñÊ½£º setrace <Ãñ×åÃû£¨ºº×Ö»òÆ´Òô£©>\n");

	}
	write("Äã¾ö¶¨Í¶ÉúÓÚ"+ me->query("national") + "¡£\n");
	me->set_temp("race_setup", 1);
	return 1;
}

