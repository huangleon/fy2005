#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����������Ľ�����������ǰ�������ϰ��Ÿ�ʽˮ����һ��Сͭ¯��ͭ¯��
������֧�����˵��㡣������ǽ�϶�û���κζ�����ȴ��ˢ�úܰס�����������
һ������¯��һλò�����˵ĵ�ʿ����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"da_yuan",
		"northwest" : __DIR__"stoneroad",
	]));
        set("valid_startroom", 1);
	set("objects", ([
                __DIR__"npc/up_taoist" : 2,
            	"/obj/specials/ding/ding_sq" : 1,
                __DIR__"npc/taolord" : 1,

 	]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


int	valid_leave(object me, string dir){
	object ding;
	if (me->query_temp("maze/ding_talk_1")) {
		if (ding = present("master ding",this_object())) {
			message_vision(HIC"
���˷��¶����ĵ���Ҳ�ա���ʩ����������ȡ�壬ƶ������ʲô�᲻���أ�
ʩ��������Ƭ�̣�

���˷�վ�������Ž���֮������������ 

���˷�һ��ִ����ľ����һ����ָ�����������дǣ��뷢�������ӭ����� 
���ͣ������˷���һ����ľ��ֱ��$N��ü�⣬$N��������·��׻���һ�� \n\n"NOR, me);
			me->unconcious();
			me->delete_temp("maze/ding_talk_1");
			me->set_temp("maze/ding_talk_2",1);
			ding->event2(me,1);
			return notify_fail("");
		}
	}
	return 1;
}
 
