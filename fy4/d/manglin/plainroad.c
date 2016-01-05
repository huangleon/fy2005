//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "Æ½Ô­Â·");
	set("long", @LONG
´óµÀ×Ô±±ÏòÄÏ£¬µØÊÆ½¥Æ½¡£Â·ÃæÆÌ×ÅĞ¡Ê¯×Ó£¬Ò»ÌõÌõ³µºÛÏòÄÏ·½ºÍ±±·½ÉìÕ¹£¬
¹â½Å×ßÔÚÉÏÃæ£¬¾õµÃÆÄÎªíÑ½Å¡£µÀÁ½ÅÔµÄÊ÷Ä¾Ô½À´Ô½ÉÙ£¬½¾ÑôËÆ»ğ£¬ÕæÏëÕÒ¸öµØ·½
ĞİÏ¢Ò»ÏÂ¡£Î÷ÃæµÄÖ§Â·ÊÇÖøÃûµÄ·çÔÆµÀ£¬òêÑÑÊı°ÙÀïÒ»Ö±Í¨Ïò[33m³ÁÏãÕò[32m¡£
LONG
	   );
	set("exits", 
	   ([ 
	     	"north" : __DIR__"woodsroad",
	     	"south" : __DIR__"southsearoad",
         	"west" : AREA_CHENXIANG"fydao3",
	    ]));
	set("outdoors", "baiyun");
	set("NONPC",1);
	set("coor/x",60);
	set("coor/y",-220);
	set("coor/z",10);
	setup();
}
