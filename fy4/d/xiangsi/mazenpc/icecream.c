// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{	
	object weapon;
	set_name("������", ({ "icecream","kirin" }) );	// icecream :pp
	set("attitude", "friendly");

	set("long",WHT"���ڶ����Ĵ����ߣ�Ŀ�о������䣬������Ϣ��\n�����������󶴵������߱����롣\n\n"NOR);
	set("no_arrest",1);
	set("no_fly",1);

	set("race", "Ұ��");
	set("class","moon");
	set("group","icecave_maze");

	set("real_boss",1);
	set("boss",1);
	set("big_boss",1);
	set("reward_npc", 1);
	set("difficulty", 10);

	set("resistance/gin",80);
	set("resistance/kee",80);
	set("resistance/sen",80);
	// GKS * 5

	set("max_gin",32000);
	set("max_sen",32000);
	set("max_kee",48000);
	set("max_force",10000);
	set("force",20000);

	set("combat_exp", 10000000);
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

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("dodge", "stormdance");
	map_skill("move", "stormdance");
	map_skill("unarmed", "shuaijiao");
	map_skill("force", "snowforce");
	map_skill("spells", "mapo");

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw", "hoof", "poke" }) );

	setup();


	set("drop/bg",15);
	set("drop/common",70);
	set("drop/rare",30);
	set("drop/amount",3);
	set("drop/common_drop",({
__DIR__"obj/cash.c",
__DIR__"obj/glacialcrevasses.c",
__DIR__"obj/lockupdrug.c",
__DIR__"obj/bingpojingbi_3.c",
__DIR__"obj/hanxueliulan_3.c",
__DIR__"obj/mingyue_3.c",
__DIR__"obj/shuanghuaningjie_3.c",
__DIR__"obj/shuangtianxuewu_3.c",
//__DIR__"obj/wufangbianhuan_3.c",
__DIR__"obj/zhaoyuwanqing_3.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/hanxueliulan_4.c",
__DIR__"obj/qinghui_3.c",
__DIR__"obj/kirinheart.c",
__DIR__"obj/arcticwind.c",
__DIR__"obj/boots.c",
	}) );



}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	message_vision(CYN"\n������������ת����Ȼ����˿�����͡�\n"NOR, this_object());
	return;
}

void smart_fight()
{
	int i;
	object enemy;
	enemy = select_opponent();

	switch (random(4))
	{
	case 0:
		ccommand("exert shuanghuaningjie");
		set("timer/shuanghuaningjie",time()-570-random(25));
		if (random(3))
			break;
	case 1:
		if (time()>query("annie/ec")+5)
		{
			set("annie/ec",time());
			message_vision(HIW"\n���������һ�ں���$N������壬���û����������ظ�����죡\n\n"NOR,enemy);
			switch (random(3))
			{
			case 0:
				enemy->set("kee",enemy->query("kee")*6/10);
				break;
			case 1:
				enemy->set("gin",enemy->query("gin")*6/10);
				break;
			case 2:
				enemy->set("sen",enemy->query("sen")*6/10);
				break;
			}
		}
		if (random(3))
			break;
	case 2:
		if (!present("healer 3",environment()) && time()>query("annie/sh")+30)
		{
			set("annie/sh",time());
			message_vision(HIW"\n���������쳤Х��������ѩ�׷����£�ѩ����ͻȻ���һ������С�ˡ�\n\n"NOR,enemy);
			enemy = new(__DIR__"healer");
			enemy->move(environment());
			enemy->set("owner",this_object());
		}
		if (random(3))
			break;
	case 3:
		ccommand("cast freeze");
		if (random(3))
			break;
	}
}

