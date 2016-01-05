
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
    set_name("��ʿ", ({ "wen shi", "zhen zhen"}) );
    set("gender", "����" );
    set("age", 35);
    set("int", 30);
    set("per", 30);
    set("long",
        "��ƽ����ѩ���ϣ���׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶġ���Ϣ���ƺ���û����Ϣ����֪������û�оȡ�\n"
        );
    set("max_gin", 3000);
    set("max_kee", 3000);
    set("max_sen", 3000);
    set("eff_gin", 30);
    set("eff_kee", 30);
    set("eff_sen", 30);
    set("gin", 3000);
    set("kee", 3000);
    set("sen", 3000);
    set("max_force", 3000);
    set("force", 3000);

    set("combat_exp", 9999999);
    set_skill("unarmed", 100);
    set_skill("sword", 180);
    set_skill("force", 200);
    set_skill("move", 100);
    set_skill("literate", 100);
    set_skill("dodge", 100);
    set_skill("yunwu-strike", 150);
    set_skill("qiuzhi-sword", 150);
    set_skill("hanmei-force", 150);
    set_skill("anxiang-steps", 100);
    map_skill("sword", "qiuzhi-sword");
    map_skill("force", "hanmei-force");
    map_skill("dodge", "anxing-steps");
    map_skill("move", "anxiang-steps");
	set("disable_type", HIR "<���Բ���>"NOR);

   	set("cured", 0);
   	set("answered", 0);
    setup();
    carry_object("/obj/armor/cloth", 
    		([ 	"name" : "���",
    			"long" : "����һ�������˳����������\n"]) 
    		)->wear();
    carry_object("/obj/armor/hat",
    		([ "name" : "����" ]) 
    		)->wear();
	this_object()->disable_player("<���Բ���>");
    this_object()->set_temp("is_unconcious",1);	
}

void init(){
	::init();
	if(find_call_out("do_leave") == -1 && !query("cured")) { 
		call_out("do_leave", 120);
	} 
	if(find_call_out("do_selfcure") == -1 && !query("cured")) {
		call_out("do_selfcure", 30);
	}
}

void do_selfcure(){
	if(query("cured")) {
		return;
	}
	this_object()->enable_player();
	message_vision("$N���ֱۻ����ض���һ�¡�\n", this_object());
	message_vision("$NŬ���ع������ľ�����վ������������Ȼվ�Ĳ��ȣ�������վ���ŵġ�\n",
			this_object());
	set("long", 
	        "��������ô����㲶�˥������׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶģ��������峿���͵ķ��ѩ��������ز��ȶ���
��Ȼ����ֱͦ��վ�ţ�Ȼ��ȴ����ʱ��������� \n"
	);
	set("cured", 1);
}
void do_leave(){
	if(environment(this_object())->query("meishan")) {
		message_vision("\n$N���ų��صĲ���������ȥ��ѩ��������һ��������㼣��\n", this_object());
		destruct(this_object());
	}
}

int Cured(object me){
	if(!query("cured") && !me->query("marks/killed_mei")) {
		message_vision("$N��Ϊ���ѵ���������������������������$n��������֪������˭�𡣡� 
���������򡡣���󣯣�\n", 
				this_object(), me);	
		set("long", 
	        "��������ô����㲶�˥������׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶģ��������峿���͵ķ��ѩ��������ز��ȶ���
��Ȼ����ֱͦ��վ�ţ�Ȼ��ȴ����ʱ��������� \n"
		);
		add_action("do_answer", "answer");
		set("cured", 1);
		this_object()->enable_player();
		remove_call_out("do_leave");
		call_out("do_leave", 60);
	} else {
		message_vision("$N΢΢һЦ��������л����֮������\n", me);
		message_vision("\n$N���ų��صĲ���������ȥ��ѩ��������һ��������㼣��\n", this_object());
		destruct(this_object());
	}
}

int do_answer(string arg) {
	object me;
	me = this_player();
	if(!arg || (arg != "yes" && arg != "no")) {
		return 0;
	}
	if(query("answered")){
		return 0;
	}
	if(arg == "yes") {
		message_vision("$N΢΢һЦ���������¾��������������\n", me);
		message_vision("$N�������ã���Ȼ��ˣ�����һ��Ҳ֪�����������ҡ�����һ�����ձص��ر�����\n",
				this_object());
		me->set("marks/÷ɽ��", 1);
		do_leave();
	} else if(arg == "no") {
		message_vision("$N��ɫãȻ��ҡ��ҡͷ��\n", me);
//		if(me->query("title") == "��ͨ����") {
			message_vision("$Nע����$n��Ц�������������$N˵����������Ը�������ң��ɵ����Ƴ������������ҡ�\n", this_object(), me);
			tell_object(me, this_object()->name() + "�ֵ����������֣���һ�����ƿ���ԣ������衡�������򶫱��У�Ȼ�����ż��ɡ���\n");
			me->set("marks/÷ɽ��", 3);
			do_leave();
//		} else {
//			message_vision("$N�������������������������Ե������л����\n", this_object());
//			me->set("marks/÷ɽ��", 2);
//			do_leave();
//		}
	}
	return 1;
}

void die(){
	object me;
	if(objectp(me=query_temp("last_damage_from") )) {
		me->set("marks/killed_mei", 1);
	}

	::die();
}
