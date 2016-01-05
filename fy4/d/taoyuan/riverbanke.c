inherit __DIR__"no_killing_place";

void create()
{
    set("short", "ÌÒÔ´Í¤");
    set("long", @LONG
ËÄÖÜµÄ²ÝÆºÐÞ¼ôµÃºÜÕûÆë£¬ÑØ×ÅºÓ°¶Éú³¤×ÅÒ»Ð©Ë®ÉúÖ²Îï£¬ÓÐ¸¡Æ¼£¬Ë®ÏÉ£¬»¹
ÓÐ¼¸´ÔÂ«Î­£¬²ÝÆºÖÐÑëÊÇÒ»×ù[37mÍ¤Ì¨[32m£¬²»Ô¶´¦µÄ²ÝÆºÉÏ´íÂäÓÐÖÂµØ°Ú×ÅÓÐÉ½Ê¯Ê÷Ä¾£¬
ÔÙ¹ýÈ¥¾ÍÊÇÒ»×ù°×Ç½·ÛÍßµÄÐ¡Í¥Ôº¡£¼¸¿ÃÐÞÖñ´Ó·ÛÇ½ÉÏÌ½³öÍ·Ëæ·çÔÆÒ¡¶¯£¬ËÄÖÜ¾²
ÇÄÇÄµÄ£¬Å¼¶ûÄÜÌýµ½ºÓÎ÷´«À´µÄ¹·½ÐÉù¡£
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"bridge",
        ]));

	set("objects", ([
		__DIR__"npc/tingzhu" : 1,
	]) );
	
	set("item_desc", ([
		"Í¤Ì¨" : "ÕâÀïÊÇ·çÔÆÖÐÖ¾Í¬µÀºÏÖ®Ê¿½áÒåµÄµØ·½¡£
£ª½áÒå£¨£ê£é£å£ù£é£©£ºÒªÇóÄÐ£±£´¡¢Å®£±£²ÒÔÉÏ£¬²»ÏÞÄÐÅ®
£ª½â³ý½áÒåÖ®Çé£ºÓÐÁ½ÖÖÍ¾¾¶
£¨£±£©¸îÅÛ¶ÏÒå£¨£ê£õ£å£ê£é£á£ï£©£ºÒªÇóË«·½ÔÚ³¡
£¨£²£©±³Æú£¨£â£å£ô£ò£á£ù£©£º
µ±Ò»·½ÍË³ö·çÔÆ£¨Èç×ÔÉ±¡¢ÇåµµµÈ£©»ò³¤ÆÚ²»ÔÚÏß£¨£¶£°ÌìÒÔÉÏ£©£¬
ÔòÁíÒ»·½¿Éµ¥·½Ãæ½â³ý½á°ÝÖ®Çé¡£¾ßÌåÇë²Î¿´ÓÐ¹Ø°ïÖúÎÄ¼þ¡£	\n\n",
		"pavilion" : "ÕâÀïÊÇ·çÔÆÖÐÖ¾Í¬µÀºÏÖ®Ê¿½áÒåµÄµØ·½¡£
£ª½áÒå£¨£ê£é£å£ù£é£©£ºÒªÇóÄÐ£±£´¡¢Å®£±£²ÒÔÉÏ£¬²»ÏÞÄÐÅ®
£ª½â³ý½áÒåÖ®Çé£ºÓÐÁ½ÖÖÍ¾¾¶
£¨£±£©¸îÅÛ¶ÏÒå£¨£ê£õ£å£ê£é£á£ï£©£ºÒªÇóË«·½ÔÚ³¡
£¨£²£©±³Æú£¨£â£å£ô£ò£á£ù£©£º
µ±Ò»·½ÍË³ö·çÔÆ£¨Èç×ÔÉ±¡¢ÇåµµµÈ£©»ò³¤ÆÚ²»ÔÚÏß£¨£¶£°ÌìÒÔÉÏ£©£¬
ÔòÁíÒ»·½¿Éµ¥·½Ãæ½â³ý½á°ÝÖ®Çé¡£	¾ßÌåÇë²Î¿´ÓÐ¹Ø°ïÖúÎÄ¼þ¡£\n\n",
		"ting" : "ÕâÀïÊÇ·çÔÆÖÐÖ¾Í¬µÀºÏÖ®Ê¿½áÒåµÄµØ·½¡£
£ª½áÒå£¨£ê£é£å£ù£é£©£ºÒªÇóÄÐ£±£´¡¢Å®£±£²ÒÔÉÏ£¬²»ÏÞÄÐÅ®
£ª½â³ý½áÒåÖ®Çé£ºÓÐÁ½ÖÖÍ¾¾¶
£¨£±£©¸îÅÛ¶ÏÒå£¨£ê£õ£å£ê£é£á£ï£©£ºÒªÇóË«·½ÔÚ³¡
£¨£²£©±³Æú£¨£â£å£ô£ò£á£ù£©£º
µ±Ò»·½ÍË³ö·çÔÆ£¨Èç×ÔÉ±¡¢ÇåµµµÈ£©»ò³¤ÆÚ²»ÔÚÏß£¨£¶£°ÌìÒÔÉÏ£©£¬
ÔòÁíÒ»·½¿Éµ¥·½Ãæ½â³ý½á°ÝÖ®Çé¡£	¾ßÌåÇë²Î¿´ÓÐ¹Ø°ïÖúÎÄ¼þ¡£\n\n",
	]) );
	
	set ("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",70);
	set("coor/y",0);
	set("coor/z",0);
    setup();

}


