
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
		"east" : __DIR__"octo12",
		"south" : __DIR__"octo10",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"obj/trash" : 1,
		__DIR__"obj/junkstaff" : 1,
		__DIR__"npc/biglama" :1,
        ]) );
	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        box = present("trash", this_object());
        matter = present("staff", this_object());
	matter->move(box);
}