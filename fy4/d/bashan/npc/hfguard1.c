// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("���׷�", ({ "gu leifei","gu","leifei" }) );
        set("title",CYN"��ɽһ��"NOR);
        set("gender", "����" );
		set("age",27);
        set("long","�˵�����ƽ��Ϊ������¾������·����׵��ĸ����ӣ�\n����׵����ڣ������Ѳ�֪ȥ��η���\n");

		set("chat_chance",1);
		set("chat_msg", ({
			"���׷����Ŵ����Ӵ����ݰν������ڿ��л���һ���������ʣ���û��һ�㺮â��\n",
			"���׷�Ц��˵��ʦ����һ�г�����磬����л����ҲҪ����һ�����֣�\n",
		}) );
        set("inquiry",([
 		"���Ʒ�"  :"ʦ���ö�ʦ��ȥ�������ȵȣ���ΪʲôҪ�����㣿\n",
 		"�˷��"  :"ʦ���ô�ʦ��ȥ�������ȵȣ���ΪʲôҪ�����㣿\n",
 		"�˵���"  :"��ʦ���˰�ɽ���ͣ���������޵У�������Ħ���涼Ҫ�������֡�\n",
 		"�˼���"  :"��ʦ���˰�ɽ���ͣ���������޵У�������Ħ���涼Ҫ�������֡�\n",
 		"�����"  :"��ʦ��˭�����£�ֻ��ʦ��ɼ�����ʦ���ʤһ�\n",
 		"����"  :"��������˼ô�����Ƿ���Լ���������ݣ��������ˡ�\n",
 		"�⽣����"  :"��������˼ô�����Ƿ���Լ���������ݣ��������ˡ�\n",
 		"���³���"  :"action���׷������Ĺ����ˣ����ĵ�˵��\n���³������죬�ҿ�����ˮ�����Ϸɹ���Ү��\n",
 		"��ˮ"  :"�����˳ơ������޵�֮�����ɾ�����ʦ��ɱ�ְ�ˮ�㶼��֪����\n",
              ]) );

        set("combat_exp", 9500000);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
             }) );

        set_skill("sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("windsword", 175);
        set_skill("13-sword", 150);

        map_skill("sword", "windsword");
        map_skill("parry", "windsword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(HIC"���׽�"NOR, ({ "thunder sword","sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("������", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
