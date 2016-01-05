#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();

void create()
{
    	set_name("�ձ���",({"tao baoyi","tao","baoyi"}));
		set("title","��������");
   		set("long","�ձ����Ǹϳ��İ�ʽ���Դ�ǰ��ϱ�������ֲֹ�������Ͷҽ��������Խ��Խ�\n");
     	
     	set("gender","����");
    	set("attitude", "friendly");
    	set("group","citizen");
    	
    	set("combat_exp",600000);  
    	set("age",42);
    	   	
    	set("inquiry", ([
        	"����" : 	(: show_me :),
             	"ϱ��" :	 (: show_me :),
             	"�ֲ�" :	 (: show_me :),
             	"��" :		 (: show_me :),
             	"��ҩ" :	 (: show_me :),
             	"ҩ" :	 	(: show_me :),
             	"ҩ��" :	"��ҩ��Ҫ��������ҩ���ӣ������Ķ�ȥ��ѽ��\n",
             	"������" :	"�����Ķ�ȥ��������ѽ��\n",
             	"ҩ����" :	"�����Ķ�ȥ��������ѽ��\n",
             	"����٢" :  "���Ƴ����ҽ������û��˵����\n",
   		]));

    	set("death_msg",CYN"\n$N�޺޵�˵�����������ݣ������˶����Ź�����\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"�е��������˰���ǿ����������������\n",

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
//		name()+"�����Դ�����������˵�����������������ǰ�������������ˡ�����\n",
    	}) );    	    	
    	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
}



int show_me()	{
	object me,ob;
	
	me=this_player();
	ob=this_object();
	if (REWARD_D->check_m_success( me, "��������")) {
		command("say �����������ҩ���ӣ���ϱ�����ڲ��ö��ˣ��������������������С�ӡ�");
		return 1;
	}
	command("say �Դ���ϱ�������ⲡ��Ҳ��֪���˶�����ҽ�����˶��ٷ��ӣ�ȴûʲô�ô���");
	command("say �ҵ��ڵ�����һ�Σ������ڷ��Ƴ��ҵ��ˡ�����٢������������һ��ҩ����");
	command("say ��������ҩ��Ҫ��������ҩ���ӣ������Ķ�ȥ��ѽ��");
	command("cry tao baoyi");
	return 1;
}



int accept_object(object who, object ob)
{

	string *mbook = ({"hammer_50","throwing_50","axe_50","staff_50","whip_50" });
	object book;
	
	if (ob->name()==HIY"������"NOR) {
		command("touch "+who->get_id());
		command("say ̫��л�ˣ��Ҿ���������Ӣ�۵Ĵ����µģ�");
	
		book = new(BOOKS+mbook[random(5)]);
		if (objectp(book)) {
			if (sizeof(all_inventory(who))<14){
				book->move(who);
				ccommand("say �Ȿ�ҼҴ��Ľ���Ҫ���͸���ɡ�\n");
				tell_object(who,"�ձ�����������ó�һ���ɾɵ�С���Ӹ��㡣\n");
			} else
				destruct(book);
		}			
			
		REWARD_D->riddle_done( who, "��������",20, 1);
		
		if (!who->query("marks/e_wanma/��������"))
		{
			who->set("marks/e_wanma/��������",1);
			tell_object(who,HIW"���������ԶС������������ˣ�\n"NOR);
		}
		
		
		QUESTS_D->special_reward(who,"��������");
		return 1;		
	}
	return 0;
}			

			 

