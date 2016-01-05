#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ɽʯ���������֮�������������ǵ����������ײ��ɡ���ֵ��ǣ���ô�ߵ�ɽ
���Ͼ�Ȼ��һ�����ڣ����������ģ����ڵ���ʯʮ�ֹ⻬���ƺ��������˽�����
��������һ�ֲ���ĸо������õ��������ô�����ⶴ���أ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"hole3",
	]));
        set("item_desc", ([
                "up": "ɽʯ����û�����֮����\n",
                "mountain": "ɽʯ����û�����֮����\n",
                "ɽ": "ɽʯ����û�����֮����\n",
        ]) );
        set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        me = this_player();
        if( arg == "up" || arg == "ɽ" || arg == "mountain")
        {
        	message_vision("$N��������ɽ����ȥ��\n", me);
        	message_vision(RED "���ã�$Nһ����С�ĵ�����ȥ��\n"NOR , me);
        	me->move(__DIR__"road5.c");
        	me->receive_wound("kee", 50);
        	me->receive_wound("sen", 50);
        	me->receive_wound("gin", 50);
        	me->set_temp("last_damage_from","��ɽ����ˤ���ˡ�");
        	return 1;
        }
        else if( arg == "down") {
        	message_vision("$N��������ɽ����ȥ��\n", me);
                me->move(__DIR__"ping_tai.c");
	        return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
