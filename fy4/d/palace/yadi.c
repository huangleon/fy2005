inherit ROOM;
#include <ansi.h>
#include <command.h>

void create()
{
        set("short", "ÑÂµ×");
        set("long", @LONG
ÔÚÄãµÄÃæÇ°ÊÇÒ»¸öĞ¡ºş£¬ºşË®·ºÖøôÔ¹â£¬ÇáÈáµØÅÄ´òÖø°¶±ßµÄ[37mÏ¸É³[32m¡£Í¸¹ıÇå³º
µÄºşË®£¬Äã¿ÉÒÔ¿´µ½ÔÚË®ÖĞÎûÏ·µÄÓãÏº£¬»¹ÓĞËæÖøË®²¨ÆÅæ¶ÆğÎèµÄË®²İ¡£°¶±ßÓĞÒ»
Ğ©°«Ğ¡µÄ¹àÄ¾£¬¹àÄ¾´ÔºóÊÇÒ»µÀ¸ßËÊÈëÔÆµÄ[37mÎ£ÑÂ[32m£¬¸øÈËÒÔ¸ß²»¿ÉÅÊµÄ¸Ğ¾õ¡£
LONG
        );
        set("item_desc", ([
             
                "Î£ÑÂ": "ÑÂ±ÚÈçÍ¬µ¶Ï÷µÄÒ»°ã»¬²»ÁôÈË£¬ÉÏÃæ´ç²İ²»Éú¡£Ì§Í·Íû£¬\nÄãÒşÔ¼¿É¼û°ëÑÂÉÏÍ»³öÒ»¿é°×É«µÄÉ½Ê¯¡£\n",
        ]) );
	set("objects", ([ 
		__DIR__"obj/sand" : 1,
	]));
	set("outdoors","fengyun");
	set("coor/x",-50);
	set("coor/y",60);
	set("coor/z",10);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_dive", "dive");
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("sand", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/oilbag");
                item->move(con);
        }
}

int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || (arg != "Î£ÑÂ" && arg != "up" && arg != "cliff")) {
		write("ÄãÒªÅÀÊ²Ã´£¿\n");
		return 1;
	}
	me = this_player();
	mlvl = (int)me->query_skill("move",1);
	if(mlvl < 50) 
		message_vision(HIY "\n$N·ÜÁ¦ÏòÉÏÅÀÈ¥£¬ÅÀÁË²»µ½Á½ÈıÕÉ£¬Ö»¾õµÄÊÖ½Å·¢Èí£¬ÏòÏÂ»¬ÁËÏÂÈ¥¡£\n"NOR, me);
	else {
		message_vision(HIY "\n$NĞ¡ĞÄÒíÒíµØÏòÉÏÅÀÈ¥£¬ÉíĞÎÂıÂı±»ÔÆÎíÕÚÑÚ¡£\n"NOR, me);
		me->move(__DIR__"whiterock");
	}
	return 1;
}

int do_dive()
{
        object *inv,me;
        object bottom;
        int i;
	string	objname;

        me = this_player();
        bottom = load_object(__DIR__"bottom1");
        if (bottom->query("underwater") > me->query_skill("swimming",1))
		return notify_fail("ÄãµÄÓÎÓ¾¼¼ÄÜÌ«²î£¬Ã»·¨¹ıÈ¥Ñ½¡£\n");
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
		objname = (string)inv[i]->query("name");
		if( !inv[i]->query("waterproof") && objname != "Â«Î­")
	       		DROP_CMD->do_drop(me, inv[i]);
		}
        message_vision("$NÍÑ¹âÁËËùÓĞÒÂ·ş£¬Ò»¸öÃÍ×ÓÔúÈëºşË®ÖĞ£®\n",me);
        if(bottom) me->move(bottom);
        return 1;
}

