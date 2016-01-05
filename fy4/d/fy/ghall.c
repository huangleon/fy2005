inherit DOOR_ROOM;
#include <room.h>

void create()
{
    set("short", "½ðÊ¨ïÚ¾Ö´óÌü");
    set("long", @LONG
´óºì[33mµØÌº[32mÒÀ¾É£¬ÕäÆæ¹ÅÍæ£¬¸ßÐü×Ö»­£¬±íÃ÷ÕâÀïµÄÖ÷ÈË²»µ«ÐÔÇéºÀË¬£¬¹ã½»Åó
ÓÑ£¬ÇÒ·Ç´ó×Ö²»Ê¶£¬Ä¿ÖÐÎÞÈËÖ®±²¡£ÉÏÊ×Ò»Ê¨Æ¤½»ÒÎ£¬×óÓÒ¸÷Ã÷ÖòÉÁË¸¡£Ò»ÉîÉ«¹Å
Ä¾Êé°¸ºáÓÚÒÎÇ°£¬ÉÏÃæÕûÆëµÄ¶Ñ×ÅÒ»¾í¾íïÚ¾ÖÑºïÚµÄ»õÆ±¡£Ïò±±Ò»µÀÌúÃÅ¡£
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"goldlion",
	"east" : __DIR__"ginhall",
	"north" : __DIR__"gmoney",
      ]));
    set("objects", ([
	__DIR__"npc/gmaster" : 1,
      ]) );

    set("item_desc", ([
	"×Ö»­":		"Õâ×Ö»­¡£¡£¡£ÂíÂí»¢»¢°É£¬´ó²¿·ÖÊÇÁÙÄ¡µÄ¡£\n",
	"Ê¨Æ¤½»ÒÎ":	"ÕâÊÇïÚ¾Ö×ÜïÚÍ·²éÃÍ×î°®×øµÄÒÎ×Ó£¬´òÉ¨µÃ¸É¸É¾»¾»¡£\n",
	"ÕäÆæ¹ÅÍæ":	"ÕâÊÇ²éÃÍ¶þÊ®¶àÄê»ýÔÜÏÂÀ´µÄ¡£\n",
	"Êé°¸":		"Êé°¸ºáÓÚÒÎÇ°£¬ÉÏÃæÕûÆëµÄ¶Ñ×ÅÒ»¾í¾íïÚ¾ÖÑºïÚµÄ»õÆ±¡£\n",
      ]));

    set("coor/x",180);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    create_door("north", "door","ÌúÃÅ", "south", DOOR_CLOSED);

}

void init(){
    add_action("do_look","look");
}


int do_look(string arg){
    object me;

    me = this_player();


    if (arg == "µØÌº" || arg == "rag" || arg == "carpet" || arg == "´óºìµØÌº") {
	if (this_player()->query_temp("marks/js_cook_mice") < 3) {
	    tell_object(this_player(),"´óÌüµÄµØÃæÉÏÆÌ×Å´óºìµØÌº£¬°ÑÎÝ×ÓÀïµÄÆø·ÕºæÍÐµÃÅ¯ÑóÑóµÄ¡£\n");
	    return 1;
	}
	tell_object(this_player(),"´óÌüµÄµØÃæÉÏÆÌ×Å´óºìµØÌº£¬°ÑÎÝ×ÓÀïµÄÆø·ÕºæÍÐµÃÅ¯ÑóÑóµÄ¡£\n");
	tell_object(this_player(),"Ææ¹ÖµÄÊÇ£¬¸É¸É¾»¾»µÄÌº×ÓÉÏµôÁË¼¸Á£Ã×·¹¡£\n");
	this_player()->set_temp("marks/js_cook_mice",4);
	return 1;
    }

    return 0;
}
