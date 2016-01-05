inherit ROOM;

void create()
{
    set("short", "ïÚ¾Ö³ø·¿");
    set("long", @LONG
½ðÊ¨ïÚ¾Ö¶Ô»ï¼ÆÃÇÊ®·Ö¿î´ý£¬²»µ«Ã¿ÔÂÓÐÐ½½ð£¬¶øÇÒ»¹°ü³Ô×¡¡£ÕâÀï¾ÍÊÇ»ï¼Æ
ÃÇÒ»ÈÕÈý²ÍµÄµØ·½¡£³ø·¿µÄÇ½ÉÏ¹ÒÂúÁË¹øÍëÆ°Åè£¬»¹ÓÐÒ»Ð©·ç¸ÉµÄÂ±Î¶¶ù¡£·¿ÖÐ·Å
×ÅÒ»ÕÅ[33m³¤Ì¨[32m£¬³¤Ì¨µÄÖÜÎ§°Ú×Å¼¸Ìõ[33m³¤µÊ[32m¡£ÓÍÑÌÃÖÂþÖÐ£¬¼¸¸ö³ø×ÓÃ¦µÃ²»¿É¿ª½»¡£
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"northeast" : __DIR__"goldlion",
      ]));
    set("objects", ([
	__DIR__"npc/goldcook" : 1,
	__DIR__"obj/wall": 1,

      ]) );

    set("coor/x",140);
    set("coor/y",-80);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}

void init(){
    add_action("do_look","look");
}


int do_look(string arg){

    if (arg == "table")	arg = "³¤Ì¨";
    if (arg == "stool")	arg = "³¤µÊ";

    if (arg == "³¤Ì¨" || arg == "³¤µÊ") {
	if (!this_player()->query_temp("marks/js_cook_mice")) {
	    tell_object(this_player(),"ÕâÊÇÒ»ÕÅºÜÆÕÍ¨µÄ"+ arg + "£¬ÉÏÃæÕ´ÂúÁËÓÍÑÌ¡£\n");
	    return 1;
	}
	tell_object(this_player(),"´ó³øÒ»ÌáÐÑÄã²Å·¢ÏÖ£¬Õâ×ÀÉÏÒÎÉÏ¶¼ÓÐÀÏÊóÅÜ¹ýµÄºÛ¼££¬Ò»Ö±ÑÓÉìµ½Ôº×ÓÀï¡£\n");
	this_player()->set_temp("marks/js_cook_mice",2);
	return 1;
    }
    return 0;
}

void reset()
{
    object          *inv;
    object          con, item;
    int             i;

    ::reset();
    con = present("wall", this_object());
    inv = all_inventory(con);
    if( sizeof(inv) != 1) {
	for(i=sizeof(inv)-1; i>=0; i--)destruct(inv[i]);
	if (item = new(__DIR__"npc/obj/luwei")) {
	    if (!item->move(con))
		destruct(item);
	}
    }
}
