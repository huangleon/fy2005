// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit __DIR__"bush_base.c";

void create()
{
        set("short", "ÕÓÔó±ßÔµ");
        set("long", @LONG
ÕâÀïÎÚÔÆÃÜ²¼£¬ÌìÉ«¼«°µ¡£ÔÙÍùÇ°×ß¾ÍÊÇÎäÁÖÖĞÓĞÃûµÄËÀÓò£­£­[33m»ğÕÓÔó[32m¡£ÄÇÀï
²»µ«¾£¼¬ÃÜ²¼£¬ÃÍÊŞ³öÃ»£¬»¹ÓĞÄÜË²¼äËæÊ±ÅçÉäÖÁÈËÓÚËÀµØµÄ¶¾»ğÈª£¬»¹Î´×ß½ü£¬
ÒÑÊÇÈÈÀË¹ö¹ö£¬ÈôÃ»ÓĞÉîºñµÄÄÚ¹¦£¬¶à´ıÒ»¿ÌÒ²ÊÇ¼èÄÑ¡£¹ÊÀÏÏà´«Õâ»ğÕÓÔóÄÚÓĞ
Ò»Ìõ¾ŞÁú£¬Ã¿µ±Ò¹ÉîÈË¾²Ê±»¹ÄÜÌıµ½ËüµÄºğÉù¡£
LONG
        );
        set("exits", ([ 
  		"north" : AREA_CHENXIANG"cxs8",
	]));

        set("item_desc", ([
                "bush": "ÕâÀï¾£¼¬(bush)ÃÜ²¼£¬µ«ÄãËÆºõ¿ÉÒÔ¿³¿ª(chop)ËüÃÇ¡£\n",
                "¾£¼¬": "ÕâÀï¾£¼¬(bush)ÃÜ²¼£¬µ«ÄãËÆºõ¿ÉÒÔ¿³¿ª(chop)ËüÃÇ¡£\n"

        ]) );

        set("outdoors", "zhaoze");
        
        set("route","south");
        set("route_room",__DIR__"zhaoze1");
        
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_cut", "chop");
        add_action("do_listen","listen");
}

void reset()
{
	::reset();
	delete("exits/"+query("route"));
}


int do_listen(){
	object dragon, room;
	room = find_object(__DIR__"center");
	if (!room)
		room = load_object(__DIR__"center");
		
	if (dragon = present("red dragon",room))
	{
		tell_object(this_player(),HIR"\nÕÓÔóÉî´¦ÒşÔ¼´«À´µÍµÍµÄºäÃù£¬ËÆºõÊÇ¾ŞÊŞµÄÎØÑÊÖ®Éù¡£\n"NOR);
	}else
		tell_object(this_player(),HIR"\nÕÓÔóÀïÒ»Æ¬£¬¾²¼ÅÅ¼¶ûÓĞ¼¸Éù¹¾¹¾µÄË®ÅİÉù¡£\n"NOR);
	return 1;
}


