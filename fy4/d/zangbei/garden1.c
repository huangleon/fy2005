inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��԰��");
        set("long", @LONG
��ס�ĵط�������������һƬ���ǣ��ڲ�ͬ�ļ����У��������в�ͬ�Ļ�ʢ����
������ס�ڻ�������ʢ���Ǹ��ط������ڿ������޵ľ��Ǿջ��������ϲ����ھջ�
԰��Ӵ����ı��͡�û��������֪�����񲮾����Ǹ���ô�����ˣ���������ʲô�£�
������˭�������ѣ����˲��ܽ��������ʱ������ȥ����������
LONG
        );
        set("exits", ([ 
		"south" :   	__DIR__"mroad3",
		"northwest" : 	__DIR__"garden2",
		"northeast":	__DIR__"garden4",
	]));
        set("objects", ([
		__DIR__"npc/sunjian":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1300);
        set("coor/y",950);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}


int valid_leave(object who,string dir) {
	
	object sun;
	
	sun=present("sun jian",this_object());
	if (!sun ) return 1;
	
	if (dir=="northwest" || dir=="northeast"){
		if (who->query("timer/��԰ʧ��") + 1440 > time()) {
			message_vision("$N��$n˵���㲻�Ǳ��ϳ�����ô��������������\n", sun, who);
			return notify_fail("");
		}
		
		if (!who->query_temp("zangbei/see_lv") 
			&& REWARD_D->riddle_check(who,"��԰����")< 2	
			&& !REWARD_D->check_m_success(who,"��԰����")) {
			message_vision("$N���ֵ�ס��$n˵����������˭����\n",sun,who);
			return notify_fail("");
		}
	}
	return 1;
}
	
		