// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "º£ÉÏ");
        set("long", @LONG
ËÄÖÜÊÇÃ£ÎŞ±ß¼ÊµÄ[33mº£Ë®[32m£¬¿´²»µ½ÈÎºÎµÄ´¬Ö»»òÂ·µØ£¬Äã±»ÕâÎŞ±ßÎŞ¼ÊµÄº£Ë®°ü
Î§×Å£¬Ëæ×Å²¨ÀË¶øÆğ¸¡£¬¿àÉ¬µÄº£Ë®²»Ê±µØ¹àÈëÄãµÄ¿ÚÖĞ£¬Äã²»ÓÉµØ¸Ğµ½ÁË×Ô¼ºµÄ
ÃìĞ¡£¬²»Öª»¹ÓĞ¶à´óµÄÉú»¹»ú»á¡£
LONG
        );
   
   set("item_desc", ([
   		"º£Ë®":		"¼ÈÈ»µ½ÁËº£Àï,×ÜÊÇÓ¦¸ÃÊÔ×ÅÓÎÓ¾ÁË£¨swim£©\n",
   	]));	
   		
   set("objects", ([
   ]) );   

	set("coor/x",1100);
	set("coor/y",-12640);
	set("coor/z",-60);
   setup();
}

void init()
{
   add_action("do_swim", "swim");
}

int do_swim(string arg)
{
   object me, room;
   int kar, k;
  
   me = this_player();
   if( me->is_fighting() )
      return notify_fail("ÄãÔÚÕ½¶·ÖĞ£¡\n");
   if( me->is_busy() )
      return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
   
   me->start_busy(2);
   
   message_vision("\n$N·ÜÁ¦ÏòÇ°ÓÎÈ¥!\n", me);
   
      tell_object(me, "Ô¶Ô¶µÄÄãËÆºõ¿´µ½ÁËÒ»Æ¬Â½µØ£¬ÄãÓÃ¾¡ËùÓĞµÄÁ¦ÆøÏòÄÇ¶ùÓÎÈ¥¡£\n");
      message_vision("$NÖÕÓÚÊªÁÜÁÜµØÅÀµ½ÁË°¶ÉÏ!\n\n", me);
      room = find_object(AREA_EASTCOAST"seaside");
      if(!objectp(room)) room = load_object(AREA_EASTCOAST"seaside");
      me->move(room);
      message("vision", me->name()+"ÊªÁÜÁÜµØ´Óº£ÀïÅÀÁËÉÏÀ´¡£\n", environment(me), me);
      return 1;
}
