#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���ϰ�", ({ "big boss" }) );
        set("gender", "����");
        set("combat_exp", 10000);
	set("age",47);
	set("env/wimpy",90);
        set("long",
		"���ϰ����ϴ���һ����ͨ�Ĳ��£���ô��Ҳ������ϰ塣\n"
	);
	set_skill("move",100);
        set_skill("dodge", 50);
	set_skill("unarmed",50);
        set("chat_chance", 1);
        set("chat_msg", ({
	name()+"���������·�Ҫ���Ứ�㣬ȴͻȻ���֣���������ָ��סֻ�ɳ棬
Ȼ����������ʵ���������˵�Ǹ��˽�ʲô���֣���\n",
	name()+"������������û���õİ�������\n",
	name()+"΢Ц��ͷ�����ú����⣬��ϲ�����˼�ס��˵�Ļ��������ÿһ�仰��\n"
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
