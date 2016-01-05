#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack();

inherit F_MASTER;
inherit NPC;
void imbue_event(object me);
void create()
{
        set_name("���ʮ����", ({ "tianfeng"}) );
        set("gender", "����" );
        set("age", 55);
        set("nickname", CYN "��������" NOR);
        set("long", 
"һ����ɫ���ƣ�Ũü��ȧ���������ߣ�������ɱ��������ϥ����ɽ��֮�ϣ�
�¾���¶�����㣬ȴ��һ˫�߳���ľ��ľ��˷���ǰ��ľ���Ͼ��ַ��ű���
�ʳ�����\n");
//    	create_family("һ����", 7, "�Ҷ�");
//      set("rank_nogen",1);
//      set("ranks",({"����","����","����",RED"��ɲ"NOR,HIR"����"NOR}));
//      set("rank_levels",({32000,512000,1536000,3456000 }));
        set("combat_exp", 3200000);
        set("attitude", "friendly");
        set("reward_npc", 1);
		set("difficulty", 5);
	
		set("skill_public",1);
	
        set_skill("unarmed", 140);
    	set_skill("ghosty-force", 200);
    	set_skill("enmeiryu",150);
    	set_skill("ittouryu",160);
    	set_skill("ninjitsu",200);
		set_skill("dodge", 140);
		set_skill("ghosty-steps",200);
		set_skill("blade",140);
   		set_skill("force", 150);
    	set_skill("parry", 140);
    	set_skill("magic", 100);
    	
    	map_skill("magic", "ninjitsu");
    	map_skill("unarmed", "enmeiryu");
    	map_skill("blade", "ittouryu");
    	map_skill("parry", "ittouryu");
   		map_skill("force", "ghosty-force");
   	
   	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: smart_fight() :),    
        }) );  
      
   
		set_temp("apply/damage",100);
        set("chat_chance", 1);
		set("chat_msg",	({
			"���ʮ������ب�Ų��������ɫ����ͻȻ�����������۵�һ���ȳ�����Ѫ��\n",
				})  );
		set("inquiry",	([
			"���" : "���ӡ������ӡ��������������\n",
			"�Ϲ���" : "��ʧɢ����ĺ��Ӱ�������֮������ܼ���һ����Ҳ�޺�����\n",
			"�޻�" : "��ʧɢ����ĺ��Ӱ�������֮������ܼ���һ����Ҳ�޺�����\n",
			"���":  "��ʧɢ����ĺ��Ӱ�������֮������ܼ���һ����Ҳ�޺�����\n",	
			"�������": 	"action���ʮ��������ؿ�����һ�ۣ�����һ�\n",
		])		);
	
		setup();
		carry_object(__DIR__"obj/wucloth")->wear();
    	carry_object(__DIR__"obj/muji")->wear();
		carry_object(__DIR__"obj/blackblade")->wield();
}



void win_enemy(object loser)
{
    	message_vision(HIC "���ʮ�������쳤̾һ�������á���\n"NOR,loser);
    	message_vision(HIR "���ʮ����ͻȻ�۵�һ���������Ѫ������һ�����쳤˻��
���Ӱ����㡣�����㡣���ںη�����\n"NOR,loser);
		loser->set("���_quest1",time());
}

void lose_enemy( object winner)
{
		object blade;
		if(!winner->query_temp("marks/fight_tf"))
            	return;
/*		if (REWARD_D->check_m_success(winner, "���˵ı���"))	
				return;*/
		if (REWARD_D->check_riddle(winner,"���˵ı���")>0)
			return;
//		winner->set("���_quest1","�ɹ�");
		REWARD_D->riddle_set( winner, "���˵ı���",1);
		winner ->delete("���_quest1");
//		If you lost/couldn't get the blade, just kill TF14 to loot it.		
		if(blade = present("black blade",this_object())) 
		{
			message_vision(HIR"���ʮ�������Ұ���۾�ͻȻ����������˫�ֽ����ʳ�������$N��
˫ϥ�����Ȼ�����㣬�ú����˵�����ת��������������������ˡ���\n"NOR,winner);
			if (!blade->move(winner))
				destruct(blade);
		}
		
}

int accept_fight(object me)
{
	int count;
	object blade,who;
	who=this_object();
	
	if (this_object()->is_fighting() || this_object()->is_busy())
        	return notify_fail("���ʮ��������æ���أ�û�պ�����\n");
	
	if(!present("black blade",this_object())) return 0;
	
	if (REWARD_D->riddle_check( me, "���˵ı���")) {
//	if(me->query("���_quest1")=="�ɹ�")
			message_vision(HIW"���ʮ�����ʵ������Ұ���������飬�����������𣿡�\n"NOR,me);
			return 0;
	}
	
	if( me->query("���_quest1")&&me->query("���_quest1")+600>time())
	{
		message_vision(HIR"���ʮ���ɲ�м�Ŀ���$N˵���������°ܽ���������������\n"NOR,me);
		return 0;
	}

	if (REWARD_D->riddle_check(me,"����֮��") == 10)
//	if (REWARD_D->riddle_check(me,"����֮��") != 9)
	{
		message_vision(HIR"���ʮ���������Ʋ��$Nһ�ۣ����ÿɷ�\n"NOR,me);
		return 0;
	}

	count=me->query_temp("���_��ս����");
	
	if(me->query("combat_exp")<2500000 || me->query("score")<2000)
	{
		if(count==0)
			message_vision(HIY"���ʮ���ɻ�Ȼ����˫����ɨ��$Nһ�ۣ�΢̾һ������Ŀ���\n"NOR,me);
		
		else if(count==1)
			message_vision(HIY"���ʮ���ɺ���һ���ͺȵ������˶�����ʮ���ɣ���ս�������µµ��Ϊ֮����
����ȼ����������ۣ���������\n"NOR,me);
		else if(count==2)
		{
			message_vision(HIW"���ʮ����üͷ΢�壬��Ǻ����һ��������է�֡�\n"NOR,me);
			kill_ob(me);
			me->delete_temp("���_��ս����");
			return 2;
		}
		me->add_temp("���_��ս����",1);
			return 0;
	}
	
	if (who->query("kee")<who->query("max_kee") || who->query("eff_kee")<who->query("max_kee")
		|| who->query("sen")<who->query("max_sen") || who->query("eff_sen")<who->query("max_sen")
		|| who->query("gin")<who->query("max_gin") || who->query("eff_gin")<who->query("max_gin"))
		{
			tell_object(this_player(),"���ʮ������������,û������.\n");
			return 0;
		}
	message_vision(HIY"���ʮ���ɳ���һ����,��Ȼ����˫����Ŀ����綢��$N����������㣬���У�\n"NOR,me);
    me->set_temp("marks/fight_tf",1);
	return 1;
}
	
	
int accept_object(object who, object ob)
{
	if(!ob->query("saki")) return 0;
	message_vision(HIC"���ʮ����˫�ֽ�����ƿ��ƣ�����ر���\n"NOR,who);
	call_out("be_poisoned",5+random(5),who);
	return 1;
}

int be_poisoned(object who)
{
    delete_temp("last_damage_from");
    message_vision(HIR"\n���ʮ���ɲ�����������ƣ������ݺᣬһ��������\n
���ʮ���ɵ���ɫͻȻ��òҰף�����������Ϻ�ɫ����Ѫ��\n
���ʮ���ɻ�������������죬��Ȼ�������ӣ��㡣���㡣��������
��λ"+RANK_D->query_respect(who)+"���������涾�������ܱƳ���Ҳ�ع������ϣ�����һ������
��֪��ɷ��Ӧ��\n"NOR,who);
	tell_object(who,MAG"���Ȼ�����ƺ��������￴�����ֶ��ԣ�����\n"NOR);
	if (REWARD_D->riddle_check( who, "���˵ı���") != 4)
//	if(who->query("���_quest4")!="�ɹ�")
	{
		die();
		return 1;
	}
    tell_object(who,HIY"answer yes/no \n"NOR);
	who->set_temp("answer_person",1);
	return 1;
}

int do_answer(string arg)
{
	object skinmask,who;
	
	who=this_player();
	if(!who->query_temp("answer_person")) return 0;
	if(arg=="yes")
	{
		message_vision("$N��ɫ���صص���һ��ͷ��\n",who);
		message_vision(HIB"���ʮ���������Ц�����ã��ҽ���Լս����ԭһ��죬��ʹ���
һս�ɡ�����ص�ӿȪ�౨��\n"NOR,who);
		skinmask=new(__DIR__"obj/skinmask");	// If you lose it, just borrow it from others. 
		skinmask->move(who);
		message_vision("���ʮ���ɸ�$Nһ��װ����\n",who);
		REWARD_D->riddle_set( who, "���˵ı���", 5);
//		who->set("���_quest5","�ɹ�");
		who->delete_temp("answer_person");
		return 1;
		
	}
	if(arg=="no")
	{
		message_vision(HIR"���ʮ������ȻһЦ���³�����Ѫ�����ض�����\n"NOR,who);
		die();
		return 1;
	}
	return 0;
}



void imbue_event(object me){
    object obj, weapon, *inv;
    string prop;
    int i;
    mapping data;
    
    if(!me || environment(me) != environment(this_object())) {
            return;
    }
	
	obj = me->query_temp("weapon");
	
	if (obj) {
		message_vision(HIG"\n��ˮ������$N��" + obj->name() + HIG"�ϣ���˳��"
            		+ obj->name() + HIG"�䵽�˵��ϡ�\n"NOR, me);	
	} else
		message_vision(HIG"\n��ˮ����$N���ϣ��������ϣ�һ�������ʧ�ˡ�����\n"NOR, me);
		
	data = ([
		"name":		"���˵ı���",
		"target":	me,
		"att_3":	"random",
		"att_3c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);
	return;	
}
	
	
void init()
{	object ob;
	::init();
	add_action("do_answer","answer");
	add_action("do_accept", "accept");
	add_action("do_killing", "kill");
	if( interactive(ob = this_player()) && !is_fighting() ) 
        if (REWARD_D->riddle_check( ob, "���˵ı���" ) == 6 )
        {
	        remove_call_out("recruiting");
                call_out("recruiting", 1, ob);
        }

}


void recruiting(object ob)
{
	
	if (!ob)	return;
	if (environment(ob)!= environment(this_object()))	return;
		
	if(ob->query("���_quest6")=="ʧ��")
	{
		message_vision(HIR"���ʮ������ȻһЦ���³�����Ѫ�����ض�����\n"NOR,ob);
		ob->delete("���_quest6");
		die();
		return;
	}
	if (REWARD_D->riddle_check( ob, "���˵ı���" ) == 6 )
	{
		tell_object(ob,WHT"\n���ʮ��������������˫�ۣ�΢΢Ц�����ã��ã��������������ߣ������ж��������
��Ϧ�����˷���ԭ֮����Ը���ˣ�ȴҲ�޺���\n\n"NOR);
		tell_object(ob,YEL"���λ��ǵ���ˮ�����ʮ���������Ϲ���������\n"NOR);
		
		// reward time
		imbue_event(ob);
        REWARD_D->riddle_done(ob,"���˵ı���",100,1);
		
		tell_object(ob,WHT"\n��ĬƬ�̣����ʮ�����ֵ�����һ���书���޴��ˣ��������ϳˣ�����ѡһ��ѧϰ��\n"NOR);
		return;
	}
}

int recognize_apprentice(object ob)
{
    if (REWARD_D->check_m_success( ob, "���˵ı���" )) return 1;
	return 0;
}


int prevent_learn(object me, string skill){
	string *slist = ({ "enmeiryu", "ittouryu", "ghosty-force","ghosty-steps","ittouryu","ninjitsu" });
	int i,amount;
	
	if(REWARD_D->check_m_success(me, "���˵ı���")){
		if (member_array(skill,slist)==-1)	return 0;
		amount = 0;	
		for (i=0;i<sizeof(slist);i++){
			if (skill != slist[i]) 
			if ((amount = me->query_skill(slist[i],1))>0) { 
				tell_object(me,"�������Ѿ�ѧ����һ�����ʮ���ɵ��书��"+SKILL_D(slist[i])->name()+"��"+amount+"����\n");
				tell_object(me,"�㲻��ͬʱӵ�ж�������书���������ѧ�µģ�����ȥ���������Ѿ�ѧ�õġ�\n");
				return 1;
			}
		}			
		return 0;	
	}	
}

smart_fight()
{
	int i;
	object *enemy;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			if (enemy[i]->query_temp("weapon")&& !random(5))
			{
				command("wield all");
				this_object()->smart_busy();
			} else 
			{	if (this_object()->query_temp("weapon"))
					command("say ��,�Ҳ��ñ���!");
				command("unwield all");
				this_object()->smart_attack();
			} 
		}
	}
}

smart_busy() {
	this_object()->perform_action("blade.gobankiri");
}
smart_attack() {
	this_object()->perform_action("unarmed.shiden");	
}


int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
		return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
       	if(victim->query("id")=="tianfeng")
        {
            this_object()->remove_all_enemy();
            command ("say �ã���ɱ��!");
            return 0;
        } 
    }
    return 0;
}

