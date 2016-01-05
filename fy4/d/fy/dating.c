inherit ROOM;
void create()
{
    set("short", "Òø¹³¶Ä·»´óÌü");
    set("long", @LONG
Ò»ÑÛ¿´¹ýÈ¥£¬Õâ´óÌüÀïÕæÊÇ½ð±Ì»Ô»Í£¬ÌÃ»Ê¸»Àö£¬Á¬ÖòÌ¨¶¼ÊÇ´¿ÒøµÄ£¬ÔÚÕâÖÖ
µØ·½ÊäÁËÇ§¶ù°Ë°ÙÁ½½ð×Ó£¬Ã»ÈË»á¾õµÃÔ©Í÷¡£´óÌüÀï°ÚÂúÁË´ó´óÐ¡Ð¡µÄ¶Ä×À£¬Ö»Òª
ÄÜËµ³öÃûÌÃµÄ¶Ä¾ß£¬ÕâÀï¶¼ÓÐ¡£ÓÐØÒ£¨£ó£é£ç£î£©Ò»¿é¡£
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"pianting",
	"north" : __DIR__"yingou",
      ]));
    set("item_desc", ([
	"sign": @TEXT
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;31m		Ð¡¶Ä¿É°²¼Ò£¬´ó¶Ä¿É¶¨°î[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
             
÷»×ÓµÄ¶Ä·¨£º

£â£å£ô¡¡£¼ÖÖÀà£¾¡¡£¼ÒøÁ¿£¾

ÖÖÀà£º¡¡£°£¬£±£¬£²£¬£³µ½£±£¸
£°£º¡¡		¶ÄÐ¡	£¨£³£­£±£°£©	Ò»ÅâÒ»
£±£º  		¶Ä´ó	£¨£±£±£­£±£¸£©	Ò»ÅâÒ»
£²£º¡¡		¶ÄÎ§÷»	£¨ÈýÁ£÷»×ÓÍ¬µã£©Ò»ÅâÈýÊ®Áù
£³£­£±£¸	¶Äµ¥µã  		Ò»Åâ°Ë

Àý×Ó£º
£â£å£ô¡¡£°¡¡£µ£°
¶ÄÎåÊ®Á½ÔÚÐ¡ÉÏ
             
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m             
TEXT
      ]) );

    set("objects", ([
	__DIR__"npc/dice_thrower" : 1,
	BOOKS"steal_30" : 1,
      ]) );
    set("NONPC",1);
    set("coor/x",-160);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fywest");
    setup();
}

void init(){
    object me;
    me = this_player();
    if( me->query("gamble/amount")) {
		tell_object(me, "ÄãÉÏ´ÎÖÐÍ¾ÁïºÅ£¬¶ÄÆ·Ì«²îÁË¡£\n");
		me->delete("gamble/amount");
		if (me->query_skill("betting",1))
		    me->decrease_skill("betting",1);
    }
}

void reset(){
    object obj;
    ::reset();
    if(!present("stealingbook", this_object())){
	obj = new(__DIR__"npc/obj/stealingbook");
	if(objectp(obj)){
	    if(!obj->move(this_object()))
		destruct(obj);
	}
    }
}
