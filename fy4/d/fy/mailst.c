
inherit ROOM;

void create()
{
    set("short", "·çÔÆæäÕ¾");
    set("long", @LONG
Ã¿Ìì¿ìÂíÈıÆ¥£¬ÔçÎçÍí¸÷´«µİÊéĞÅÈı´Î¡£ÎŞÂÛ¹ÙÔ±ÑÃÒÛ»¹ÊÇÆÕÍ¨°ÙĞÕ¶¼¿ÉÒÔÔÚ
Õâ¶ùÃâ·ÑÓÊ¼ÄÊéĞÅ¡£²»¹ÜÄãµÄÊéĞÅÒª¼Äµ½ÄÇÀï£¬Ö»Òª½»¸øæäÕ¾£¬ÈıÌìÖ®ÄÚ¾ø¶Ô¿ÉÒÔ
ËÍµ½¡£½üÀ´³¯Í¢½ÚËõ¿ªÖ§£¬Íõ·çÒ²¹ÒÆğÁËÅÆ×Ó(Sign)£¬ºÍ¹ØÍâµÄÂÀ¹§ºÏ»ï£¬×öÆğÁË
³ö×âÂí³µµ½¹ØÍâµÄÉúÒâ¡£
LONG
    );
    set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"fengdoor",
      ]));
    set("objects", ([
	__DIR__"npc/officer": 1
      ]) );
    set("item_desc", ([
	"sign": @TEXT
[37mæäÕ¾·şÎñÄÚÈİ£º
£¨£±£©³ö×âÂí³µ(rent mache): ÎÆÒø8Á½
£¨£²£©ÊÕ¼ÄĞÅ¼ş£ºÄã¿ÉÒÔÔÚÕâÀïÏòÍõ·çÑ¯ÎÊ¡ºĞÅ¡»À´²éÑ¯ĞÅÏä¡£
[32m
TEXT
      ]) );

    set("coor/x",-40);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
    setup();
}

int valid_leave(object me, string dir)
{
    object mbox;

    if( mbox = me->query_temp("mbox_ob") ) {
	tell_object(me, "Äã½«ĞÅÏä½»»ØæäÕ¾¡£\n");
	destruct(mbox);
    }
    return 1;
}
