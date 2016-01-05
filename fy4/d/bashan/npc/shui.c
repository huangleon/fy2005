inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
	object armor,weapon;
	set_name("ˮ����", ({ "shui ruxi","shui"}) );
	set("gender", "Ů��" );
	set("title",YEL"������� "NOR CYN"Ǭ������"NOR);
	set("nickname",HIW"���ﻨ��"NOR);
	set("age", 20+random(10));

	set("attitude","friendly");
	set("long",
		"\n"
		);

	set("resistance/kee",100);
	set("resistance/gin",100);
	set("resistance/sen",100);

	set("class","demon");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",20);
	set("per",200);
	set("force",2500);
	set("max_force",2500);
	set("force_factor",130+random(100));
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);


	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);
	
	set_skill("heavendance",220);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("stormdance",235);
	set_skill("move",200);
	set_skill("dodge",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 700);
	set_skill("force", 200);

	set_skill("lingxi-zhi", 170);
	set_skill("divineforce", 200);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);

	set("NO_ASK","�������������ϣ������µף���δ������ţ�\n");
	set("NO_KILL","�������ϣ������µף�����������ţ�\n");

	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "divineforce");
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");
	map_skill("blade","heavendance");
	map_skill("parry","heavendance");
    	

	add_temp("apply/iron-cloth", 200);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight(this_object()) :),
	}) );

	setup();
	set_temp("condition_type",NOR CYN" <ɽ����>"NOR);

	carry_object("/d/wudang/npc/obj/longskirt")->wear();
	carry_object("/d/wudang/npc/obj/cyin")->wield();
	carry_object(__DIR__"obj/stone")->wear();

/*
    set("reward_npc", 1);
	set("difficulty",7);
*/
}
/*
int kill_ob(object who)
{
	object me;
	int exp_r,busyst;
	string msg;
	::kill_ob(who);
	smart_fight(who);
	return 1;
}
*/
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
	return enemy[random(sizeof(enemy))];
}


void force_busy(int busy)
{
	message_vision(CYN"\nˮ������ȹƮ�ɣ�����������֮�⡣\n"NOR, this_object());
	return;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	message_vision(CYN"\nˮ������ȹƮ�ɣ�����������֮�⡣\n"NOR, this_object());
	return;
}

void do_ggyy(object me,object target,int count)
{
	int i,j;
	object item,env=environment(me),*inv;
	string msg;
	string *event_msg = ({
"\n����֮�У�����ʦͻȻ���һ����Ѫ���ȵ�����ס��\n",
"����ʦ��ס�ؿڣ���ɫ�־����ɣ����´�����ˮ�������ʵ�������֮������\n��أ��������춼ˮ�£�\n",
"ˮ����������ȥ������Ѫ������ĵ��˵�ͷ��\n",
"����ʦ��̾һ����˵������ħ�����������ˣ��������ˣ����ˣ������ˣ�\n",
"�������������������ʦһ��������������ȥ��\n",
"ˮ����վ����׷�������˱����߰���Զ������ͷ�ϰ���һö�������Σ���Ц����\n����Ҫ�����ߣ�ƫ���ֲ����飬��˵���ǵȻ��������������ô��",
"",
"\nˮ���������α�ط��ϣ���̾�������²Ŵ�ļ�ö���׷���룬�����վ�������\n�ˡ���֪��������������ˣ���������ȥ����������ɽ���������ý������ˡ�\n"
"\nˮ�����������߽���ɽ����һ�����ﲻ����\n\n��һ��Ѫսֻ�����㴭����������������������Ϣ��\n"
});
	if (!me || !target)
		return;
	if (environment(target) != env)
		return;
	remove_all_killer();
//	if (me != environment(target) || target->is_fighting())
//		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,target);
	if (count == 6)
	{
		inv = all_inventory(env);
		for(i=0 ;i < sizeof(inv);i++)
		{
			if(inv[i]->query_temp("condition_type") == NOR CYN" <ɽ����>"NOR && inv[i]!= this_object())
			{
				message_vision(CYN"\n$N��ָ���Ŵ����Σ�����$n�ı�Ӱ����һ��������\n"HIG"\nһ������ɫ��΢����Ӷ�����û��$n���ġ�\n"NOR,me,inv[i]);
				inv[i]->die();
			}
		}
	}
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{
		env->set("exits/down","/d/bashan/hole4");
		destruct(this_object());
		return;
	}
	return;
}


void smart_fight(object who)
{
	object me,target,item;
	object * tar;
	object shadow,hisweapon,newweapon;
	int i,j,temp,num,temp1,num1;

	me = this_object();

	if (who != me)
		target = who;
	else
		target = select_opponent();
	
	tar = me->query_enemy();
	if (sizeof(tar) <= 5)
	{
		do_ggyy(me,me,0);
		return;	
	}

	if (sizeof(tar) > 1)
	{
		message_vision(WHT"\n$Nһ��ˮ�䣬һ������ɫ��˿�߷ɼ�����������������ȥ��\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

// Ϊ����parry busy��Ч(��,̫����),���ﲻʹ��mimic function....
			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
			tar[i]->add("force_factor",query("force_factor")/2);
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,WHT"����ɫ��˿�߷���$N��$N����һ�����ȣ����ɼ�����$n��ȥ��"NOR);
			tar[i]->add("force_factor",-query("force_factor")/2);
			target->add_temp("no_check_pfm_win",-1);
			tar[i]->start_busy(j);
		}
	}

	return;
}

void die()
{
	return;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
