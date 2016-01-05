
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
		"north" : __DIR__"octo8",
		"south" : __DIR__"octo6",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"obj/trash" : 1,
		__DIR__"obj/junkblade" : 1,
		__DIR__"obj/junkstaff" : 1,
		"/obj/money/coin" : 1,
		__DIR__"obj/junksword" : 1,
		"/obj/npc/beggar" :1,
		__DIR__"npc/biglama" :1,
        ]) );
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        box = present("trash", this_object());
        matter = present("blade", this_object());
	matter->move(box);
        matter = present("staff", this_object());
        matter->move(box);
        matter = present("coin", this_object());
        matter->move(box);
        matter = present("sword", this_object());
        matter->move(box);
}