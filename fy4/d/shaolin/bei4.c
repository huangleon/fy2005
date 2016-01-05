// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "±®ÁÖ");
        set("long", @LONG
´Ë±®´ó¶àÊı¼ÇÊö×ÅÉÙÁÖÎäÑ§£¬ÆäÖĞ³ÌÉÜÌâ¡°[33mÉÙÁÖ¹ÛÎä[32m¡±Ê«±®£¬Çå¡°[33mÎ÷À´ÌÃÖ¾ÉÆ
±®[32m¡±¶¼¼ÇÊöÁËÉÙÁÖÎäÑ§µÄĞÎÉñËùÔÚ£¬Ï°ÎäÖ®ÈËµ½´ËÎŞ²»×¢Ä¿ÄıÉñ£¬ÏêÏ¸ÑĞ¾¿£¬ÒÔÆÚ
ÁìÎòÈô¸É¡£¹ıÁË¶«±®ÁÖ£¬±ãÊÇ´ÈÔÆÌÃ¡£
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bei3",
  "east" : __DIR__"ciyun",
]));
        set("objects", ([
                BOOKS"skill/dabei_50" : 1,
                BOOKS"unarmed_50a" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
}
