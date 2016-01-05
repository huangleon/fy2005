// teacher.c
//Modified by justdoit 04/11/2001

inherit NPC;
#include <ansi.h>

int test_dart();
void create_level(object me, object who,string name, int exp);

void create()
{
        set_name("����", ({ "zha meng", "meng" }) );
    	set("long","
��ʨ�Ʋ����������׼ҵ��ӣ��˲��������ˬ���ҹ㽻���ѣ�
������������̵ģ�ֻҪΪ�ھ�[37m����[32m�����ͿϽ̡�
�����롡����硡��������������룩\n"
        );
    	set("nickname", HIY "��ʨ��"NOR);
    	set("gender", "����" );
    	set("age", 32);
    	create_family("����", 21, "�׼ҵ���");
    	set("skill_public",1);
    	set("reward_npc", 1);
    	set("difficulty", 4);
    	set("attitude", "peaceful");
    	
       	set("inquiry",	([
        	"mission" : 	(: test_dart :),
        	"����" : 	(: test_dart :),
		 "����": 	"��������ȱ���֣���ȥ��Щæ�ɣ��������ҽ������֡�
������������������������ᡡ����硡������衡����\n",
		 "����": 	"��������ȱ���֣���ȥ��Щæ�ɣ��������ҽ������֡�
������������������������ᡡ����硡������衡����\n",
		 "work": 	"��������ȱ���֣���ȥ��Щæ�ɣ��������ҽ������֡�
������������������������ᡡ����硡������衡����\n",
		 "job": 	"��������ȱ���֣���ȥ��Щæ�ɣ��������ҽ������֡�
������������������������ᡡ����硡������衡����\n",
		 "chufeng":	"ѧ���ҵ��޺�ȭ�����������г���չ�ᣨ����������������磩",
		 "����չ��":	"ѧ���ҵ��޺�ȭ�����������г���չ�ᣨ����������������磩",
		 "�޺�ȭ":	"ѧ���ҵ��޺�ȭ�����������г���չ�ᣨ����������������磩",
		 "�����޳���":   "action����ҡҡͷ˵�������޳�����Ȼ���ף�ȴûʲô������ʽ��\n",
		 "wuchen-steps":   "action����ҡҡͷ˵�������޳�����Ȼ���ף�ȴûʲô������ʽ��\n",
	]) );
    	
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"����˵����������ھ����ⲻ��\n",
            	"����˵�������ڣ�����������£�������\n",
            	"����˵������һ�С�����չ�ᡱ��chufeng�������޺�ȭ�ľ��裡\n",
            	"����˵����С�ӣ������ǲ�����ѧ����ô��\n",
            }) );
    	  
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
          (: perform_action, "unarmed.chufeng" :)
        }) );
    	
    	set_skill("unarmed", 100);
    	set_skill("literate", 100);
    	set_skill("force", 100);
    	set_skill("dodge",100);
    	set_skill("move", 100);
    	set_skill("parry",100);
    	set_skill("wuchen-steps",200);
    	set_skill("luohan-quan",200);
    	set_skill("foreknowledge",100);
    	set_skill("chanting",100);
    	set_skill("perception",100);
    	map_skill("unarmed", "luohan-quan");
    	map_skill("dodge","wuchen-steps");
    
    	set("combat_exp", 3500000);
    	setup();
    	carry_object(__DIR__"obj/jinzhuang")->wear();
}

int recognize_apprentice(object ob)
{
    	if((time() - ob->query("marks/��ʨ") ) > 1800  ){
        	say("����˵�����㣮�������ܾ�ûΪ�ھֳ�������....\n");
        	return 0;
    	}
	return 1;
}

int test_dart()
{
    	object me;
	
    	me=this_player();
    	if (query("marks/gived")+600> time() )
    	{
        	command("say �����ھ�����û����Ҫ�����ڡ�");
        	return 1;
    	}
    	command("say �����Ϲ�Ǯׯ��һ��������Ҫ�˵����������Ը��Э�����ǣ�(accept mission)");
    	add_action("do_accept", "accept");
    	return 1;
}

int do_accept(string arg)
{    
    	object ob,cart,biaotou;
    	object me,*team;
    	int i, exp;	
    
    	if (arg != "mission") return 0;
    
    	me=this_player();
    	team=me->query_team();
    	if (sizeof(team)==0) team=({me});

   		if (sizeof(team) != 0 && (team[0]!=me)) 
        	return notify_fail("ֻ�ж����������������ڡ�\n");
	
    	for (i=0;i<sizeof(team);i++)
    	{
        	if (!intp(team[i]->query("deposit")) 
        		|| team[i]->query("deposit")<200000)
        	{
            		command("say ������Σ�յ��£��ҿ�"+RANK_D->query_respect(team[i])+"û���⳥������");
            		return 1;
        	}
    		if (team[i]->query("combat_exp")>exp)
    		exp= team[i]->query("combat_exp");
    	} 

		if (exp < 1000000){
            command("say ����·;Σ�գ��ҿ���λС�����ƺ����ˣ�����������߾�����Ҫ28�����ϣ�");
            return 1;
        }
			
//begin: modified by justdoit
	if (query("marks/gived")+ 600 > time())	{
		 command("say �������ˣ��Ѿ����˽�����֧���ˡ�");
		 return 1;
	}
//end: modified by justdoit

    	set("marks/gived",time());
    	command("say �ðɡ���������ͷ�߰ɡ�");
    	command("say ���ڿ���Ҫ��˫�ݵģ�һ·С�ġ�");
    
    	me->set("marks/����",time());	
    	say("һ���ڳ�����Ժʻ����\n");
	
    	ob=new(__DIR__"obj/cart");
    	ob->move(environment());
    	cart=ob;
	
    	biaotou=new(__DIR__"biaotou");
    	biaotou->move(environment());
    	biaotou->get_quest("/d/fy/cartway1");
    	biaotou->set_cart(cart);
    	biaotou->set_protector(team);
    	biaotou->set("combat_exp",exp);
    	create_level(me,biaotou,"biaotou",exp);
	
    	ob=new("/d/fy/obj/biaoyin");
    	ob->set_amount(10+random(10));
    	ob->move(cart);
	
    	ob=new(__DIR__"biaoshia");
    	ob->move(environment());
    	ob->set_leader(biaotou);
    	ob->set_temp("protecting",cart);
    	ob->set("combat_exp",exp/2);	
    	create_level(me, ob,"biao",3*exp/4);
 
    	ob=new(__DIR__"biaoshi1a");
    	ob->move(environment());
    	ob->set_leader(biaotou);
    	ob->set_temp("protecting",cart);
    	ob->set("combat_exp",exp/2);
    	create_level(me, ob,"biao",3*exp/4);		
	
    	ob=new(__DIR__"biaoshi1a");
    	ob->move(environment());
    	ob->set_leader(biaotou);
    	ob->set_temp("protecting",cart);
    	ob->set("combat_exp",exp/2);
    	create_level(me, ob,"biao",3*exp/4);	
    
    	for(i=0;i<sizeof(team);i++)
       		team[i]->set_temp("protecting",cart);
    	
    	me->set_temp("protecting",cart);
    	me->set_leader(biaotou);
    	biaotou->go_now();
    	return 1;	
}

void reset()
{
    	delete("marks/gived");
}



void create_level(object me, object who,string name, int exp)
{
 	int level;
 	level=100+130*(exp-1000000)/5500000;
 	if (exp<1000000) level=100;
 	if (exp>6400000) level=230;
 	level=level*level/100;
 	if (name=="biaotou") {
	 	who->set("toughness",200);
	 	"/feature/nada"->reset_npc(who);
		who->set("agi",who->query("agi")*3/4);
    	who->set("str",who->query("str")/2);
    	who->full_me();		
		who->set_skill("hammer", 70 + random(level/2));
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("changquan",50+random(level/2));
		who->set_skill("unarmed",70 + random(level/2));
		return;
	} 	
 	if (name=="biao") {
	 	"/feature/nada"->reset_npc(who);
		who->set("agi",who->query("agi"));
    	who->set("str",who->query("str"));
    	who->full_me();		
		who->set_skill("hammer", 70 + random(level/2));
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("changquan",50+random(level/2));
		who->set_skill("unarmed",70 + random(level/2));
		return;
	}
	if (name=="gangster" || name == "gangsterboss") {
		who->set("toughness",70);
    	"/feature/nada"->reset_npc(who);
    	who->set("agi",who->query("agi")*3/4);
    	who->set("str",who->query("str")*3/4);
    	who->full_me();		
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("blade",70+random(level/2));
		who->set_skill("demon-steps",70+random(level/2));
		who->set_skill("unarmed",70+ random(level/2));
		who->set_skill("demon-strike",50+random(level/8));
		who->set_skill("demon-blade",50+random(level/8));
		return;
	}

}