#include <ansi.h>

inherit ROOM;
#define FATEMARK "ËÞÃüB/º£ÊÐò×Â¥"

void create()
{
        set("short", "É³Áë");
        set("long", @long
·ÅÑÛÍûÈ¥£¬Ö»ÓÐ»ÆÉ³£¬ÎÞ±ßÎÞ¼Ê£¬ÎÞÇîÎÞ¾¡µÄ»ÆÉ³£¬Ã»ÓÐË®£¬Ã»ÓÐÉúÃü£¬Ò²
Ã»ÓÐÏ£Íû¡£´Ë´¦µØÔ¶ÈËÏ¡£¬Ê±³£³öÃ»µÄÉ³µÁºáÐÐ²þâ±£¬É³ÇðÉÏºÕÈ»Ê¬Éí×Ýºá£¬Ñª
¼£Î´¸É¡£¸üÎª¿É²ÀµÄÊÇÆµ·±µÄÉ³±©£¬µ«¼û»ÆÉ³ÔÚ·ç±©ÖÐ¾íÎè£¬Î¨ÓÐÑØ×ÅÁë¼¹Íù[33m±±[32m
²ÅÓÐ³öÂ·£¬ÈôÊÇºúÂÒÏ¹´³£¬ÕâÒ»±²×ÓÒ²²»Ò»¶¨×ßµÃ³öÈ¥¡£
long
        );
        set("exits", ([ 
		"southwest" :   __DIR__"sandlin",
		"northwest" :   __DIR__"yangguan",
		"west" : 	__DIR__"desert5",
		"east" : 	__DIR__"desert6",
	]));
        set("outdoors", "quicksand");
	set("coor/x",-900);
	set("coor/y",100);
	set("coor/z",0);
	setup();
}



void init_scenery()
{
        remove_call_out("sun_rise");
        call_out("sun_rise",1, random(2), 0);
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(3)) {
		ob->set(FATEMARK,num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) µÃµ½"+FATEMARK+" "+num+"¡£ %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}


void sun_rise(int sunrise_stage)
{
	object *ppls;
    	int i, j;
    	object ob;
    	function f = (:add_fate_mark:);
    	ob=this_object();
    	   	
	switch(sunrise_stage)
	{
    		case 0: message("vision", YEL"¸Õ²Å»¹ÔÚËÁÄõµÄÉ³±©ÂýÂýÆ½Ï¢ÏÂÀ´£¬Ã»ÓÐ·ç£¬Ò»Ë¿·ç¶¼Ã»ÓÐ£¬Ò²Ã»ÓÐË¿ºÁÉùÒô¡£\n"NOR, ob);
    			call_out("sun_rise",10,1);
    			break;
    		case 1:
        		message("vision", WHT"\nÔ¶Ô¶ÍûÈ¥£¬Ìì±ßµÄÔÆÏ¼ÖÐ£¬ÒþÒþÏÖ³ö³ÇÀªµÄÓ°×Ó¡£\n"NOR, ob);
        		call_out("sun_rise", 5, 2);
        		break;
    		case 2:
        		message("vision", WHT"\nÕâ³ÇÀªµÄÓ°×ÓÔ½À´Ô½ÇåÎú£¬ºÓÁ÷äýäý£¬ºþ²´Èç±Ì£¬½ÖµÀ·¿ÎÝ·ðËþ³ÇÇ½£¬ÒÀÏ¡¿É±æ¡£\n"NOR, ob);
        		call_out("sun_rise", 5, 3);
        		break;
    		case 3:
        		message("vision", WHT"\nö®ÄÇÖ®¼ä£¬ÔÆ²Ê±ä»Ã£¬ÕâÐ©»ÃÏñÓÖ¹éì¶ÎÞÓÐ¡£Ò»ÇÐ·Â·ðÔÚÃÎ»ÃÖ®ÖÐ¡£¡£\n"NOR, this_object(), ob);
        		ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
            		if(sizeof(ppls))
					map_array(ppls,f);
                	break;
		default:
			return notify_fail("something wrong\n");
	}
}
