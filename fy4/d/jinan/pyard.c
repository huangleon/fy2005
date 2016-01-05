#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "´óÀÎÄÚ");
	set("long", @LONG
Ê¯Ç½Î§³ÉµÄÔºÂäºÜ´ó£¬»ÒºÚÉ«µÄÔºÇ½ÊÇÆ½³£ÔºÇ½µÄÈıËÄ±¶Ö®¸ß£¬ÉÏÃæÕ¾×Å¼¸¸ö
[33mÓü×ä[32m£¬Õı¾¯ÌèµØ¿´ÊØ×Å·¸ÈË¡£Ôº×ÓÀï¶ÑÂúÁË¾Ş´óµÄ[33mÊ¯ÁÏ[32m£¬ÓĞ²»ÉÙµÄ·¸ÈËÕıÔÚÃ¦ÂµµÄ
°áÔË¡£Ç½ÃæÒ»¸ö[33m³ôË®¿Ó[32mÅÔÊ÷ÁËÒ»¿é¸æÊ¾ÅÆ£¨[33m£ó£é£ç£î[32m£©¡£Ôº×ÓÏòÎ÷ÊÇ³öÓüµÄ´óÃÅ¡£
LONG
	);
    	set("exits", ([ /* sizeof() == 3 */
       		"west" : __DIR__"dayu",
    	]));
    	set("objects", ([

    	]) );
	set("item_desc", ([
	    	"sign": "·²À´´ËµÄ·¸ÈË±ØĞë¹¤×÷£¨£÷£ï£ò£ë£©¶şÊ®´Î·½¿É³öÈ¥¡£\n",
	    	"¸æÊ¾ÅÆ" : "·²À´´ËµÄ·¸ÈË±ØĞë¹¤×÷£¨£÷£ï£ò£ë£©¶şÊ®´Î·½¿É³öÈ¥¡£\n",
	    	"³ôË®¿Ó" : "³ôË®¿ÓÀï¼¸ÌõÎÃÓ¬µÄÓ×³æÔÚÈä¶¯£¬½«¾Í×ÅºÈ¼¸¿Ú°É£¨drink£©\n",
	    	"pond" : "³ôË®¿ÓÀï¼¸ÌõÎÃÓ¬µÄÓ×³æÔÚÈä¶¯£¬½«¾Í×ÅºÈ¼¸¿Ú°É£¨drink£©\n",	
	    	"Óü×ä":	  "Óü×äËµ£º¶«ÕÅÎ÷Íû£¬ÏëÔ½ÓüÃ´£¿ÀÏ×ÓÕı³îÃ»»ú»á´şÄãÄØ£¡\n",
	    	"Ê¯ÁÏ":	  "Óü×äËµ£º¶«ÕÅÎ÷Íû£¬ÏëÔ½ÓüÃ´£¿ÀÏ×ÓÕı³îÃ»»ú»á´şÄãÄØ£¡\n",	
	]) );

//    	set("no_fight", 1);
    	set("no_fly",1);
    	set("outdoors", "jinan");
	set("valid_startroom",1);
	set("coor/x",30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_work", "work");
	add_action("do_drink", "drink");
    	if( interactive(this_player())){
	    	this_player()->set("startroom", __FILE__);
    	}
}


int do_drink(){

	object me= this_player();
	
	if (me->is_busy())
		return notify_fail("ÄãÏÖÔÚÕıÃ¦¡£\n");
	
	message_vision(CYN"$NÅ¿ÔÚ³ôË®¿Ó±ß¹¾¹¾µØºÈÁË¼¸¿Ú£¬¿È£¬ÂäÄÑµÄÓ¢ĞÛ²»ÈçÊ¸¹·°¡£¡\n"NOR, me);
	me->perform_busy(1);	
	if (me->query("food")<100) me->set("food",100);
        if (me->query("water")<100) me->set("water",100);	
        return 1;
}

int do_work(){
	object me;
	int i, gin, sen;
	me = this_player();
	i = me->query_temp("jail_work");
	gin = me->query("max_gin")*2/3;
	sen = me->query("max_sen")*2/3;
	if(me->is_busy()) 
		return notify_fail("ÄãµÄ¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜ¹¤×÷¡£\n");
	message_vision(HIR"$NĞÁ¿àµÄ¼Ó¹¤Ê¯ÁÏ£¬²îµãÃ»ÀÛËÀ¹ıÈ¥¡£\n"NOR, me);
	me->receive_damage("gin",gin);
	me->receive_damage("sen",sen);
	me->set_temp("last_damage_from","ÔÚ¼ÃÄÏ´óÀÎÇ¿ÖÆÀÍ¶¯¹ı¶ÈÀÛËÀÁË¡£\n");
	me->perform_busy(2);
	me->set_temp("jail_work", i+1);
	return 1;	 
}

int valid_leave(object me, string dir){
	object obj;
	
	if(dir == "west" ) {
		if(me->query_temp("jail_work") < 20){
				return notify_fail("Óü×äºÈµÀ£º¡°Õ¾×¡£¬»¹Ã»ÓĞ×öÍê¹¤¾ÍÏë×ß£¿¡±\n");
			} 
			me->delete_temp("jail_work");
			me->set("vendetta/authority", 0);
			me->delete("marks/crime");
			me->set("startroom",AREA_FY"fqkhotel");	
			tell_object(me,HIR"\nÓü×äËµ£º³öÈ¥¹æ¹æ¾Ø¾Ø×öÈË£¬±ğÔÙ·¸ÊÂ¶ùÁË¡£\n"NOR);	
	}
	return 1;
}
