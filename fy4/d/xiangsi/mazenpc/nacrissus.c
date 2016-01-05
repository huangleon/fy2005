// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{	
	object weapon;
	set_name("����ˮ��", ({ "narcissus" }) );
	set("class","moon");
	set("group","icecave_maze");
	set("gender","Ů��");
	set("age",16);
	set("per",34);
	set("score",-10000);
	set("force_factor",160);

	set("real_boss",1);
	set("boss",1);
	set("big_boss",1);

	set("resistance/gin",70);
	set("resistance/kee",70);
	set("resistance/sen",70);
	// GKS * 5

	set("max_gin",20000);
	set("max_sen",20000);
	set("max_kee",32000);
	set("max_force",10000);
	set("force",20000);

	set_temp("buff_type/blocked",1);

	set("combat_exp", 8000000);
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

	carry_object(__DIR__"obj/nacrissus_boot")->wear();

	set("attitude", "friendly");

	set("long",WHT"����̬��Ȼ����ɫ�������˿����ڳ�����˼��\n����������ǰ��������������ˮ�ɡ�\n\n"NOR);
	set("no_arrest",1);
	set("no_fly",1);

	set("drop/bg",20);
	set("drop/common",85);
	set("drop/rare",15);
	set("drop/amount",2);
	set("drop/common_drop",({
__DIR__"obj/cash.c",
__DIR__"obj/glacialcrevasses.c",
__DIR__"obj/lockupdrug.c",
__DIR__"obj/bingpojingbi_3.c",
__DIR__"obj/hanxueliulan_3.c",
__DIR__"obj/mingyue_3.c",
__DIR__"obj/shuanghuaningjie_3.c",
__DIR__"obj/shuangtianxuewu_3.c",
__DIR__"obj/qixingbanyue_2.c",
//__DIR__"obj/wufangbianhuan_3.c",
__DIR__"obj/zhaoyuwanqing_3.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/qinghui_3.c",
__DIR__"obj/arcticwind.c",
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

void unconcious()
{
	::die();
}

void die()
{
	object *enemies,target,*sy_inv,things,me;
	int i,j;
	enemies=query_enemy();
	if (enemies && sizeof(enemies))
	{
		message_vision(BRED HIW"\n��������\n"NOR,this_object());

		message_vision(HIW"\n$N"HIW"ҧס�´���̧����ȥ�����Ѫ����Ȼ�����أ�������衣\n����$N"HIW"�������ѻ�ΪƬƬ�������׷ɶ������㲻��Ŀ����������\n\n"HIR"�辡֮ʱ��$N����΢�֣����Ӱ빪��ͻȻ����һƬѪ�꣬�����˾����������ڡ�\n\n"NOR,this_object());

		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++)
		{
			things = sy_inv[j];
			destruct(things);
		}

		// ÿ���͸�shimon
		set("kee",24000);
		set("sen",20000);
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

	me = query_temp("last_damage_from");
	if (me)
		me->set("free_learn/advanced_spells_perception",1);

	::die();
}

void smart_fight()
{
	int i;
	object enemy,*enemies;
	enemy = select_opponent();
	enemies=query_enemy();


	i = query_busy();
	stop_busy();

	if (time()>query("annie/ec")+30 && !random(3))
	{
		set("annie/ec",time());
		message_vision(BBLU HIW"\n��Ȼ֮��\n"NOR,enemy);
		message_vision(HIR"\n$N"HIR"˫�ָ��ڱ�������Ʈ��΢����ü���м�һ����ɰԽ�����ޣ�����\n\n"NOR,this_object());
		call_out("hurting",8);
	}

	if (time()>query("annie/ed")+8 && time()>query("annie/ec")+9)
	{
		set("annie/ed",time());
		message_vision(BCYN WHT"\n�������\n"NOR,enemy);
		map_skill("force","divineforce");
		ccommand("perform force.lobotomy");
		map_skill("force","snowforce");
	}

	perform_busy(i);
}

