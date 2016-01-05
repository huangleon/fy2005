 
#include <ansi.h>
inherit NPC;
int answer();
int do_leave();
void create()
{
	set_name("����", ({ "qing qing", "qing" }) );
	set("gender", "Ů��" );
	set("age", 18);
	
	set("long", @LONG
���ഩ��һ����ɫ���·��������Ǵ������ʵ���գ�������峺�ĺ� 
ˮ����ˮ�е�ӳ�ŵ�Զɽ���������ض����ʡ����������ϸ�������� 
���Ǵ����е�������������䵶���ô��������ʣ�����������һ������ 
Բ������顣������۲������������������ᡣ 
LONG
);

	set("inquiry",([
	"wandao" : (: answer :),
        "Բ���䵶" : (: answer :),
        "�䵶" : (: answer :),
    ]) );
/*    set("chat_chance", 1);
	set("chat_msg", ({
		(: random_move :),
	})); */
        set("combat_exp", 1000000);
	set("attitude", "friendly");
	set("finish", 0);
	set_skill("move", 200);
	set_skill("parry", 250);
	set_skill("blade", 250);
	set_skill("dodge", 250);
	set_skill("moon-blade", 80);
	map_skill("blade", "moon-blade");
	set("reset", 1);
	set("arrive_msg", "��һ��紵���������з·��и�Ӱ�ӡ�һ��������Ӱ�ӣ������ֵ�����������\n");
	setup();
	carry_object("/obj/armor/cloth",
		([ "name": "����",
			"long": "����ɫ���·���\n" ])
		)->wear();
	carry_object(__DIR__"obj/basket")->wield();
	carry_object(__DIR__"obj/wandao");
}

void init(){
	::init();
	if(environment(this_object())->query("short") == "��Ů��") {
		remove_call_out("do_leave");	
		call_out("do_leave", 120);
	}
}

int answer(){
	object stone, me;
	
	me = this_player();
	message_vision("$N����$n��ǳǳ��Ц�ˣ�����Ҳ�õ�����\n", this_object(), me);
	if(environment(this_object())->query("short") == "��Ů��") {
		message_vision("\n$N��Ȼ��ת��ͷ��������˼�ؿ��ž���Զ����һ����ʯ��\n", this_object());
		message_vision("$N�е��ź�����������ǲݵ�Ҷ��ÿ��ֻ��һ�Σ�ÿ��ֻ����Ƭ��������� 
�ó�Щ������Ҷ�Ӿ�Ҫ��ή�ˡ��� \n", this_object());
		environment(this_object())->wang_you();
	}
	return 1;
}

int xiaolou(object me){
	object obj, petal;
	if(!interactive(me) || environment(me) != environment(this_object())) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
	}
	obj = present("eagle man", environment(this_object()));
	message_vision("\n$N��ɭɭ�ĵ�����������С¥һҹ�����ꡣ��\n", obj);
	message_vision("\n$N����ɫ���ˣ���Ȼ����������Ļ�������ס���Ǳ��䵶�ĵ�����\n",
			this_object()); 
	petal = new(__DIR__"obj/petal");
	petal->move(environment(this_object()));
	if(obj) {
		obj->wf(me);
	} else {
		environment(this_object())->do_leavee();
		environment(this_object())->do_leave();
	}
}

int do_killeagle(object me){
	object obj;
	
	message("vision", HIW"\n������ʱ������ʹ�������ĵ����������ʱ��" 
+ me->name() + HIW"���۾��ѽ�Ҫ����\n"NOR, environment(me), me);	
	tell_object(me, HIC"\n�ƺ������������ﵶ��һ�����ڰ��к�Ȼ���˹⣬�¹⣬Բ�¡�\n"NOR); 
	me->unconcious();
	obj = present("eagle man", environment(this_object()));
	message_vision("ֻ������û��$N����ǰ��\n", obj);
	obj->die();
	call_out("check_wake", 5, me);
	return 1;
}

void check_wake(object me){
	object blade;
	
	if(environment(me) != environment(this_object())){
		set("finish", 1);
		do_leave();
	}
	if(me->query_temp("is_unconcious")){
		remove_call_out("check_wake");
		call_out("check_wake", 3, me);
	} else {
		tell_object(me, "\n�������ۣ��Ϳ���һ�ֱ��̰��Բ�£�Ҳ������������˫���¹�������۾���\n"); 
		tell_object(me, "�����������ϻ����ڵ��£��������еڶ�˫��ô�������۾���\n");
		message_vision("$N����$n���ԣ��۾��ﻹ������⡣\n", this_object(), me);
		message_vision("\n$N���ַ�����գ���ɫ�������ˣ������Ӷ��ѿ�ʼ��������Ȼ����������������᣿��\n", 
				this_object());
		message_vision("$N��ɫ��ø���֣��·���˵�����ĺ��¡�$P�����ش���������Ǳ�����ĵ���\n"
+ "����$n���\n", this_object(), me);
		set("finish", 1);
		if(blade = present("moonblade", this_object())){
			blade->move(me);
		}

		blade = present("wang you",me);
		if (blade && REWARD_D->riddle_check(me,"����ëŮ��") == 3)
		{
			destruct(blade);
//			REWARD_D->riddle_done(me,"Բ���䵶",100);
			REWARD_D->riddle_set(me,"����ëŮ��",4);
			blade=new(__DIR__"obj/grass");
			blade->move(me);
			blade->set("owner",me);
		}

		do_leave();
	}
}

int do_leave(){
//	message_vision("hehe\n", this_object());	
	if(find_call_out("check_wake") == 1) {
		call_out("do_leave", 20);
		return 1;
	}
//	message_vision("ha\n", this_object());
	if(this_object()->query("finish")) {
		message_vision("\n$P�����������ȥ����ʧ��ҹĻ�С�\n", this_object());
		message_vision("�����̾Ϣ������Զ��ɽ�ȴ�������ͬ�ľ���ҹ����Զ�ķ硣���� \n", this_object());
		destruct(this_object());
	} else {
		message_vision("$N��Ӱһ�ݣ��������ѵ�ˮ����ʯ����һͣ�پ�û���˺ڰ�֮�С�\n", this_object());
		destruct(this_object());
	}
	return 1;
 
}
int die(){
	object obj;
	if(present("eagle man", environment(this_object()))){
		environment(this_object())->leavee();
	}
	message_vision("ֻ��һ����������$N��Ȼʧȥ����Ӱ��\n", this_object());
	obj = new(__DIR__"obj/basket");
	obj->move(environment(this_object()));
	destruct(this_object());
	return 1;	
}
