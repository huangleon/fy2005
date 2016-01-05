#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int estate();
int fail();

void create()
{
    	set_name("���ϴ�",({"gao laoda","gao"}));
	set("title",HIR"�����"NOR);
   	set("long","
���ϴ󲢲��Ǵ���Ǵ󼧣�����һ˫���������֣�ֻ��������̫����Щ��
����ʾ����˫�ֵ��������־�ǿ���Ը���ս�Ҽ��������ص�ʱ��ʮ
�������һ���˴������ĸ����ӣ������������κ��£���͵����������
ƭ�����������������ѡ���ʱ����˭ֻҪ����һ���·����Ϳ���������
�ϵõ�һ�С�������ȴ����ӵ��һ�С�\n");
     	
     	set("gender","Ů��");
     	set("group","khlr");
     	
    	set("age",32); 	 	

    	set("combat_exp",9500000);  
    	set("attitude", "friendly");
    	
		set("reward_npc",5);
	    	
    	set("inquiry", ([
 		"����":		(: estate() :),
 		"�����":	(: estate() :),
 		"��":		(: estate() :),
 		"����":		(: estate() :),
 		"���ǻ�":	"���ǻ꣬ʯȺ��С�Σ�Ҷ�趼����һ�ִ���ġ�\n",
 		"ʯȺ":		"���ǻ꣬ʯȺ��С�Σ�Ҷ�趼����һ�ִ���ġ�\n",
 		"Ҷ��":		"���ǻ꣬ʯȺ��С�Σ�Ҷ�趼����һ�ִ���ġ�\n",
 		"С��":		"���ǻ꣬ʯȺ��С�Σ�Ҷ�趼����һ�ִ���ġ�\n",
 		"½����":	"½�������Ϻ��꣬�����������ֶ��һ���֪������ʲô�������ˡ�\n",
 		"��������":	"���Ϻ��꣬����ϸ������֪������ʲô�������ˡ�\n",
 		"ʧ��":		(: fail() :),
 		"fail":		(: fail() :),
 		"msg":		"yes",
   		]));
    	
    	set("death_msg",CYN"\n$N��Ц�ŵ�������ȫ��ȥ���ɣ���������á���\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"\n���ϴ���Ϻ�ɫ�Ĵ������£�һ���˾��������ڻ谵�����ڣ�������������
��������η�塪Ҳ�������������ϵ����ƻᱻ�ճ������������ճ����������
Щ���ˡ���Щ���˾��ѽ���˰̣���ԶĨ��ȥ�İ̡���\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_u","nine-moon-claw",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": BLU"����ɫ��ȹ"NOR,
					"long": "һ������ɫ��ȹ��\n",					
					 ]))->wear();   
 
}

int fail(){
	object me=this_player();
	
	if (me->query("timer/��԰ʧ��") + 1440 > time()) {
		command("sigh");
		command("say ���񲮹������ϼ�޻������ܻ��Ż������������ҡ�");
		command("say �����ݱ�һ���������ң������������ԣ�");
		return 1;
	}
	
	message_vision(CYN"���ϴ���Ϻ�ɫ�Ĵ������£�һ���˾��������ڻ谵�����ڣ�������������
��������η�塪Ҳ�������������ϵ����ƻᱻ�ճ������������ճ����������
Щ���ˡ���Щ���˾��ѽ���˰̣���ԶĨ��ȥ�İ̡���\n",me);
	return 1;

}
int estate() {
	object ob,me;
	ob=this_object();
	me=this_player();
	
	
	if (REWARD_D->check_m_success(me,"��԰����")==1
		|| REWARD_D->riddle_check(me,"��԰����")==14) {
		message_vision("
���ϴ������˵�����Ȼ�������񲮣�����ʲô��˵�ģ�\n",me);
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"��԰����")==2) {
		message_vision("
���ϴ�˵�����˵�������Ҫ�ؽ�����֡�\n",me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"��԰����")==13) {
		message_vision("
���ϴ�˵�������Ѿ����ˣ����������ǵĽ�����Ҫ�����ĵ���������ġ�\n",me);
		return 1;
	}
	
	if (me->query("timer/��԰ʧ��") + 1440 > time()) {
		command("sigh");
		command("say ���񲮹������ϼ�޻������ܻ��Ż������������ҡ�");
		command("say �����ݱ�һ���������ң������������ԣ�");
		return 1;
	}
			
	if (REWARD_D->riddle_check(me,"��԰����")) {
		switch (random(3)) {
		case 0:	message_vision("
���ϴ�������������ȥ������$N���֣��������ŵ�����֪����Ҳ�۵úܣ�
��������������ӵģ�����Ҫ����ȥ���Ͳ���ͣ������\n",me);
				break;
		case 1: message_vision("
���ϴ�˵��������һ���ܿ��µĶ��֣���Ҫ���ĵ�һ��������ȡ������
���׵׵����Σ������Ϊ��ɱ�ˣ�����ɱ����ֵ��ˣ�������һ��Ҫ����
û�����Ĳſ��ܵ��֡�\n",me);
				break;
		case 2: message_vision("
���ϴ�˵�����񲮵������˲żüã������｣��������丱�����㴨��
ı���㣬����½����������������������򲻿���С�\n",me);
		}		
		return 1;
	}
	
	if (me->query("combat_exp")<5100000) {
		message_vision("���ϴ��˿�$N˵����������ͣ����°ﲻ���ҵ�æ��\n",me);
		tell_object(me,"����ȼ�90��\n");
		return 1;
	}
	
	message_vision("\n
���ϴ󻷹����ܣ�������˵���������ҵ����ӣ����������е�һ�У�ȫ������
�ġ��������ӣ�ֻ�������ҲƲ��м�С��С�Ĳ��֡���������ģ����ǼҲ���
��ĸ��̾�ó�����������Ժյ����ֺ��ܣ�ֻҪ�ҿ������Ǿͻ�ȥΪ�����κ�
�£���Ϊ����Ҳͬ���������ҡ�

�����������ֵĵ�ȴ�����ҵģ��ܶ���ǰ������������ʱ�һ��������
�ҵĲƲ����������������������԰�ӣ�������ȴ��Ȼ�ò��������ֵĵ�����
��Ϊ���������񲮵ġ�

��Ψһ��Ը���������ŵ�����������������õ������ҵ�һ��Ʋ�������ģ�
��Ҳ�������ڽ������������������ǳ������ҡ�������

���Ѿ�����׼�����µ���ݣ������ȥ��԰Ͷ�����㴨�������������뵽��԰��
��˵���Ҹ��ϴ��Ƽ��ġ�\n\n",me);
	me->delete("marks/kuaihuo/��ʶ��");
	REWARD_D->riddle_set(me,"��԰����", 1);
//	me->set("marks/kuaihuo/�Ӵ�ɱ����",1);
	return 1;
}

int accept_object (object who, object item) {
	
	object paper, me;
	mapping data;
	
	me = who;	
	
	if (REWARD_D->check_m_success(me,"��԰����")==2) {
		message_vision("���ϴ�˵���㲻���Ѿ��ѵ���������ô��\n",me);
		return 0;
	}
	
	if (REWARD_D->check_m_success(me,"��԰����")==1) {
		message_vision("
���ϴ������˵�����Ȼ�������񲮣�����ʲô��˵�ģ�\n",me);
		return 0;
	}
	
				
	if (item->query("kuaihuo") 
		&& item->query("item_owner") == who
		&& item->query("name")=="����") {
			message_vision(CYN"
���ϴ����ſ���ֵĵ����������ã����������Ứ������������\n"NOR,who);

			me->delete_temp("marks/kuaihuo");
			REWARD_D->riddle_done(me,"��԰����",100,2);
		
			data = ([
				"name":		"��԰����",
				"target":	me,
				"att_1":	"con",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);	
		
			me->add("deposit",2000000);
			tell_object(me,YEL"\n���ϴ�˵����������ƽ����Ѿ���������˺š�\n"NOR);
			return 1;
	}
	
	return 0;
}
	