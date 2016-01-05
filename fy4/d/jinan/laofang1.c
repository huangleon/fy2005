
inherit ROOM;

void create()
{
    set("short", "ÀÎ·¿");
	set("long", @LONG
ÕâÀïÊÇ¹ØÑº·¸ÈËµÄµØ·½£¬²»µ½Ê®³ß¼û·½µÄÀÎ·¿ÖĞÃ»ÓĞ´²é½±»Èì£¬Ö»ÓĞ¼¸¶Ñ¿İ»Æ
É¢·¢×ÅÄÑÎÅÆøÎ¶µÄµ¾²İ£¬²»Ê±µÄÓĞ´óÀÏÊó´ÓÄãµÄ½ÅÏÂÅÜ¹ı£¬²»Öª´ÓÄÇÀïÆ®À´µÄ¸¯³ô
Ö®Æø³ä³â×ÅÕû¸öÀÎ·¿¡£ËÀ¼ÅºÚ°µµÄÀÎ·¿Àï£¬²»Ê±´ÓÔ¶´¦´«À´·¸ÈËµÄºô¾ÈÉù¡£
 [33m£¨£ì£é£ó£ô£å£î¡¡ºô¾ÈÉù£©[32m
LONG
	);
    	set("indoors", "jinan");
	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",0);
	set("valid_startroom",1);
	set("no_magic", 1);
	setup();
}
void init()
{
	this_player()->set("startroom", base_name(this_object()));
	add_action("do_listen", "listen");
}

int do_listen(string arg)
{ 
	object player;
	player = this_player();
	if (arg == "sound" || arg== "ºô¾ÈÉù")
	{
		tell_object(player,"ÄãĞ¡ĞÄµØÏëÇãÌıÔ¶´¦ÀÎ·¿ÀïµÄºô¾ÈÉù£¬¿ÉÖÜÎ§Í»È»ÏİÈëËÀÒ»°ãµÄ¼Å¾²ÖĞ¡£\n");
		tell_object(player,	"Ò»Õó»Ì¿ÖÓ¿ÉÏĞÄÍ·£¬Äã²»ÓÉÏë´óÉùºô¾È(yell help) \n") ;
		add_action("do_yell","yell");
	}else
	{
		return notify_fail("ÄãÒªÌıÊ²Ã´£¿\n");
	}
	return 1;
}

int do_yell(string arg)
{
	object player,yuzuzhang;
	player = this_player();
	if (arg != "help")
	{
		return notify_fail("ÄãÒª´óÉùºô½ĞÊ²Ã´£¿\n");
	}else
	{
		message_vision("$NÉùË»Á¦½ßµØ´óº°£º¡°¿ìÀ´ÈË°¡£¡·ÅÎÒ³öÈ¥£¡£¡£¡¡±\n",player);
		if (!random(3))
		{
			
			if (yuzuzhang = present("yuzu zhang",this_object()))
			{
				return notify_fail("Óü×ä³¤Õâ»á¶ùÕıÃ¦×ÅÄÄ£¬Ã»¿ÕÀíÄã£¡µÈ»á¶ùÔÙÊÔÊÔ°É¡£\n");
			}else
			{
				yuzuzhang = new(__DIR__"npc/yuzuzhang");
				yuzuzhang->move(this_object());
			}
			
			message_vision("Ö»¼û$NÂıÂıõâÁË¹ıÀ´ \n",yuzuzhang);
			yuzuzhang->release_player(player);
		}
		else
		{
			tell_object(player,"ÄãÖ»Ìı¼ûÄãÆà²ÒµÄ½ĞÉùÔÚ¿Õµ´µ´µÄÀÎ·¿ÖĞ»Øµ´£¬¸ü¼Ó¼ÓÉîÁËÄãµÄ¿Ö¾å¡£\n");
		}
	}
	return 1;
}
