#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("����",({"sun yubo","sun"}));
	set("title",HIY"�ջ�԰"NOR);
	set("long","
�ϲ��������񲮣�û��������֪�����񲮾����Ǹ���ô�����ˣ���������ʲô
�¡�������˭�����������˲��ܽ��������ʱ������ȥ�������������Ӳ��д�
���ã�Ҳ�����տ���ŵ��ֻҪ����Ӧ���㣬�������㶼���Է���һ�ߣ���Ϊ
����������ʧ�����㲻�ظ����κα��������ڲ��������������ѡ��������ô
�¿������������Ὣ�������������ϣ���취Ϊ��������Ϊ��ϲ����ȫ��
�ˣ�ϲ��������������һ�в��������£��������������յ�ũ�ˣ�����ȳ漱
�ڳ���һ��������Ȼ��ϣ�����꣬������ȴ�����ڲ�֪������������\n");
   	
     	set("gender","����");
     	
    	set("age",72); 	 	
    	
    	set("combat_exp",100000000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"*":	(: message_vision(CYN"�ϲ�ЦЦ��һ�Բ�����\n"NOR,this_object()) :),
   		]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","taiji",1);
	
		setup();
    	carry_object(__DIR__"obj/cyancloth")->wear();
 
}


string *event1_msg=	({
	
	"��Ȼ�Ը�¥ʧ�㣬��Ȼ�Թ������˺ڰ����޵���Ԩ��
������Щ��û���ϲ�����������ĸо������¡�",

    	"��Ϊ���ѿ���վ������ǰ�ĺ�Ȼ�������㴨��",

    	"�����������ε��ˣ��������ѣ����Ķ��ӡ�",

    	"���㴨����һ����鶼û�У�����ؿ���������Ȼ�������õ��������롣",

    	"�ϲ�ҧ�������ѿɸо����Լ���ָ����䡣",

    	"���㴨�����㳣˵�ҵ��������ѿ��������°�����һ�����ƼҵĶ�ɰ�Ͷ�
��޼���Ȳ��ϣ���Ϊ�����ְ������оȣ�������ȴû�н�ҩ��",

    	"���㴨������������������С���������ע��������Ҳ���ܵ��֡�",
    	
    	"�ϲ��ĺ����ѽ����̴٣���������ʲô�ط��������㣿",

    	"���㴨����û�С�",

    	"�ϲ�������ô��Ϊ����˺��ң�",

    	"���㴨�����Ҳ����㣬��ֻ����Ҫ��������ֻ��Ҫ��ĵ�λ�ͲƱ���",
    	
    	"���㴨ת��ͷ������˵���������Ѿ����Զ����ˡ�",

});

void init(){
		add_action("do_answer","answer");		
		if (interactive(this_player()))
			this_player()->delete_temp("marks/kuaihuo/laobo_1");
		::init();
}


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) || me->is_fighting()) {
		return;
	}
	
	tell_object(me,CYN"\n"+event1_msg[count]+"\n"NOR);
	if(++count==sizeof(event1_msg))
	{
		tell_object(me,WHT"\n��������ɸ��ϴ�ʹ�������ʱ�������Ƿ����̶��֣�\n"NOR);
		tell_object(me,WHT"answer yes/no\n"NOR);
		me->set_temp("marks/kuaihuo/laobo_1",1);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}

int accept_object(object me, object item) {
	object ob, lu;
	if (item->name()!="�缦")	return 0;
	ob = this_object();
	if (item->query("item_owner")!= me)
		return notify_fail("�ϲ�˵������ô�������Ҫ��Ķ����أ�\n");
	
	message_vision(CYN"
�ϲ�������վ�����������ߵ�����ǰ��Ц��Ц�����͵���������ļ�ͷ��\n"NOR,ob);
	item->move(ob);
	ob->ccommand("eat chicken");
	me->delete_temp("marks/kuaihuo/lv_cook");
	message_vision(CYN"
�ϲ���Ȼһ㶣�����һ�����缦���ڵ��ϣ�����һ�죬�ѵ������Ѩ����

������ʱ���ź�Ȼ��ײ����ײ�÷��顣

һ����Ӱ�ӽ�����

�ߵ㺮�ǣ�������������ϲ��ı�����\n\n"NOR,ob);
	
	me->start_busy(1000);
	ob->set("combat_exp",5000000);
	ob->set("level", 90);
	ob->set("eff_kee",5000);
	ob->set("kee",5000);
	ob->set("str",80);
	ob->set("no_heal",1);
	lu = new(__DIR__"lv2");
	lu ->move(environment(me));
	ob->set("NO_KILL","�����ڲ��ܶ�������ɱʲô�ˣ�\n");
	lu->set("NO_KILL","�����ڲ��ܶ�������ɱʲô�ˣ�\n");
	call_out("event1",2,me,0);
	return 1;
}

int do_answer(string arg){
	object me, ob, lu;
	me = this_player();
	ob = this_object();
	
	if (!me->query_temp("marks/kuaihuo/laobo_1"))
		return 0;
	
	if (!arg || (arg!="yes" && arg!="no"))
		return notify_fail("answer yes/no ");
	
	if (arg == "yes") {
		message_vision(YEL"
���㴨һ�����Ŀ��㱻��ס��Ѩ��������һ�����ϲ�չ��������\n"NOR,me);
		ob->delete("NO_KILL");
		lu = present("lv xiangchuan",environment(me));
		lu->delete("NO_KILL");
		me->stop_busy();
		ob->kill_ob(me);
		me->kill_ob(ob);
		me->delete_temp("marks/kuaihuo/laobo_1");
		me->set_temp("marks/kuaihuo/��ɱ�ϲ�",1);	
		return 1;
	}
	if (arg = "no") {
		message_vision(YEL"
$Nҡҡͷ˵���Ҳ��ܳ���֮Σ���ο�����Щ�������˽��ϲ���Ϊ�ˣ����ٲ���
����Ϊ��������������������������������֮ͽ��\n"NOR,me);
		tell_object(me,YEL"
��ǿ���������忪�����Ѩ����\n"NOR,me);
		me->stop_busy();
		ob->delete("NO_KILL");
		lu = present("lv xiangchuan",environment(me));
		if (lu) {
			lu->delete("NO_KILL");
			lu->kill_ob(me);
		} else {
			tell_object(me,"bugs, please report it to wizard.\n");
			return 1;
		}
		me->kill_ob(lu);
		me->delete_temp("marks/kuaihuo/laobo_1");
		me->set_temp("marks/kuaihuo/��ɱ���㴨",1);
		return 1;
	}
	return 1;
}


void die(){
	object room, sunju, bed, me, owner,lu;
	
	if(objectp(me=query_temp("last_damage_from") ))     
        	if(owner=me->query("possessed")) {
			me = owner;
	} 
	if (!me) ::die();
	
	room = find_object(AREA_ZANGBEI"tunnel4");
	if (!room) room = load_object(AREA_ZANGBEI"tunnel4");
	if (!sunju = present("sun ju", room)) {
		
		if ( me->query_temp("marks/kuaihuo/��ɱ�ϲ�"))
			REWARD_D->riddle_set(me,"��԰����",13);
	//	me->set("marks/kuaihuo/ɱ����",1);
		lu = present("lv xiangchuan",environment(me));
		if (lu) {
			message_vision(CYN"
���㴨������������Ц�������󹦸�ɣ���ѡ��ĺ���ȷ����

���㴨�ֵ��������ϴ�Ҫ�ĵ�����һ�������������ȡ����

����δ�ϣ���Խ����ȥ��\n\n"NOR,me);
			destruct(lu);
		}
		::die();
		return;
	}
	
	message_vision(CYN"
�ϲ���ȻЦ��Ц�����������Ҳ������˵��һ�仰����˵������û�о��Ե��£�
��ȴһ��Ҫ˵�Ҿ���û�����ߡ�

�ϲ����˺�Ȼ�Ӵ���������ȥ����Ȼ�����ˡ�

���ᣬ�ᣬ�ᡱһ�������죬ʮ���㺮����ڴ��ϡ�

������ȴ��û���ˡ�

���㴨��̾һ�������ˣ����ǰ��ˣ�����

˵����ɫ�Ұף�Խ��������\n\n"NOR,this_object());
	lu = present("lv xiangchuan",environment(this_object()));
	if (lu) {
		destruct(lu);
	}
	environment(this_object())->set("escaped",1);
	tell_object(me,WHT"����ʧ�ܡ���������ͷ�����ɡ�\n"NOR);
	REWARD_D->riddle_clear(me,"��԰����");
	me->delete_temp("marks/kuaihuo");		
	me->set("timer/��԰ʧ��",time());		// Time to restart.
	destruct(this_object());
	return;
}


void thank_you(object me){
	
	message_vision(CYN"

�ϲ�Ц�ˣ���Ц����ȴ�·���˵���������������ᡣ

���㴨�������������Գɵ���ľ�����ˣ�

�ϲ���Ц�����Щ�˸У����ѽ������ʣ�һ���ֵ���

����ǧ��ĪҪ��Ϊ�κ��·��գ���������£�ȥ��С������ȥ����

����Ҫ����Ϊ�һ���ȥ���úõػ���ȥ��������ֵػ���ȥ����\n\n"NOR,me);
	this_object()->delete("no_heal");
	this_object()->set("combat_exp",100000000);
	this_object()->set("level",589);
	return;
}

