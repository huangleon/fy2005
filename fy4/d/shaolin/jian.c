// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "É®¼à");
        set("long", @LONG
Ò»´¦ÇåÓÄËùÔÚ£¬Èç²»ÊÇÃÜÃÜµÄµÄ[33mÌúÀ¸[32m£¨£â£á£ò£ó£©£¬Ò²Ïë²»µ½ÕâÊÇ¼àÓü£¬ÕâÀï
Çô½ûµÄ¶¼ÊÇÉÙÁÖµÄ°ÜÀà»òÕß´³ÉÙÁÖµÄÐ°Í½£¬ÄÜ±»¹Ø½øÕâÀïµÄ¶¼ÊÇ·Ç·²Ö®ÈË£¬¿ÉÏ§Æ·
ÐÐ²»¶Ë£¬ËÄ³¤ÀÏÃ¿ÈÕÔçÍí¶¼ÒªÄîËÌ½ð¸Õ¾­¼ÓÒÔµã»¯£¬ÒÑÓÐ²»ÉÙÈËÓÉ´Ë¸Ä¶ñ´ÓÉÆ£¬ò¯
ÐÄÏò·ð¡£
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"laon",
  		"south" : __DIR__"laos",
  		"west": __DIR__"lao",
  		"east" : __DIR__"laoe",
		]));
        set("objects", ([
                __DIR__"obj/mantou" : 2,
                __DIR__"obj/purewater" : 2,
				BOOKS"skill/daode_50" : 1,
       	]) );
		set("NONPC", 1);
		set("coor/x",20);
		set("coor/y",120);
		set("coor/z",20);
		setup();
}

void init()
{
	if(this_player()->query_skill("daode",1) < 10)
		this_player()->set("startroom", base_name(this_object()));

}
