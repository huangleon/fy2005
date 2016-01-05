inherit ROOM;
void create()
{
    set("short", "ïÚ¾ÖÄÚÔº");
    set("long", @LONG
Ò»¼ä±±·½³£¼ûµÄËÄºÏÐ¡Ôº£¬ÊÇ½ðÊ¨ïÚ¾ÖµÄïÚÍ·»ï¼ÆÃÇÐÁ¿àÖ®Óà£¬ÐÝÏ¢·ÅËÉµÄµØ
·½¡£ÖÜÎ§ÓÐ¼¸¼äÇàÍßÐ¡·¿£¬ÊÇ¹©Ã»ÓÐ¼ÒµÄÄêÇà»ï¼ÆÃÇ×¡µÄ¡£Ôº×ÓµÄÖÐÑëºáÆßÊú°ËµÄ
¼Ü×Å¼¸¸ù[33mÖñ¸Í[32m£¬¶«±±½ÇµÄµØÉÏÔÓÂÒµØ¶Ñ×ÅÐ©[33mÖñÏ¯[32m¡£
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"ghall",
	"east"  : __DIR__"gke1", 
	"north" : __DIR__"gke2",
	"south" : __DIR__"gke3",
      ]));
    set("item_desc", ([
	"bamboo": 	"ÕâÐ©Öñ¸ÍºÃÏó¿ÉÒÔÅ²¶¯£¨move bamboo£©¡£\n",
	"Öñ¸Í" : 	"ÕâÐ©Öñ¸ÍºÃÏó¿ÉÒÔÅ²¶¯£¨move bamboo£©¡£\n",
	"¼¸¸ùÖñ¸Í" : 	"ÕâÐ©Öñ¸ÍºÃÏó¿ÉÒÔÅ²¶¯£¨move bamboo£©¡£\n",
	"ÖñÏ¯":		"ÆÆÆÆÀÃÀÃµÄÖñÏ¯ÉÏ»ýÂúÁË»Ò³¾£¬ºÃ¾ÃÃ»ÈËÇåÀí¹ýÁË£¨move ÖñÏ¯£©¡£\n",
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",200);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init()
{
    add_action("do_move", "move");
}

int do_move(string arg)
{
    object cock, me, room;

    me = this_player();

    if ( arg == "bamboo" || arg == "Öñ¸Í" || arg == "¼¸¸ùÖñ¸Í") {
	if (me->is_busy())
	    return notify_fail("ÄãÏÖÔÚÕýÃ¦¡£\n");
	me->perform_busy(1);

	if( query("amount") > 10 ) 
	    return notify_fail("»¹Å²£¿£¡ó¯òë¶¼±»ÄãÏÅµÄÅÜ¹âÁË¡£\n" );
	cock = new(__DIR__"npc/cockroach");
	if(cock) {
	    cock->move(this_object());
	    message_vision("$NÅ²ÁËÏÂÖñ¸Í£¬Ò»Ö»"+cock->name()+"·É¿ìµØÅÀÁË³öÀ´£®\n", this_player());
	}
	add("amount",1);
	return 1;
    }
    if ( arg == "ÖñÏ¯") {
	if (me->query_temp("marks/js_cook_mice") < 4) {
	    message_vision("$NÅ²ÁËÅ²ÖñÏ¯£¬ÄÖµÃÂúÔº×ÓÊÇ»Ò¡£\n",me);
	    return 1;
	}
	if (me->query_temp("marks/js_cook_move")<3) {
	    me->add_temp("marks/js_cook_move",1);
	    message_vision("$NÀ­ÆðÒ»ÕÅÖñÏ¯£¬ÏÂÃæ¿Õ¿Õµ´µ´£¬Ö»ÓÐÆËÃæµÄ»Ò³¾¡£¡£\n",me);
	    return 1;
	}
	me->delete_temp("marks/js_cook_move");
	me->delete_temp("marks/js_cook_mice");
	if ( !objectp(room = find_object(__DIR__"mice_room0")))
	    room = load_object(__DIR__"mice_room0");
	message_vision("$NÓÃÁ¦Ò»À­ÖñÏ¯£¬Ã»ÁÏµ½½ÅÏÂÒ»»¬£¬ÆËÍ¨Ë¤ÔÚµØÉÏ¡£\n",me);
	me->unconcious();
	me->move(room);
	return 1;
    }

    return notify_fail("ÄãÒª°á¶¯Ê²Ã´£¿\n");
}

void reset()
{
    ::reset();
    set("amount",0);
}
