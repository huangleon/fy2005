inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�ݺ���", ({ "fat bonze","bonze" }) );
        set("gender", "����" );
        set("title", YEL"��ͷ���"NOR );
        set("class", "bonze");
        set("age", 32);
        
        set("long", "һ����ͷ���У��������ӣ���ֱ���ֲ���ͷ���Ľ�̡�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ݺ�����ƤЦ���������ǵ���������ò�����ӣ��Һ������ϻ��ס�\n",
                }) );
        set("combat_exp", 500000);
        set("attitude", "friendly");
  
        set_skill("force", 60);
        set_skill("unarmed", 70);
        set_skill("iron-cloth", 50);
        set_skill("xisui", 40);
        set_skill("yizhichan", 80);
        set_skill("dodge", 60);
        
        map_skill("unarmed","yizhichan");
        map_skill("iron-cloth","xisui");
        
        setup();
        carry_object("/d/qianfo/npc/obj/cloth")->wear();
        carry_object("/d/qianfo/npc/obj/shoe")->wear();
}


int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
}
