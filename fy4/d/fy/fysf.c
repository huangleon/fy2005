
inherit ROOM;

void create()
{
    object con,item;
    set("short", "�����鷿");
    set("long", @LONG
����鷿����̽��ż������С�ʱ����֮�������Ӳ��õľ��¸���������һ��
���񰸣�������ֻ[33m����ƿ[32m��ƿ����ż�ʮ֦�軨����ƿ�����ż����ŷ�������Щ��
ī��ʯ�����и�������񲧣���������ϴ�ʵġ�
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
