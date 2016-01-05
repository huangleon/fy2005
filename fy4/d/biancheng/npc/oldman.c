#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();

void create()
{
    	set_name("��������",({"oldman"}));
	set("long","
�����Ѿ���ʮ�����ˣ��������ֱͦ���޷���׺�ϡ���ˣ�¶��������ͻ���
���š�������������������ƣ�ÿһ���������µĺۼ���\n");
     	
     	set("gender","����");
    	set("attitude", "friendly");
    	set("group","citizen");
    	
    	set("combat_exp",4000000);  
    	set("age",72);
    	 	 	
		set("inquiry", ([
        	"����" : 	(: show_me :),
           	"��" :		 (: show_me :),
           	"�ص�" :	 (: show_me :),
           	"ghost": 	 (: show_me :),
   		]));

    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"���������˰���ǿ������Ĺ������\n",

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"˵�����������������ͺ��ˡ���\n",
    	}) );    	    	
    	
    	
		auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","healer",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/stick")->wield();
}


void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object book;
	int count;
	
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query("marks/wanma/zombie")>= ob->query("achieved_level")+40) {
		command("touch "+ob->get_id());
		command("say ̫��л�ˣ���ص�Ӧ����̫ƽһ���ˣ�");
		if (!REWARD_D->check_m_success(ob,"ɨ����ʬ")) {
			REWARD_D->riddle_done(ob,"ɨ����ʬ",50,1);
			ob->set("marks/e_wanma/ɨ����ʬ",1);
			tell_object(ob,HIW"���������ԶС������������ˣ�\n"NOR);
		} 
		tell_object(ob,CYN"\n���������ͳ�һ���ƾɵ�С����˵���Ȿ����������һ����ͷ�񵽵ģ�\n"
+ RANK_D->query_respect(ob)+"��ħ������˵��������Щ�ô���\n"NOR);
		ob->delete("marks/wanma/zombie");
		book = new(BOOKS"learn/spells_150");
		book->move(ob);
		return;
	}	
	if ( REWARD_D->check_m_success(ob,"ɨ����ʬ")){
		command("greet "+ob->query("id"));
		return;
	}
	if (REWARD_D->riddle_check(ob,"ɨ����ʬ")) {
		command("say �����δ��������λ"+RANK_D->query_respect(ob)+"���ö��Ŭ������");
		count = ob->query("achieved_level")+40;
		count = ob->query("marks/wanma/zombie")* 100 / count;
		tell_object(ob,"���������˰ٷ�֮"+chinese_number(count)+"Ү����\n");
		return;
	}		
	command("say ��λ"+RANK_D->query_respect(ob)+"��ֹ�����ص��й���̫ƽ����");
	return;	
}



int show_me()	{
	object me,ob;
	
	me=this_player();
	ob=this_object();
	if (REWARD_D->riddle_check(me,"ɨ����ʬ")) {
		command("say ��ʬ��������صز�̫ƽ��!");
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"ɨ����ʬ")) {
		command("say �����İ������������ϵ����ָ���ɨĹ�ˡ�");
		return 1;
	}
	command("say ��ص��԰���ǰ��ʼ�ֹ����������йֽ���������������Ҳ��̫ƽ�ˡ�");
	command("say ���ϵ��˶�����ȥɨĹ��Ҳ�м�������Ľ���ȥ����һȥ��û��������");
	command("shiver");
	command("say ǰЩ���и������·��Ĺ�ү����а���˽�ȥ�����ڻ�û����Ϣ�������׶༪�١�");
	command("say �����ܰ�������Ķ�������ɾ�������ȫ�����ٶ��м�������");
	command("say ��һ��������������ˣ��ҿ��ͷ�ĸ�ͷ��kneel�������ˡ�");
	tell_object(me,"˵�գ����˲�ΡΡ���ߵ�һ�ԡ� \n");
	REWARD_D->riddle_set(me,"ɨ����ʬ",1);
	return 1;
}

