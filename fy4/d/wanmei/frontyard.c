inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "É½×¯Ç°Ôº");
        set("long", @LONG
Ê®ÕÉ·½Ô°µÄÔº×ÓÁ½²àÖÖ×Å¼¸ÅÅ´äÂÌµÄ[37mÊß²Ë[32m¡£Ôº½ÇÓĞÒ»¿ÚĞ¡¾®¡£¾®¿ÚÓĞÒ»Ä¾Í°£¬
Í°ÉÏÏµ×ÅÂéÉş£¬ÏÔÈ»ÊÇÓÃÀ´¼³Ë®µÄ¡£Ôº×ÓÁíÒ»±ß¶Ñ×ÅµÄ¼¸À¦¸Õ¿³ÏÂÀ´µÄ[37mÄ¾²ñ[32mÕıÔÚÌ«
ÑôÏÂÂıÂıÉ¹¸É¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  				"west" : __DIR__"gate",
  				"east" : __DIR__"meidang",
			  	"north" : __DIR__"woodroom",
			  	"south" : __DIR__"woodhouse",
			  	"northeast" : __DIR__"left",
			  	"southeast" : __DIR__"right",
		]));
        set("outdoors", "wanmei");
        set("resource/water",1);
        set("liquid/container","Ğ¡¾®");
        set("liquid/name","Ğ¡¾®Ë®");
        set("item_desc", ([
                "Êß²Ë": "
                        ºÃÇàºÃÂÌµÄÊß²ËÑ½£¡ÄãÈç¹û²»ÅÂÈËÂî£¬°Î£¨£ğ£õ£ì£ì£©Ò»¿Ã°É£¡\n",
                "Ä¾²ñ": "
                        ¿ì¸ÉÁËµÄÄ¾²Ä£¬ÄÃ£¨£ğ£é£ã£ë£©¼¸¸ù¶ù£¿\n",
        ]) );
		set("coor/x",-30);
		set("coor/y",0);
		set("coor/z",0);
		setup();
}


void init()
{
    add_action("do_pull", "pull");
    add_action("do_pick", "pick");
    
}

void reset()
{
    ::reset();
    delete("pulled");
    delete("picked");
}


do_pull()
{
    object vege;
    if((int) query("pulled") <= 10)
    {
        vege = new(__DIR__"obj/vege");
        message_vision("$N°ÎÁËÒ»¿Ã"+vege->query("name")+"·ÅÔÚ»³Àï¡£\n", this_player());
        vege->move(this_player());
        add("pulled",1);
        return 1;
    }
    else
	write("¶¼±»ÈË°Î¹âÁË£¡£¡\n");
    return 1;
}

int do_pick()
{
    object vege;
    if((int) query("picked") <= 10)
    {
        vege = new(__DIR__"obj/wood");
        message_vision("$NÄÃÁËÒ»¸ù"+vege->query("name")+"·ÅÔÚ»³Àï¡£\n", this_player());

        vege->move(this_player());
        add("picked",1);
        return 1;
    }
    else
        write("¶¼±»ÈËÄÃ¹âÁË£¡£¡\n");
    return 1;
}

