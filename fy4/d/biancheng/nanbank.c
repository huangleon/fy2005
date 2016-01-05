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
[32m
LONG
    );

    set("exits", ([
	"west"      : __DIR__"nstreet1",
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

    set("coor/x",0);
    set("coor/y",10);
    set("coor/z",0);
    set("map","biancheng");
    setup();
}
