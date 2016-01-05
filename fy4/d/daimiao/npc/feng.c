// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// �˲���֮���� ����ǳ� ����� 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 100 DMG 25 ATTACK 80K DODGE 75K PARRY 71K
// ����4��SEAL������

// A�����ڱ�׼8M��D�����ڱ�׼8M��P:���ڱ�׼8M�����˿�TK��

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("�����", ({ "feng qiuguan","feng"}) );
	set("gender", "����" );
	set("title",YEL"������� "NOR CYN"����"NOR);
	set("nickname",MAG"����ǳ�"NOR);

	set("age",30+random(10));

	set("attitude","friendly");

	set("long",	"�����Ŀ����Ө�����Լ��ڹ���Ϊ���黯����\n");

	set("class","demon");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("str",40);
	set("per",200);
	set("force",2500);
	set("max_force",2500);
	set("force_factor",130+random(100));
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_arrest",1);
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);
	
	set_skill("dragonwhip",250);
	set_skill("xiaohun-whip",320);
	set_skill("whip",200);

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

//	set_skill("huoyan-dao", 250);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",600);

	set_skill("divineforce",200);

	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "huoyan-dao");
	map_skill("force", "divineforce");
    	map_skill("dodge","fall-steps");
    	map_skill("move","anxiang-steps");
    	map_skill("whip","dragonwhip");
    	map_skill("parry","xiaohun-whip");
    	
        add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );


	setup();

    set("reward_npc", 1);
	set("difficulty",7);

	carry_object(__DIR__"obj/fengwhip")->wield();
	carry_object(__DIR__"obj/fengcloth")->wield();
	carry_object(__DIR__"obj/paper4");

}


void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;
	message_vision(CYN"�����ҡͷ��̾�����������һ˿Ц�⣺�Ҿ�֪����С�ӳ��²����\n�����࣬��Ȼ�ְ�����Ū��һ�Ρ�\n"NOR,ob);
	return;
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
	return enemy[random(sizeof(enemy))];
}



int kill_ob(object who)
{
	::kill_ob(who);
	stop_busy();
	smart_fight();
	return 1;
}

void smart_fight()
{
	object me,target,*enemy;
	int i=0,flag=10;
	me = this_object();
	target = select_opponent();
	enemy = query_enemy();
	for (i=0;i<sizeof(enemy) ; i++)
		if (enemy[i]->query_busy() < flag)
			flag = enemy[i]->query_busy();
	i=0;
	if (me->query_temp("weapon"))
	{
		if (flag > 2)
			i=ccommand("perform firestorm");
		else
			i=ccommand("perform thousandfeather");

		if (i)
			start_busy(2);	// thousandfeather is a 2+random(2) pfm. lets cheat a bit
	}


	return;
}

void die()
{
	object me,owner,enemy,paper,*sy_inv,things;
	int j;
	me = this_object();
	
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
	
	if (environment(me)->query("short") == "С��" || !REWARD_D->check_m_success(enemy,"̽��׷Դ"))
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

	message_vision(CYN"\n�����Ĩȥ��ǵ���Ѫ��΢Ц������Ȼ�Ǻ����ա�����̰���֮�У���ȥ�Ҳ�
���˽�İ�������������ֻ�о�ɽ���Ƶ�ס�㡣

����ٵ�����¥��������������ϼ֮ɽ��������������������һս��\n\n"NOR,me,enemy);
//		REWARD_D->riddle_done(enemy,"��ƭ",100,1);
	enemy->set("annie/demon_killed_feng",1);
	::die();
	return;
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/




