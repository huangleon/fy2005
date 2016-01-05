#include <ansi.h>
inherit SMART_NPC;

int do_poison();

void create()
{
	set_name("��������",({"bandit leader","leader"}));
	set("long", "
һ��ͷ�����������µ�ë�����ӣ�һ��ִ�žƱ���һ�ְ�������
����ʯ���ĺ�������������۹�ɨ������ŭ��������\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 4500000);
	set("group","bandit");
	
	set("inquiry",([
		"С��":		"action�����������������һ˿����֮ɫ��С�̣�û��˵����\n",
		"˾����":	"action����������Ц������˵�����Ǹ����׼����˾���̣�\n",
	]));
	
    set("nb_chat_chance", 100);
    set("nb_chat_msg_combat", ([
		5: (:do_poison() :),
    ]) );  
		
	set("chat_chance", 1);
    set("chat_msg", ({
    	"��������˵��û�¶����߰ɣ�����������͡�\n",
     }) );
     
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: auto_smart_fight(40) :),    
    }) );
	
	auto_npc_setup("guardian",200,175,0,"/obj/weapon/","fighter_w","dragonstrike",1);
	setup();
	carry_object(__DIR__"obj/oldcloth")->wear();	
}


void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_answer","answer");
}

void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() ) return;
		command("say ���²����������λ��������˭��");
}

int do_answer(string arg){
	
	object me;
	
	me = this_player();
	
	if (arg == "С��"|| arg=="˾��С��") {
		if (!REWARD_D->riddle_check(me,"˾��С��")) {
			command("say ��ʱ�����޹أ��αؽ��˻�ˮ��");
			return 1;
		}
		command("hmm");
		command("say ��˵С�����ҵ����½��ߣ�����֤�������ҿ���");
		return 1;
	}
	
	if (arg == "����" || arg == "��������"){
		command("shake");
		command("say ����ʶ�㡣");
		return 1;
	}
	
	command("say û��˵��");	
	return 1;	
}

int accept_object(object me, object obj){
	int stage;
	
	if (obj->query("24dao")) {
		
		stage = REWARD_D->riddle_check(me,"˾��С��");
		switch (stage) {
			case 0: command("say ���������޹أ��αؽ��˻�ˮ��");
					return 1;
			case 1:	command("say ��С����˭���㶼��֪������������������");
					return 0;
			case 2: 
			case 3:
			case 4:	command("hmm");
					command("say ������С�������ǵĶ�ͷ�����ⲻ����˵�����������С�");
					if (REWARD_D->riddle_check(me,"˾��С��")==2)
						REWARD_D->riddle_set(me,"˾��С��",3);
					return 1;
		}			
	}
	
	if (obj->query("24dao_ren")) {
		stage = REWARD_D->riddle_check(me,"˾��С��");
		switch (stage) {
			case 0: command("say ���������޹أ��αؽ��˻�ˮ��");
					return 0;
			case 1:	command("say ��С���ӵ�������ø���������");
					return 0;
			case 2: command("say �ⶫ����������ʲô��ϵ��");
					return 0;
			case 3:	
			case 4:	command("hmm");
					command("say �ã���Ȼ��ˣ����˲�˵�����ˡ�");
					call_out("event1",2,me,0);
					me->start_busy(12);
					return 1;
		}
	}
	
	return 0;
}


string *event1_msg=	({
	CYN"��������˵��"CYN"��֪��������⣬���Ƿ�֪���ҵ�������\n"NOR,
	CYN"���֪��С�̵ĸ�����˭������������˾���̵����������㲻��İ����\n"NOR
	CYN"�������������¶��Թ��֮ɫ��"CYN"��ȫ��һʮ���ڣ���������δ���µ�
���ӣ�����������˾���̵Ľ��¡�\n"NOR,
	CYN"��������һָ��Χ�����⼸���ֵܣ�֮�����ڴ��ʵ���Ҳ�ǰ�˾�������͡�\n"NOR,
	CYN"���������գ�������˹�ʱ��˾�����Ӿ��Ѳ������Һ��Ҳ�����������ˣ�
���Ҳ������ۣ����������˸����֡�\n"NOR,
	CYN"��������˵��"CYN"��ծ�ӻ����Թ���ˣ����ο����Ӵ�С�ڶ��˹ȳ��󣬶���
Ŀ妽������׼���֮�£����ס�н���Ѫ�ȳ�ɱ֮�У������䳤������һ
��˾���̣�����ʹ˳�ȥ���Ծ��󻼣�\n"NOR,
	CYN"���²��ض�˵������ִ���ͷ��ֻ����ɱ�ҡ�\n"NOR,
	});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) 
		|| this_object()->is_fighting() 
		) return;
	
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		tell_object(me, CYN"����ɱ��"+chinese_number(me->query("MKS"))+"�ˣ��ҵ���Ȼ�����������С�\n"NOR);
		message_vision(YEL"\n�������쿨��һ���������е�С������÷��顣\n"NOR,me);
		if (REWARD_D->riddle_check(me,"˾��С��")==3)
			REWARD_D->riddle_set(me,"˾��С��",4);
			set("poisoned",1);
		return;
	}
	else 
		call_out("event1",1,me,count);
	return ;
}

int do_poison(){
	
	object room;
	
	if (!is_fighting()|| !query("poisoned"))	return 1;
	
	message_vision(CYN"
���������Ȼ��ɫ���Ϸ��࣬��ס�Լ��ĺ����ɺɵصͺ�������

"HIM"���ꡣ���ϳ�˿������"NOR+CYN"

����˾���̵�ʲô�ˣ�

��������е����á��ã�����Ҳ����Ź����ǵġ�

�����������ײײ�س�������ʡ�

һ�������Ľ������˳�����

������\n"NOR,this_object());

	room = find_object(AREA_ZANGBEI"innercamp");
	if (!room)	room= load_object(AREA_ZANGBEI"innercamp");
	room->set("poisoned",1);
	this_object()->move(room);	
	::die();
	return 1;
}
	
	
void die(){
	object room;
	remove_all_killer();	
	message_vision(CYN"
��������е����á��ã�����Ҳ����Ź����ǵġ�

�����������ײײ�س�������ʡ�

һ�������Ľ������˳�����

������\n"NOR,this_object());

	room = find_object(AREA_ZANGBEI"innercamp");
	if (!room)	room= load_object(AREA_ZANGBEI"innercamp");
	this_object()->move(room);	
	::die();
}

		