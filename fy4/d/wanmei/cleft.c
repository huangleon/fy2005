// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "×óÆ«Ôº");
        set("long", @LONG
ÔºÖĞÖÖÂúÁË[37mÃ·Ê÷[32mÓ×Ãç¡£Ã¿¿Ã¶¼ÔÚ×Â×³³É³¤£¬ÏÔÈ»ÓĞÈË¾«ĞÄÕÕ¹Ë¡£Ã·ÃçÖ®¼ä»¹ÓĞ
ÈË¹¤¿ª¿ÑµÄĞ¡ºÓ¹µ£¬°ë³ßÉîµÄÇşË®ÈÆÊ÷¶øÌÊ£¬¹à¸È×ÅÃ¿Ò»¿ÃÓ×Ãç¡£ÍÁÈÀºÚ¶øËÖËÉ£¬
ÏÔÈ»ÊÇ±¥º¬ÓªÑøµÄ·ÊÍÁ¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("item_desc", ([
                "Ã·Ê÷": "ÄãËÆºõ¿ÉÒÔ¿³£¨£ã£è£ï£ğ£©¼¸¸ùÏÂÀ´¡£\n",
                "tree": "ÄãËÆºõ¿ÉÒÔ¿³£¨£ã£è£ï£ğ£©¼¸¸ùÏÂÀ´¡£\n",

        ]) );
		set("coor/x",-10);
		set("coor/y",10);
		set("coor/z",0);
		setup();
}
void init()
{
		add_action("do_chop","chop");
}


do_chop()	{
	object vege;
	if((int) query("pulled") <= 20)
	{
		vege = new(__DIR__"obj/tree");
		if (!vege->move(this_player()))
			{
				write("Ì«¶àÌ«ÖØÁË£¬Ã»·¨ÄÃÁË£¡£¡£¡\n");
				destruct(vege);
				return 1;
			}
		write("Äã¿³ÁËÒ»¿ÃÃ·Ê÷Ó×Ãç·ÅÔÚ»³Àï¡£\n");
		add("pulled",1);
		return 1;
	}
	else
        write("¶¼±»ÈË¿³¹âÁË£¡£¡\n");
        return 1;
}



void reset()
{
	:: reset();
	delete("pulled");
}
