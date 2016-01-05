
inherit ROOM;

void create()
{
        set("short", "��·��");
        set("long", @LONG
������ߣ�ǰ����������ɽ�ߡ�һ����ǰ��һ�����ҡ�һ�߾��ӹ�ĸ��ʯ��
��������·�䡣�Ÿ�ʯ�ܵ�Ӥ�����������������ϣ��е��ֳ����̣��е��ֳ�������
ʯ�����֮���棬�����ǹ��񹤡�
LONG
        );
        set("exits", ([ 
	  	"south" : __DIR__"firehole",
  		"west" : __DIR__"windhole",
	]));
        set("objects", ([
        	__DIR__"obj/stonejudge" : 1,
                 ]) );

        set("outdoors", "palace");

	set("coor/x",-70);
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
		room = find_object(__DIR__"realhole");
		if (!room) 
			load_object(__DIR__"realhole");
		me->move(room);
		return 1;
	}
	return 0;
}

