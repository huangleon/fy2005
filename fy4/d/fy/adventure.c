inherit ROOM;

void create()
{
    set("short", "ðÐðÄ¸ó");
    set("long", @LONG
Ò»¼äÆÕÆÕÍ¨Í¨µÄµêÆÌ£¬ÕÐÅÆÉÏÖ»ÓÐ¼ò¼òµ¥µ¥µÄ¡°ðÐðÄ¸ó¡±Èý×Ö£¬ÔÚÕâ·±»ªµÄÎ÷
ÊÐ¿Ú£¬ÏÔµÃÓÐÐ©¸ñ¸ñ²»Èë¡£ðÐðÄ¸ó²¢²»ÊÇÉÍÄñµÄµØ·½£¬¼È²»ÊÇµ±ÆÌ£¬Ò²²»ÊÇÇ®×¯£¬
¸ü²»ÊÇ¾ÆÂ¥£¬¶øÊÇÂôÒ»Ð©Ï¡Ææ¹Å¹ÖµÄ¶«Î÷£¬¾ÝËµ¶¼ÊÇÖ÷ÈËµ±ÄêÓÎÀúËÄ·½ËùÃÙµÃ£¬Ïë
Òª´³µ´½­ºþµÄÄêÇáÈËÃÇ£¬³£³£µ½ÕâÀïÀ´¹ºÂòÒ»Ð©³öÓÎµÄ±Ø±¸ÎïÆ·£¨£ó£á£í£ð£ì£å¿É
ÒÔ²é¿´ÕýÔÚ´ýÊÛÎïÆ·µÄÊôÐÔ£©¡£ðÐðÄ¸óÀïÆ½ËØÖ»ÓÐÒ»¸öÑÛ¾¦ºÜ´óµÄÐ¡¹ÃÄï£¬ÒÐ×Å¿é
ÅÆ×Ó£¨£ó£é£ç£î£©³öÉñ¶ù¡£
LONG
    );

    set("exits", ([
	"south"      : __DIR__"wcloud1",
      ]) );
    set("item_desc", ([
	"sign": @TEXT
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36m		ðÐðÄ¸óÌá¹©ÒµÎñ[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

1¡£Ï¡ÓÐ¾íÖá£º¶àÉÙÄêÀ´½­ºþÐÈ·çÑªÓê£¬ÖÐÔ­¸÷´óÃÅÅÉµÄÐí¶àÎä¹¦ÃØ
¾÷¶¼ÄªÃûÆäÃîµØÊ§´«ÁË£¬¾ÝËµºÃ¶àÁ÷Ê§µ½Ò»Ð©ÏÕ¶ñµÄÄ§Í·ÊÖÀï£¬ÒªÏë
µÃµ½¿ÉÒªÃ°ÉÏÉúÃüÎ£ÏÕ¡£ðÐðÄ¸óÎªÄúÌá¹©×î¼ÑÄ¡±¾£¬Ð§¹û¾ø¶ÔÒ»Á÷£¬
¼ÛÇ®¾ø¶Ô°º¹ó¡££¨°×ÔÆµº·Öµê¾­Óª£©

2¡£²Æ²ú±£ÏÕ£ºÔÚ½­ºþÉÏÌòµ¶Í·¹ýÈÕ×ÓµÄ£¬Ãâ²»ÁËÓÐÐ©ÉÁÊ§£¬ÕâÎä¹¦
´òÁËÕÛ¿Û»¹ÄÜ¹»ÔÙÁ·£¬ÐÁÐÁ¿à¿à×¬µ½µÄ²ÆÎïµôÁË¿ÉÔõÃ´°ì¡£¸óÖ÷¶Ô´Ë
ÉîÓÐÌå»á£¬¹Ê¿ªÁË²Æ²ú±£ÏÕÒ»Òµ¡£¸¶ÉÏÒ»µã¶ù½ð×Ó£¨ÎåÁ½£©£¬±ã¿ÉÒÔ
½«Éí±ßµÄ¶«Î÷±£ÉÏÈýÌì¡£(ask shangguan xuer about ²Æ²ú±£ÏÕ)£¬Ä¿
Ç°ðÐðÄ¸ó³Ð±£µÄ·¶Î§°üÀ¨£º
£¨1£©µØÓüÂþÓÎ£¨³öÁËÒâÍâÎïÆ·½«ËæÉí¸úËæ£©
£¨2£©³öÍâÂÃÓÎ£¨Õ½¶·ÖÐÌÓÅÜ½«²»»á¶ªÊ§ÎïÆ·£©
£¨3£©µÛÍõ¹È¡¢ÀÇÉ½ÏÕÇø²ÆÎï±£ÏÕ

3¡£ÐþÁéÓñºÐ£º¸æ±ð´óÃ×£¡¸æ±ð¶ÏÏßµÄÓÇÂÇ£¡ÐþÁéÓñºÐÊÇÄãÍê³ÉÌì»ú
ÀÏÈËÈÎÎñµÄ×î¼ÑÅÄµµ£¡£¨ask shangguan xuer about treasurebox£©
¾ßÌåÊ¹ÓÃ·½·¨Çë²Î¼û£è£å£ì£ð¡¡£ç£á£í£åÖÐµÄÌì»úÊ¹ÃüÆª£¬ÒÔ¼°ÐþÁé
ÓñºÐµÄ×Ô´øËµÃ÷¡£

£´¡£´óÐ¡ÐÐÄÒ£ºÆ·ÖÖ¶àÑù£¬ÈÎÄúÑ¡Ôñ£¡

£µ¡£ÕýÔÚÀ©Õ¹ÖÐ£¡


[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
TEXT
      ]) );

    set("objects", ([
		__DIR__"npc/snow" : 1,

     ]) );

    set("coor/x",-80);
    set("coor/y",10);
    set("coor/z",0);
    set("map","fywest");
    setup();
}
