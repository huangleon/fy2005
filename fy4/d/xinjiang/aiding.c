/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "°¬¶¡ºş");
        set("long", @LONG
°¬¶¡ºş£¬±±ÓĞ²©¸ñ´ïÉ½£¬Î÷ÓĞ¿¦À­ÎÚ³ÉÉ½£¬ÄÏÓĞ¾õÂåËş¸ñÉ½£¬¶«ÄÏÓĞ¿âÄ·Ëş¸ñ
É½¡£ÒâÎªÔÂ¹âºş¡£Òòºş´ó²¿·ÖÊÇÖåñŞÈç²¨µÄ¸ÉºÔºşµ×£¬´¥Ä¿½ÔÊÇÒø°×¾§Ó¨µÄ[37mÑÎ°Í[32m£¬
ÔÚÑô¹âÏÂÉÁÉÁ·¢¹â£¬¿áËÆº®Ò¹¾¦¿ÕµÄÔÂ¹â£¬¹ÊÃû°¬¶¡ºş¡£
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"tulufan",
  "westdown" : __DIR__"pubu",
]));
        set("objects", ([
        __DIR__"npc/saltboss" : 1,
                        ]) );
        set("item_desc", ([
	           "ÑÎ°Í": "ºñºñµÄÒ»²ãÑÎ°ÍÆÌ¸ÇÔÚÒÑ¾­¸ÉºÔµÄºşµ×¡£\n",
	           "yanba": "ºñºñµÄÒ»²ãÑÎ°ÍÆÌ¸ÇÔÚÒÑ¾­¸ÉºÔµÄºşµ×¡£\n",
	           "salt rock": "ºñºñµÄÒ»²ãÑÎ°ÍÆÌ¸ÇÔÚÒÑ¾­¸ÉºÔµÄºşµ×¡£\n",
	           "salt": "ºñºñµÄÒ»²ãÑÎ°ÍÆÌ¸ÇÔÚÒÑ¾­¸ÉºÔµÄºşµ×¡£\n",
        ]));
	//set("no_pk",1);
	
	
        set("outdoors", "xinjiang");
		set("coor/x",50);
		set("coor/y",-60);
		set("coor/z",10);
		setup();
}


void dig_notify()
{
     object me, salt;
     me = this_player();     
          
     message_vision("$NÔÚºşµ×¿ªÊ¼Ã¦ÂÒµØÍÚ¾òÆğÀ´¡£\n",me);
     
    if (!me->query_temp("marks/xj_noticed_salt")) {
    	tell_object(me,"ÂşÎŞÄ¿µÄµØÍÚÁË°ëÌì£¬ÔËÆøÕæ²»ºÃ£¬Ê²Ã´¶¼Ã»ÓĞÕÒµ½¡£\n");
    	return;
    }
     
     if(query("already")) {
     	tell_object(me,"ÄÜÍÚ¶¯µÄÑÎ°Í¶¼ÒÑ¾­±»ÍÚÍêÁË¡£\n");
     	return ;
     }
     
     message_vision("ïÏ£®£®µÃÒ»Éù£¬ÔÙ¿´µØÉÏµÄÑÎ°Í±»$NÔÒÏÂÒ»Ğ¡¿é¡£\n", me);
     salt = present("salt rock", this_object());
     if(!objectp(salt)) {
        salt = new(__DIR__"obj/salt");
        salt->move(this_object());
     }
	set("already",1);
}


void reset(){
	::reset();
	if (!random(20))
		set("already",0);
}
