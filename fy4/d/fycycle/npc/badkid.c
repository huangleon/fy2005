inherit NPC;
#include <ansi.h>
void create()
{
        set_name("С��ͯ", ({ "smart kid","kid" }) );
        set("gender", "����" );
        set("title", GRN"����Ź�"NOR );
        set("age", 12);

        set("long", "һ���Ź־����С��ͯ����üŪ�۵�������������ͣ��\n");
        set("chat_chance", 1);
        set("chat_msg", ({
        	"С��ͯ����Ц������үү�������ʤ�ˣ�������һ��Ĺ�Ů������һ���ž����Ѹ�ô��\n",
                "С��ͯ�����ݺ��еĹ�ͷЦ������ʦ����Ҫ���Ҳ���������̫\n�������滨�����ǡ����١�\n",
        }) );
        set("combat_exp", 200000);
        set("attitude", "friendly");
        
        set_skill("force", 60);
        set_skill("unarmed", 30);
        set_skill("dodge", 100);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}


int accept_fight(object me)
{
        command("say ���������Դ���С����\n");
        return 0;
}
