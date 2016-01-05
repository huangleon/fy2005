
inherit ROOM;

void create()
{
	object box, matter;
        set("short", "�˽ǽ�");
        set("long", @LONG
���г���Ƥ��й⻬������һ�棬Ҳ�дֲڳ�ª��һ�档��ΰ˽ǽ�������
����ǽ塣��Ⱥ��ӵ�������ؤ�������ƾ����ڵ��·������ͷ����㣬�����ڳ�
���У��ȴ���������͵�ʩ�ᡣ
LONG
        );
              
        set("exits", ([ 
		"north" : __DIR__"octo7",
		"east" : __DIR__"octo5",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"obj/trash" : 1,
		__DIR__"obj/junkblade" : 2,
		__DIR__"obj/junkstaff" : 1,
		"/obj/money/silver" : 1,
		"/obj/npc/scavenger" : 1,
		__DIR__"npc/dog" : 2,
		__DIR__"npc/woodcutter" : 1,
		__DIR__"obj/junksword" : 1,
                __DIR__"obj/fake-tooth" : 1,
        ]) );
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        box = present("trash", this_object());
        matter = present("blade", this_object());
	matter->move(box);
        matter = present("staff", this_object());
        matter->move(box);
        matter = present("blade", this_object());
        matter->move(box);
        matter = present("silver", this_object());
        matter->move(box);
        matter = present("sword", this_object());
        matter->move(box);
        matter = present("tooth", this_object());
        matter->move(box);
}