inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "�ٻ���");
        set("long", @LONG
���ǿ����רΪ�׷ɷɶ�����İٻ��������е���װ�εؼ����£�����עĿ
������Ŀ�Ĵ�����Ĵ����ң����СС�ġ�ϲ�������ڸ���װ֡�ϣ������Ŀ��
�����������ػ�֦��չ��ϲ��æµ����ͣ��һ����ͷʦ�������ĵ�Ϊ����׷ɷ�
��ͷ��硣
LONG
        );

        set("exits", ([ 
		"south" : __DIR__"eaststrt2",
		]));
        set("indoors", "loulan");
        set("objects", ([
                  __DIR__"npc/xiniang" : 2,
                  __DIR__"npc/hairjiang" : 1,
                  __DIR__"npc/ms_wang" : 1,
        ]) );

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

/*
void init()
{
	object me;
	object room;
        
        if( interactive(me = this_player()) ) 
        if( userp(me) && !me->query_temp("marks/jade_to_zhu") && environment(me)==this_object()
        	|| !me->is_fighting()) {
		room = find_object("/d/loulan/eaststrt2");
		if(!objectp(room)) 
			room = load_object("/d/loulan/eaststrt2");
		message_vision(HIY"������������װ���������ӡ�������ϲ�����������İ�$N���˳���������\n"NOR,me);
		me->move(room);
        }
}

*/