inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("���Ϸ�", ({ "ji nanfeng","nanfeng","ji"}) );
	set("gender", "����");
	set("title",CYN"Ѫ���� "NOR MAG"���̿�"NOR);
	set("nickname", BBLU HIW"���׽���"NOR);
	set("age", 20+random(10));
	set("long","������Ѫ�����£�ȴ�Ӳ�������ʹ����Ϊ���������أ�\nѪ����������Ȼ���в��ʣ�ȴҲ�޷��κΡ�\n");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",40);
	set("force_factor",150);
	set("per",40);

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);

	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

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

	carry_object(__DIR__"obj/chusword4")->wield();

    armor=new("/obj/armor/cloth");
	armor->set_name("���İ�ɳ���",({"cloth"}) );
	armor->move(this_object());
	armor->wear();

    set("reward_npc", 1);
	set("difficulty",7);
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

void attackx(object me,object target,int attack,int damage)
{
	me->add_temp("apply/attack",attack);
	me->add_temp("apply/damage",damage);
	target->add_temp("combat_no_report",1);
	COMBAT_D->do_attack(me,target,TYPE_PERFORM," ");
	target->add_temp("combat_no_report",-1);
	if (!target->query_temp("damaged_during_attack"))
		message_vision("���û�ж�$N����κ��˺���\n\n",target);
	else
		COMBAT_D->report_status(target);

	me->add_temp("apply/attack",-attack);
	me->add_temp("apply/damage",-damage);
}

int kill_ob(object who)
{
	int a = query_busy();

	if (base_name(who) == "/obj/npc/danei" || base_name(who) == "/obj/npc/danei_guard")
	{
		message_vision(HIW "$N�������֣������е���ǹ���˸��ɲ�Ǽ�����������ţ�����\n" NOR,this_object());
		who->die();
		return 1;
	}

	::kill_ob(who);
	smart_fight();
	return 1;
}

int bbqthem(object me, object obj) 
{
	int spells, busy_num,mod,magic;
	string id_enemy;
	mapping buff;
	

	if (ANNIE_D->check_buff(obj,"blind")) return 1;

	buff =
	([
		"caster":me,
		"who":obj,
		"type":"blind",
		"att":"curse",
		"name":"���׽��͡����ս�ʽ",
		"buff1":"block_msg/all",
		"buff1_c":1,
		"time":10,
		"buff_msg":YEL"һ��ҫ�۵�����������$N"YEL"ֻ������ǰ��ãã��һƬ��ʲô���������ˣ�����\n"NOR,
		"disa_msg":HIG"���������ģ�����۾���ʼ���Էֱ���Χ�������ˡ�\n"NOR,
	]);
	ANNIE_D->buffup(buff);

	return 1;
}

void smart_fight()
{
	int i,n=99,resist;
	object *enemy,me=this_object();
	string action;
	object env, *inv;

	env = environment(me);
	inv = all_inventory(env);
	enemy = me->query_enemy();

	if (is_busy())
		return;

	i = random(6);
	switch (i)
	{
	case 0:
		message_vision(BBLU HIW"\n���Ϸ�ʩչ"BRED HIW"���ս�ʽ"NOR BBLU HIW"��\n"NOR,this_object());
		attackx(me, enemy[random(sizeof(enemy))], 150, 999);
		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
				bbqthem(me, enemy[i]);
		perform_busy(3);
		break;
	case 1:
		message_vision(BBLU HIW"\n���Ϸ�ʩչ"BRED HIW"�񽣰���"NOR BBLU HIW"��\n"NOR,this_object());

		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
				attackx(me, enemy[i], 300, 300);

		perform_busy(3);
		break;
	case 2:
		message_vision(BBLU HIW"\n���Ϸ�ʩչ"BRED HIW"������Ϯ"NOR BBLU HIW"��\n"NOR,this_object());
		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
			{
				attackx(me, enemy[i], 600, -300);
				if (enemy[i]->query_temp("damaged_during_attack"))
				{
					message_vision(YEL"$N"YEL"һ�Ŵ�ʽ����ʱ�������꣬��������\n"NOR,enemy[i]);
					enemy[i]->perform_busy(enemy[i]->query_busy()+3+random(3));
				}
			}
		perform_busy(3);
		break;
	case 3:
		message_vision(BBLU HIW"\n���Ϸ�ʩչ"BRED HIW"������"NOR BBLU HIW"��\n"NOR,this_object());
		n=sizeof(enemy);
		if (n>5)
			n = 5;
		if (sizeof(enemy))
	        for(i=0; i<n*2; i++)
				attackx(me, enemy[random(sizeof(enemy))], 150, 200);

		perform_busy(3);
		break;
	case 4:
		message_vision(BBLU HIW"\n���Ϸ�ʩչ"BRED HIW"��M��ɳ"NOR BBLU HIW"��\n"NOR,this_object());

		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
			{
				resist=me->query_temp("resistance/kee");
				if (resist > 0 )
					me->set_temp("resistance/kee",0);
				attackx(me, enemy[i], 0, 500);
				me->set_temp("resistance/kee",resist);
			}

		perform_busy(3);
		break;
	case 5:
		message_vision(BBLU HIW"\n���Ϸ�ʩչ"BRED HIW"�������"NOR BBLU HIW"��\n"NOR,this_object());
		attackx(me, enemy[random(sizeof(enemy))], 888, 2222);
		perform_busy(2);
		break;
	}

	return;
}


void die()
{
	object me=this_object(),owner,enemy,paper,*sy_inv,things,env=environment(me),soul;
	int j;
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
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	::die();
	return;
}

	
mapping ob_hit(object attacker, object victim,int damage)
{
	mapping data = ([]);
	if (!victim->query_busy())
		return 0;
	victim->stop_busy();
	data["msg"] = CYN"$n���۹Ķ�����$Nһ��֮�������ƮƮ�����˿�ȥ��\n"NOR;
	return data;
}

/*
update here;ask ke about silencer;call mingyue->delete_temp(inquiry_time);ask ke about silencer;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill fighter);call chu->ccommand(kill fighter 2);
update here;clone /d/bashan/npc/yawnboy;clone /d/bashan/npc/yawngirl;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill justdoit);call chu->ccommand(kill sinny);

Ҳ����Ǳ����ѧ�����Խ�ʦ���ı�����Ѫ�������󣬿������Լ��ľ��ž��ޣ��������С�
���ɣ����ɣ�ʦ�����µ��վ����ޣ����ֲ���Ҳ���ֲ��ˣ��Ǿ����ݻ��Լ����ĵã��ɽ����⣬����ȭ�ơ�
���ɣ����ɣ���ѧ����ǧ��ˮ��һưһư���������ܽ��Լ���һ���ڤ����û��

��ȥ�����˰������У��ܷ��֤�˰����ƹ�����������ޣ�ԭҲ�����ʲô��
��������֮�⻹�������Ʒ����ǣ���֮���أ�

����Ҳվ���ҽ����λ���ϣ��ͻ����ף����ڵ��ң���û������ѡ��

blank

�ν��ɣ�Ը�������ܵó���Ը��



�׶��ھ���֮�ϣ���Х��Ⱥɽ֮�ߣ�����֮�������������������ܰ��á�
�������Ӵ˰�Ъ�ɣ��������߹ȵף�������ԭ�������ˣ�ֱ����Զ������


*/

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/


// ������� �������
// ����֮�գ��£��� ����֮�ˣ�ˮ����
