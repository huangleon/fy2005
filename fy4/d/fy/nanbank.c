// inn.c

inherit ROOM;


void create()
{
    set("short", "ÄÏ¹¬Ç®×¯");
    set("long", @LONG
ÖĞÔ­ÄÏ¹¬ÊÀ¼Ò£¬¼Ò²ÆÍò¹á£¬²úÒµ²»¿ÉÊ¤Êı¡£´Ë¼äÇ®×¯ºÚØÒºì×Ö£¬ÕıÊÇÄÏ¹¬²úÒµÖ®
Ò»¡£ÄÏ¹¬Ç®×¯µÄÒøÆ±ĞÅÓş¼«ºÃ£¬´ó½­ÄÏ±±¶¼¿É¶ÒÏÖ¡£¾ÍÊÇ¸»¿ÉµĞ¹úµÄ½ğÇ®°ï£¬Ò²ÄÑÍû
ÆäÏî±³¡£Ç®×¯ÖĞÑëÓĞÒ»ºìÄ¾¹ñÌ¨£¬°ëÈË¶à¸ß£¬ÉÏÓĞÅÆ£¨£ó£é£ç£î£©Ò»¿é¡£
[31m
                	ÄÏ¹¬Ç®×¯
[37m
LONG
    );

    set("exits", ([
	"south"      : __DIR__"wcloud2",
      ]) );
    set("item_desc", ([
	"sign": @TEXT
ÕâÀïÊÇÇ®×¯£¬Ä¿Ç°ÎÒÃÇÌá¹©µÄ·şÎñÓĞ£º

convert     ¶Ò»»Ç®±Ò
withdraw    ÌáÈ¡´æ¿î
deposit     ´æÈëÇ®±Ò
balance     ²éÑ¯´æ¿îÊı¶î
loan	    ÏòÇ®×¯½èÇ®
transfer    Ö±½Ó×ªÕÊ

TEXT
      ]) );


    set("objects", ([
	__DIR__"npc/bankowner" : 1,

      ]) );

    set("coor/x",-120);
    set("coor/y",20);
    set("coor/z",0);
    set("map","fywest");
    setup();
}
