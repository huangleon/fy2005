
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�߹����κ��ţ������º���ɭɭ��Ʈ���������İ������ɵİ����У���ʱ��
�����һ����ʯ�ܵĹ����е�ţ�ף��е����棬���������������п�����������
���ľ���Խ��ǰ������ԽŨ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"naibridge",
]));
        set("objects", ([
        __DIR__"obj/judge" : 1,
                        ]) );

        set("outdoors", "palace");

	set("coor/x",-90);
	set("coor/y",50);
	set("coor/z",10);
	setup();
}
void init()
{
        add_action("do_east", "go");
        
}
int do_east(string arg)
{
	object me;
	object room;
	me = this_player();
        
        if (arg == "east") {
	        message_vision("$N�Ӷ����һ��ɽ�����˽�ȥ��\n", me);
		room = load_object(__DIR__"windhole");
		if(room) me->move(room);
		return 1;
	}
	
	return 0;
}
