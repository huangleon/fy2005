#include <ansi.h>

inherit NPC;
void create()
{
    	set_name("��ëС�ڹ�", ({ "green turtle", "turtle" }) );
    	set("race", "Ұ��");
    	set("age", 1);
    	set("gender", "����");
    	set("long", "
����һֻ���ƴ�С���ڹ꣬���ϳ���ϸϸ��������ë�������������С���� 
����ʱ��ͷ������һ˫СԲ�۾����鶯���ƺ����������ԣ��ɰ���������ץ
ס������������裩\n");
    	set("attitude","peaceful");
    	set("chat_msg", ({
			"��ëС�ڹ���ͷ��ͣ�����ܿ��������е�Ѱ��ʲô... ... ���ǲ�������ˣ�\n",
		}) );
		set("chat_chance", 1);
		set("weight", 3000);
		set("no_drop", 1);
		set("no_get", 1);
    	setup();
}


int kill_ob(object me)
{
    	message_vision("$N��ͷ�����˻�ȥ�����С���򣬹���������ݴ��в����ˡ� \n",this_object());
    	me->set("marks/����", 1);
    	destruct(this_object());
    	return 1;
}

void init() {
	if (this_player() == environment()) {
		add_action("do_release", "release");
	}
	add_action("do_catch", "catch");
}

int query_autoload() { 
	return 1; 
}

int do_catch(string arg) {
	object me, turtle;
	
	me = this_player();
	turtle = present("green turtle", environment(me));
	if(!arg || (arg != "green turtle" && arg != "turtle")) {
		return 0;
	}
	if(!present("green turtle", environment(me))){
		return 0;
	}
	if (turtle->query("turtle_owner")!=me)
	{
		message_vision("$N��ͷ�����˻�ȥ�����С���򣬹���������ݴ��в����ˡ� \n",this_object());
    		destruct(this_object());
    		return 1;
	}    
	message_vision(HIG"$NС�ĵ�����֣���$n׽��������$n��ͷ�������\n"NOR, me, turtle);
	message_vision(HIG"һ˫С�۾����ŵ����⿴��\n"NOR, me); 
	if (turtle->move(me))
		set("long", "
����һֻ���ƴ�С���ڹ꣬���ϳ���ϸϸ��������ë��ԶԶһ������һ��
��Ө��С"HIG"���"NOR"������ʱ��ͷ������һ˫СԲ�۾����鶯���ƺ����������ԣ�
�ֿɰ��ֿ�����Ҳ��������Ҹ�ʲô�ط���������release��\n");
	return 1;
}


int do_release(string arg) {
	object me;
	
	me = this_player();

	if (!arg || (arg != "turtle" && arg != "green turtle")) {
		tell_object(me,"�����������ʲô��\n");
		return 1;
	}
	if(environment(me)->release_turtle(this_object())) {
		tell_object(me, "�������ر�̯���֣�����ذ���ëС�ڹ����������\n");
		tell_object(me, "��ëС�ڹ��˷ܵش����������£��ֻ�ͷ������һ�ۣ�ת���ν����ء�\n", this_object(), me); 
		message("vision", me->name() + "�����ر�����İ�һ����ëС�ڹ���¡�\n", environment(me), me);
		destruct(this_object());	
		return 1;
	} else {
		tell_object(me, "��ëС�ڹ굨�ӵ�̽ͷ������Χ�����������뿪�㡣\n");
		message("vision","��ëС�ڹ��"+ me->name() + "���е��ӵ�̽ͷ������Χ�������뿪" 
				+ me ->name() + "��\n", environment(me), me); 
		return 1;
	}	
	return 1;
}

     
