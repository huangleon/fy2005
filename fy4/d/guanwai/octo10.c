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
		"north" : __DIR__"octo11",
		"south" : __DIR__"octo9",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"obj/trash" : 1,
		__DIR__"obj/junkstaff" : 1,
        ]) );
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        box = present("trash", this_object());
        matter = present("staff", this_object());
	matter->move(box);
}