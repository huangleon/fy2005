// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
���������������죬�������ԣ�һ�н��޳���������Ҳ���پ���������ν�� 
����˥��Ϊ�����ѹ��塢ͷ�ϻ�ή��������ࡢҸ�º��������ֱ�������������� 
����һ������õ����ֻ�з𷨸�������ֵ��ӷ��л���������������������� 
һ��˶��������������У����������������ɮ��ϥ���ԡ�����һ����ǿ������ǹ 
һ���Ȼͦ���š� 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("afei_cage",1);
	set("exits",([
		"west" : __DIR__"sl-exit",

	]));
        set("objects", ([
                __DIR__"npc/sl-afei": 1,
 		__DIR__"npc/sl-jailer1": 1,
 		__DIR__"npc/sl-jailer2": 1,
             
        ]) );
        
        set("item_desc", ([
		"����": "
һ����������ÿ����������ȭͷ��ϸ�����ž޴��ͭ�������������ҵ�Կ���� 
�Ǳ��޿���֮�����ˡ���\n",
		"cage": "
һ����������ÿ����������ȭͷ��ϸ�����ž޴��ͭ�������������ҵ�Կ���� 
�Ǳ��޿���֮�����ˡ���\n",
	]) );
	setup();
	
}

int	valid_leave(object who, string dir){
	
	object room;
	if (who->query_temp("maze/sl_2")) {
		message_vision(YEL"
$N��׼�������뿪��������Ȼ�����������һ��˶������Ĵ�������ͷ
������$N����������һ���ִֵ�������ͷ����$N�ĺ������ϡ� "+HIR"


$N��ʱʧȥ��֪�������� 

\n"NOR,who);
		who->delete_temp("maze/sl_2");
		who->unconcious();
		who->set_temp("maze/see_li",2);
		room = find_object(AREA_FY"fysecret");
		if (!room) room = load_object(AREA_FY"fysecret");
		who->move(room);
		return notify_fail("");
	}
	return 1;
}


void reset(){
	set("door_open",0);
	::reset();
}