
inherit ROOM;

void create()
{
    set("short", "ÕÅ¼ÒÌúÆÌ");
    set("long", @LONG
·çÔÆÀÏÉÙ¶¼Ï²»¶ÔÚÕâÀï´òÔì³ÆÊÖµÄÌúÆ÷£¬´Ó»ðÂ¯ÖÐÃ°³öµÄ»ð¹â½«Ç½±ÚÓ³µÃÍ¨ºì£¬
ÎÝ×ÓµÄ½ÇÂäÀï¶ÑÂúÁË¸÷Ê½ÌúÆ÷£¬³úÍ·¡¢Ìú´¸¡¢²ù×Ó¡¢³¤½£µÈ£¬ÓÐµÄÒÑ¾­Íê¹¤£¬ÓÐµÄ
»¹Ö»ÊÇ¸ö´ÖÄ££¬¶£¶£µ±µ±´òÌúµÄÉùÒôÂúÎÝ×ÓÏì¡£ÃÅ¿ÚÓÐÒ»¸ö´óÄ¾ÅÆ£¨£ó£é£ç£î£©¡£
LONG
    );
    set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"huanyun8",
      ]));

    set("objects", ([
	__DIR__"npc/smith": 1 ]) );
    set("item_desc", ([
	"sign": @TEXT
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36m		±¾ÌúÆÌÌá¹©ÒµÎñ[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

£¨1£©ÐÞ²¹ÎäÆ÷£¨£ø£é£õ£©£º
* ×ÔÖÆÎäÆ÷Ã¿µãÒ»Á½»Æ½ð£®µ«²»»á³¬¹ýÎäÆ÷ÉËº¦Á¦µÄËÄ·ÖÖ®Ò»¡£
* ·Ç×ÔÖÆÎäÆ÷£¬ÉËº¦Á¦25ÒÔÏÂÍ³ÊÕÒ»Á½»Æ½ð£¬25ÒÔÉÏÃ¿µãÈýÁ½»Æ½ð¡£

£¨2£©¹À¼Û£¨£å£ó£ô£é£í£á£ô£å£©
¹ÀËãÐÞÀíÎäÆ÷ËùÐèÒªµÄ½ð¶î¡£

£¨3£©¶©×÷×ÔÖÆÎäÆ÷£¨£ä£é£î£ç£©£ºÃ¿¼þÊ®Á½»Æ½ð

¸«£¨£á£ø£å£©£¬µ¶£¨£â£ì£á£ä£å£©£¬´¸£¨£è£á£í£í£å£ò£©£¬
Ã¬£¨£ó£ð£å£á£ò£©£¬ÕÈ£¨£ó£ô£á£æ£æ£©£¬½££¨£ó£÷£ï£ò£ä£©£¬
±Þ£¨£÷£è£é£ð£©

£ä£é£î£ç <ÎäÆ÷ÖÖÀà> <ÑÕÉ«> <ÎäÆ÷ÖÐÎÄÃû> <ÎäÆ÷Ó¢ÎÄÃû>

Àý×Ó£º
£ä£é£î£ç¡¡£ó£÷£ï£ò£ä¡¡$£È£É£Ç$ ±ÌÑª½£ £â£ì£ï£ï£ä£ù

ÕÅÌú½³¾Í»áÓÃËû×Ô±¸µÄ²ÄÁÏ°ïÄã×÷Ò»¼þ·¢ÂÌÉ«µÄ£¢±ÌÑª½££¢ 
½Ð £â£ì£ï£ï£ä£ù

$BLK$ - ºÚÉ«            $NOR$ - »Ö¸´Õý³£ÑÕÉ«
$RED$ - ºìÉ«            $HIR$ - ÁÁºìÉ«
$GRN$ - ÂÌÉ«            $HIG$ - ÁÁÂÌÉ«
$YEL$ - ÍÁ»ÆÉ«          $HIY$ - »ÆÉ«
$BLU$ - ÉîÀ¶É«          $HIB$ - À¶É«
$MAG$ - Ç³×ÏÉ«          $HIM$ - ·ÛºìÉ«
$CYN$ - À¶ÂÌÉ«          $HIC$ - ÌìÇàÉ«
$WHT$ - Ç³»ÒÉ«          $HIW$ - °×É«

£ª¾ßÌåÑÕÉ«¿ÉÓÃÃüÁîcolor²ì¿´¡£
£ª×ÔÖÆÎäÆ÷³É¹¦ºóÎÞ·¨¸Ä±äÖÐÓ¢ÎÄ´úºÅ»òÎäÆ÷ÖÖÀà£¬ÇëÉ÷ÖØÑ¡Ôñ¡£
£ª×ÔÖÆÎäÆ÷ÃüÃûÇë×¢Òâ
£¨£±£©²»Òª²ÉÓÃÈËÃû¡¢»òÍ¨Ë×ÎïÃûÈçswordµÈÎªÓ¢ÎÄÃû£¬
·ñÔò¿ÉÄÜµ¼ÖÂÄãÎÞ·¨Õý³£¿´µ½¸ÃÎïÆ·µÄÐÅÏ¢¡£
£¨£²£©²»Òª²ÉÓÃ²»ÑÅÃû×Ö£¬·ñÔòÎ×Ê¦½«½«ÆäÏú»Ù²¢²»×÷Åâ³¥¡£

£ªÓëÒÔÍù·çÔÆ°æ±¾²»Í¬£¬Öý½£²»ÔÙÐèÒª×Ô±¸Ô­ÁÏ£¬Ìá¸ßÎäÆ÷É±ÉË
Á¦µÄÍ¾¾¶ÎªÑ°ÕÒ¸÷ÖÖÔ­ÁÏ£¬¶øºóµ½¼À½£Í¤µÄ·®·òÈË´¦¼À½£¡£×î»ù
±¾µÄ¼À½£Ô­ÁÏ¿ÉÔÚáÔÉ½½ÅÏÂËï¼ÇÌúÆÌ´¦¹ºÂò£¬ÒÔºó±ã»á´ÓÃÕÌâ»ò
É±ËÀNPCºóµÃµ½£¬ÐÂÊÖÒ²¿ÉÏòÀÏÍæ¼Ò¹ºÂò¡£µ«ÊÇ£¬Ðí¶àÔ­ÁÏ¶¼ÓÐ
Ò»¶¨µÄµÈ¼¶ÒªÇó£¬Ö»ÓÐ´ïµ½ÕâÒ»µÈ¼¶²ÅÄÜ¼À½£¡£

£ª×ÔÖÆÎäÆ÷ºó¿ÉÓÃalterÃüÁîÀ´¸Ä±äÅå´÷ÐÅÏ¢¡£

£ª×ÔÖÆÎäÆ÷¿ÉÓÃdestroyÏú»Ù£¬×¢Òâ£¬ÎäÆ÷ÉÏËùÓÐÊôÐÔµÈÒ²»á±»»Ù¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
TEXT
      ]) );

    set("coor/x",40);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
