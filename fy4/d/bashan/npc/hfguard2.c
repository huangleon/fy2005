// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("�˵��", ({ "gu dianfei","gu","dianfei" }) );
        set("title",CYN"��ɽһ��"NOR);
        set("gender", "����" );

		set("age",27);

        set("long","�˵�����ƽ��Ϊ������¾������·����׵��ĸ����ӣ�\n����׵����ڣ������Ѳ�֪ȥ��η���\n");

		set("chat_chance",1);
		set("chat_msg", ({
			"�˵��΢Ц����ʦ����һʽ�������㣬���������޼������Ѿ�����ࡣ\n",
			"�˵�ɳ�������ʦ��˵���׻ط罣��ר�Ƹ����Ʒ����ҿ�����ȴ�и�����©����\n",
			"�˵�ɵ�����˵������ʦ�ֵܵ�������������Զ����ٵġ�\n",
		}) );
   
		set("inquiry",([
 		"���Ʒ�"  :"ʦ���ö�ʦ��ȥ�������ȵȣ���ΪʲôҪ�����㣿\n",
 		"�˷��"  :"ʦ���ô�ʦ��ȥ�������ȵȣ���ΪʲôҪ�����㣿\n",
 		"�˵���"  :"��ʦ���˰�ɽ���ͣ���������޵У�������Ħ���涼Ҫ�������֡�\n",
 		"�˼���"  :"��ʦ���˰�ɽ���ͣ���������޵У�������Ħ���涼Ҫ�������֡�\n",
 		"�����"  :"��ʦ��˭�����£�ֻ��ʦ��ɼ�����ʦ���ʤһ�\n",
 		"����"  :"��������˼ô�����Ƿ���Լ���������ݣ��������ˡ�\n",
 		"�⽣����"  :"��������˼ô�����Ƿ���Լ���������ݣ��������ˡ�\n",
 		"���³���"  :"action�˵����������������������ǵ��˼ҵ����վͺã���Ҫ˵�����\n",
 		"©��":		"Ҳ��֪Ϊ�Σ��ϴ��������˸��ֻ��ĺ��У�ʦ�ֵĻط罣������Ʋ��������Ʒ������չ��գ�\n",
              ]) );

        set("combat_exp", 9500000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
          	(: auto_smart_fight(30) :)
             }) );
        set_skill("sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("softsword", 180);
		set_skill("unarmed",200);
		set_skill("spicyclaw",200);
		set_skill("13-sword",200);
		
		map_skill("unarmed","spicyclaw");
        map_skill("sword", "softsword");
        map_skill("parry", "softsword");
        map_skill("dodge", "13-sword");
	
		set("perform_weapon_attack","swordsman/sword/softsword/changtianluodian");
		set("perform_unarmed_attack","demon/unarmed/spicyclaw/extrahit5");
		set("perform_unarmed_attack2","demon/unarmed/spicyclaw/extrahit4");
		
		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(HIB"��罣"NOR, ({ "lightning sword","sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�ɵ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
