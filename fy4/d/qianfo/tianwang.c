//mac's tianwang.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
���汾��Ϊ���ջ���Ĳ���������������Ϊ�Ĵ��������������������£���
��������ͷ��߸�����ְѵ�������ִì���أ������������಩�棬����ִ�Σ�����
�ѳ���������������ɳ�ţ�����ֿì���أ������������Ϸ������������죬ִ��ɫ
�����������˳�����Ϊ�ֹ�����������Ŀ���ػ�������
LONG
  );
  set("exits",([
         "south":__DIR__"dadian.c",
         "north":__DIR__"mile.c",
         "west" :__DIR__"jialan.c",
         "east" :__DIR__"damo.c"
               ]));
        set("objects", ([
                __DIR__"npc/master2" : 1,
		__DIR__"npc/tianwang1" : 1,
                __DIR__"npc/tianwang2" : 1,
                __DIR__"npc/tianwang3" : 1,
                __DIR__"npc/tianwang4" : 1,

		
       ]) );

	set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (QUESTS_D->verify_quest(me,"����ͭ��"))
		QUESTS_D->special_reward(me,"����ͭ��");
	return 1;		
	
}

