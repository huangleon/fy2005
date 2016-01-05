// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// �˲���֮ҹ���� ǧ�꼯�� ���� 
// EXP 8M KEE 40K GIN/SEN 24K RESIST/ALL 60
// STR 40 DMG 25 ATTACK 46K DODGE 45K PARRY 150K
// PETMASTER

// A/D/P��Զ���ڱ�׼8M��PARRY��ֵ�ߣ����˲���TK��
// ����Ⱥ��6M EXP����ȫBUFF֮��50-81K ATTACK,32K D/P.

inherit NPC;
#include <ansi.h>
#include <combat.h>
void clear_room();

void create()
{
	object armor,weapon;
	set_name("����", ({ "xin wang","xin"}) );
	set("gender", "����" );
	set("title",YEL"������� "NOR CYN"ҹ����"NOR);
	set("nickname",RED"ǧ�꼯��"NOR);
	set("age", 60+random(10));
	set("attitude","friendly");

	set("long",
		"�������°׷������糤�룬�ֳ�ֽ�����������ۣ�������һ��\n�����ɷ硣\n"
		);
	set("class","demon");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",20);
	set("per",20);
	set("force",2500);
	set("max_force",2500);
	set("force_factor",64);
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_arrest",1);

	set("group","demon");
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",40000);
	set("max_gin",24000);
	set("max_sen",24000);
	
	set_skill("daimonsword",160);
	set_skill("sky-sword",250);
	set_skill("sword",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("move",200);
	set_skill("dodge",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("lingxi-zhi", 170);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "bolomiduo");
    	map_skill("dodge","fall-steps");
    	map_skill("move","anxiang-steps");
    	map_skill("sword","daimonsword");
    	map_skill("parry","sky-sword");
    	
        add_temp("apply/iron-cloth", 200);

	set("NO_KILL","����������վ������ǰ�ĳ�֮��������̶̵��ĳ߾���������޷���Խ��\n");
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//               (: smart_fight() :),
        }) );

		set("chat_chance",0);
		set("chat_msg", ({
	             (: clear_room() :),	// ; to kickout jiasi/(pet) player
        }) );

	setup();

	carry_object(__DIR__"obj/taopao")->wear();
	carry_object(__DIR__"obj/papersword")->wield();
	carry_object(__DIR__"obj/paper3");

    set("reward_npc", 1);
	set("difficulty",7);

}

void init()
{
	object me;
	::init();
	me = this_player();
	if (userp(me) && environment(me)->query("short") == "��������" && !is_fighting())
	{
		remove_call_out("do_greeting");
		call_out("do_greeting",1,me,environment(this_object()));
	}
}


void do_killob(object me,object room)
{
	if (!me || environment(me) != room)
		return;
	message_vision(CYN"\n$NЦ�����ֲ�������ɱ�����Ⱥ����Ȼ�м��ֱ��¡�������һ��Ҳ�͵���\nΪֹ�ˡ��������İɣ����ʬ�������ϼѣ����ǲ����˷ѵġ�\n"NOR,this_object(),me);

	call_out("do_m_killob",1,me,room);

	return;
}

void do_m_killob(object me,object room)
{
	if (!me || environment(me) != room)
		return;
	message_vision(CYN"\n$N���������дǣ�˫�ּ�����ڿ��л��裬��Ȼ��ȵ�����\n"NOR,this_object(),me);
	call_out("do_n_killob",2+random(2),me,room);
}

void do_n_killob(object me,object room)
{
	object guard;
	if (!me || environment(me) != room)
		return;
	message_vision(HIB"\nһ�������ɿ��˳�ŵ��ϵķ�ͼ������������ͼ��ʼ����ҫ�۵Ĺ�â��\n\n"HIW"ɲ�Ǽ�⻪��ʢ��������𣬼�����Ϣ������������Σ�\n\n"NOR,this_object(),me);

	delete("NO_KILL");

	set("chat_chance",100);			// �_ʼ�O�y����Kֹ��r ; annie 6.27.03

	me->set_temp("annie/demon_xin_2",0);	// ���ʧ�ܣ���ͷ������
	delete("NO_KILL");
	guard = new(__DIR__"tiger");
	guard->move(room);
	guard->kill_ob(me);
	me->kill_ob(guard);
	guard = new(__DIR__"dragon");
	guard->move(room);
	guard->kill_ob(me);
	me->kill_ob(guard);
	guard = new(__DIR__"turtle");
	guard->move(room);
	guard->kill_ob(me);
	me->kill_ob(guard);
	guard = new(__DIR__"phoenix");
	guard->move(room);
	guard->kill_ob(me);
	message_vision(CYN"\n$N������Ц�������ˣ����ڳ��ˣ�ʧ�������������ת��֮�����ڳ��ˣ�\n\n"NOR,this_object(),me);
	me->kill_ob(guard);
	kill_ob(me);
	me->kill_ob(this_object());

}

void do_greeting(object me,object room)
{
	if (!me || environment(me) != room)
		return;
	call_out("do_killob",1+random(2),me,room);
}

void clear_room()	// ; annie 6.27.03 ̎������Ć��}
{
	object room,me;
	object *olist;
	int i;
	me = this_object();
	room = environment(me);
	olist = all_inventory(room);

	set("NO_KILL","����������վ������ǰ�ĳ�֮��������̶̵��ĳ߾���������޷���Խ��\n");

	for(i=0; i<sizeof(olist); i++)
	{
		if (olist[i] == me)
			continue;
		if (!olist[i]->query("max_kee"))	// item? character? ... forgot what' the function for ><" ; annie 6.27.03
			continue;
		if (!userp(olist[i]) && olist[i]->query("title") == WHT"����֮"NOR)
		{
			destruct(olist[i]);
			continue;
		}
		message_vision(CYN"\n�������һ�����׳�һ������ɫ�ķ�ֽ����$N���ϡ�\n$N������������ģ����ʧ�ˣ�����\n\n"NOR,olist[i]);
		olist[i]->move(load_object("/d/taoguan/taoguan"));
		message_vision(CYN"\n����ǰ�Ŀ�����Ȼ��ʼ���󲨶���һ��ģ�������������Ĵ���������ֳ���������\n\n"NOR,olist[i]);
	}

	set("chat_chance",0);
	return;
}

void kill_ob(object who)
{
	object me=who,here=environment(who),*inv=all_inventory(here);
	int i;
	::kill_ob(who);
	for (i=0;i<sizeof(inv) ; i++)
		if (!userp(inv[i]) && inv[i]->query("title") == WHT"����֮"NOR)
			if (!inv[i]->is_fighting(me))
			{
				inv[i]->kill_ob(me);
				me->kill_ob(inv[i]);
			}
}


void die()
{
	object room,me;
	object *olist;
	object owner,enemy,paper,*sy_inv,things;
	int i,j=0;
	me = this_object();
	room = environment(me);
	olist = all_inventory(room);

	for(i=0; i<sizeof(olist); i++)
		if (olist[i]->query("title") == WHT"����֮"NOR)
			j = 1;
	if (j)											// ����߀�����`����,IMMORTAL.; annie 6.27
		this_object()->full_me();
//		"/cmds/imm/full"->main(this_object(),"");
	else
	{
		if (!query_temp("last_damage_from"))
		{
			sy_inv = all_inventory(this_object());
			for(j=0;j<sizeof(sy_inv);j++){
				things = sy_inv[j];
				destruct(things);
			}
			::die();
			return;
		}

		if(objectp(enemy=query_temp("last_damage_from")))
			if(owner=enemy->query("possessed"))
				enemy = owner;
				
		if (environment(me)->query("short") != "��������")
		{
			set("reward_npc", 0);
			sy_inv = all_inventory(this_object());
			for(j=0;j<sizeof(sy_inv);j++){
				things = sy_inv[j];
				destruct(things);
			}
			::die();
			return;
		}

		message_vision(CYN"\n$N������߳���Ѫ������ͻȻ��¶��һ��˵�������ļ�ڽ֮ɫ��\n"WHT"�����׷﹫����Ȼ�Ѿ��ѳ�ħ�̣�ħ���Բ������������������\n������������Ϊ�˱���\n������һ����ʧ���ˣ���������һ�����ǻ�ɹ��ġ�\n\n"NOR,me,enemy);
//		REWARD_D->riddle_done(enemy,"���",100,1);
		enemy->set("annie/demon_killed_xin",1);	// 
		environment()->pushout();
		::die();
	}
	return;
}

