#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "mrs liu" }) );
        set("gender", "Ů��");
	set("age",35);
	set("env/wimpy",90);
        set("combat_exp", 10000);
        set("long",
		"������Ҳ�������ģ�������������Сʮ���꣬���Ǿ���������������
�˶��޷�����������ʵ��͡���������Ȼ��ϸ����Ƥ����Ȼ�Ử����С��
��Ȼ�⻬ƽ̹�������û��һ˿���ơ�\n"
	);
	set_skill("move",100);
        set_skill("dodge", 50);
	set_skill("unarmed",30);
        set("chat_chance", 1);
        set("chat_msg", ({
		name()+"��Ц�����������ˣ������кô��ġ�\n",
		name()+"��һ��ѩ�׵����������ҧ��ӣ�Ұ�ĺ촽��������Ǹ����ˡ�\n",
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
