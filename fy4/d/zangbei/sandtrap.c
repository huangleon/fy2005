#include <ansi.h>
inherit ROOM;

void create()
{
	object me;
	me = this_player();
	set("short", "ɳѨ");

	set("long", @LONG
һ��ɳ�ӵĶ�Ѩ�������������ɳ�ӣ����ܵ�ɳǽ����ʱ�Ϳ���̮����������
�ᣬͷ����ʱ����ϸɳ���£��������ʲô������ͣ����������䶯������ģ�ʪ
ʪ�ģ��㲻��ͷƤ�����ˡ�
LONG
	);
	set("indoors", "eren");
	set("objects", ([
		__DIR__"npc/sandworm" : 2,
	]) );
	set("coor/x",0);
    	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{	
	add_action("do_climb", "climb");
}


int do_climb(string arg)
{
    object obj, me;
    int	kar;
    
    if(!arg || arg=="") return notify_fail("��Ҫ����������\n");
    me = this_player();
    if( arg == "wall" || arg == "����" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
        message_vision("$Nʹ�����̵�������˳��ɳ��������ȥ��\n", me);
        me->start_busy(1);
        call_out("climb_wall", 2, me);
        return 1;
    }
    return notify_fail("�㲻������"+arg+"��\n");
}       

int climb_wall(object me)
{
    int kar;
    
    if (me->is_ghost()) return 0;
    kar = (int)me->query("kar");
    if( kar > 60 ) kar = 60;
    if( random(60 - kar) < 15 )
    {
        me->move(__DIR__"yangguan2.c");
        message_vision("$N��ɳѨ�м��ѵ����˳�����\n", me);
    }
    else message_vision("$N����һ��ûץ�ȣ��ֵ���������\n", me);
    return 1;
}