
inherit ROOM;

void create()
{
	set("short", "Ğ¡Õò");
	set("long", @LONG
Ğ¡Õò²»ÊÇºÜ´ó£¬µ«È´ºÜ·±»ª¡£ÒòÆäÔÚÎäµ±É½½Å£¬ÕòÖĞ¼ÈÊ¹¼¸ËêĞ¡Í¯£¬Ò²»á¼¸ÕĞ
Ì«¼«È­¡£Ğ¡Õò¶«±ßÊÇÌÒ»¨ÁÖ£¬ÌÒ»¨ÁÖºó¾İËµ»¹ÓĞ¸öĞ¡´å£¬µ±µØÈË½Ğ×ö[33mÌÒÔ´´å[32m£¬´åÈË
ÉõÉÙ³öÍâ×ß¶¯£¬Ò²²»ÖªÈë¿ÚÔÚÄÇÀï¡£Ğ¡ÕòÔÙÏòÄÏ£¬¾ÍÊÇ¶¦¶¦´óÃûµÄ[33mÎäµ±É½[32m¡£
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"xzroad1",
		"north" : __DIR__"bwuroad2",
		"east" : AREA_TAOYUAN"taolin",
	]));
	set("outdoors", "wudang");
	set("objects", ([ 
		__DIR__"npc/xiaotong": 2 
	]) );
	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
