// ; annie 6.28.03
// ; annie 07.2003
// ; annie 08.2003
// ; annie 09.2003
// dancing_faery@hotmail.com
// 
// �˲���֮���� ҹ��û� ���Ͻ� 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 100 DMG 25 ATTACK 75K DODGE 77K PARRY 75K
// daimonsword,summon sword spirits.

// A/D/P�����ڱ�׼8M������Ϊ����TK��


inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("���Ͻ�", ({ "chu nanjiang","chu"}) );
	set("gender", "����" );
	set("title",YEL"������� "NOR CYN"����"NOR);
	set("nickname",HIC"ҹ��û�"NOR);
	set("age", 20+random(10));
	set("long",
		"һϮ���İ������棬�����ͱ�ͦ������������һ��\n����ƽ������ͭ������ȴ��������˫�ĸɽ�Īа��\n���������Ŀ����㣬����û���κα��顣\n"
		);
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",40);
	set("force_factor",180);
	set("per",40);

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);

	set_skill("demon-blade",240);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",340);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("move",200);
	set_skill("dodge",200);

	set_skill("demon-force",200);

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
	set_skill("divineforce",200);	

	set_skill("qiuzhi-sword",250);
	set_skill("daimonsword",250);
	set_skill("zensword",250);
	set_skill("sword",200);

	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "divineforce");
    	map_skill("dodge","cloud-dance");
    	map_skill("move","anxiang-steps");
    	map_skill("sword","daimonsword");
    	map_skill("parry","qiuzhi-sword");
	
    	
        add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

	setup();


	setup();
    armor=new("/obj/armor/cloth");
	armor->set_name("���İ�ɳ���",({"cloth"}) );
	armor->move(this_object());
	armor->wear();

    carry_object(__DIR__"obj/chusword1")->wield();
    carry_object(__DIR__"obj/chusword2")->wield();

    set("reward_npc", 1);
	set("difficulty",7);

	set("marry","x g e e s e");
	set("marry_name","С��");
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[0];	// ��0ɱ��
}


int release_swordsoul()
{
	object *enemy;
	int i,flag;
	object me = this_object(),env=environment(me),soul;
	flag=0;
	enemy = all_inventory(me);
	i = sizeof(enemy);
	while (i--)
		if (enemy[i]->name()==CYN"�Ž����ɽ�"NOR)
			flag=1;
	if (!present("sword spirit cyan",env) && flag && query("cyan") + 60 < time())
	{
		message_vision(CYN"\nһ����ɫ�Ĺ�â�ӹŽ����ɽ����������û�Ϊһ�����轣�Σ�����\n"NOR,this_object());
		soul=new(__DIR__"cyansoul");
		soul->move(env);
		soul->set("possessed",this_object());

		enemy = query_temp("protectors");
		if(sizeof(enemy))
			enemy += ({ soul });
		else
			enemy = ({ soul });
		set_temp("protectors",enemy);

		enemy = query_enemy();
		i = sizeof(enemy);
		while(i--)
			if( enemy[i] && living(enemy[i]) )
			{
				soul->kill_ob(enemy[i]);
				enemy[i]->kill_ob(soul);
			}
	}
	flag=0;
	enemy = all_inventory(me);
	i = sizeof(enemy);
	while (i--)
		if (enemy[i]->name()==YEL"�Ž���Īа"NOR)
			flag=1;
	if (!present("sword spirit yellow",env) && flag && query("yellow") + 60 < time())
	{
		message_vision(YEL"\nһ����ɫ�Ĺ�â�ӹŽ���Īа���������û�Ϊһ�����轣�Σ�����\n"NOR,this_object());
		soul=new(__DIR__"yellowsoul");
		soul->move(env);
		soul->set("possessed",this_object());

		enemy = query_temp("protectors");
		if(sizeof(enemy))
			enemy += ({ soul });
		else
			enemy = ({ soul });
		set_temp("protectors",enemy);

		enemy = query_enemy();
		i = sizeof(enemy);
		while(i--)
			if( enemy[i] && living(enemy[i]) )
			{
				soul->kill_ob(enemy[i]);
				enemy[i]->kill_ob(soul);
			}
	}
}

int kill_ob(object who)
{
	int a = query_busy();

	if (who->is_zombie() == 1 || base_name(who) == "/obj/npc/danei" || base_name(who) == "/obj/npc/danei_guard")
	{
		message_vision(HIW "$N�������֣������е���ǹ���˸��ɲ�Ǽ�����������ţ�����\n" NOR,this_object());
		who->die();
		return 1;
	}

	::kill_ob(who);
//	smart_fight();
/*	stop_busy();
	if (ccommand("perform force.check_gspm"))
		ccommand("perform force.guishenpomie");
	start_busy(a);
*/	this_object()->smart_busy(who);
	return 1;
}

void smart_fight()
{
	int i,max_busy=99;
	object *enemy,target,sword;
	string action;

//	if (ccommand("perform force.check_gspm"))
//		ccommand("perform force.guishenpomie");

	release_swordsoul();

	enemy = this_object()->query_enemy();
/*
	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (!enemy[i]->is_busy() && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp"))
				this_object()->smart_busy(enemy[i]);
*/
	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (enemy[i]->query_busy() < max_busy)
				max_busy = enemy[i]->query_busy();

	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (enemy[i]->query_weapon())
				if (enemy[i]->query_weapon()->query("weapon_prop/damage") > 5)
				{
					target=enemy[i];
					action="libie";
				}

	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (ANNIE_D->get_buff_num(enemy[i],1) > 0)
			{
				target=enemy[i];
				action="chousi";
			}

	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (enemy[i]->query("kee")<3000 && !enemy[i]->query("possessed") && enemy[i]->query("combat_exp") > 4000000)
			{
				target=enemy[i];
				action="duanchang";
			}

	if (query("kee") < 3000 && action!="duanchang")
	{
		target=select_opponent();
		action="duanchang";
	}

	if (!action)
	{
		target=select_opponent();
		action="libie";
	}

/*
	if (action)
		ccommand("say "+action+"max busy"+max_busy);
	else
		ccommand("say no action max busy"+max_busy);


	if (!action && max_busy >= 2)
	{
		map_skill("sword","qiuzhi-sword");
		perform_action("sword.hanmeiluo");
		return;
	}
	if (action == "libie" && max_busy < 3)
		return;
*/	map_skill("sword","daimonsword");
	if (action == "duanchang")
	{
		sword=present("ancient sword 2",this_object());
		if (!sword)
		{
			if (present("sword spirit cyan",environment(this_object())))
				present("sword spirit cyan",environment(this_object()))->leave();
			SKILL_D("daimonsword")->perform_target(this_object(),action,target);
			return;
		}
		if (present("sword spirit yellow",environment(this_object())))
			present("sword spirit yellow",environment(this_object()))->leave();
		if (SKILL_D("daimonsword")->perform_target(this_object(),action,target))
		{
			sword=present("ancient sword",this_object());
			if (!sword)
				return;
			message_vision(CYN"\n���Ͻ�һ����ߣ���"+sword->name()+CYN"�ɿ�ػ������֡�\n"NOR,this_object());
			destruct(sword);
			carry_object(__DIR__"obj/chusword3")->wield();
		}
		return;
	}
	SKILL_D("daimonsword")->perform_target(this_object(),action,target);
	return;
}

smart_busy(object target) {
	SKILL_D("demon-steps")->perform_target(this_object(),"lianhuanbabu",target);
	set("class","huashan");
	SKILL_D("cloud-dance")->perform_target(this_object(),"yexuechuji",target);
	set("class","demon");
	return;
}

void die()
{
	object me=this_object(),owner,enemy,paper,*sy_inv,things,env=environment(me),soul;
	int j;
	if (soul=present("sword spirit yellow",env))
		soul->die();
	if (soul=present("sword spirit cyan",env))
		soul->die();
	if (!query_temp("last_damage_from"))
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		delete("reward_npc");
		::die();
		return;
	}
	if (environment(me)->query("short") != "��������")
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		delete("reward_npc");
		::die();
		return;
	}
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	if (paper = present("paper"))
		paper->move(environment());
	enemy->set("annie/demon_killed_chu",1);	
	environment()->set("exits/up","/d/bashan/maze3/entry");
	::die();
	return;
}

mapping ob_hit(object attacker, object victim,int damage)
{
	mapping data = ([]);
	if (!victim->is_busy())
		return 0;
	victim->stop_busy();
	data["msg"] = CYN"$n���۹Ķ�����$Nһ��֮�������ƮƮ�����˿�ȥ��\n"NOR;
	return data;
}

/*
update here;ask ke about silencer;call mingyue->delete_temp(inquiry_time);ask ke about silencer;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill fighter);call chu->ccommand(kill fighter 2);
update here;clone /d/bashan/npc/yawnboy;clone /d/bashan/npc/yawngirl;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill justdoit);call chu->ccommand(kill sinny);
*/

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
