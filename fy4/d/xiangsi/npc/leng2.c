// annie 07.2003
// dancing_faery@hotmail.com
// �亮�� & ����˪
#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("����˪", ({ "leng ningshuang","leng" }) );
        set("title","��¹�");
		set("nickname",WHT"�����޺�"NOR);
        set("gender", "Ů��" );

		set("class","huashan");
		set("age",25);

		set("death_msg",CYN"\n$N�����������䣮��������������\n"NOR);
		set("chat_chance", 1);
		set("chat_msg", ({
			"����˪��ŵ����Ǹ������ӣ���ô���������ң�\n",
			"����˪ҧҧ������������Ѱ�ң���ƫ��ȥ������\n",
		}) );

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );

        set("combat_exp", 7500000);
        set("score", 50);
		
		set_skill("stormdance",200);
		set_skill("snowforce",200);

		set_skill("zen",200);
		set_skill("xiaodao",200);
		set_skill("demosword",200);
		set_skill("zensword",200);
		set_skill("cloud-dance",200);
		set_skill("dodge",200);
		set_skill("parry",200);
		set_skill("hanmei-force",200);
		set_skill("zen",200);
		set_skill("xiaodao",200);
		set_skill("snowforce",200);
		set_skill("cloud-dance",200);
		set_skill("anxiang-steps",200);
		set_skill("sword",350);
			
		map_skill("parry","zensword");
		map_skill("sword","zensword");
		map_skill("force","hanmei-force");
		map_skill("dodge","cloud-dance");
		
		set("smartnpc_busy",1);
		set("perform_weapon_attack","npc/sword/zensword/menghuankonghua");
		set("perform_busy_d",	"huashan/dodge/cloud-dance/yexuechuji");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(RED"����"NOR, ({"sword" }) );
		weapon->set("long","����һ�����ɵĶ̽��������Ͽ��ţ���ƽ�����֡�\n");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�׵���ȹ", ({ "cloth" }) );
		weapon->set("long","һ��С�ɵĳ�ȹ��\n");
		weapon->set("value",0);
		weapon->wear();

}