inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"������"NOR);

	set("long", @LONG
һ�ֲ�֪���Ĺ����������ϻ���������׵�֭Һ�������ǳ�֮Ϊ��������վ��
Ũ���������Զ����Զ���İ������죬�������ң���ѩ��ɽ�������ʵ������£�ƽ
��������Ϊ�Լ���������������ƽ��������Ϊ�Լ��������ܶ���
LONG);

	set("type","street");
	set("exits",([
        "northeast":__DIR__"birdroad2",
		"southwest":__DIR__"birdroad3",
	]) );
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/bancha" : 1,
        ]) );   
	set("coor/x",-15);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}

void init ()
{
        add_action ("do_climb", "climb");
}

int do_climb (string arg)
{
	object npc,me,room;
	int dodge;
	me = this_player();
	dodge = me->query_skill("move",1);
	if (!arg || (arg != "tree" && arg != "������" && arg != "up"))
		return notify_fail("��Ҫ��ʲô��\n");
	else if( npc = present("bancha bana", this_object()) )
	{
		message_vision("$NбƳ��$nһ�ۣ������廨����ܾ�û����Ѫ�ˣ���Ī������һ�£�\n",npc,me);
		return notify_fail("������ɱ�����ǣ����ϲ������ģ�\n");
	}
	else if (dodge < 120)
		return notify_fail("��̫�ߣ�����Ṧ̫�������ȥҮ���裱��������\n");
	else
	{
		room = find_object(__DIR__"birdhouse");
		if(!room)
			room=load_object(__DIR__"birdhouse");
		message_vision("$N���㲢�ã����������Ϲ�������\n",me);
		me->move(room);
		me->start_busy(2);
        	message("vision",me->name()+"����������������\n",room,me);
		return 1;
	}
}

int valid_leave(object me,string dir)
{
        if ( (dir=="southwest") &&  present("bancha bana", this_object()))
        {
        	if( !me->query_temp("marks/won_bancha") )
        	{
        		return notify_fail("��������Цһ���������ȷ������ӣ�����̤����ʥĸѩ��벽���������Ӯ�ң�\n");
        		return ::valid_leave(me,dir);
        	}
        	else
        	{
        		return 1;
        	}
        }
        return 1;
}
