#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "佻�Ϫ");

	set("long", @LONG
һ���峺���׵�Ȫˮ�����Ե�ɽ�н����������������д��ӵ��أ�����С����
������̣�����ɽ��������Ϫˮ�и�ɫ�ͷ׵Ļ�������Ϫˮ���������ʣ�һ������
�续��Ȫˮǳǳ���У��������ϣ��ɿ�����Զ���������ȪˮԴͷ�и�������
LONG);

	set("type","waterbody");
	set("exits",([
		"south":__DIR__"sunlake",
		"northeast":__DIR__"brook",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/xiaoma":1,
    	]) ); 
	set("coor/x",-70);
	set("coor/y",-30);
	set("coor/z",0);
	setup();

}

void init(){
	object me;
	me = this_player();
	if (!REWARD_D->imbue_check(me,"��ɽ����") && REWARD_D->check_m_success( me,"��ɽ����")
			&& present("xiao ma", this_object())) 
		call_out("imbue_event", 2, me, 1);
/*	{
	if(!me->query("imbue/xiaoma") && me->query("marks/ɱ̫��ʹ��") && present("xiao ma", this_object())) {
		if(me->query("marks/wolf_xiaoma_good") ) {
			call_out("imbue_event", 2, me, 0);
		} else if (me->query("marks/wolf_xiaoma_normal")) {
			call_out("imbue_event", 2, me, 1);
		}
	}*/
	
}


int imbue_event(object me, int j){
	object xiaoma, weapon, obj, *inv;
	string prop;
	int i;
	mapping data;
	
	if(!me || !interactive(me) || environment(me) != this_object()){
		return 0;
	}
	xiaoma = present("xiao ma", this_object());
	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	
	message_vision("\n$N��������$n�ı���һ������С�ӣ��ɵĺá��ı��顣\n", xiaoma, me);
	message_vision("$NͻȻ�����������˿ڳ���֮��$Nʹ������ֱ�У�����ĺ�ˮ��ર�વ�������������\n", xiaoma, me);
	if(!objectp(weapon)){
		if(objectp(obj)){
			message_vision(HIR"\n������Ѫˮ�ĺ������$N��\n" + obj->name() + HIR"�ϣ��ֹ�����ϡ�\n"NOR, me);
		} else {
			message_vision(HIR"\n������Ѫˮ�ĺ��齦��$N���ϣ����ڵ��ϡ�\n"NOR, me);
		}
	} else {
		message_vision(HIR"\n������Ѫˮ�ĺ������$N��" + weapon->name() + HIR"�ϣ�һת˲���ֻ�Ϊˮ�����ŵ���Ӱ���١�����\n"NOR, me);  	
	}
		
	data = ([
		"name":		"��ɽ����",
		"target":	me,
		"att_1":	"str",
		"att_1c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);	
	return 1;
}