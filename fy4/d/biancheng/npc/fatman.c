#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int test_dart();
void create_level(object me, object who,string name, int exp);

void create()
{
    	set_name("����",({"fatman"}));
	set("title","���سɷ�");
   	set("long","
һ����������̫�֣���������������Ե��е��޴���Ц�������ӱ�ͷ���ԣ�
���뿿�����ϴ��˯��Ȼ��������ǰ����������һ�����µ���֯�С����֡���
�ɵ��ǰ�Ʊ����������ɱ��һ˫���������ָ������֯Ҳ��������ԡ�����
�Ӿ���Ĵָ�����ֵ�Ĵָ����������˵���ܹ���Ǯ���͵���С���Ͽ��˸���
�̣�������̫ƽ���ӡ�
\n");
     	set("gender","����");
    	set("age",42);
    	
    	set("reward_npc",1);
    	set("difficulty",2);
	
    	set("combat_exp",4500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
        	"ǿ��" : 	"������ǿ��������Ҳ��ǿ���������ӿ���ô����ȥѽ��\n",
            "�����ǿ��" : 	"������������կ����Щɽ��ô��\n",
            "���ڵ�ǿ��" : 	"�����������Ǻ����ô����С�ӿɲ������ҡ�\n",
			"Ĵָ":	(: message_vision("������Ц�����͹ٿ���Ц�ɣ�С�����������ָ�׵ġ�\n",this_object()) :),
			"����":		"�ҵ��ֺܸɾ�ѽ���͹�����\n",
			"escort":		(: test_dart :),
			"����":			(: test_dart :),
			"job":			(: test_dart :),	
			"��æ":			(: test_dart :),
			"���������粻ֹ��":		(: test_dart :),
   		]));
    	
    	set("death_msg",CYN"\n$N���յ�˵������Ӧ����Ӧ����\n"NOR);  	
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		 (: auto_smart_fight(20) :),
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"�������ˣ������˸��������ٵ���������ڣ����ۡ��İ�һ�ڲ����ڵ��ϡ�\n",
			"����һָ���Ų���ף��������ת�˸�Ȧ�ӣ����ǵ�ˮ������\n",
			"�������Ŵ����૵�˵�����������粻ֹ����\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","pangu-hammer",1);
		setup();
    	set("force",query("max_force")*2);
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/teapot")->wield();
}


int test_dart()
{
    	object me;
	
    	me=this_player();
    	if (query("marks/gived") )
    	{
        	command("say û�¶���û�¶�������̫ƽ��");
        	return 1;
    	}
    	
    	command("say ��ѽ���������¶�ʵ��æ���߲�����");
    	command("say ������Ů��ȥ�������㣬��һ�����������ô�졣");
    	message_vision(CYN"���ӿ��˿�$N˵����λ"+ RANK_D->query_respect(me) + "��������Ҳȥ����ܲ���˳;�տ�һ���ҹ�Ů����\n"NOR,me);
    	command("say (accept mission)");
    	add_action("do_accept", "accept");
    	return 1;
}

void reset()
{
    	delete("marks/gived");
}


int do_accept(string arg) {
		object me;
		me=this_player();
		
    	if (arg != "mission") return 0;

		if (query("marks/gived"))	{
			 command("say ��ѽ�����и��˱��ˣ�лл���ˡ�");
			 return 1;
		}
		
		command("say ����������Ů������Ů�������������Ƥ��СŮ��������죩�ľ����������Ǹ�ȥ�أ�");
		me->set_temp("marks/biancheng/fatman_1",1);
		add_action("do_answer","answer");
		return 1;
}
		
	

int do_answer(string arg)
{    
    	object ob,cart,escortee;
    	object me,*team;
    	int i, exp;	
    
    	me=this_player();
    	
    	if (!me->query_temp("marks/biancheng/fatman_1"))	return 0;
    		
    	if (arg != "girl" && arg!="lady") return 0;

		if (query("marks/gived"))	{
			 command("say ��ѽ�����и��˱��ˣ�лл���ˡ�");
			 return 1;
		}
    
    	
    	team=me->query_team();
    	
    	if (sizeof(team)==0) team=({me});

   		if (sizeof(team) != 0 && (team[0]!=me)) 
        	return notify_fail("ֻ�ж���������ܽ��ܴ�����\n");
	
    	for (i=0;i<sizeof(team);i++)
    	{
        	if (team[i]->query("combat_exp")<3000000)
        	{
            	command("say ��λ"+RANK_D->query_respect(team[i])+"�����У��ҿɲ����ģ�");
            	return 1;
        	}
    		if (team[i]->query("combat_exp")>exp)
    		exp= team[i]->query("combat_exp");
    	} 

    	set("marks/gived",1);
    	
    	if (arg == "lady")
    		command("say ̫���ˣ���һ·���Ҵ��Ů���Ϳ����տ��ˡ�");
    	else
    		command("say ̫���ˣ���һ·����С��Ů���Ϳ����տ��ˡ�");
    		
   	    me->delete_temp("marks/biancheng/fatman_1");
   	    	
    	say("���ݱı��������ܳ������ֵĹ��\n");
	
		// ����escortee
       	escortee = new(__DIR__"fatmom");
       	escortee->move(environment());
       	
       	     	     	       	
       	// ���� escortee ����
    	escortee->set("combat_exp",exp*3/4);
    	"/feature/nada"->reset_npc(escortee);
    	
    	if (escortee->query("max_kee")> 9000)
    		escortee->set("max_kee",9000);
    	if (escortee->query("max_sen")>9000)
    		escortee->set("max_sen",9000);
    	if (escortee->query("max_gin")>9000)
    		escortee->set("max_gin",9000);
    		
    	escortee->full_me();
    	SMART_D->auto_npc_setup(escortee, "�ֹ���", 150, 170, 1, "/obj/weapon/", "fight_w", "thunderwhip2", 1); 
    	
    	if (arg == "lady") {
       		escortee->set("name","�ֹ���");
       		escortee->ccommand("say ������߯Ҳ���¶���ƾ�ҵĹ���˭�Ҷ���һ��ͷ������");
       		escortee->set("escortee","active");
       		
       	} else	{
       		escortee->set("name","��С����");
       		escortee->ccommand("say ��������λ"+RANK_D->query_respect(me)+"��������ͷ��İɡ�");
       		escortee->set("escortee","passive");
       		
       	}
    	
    	// ����extra NPC escorter
/*    	ob=new(__DIR__"biaoshia");
    	ob->move(environment());
    	ob->set_leader(escortee);
    	ob->set_temp("protecting",escortee);
    	ob->set("combat_exp",exp);	
    	"/feature/nada"->reset_npc(ob);
    	SMART_D->auto_npc_setup(escortee, "�ֹ���", 200, 170, 1, "/obj/weapon/", "fight_w", "thunderwhip2", 1); */
    	    	
    	escortee->init_escort(me,exp);
    	return 1;	
}