// annie 07.2003
// dancing_faery@hotmail.com
// �亮�� & ����˪
#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("�亮��", ({ "leng hanxiu","leng" }) );
        set("title","��������ɽ����");
		set("nickname",WHT"��ѩ��"NOR);
        set("gender", "����" );
		
		set("class","huashan");
		set("age",25);

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );

        set("combat_exp", 8000000);
        set("score", 50);

		set("death_msg",CYN"\n$N����������˪�������㣮����һ���ˣ�����ҪС�ģ�����\n"NOR);
		set("chat_chance", 1);
		set("chat_msg", ({
		"�亮�伱������˪����˪������ˣ�������ô��\n",
		"�亮����Ŀ�Ĺˣ��������֣����Ż�������ģ����Ķ�ȥ�ˣ�\n",
		}) );

		set_skill("zen",200);
		set_skill("xiaodao",200);
		set_skill("demosword",200);
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
		set_skill("zensword",200);
		set_skill("sword", 350);
		
		map_skill("parry","zensword");
		map_skill("sword","demosword");
		map_skill("force","hanmei-force");
		map_skill("dodge","cloud-dance");
		
		set("smartnpc_busy",1);
		set("perform_weapon_attack","npc/sword/demosword/zhutianjianzhen");
		set("perform_busy_d",	"huashan/dodge/cloud-dance/yexuechuji");
		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(WHT"����콣"NOR, ({"sword" }) );
		weapon->set("long","����һ�����ɵĳ����������Ͽ��ţ����������֡�\n");
		weapon->set("nodrop_weapon",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�������", ({ "cloth" }) );
		weapon->set("long","һ����С�İ��¡�\n");
		weapon->set("value",0);
		weapon->wear();

}