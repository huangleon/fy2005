#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "¿×È¸ºÓ");
        set("long", @LONG
¾Ý´«¹ÅÂ¥À¼µÄ³Ç³Ø¡¢ËÂÔººÍ´åÂä±ã¹ã²¼ÓÚ¿×È¸ºÓÏÂÓÎÁ½°¶¡£ÕâÀïÒ²Ô­±¾ÊÇÌõ¼±
ÍÄµÄºÓÁ÷£¬Ç§°ÙÄêÇ°Ò²ÔøÓÐÈçÒ»ÌõÂÌ´ø°ãÔÚ²ÝÔ­ÉÏòêÑÑ£¬µ«Èç½ñÒ»ÇÐ¶¼ÒÑÊÇ¹ýÑÛÑÌ
ÔÆ£¬ÎôÈÕµÄ³¤ºÓÏÖ½ñ²»¸´´æÔÚ£¬Ö»ÓÐÌõÒ²ÈçÍ¬³ñ´øÒ»ÑùµÄ[37mÉ³Á÷[32mÔÚÎôÈÕµÄºÓµÀÖÐÂýÂý
Á÷ÌÊ£¬²»ÖªÍ¨ÏòºÎ·½¡£¡£¡£
LONG
        );

        set("exits", ([ 
		"southeast" : AREA_QUICKSAND"yangguan",
	]));
        set("outdoors", "loulan");
        set("objects", ([
                __DIR__"npc/xiongmaoer" : 1,
        ]) );
	set("item_desc", ([
                "É³Á÷":"
¿×È¸ºÓÖÐ½þÂúÁËÉ³Ê¯£¬ÍðÈç»Æ½ðÓñ´ø°ã£¬ÔÚÑô¹âÏÂÒ«ÑÛ¶áÄ¿£¬Ï¸Ï¸¿´È¥£¬É³Á÷
ËÆºõÔÚ»º»ºÁ÷¶¯£¬²»ÖªµÀÄÜ²»ÄÜÌË£¨WADE£©¹ýÈ¥¡£¡£ ¡£\n",
		"sand":"
¿×È¸ºÓÖÐ½þÂúÁËÉ³Ê¯£¬ÍðÈç»Æ½ðÓñ´ø°ã£¬ÔÚÑô¹âÏÂÒ«ÑÛ¶áÄ¿£¬Ï¸Ï¸¿´È¥£¬É³Á÷
ËÆºõÔÚ»º»ºÁ÷¶¯£¬²»ÖªµÀÄÜ²»ÄÜÌË£¨WADE£©¹ýÈ¥¡£¡£ ¡£\n",
                "sandstream": "
¿×È¸ºÓÖÐ½þÂúÁËÉ³Ê¯£¬ÍðÈç»Æ½ðÓñ´ø°ã£¬ÔÚÑô¹âÏÂÒ«ÑÛ¶áÄ¿£¬Ï¸Ï¸¿´È¥£¬É³Á÷
ËÆºõÔÚ»º»ºÁ÷¶¯£¬²»ÖªµÀÄÜ²»ÄÜÌË£¨WADE£©¹ýÈ¥¡£¡£ ¡£\n",
	
        ]) );
		set("coor/x",0);
		set("coor/y",0);
		set("coor/z",100);
		setup();
}

 void init()
{
		add_action("do_wade","wade");
}

int do_wade(string arg)
{
		object room;
        object me;  
		me=this_player();
		
		if (me->is_busy())
			return notify_fail("ÄãÏÖÔÚÕýÃ¦¡£\n");
					
		if (!arg || arg == "sand" || arg = "sandstream" || arg = "É³Á÷"
			|| arg = "É³")
		{
			if(!objectp(room = find_object(__DIR__"sandstream")))
			room = load_object(__DIR__"sandstream");
			message_vision("$NÐ¡ÐÄÒíÒí²È½øÉ³ºÓÁ÷......\n",this_player());
			me->start_busy(2);
			me->move(room);
			return 1;
		} 
}
