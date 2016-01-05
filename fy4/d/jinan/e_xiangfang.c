inherit ROOM;
void create()
{
        set("short", "¶«Ïá·¿");
        set("long", @LONG
¶«Ïá·¿ÊÇÑÃÃÅ´óÐ¡¹ÙÔ±·¢²¼ÎÄ¸æ£¬´¦ÀíÈÕ³£ÊÂÎñµÄËùÔÚ¡£·çÔÆÉç»áÁúÉß»ìÔÓ¡¢
Á¼Ý¬²»Æë¡¢³ÖÇ¿ÐÐÐ×±È±È½ÔÊÇ£¬¶øÒÔÍù¹Ù¸®ÎÞÁ¦¹ÜÏ½£¬ÒÔÖÁÊÀ·çÈÕÏÂ£¬ÒóÕýÁ®Àø¾«
Í¼ÖÎ£¬´Ó½­ºþÉÏÆ¸ÇëÃûÃÅ¸ßÊÖµ£ÈÎ²¶¿ì£¬¸ü½¨Á¢ÁËÒ»Ì×ÑÏÀ÷µÄÂÉÖÎÖÆ¶È¡£½øÃÅµÄºì
Ä¾ÆÁ·çÉÏÌù×ÅÒ»ÕÅ´ó´óµÄ¸æÊ¾£¨£ó£é£ç£î£©
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"govern",
	]));
        set("objects", ([
        	__DIR__"npc/butou1" : 1,
        	__DIR__"npc/shiye1" : 1,
        ]) );
	set("item_desc", ([
                "sign": @TEXT
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36m		·çÔÆ¼©ÄÃ²¶É±¹«¸æ[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

£¨1£©ÑÏ½ûÈÎºÎ¹Ù¸®ºË×¼ÒÔÍâµÄ³ðÉ±£¬Ñ²²¶ºÍÌÓ·¸²»ÊÜ¹Ù¸®¹ÜÏ½£¬
    ¿ÉÏà»¥×·É±¡£

£¨2£©¼ÓÈëÑ²²¶·½·¨£º
	Îä¹¦´ïµ½Ò»¶¨¾³½ç£¨£²£°¼¶£©ºó¿ÉÏòÐÏÈñÑ¯ÎÊÑ²²¶Ò»ÊÂ£¬ÈôÂú
	×ãÌõ¼þÔò¿É¼ÓÈëÑ²²¶µÄ¶ÓÎé¡£µ«½­ºþÏÕ¶ñ£¬×Ô¼ºÒ²¿ÉÄÜ»á±»Æä
	ËûÌÓ·¸»òÑ²²¶°µËã¡£Ñ²²¶Ã¿ÈÎ³ÖÐøÆßÌì£¬ËÀÍö»òÆÚÂúºó×Ô¶¯Àë
	ÈÎ¡£
	
£¨3£©Í¨¼©ÌÓ·¸·½·¨£º
	°ì°¸Ê¦Ò¯¸ºÔð·¸ÈËÔÚ°¸¼ÍÂ¼£¬Ö»Òª³öµÄÆðÉÍ½ð£¬¾ÍÄÜ½«ÈÎºÎÈË
	ÁÐÈëÃûµ¥£¬Ã¿´ÎÍ¨¼©ÓÐÐ§Ê±¼äÎª¶þÊ®ËÄÐ¡Ê±×óÓÒ£¬ÌÓ·¸±»»÷±Ð
	»òÓâÊ±Í¨¼©Áî×Ô¶¯È¡Ïû¡£»÷±ÐÌÓ·¸Õß£¨Ñ²²¶»òÆäËûÌÓ·¸£©¿ÉµÃ
	µ½ÐüÉÍ½ð¶îµÄ£¹£°£¥£©
	
£¨4£©ÓÐ¹ØÃüÁî£º
	xunbu£º		ÔÚÐÏÈñ´¦²éÑ¯ËùÓÐ²¶¿ìÃûµ¥
	fugitive:	ÔÚ°ì°¸Ê¦Ò¯´¦²éÑ¯ËùÓÐÌÓ·¸Ãûµ¥

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
TEXT
        ]) );	
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
