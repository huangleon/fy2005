// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
//inherit __DIR__"maze_npc.c";
inherit SMART_NPC;

void smart_fight();

void create()
{	
	object weapon;
	set_name("����ˮ��", ({ "narcissus","boss" }) );
	set("class","moon");
	set("group","icecave_maze");
	set("gender","Ů��");
	set("age",16);
	set("str",24);
	set("per",34);
	set("score",-10000);
	set("force_factor",160);
	set("agi", 70);
	set("gold", 40);
	set("real_boss",1);
	set("boss",1);

	set("max_gin",120000);
	set("max_sen",120000);
	set("max_kee",120000);
	set("max_force",2000);
	set("force",3000);

	set_temp("buff_type/blocked",1);

	set("combat_exp", 8100000);	// L120
	set_skill("mapo", 200);
	set_skill("spells", 200);
	set_skill("stormdance", 200);
	set_skill("snowforce", 280);
	set_skill("shuaijiao", 210);
	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("divineforce", 200);

	set("nb_chat_chance", 100);
	set("nb_chat_msg_combat", ([
		100: 	(: smart_fight() :),
	]) );    	

	map_skill("dodge", "stormdance");
	map_skill("move", "stormdance");
	map_skill("unarmed", "shuaijiao");
	map_skill("force", "snowforce");
	map_skill("spells", "mapo");

	setup();


	weapon=carry_object("/obj/armor/hat");
	weapon->set_name(HIG"������"NOR, ({ "emerald diadem"}) );
	weapon->set("long","һ������������񻷣�������Ƕ��һ��͸�̵���䡣\n");
	weapon->set("no_get",1);
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/d/xiangsi/npc/obj/longskirt");
	weapon->set_name(HIR BLK"��̨����"NOR, ({ "dancer skirt"}) );
	weapon->set("long","һ��������������ı�ɴ��\n");
	weapon->set("no_get",1);
	weapon->set("value",0);
	weapon->wear();

	carry_object("/d/xiangsi/mazenpc/obj/nacrissus_boot")->wear();

	set("attitude", "friendly");

	set("long",WHT"����̬��Ȼ����ɫ�������˿����ڳ�����˼��\n����������ǰ��������������ˮ�ɡ�\n\n"NOR);
	set("no_arrest",1);
	set("no_fly",1);


	set("drop/fixed_amount",1);
	set("drop/fixed_drop", ({		// L80-90 books
			BOOKS"class/cloud-dance_yegui_2",
			BOOKS"class/dragonstrike_zjbl_3",
			BOOKS"class/iceheart_buffup_3",
			BOOKS"class/xueyeqianzong_wolverine_3",
			BOOKS"class/nine-moon-claw_weiwoduzun_2",
			BOOKS"class/yijinjing_shield_2",
			BOOKS"class/yue-spear_juechufengsheng_2",
	}));
		
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/wrists_130_7.c",
"/obj/generate/neck_130_8.c",
"/obj/generate/head_130_18.c",
"/obj/generate/boots_130_9.c",
"/obj/generate/boots_130_19.c",
	}) );
	set("drop/rare_drop",({
"none",
	}) );

}


int hurting(){
	int i,dam;
	object *inv;
	mapping buff;
	inv = query_enemy();
	if (!inv || !sizeof(inv))
		return 0;
	message_vision(HIW"\n$N"HIW"����ɢ��һ��ѩ�Ƶİ�â��ת˲��ͽ������������ڡ�\n\n"NOR,this_object());
    for (i=0; i<sizeof(inv); i++)
	{
		if (ANNIE_D->check_buff(inv[i],"blind")) continue;

		buff =
		([
			"caster":this_object(),
			"who":inv[i],
			"type":"blind",
			"att":"curse",
			"name":"����ˮ�ɡ���Ȼ֮��",
			"buff1":"block_msg/all",
			"buff1_c":1,
			"time":20,
			"buff_msg":YEL"$N"YEL"ֻ����â��һ��������������У���ʱʲôҲ�������ˡ�\n"NOR,
		]);
		ANNIE_D->buffup(buff);
   	}
	return 1;
}

int kill_ob(object who)
{
        ::kill_ob(who);
        smart_fight();
        return 1;
}

void unconcious()
{
	::die();
}

void die()
{
	object *enemies,target,*sy_inv,things,me;
	int i,j;
	object who;

	enemies=query_enemy();
	if (enemies && sizeof(enemies))
	{
		message_vision(BRED HIW"\n��������\n"NOR,this_object());
		message_vision(HIW"\n$N"HIW"ҧס�´���̧����ȥ�����Ѫ����Ȼ�����أ�������衣
����$N"HIW"�������ѻ�ΪƬƬ�������׷ɶ������㲻��Ŀ����������

"HIR"�辡֮ʱ��$N����΢�֣����Ӱ빪��ͻȻ����һƬѪ�꣬�����˾����������ڡ�\n\n"NOR,this_object());

		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++)
		{
			things = sy_inv[j];
			destruct(things);
		}
		// ÿ���͸�shimon
		set("kee",2000);
		set("sen",80000);
		add_temp("apply/attack",888);
		add_temp("apply/damage",3333);

		for (i=0; i<sizeof(enemies); i++)
		{
			target = enemies[i];
			target->add_temp("combat_no_report",1);
			stop_busy();
			target->perform_busy(1);
			COMBAT_D->do_attack(this_object(),target, TYPE_PERFORM);
			target->add_temp("combat_no_report",-1);
			if (target->query_temp("damaged_during_attack"))
				COMBAT_D->report_status(target);
		}
	}

	who = query_temp("last_damage_from");
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);
		
	::die();	
	return;
}

void smart_fight()
{
	int i;
	object me,ob,*enemy;
	mapping buff;
	me = this_object();
	
	ccommand("exert npc_hurtless");
	if (time()>query("annie/ec")+30 && !random(3))
	{
		set("annie/ec",time());
		message_vision(BBLU HIW"\n��Ȼ֮��\n"NOR,me);
		message_vision(HIR"\n$N"HIR"˫�ָ��ڱ�������Ʈ��΢����ü���м�һ����ɰԽ�����ޣ�����\n\n"NOR,this_object());
		call_out("hurting",8);
	}

	enemy=query_enemy();
	if (time()>query("annie/ed")+8 && time()>query("annie/ec")+9)
	{
		for (i=0;i<sizeof(enemy);i++) {
			if (objectp(ob = enemy[i])) {
				if (ANNIE_D->check_buff(ob,"idiot"))	continue;
				message_vision(BCYN WHT"\n�������\n"NOR,ob);
				buff =
				([
					"caster":me,
					"who":	ob,
					"type": "idiot",
					"att": "curse",
					"buff1":"disable_inputs",
					"buff1_c":1,
					"disable_type":NOR CYN " <�������>" NOR,
					"name": "��а�ľ����������",
					"time": 16,
					"buff_msg":HIG"\n$n"HIG"˫��£���ؿڣ�������գ�����΢̧������յ���ף��������
"BLU"$N"BLU"����һ��ֻ���������壬��������ǲ��ܼ���\n\n"NOR,
				]);
				ANNIE_D->buffup(buff);
			}
		}
		set("annie/ed",time());	
	}

}

