#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "mr liu" }) );
        set("gender", "����");
        set("combat_exp", 10000);
	set("age",47);
	set("env/wimpy",90);
        set("long","
�����ɴӼ�����ǰ�Ϳ�ʼ������һ�������������ޣ��ü���
�ƽ̴������ط����Ƶ��񵤡�\n"
	);
	set_skill("move",100);
        set_skill("dodge", 50);
	set_skill("unarmed",50);

        set("chat_chance", 1);
        set("chat_msg", ({
		name()+"��Ц�����������ܸ�֪�����ǲ�����������ˣ�\n",
		name()+"��������Ȼ�Ǹ����ˣ�������������ʲô���⣬�ò��ŵ���˵��������Ҳ�ܲµõ��ġ�\n"
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
