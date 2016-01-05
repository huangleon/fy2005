
inherit ROOM;

void create()
{
        set("short", "�ӵ���");
        set("long", @LONG
��·�������������˷ֲ���������·���ҷֿ�������ȴ��һ����ӡ�������
��ȥ�������������ң�Ҳ��֪�ж��һ������йٵ�ʯ���������ڿӱߡ�����
�������ӵ׷·�Ʈ����һ���Х֮����
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"woods",
  "north" : __DIR__"cliff",
  "west" : __DIR__"bladem",
]));
        set("item_desc", ([
                "����й�": "����һ������йٵ�ʯ����һ�ָ��룬һ�ֳֽ�������֮��ָ����ϡ���\n",
                "ʯ��" : "����һ������йٵ�ʯ����һ�ָ��룬һ�ֳֽ�������֮��ָ����ϡ�\n",
                "statue" : "����һ������йٵ�ʯ����һ�ָ��룬һ�ֳֽ�������֮��ָ����ϡ�\n"
        ]) );
        set("outdoors", "palace");

	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",10);

	setup();
}
void init()
{
        add_action("do_down", "go");
        
}

int do_down(string arg)
{
	object me;
	object room;
	me = this_player();
        if (arg == "down") {
        	message_vision("$N����������У�\n", me);
		room = find_object(__DIR__"kengdi");
		if (!room) room = load_object(__DIR__"kengdi");
		me->move(room);
		return 1;
	}
	return 0;
}

