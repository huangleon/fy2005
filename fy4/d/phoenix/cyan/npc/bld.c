// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();

void smart_fight()
{

	if (!random(5))
		ccommand("perform fenqin");
	else
	{
		ccommand("enable blade spring-blade");
			ccommand("perform fengsiyunqi");
		ccommand("enable blade beilongblade");

	}
	ccommand("perform changrijiangjin");
}

void create()
{
	object weapon;
	set_name("���޺�", ({ "jiang wuhen","jiang","wuhen","jiangwuhen" }) );
	set("class","official");
	set("gender", "����" );
	set("age", 46);

	set("nickname",RED"�����޳�"NOR);
	set("title","��͢���� "CYN"�̲�ִ��"NOR);

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("inquiry",([
		"��Ѫƽ��": "action���޺޵��۾����࣬͸������÷���һ����Ͼ����䡣\n���޺����¶��һ˿��Ц��"WHT"�ƶ���"CYN"�ƶ��ˣ������Ϸ��Ҫ������ͷ��",
		"�ƶ���":  "��һ�Ѵ󵶷������ţ�˳�ں����ϡ��������⣬�Ե���\nƬ������Ƭ���������ã��ȵ��ַ������ˣ����ڶ����ϻ���ī�ߣ�Ҫ\nһ������ȥ���ö������߶��ϣ�����ֺ������ڶ�������ͭǮ������\n����������Ƭ�䣬��ͭǮ���䣬����С�ɡ�",
		]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"���޺޵���Ҫ�����ҵĵ�����������������Ķ��������ƶ������������ɡ�\n",
		"���޺޵��������˵���Ҫ�������˽⡣��������ÿһ���ǽڵĹ��죬ÿһ��\n�����Ծ�����Լ�ÿһ��������������һ��ʱ�ĸ��ַ�Ӧ����ָ�ƣ�ɱ�˾�\n���嶡��ţһ���������ࡣ\n",
	}) );

	set("combat_exp", 5700000);

	set_skill("blade", 200);
	set_skill("beilongblade", 220);
	set_skill("spring-blade", 220);
	map_skill("blade","beilongblade");

	set_skill("unarmed", 200);
	set_skill("luoriquan", 220);
	map_skill("unarmed","luoriquan");


	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight() :),
	}) );

	setup();

	
	carry_object("/d/shenshui/obj/medicine");

        weapon=carry_object("/obj/weapon/blade/pxblade");
        weapon->set_name(MAG"���γ���"NOR, ({ "blade" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("ִ�³���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

