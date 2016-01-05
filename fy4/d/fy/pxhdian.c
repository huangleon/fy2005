inherit ROOM;
void create()
{
    set("short", "Æ®Ïã»¨µê");
    set("long", @LONG
¾­¹ýÁËÕâÃ´¶àÄê£¬ÕâÀïËÆºõÒ»µã¶¼Ã»ÓÐ¸Ä±ä£¬ÈËÀ´ÈËÍù²»¶Ï¡£Î´Èë´Ë´¦£¬ÇåÐÂ
µÄ»¨ÏãÒÑÇßÈËÐÄÆ¢¡£µêÖÐ¸÷ÖÖÃû»¨£¬ÁáÀÅÂúÄ¿£¬²»·¦ÕäÆæÒìÖÖ¡£À´¿Í²»·Ö¸ßµÍ¹ó¼ú£¬
ÕâÀïµÄÖ÷ÈË×ÜÊÇÐ¦Á³ÏàÓ­¡£Ðí¶à³ÇÖÐµÄÄêÇàÈË¶¼Ï²»¶ÔÚÕâ¶ù¶ºÁô£¬ÅÎÓÐÒ»ÌìÌÒ»¨ÔË
»á½µÁÙÔÚÉíÉÏ¡£¾ÝÕâÀïµÄÀÏ°åËµ£¬ÔÚÆ®Ïã»¨µê½á³ÉµÄÁ¼ÔµÒÑ²»¿ÉÊ¤Êý¡£µêÃÅ¿ÚºìÖ½
ÌùÁËÕÅ¸æÊ¾£¨£ó£é£ç£î£©¡£
LONG
    );
    set("exits", ([
	"west" : __DIR__"swind31",
      ]));
    set("objects", ([
	__DIR__"npc/flowerseller": 1,
      ]) );
    set("item_desc", ([
	"sign": @TEXT
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;31m	¹Ø¹ØöÂð¯£¬ÔÚºÓÖ®ÖÞ¡£ñºñ»ÊçÅ®£¬¾ý×ÓºÃåÏ¡£[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
             
±¾»¨µêÃÉ¸÷·½»Ý¹Ë£¬ÉúÒâÐËÂ¡£¬ÏÖÈ±Èô¸ÉÈËÊÖËÍ»¨¸÷µØ£º
´ËµØ¿ÉÖ´ÐÐµÄÃüÁî£º

1¡£[37mdelivery[32m
°´¹ËÖ÷ËùÍÐ£¬ÔÚ¹æ¶¨Ê±¼äÄÚËÍ»¨¸øÖ¸¶¨¹ó¿Í£¬·²½ÓÊÖÕßÐëÔ¤¸¶¶¨½ðÒ»Òø£¬
´ÓÒøÐÐ×Ô¶¯×ªÕË¡£
2¡£[37mask hua mancheng about deposit[32m
Íê³ÉËÍ»¨ºó£¬¿ÉÏòµêÖ÷»¨Âú³ÇÑ¯ÎÊÈ¡»Ø¶¨½ð£¬×Ô¶¯×ªÈëÄãµÄÕËºÅ¡£
3¡£[37mcancel delivery[32m
ÈôÊÇÒò¸÷ÖÖÔ­ÒòÎÞ·¨Íê³É½ÓÊÖÖ®Ôð£¬¿ÉÈ¡ÏûÕâ´ÎÈÎÎñ¡£
             
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m             
TEXT
      ]) );
    set("no_fight",1);
    set("no_magic",1);
    set("NONPC", 1);
    set("coor/x",20);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();

}
