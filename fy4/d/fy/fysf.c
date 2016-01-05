
inherit ROOM;

void create()
{
    object con,item;
    set("short", "·çÔÆÊé·¿");
    set("long", @LONG
Õâ¼äÊé·¿ÊÇÀîÌ½»¨Å¼¶ø»ØÀ´Ð¡í¬Ê±¶ÁÊéÖ®´¦¡£ÎÝ×Ó²¼ÖÃµÄ¾«ÖÂ¸»Àö£¬ÕýÖÐÒ»ÕÅ
ÇàÓñ°¸£¬°¸ÉÏÁ½Ö»[33m°×ÓñÆ¿[32m£¬Æ¿Àï²å×Å¼¸Ê®Ö¦²è»¨¡£ÓñÆ¿ÅÔÆÌ×Å¼¸ÕÅÐÅ·¤£¬·Å×ÅÐ©±Ê
Ä«ÑâÊ¯£¬»¹ÓÐ¸ö¶·´óµÄÓñ²§£¬ÏëÊÇÓÃÀ´Ï´±ÊµÄ¡£
LONG
    );
    set("exits", ([
	"west" : __DIR__"fyyage",
      ]));
    set("objects", ([
	__DIR__"npc/bookgirl": 1,
	__DIR__"obj/vase" : 2,
	__DIR__"obj/flower" : 1,
      ]) );
    set("coor/x",60);
    set("coor/y",40);
    set("coor/z",10);
    setup();
    con = present("vase",this_object());
    item = present("flower",this_object());
    item->set_amount(3+random(30));
    item->move(con);
}
