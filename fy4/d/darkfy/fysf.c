
inherit ROOM;

void create()
{
	object con,item;
        set("short", "�����鷿");
        set("long", @LONG
����鷿����̽��ż������СϢʱ�������á����Ӳ��õľ��¸���������һ����
�񰸣�������ֻ����ƿ��ƿ����ż�ʮ֦�軨����ƿ�����ż����ŷ�������Щ��ī��
ʯ�����и�������񲧣���������ϴ�ʵġ�
LONG
        );
        set("exits", ([
                "west" : __DIR__"fyyage",
        ]));
        set("objects", ([
                __DIR__"npc/bookgirl": 1,
		__DIR__"obj/vase" : 1,
		__DIR__"obj/flower" : 1,
        ]) );
        set("coor/x",20);
        set("coor/y",10);
        set("coor/z",-290);
        setup();
        con = present("vase",this_object());
        item = present("flower",this_object());
        item->set_amount(3+random(30));
        item->move(con);
}
