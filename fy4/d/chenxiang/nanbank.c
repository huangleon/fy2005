// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
	set("short", "³ÁÏãÄÏ¹¬");
	set("long", @LONG
ÖĞÔ­ÄÏ¹¬ÊÀ¼Ò£¬¼Ò²ÆÍò¹á£¬²úÒµ²»¿ÉÊ¤Êı¡£´Ë¼äÇ®×¯ºÚØÒºì×Ö£¬ÕıÊÇÄÏ¹¬²úÒµ
Ö®Ò»¡£ÄÏ¹¬Ç®×¯µÄÒøÆ±ĞÅÓş¼«ºÃ£¬´ó½­ÄÏ±±¶¼¿É¶ÒÏÖ¡£¾ÍÊÇ¸»¿ÉµĞ¹úµÄ½ğÇ®°ï£¬Ò²
ÄÑÍûÆäÏî±³¡£Ç®×¯ÖĞÑëÓĞÒ»ºìÄ¾¹ñÌ¨£¬°ëÈË¶à¸ß£¬ÉÏÓĞÅÆ£¨£ó£é£ç£î£©Ò»¿é¡£
[31m
                	ÄÏ¹¬Ç®×¯
[37m
LONG
	);
	
	set("exits", ([
		"east"    	: __DIR__"cxcenter",
	]) );
        set("item_desc", ([
                "sign": @TEXT
ÕâÀïÊÇÇ®×¯£¬Ä¿Ç°ÎÒÃÇÌá¹©µÄ·şÎñÓĞ£º

convert     ¶Ò»»Ç®±Ò¡£
withdraw    ÌáÈ¡´æ¿î¡£
deposit     ´æÈëÇ®±Ò¡£
balance     ²ìÑ°´æ¿î¡£
loan        ÏòÇ®×¯½èÇ®¡£
TEXT
        ]) );


	set("objects", ([
		__DIR__"npc/bankowner" : 1,

			]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
