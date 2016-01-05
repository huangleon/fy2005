inherit ROOM;
void close_path();

void create()
{
    set("short", "·çÔÆÑÅ¸ó");
    set("long", @LONG
ÕâÀï×¨ÃÅÕĞ´ı½­ºşÉÏÍò¶ù¼«ÏìÁÁµÄÈËÎï¡£ÄÜÓĞĞÒ×øÔÚÕâµÄ£¬²»ÊÇÒ»ÖÀÇ§½ğµÄºÀ
¿Í£¬¾ÍÊÇ¶å¶å½Å½­ºşËÄ²üµÄÒ»·½°ÔÖ÷¡£Õû¼ä·¿×ÓµÄÖĞÑëÖ»ÓĞÒ»ÕÅÉÏµÈ´äÓñ´òÄ¥³ÉµÄ
°ËÏÉ×À£¬×ÀÉÏ·Å×ÅËÄÖ»Óù´Í½ğ±­¡£ÈıÃæµÄÇ½ÉÏ¹ÒÂúÁË×Ö»­£¬Ê£ÏÂµÄÒ»ÃæÊÇÒ»µÀÒ»´¹
¼°µØµÄ[33mºì²¼¹ÒÁ±[32m¡£
LONG
    );
    set("exits", ([
	"down" : __DIR__"fyge",
	"east" : __DIR__"fysf",
      ]));
    set("objects", ([
				__DIR__"npc/servant": 1,
				__DIR__"npc/tatoo": 1,
	//			AREA_GUANWAI"npc/champion": 1,

      ]) );
    set("item_desc", ([
	"curtain": "Õâ¸öºì²¼¹ÒÁ±ËÆºõ¿ÉÒÔÏÆ¿ª(open)¡£\n",
	"¹ÒÁ±" : 	"Õâ¸öºì²¼¹ÒÁ±ËÆºõ¿ÉÒÔÏÆ¿ª(open)¡£\n",
	"ºì²¼¹ÒÁ±" : "Õâ¸öºì²¼¹ÒÁ±ËÆºõ¿ÉÒÔÏÆ¿ª(open)¡£\n"
      ]) );
//    set("NONPC",1);
    set("coor/x",40);
    set("coor/y",40);
    set("coor/z",10);
    setup();
}

void init()
{
    add_action("do_open", "open");
}

void close_path()
{
    if( !query("exits/north") ) return;
    message("vision","ºì²¼¹ÒÁ±ÓÖÂäÁËÏÂÀ´£¬¸Ç×¡ÁË°µÃÅ¡£\n",this_object() );
    delete("exits/north");
}


int do_open(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg=="" ) return 0;

    if( arg=="curtain" || arg =="ºì²¼¹ÒÁ±" || arg=="¹ÒÁ±") {
	write("ÄãÏÆ¿ªºì²¼¹ÒÁ±£¬");
	if( (int) me->query("force_factor") >= 100 )	{
	    write("ÍÆ¿ªÁËºóÃæÏò±±µÄÒ»ÉÈ°µÃÅ¡£\n");
	    if( !query("exits/west") ) {
		set("exits/north", __DIR__"fysecret");
		call_out("close_path", 5);
	    }
	    return 1;	
	}	else
	    write("ÊÔ×ÅÍÆÁËÍÆºóÃæµÄ°µÃÅ£¬µ«Ã»ÓĞÍÆ¿ª¡£\n");
	return 1;
    }
    write("ÄãÒªÏÆ¿ªÊ²Ã´£¿\n");
}



void init_scenery()
{
    object tie;
    tie = present("royal servant", this_object());
    if (tie) {        
	if (tie->query("in_meihuadao")) {
	    tie->delete("in_meihuadao");
	    tie->delete("no_heal");
	    return;
	} else {
	    CHANNEL_D->do_sys_channel("info",sprintf("%s£¬Ìú´«¼××·Ï®Ã·»¨µÁÎ´¹û£¬ÖĞÌÒ»¨ÕÎÖØÉË¶ø¹é¡£", NATURE_D->game_time()));
	    tie->set("in_meihuadao",1);
	    tie->set("eff_kee",tie->query("max_kee")/2);
	    tie->set("eff_gin",tie->query("max_gin")/2);
	    tie->set("eff_sen",tie->query("max_sen")/2);
	    tie->set("no_heal",1);
	}
    }
    return;	
}

