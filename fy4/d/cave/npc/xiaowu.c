#include <ansi.h>
inherit SMART_NPC;
int gao();

void create()
{
    	set_name("С��", ({"xiao wu","wu"}) );
    	set("gender", "����" );
    	set("nickname", HIC"���ֽ�"NOR);
    	set("title", "������ �̿�");
    	set("long", "
С�俴���·��Ǹ�����㡢����ɢ���ˣ���ϲ��Ц����ϲ���ơ�û����������
����ɱ��ʱ�Ķ����Ƕ�ôѸ�٣���ô׼ȷ������Ҫ��Ϲ������ۣ����Ľ��;�
����������ĵط���\n");
 	set("attitude", "friendly");
    	set("age", 25);
		set("per", 25);
        set("combat_exp", 3000000);
    	set("class","assassin");
    	
    	set("reward_npc", 1);
        set("difficulty", 3);
            	
    	set("chat_chance", 1);
    	set("chat_msg", ({
 	   "С��������ü���૵����������ȳ�������³ç�һ��أ�\n",
    	}) );
		set("inquiry", ([
		"gaoli" : (: gao :),
		"gao" : (: gao :),
		"����" : (: gao :),
		"gao li" : (: gao :),
		]));
		set("jadebox", 1);
	
	       	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(60) :),
        }) );	  
    		
		auto_npc_setup("wang",180,180,0,"/obj/weapon/","fighter_w","sharen-sword",1);
    	setup();
    	carry_object("/d/fugui/npc/obj/m_cloth3")->wear();
    	carry_object(__DIR__"obj/windsword")->wield();
       	if (!random(5)) carry_object(__DIR__"obj/stone_2");

}

int gao(){
	object me;
	me = this_player();
	if(query("answering")){
		return notify_fail("С���ƺ�����æ��\n");
	}
	if(me->query("combat_exp") < 1000000) {
		message_vision("$N������$nһ����������ü��������û����������������һ���غ��ˡ���\n", 
				this_object(), me);
	} else if (me->query_temp("marks/underground_gao")) {
		message_vision("$N����һ����$n�����Ҹող��Ǹ�����ȸ��������ѵ��Ǹ����Ӳ����ã�\n",
				this_object(), me);
	} else {
		message_vision("$NƲ��$nһ�ۣ���˼�˰��Σ�˫��ͻȻ�ų����������ˣ�������������
һ�����Ծȸ�����˫˫��һ�����ԡ�\n", this_object(), me);
		set("answering", 1);
		call_out("give_jadebox", 2, me);
	}
	return 1;
}

void give_jadebox(object me){
	object box;
	if(!interactive(me) || environment(me) != environment(this_object())){
		return;
	}  
	message_vision("$N����Ц��Ц���ã���Ͱ����ȸ����н������������ţ���������ȸ�� 
�����������棬����ȸ����ڵ�����Ŀ�ģ�����ɱ�ˣ����Ǿ��������ԡ����� 
�����򲻵���ʱ������Ҫ������\n", this_object(), me); 	
	me->set_temp("marks/underground_gao", 1);
	box = new(__DIR__"obj/jadebox");
	if(objectp(box)){
		box->move(me);
	}
	delete("answering");
	return;
}
