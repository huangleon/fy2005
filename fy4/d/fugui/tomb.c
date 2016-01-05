#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ÂÒÔá¸Ô");

	set("long", @LONG
ÕâÀïÊÇ¸½½ü°ÙĞÕÃÇÌ¸Ö®É«±äµÄÂÒÔá¸Ô£¬ÆëÈË¸ßµÄÒ°²İÔÚÕóÕóÒõ·çÖĞÒ¡°Ú²»¶¨£¬
ÖÜÎ§ÃÜÃÜÂéÂéµØ¶ÑÁËºÃ¼¸Ê®¸ö·ØÍ·¡£µ«¿´ÉÏÈ¥¶¼ºÜ¾ÃÃ»ÓĞÈË¼Àìë£¬Ä¹±®¶«Ò»¿é£¬Î÷
Ò»¿éµ¹ÔÚµØÉÏ£¬Ò»¸±ÆÆ°Ü²»¿°µÄ¾°Ïó¡£ºñºñµÄ[37mÒ°²İ[32mÔÚ·çÖĞÒ¡°Ú£¬ÑÍÃ»ÁË½ÅÏÂµÄÂ·¡£
LONG);

	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"milin2",
		"north":__DIR__"tomb1",
	]) );

	set("item_desc", ([
                "grass": "Ò°²İÔÚ·çÖĞ×óÓÒÒ¡°Ú£¬µ²×¡ÁËÈ¥Â·£¬µ«ÄãËÆºõ¿ÉÒÔ²¦¿ª(pushaside)Ëü¡£\n",
                "Ò°²İ": "Ò°²İÔÚ·çÖĞ×óÓÒÒ¡°Ú£¬µ²×¡ÁËÈ¥Â·£¬µ«ÄãËÆºõ¿ÉÒÔ²¦¿ª(pushaside)Ëü¡£\n"
        ]) );
        set("objects", ([
                __DIR__"obj/fakecaoren" : 1,
         ]) );
	set("coor/x",-30);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}

void init()
{	object ob;
	string outexit;
	add_action("do_push", "pushaside");
	if( interactive( ob = this_player()))
	{
		if(query("exits/east")) delete("exits/east");
		outexit = __DIR__"milin"+(string)(1+ random(25))+ ".c";	
		set("exits/east", outexit);
	}
}

int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("ÄãÒª²¦¿ªÊ²Ã´£¿\n");
                return 1;
        }
        if( arg == "Ò°²İ" || arg == "grass" || arg == "²İ" )
        {
        	me = this_player();
        	message_vision("$N²¦¿ªÂ·±ßµÄÒ°²İ£¬·¢ÏÖÁËÒ»ÌõÏòÎ÷µÄÂ·¡£\n", me);
 	if( !query("exits/west") ) 
 	{
		set("exits/west", __DIR__"tomb2");
		call_out("close_path", 5);
	}
        return 1;
        }
        else
        {
                write("Äã²»¿ÉÒÔ²¦¿ª"+arg+"\n");
                return 1;
        }
}

void close_path()
{
        if( !query("exits/west") ) 
        	return;
        message("vision",
"Ò»Õó·ç´µ¹ı£¬Ò°²İÓĞÈç»îÁËÒ»°ã£¬×óÓÒÒ¡°Ú£¬ÓÖµ²×¡ÁËÈ¥Â·¡£\n",this_object() );
	delete("exits/west");
}
