inherit NPC;
#include <ansi.h>

void create()
{
    set_name(HIR"Ѫ����"NOR,({"bloody parrot","parrot"}));
//    set("title","ն�ݳ���");
    set("long","Ѫ��ɫ�����ģ�Ѫ��ɫ����ë��Ѫ��ɫ����צ���۾���Ҳ��Ѫ�����ɫ�������ǧ
���ٰ�ʮ�ߵ�ħѪ���γ�����һֻѪ���ġ��һ���է�֣�Ѫ��������һ���һ�Ҳ�ơ�\n");
    set("race","Ұ��");
    set("age",32);
    set("no_arrest",1);
    set("int",220);
    set("cor",300);
    set("per",100);
    set("cps",200);
    set("str",200);
    set("limbs", ({ "ͷ��", "����", "β��", "���" }) );
    set("verbs", ({ "bite" }) );
    set("max_kee",100000);
    set("max_sen",100000);
    set("max_gin",100000);
    set("resistance/kee",100);
    set("resistance/gin",100);
    set("resistance/sen",100);
    set("combat_exp",99000000);  
    set("attitude", "friendly");
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     
        }) );
    set("chat_chance",1);
    set("chat_msg",({
	name()+"����Ц��������һ����Ц��Ц���г�����һ��˵������а�����졣\n",
    }) );
    setup();        
}


void init() {
	
	object ob;
	::init();
//	add_action("do_answer","answer");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
	tell_object(ob,HIR"Ѫ���ĵ��죬��Ȼ�ſ��ţ������³�����������"+ob->name()+"����\n"NOR);
	tell_object(ob,HIR"   Ѫ���ĵ����ص��������Ը����ʲô����\n"NOR);
	tell_object(ob,WHT" force/spells/magic/parry/dodge/move/ + 10 level \n"NOR);
	return;
}