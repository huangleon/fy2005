// laoban.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����ջ�ϰ�", ({ "laoban" }) );
        set("long",
                "һ��������Ц�����ӡ���Ȼ������Ц�ݣ���ȴ���úܲ������\n"
                );

        set("attitude", "peaceful");
        set("str", 40);
        set("cor", 26);
        set("agi", 60);

        set("combat_exp", 10000);

        set("chat_chance", 1);
        set("chat_msg", ({
                "�����ջ�ϰ�̾����������������������ֹ����Ƿ�������������\nԽ��Խ��������\n",
                }) );

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 30);

        setup();
        carry_object("/obj/armor/cloth")->wear();
}
