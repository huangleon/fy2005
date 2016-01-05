#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
	object weapon;
	set_name("����", ({ "the king of boasters", "busan" }) );
	set("class","blowman");
	set("gender", "����" );
	set("age", 25);

	set("nickname",HIY"���µ�һ�Σ�������˫��"NOR);
	set("title",HIC"��ţ����"NOR);

	set("attitude", "friendly");

	set("long","��˵����ÿ�����¾�Ҫ��һ��Ƥ������������\n�����Ĳ��־��Ǽ����ޱȵ���ţƤ��\n");

	set("chat_chance", 100);
	set("chat_msg", ({
	CYN"����ҡͷ���Ե�����֪��֪���������һ���֣��������ҵ�ָ���µ����ġ�\n"NOR,
	CYN"�����ӱ��������һ������һ�����׬����ʮ��Ǳ�ܣ�����ұȣ�\n"NOR,
	CYN"��������˵�������ڲ�ɱǮ�ˣ�������ɱǮ��ʱ��һ���ǧ���ƽ�Ҳ���еġ�\n"NOR,
	CYN"�����ϳ���������ʲô���㲻��ʶ�ң��ҿ����������µ�һ�����֣���Щ�����������µ��ˣ�û��ʮ��Ҳ�ж�ʮ���ˡ�\n"NOR,
	CYN"����̾������ţҲ��һ�ֱ��£���������м��������治��ɫ�Ĳ����Ĵ�ţƤ�أ�\n"NOR,
	CYN"��������һ���죬��ֻ���������������ˮ��ĭ���Ƶ����˳�ȥ���ܿ�ͰѰ�����Ĵ�����ע������������\n"NOR,
	CYN"������ͷ���˴��Լ����ϵĴ�ţƤ����ţƤ��ʱ�͵ùĹ����ҡ�\n"NOR,
	CYN"����������������ҿ����������У�����Ψһ����ţ�Ϊʲôû�����������أ�\n"NOR,
	}) );

	set("combat_exp", 1);

	setup();

	weapon = carry_object("/obj/armor/cloth");
	weapon->set("name",YEL"��ţƤ"NOR);
	weapon->set("long","��̯��ţƤһ����ԭ����߿տգ�ʲôҲû�С�");
	weapon->wear();

}





int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	write("��˵����ÿ�����¾�Ҫ��һ��Ƥ�����������������Ĳ��־��ǽ�����˵������ޱȵ���ţƤ��\n��������Լ��ʮ���ꡣ\n��������ͷ���Եġ�\n��������ԲԲ��������������������"HIR"��ɲ�"NOR"��������֪��ǳ��\n��"HIG"�������ϲ���˿���˺�"NOR"��\n����"NOR YEL"��ţƤ"NOR"(Cloth)\n");
	return 1;
}

int do_listskill(string arg)
{
	object me = this_player();
	if (!arg || present(arg,environment()) != this_object())
		return 0;
	write("����Ŀǰ��ѧ��һ�ּ��ܣ�\n\n�Դ�����֮�� (blowing)                   - "HIW"��ɲ�"NOR" 400/    0\n\n");
	return 1;
}

void init()
{
	object ob;
	::init();
	add_action("do_listskill","skills");
	add_action("do_look","look");
}

