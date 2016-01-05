inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�����");
        set("long", @LONG
�����λ��������ѩ����£����������ɼ����£����������������ڴ��
�̷�С�����ڹ����������ȡ������������ïʢ���ݲؾ���˵���ڳ����תʮ��
�ξ��൱����һ�����صĹ��£����Ծ���������ɽ�ϵ�����Ҳ��������תɽת�£�
���Լ����µ����
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"tianxin",
		"south":  __DIR__"zhayi",
		"northeast": __DIR__"temple1a",
	]));
        set("objects", ([
        	__DIR__"npc/monk1":	1,
	]) );
	set("coor/x",-1710);
        set("coor/y",650);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}

void 	init(){
	add_action("do_around","around");
}


int do_around(){
	
	object me = this_player();
	object tong = me->query_temp("weapon");
	
	
	if (!tong || tong->name() != "ת��Ͳ")
		return notify_fail("û�о�Ͳ�����ת����\n");
	
	if (me->is_busy())
		return notify_fail("������æ�úܣ�û��ת����\n");
				
	message_vision(YEL"$Nת�������е�С��Ͳ���ϵ����ž��ģ�����"
		+this_object()->query("short") + "��������һȦ��\n"NOR, me);
	me->start_busy(1);
	
	if (me->query("marks/ת��") 	||	REWARD_D->riddle_check(me,"��ͯת��")!= 1
		|| me->query_temp("zhuanjing/chonggu"))	return 1;
						
	me->add_temp("zhuan_around",1);
	
	if (random (me->query_temp("zhuan_around"))>= 10)
	{
		tell_object(me,WHT"\n����"+ query("short")+"ת����ϣ������ڷ𷨵��˽�������ߡ�\n"NOR);	
		me->delete_temp("zhuan_around");
		me->set_temp("zhuanjing/chonggu",1);
		
		if (mapp (me->query_temp("zhuanjing")))
		if (sizeof(me->query_temp("zhuanjing")) == 4)
		{
			REWARD_D->riddle_set(me,"��ͯת��",2);
			me->set_skill("lamaism",me->query_skill("lamaism",1)+1);
			tell_object(me,HIC"������ڷ������һ���ȼ���\n"NOR);			
			me->set("marks/ת��",1);
			me->delete_temp("zhuanjing");
		}
	}
	return 1;
}
	
	
