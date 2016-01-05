//XXDER
inherit ROOM;

void create()
{
        set("short", "ÁøÊ÷ÉÏ");
        set("long", @LONG
ÁøÊ÷ºÜ´ó£¬ÓÉÓÚÊ÷ºáÎÔÔÚË®ÃæÉÏ£¬ËùÒÔ²¢²»¸ß¡£×øÔÚÕâÀï£¬ÄãµÄ½Å¼¸ºõ¿ÉÒÔÅö
µ½Ë®Ãæ£¬Î¢·çÏ®À´£¬ÁøÌõÇá·÷×ÅÄãµÄÃæ¼Õ£¬ºÃËÆÇéÈËµÄÊÖÒ»°ãÎÂÈá¡£¼¸Ìõ[37m½õÀğ[32mÔÚÊ÷
ÏÂµÄË®ÖĞÓÆÏĞµØÓÎÀ´ÓÎÈ¥£¬²»Ô¶´¦µÄĞ¡ÇÅµ¹Ó³ÔÚË®ÖĞ£¬´ÓÕâÀï¿´È¥±ğÓĞÒ»·¬¾°ÖÂ¡£
LONG
        );

   set("exits", ([ /* sizeof() == 4 */
      "down" : __DIR__"northpond",
   ]));
	
	set("item_desc", ([
		"fish":	"ÍÛ£¬ºÃ´óµÄÓã¶ù£¬Èç¹ûÓĞµöÓã¸Í¾ÍºÃÁË£¡\n",
		"½õÀğ":	"ÍÛ£¬ºÃ´óµÄÓã¶ù£¬Èç¹ûÓĞµöÓã¸Í¾ÍºÃÁË£¡\n",
		"ºÚ°ß": "Õâ¶ùÌ«Ô¶ÁË£¬ÔõÃ´Ò²¿´²»Çå³ş¡£\n",
		"Ê¯Í·":	"Ò»¿é´ó´óµÄÌ«ºşÊ¯¡£\n",
		"stone":	"Ò»¿é´ó´óµÄÌ«ºşÊ¯¡£\n",	
	]));
				
   	set("outdoors", "qingping");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",10);
   	setup();
}

int fish_notify(object obj){
   	object me, room, fish, *inv, bait;
   	int i,llvl;

   	me = this_player();
   	llvl = (int)me->query("kar");

	inv = all_inventory(obj);
	if(sizeof(inv) == 0){
		message("vision",me->name() + "ÌÍ³öÁË" + obj->name() + "ÓÖ·ÅÁË»ØÈ¥¡£\n", environment(me), me);
     	tell_object(me, obj->name() + "ÉÏÃ»ÓĞ¶üÔõÃ´¿ÉÒÔµöÓãÄØ ? \n");		
		return 1;
	}		
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("fish_bait")) {
			bait = inv[i];
      		message_vision("$N×øÔÚÊ÷¸ÉÉÏ¾²¾²µÄ¿ªÊ¼´¹µö¡£ \n" , me);
      		me->start_busy(3);
      		if(llvl > 15 && random(20) < llvl) {
            		tell_object(me, "ÎŞÁÄÖĞÄã×¢Òâµ½ÇÅÍ·Ñ©°×µÄÊ¯Í·ÉÏËÆºõÓĞÒ»¿éºÚ°ß¡£\n");
            		me->set_temp("marks/bridge", 1);
      		} else if(random(300) < llvl) {
            	tell_object(me, "ÎŞÁÄÖĞÄã×¢Òâµ½ÇÅÍ·Ñ©°×µÄÊ¯Í·ÉÏËÆºõÓĞÒ»¿éºÚ°ß¡£\n");
            	me->set_temp("marks/bridge", 1);
      		}
      		remove_call_out("do_fishing");              
      		call_out("do_fishing", 5, me, bait);			
			return 1;
		} 
	}
   	tell_object(me, "ÄãÓÃµÄ¶ü²»Ì«¶Ô°É ? \n");			
	return 1;
}

void do_fishing(object me, object bait)
{
   object 	fish;

   if(me && environment(me) == this_object()) {
   message_vision("$NºÜ¿ìÓÖ³¶¶¯ÁËÒ»ÏÂÓã¸Ë, " , me);
   switch (random(3)) {
      case 0:
         message_vision("È´Ê²Ã´¶¼Ã»µöÉÏÀ´ ! \n", me);
         break;
      case 1:
         message_vision("Ê²Ã´¶¼Ã»µöÉÏÀ´ , Óã¶üÈ´±»Óã³ÔÁË !!  \n", me);
         destruct(bait);
         break;
      case 2:
         message_vision("Óã¹³ÉÏµö×ÅÒ»ÌõÓã !!  \n", me);
         fish = new(__DIR__"obj/fish");
         fish->move(me);
         destruct(bait);
         break;
      }
   }
   return;
}

