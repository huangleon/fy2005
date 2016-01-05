 
#include <ansi.h>
inherit NPC;
void do_leave(object me);
void create()
{
	set_name("�������ҵ���Ů", ({ "girl", "fang girl" }) );
	set("gender", "Ů��" );
	set("age", 18);
	
	set("long", @LONG
����Ȼ�������ң����Ų������������ڰ׷�������ˮΪ����۹⣬ȴ����Ϊ֮���ԡ�
LONG
);
	set("fall_down", 0);
	setup();
	carry_object("/obj/armor/cloth",
		([ "name": "������",
			"long": "����ɫ���·����ѱ������˼�������\n" ])
		)->wear();
}

void init(){
	::init();
	add_action("do_getup", "getup");
}

void do_leave(object me){
	object yu, fang;
	
	if(!yu = present("yu yifei", environment(this_object()))) {
		message_vision("$Nվ����������������������ȥ��\n", this_object());
	} else if(!interactive(me) || environment(me) != environment(this_object())) {
		message_vision("$Nվ����������������������ȥ��\n", this_object());
	} else {
	message_vision("��Ůվ�������������ڰ׷�������ˮΪ����۹���$N��$n����һɨ��
��������������ȥ��$nҲ�����ظ��˹�ȥ��\n", me, yu);
	}
	destruct(yu);
	destruct(this_object());
}

int fall(object me){
	message_vision(HIY"\nֻ��һ����Ů�ɱ�������$Nһ������������ײ���ڵء�\n"NOR, me);
	tell_object(me, "\n��о���ѹ�����ϵ���һ�����������ů�����������Ҹպ�����������棬\n");
	tell_object(me, "���������������������ϡ�����������\n");
	set("fall_down", 1);
	call_out("self_get_up", 20, me);
}

int do_getup(){
	object me, yu;
	me = this_player();
	if(!query("fall_down")) {
		return 0;
	}
	if (me!= query("target"))	return 0;
	remove_call_out("self_get_up");
	message_vision("$Nվ�����������ַ���$n��\n", me, this_object());
	message_vision("\n$N�޷����ң��������������������ż��������ţ�������$n�������Ⱦ��ң���\n", 
			this_object(), me);
	tell_object(me, "�����𷽲ŵ��龰����������һ�ȣ����ɵ���Գ����\n"); 
	message_vision(WHT"\n$N����δ�䣬ֻ��һ����Ӱ�ӹ���$N����Ӱ��Ȼ��ʧ������\n"NOR,this_object());
	REWARD_D->riddle_set(me,"��ɽ����",1);
	me->set("marks/���������", 1);
	if(yu = present("yu yifei", environment(this_object()))) {
		message_vision("ֻ��$N�����������������������δ����Ҳ�����ˡ�\n", yu);
		destruct(yu);
	}	
	destruct(this_object());
	return 1;
}

void self_get_up(object me){
	object fang;

	do_leave(me);
	set("fall_down", 0);
	return;
}
