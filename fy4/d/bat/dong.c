inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����");
        set("long", @LONG
һ�������Ƶ���ʯ������������������������(huache)������ͨ��һ������
���ɽ���� 
LONG
        );
        set("exits", ([ 
       "west" : __DIR__"anbian",
	]));
        set("item_desc", ([
                "huache": @TEXT
�ƺ�������(dash)��ȥ,������...
TEXT
        ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",30);
	setup();
}

void init()
{
        add_action("do_dash", "dash");
}

int do_dash(string arg)
{
        object room;
        object me;
        me = this_player();
	
		if (me->is_busy())
			return notify_fail("��������æ��\n");
			
		if (!arg || arg == "huache" || arg == "����") {
			room = find_object(__DIR__"dong1");
			if (!room) room = load_object(__DIR__"dong1");
			message_vision("$Nһ���Ӿ������˻�����\n",me);
			tell_object(me,"��Խ׹Խ�죮���������ƺ�������һ���ҽУ�����ë���Ȼ��\n");
	       	me->move(room);
        	return 1;
        }
        write("�������Ķ�����\n");
        return 1;
}