#include <ansi.h>
inherit NPC;
void use_poison();

void create()
{
    	set_name(MAG"С��"NOR, ({ "snake", "little snake" }) );
    	set("race", "����");
    	set("age", 1);
    	set("gender", "����");
    	set("long", "һ��ȫ���Ϻ�ɫ��С�ߣ������ε��Դ����м�����ɫ�İ��ơ�
���������ץ����ҪС��Щ����������裩\n");
    	set("attitude","peaceful");
    
	set("weight", 300);
	set("combat_exp", random(100000));
    	set("chat_chance_combat", 10);
    	set("chat_msg_combat", ({
    		(: use_poison :),
    	}));
    	setup();
}


void init() {
    	::init();
	add_action("do_catch", "catch");
	if(this_player() == environment()){
		add_action("do_insert", "insert");
	}
}

void use_poison()
{
    	object *enemy, ob;
    	string msg;

    	enemy = query_enemy();
    	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	message_vision(MAG"ֻ��һ���Ϲ���𣬳���$N��\n"NOR, ob);
    	tell_object(ob,"��ֻ��������һ�飬һ����˳�ž�������ȫ��\n");
    	ob->receive_wound("kee",50,this_object());
    	ob->apply_condition("canxia", 
    		(int)this_player()->query_condition("canxia")+ random(3)+3);
}


int do_insert(string arg){
	object obj, me, cont;
	string Sitem, Titem;
	me = this_player();
	
	if(!arg) {
		return notify_fail("��Ҫ��С�߷Ž��������������������塡����������\n");
	} 
	if(sscanf(arg, "%s in %s", Sitem, Titem) == 2);
	else {
		return notify_fail("��Ҫ��С�߷Ž����\n");
	}
	if(Sitem != "snake") {
		return 0;
	}	
	if( Titem != "zhutong" && Titem != "zhu tong") {
		message("vision", me->name() + "����С����ԥ��һ�£��ַ��˻�ȥ��\n", environment(me), me);
		return notify_fail("���ƺ�����һ���ܺõ�����ɣ�\n");
	} else {
		if(obj = present("zhu tong", me)){
			if(obj->query("have_snake")){
				return notify_fail("�����Ѿ������ˡ�\n");
			} else if(obj->query("is_open")){
				message_vision(MAG"\n$N��С�߶�׼��Ͳ��ֻ��һ���Ϲ������Ͳ��$N��ϸ�İ���Ͳš�ϡ�\n"NOR, this_player());
			} else {
				message_vision(MAG"$N����Ͳš������С�߶�׼��Ͳ��ֻ��һ���Ϲ������Ͳ��$N��ϸ�İ���Ͳš�ϡ�\n"NOR, me);
			}
			obj->set("is_open", 0);
			obj->set("have_snake", 1);
			obj->set("long", "һ������ɫ��С��Ͳ��������һ��С�ߡ�\n");
			obj->set("train_needed", random(10));
			obj->add_action("do_train", "train");
			destruct(this_object());
		} else {	
			return notify_fail("��û�����������ɣ�\n");
		}
	}
	return 1;
}

int do_catch(string arg) {
	object me, obj;
	
	me = this_player();
	obj = present("little snake", environment(me));
	if(!arg || (arg != "snake" && arg != "С��")) {
		return 0;
	}
	if(!present("little snake", environment(me))){
		return 0;
	}
	message_vision("\n$N�����ȥ��׽סС�ߣ�ֻ��С�ߵı��������һ������$N��\n", me);
	if(!random(3) && me->query("agi")>= 36){
		message_vision(YEL"$N�ɿ�ĳ���׼ȷ������С�ߵ�����֮�ϡ�\n"NOR, me);
		message_vision(WHT"ɲ�Ǽ䣬С�ߵ���������������$N��ϸ�İ�С������\n"NOR, me);
		tell_object(me, "��������С�߷����������������������塡����������\n");
		obj->move(me);
		call_out("Wake", 30);
	} else {
		tell_object(me, WHT"��о�������ͻȻ������ʹ�ĸо���һ����˳�ž�������ȫ��\n"NOR);
		message_vision("С�ߴ�$N����ӹ�����ʧ�����ˡ�\n", me);
		me->apply_condition("canxia", 10);
		environment(me)->set("have_snake", 1);
		destruct(obj);
	}
	return 1;
}

void Wake() {
    	object container;
    
    	container = environment(this_object());
    	if(container->name() != "��Ͳ" && userp(environment(this_object()))) {
		tell_object(environment(this_object()), WHT"��ͻȻ�е�һ����ʹ��ֻ���ú���˳�ž�������ȫ��\n"NOR);
		environment(this_object())->apply_condition("canxia", 10);
    	destruct(this_object());
    }
}
