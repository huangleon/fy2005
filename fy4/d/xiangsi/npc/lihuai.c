inherit NPC;
#include <ansi.h>
void create()
{
	object weapon;
        set_name("�", ({ "li huai","li" }) );
        set("gender", "����" );
		set("nickname",HIG"�ּ��ɵ�"NOR);
		set("age",20);
		set("c",HIG"�������ϲ���˿���˺ۡ�"NOR);
        set("reward_npc", 1);
		set("difficulty", 10);
		set("attitude","friendly");
        set("max_force", 15000);
		set("NO_KILL",1);
        set("force", 15000);
        set("force_factor", 1);
        set("long","һ���糾���͵������ˣ���һ������˵����ѣ�\n��������Ӧ���ޱ����ǣ�����ȴ���ޱȾ���\n");
        create_family("����һ��", 4, "�˽�");
        set("combat_exp", 10000000);

        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
		set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
       	map_skill("throwing", "feidao");
        setup();
        weapon = carry_object("/obj/armor/cloth");
		weapon->set("name",HIR BLK"�����˵�����"NOR);
		weapon->wear();
}

int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	write("һ���糾���͵������ˣ���һ������˵����ѣ�\n��������Ӧ���ޱ����ǣ�����ȴ���ޱȾ���\n��������Լ��ʮ���ꡣ\n��������棬�������ٷ硣\n��"CYN"���˾�����������"GRN"���书����������"HIB"�����ž�"NOR"�������ƺ����ᡣ\n��"+query("c")+"\n����������һ��"YEL"����"NOR"(Tofu)\n  ��"HIR BLK"�����˵�����"NOR"(Cloth)\n");
	return 1;
}

void init()
{
	add_action("do_look","look");
	::init();
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
